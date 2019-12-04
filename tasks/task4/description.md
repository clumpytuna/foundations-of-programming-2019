## Problem A

Create a structure represents a point and write a function to compute an Euclidean distance between two dots.

```
struct Point {
  // Add fields here
};

??? GetDistance(const Point& x, const Point& y) {
  // Code to compute a distance
}

```

Example of usage:

  ```
  Point x = {0.0, 0.0};
  Point y = {4.0, 3.0};
  
  cout << "Distance between x and y is " << GetDistance(x, y);
  ```
  
Output:
```
Distance between x and y is 5

```


Here you can find a solution template: [point.cpp](tasks/task4/point.cpp)

## Problem B

Implement a class stores a set of strings in sorted order. The class must contain two public methods:

```
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

Example of usage:
```
SortedNumbers numbers;

numbers.AddNumber(-1);
numbers.AddNumber(2);
numbers.AddNumber(3);
numbers.AddNumber(-4);

for (int s: numbers.getSortedNumbers()) {
  cout << s << ' ';
}

```

Output:

```
-4 -1 2 3
```


Here you can find a solution template: [sorted_numbers.cpp](tasks/task4/sorted_numbers.cpp)



## Problem C