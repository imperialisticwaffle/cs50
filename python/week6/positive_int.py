def main():
    print(get_positive_int())
    return

def get_positive_int():
    while True:
        n = int(input("Input an integer: "))    # Once you declare a variable it will be available until the end of the function, but not across functions
        if n > 0:
            break
    return n

main()