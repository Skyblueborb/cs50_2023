#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool is_valid(long number);

int main(void)
{
    long card;
    do {
        card = get_long("Number: ");
    }
    while (card < 0);

    if (is_valid(card)) {
        if (card / 1000000000000 == 4 || card / 1000000000000000 == 4) printf("VISA\n");
        else if (card / 1000000000000000 == 5) {
            switch (card / 100000000000000 % 50)
            {
                case 1 ... 5:
                    printf("MASTERCARD\n");
                    break;
                default:
                    printf("INVALID\n");
            }
        }
        else if (card / 100000000000000 == 3) {
            switch (card / 10000000000000 % 30)
            {
                case 4:
                case 7:
                    printf("AMEX\n");
                    break;
                default:
                    printf("INVALID\n");
            }
        }
    }
    else printf("INVALID\n");
}

bool is_valid(long number)
{
    int sum = 0;
    int multiply = 0;
    bool operation = true; // sum = false; multiply = 1

    while (number > 0)
    {
        int digit = number % 10;
        if (operation) {
            sum += digit;
            operation = false;
        }
        else
        {
            if (digit * 2 >= 10) {
                multiply += digit * 2 % 10;
                multiply += digit * 2 / 10;
            }
            else multiply += digit * 2;
            operation = true;
        }
        number /= 10;
    }
    if ((sum + multiply) % 10 == 0) {
        return true;
    }
    else return false;

}
