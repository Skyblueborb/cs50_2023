#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char subsitute(char c, string key);
bool check_key(string key);
bool hasDuplicateChars(string s);

int main(int argc, string argv[])
{
    string key;
    if(argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (!check_key(argv[1])) return 1;

    key = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i=0, n=strlen(plaintext); i < n; i++)
    {
        printf("%c", subsitute(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

bool check_key(string key)
{
    if (strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    for (int i=0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i])) return false;
    }
    if(hasDuplicateChars(key)) return false;

    return true;
}

char subsitute(char c, string key)
{
    if (islower(c))
        c = tolower(key[c-97]);
    else if (isupper(c))
        c = toupper(key[c-65]);
    return c;
}

bool hasDuplicateChars(string s)
{
    int len = strlen(s);

    // Loop for every single char, excluding the last one
    for (int i = 0; i < len - 1; i++) {
        // Comparing i and j results in comparing each char, with every other char available in the string
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                return true;
            }
        }
    }

    return false;
}
