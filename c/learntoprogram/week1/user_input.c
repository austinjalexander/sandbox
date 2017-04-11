#include <stdio.h>

/*** GREETINGS ***/
// ok, so main() looks a little different;
// it's got this "int" prefix and 
// there's that "return 0" statement at the bottom;
// just ignore them for now  :)

int main() { 

  /*** INFORMATION AND VARIABLES ***/
  // types of information:
  // information can be categorized;
  // for example, in this file, 
  // there are numbers and there are characters;
  // these can both be further categorized:
  // for example, numbers that use '.'
  // and numbers that don't

  // variables: you can think of them as containers
  // for information; in other words, they hold things 
  // (which is not really true, but it's easier 
  // to think about it this way)

  int integer_number = 0; 
  // "int" is short for integer, which means
  // it's non-decimal (so not 0.0) 
  // in this particular case, the number 0 
  // is being placed inside
  // a variable called "number"

  double decimal_number = 0.0; 
  // "double": you can think of these as decimals,
  // numbers that contain a decimal point

  char character_string[] = "Your Name Here"; 
  // "char" is short for "character";
  // the rest of this line can get a 
  // little complicated to explain...
  // for now, look at the "[]" part, just remember that
  // that's a thing (whatever it means);
  // otherwise, just know this: 
  // manipulating characters of text 
  // on computers is tough! 
  // machines think in 0's and 1's after all!

  // there are other types of data in C
  // (i.e., besides integers, doubles, and characters), 
  // but you can get pretty far with these three

  // NOTE: whenever you create a variable, 
  // you should always give it an initial value, even if it's " "

  printf("\nhello, world - from: %s\n", character_string);

  printf("\nPlease enter a number, then I'll double it: ");

  /** SCANF FOR USER INPUT ***/
  scanf("%d", &integer_number);
  // the & is necessary for scanf to work;
  // basically it's a special way to access 
  // the variable integer_number directly;
  // we'll deal with it more later
  printf("You entered: %d\n", integer_number);

  integer_number = integer_number * 2; // do some math

  printf("Your number doubled: %d\n\n", integer_number);

  return 0;
}

