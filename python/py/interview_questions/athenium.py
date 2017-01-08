# This was an interesting problem. I decided to use nearest-rank percentiles,
# in order to return the example result,
# although other results aren't always necessarily ideal. I have some notes 
# following the code below.

# I've included different cases and their behavior (commented).

#######
numeric_grades = []
# CASES
case = 0
# case 0; problem example
if case == 0:
  numeric_grades = [99, 92, 91, 91, # A
                    89, 85, 83, 82, # B
                    80, 79, 78, 78, # C
                    77, 76, 75, 74, # D
                    62, 55, 43, 20] # F
# case 1
elif case == 1:
  numeric_grades = [99, 92, 91, 91, 91, # A
                    85, 83, 82,         # B
                    80, 79, 78, 78,     # C
                    77, 76, 75, 74,     # D
                    62, 55, 43, 20]     # F
# case 2
elif case == 2:
  numeric_grades = [91, 91, 91, 91, 91, # A
                    91, 91, 91, 91, 91, # A
                    91, 91, 91, 91, 91, # A
                    91, 91, 91, 91,     # A
                    20]                 # F
# case 3
elif case == 3:
  numeric_grades = [91, 91, 91, 91, 91, # A
                    91, 91, 91, 91, 91, # A
                    91, 91, 91, 91, 91, # A
                    91, 91, 91, 91,     # A
                    20]                 # F
# case 4
elif case == 4:
  numeric_grades = [66] # A
# case 5
elif case == 5:
  numeric_grades = [66, 66] # A
# case 6
elif case == 6:
  numeric_grades = [66, 66, # A
                    65]     # D <-- it could be argued that this should be F
# case 7
elif case == 7:
  numeric_grades = [66, # A
                    65, # B <-- it could be argued that this should be F
                    65] # B <-- it could be argued that this should be F
# case 8
elif case == 8:
  numeric_grades = [66, # A
                    65, # B <-- it could be argued that this should be C
                    64] # D <-- it could be argued that this should be F
#######

def convert_numeric_to_alpha(numeric_grades):
  # LETTERS
  letter_grades = ["A", "B", "C", "D", "F"]

  # SORT ASCENDING FOR PERCENTILE CALCULATIONS
  sorted_numeric_grades = sorted(numeric_grades)

  # NUMBER OF GRADES
  n = len(sorted_numeric_grades)

  # NEAREST-RANK PERCENTILES
  top_20perc_A = sorted_numeric_grades[int(0.8 * n):]
  next_20perc_B = sorted_numeric_grades[int(0.6 * n):int(0.8 * n)]
  next_20perc_C = sorted_numeric_grades[int(0.4 * n):int(0.6 * n)]
  next_20perc_D = sorted_numeric_grades[int(0.2 * n):int(0.4 * n)]
  bottom_20perc_F = sorted_numeric_grades[:int(0.2 * n)]

  percentiles = [top_20perc_A, next_20perc_B, 
                 next_20perc_C, next_20perc_D, bottom_20perc_F]
  #print percentiles

  # LOOP THROUGH GRADES
  grades_converted = []
  for grade in numeric_grades:
    # LOOP THROUGH PERCENTILES
    for i in xrange(len(percentiles)):
      # IF GRADE IS IN PERCENTILE, CAPTURE AND BREAK 
      # (this keeps the same number in the same group)
      if grade in percentiles[i]:
        grades_converted.append(letter_grades[i])
        break

  # PRINT NUMERIC AND LETTER
  for i in xrange(len(numeric_grades)):
    print numeric_grades[i], grades_converted[i]

  # RETURN LETTER LIST
  return letter_grades

# CALL FUNCTION
convert_numeric_to_alpha(numeric_grades)

'''
NOTES:
At first glance, the problem seems trivial: break up a collection of numeric 
grades into 20% ranges. My natural inclination is to do some math for such 
a problem (e.g., find the range, create subranges using 20% of the range), 
however, after further reflection on the stated problem, 
and when I consider the edge and odd-numbered cases, 
the entire structure of the question and the example given compels 
me to ask a number of my own questions:

How should any of the following be returned?

[ 65 ] #=> [ "A" ] ?
[ 66, 65 ] #=> [ "A", "F" ] ?
[ 66, 65, 64 ] #=> [ "A", "B?C?D?", "F" ] ?
[ 66, 66, 65, 62 ] #=> [ "A", "A", "B?C?D?", "F" ] ?

The way in which the question is posed and the actual example given suggests 
that normal numeric properties of numbers other than natural ordering aren't 
being considered (thus, perhaps I shouldn't use math to determine 
quantitatively, for example, that 65 in the fourth example above could be 
labeled "B"). Instead, the question seems to be concerned with the 
labeling of groups of items (grouped by an intrinsic order and a certain 
number of members per group based on a percentage of the total number of elements), 
which means I should be able to ask the same types of questions for the 
following non-numeric lists:

[ "Zebra" ] #=> [ "A" ] ?
[ "Zebra", "Lion" ] #=> [ "A", "F" ] ?
[ "Zebra", "Snake", "Lion" ] #=> [ "A", "B?C?D?", "F" ] ?
[ "Zebra", "Zebra", "Snake", "Bat" ] #=> [ "A", "A", "B?C?D?", "F" ] ?

Thus, in order to return the correct answer for the example given, 
I chose to use nearest-rank percentiles, although, as I mentioned at the beginning 
of the file, their behavior is not necessarily ideal in edge cases (and when it 
comes to the domain of numeric grades converted to letter grades, 
not using calculated subranges can result in strange labels).
'''

