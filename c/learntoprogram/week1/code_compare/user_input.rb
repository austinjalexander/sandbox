# notice how we don't have to explictly declare the types
# of each variable (e.g., int, double, etc.); 
# moreover, we can actually put an integer in a variable on 
# one line and then put a string in the same variable on the next;
# oh boy can this dupe us!

integer_number = 0

decimal_number = 0.0

my_string = "Your Name Here"

valid = true

puts "\nhello, world - from: " + my_string

print "\nPlease enter a number, then I'll double it:"
	
# gets.chomp is used to get input from the user
integer_number = gets.chomp

puts "You entered: " + integer_number

# gets.chomp gives us a string, so, do to math,
# we need to convert it to an integer
integer_number = integer_number.to_i * 2

# but now to combine it with other strings,
# we have to convert the integer into a string!
puts "Your number doubled: " + integer_number.to_s + "\n\n"

