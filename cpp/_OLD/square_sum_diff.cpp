#include <iostream>

using namespace std;


int main() { 
  
  int sum_of_squares = 0, square_of_sum = 0;
  for (int i = 0; i < 101; i++) {
    sum_of_squares += (i * i);
    square_of_sum += i;
  }

  square_of_sum *= square_of_sum;

  cout << (square_of_sum - sum_of_squares) << endl;


  return 0;
    
} 


