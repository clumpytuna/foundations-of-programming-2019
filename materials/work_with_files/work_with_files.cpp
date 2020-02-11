#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

// Practice 12.11.2019
// In this file you can find the examples of using input and output streams
// To run a code snippet just delete /* */ symbols


using namespace std;


// Just function to print a vector
void PrintVector(const vector<int>& v) {
  for (int element: v) {
    cout << element << ' ';
  }
  cout << endl;
}


// Function to read a file into string
// I recommend you to read this function later
string ReadFile(ifstream& input) {
  string file;
  string s;
  if (input.is_open()) {
    while (getline(input, s)) {
      file += s;
      file += '\n';
    }
  } else {
    cout << "Error!" << endl;
  }

  return file;
}


// Last time you had questions about reading a sequence of number
// Here you can find 3 ways how to read numbers

int main() {

  /*
  // The size of vector is known. Let's read it.

  int n;
  cin >> n;

  // Create an empty vector, read a number,
  // append the number to the end of the vector
  vector<int> first;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    first.push_back(x);
  }

  PrintVector(first);

  // Create a vector size of n and read numbers one by one
  std::vector<int> second(n);

  for (int i = 0; i < n; ++i) {
    cin >> second[i];
  }

  PrintVector(second);


  vector <int> third(n);

  for (int& element: third) {
    cin >> element;
  }

  PrintVector(third);
  */

  /*
  // In this example we want to read a file
  // Remember to create file 1.txt before you read it

  // To create input stream use ifstream and remember to include <fstream> to use this class
  ifstream input("1.txt");

  string s;


  // If file doesn't exist or we can't open a file .is_open() will return false
  // Before reading file we want to check is it open or not

  if (input.is_open()) {
    while (getline(input, s)) {
      cout << s << endl;
    }
  } else {
    cout << "Error!" << endl;
  }

  */

  /*
  // We want to read date from file
  // The format of a date is year-month-day


  // In this example we want to read a file
  // Remember to create file 1.txt before you read it,
  // and fill it with date in year-month-day format


  ifstream input("1.txt");

  if (!input.is_open()) {
    cout << "Error!" << endl;
  }

  string year;
  string month;
  string day;


  // Let's use the third parameter of getline
  // Using this parameter we can read until the '-' symbol
  // Be the default getline reads until '\n'

  getline(input, year, '-');
  cout << year << endl;

  getline(input, month, '-');
  cout << month << endl;

  getline(input, day, '-');
  cout << day << endl;

  */


  /*

 // To read a date in year-month-day format
 // we can also use ">>" operator

  ifstream input("1.txt");

  if (!input.is_open()) {
    cout << "Error!" << endl;
  }

  int year;
  int month;
  int day;


  // ignore function just skip n symbols
  input >> year;
  input.ignore(1);

  input >> month;
  input.ignore(1);

  input >> day;

  cout << year << '-' << month << '-' << day;

  */


  /*
  // To write something to file use output stream output

   ofstream output("2.txt");
  output << "Hello world!" << endl;
  output << 1 << ' ' << "123" << endl;
  output.close();

  // Of course you can read it
  ifstream input("2.txt");
  cout << ReadFile(input);
  input.close();


  cout << "Read file again" << endl;


  // To add something to the existing file use ios::app
  // otherwise you will create new empty file and preavious file will be deleted
  ofstream output_("2.txt", ios::app);
  output_ << "New line" << endl;
  output_.close();

  ifstream input_("2.txt");
  cout << ReadFile(input_);

  */

  /*
  // To print float numbers with precision use setprecision

  ifstream input("double.txt");

  double d;

  input >> d;
  cout << setprecision(3) << d;

  */
  return 0;
}