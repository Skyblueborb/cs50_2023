// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    int length = strlen(password);
    bool upper, lower, number, special;
    for (int i=0; i < length; i++) {
        if(isupper(password[i])) upper=true;
        else if (islower(password[i])) lower=true;
        else if (isdigit(password[i])) number=true;
        else if (ispunct(password[i])) special=true;
    }
    return upper && lower && number && special;
}
