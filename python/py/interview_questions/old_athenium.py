For question 2, I actually have my own questions, although perhaps I'm over-complicating things (something Jim and I actually discussed as a problem for new programmers!), but they've become difficult to un-see. 

At first glance, the problem seems trivial: break up a collection of numeric grades into 20% ranges. My natural inclination is to do some math for such a problem (e.g., find the range, create subranges using 20% of the range; use percentiles, etc.), however, after further reflection on the problem (particularly the edge [e.g., n = 4] and odd-numbered cases), the entire structure of the question and the example given compels me to ask a number of my own questions:

How would any of the following be returned?

[ 65 ] #=> [ "A" ] ?
[ 66, 65 ] #=> [ "A", "F" ] ?
[ 66, 65, 64 ] #=> [ "A", "B?C?D?", "F" ] ?
[ 66, 66, 65, 62 ] #=> [ "A", "A", "B?C?D?", "F" ] ?

The way in which the question is posed and the actual example given suggests that normal numeric properties of numbers other than natural ordering aren't being considered (thus, I'm unable to use math to determine quantitatively, for example, that 65 in the fourth example above could be labeled "B"). Instead, the question seems to be concerned with the labeling of groups of items (grouped by an intrinsic order and a certain number of members per group based on a percentage), which means I should be able to ask the same types of questions for the following non-numeric lists:

[ "Zebra" ] #=> [ "A" ] ?
[ "Zebra", "Lion" ] #=> [ "A", "F" ] ?
[ "Zebra", "Snake", "Lion" ] #=> [ "A", "B?C?D?", "F" ] ?
[ "Zebra", "Zebra", "Snake", "Bat" ] #=> [ "A", "A", "B?C?D?", "F" ] ?

So, I find myself perplexed. If I'm given a list only slightly different than the original, the requirement of first/next/last 20% groupings seems strange indeed:

original: 
| 99 92 91 91 | 89 85 83 82 | 80 79 78 78 | 77 76 75 74 | 62 55 43 20 |

slightly modified:
| 99 92 91 91 91 | 83 82 |? 80 79 78 78 |? 77 76 75 74 |? 62 55 43 20 | # ???

or:
| 99 92 91 89 89 | 85 83 82 |? 80 79 78 78 |? 77 76 75 74 |? 62 55 43 20 | # ???

In this last case, for example, based on the problem set up, 89 should (I think) go with the "top 20%" (i.e., with 99, 92, and 91), but that means that there is no longer an appropriate number of 20% groupings remaining (i.e., there is either no sub-next 20% or there is no last 20%). 

Moreover, without the ability to group using mathematically-calculated subranges (which could render the original example given incorrect), it's unclear how to work with, for example, an odd-numbered case:

| 99 92 91 91 |? 89 85 83 82 |? 80 79 78 78 |? 77 76 75 74 |? 62 55 43 |?

I can use 20% of 19 to create a subrange, but I'm unsure how to group 19 numbers into five groups based on 3.8 without using math.



'''
# get the max
max_grade = max(numeric_grades)
# get the min 
min_grade = min(numeric_grades) 
# find the range difference
range_diff = (max_grade - min_grade)
# calculate 20% subrange
subrange = range_diff * 0.2


current_range_max = max_grade

for grade in numeric_grades:




def get_letter(numeric_grades, letter_grades, grade):
  # settings
  max_grade = max(numeric_grades) 
  min_grade = min(numeric_grades) 
  range_diff = (max_grade - min_grade) * 0.2
  current_range_max = max_grade

  # loop for the number of letter grades (i.e., 5)
  for i in xrange(len(letter_grades)): 

    current_range_min = (current_range_max - range_diff)

    if grade >= current_range_min:
      print grade, letter_grades[i]
      break

    current_range_max -= range_diff


'''

'''

#numeric_grades = [65] # A 

#numeric_grades = [88, 88] # A, A

#numeric_grades = [88, 65] # A, F

#numeric_grades = [88, 77, 65] # A, F

numeric_grades = [5, 4, 3] # A, C, F 

#numeric_grades = [4, 2, 1, 5, 3]

sorted_numeric_grades = sorted(numeric_grades, reverse=True)



# if there is only one grade, it's A
if len(numeric_grades) == 1:
  print numeric_grades[0], "A"

# if there are only 2 grades,
elif len(numeric_grades) == 2:
  
  # if they are they are different, 
  # the greater is A, the lesser is F
  if numeric_grades[0] > numeric_grades[1]:
    print numeric_grades[0], "A"
    print numeric_grades[1], "F"
 
  # if they are the same, both are A's
  else:
    print numeric_grades[0], "A"
    print numeric_grades[1], "A"

# if there are only 3 grades,
elif len(numeric_grades) == 3:
  for grade in numeric_grades:
    print grade, 
'''










