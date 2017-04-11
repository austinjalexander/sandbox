# note the use of :
for i in range(5):
  integer_number = 0
  # the comma at the end of the print next line does something special;
  # can you guess what it is?
  print "\nPlease enter a number, then I'll double it:",
  integer_number = raw_input()
  print "You entered: " + str(integer_number)
  print "Your number doubled: " + str(int(integer_number) * 2) + "\n"

counter = 0
while counter < 5:
  integer_number = 0
  print "\nPlease enter a number, then I'll double it:",
  integer_number = raw_input()
  print "You entered: " + str(integer_number)
  print "Your number doubled: " + str(int(integer_number) * 2) + "\n"
  counter = counter + 1
    
# while i'm using a string here, often Boolean values of 
# true or false are used in while-loop conditions
action = "continue"
while action != "quit":
  print "Type \"quit\" to exit the program:",
  action = raw_input()

