import sys

people = {
    "Brian": "+!-617-495-1000",
    "David": "+1-949-468-2750"
}

name = input("Enter a name to search: ")
if name in people:                              # Python searches keys first
    print(f"Number: {people[name]}")
    sys.exit(0)
else:
    sys.exit(1)