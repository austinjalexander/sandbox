# make a note how the for- and while-loops end!
for i in 1..5
  integer_number = 0
  # the comma at the end of the print next line does something special;
  # can you guess what it is?
  print "\nPlease enter a number, then I'll double it: "
  integer_number = gets.chomp
  puts "You entered: " + integer_number
  puts "Your number doubled: " + (integer_number.to_i * 2).to_s + "\n"
end

counter = 0
while counter < 5
  integer_number = 0
  print "\nPlease enter a number, then I'll double it: "
  integer_number = gets.chomp
  puts "You entered: " + integer_number
  puts "Your number doubled: " + (integer_number.to_i * 2).to_s + "\n"
  counter = counter + 1
end
    
# while i'm using a string here, often Boolean values of 
# true or false are used in while-loop conditions
action = "continue"
while action != "quit"
  print "Type \"quit\" to exit the program: "
  action = gets.chomp
end
