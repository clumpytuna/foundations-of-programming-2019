#include <string>
#include <iostream>

using namespace std;

class PhoneBook {
 public:
  void AddEntry(const string& name, const string& number) {
    // add phonebook entry
  }

  void ChangeNumber(const string& name, const string& new_number) {
    // change a phone number of an entry with  name equals to the first parameter to new_number
  }

  void ChangeName(const string& new_name, const string& number) {
    // change a phone number of an entry with number equals to the second parameter to new_name
  }

  string GetNumberByName(const string& name) {
    // return phone number corresponding to the name
  }

  string GetNameByNumber(const string& number) {
    // return name corresponding to the phone number
  }

 private:
  // add private fields here
};

int main () {

  PhoneBook myPhoneBook;

  myPhoneBook.AddEntry("Freddy Mercury", "8-800-555-35-35");
  myPhoneBook.AddEntry("Cesar", "8 (495) 642-50-50");
  myPhoneBook.AddEntry("Me", "8-111-111-11-11");

  cout << "Freddy's number: " << myPhoneBook.GetNumberByName("Freddy Mercury") << endl;
  cout << "Caesar's number: " << myPhoneBook.GetNumberByName("Cesar") << endl;

  myPhoneBook.ChangeNumber("Me", "8-900-800-70-60");

  cout << "My new number is:" << myPhoneBook.GetNumberByName("Me") << endl;
  cout << "8-800-555-35-35 is the phone number of " << myPhoneBook.GetNameByNumber("8-800-555-35-35") << endl;
  return 0;
}