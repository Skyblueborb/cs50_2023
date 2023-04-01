#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i=0, start_size, end_size;
    do {

        // TODO: Prompt for start size
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);
    int population=start_size;

    do {
        // TODO: Prompt for end size
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);


    // TODO: Calculate number of years until we reach threshold
    while (population < end_size)
    {
        population += (population / 3) - (population / 4);
        i++;
    }

    // TODO: Print number of years
    printf("Years: %i", i);
}
