#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <cs50.h>

void swap(BYTE *a, BYTE *b);        // For reflect

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE gs = round(((int) image[i][j].rgbtBlue + (int) image[i][j].rgbtGreen + (int) image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = gs;
            image[i][j].rgbtGreen= gs;
            image[i][j].rgbtRed = gs;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int nRed = round((0.393 * (int) image[i][j].rgbtRed) + (0.769 * (int) image[i][j].rgbtGreen) + (0.189 * (int) image[i][j].rgbtBlue));
            int nGreen = round((0.349 * (int) image[i][j].rgbtRed) + (0.686 * (int) image[i][j].rgbtGreen) + (0.168 * (int) image[i][j].rgbtBlue));
            int nBlue = round((0.272 * (int) image[i][j].rgbtRed) + (0.534 * (int) image[i][j].rgbtGreen) + (0.131 * (int) image[i][j].rgbtBlue));

            if (nRed > 255)     // Logical paths
            {
                image[i][j].rgbtRed = 255;
                if (nGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                    if (nBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else if (nBlue < 255)
                    {
                        image[i][j].rgbtBlue = (BYTE) nBlue;
                    }
                }
                else if (nGreen < 255)
                {
                    image[i][j].rgbtGreen = (BYTE) nGreen;
                    if (nBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else if (nBlue < 255)
                    {
                        image[i][j].rgbtBlue = (BYTE) nBlue;
                    }
                }
            }
            else if (nRed < 255)
            {
                image[i][j].rgbtRed = (BYTE) nRed;
                if (nGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                    if (nBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else if (nBlue < 255)
                    {
                        image[i][j].rgbtBlue = (BYTE) nBlue;
                    }
                }
                else if (nGreen < 255)
                {
                    image[i][j].rgbtGreen = (BYTE) nGreen;
                    if (nBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                    else if (nBlue < 255)
                    {
                        image[i][j].rgbtBlue = (BYTE) nBlue;
                    }
                }
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])         // Width is really just total num elements in array, indexed from 1 (hence the need for width - 1 later)
{
    if ((width) % 2 == 1)       // Odd num elements in [width] (0 to width)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                swap(&image[i][j].rgbtBlue, &image[i][(width - 1) - j].rgbtBlue);
                swap(&image[i][j].rgbtGreen, &image[i][(width - 1) - j].rgbtGreen);
                swap(&image[i][j].rgbtRed, &image[i][(width - 1) - j].rgbtRed);
            }
        }
    }
    else                            // Even num elements
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= (width - 1) / 2; j++)
            {
                swap(&image[i][j].rgbtBlue, &image[i][(width - 1) - j].rgbtBlue);
                swap(&image[i][j].rgbtGreen, &image[i][(width - 1) - j].rgbtGreen);
                swap(&image[i][j].rgbtRed, &image[i][(width - 1) - j].rgbtRed);
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE icopy[height][width];     // Create duplicate image so as not to skew values of original image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            icopy[x][y] = image[x][y];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)       // Upper leftmost corner case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed + (int) icopy[i + 1][j].rgbtRed + (int) icopy[i + 1][j + 1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen + (int) icopy[i + 1][j].rgbtGreen +
                (int) icopy[i + 1][j + 1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue + (int) icopy[i + 1][j].rgbtBlue + (int) icopy[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == (width - 1))     // Upper rightmost corner case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i + 1][j].rgbtRed + (int) icopy[i][j - 1].rgbtRed + (int) icopy[i + 1][j - 1].rgbtRed + (int) icopy[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i + 1][j].rgbtGreen + (int) icopy[i][j - 1].rgbtGreen + (int) icopy[i + 1][j - 1].rgbtGreen +
                (int) icopy[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i + 1][j].rgbtBlue + (int) icopy[i][j - 1].rgbtBlue + (int) icopy[i + 1][j - 1].rgbtBlue + (int) icopy[i][j].rgbtBlue) / 4.0);
            }
            else if (i == (height - 1) && j == 0)       // Bottom leftmost corner case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed + (int) icopy[i - 1][j + 1].rgbtRed + (int) icopy[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen + (int) icopy[i - 1][j + 1].rgbtGreen +
                (int) icopy[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue + (int) icopy[i - 1][j + 1].rgbtBlue + (int) icopy[i][j].rgbtBlue) / 4.0);
            }
            else if (i == (height - 1) && j == (width - 1))     // Bottom rightmost corner case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j].rgbtRed + (int) icopy[i][j - 1].rgbtRed + (int) icopy[i - 1][j - 1].rgbtRed + (int) icopy[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j].rgbtGreen + (int) icopy[i][j - 1].rgbtGreen + (int) icopy[i - 1][j - 1].rgbtGreen +
                (int) icopy[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j].rgbtBlue + (int) icopy[i][j - 1].rgbtBlue + (int) icopy[i - 1][j - 1].rgbtBlue + (int) icopy[i][j].rgbtBlue) / 4.0);
            }
            else if (i == 0)        // Upper edge case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i][j - 1].rgbtRed + (int) icopy[i][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed + (int) icopy[i + 1][j - 1].rgbtRed +
                (int) icopy[i + 1][j].rgbtRed + (int) icopy[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i][j - 1].rgbtGreen + (int) icopy[i][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen + (int) icopy[i + 1][j - 1].rgbtGreen +
                (int) icopy[i + 1][j].rgbtGreen + (int) icopy[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i][j - 1].rgbtBlue + (int) icopy[i][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue + (int) icopy[i + 1][j - 1].rgbtBlue +
                (int) icopy[i + 1][j].rgbtBlue + (int) icopy[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == 0)        // Left edge case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j].rgbtRed + (int) icopy[i - 1][j + 1].rgbtRed + (int) icopy[i][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed +
                (int) icopy[i + 1][j].rgbtRed + (int) icopy[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j].rgbtGreen + (int) icopy[i - 1][j + 1].rgbtGreen + (int) icopy[i][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen +
                (int) icopy[i + 1][j].rgbtGreen + (int) icopy[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j].rgbtBlue + (int) icopy[i - 1][j + 1].rgbtBlue + (int) icopy[i][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue +
                (int) icopy[i + 1][j].rgbtBlue + (int) icopy[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == (width - 1))      // Right edge case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtRed + (int) icopy[i - 1][j].rgbtRed + (int) icopy[i][j - 1].rgbtRed + (int) icopy[i][j].rgbtRed +
                (int) icopy[i + 1][j - 1].rgbtRed + (int) icopy[i + 1][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtGreen + (int) icopy[i - 1][j].rgbtGreen + (int) icopy[i][j - 1].rgbtGreen + (int) icopy[i][j].rgbtGreen +
                (int) icopy[i + 1][j - 1].rgbtGreen + (int) icopy[i + 1][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtBlue + (int) icopy[i - 1][j].rgbtBlue + (int) icopy[i][j - 1].rgbtBlue + (int) icopy[i][j].rgbtBlue +
                (int) icopy[i + 1][j - 1].rgbtBlue + (int) icopy[i + 1][j].rgbtBlue) / 6.0);
            }
            else if (i == (height - 1))         // Bottom edge case
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtRed + (int) icopy[i - 1][j].rgbtRed + (int) icopy[i - 1][j + 1].rgbtRed + (int) icopy[i][j - 1].rgbtRed +
                (int) icopy[i][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtGreen + (int) icopy[i - 1][j].rgbtGreen + (int) icopy[i - 1][j + 1].rgbtGreen +
                (int) icopy[i][j - 1].rgbtGreen + (int) icopy[i][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtBlue + (int) icopy[i - 1][j].rgbtBlue + (int) icopy[i - 1][j + 1].rgbtBlue + (int) icopy[i][j - 1].rgbtBlue +
                (int) icopy[i][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue) / 6.0);
            }
            else        // Everything else
            {
                image[i][j].rgbtRed = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtRed + (int) icopy[i - 1][j].rgbtRed + (int) icopy[i - 1][j + 1].rgbtRed + (int) icopy[i][j - 1].rgbtRed +
                (int) icopy[i][j].rgbtRed + (int) icopy[i][j + 1].rgbtRed + (int) icopy[i + 1][j - 1].rgbtRed + (int) icopy[i + 1][j].rgbtRed + (int) icopy[i + 1][j + 1].rgbtRed)
                / 9.0);
                image[i][j].rgbtGreen = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtGreen + (int) icopy[i - 1][j].rgbtGreen + (int) icopy[i - 1][j + 1].rgbtGreen +
                (int) icopy[i][j - 1].rgbtGreen + (int) icopy[i][j].rgbtGreen + (int) icopy[i][j + 1].rgbtGreen + (int) icopy[i + 1][j - 1].rgbtGreen + (int) icopy[i + 1][j].rgbtGreen +
                (int) icopy[i + 1][j + 1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = (BYTE) round(((int) icopy[i - 1][j - 1].rgbtBlue + (int) icopy[i - 1][j].rgbtBlue + (int) icopy[i - 1][j + 1].rgbtBlue + (int) icopy[i][j - 1].rgbtBlue +
                (int) icopy[i][j].rgbtBlue + (int) icopy[i][j + 1].rgbtBlue + (int) icopy[i + 1][j - 1].rgbtBlue + (int) icopy[i + 1][j].rgbtBlue + (int) icopy[i + 1][j + 1].rgbtBlue)
                / 9.0);
            }
        }
    }
    return;
}



void swap(BYTE *a, BYTE *b)
{
    int tmp = 0;        // Can store uint8_t data type no problem
    tmp = *a;           // First value to mediator
    *a = *b;            // First value to second value
    *b = tmp;           // Mediator (first value) to second value
}
