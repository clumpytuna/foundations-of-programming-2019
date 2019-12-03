
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

  int n;
  cin >> n;

  SortedNumbers numbers;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    numbers.AddNumber(x);
  }

  for (int s: numbers.getSortedNumbers()) {
    cout << s << ' ';
  }

}