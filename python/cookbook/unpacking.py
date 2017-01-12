import random

grades = [random.randrange(100) for assigments in range(30)]
print(len(grades))
first, *middle, last = grades
print(len(middle))

record = ('Dave', 'dave@example.com', '773-555-1212', '847-555-1212')
name, email, *phone_numbers = record
print(phone_numbers)

*beginning, last = [10, 8, 7, 1, 9, 5, 10, 3]
print(beginning)
print(last)