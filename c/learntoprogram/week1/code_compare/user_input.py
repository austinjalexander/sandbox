# notice how we don't have to explictly declare the types
# of each variable (e.g., int, double, etc.); 
# moreover, we can actually put an integer in a variable on 
# one line and then put a string in the same variable on the next;
# oh boy can this dupe us!

integer_number = 0

decimal_number = 0.0

my_string = "Your Name Here"

valid = True

print "\nhello, world - from: " + my_string

print "\nPlease enter a number, then I'll double it:",
	
# raw_input() is used to get input from the user
integer_number = raw_input()

print "You entered: " + integer_number

# raw_input() gives us a string, so, do to math,
# we need to convert it to an integer
integer_number = int(integer_number) * 2

# but now to combine it with other strings,
# we have to convert the integer into a string!
print "Your number doubled: " + str(integer_number) + "\n"

