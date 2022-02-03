text = input("Provide some text to analyze for readability: ")

def main():
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    print(f"Total letters: {letters}")
    print(f"Total words: {words}")
    print(f"Total sentences: {sentences}")
    wavg = (100 / words)
    L = (letters * wavg)
    S = (sentences * wavg)
    index = ((0.0588 * L) - (0.296 * S) - 15.8)
    if round(index) < 1:
        print("Before Grade 1")
    elif round(index) > 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

def count_letters(text):
    lcount = 0
    for letter in text:
        if (letter.lower()).isalpha() == True:
            lcount += 1
        else:
            continue
    return lcount

def count_words(text):
    wcount, i = 0, 0
    for letter in text:
        if letter == " " or (letter == "." and i == (len(text) - 1)) or (letter == "!" and i == (len(text) - 1)) or (letter == "?" and i == (len(text) - 1)):     # Figure out indices
            wcount += 1
            i += 1
        else:
            i += 1
            continue
    return wcount

def count_sentences(text):
    scount, i = 0, 0
    for letter in text:
        i += 1
        if i >= 3:
            if (letter == "." and text[i - 3].isupper() == True) or (letter == "." and text[i - 2].isupper() == True):
                continue
            elif (letter == "." and (i - 1) == (len(text) - 1)) or (letter == "!" and (i - 1) == (len(text) - 1)) or (letter == "?" and (i - 1) == (len(text) - 1)) or (letter == '"' and (i - 1) == (len(text) - 1)):
                scount += 1
            elif (letter == "." and text[i].isspace() == True) or (letter == "!" and text[i].isspace() == True) or (letter == "?" and text[i].isspace() == True):
                scount += 1
        else:
            continue
    return scount

if __name__ == "__main__":
    main()