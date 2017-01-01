#include <iostream>
#include <cctype>
using namespace std;

int WordCount(string str) { 

	int count = 0;
  for (int i = 0; i < str.length(); i++) {
      char c = str[i];
  	if (isspace(c)) {
  		count++;
  	}
  }  
  return (count + 1); 
            
}


int main() { 
  
  // keep this function call here
  cout << WordCount("Argument goes here");
  return 0;
    
} 


