#include <stdio.h>
#include <string.h> // this is for strcmp()

/*** GREETINGS ***/
// control structures:
// for-loops and while-loops: 
// they run until they meet your condition
// (or at least until something else unexpected happens!)

int main() { 

  // say we want to ask the user to let us double her 
  // inputs five times:

  int i = 0; // i is short for "iterator"
  for (i = 0; i < 5; i++) {
    int integer_number = 0;
    printf("\nPlease enter a number, then I'll double it: ");
    scanf("%d", &integer_number);
    printf("You entered: %d\n", integer_number);
    printf("Your number doubled: %d\n\n", integer_number * 2);
  }
  // ok, so we're able to use < and > and <= and >=
  // and == and != to compare stuff

  // the following while loop runs just like the for loop
  int counter = 0;
  while (counter < 5) {
    int integer_number = 0;
    printf("\nPlease enter a number, then I'll double it: ");
    scanf("%d", &integer_number);
    printf("You entered: %d\n", integer_number);
    printf("Your number doubled: %d\n\n", integer_number * 2);
    counter++;    
  }

  // using either for or while is often a matter of subjective 
  // problem/task conceptualization; however, for-loops tend
  // to be a good fit when you want a loop to run a certain 
  // number of times; while-loops tend to be a good match when
  // you want a loop to run until something happens, like so:
  
  // run a loop until the user decides to quit
  char action[] = "continue";
  // don't mind the strcmp() part in the loop condition, but, 
  // if you had to guess, what would you think "strcmp" means?
  while (strcmp(action, "quit") != 0) {
    printf("Type \"quit\" to exit the program: ");
    scanf("%s", action);
  }

  return 0;
}

