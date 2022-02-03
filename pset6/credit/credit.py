cc = input("Input credit card number: ")

def main():
    if (len(cc) != 13) and (len(cc) != 15) and (len(cc) != 16):
        print("INVALID")
    elif (len(cc) == 16 or len(cc) == 13) and int(cc[0]) == 4 and luhn(cc) == 0:
        print("VISA")
    elif len(cc) == 16 and int(cc[0]) == 5 and (int(cc[1]) > 0 and int(cc[1]) < 6) and luhn(cc) == 0:
        print("MASTERCARD")
    elif len(cc) == 15 and ((int(cc[0]) == 3 and int(cc[1]) == 4) or (int(cc[0]) == 3 and int(cc[1]) == 7)) and luhn(cc) == 0:
        print("AMEX")
    else:
        print("INVALID")

def luhn(cc):
    dig_tmp, dig_sum, sum1, sum2 = 0, 0, 0, 0
    if len(cc) % 2 == 0:                            # even case
        for i in range(0, (len(cc) - 1), 2):        # From first digit to second last
            dig_tmp = 2 * int(cc[i])
            if (dig_tmp) > 9:
                for dig in str(dig_tmp):
                    dig_sum += int(dig)
                sum1 += dig_sum
                dig_sum = 0                         # reset
            else:
                sum1 += dig_tmp
        for j in range(1, len(cc), 2):              # From second digit to last
            sum2 += int(cc[j])
    else:                                           # odd case
        for i in range(1, (len(cc) - 1), 2):        # From second digit to second last
            dig_tmp = 2 * int(cc[i])
            if (dig_tmp) > 9:
                for dig in str(dig_tmp):
                    dig_sum += int(dig)
                sum1 += dig_sum
                dig_sum = 0                         # reset
            else:
                sum1 += dig_tmp
        for j in range(0, len(cc), 2):          # From first digit to last
            sum2 += int(cc[j])
    return (sum1 + sum2) % 10

if __name__ == "__main__":
    main()




''' def check_card(cc):
    global cc2
    global cc3
    global sum1
    global sum2
    global rem
    if (len(cc) % 2) == 0:                          # If length is even (case is different)
        while cc2 > 1:
            if cc2 == cc:                           # For second last digit, special case
                cc2 /= 10                           # rm last digit
                if (2 * (cc2 % 10)) > 9:            # if 2 * last digit of cc2 is a two digit num
                    sum1 += (2 * (cc2 % 10)) / 10   # get first digit
                    sum1 += (2 * (cc2 % 10)) % 10   # get second digit
                else:
                    sum1 += 2 * (cc2 % 10)          # get new last digit
            else:
                cc2 /= 100                          # rm last digit
                if (2 * (cc2 % 10)) > 9:            # if 2 * last digit of cc2 is a two digit num
                    sum1 += (2 * (cc2 % 10)) / 10   # get first digit
                    sum1 += (2 * (cc2 % 10)) % 10   # get second digit
                else:
                    sum1 += 2 * (cc2 % 10)          # get new last digit
        while cc3 > 10:
                rem = cc3 % 10                          # get last digit
                sum2 += rem
                cc3 /= 100                              # get to third last digit, then 5th, then 7th, etc.

    else:                                           # If length is odd
        while cc2 > 10:
            if cc2 == cc:                           # For second last digit, special case
                cc2 /= 10                           # rm last digit
                if (2 * (cc2 % 10)) > 9:            # if 2 * last digit of cc2 is a two digit num
                    sum1 += (2 * (cc2 % 10)) / 10   # get first digit
                    sum1 += (2 * (cc2 % 10)) % 10   # get second digit
                else:
                    sum1 += 2 * (cc2 % 10)          # get new last digit
            else:
                cc2 /= 100                          # rm last digit
                if (2 * (cc2 % 10)) > 9:            # if 2 * last digit of cc2 is a two digit num
                    sum1 += (2 * (cc2 % 10)) / 10   # get first digit
                    sum1 += (2 * (cc2 % 10)) % 10   # get second digit
                else:
                    sum1 += 2 * (cc2 % 10)          # get new last digit
        while cc3 > 1:
            rem = cc3 % 10                          # get last digit
            cc3 /= 100                              # get to third last digit, then 5th, then 7th, etc.
            sum2 += rem

    if (len(cc) == 16) or (len(cc) == 13):
        if ((sum1 + sum2) % 10 == 0) and (floor(cc / (float(10 ** (len(cc) - 1)) + 0.5)) == 4):
            print("VISA")

        elif (len(cc) == 16) and (floor(cc / (float(10 ** (len(cc) - 2)))) < 56) and (floor(cc / (float(10 ** (len - 2)))) > 50) and ((sum1 + sum2) % 10 == 0): # Determine if first 2 digits are 51 to 55
            print("MASTERCARD")
        else:
            print("INVALID")

    elif (len(cc) == 15) and ((sum1 + sum2) % 10 == 0):
        if ((floor(cc / (float(10 ** (len - 2)) + 0.5))) == 34) or (floor(cc / (float(10 ** (len - 2)) + 0.5)) == 37):
            print("AMEX")
        else:
            print("INVALID")

    else:
        print("INVALID")

if __name__ == "__main__":
    main()
'''
