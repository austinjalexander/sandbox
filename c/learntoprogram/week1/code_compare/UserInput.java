import java.util.Scanner;
// this import statement is Java's way of getting
// some pre-made code for you

public class UserInput {
  public static void main(String[] args) {

  int integer_number = 0; 

  double decimal_number = 0.0; 

  String my_string = "Your Name Here";

  boolean valid = true;

  System.out.println("\nhello, world - from: " + my_string);
  // notice: this is println(), not print();
  // what do you think the difference is?

  System.out.print("\nPlease enter a number, "
                   + "then I'll double it: ");
	
  // so, to access the user's input,
  // we'll actually have to create something;
  // i'll call it "keyboard"
  Scanner keyboard = new Scanner(System.in);

  // then we'll use it to get an integer from the user:
  integer_number = keyboard.nextInt();

  System.out.println("You entered: "
                     + integer_number);

  integer_number = integer_number * 2; // do some math
  System.out.println("Your number doubled: " 
                     + integer_number + "\n");
  }
}

