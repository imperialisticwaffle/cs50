import sys
import csv
import re

database, all_str_max = [], []
seq = open(sys.argv[2])

with open(sys.argv[1], "r") as csvfile:
    reader = csv.reader(csvfile, delimiter = ",")
    for row in reader:
        database.append(row)

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py 'DATABASE' 'DNA SEQUENCE")

    str_count(database, seq)

    new_asm = list(map(str, all_str_max))       # Convert ASM to string list for comparison, not int

    for i in range(1, len(database)):           # Loop over all rows (individuals)
        name = database[i].pop(0)               # Remove first name
        if new_asm == database[i]:
            print(name)
            return name
            sys.exit(0)
    print("No match")
    sys.exit(0)


def str_count(database, seq):
    for i in range(1, len(database[0])):            # Loop over all STR listings in header row of database/csv
        current_str = database[0][i]                # For each STR type
        str_groups = re.findall(rf'(?:{current_str})+', seq.read())      # https://stackoverflow.com/questions/61131768/how-to-count-consecutive-repetitions-of-a-substring-in-a-string
        if len(str_groups) > 0:
            reps = int(len(max(str_groups, key = len)) / (len(database[0][i])))
            all_str_max.append(reps)
            seq.seek(0)                             # Place cursor at start
        else:
            seq.seek(0)
            continue
    return all_str_max

if __name__ == "__main__":
    main()