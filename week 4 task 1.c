#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");
    float factor = atof(argv[3]);

    if (input == NULL || output == NULL)
    {
        return 1;
    }

    BYTE header[44];
    fread(header, 44, 1, input);
    fwrite(header, 44, 1, output);

    int16_t sample;
    while (fread(&sample, sizeof(sample), 1, input))
    {
        sample = sample * factor;
        fwrite(&sample, sizeof(sample), 1, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}