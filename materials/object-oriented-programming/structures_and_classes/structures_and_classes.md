# Structures and Classes in C++

## Structures

We often come around situations where we need to store a group of data whether of similar data types or non-similar data types. Structures in C++ are user defined data types which are used to store group of items of non-similar data types. A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type.

**Let's consider some examples with structures**

  #### _How to create a structure_?

  The ‘struct’ keyword is used to create a structure. The general syntax to create a structure is as shown below:

```c++
 struct structureName{
    type member1;
    type member2;
    .
    .
    type memberN;
};
```

Let's create our own structure. For example we want to have the type to represent a person.
```c++
struct Person {
  string first_name;
  string last_name;
  int year_of_birth;
};
```

Now we can work with our structure and use it as built-in data type.
Let's write a function to write information about a person.
```c++
void PrintPerson(const Person& person) {
  cout << "First Name: " << person.first_name <<
       ", Last Name: " << person.last_name <<
       ", Year of Birth: " << person.year_of_birth << "\n";
}
```

Function to print information about set of persons.

```c++
void PrintPersons(
    const vector<Person>& persons) {
  for (Person person : persons) {
    PrintPerson(person);
  }
}
```

We can write a function that returns certain person. 
```c++
Person GetPerson() {
  // Here we create a structure using braces.
  return {"Bjarne", "Stroustrup", 1950};
}
```

#### _What if we create a structure and want to use it inside other structure?_
```c++
struct PersonInfo {
  string place_of_birth;
  int year_of_birth;
};
```

We can easily do it. We can use our custom type everywhere as built-in C++ data types.
```c++
struct DetailedPerson {
  string first_name;
  string last_name;
  PersonInfo info;
};
```


#### _How can we declare and initialize a variable of our new type?_

The easiest way to do it is to define a variable. Then initialize each field. You can access fields using following syntax name_of_variable.name_of_fields
  ```c++
  Person first_person;
  first_person.first_name = "Bjarne";
  first_person.last_name = "Stroustrup";
  first_person.year_of_birth = 1950;
  ```



  There is the shorter way to do it.
  Write braces and values of fields in the same order that we defined.
  ```c++
  Person second_person = {"Dennis", "Ritchie", 1941};
  ```

  We can construct structure in place. Without creating a variable.
  ```c++
  PrintPerson({"Dennis", "Ritchie", 1941});
  ```
  
  If function returns structure we can initialize variable like this
  ```c++
  Person certain_person = GetPerson();
  ```

  To create nested structure we can use already known syntax
  ```c++
  PersonInfo info = {"Maida Vale", 1912};
  DetailedPerson third_person = {"Alan", "Turing", info};
  ```
  To access inner fields you can use expected syntax
  ```c++
  cout << third_person.info.place_of_birth << endl;
  ```
  
  
  **You can find source code [here](structures.cpp) and more information [here](https://en.cppreference.com/w/c/language/struct).**


  ## Classes
  
  A class in C++ is the building block, that leads to Object-Oriented programming. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.
  
  Let's write a program to work with routes between cities. Every route consist of two strings: city destination name and city source name.
  
  
  Let's define structure:
  ```c++
  struct Route {
    string source;
    string destination;
  };
  ```
  
  Also we are given a function to compute the distance 
  ```c++
  int ComputeDistance(
    const string& source,
    const string& destination);
  ```
  
  Someone already implemented this function for us, and computing this function takes a long time. Calculating a distance is expensive, so it needs to be stored somewhere. Let's create a new field in the structure.
  ```c++
  struct Route {
    string source;
    string destination;
    int length;
  };
  ```
  
  Now we can write the program to work with routes and it will be work perfect. However the length field is publicly available, and we can't be sure that it stores correct distance between source and destination.
  
  - We can accidentally change the value of the variable length
  - We can change one of the cities and forget to update the length value


   We want to minimize a probability of errors, that's why we need to forbid public access to the fields.
   
   We can define private section:
   ```c++
   struct Route {
     private:
       string source;
       string destination;
       int length;
     };
   ```
   
   There is no access to the fields from outside of the structure:
   
   ```c++
    Route route;
    route.source = "Moscow";  // This line cause an error
    cout << route.length; // As well as this line
   ```
   
   Now the structure is absolutely useless, there is nothing in the public access. In order to access private fields, we need to use methods.

    
   Let's add methods to the structure so that it becomes more functional:
   ```c++
   struct Route {
    public:
      string GetSource() { return source; }
      string GetDestination() { return destination; }
      int GetLength() { return length; }
    
    private:
      string source;
      string destination;
      int length;
   };
   
   ```
   Methods are very similar to functions, but are tied to a specific class. And when these methods are called, they will work in the context of a particular object.

   To define a method use the following syntax: write returning type, name of a method, then write a body in braces.
   
   Now we can use new methods like this:
   ```c++
   Route route;
   cout << route.GetLength();
   // We have an access to read
   int destination_name_length = route.GetDestination().length();
   
   ```
   In fact, a structure with private or public sections and methods is formally not a structure, but a class. Therefore, instead of the struct keyword, it is better to use class keyword:
   
   ```c++
   class Route { // class instead of struct 
    public:
      string GetSource() { return source; }
      string GetDestination() { return destination; }
      int GetLength() { return length; }
    
    private:
      string source;
      string destination;
      int length;
   };
   ```
    
   It will increase the readability of the code, as the following agreement exists:
   
   ***Structure*** (struct) is a set of public fields. It is used if you do not need to control the consistency. A typical example of the structure is:
   ```c++
   struct Point {
    double x;
    double y;
   };
   ```
   
   ***Class*** hides data and provides a specific interface for accessing data. It is used if the fields are connected with each other and this connection needs to be controlled. An example of a class is the Route class described above.
   
   
   
   In the discussed example, the fields of the Route class were made private to make the use of the class more secure. But now we can't change an instance of the class. To provide a way to change fields, we need to write some more public methods:
   - SetSource — to change the source.
   - SetDestination — to change the destination.
   
   In both methods, we must remember to update the route length. The best way to do it is to write UpdateLength method. The method should be available only inside the class, so let's make it private:
   
   ```c++
   class Route {
    public:
   
     string GetSource() {
       return source;
     }
   
     string GetDestination() {
       return destination;
     }
   
     int GetLength() {
       return length;
     }
   
     void SetSource(const string& new_source) {
       source = new_source;
       UpdateLength();
     }
   
     void SetDestination(const string& new_destination) {
       destination = new_destination;
       UpdateLength();
     }
   
    private:
     void UpdateLength() {
       length = ComputeDistance(source, destination);
     }
   
     string source;
     string destination;
     int length;
   };
   ```
   
   Thus, we created the class and can use it in the following way: 
   ```c++
   Route route;
   route.SetSource("Moscow");
   route.SetDestination("Dubna");
   cout << "Route from " <<
       route.GetSource() << " to " <<
       route.GetDestination() << " is " <<
       route.GetLength() << " meters long";
   ```
   
   **You can find source code [here](classes.cpp) and more information [here](https://en.cppreference.com/w/cpp/language/classes).**
    