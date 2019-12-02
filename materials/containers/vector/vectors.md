## Vector in C++ STL
Vector is a kind of sequence in C++. You can create vector of any size you want and also you can
modify vectors: add elements, erase elements and so on. Vectors are same as dynamic arrays with the ability to resize itself automatically.

In this file you can find code snippets to work with vectors. Source code is avaliable [here](vectors.cpp). 
More information and documentation are [here](https://en.cppreference.com/w/cpp/container/vector).


**Let's consider some examples with vectors**


  You can initialize vector like this
  ```
   vector<int> first_v = {1, 2, 1, 2, 1};
  ```
  
  

  You can create empty vector size of n
  ```
  int n = 10;
  vector<int> second_v(n);
  ```
  Create vector size of n and fill it with 1's or with any other number
  ```
  vector<int> third_v(n, 1)
   ```

  Access vector by index. All vectors are indexed from 0.
  ```
  first_v[0] = 1;
  cout << first_v[2];
  ```

  Let's iterate through vectors using different types of loops.
  We can check size of vector using method .size().
  ```
  for (int i = 0; i < first_v.size(); ++i) {
    cout << first_v[i] << ' ';
  }
  cout << endl;
  ```

  For iterating we also can use range-based for
  ```
  for (int x : first_v) {
    cout << first_v << ' ';
  }
  ```  
  
  If you are going to modify vector elements don't forget about references &
  ```
  for (int& x : first_v) {
    x += 1;
  }
  ```

  Otherwise you just work with copy of elements and can't modify elements itself


  Using usual type of loops you can use different conditions and operations. For example to iterate from end to begin
  ```
  for (int i = first_v.size() - 1; i >= 0; --i) {
    cout << first_v[i] << ' ';
  }
  ```

  Or to iterate elements with odd indices
  ```
  for (int i = 0; i < v_first.size(); ++i) {
    cout << first_v[i] << ' ';
  }
  ```
  
  There are 3 ways how to read vectors from the console

  Create an empty vector. Read a number.
  Append the number to the end of the vector
  ```
  vector<int> first;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    first.push_back(x);
  }
  ```
  

  Create a vector size of n and read numbers one by one
  ```
  std::vector<int> second(n);

  for (int i = 0; i < n; ++i) {
    cin >> second[i];
  }
  ```
  
  Same way as previous using range based for
  ```
  vector <int> third(n);

  for (int& element: third) {
    cin >> element;
  }
  ```
  
  We can create multidimensional vectors.
  Let's create matrix. Size of M x M.
  
  First we create vector filled with n empty vectors
  ```
  vector<vector<int>> matrix(n);
  ```
  
  Resize each of this vectors
  ```
  int m = 10;
  for (auto& v: matrix) {
    v.resize(m);
  }
  ```
  Now we have matrix filled with zeros.
  Let's print it
  ```
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
        cout << matrix[i][j] << ' ';
    }
    cout << endl;
  }
  ```
  
  More information you can find [here](https://en.cppreference.com/w/cpp/container/vector).