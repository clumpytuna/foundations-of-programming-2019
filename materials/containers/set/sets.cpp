// Here you can find basics about sets in STL
// First of all don't forget to include <set>!

// Sets are a type of associative containers in which each element has to be unique,
// because the value of the element identifies it. The value of the element cannot be modified once it is added to the set,
// though it is possible to remove and add the modified value of that element.

#include <iostream>
#include <set>

using namespace std;

// Function to print a set
void PrintSet(const set<int>& s) {
  for (auto element : s) {
    cout << element << ' ';
  }
  cout << endl;

}

int main() {

  // Empty set container
  set<int> s;

  // insert elements in random order
  s.insert(10);
  s.insert(20);
  s.insert(30);
  // only one 10 will be added to the set
  s.insert(10);


  PrintSet(s);

  // remove elements from set
  s.erase(10);

  // We can use range-based for to iterate through set
  for (int x : s) {
    cout << x << ' ';
  }
  cout  << endl;

  // We can't access elements by index. Elements have no index
  /* This code cause an error
   s[0] = 15;
   */

  // To check if set contains element you can use .count method.
  // Set contains only one copy of any element so .count returns 0 or 1.
  cout << s.count(10) << endl;

  return 0;
}