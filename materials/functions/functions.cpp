#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// Practice 5.11.2019
// In this file you can find the examples of using STL functions

using namespace std;

void PrintVector(vector<int> v) {
  for (int x: v) {
    cout << x << ' ';
  }
  cout << endl;
}


// We will need this functions later now just skip it

bool cmp(int a, int b) {
  return a > b;
}

bool gt1(int x) {
  return x > 1;
}

int main() {

  // Sort function example
  // We want to sort a vector

  vector <int> v = {1, 2, 3, 1};

  PrintVector(v);


  // How can we do it?
  // We can write algorithm sorting vectors. But can we really do?




  // ??????????????????????????????????????????????????????????????



  // In fact it is too hard for us now. Later we will know how to implement such algorithms
  // but now it's better to use built-in functions.

  sort(begin(v), end(v));

  PrintVector(v);


  // If we want to sort in other order we can use sort with 3 parameters
  // The third parameter is a function comparing numbers
  sort(begin(v), end(v), cmp);


  // Also we can use lambda functions like this:
  // In this case we don't need to go to the definition. We can know what function do just on the place.
  // It safes our time!
  sort(begin(v), end(v), [](int a, int b) {
    return a > b;
  } );

  PrintVector(v);


  // Count function example
  // Here we want to count the occurrences of number 1 inside of the vector v

  vector <int> a = {1, 2, 3, 1};

  // How can we do it?

  // We can write a loop
  int ones = 0;

  for (int x : a ) {
    if (x == 1) {
      ones++;
    }
  }

  cout << ones << endl;

  // Or just use build-in function and make it much more shorter!
  cout << count(begin(v), end(v), 1) << endl;

  //--------------------------------------------------------------------------

  // count_if function example
  // We want to count numbers greater than n in the vector n

  int n = 1;
  vector <int> b = {1, 2, 3, 1, 2, 3};

  // How can we do it?

  int greater_than_n_counter = 0;

  // Of course we can create a loop
  for (int i = 0; i < b.size(); ++i) {
    if (b[i] > n) {
      greater_than_n_counter += 1;
    }
  }

  cout << greater_than_n_counter << endl;

  // Or even a range-based for loop

  greater_than_n_counter = 0;

  for (int element : b) {
    if (element > n) {
      ++greater_than_n_counter;
    }
  }

  cout << greater_than_n_counter << endl;

  // But it is still a lot of lines of code!
  // We can do it shorter and easier!


  // if we know n is equal to 1 we can write this:
  cout << count_if(begin(v), end(v), gt1) << endl;

  // or use lambda functions like this:
  cout << count_if(begin(v), end(v), [](int x) {
    return x > 1;
  }) << endl;
  // In this case we don't need to go to the definition. We can know what function do just on the place.
  // It safes our time!



  // What if we don't know a value of n? For example we got it from the input
  cin >> n;

  // In this case we can write a function with two arguments and try to put it in count_if function
  // Ooh no!  Count_if function can get only function with one parameter!
  // We can deal with it. Let's use lambda function!

  // We can catch n from the context and use it inside lambda function
  cout << count_if(begin(v), end(v), [n] (int x) {
    return x > n;
  }) << endl;



  return 0;
}