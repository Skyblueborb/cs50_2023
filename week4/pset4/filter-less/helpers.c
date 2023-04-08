#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate sepia values
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Check if those values are correct
            if (sepiaRed > 255) sepiaRed = 255;
            if (sepiaBlue > 255) sepiaBlue = 255;
            if (sepiaGreen > 255) sepiaGreen = 255;

            // Change each pixel to to correct values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, n = width; j < width/2; j++, n--) {
            RGBTRIPLE buf = image[i][j];
            image[i][j] = image[i][n-1];
            image[i][n-1] = buf;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buf[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float cnt = 0.0;

            // k - rows
            for (int k = -1; k <= 1; k++)
            {
                // l - columns
                for (int l = -1; l <= 1; l++)
                {
                    if ((i + k >= 0 && i + k < height) && (j + l >= 0 && j + l < width))
                    {
                        sumRed += image[i + k][j + l].rgbtRed;
                        sumGreen += image[i + k][j + l].rgbtGreen;
                        sumBlue += image[i + k][j + l].rgbtBlue;
                        cnt++;
                    }
                }
            }

            buf[i][j].rgbtRed = round(sumRed / cnt);
            buf[i][j].rgbtGreen = round(sumGreen / cnt);
            buf[i][j].rgbtBlue = round(sumBlue / cnt);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = buf[i][j];
        }
    }
    return;
}

