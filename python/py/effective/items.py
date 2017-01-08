### Item 1
# $ python --version
# $ ptyhon3 --version

import sys
print(sys.version_info)
print(sys.version)

### Item 2
# PEP 8 Style Guide
for i in xrange(5):
    print i # four spaces of indentation

# 79 characters or less lines

if (2 + 2 == 4) and (2 + 2 == 4) and (2 + 2 == 4) and 
    (2 + 2 == 4):
    print("YEP")

# separate functions and classes in a file by two lines

def first_func():
  return True


def second_func():
  return False


class Person:
  def __init__(self, name):
    self.name = name

  def get_name(): # separate methods by one line
    return self.name


class Pet:
  def __init__(self, name):
    self.name = name

