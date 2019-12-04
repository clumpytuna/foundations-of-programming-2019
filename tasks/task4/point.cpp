#include <iostream>

using namespace std;

struct Point {
  // Add fields here
};

??? GetDistance(const Point& a, const Point& b) {
  // Code to compute a distance
}

int main() {

  Point a = {0.0, 0.0};
  Point b = {4.0, 3.0};

  cout << "Distance between a and b is:" << GetDistance(a, b);
  return 0;
}