import sys

if len(sys.argv) != 2:
    print("insufficient or excessive command line arguments")
    sys.exit(1)

print(f"hello, {sys.argv[1]}!")
sys.exit(0)