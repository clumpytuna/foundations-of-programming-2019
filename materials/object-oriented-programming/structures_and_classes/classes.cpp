// Here you can find examples of using classes in C++

#include <string>

class Route {
 public:
  string GetSource() { return source; }
  string GetDestination() { return destination; } int GetLength() { return length; }
 private:
  string source;
  string destination;
  int length;
};



int main() {
  Route route;
  cout << route.GetLength();
  // We have an access to read
  int destination_name_length = route.GetDestination().length();
  return 0;
}