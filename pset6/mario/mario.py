import sys

def main():
    height = input("Input a height: ")

    while height.isalpha() == True or height == "" or int(height) > 8 or int(height) < 1:
        height = input("Input a height: ")

    print_pyramid(height)
    sys.exit(0)

def print_pyramid(height):
    spaces = int(height) - 1
    hashes = 1
    for i in range(int(height)):
        print((" " * spaces) + ("#" * hashes) + "  " + ("#" * hashes))
        spaces -= 1
        hashes += 1

if __name__ == "__main__":
    main()