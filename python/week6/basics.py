# Some basic review.

import cs50

answer = input("What's your name? ")    # "get_string" is not defined; you could do "from cs50 import get_string", or just import cs50, or import multiple functions w/ a comma separated list
print("Hello, " + answer)

# We can produce a variation of the print statement above with formatted strings

print(f"Hello, {answer}")

# Variable assignment

counter = 0
counter += 1    # Increment

# If conditions
x = int(input("x: "))       # Cast return value to int
y = int(input("y: "))

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x equals y")

# Addition of integers

print(x + y)        # Else if x and y were treated like ASCII characters, print would simply return both next to one another

a = cs50.get_int("a: ")
b = cs50.get_int("b: ")

if a < b:
    print("a is less than b")
elif a > b:
    print("a is greater than b")
else:
    print("a equals b")

# While block and for loops

i = 0
while i < 3:
    print("Hello, world")
    i += 1

for i in [0, 1, 2]:
    print("hello, world")

for i in range(0, 11, 2):     # range(start, stop, step). Stop is exclusive, meaning it doesn't get counted.
    print(i)


# More conditional practice

s = input("Do you agree? ")

if s.lower() in ["y", "yes"]:
    print("Agreed")
elif s.lower() in ["n", "no"]:
    print("Not agreed")


# Code design

def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

main()

# Print can take multiple arguments

for i in range(4):
    print("?", end = "")        # This makes it so our output, instead of ?\n?\n?\n (where \n is of course a newline), it will be "????".
print()     # Prints newline.

# Alternatively...

print("?" * 4)                  # "????"

# We can run python programs in the cs50 IDE with > python filename.py
# Python is a loosely typed language (unlike C which is a strongly typed language), meaning the onus is not on the programmer to continuously declare data types when initializing variables.

# Python uses an interpreter to convert your source code at runtime into machine readable code, whereas in C the compiler we used (clang) does that prior to runtime, hence faster program
# execution times in C.

