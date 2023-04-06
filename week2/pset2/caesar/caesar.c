#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    string ciphertext = malloc(strlen(plaintext));
    for (int i=0, n=strlen(plaintext); i < n; i++) {
        ciphertext[i] = rotate(plaintext[i], key);
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool only_digits(string s)
{
    for(int i=0, n=strlen(s); i < n; i++)
    {
        if(!isdigit(s[i])) return false;
    }
    return true;
}

char rotate(char c, int key)
{
    if(isalpha(c)) {
        if(islower(c) && c + key % 26 > 122) c += key % 26 - 26;
        else if (isupper(c) && c + key % 26 > 90) c += key % 26 - 26;
        else c += key % 26;
    }
    return c;
}
