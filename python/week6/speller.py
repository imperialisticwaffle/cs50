words = set()   # set() is a collection of values that handles duplicates for you

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:       # Iterates over each line
        words.add(line.rstrip())    # Strip trailing whitespace after each word
    file.close()
    return True

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def size():
    return len(words)