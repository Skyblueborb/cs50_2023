#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);

int main(void)
{
    // Get height from user in the range <1,8>
    static int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    // Print a pyramid with the provided height
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        print_pyramid(i);
        printf(" ");

        print_pyramid(i);
        printf("\n");
    }
}

void print_pyramid(int n)
{
    for (int j=0; j < n + 1; j++)
    {
        printf("#");
    }
}
