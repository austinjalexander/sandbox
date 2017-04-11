import java.util.Scanner;
// this import statement is Java's way of getting
// some pre-made code for you

public class Control {
  public static void main(String[] args) {

    // in Java, you can create the iterator in the for-loop header
    for (int i = 0; i < 5; i++) {
      int integer_number = 0;
      System.out.print("\nPlease enter a number, then I'll double it: ");
      Scanner keyboard = new Scanner(System.in);
      integer_number = keyboard.nextInt();
      System.out.println("You entered: " + integer_number);
      System.out.println("Your number doubled: " 
                + integer_number * 2 + "\n");
    }

    int counter = 0;
    while (counter < 5) {
      int integer_number = 0;
      System.out.print("\nPlease enter a number, then I'll double it: ");
      Scanner keyboard = new Scanner(System.in);
      integer_number = keyboard.nextInt();
      System.out.println("You entered: " + integer_number);
      System.out.println("Your number doubled: " 
                + integer_number * 2 + "\n");
      counter++;    
    }
    
    // while i'm using a string here, often Boolean values of 
    // true or false are used in while-loop conditions
    String action = "continue";
    // what do you think is happening with that ! in the next line?
    while (!(action.equals("quit"))) {
      System.out.print("Type \"quit\" to exit the program: ");
      Scanner keyboard = new Scanner(System.in);
      action = keyboard.next();
    }
  }

}

