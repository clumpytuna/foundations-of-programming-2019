#include <vector>
#include <iostream>

using namespace std;

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

int main() {
  SortedNumbers numbers;

  numbers.AddNumber(-1);
  numbers.AddNumber(2);
  numbers.AddNumber(3);
  numbers.AddNumber(-4);

  for (int s: numbers.getSortedNumbers()) {
    cout << s << ' ';
  }
  return 0;
}