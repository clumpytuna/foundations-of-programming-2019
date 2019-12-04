# Map in C++ Standard Template Library (STL)
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.


**Let's consider some examples with sets**


  Create map with integer keys and string values
  ```c++
  map<int, string> events;
  ```
  Adding elements in map
  ```c++
  events[1946] = "Freddie Mercury's birth";
  events[1958] = "Michael Jackson's birth";
  events[1970] = "UNIX epoch start";
  ```
  Let's iterate through the map.
  You can access key of element use item.first. Use item.second to access value of element.
  ```c++
  for (auto item: events) {
    cout << item.first << ": " << item.second << endl;
  }
  cout << endl;
  ```
  
  Each element of map is a pair
  ```c++
  for (pair<int, string> item: events) {
    cout << item.first << ": " << item.second << endl;
  }
  ```
  Since C++ 17 you can write loop through map more expressive
  ```c++
  for (const auto& [key, value] : m) {
    cout << key << ' ' << value;
  }
  ```


  To delete elements from map use .erase method
  ```c++
  events.erase(1946);
  ```
  
  To check if map contains element with certain key you can use .count method.
  Map contains only one copy of any element so .count returns 0 or 1.
  ```c++
  cout << events.count(1946) << endl;
  ```


You can find source code [here](maps.cpp) and more information [here](https://en.cppreference.com/w/cpp/container/map).
