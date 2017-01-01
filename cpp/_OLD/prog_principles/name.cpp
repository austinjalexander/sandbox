//#include "std_lib_facilities.h"
#include <iostream>
#include <string>

using namespace std;

int main(int n) {
  cout << "Enter name:";
  string name;
  cin >> name;
  cout << "\nHello: " << name << endl;

  constexpr double pi = 3.14159; // known at compile time
  const int c = n * pi; // not known at compile time, but never changed after
  double new_val = double(1);

  return 0;
}
