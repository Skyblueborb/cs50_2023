#include "helpers.h"

#define NO_COLOR 0x00

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for(int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            if(image[i][j].rgbtBlue == NO_COLOR && image[i][j].rgbtGreen == NO_COLOR && image[i][j].rgbtRed == NO_COLOR)
            {
                image[i][j].rgbtBlue = 0xff;
                image[i][j].rgbtGreen = 0xff;
            }
        }
    }
}
