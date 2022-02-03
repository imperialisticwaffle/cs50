/* WAV files are a common file format for representing audio. WAV files store audio as a sequence of “samples”: numbers that represent the value of some audio signal at a particular point in
time. WAV files begin with a 44-byte “header” that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample.
After the header, the WAV file contains a sequence of samples, each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.

Scaling each sample value by a given factor has the effect of changing the volume of the audio. Multiplying each sample value by 2.0, for example, will have the effect of doubling the volume
of the origin audio. Multiplying each sample by 0.5, meanwhile, will have the effect of cutting the volume in half. */

// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint8_t byte;       // Custom data type unsigned int = byte
typedef int16_t two_bytes;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");      // Input is your pointer argument in read only
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    byte header[HEADER_SIZE];
    fread(header, sizeof(header), 1, input);
    fwrite(header, sizeof(header), 1, output);

    // TODO: Read samples from input file and write updated data to output file
    two_bytes buffer;       // <buffer> passed into fread() is a pointer value
    while(fread(&buffer, sizeof(two_bytes), 1, input))      // COME BACK AND CHECK THIS LATER *****************
    {
        if (feof(input))
            break;
        buffer *= factor;
        fwrite(&buffer, sizeof(two_bytes), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
