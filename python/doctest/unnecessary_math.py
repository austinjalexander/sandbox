'''
Module showing how doctests can be included with source code.
Each '>>>' line is run as if in a Python shell and counts as a test.
The next line, if not '>>>' is the expected output of the previous line.
If anything doesn't match exactly (including trailing spaces), the test fails.
'''

def multiply(a, b):
	"""
	>>> multiply(4, 3)
	12
	>>> multiply('a', 3)
	'aaa'
	"""
	return a * b

# $ python -m doctest -v unnecessary_math.py
