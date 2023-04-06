#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float determine_grade(string text);

int main(void)
{
    string text = get_string("Text: ");
    float grade = determine_grade(text);

    if (grade > 16) printf("Grade 16+\n");
    else if (grade < 1) printf("Before Grade 1\n");
    else printf("Grade %.0f\n", grade);

    return 0;
}

/*
*   Counts letters, words and sentences
*/
float determine_grade(string text) {
    string grade;
    float letters=0, sentences=0, words=0;
    float index;
    for (int i=0, n=strlen(text); i < n; i++)
    {
        // Counts letters
        if (isalpha(text[i])) letters++;

        // Counts sentences based on amount of punctuation
        switch (text[i]) {
            case '.':
            case '!':
            case '?':
                sentences++;
                break;
            case ' ':
                words++;
                break;
        }
    }
    // Correct the number of words, since all of the times, the number of words is one more than the number of spaces
    words++;

    index = 0.0588 * (letters/words*100) - 0.296 * (sentences/words*100) - 15.8;
    printf("%f, %f, %f, %f\n", letters, words, sentences, index);
    return index;
}

