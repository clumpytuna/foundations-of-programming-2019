#include <vector>
#include <iostream>


using namespace std;


class SortedNumbers {
 public:
  void AddNumber(int n) {
    // Add number
  }
  vector<int> GetSortedNumbers() {
    // get all numbers in sorted order
  }
 private:
  // private fields
};


int main() {
  int n;


  SortedNumbers numbers;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    numbers.AddNumber(x);
  }


  for (int n: numbers.GetSortedNumbers()) {
    cout << n;
  }

  return 0;
}