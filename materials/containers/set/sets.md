# Set in C++ Standard Template Library (STL)

Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.


**Let's consider some examples with sets**

  Create empty set container
  ```
  set<int> s;
  ```
  Insert elements in random order
  ```
  s.insert(10);
  s.insert(20);
  s.insert(30);
  // only one 10 will be added to the set
  s.insert(10);
  ```

  Remove elements from set
  ```
  s.erase(10);
  ```
  
  We can use range-based for to iterate through set. You can run source [code](materials/containers/set/sets.cpp) and see that set stores elements in sorted order.
  ```
  for (int x : s) {
    cout << x << ' ';
  }
  cout  << endl;
  ```
  We can't access elements by index. Elements have no index
  ```
   // This code cause an error
   s[0] = 15;
   
  ```
  To check if set contains element you can use .count method. Set contains only one copy of any element so .count returns 0 or 1.
  ```
  if (s.count(10)) {
    cout << "s contains 10" << endl;
  } else {
    cout << "s doesn't contain 10" << endl;
  }
  ```
  
  You can find source code [here](materials/containers/set/sets.cpp) and more information [here](https://en.cppreference.com/w/cpp/container/set). 