from sys import argv            # Explicit declaration of argv import for access in Python

if len(argv) == 2:
    print(f"Hello, {argv[1]}!")
else:
    print("Hello, world!")