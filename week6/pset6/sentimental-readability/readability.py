# TODO
from cs50 import get_string

def main():
    text = get_string("Text: ")
    words = text.count(" ") +1
    letters = 0
    sentences = 0
    for char in text:
        if char.isalpha():
            letters += 1
        if char in ['.', '!', '?']:
            sentences += 1

    grade = 0.0588 * (letters/words*100) - 0.296 * (sentences/words*100) - 15.8;
    print(letters, words, sentences, grade)
    if grade > 16: print("Grade 16+")
    elif grade < 1: print("Before Grade 1")
    else: print(f"Grade {grade:.0f}")


main()
