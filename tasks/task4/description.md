## Problem A


### Description
Create a structure represents a point and write a function to compute an Euclidean distance between two dots.

```c++
struct Point {
  // Add fields here
};

double GetDistance(const Point& x, const Point& y) {
  // Code to compute a distance
}

```

### Example

**Code**

  ```c++
  Point x = {0.0, 0.0};
  Point y = {4.0, 3.0};
  
  cout << "Distance between x and y is " << GetDistance(x, y);
  ```
  
**Output**
```
Distance between x and y is 5

```


Here you can find a solution template: [point.cpp](point.cpp)

## Problem B

### Description

Implement a class stores a set of strings in sorted order. The class should contain two public methods:

```c++
class SortedNumbers {
 public:
  void AddNumber(int x) {
    // Write your code here
  }

  vector<int> getSortedNumbers() {
    // Write your code here
  }

 private:
  // create fields here
};
```

### Example

**Code**
```c++
SortedNumbers numbers;

numbers.AddNumber(-1);
numbers.AddNumber(2);
numbers.AddNumber(3);
numbers.AddNumber(-4);

for (int s: numbers.getSortedNumbers()) {
  cout << s << ' ';
}

```

**Output**

```
-4 -1 2 3
```


Here you can find a solution template: [sorted_numbers.cpp](sorted_numbers.cpp)



## Problem C

### Description

Create a class represents phonebook.
```c++
class PhoneBook {
 public:
  void AddEntry(const string& name, const string& number) {
    // add phonebook entry
  }

  void ChangeNumber(const string& name, const string& new_number) {
    // change a phone number of an entry with  name equals to the first parameter to new_number
  }

  void ChangeName(const string& new_name, const string& number) {
    // change a phone number of an entry with number equals to the second parameter to new_name
  }

  string GetNumberByName(const string& name) {
    // return phone number corresponding to the name
  }

  string GetNameByNumber(const string& number) {
    // return name corresponding to the phone number
  }

 private:
  // add private fields here
};
```

- Consider that all telephone numbers are unique.
- If there is no such name method _GetNumberByName_ should return "**No such person**"
- If there is no such phone number method _GetNameByNumber_ should return "**No such phone number**"


### Example
**Code**
```c++
PhoneBook myPhoneBook;

myPhoneBook.AddEntry("Freddy Mercury", "8-800-555-35-35");
myPhoneBook.AddEntry("Cesar", "8 (495) 642-50-50");
myPhoneBook.AddEntry("Me", "8-111-111-11-11");

cout << "Freddy's number: " << myPhoneBook.GetNumberByName("Freddy Mercury") << endl;

cout << "Caesar's number: " << myPhoneBook.GetNumberByName("Cesar") << endl;

myPhoneBook.ChangeNumber("Me", "8-900-800-70-60");

cout << "My new number is: " << myPhoneBook.GetNumberByName("Me") << endl;

cout << "8-800-555-35-35 is the phone number of " << myPhoneBook.GetNameByNumber("8-800-555-35-35") << endl;
```

**Output**
```
Freddy's number: 8-800-555-35-35
Caesar's number: 8 (495) 642-50-50
My new number is: 8-900-800-70-60
8-800-555-35-35 is the phone number of Freddy Mercury
```

Here you can find a solution template: [phonebook.cpp](phonebook.cpp)