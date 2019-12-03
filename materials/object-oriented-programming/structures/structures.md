# Structures in C++

 Here you can find infromation about Structures in C++. We often come around situations where we need to store a group of data whether of similar data types or non-similar data types. Structures in C++ are user defined data types which are used to store group of items of non-similar data types. A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type.

**Let's consider some examples with structures**

  _How to create a structure_?

  The ‘struct’ keyword is used to create a structure. The general syntax to create a structure is as shown below:

```
 struct structureName{
    type member1;
    type member2;
    .
    .
    type memberN;
};
```

Let's create our own structure. For example we want to have the type to represent a person.
```
struct Person {
  string first_name;
  string last_name;
  int year_of_birth;
};
```

Now we can work with our structure and use it as built-in data type.
Let's write a function to write information about a person.
```
void PrintPerson(const Person& person) {
  cout << "First Name: " << person.first_name <<
       ", Last Name: " << person.last_name <<
       ", Year of Birth: " << person.year_of_birth << "\n";
}
```

Function to print information about set of persons.

```
void PrintPersons(
    const vector<Person>& persons) {
  for (Person person : persons) {
    PrintPerson(person);
  }
}
```

We can write a function that returns certain person. 
```
Person GetPerson() {
  // Here we create a structure using braces.
  return {"Bjarne", "Stroustrup", 1950};
}
```

What if we create a structure and want to use it inside other structure?
```
struct PersonInfo {
  string place_of_birth;
  int year_of_birth;
};
```

We can easily do it. We can use our custom type everywhere as built-in C++ data types.
```
struct DetailedPerson {
  string first_name;
  string last_name;
  PersonInfo info;
};
```


_How can we create a variable of our new type?_

The easiest way to do it is to define a variable. Then initialize each field. You can access fields using following syntax name_of_variable.name_of_fields
  ```
  Person first_person;
  first_person.first_name = "Bjarne";
  first_person.last_name = "Stroustrup";
  first_person.year_of_birth = 1950;
  ```



  There is the shorter way to do it.
  Write braces and values of fields in the same order that we defined.
  ```
  Person second_person = {"Dennis", "Ritchie", 1941};
  ```

  We can construct structure in place. Without creating a variable.
  ```
  PrintPerson({"Dennis", "Ritchie", 1941});
  ```
  
  If function returns structure we can initialize variable like this
  ```
  Person certain_person = GetPerson();
  ```

  To create nested structure we can use already known syntax
  ```
  PersonInfo info = {"Maida Vale", 1912};
  DetailedPerson third_person = {"Alan", "Turing", info};
  ```
  To access inner fields you can use expected syntax
  ```
  cout << third_person.info.place_of_birth << endl;
  ```
  
  You can find source code [here](structures.cpp) and more information [here](https://en.cppreference.com/w/c/language/struct).



















