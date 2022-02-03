import csv

with open("phonebook.csv", "a") as file:        # Automatically closes the file for you eventually
    name = input("Name: ")
    number = input("Number: ")
    writer = csv.writer(file)                   # Wrapping file with csv functionality
    writer.writerow([name, number])             # Writing to file