#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int weeks;
    float sum, avg;
    char ans;
    weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks-1];

    for(int i=0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
        sum += hours[i];
    }
    ans = get_char("Enter T for total hours, A for average hours per week: ");
    if (tolower(ans) == 't') {
        printf("%.1f hours\n", sum);
    }
    else if (tolower(ans) == 'a') {
        printf("%.1f hours\n", sum / weeks);
    }
    return 0;
}
