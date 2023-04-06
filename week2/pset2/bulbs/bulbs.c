#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int char_to_dec(char c);

int main(void)
{
    string message = get_string("Message: ");
    int binary_num[BITS_IN_BYTE];

    for (int i=0, n=strlen(message); i < n; i++)
    {
        // Decimal to binary, the binary_num is an array of bits
        int binary_num[BITS_IN_BYTE-1];
        for (int j=0; j < BITS_IN_BYTE; j++)
        {
            binary_num[j] = message[i] % 2;
            message[i] /= 2;
        }
        // Print the bulbs incrementing down from the largest index of the array
        for (int k=BITS_IN_BYTE-1; k >= 0; k--)
        {
            print_bulb(binary_num[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
