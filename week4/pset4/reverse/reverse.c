#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

#define WAV_HEADER_SIZE 44

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: %s, input.wav output.wav\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER input_header;
    fread(&input_header, WAV_HEADER_SIZE, 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(input_header)) {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&input_header, WAV_HEADER_SIZE, 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(input_header);

    // Write reversed audio to file
    // TODO #8
    int buf[block_size];
    fseek(input, -block_size, SEEK_END);
    while(fread(&buf, block_size, 1, input))
    {
        if (ftell(input) -2 * block_size < WAV_HEADER_SIZE)
        {
            fseek(input, -ftell(input) - WAV_HEADER_SIZE, SEEK_CUR);
            fwrite(&buf, ftell(input) - WAV_HEADER_SIZE, 1, output);
            break;
        }
        else
        {
            fwrite(&buf, block_size, 1, output);
            fseek(input, -2 * block_size, SEEK_CUR);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char *wave_format = "WAVE";
    for (int i = 0; i < 4; i++)
    {
       if (!(header.format[i] == wave_format[i]))
       {
            return 1;
       }
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}
