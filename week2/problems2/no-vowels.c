// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }
    string word = replace(argv[1]);
    printf("%s", word);
    return 0;
}

string replace(string word)
{
    for (int i=0, n=strlen(word); i < n; i++) {
        switch (word[i]) {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                continue;
        }
    }
    return word;
}
