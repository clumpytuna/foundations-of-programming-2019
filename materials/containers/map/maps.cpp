// Maps are associative containers that store elements in a mapped fashion.
// Each element has a key value and a mapped value. No two mapped values can have same key values.

// First of all don't forget to include <map>!
#include <map>
#include <utility>
#include <iostream>

using namespace std;

// Function to print map
void PrintMap(const map<int, string>& m) {
  cout << "Size = " << m.size() << endl;
  for (auto item: m) {
    cout << item.first << ": " << item.second << endl;
  }
}

int main() {

  // Create map with integer keys and string values
  map<int, string> events;

  // Adding elements in map
  events[1946] = "Freddie Mercury's birth";
  events[1958] = "Michael Jackson's birth";
  events[1970] = "UNIX epoch start";

  // Let's iterate through the map.
  // You can access key of element use item.first. Use item.second to access value of element.
  for (auto item: events) {
    cout << item.first << ": " << item.second << endl;
  }
  cout << endl;

  // Each element of map is a pair
  for (pair<int, string> item: events) {
    cout << item.first << ": " << item.second << endl;
  }

  // Since C++ 17 you can write loop through map more expressive

  for (const auto& [key, value]: events) {
    cout << key << ' ' << value;
  }



  // To delete elements from map use .erase method

  PrintMap(events);
  events.erase(1946);
  PrintMap(events);

  // To check if map contains element with certain key you can use .count method.
  // Map contains only one copy of any element so .count returns 0 or 1.

  cout << events.count(1946) << endl;
}