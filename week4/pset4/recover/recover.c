#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    BYTE buffer[512];
    char filename[8];
    int i=0;
    FILE *jpg = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Perform a comparison to find jpgs, use some fancy bitwise operators to figure out the first 4 bits of the next byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (i > 0)
            {
                fclose(jpg);
            }
            sprintf(filename, "%03i.jpg", i);
            jpg = fopen(filename, "w");
            i++;
        }

        // Write to the file only if we have found a jpg
        if (i > 0)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, jpg);
        }
    }

    fclose(raw_file);
    fclose(jpg);

    return 0;
}
