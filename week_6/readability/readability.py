import re


def main():
    text = input("Text: ")
    grade(count_letters(text), count_words(text), count_sentences(text))


def count_letters(text):
    char_list = list(text)
    count = 0

    for i in char_list:
        if i.isalpha():
            count += 1
    return count


def count_words(text):
    return len(text.split(" "))


def count_sentences(text):
    return len(re.split(r"[.!?]", text)) - 1


def grade(char, words, sentences):
    l = (char / words) * 100
    s = (sentences / words) * 100
    score = round(0.0588 * l - 0.296 * s - 15.8)

    if score < 1:
        print("Before Grade 1")
    elif score >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {score}")


main()
