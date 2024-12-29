#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File can not be opened\n");
        return 1;
    }
    // Create a buffer for a block of data
    BYTE buffer[BLOCK];
    FILE *jpeg = NULL;
    int filenumber = 0;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK, card) == BLOCK)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

            if (jpeg != NULL)
            {
                fclose(jpeg);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", filenumber);
            jpeg = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK, jpeg);
            filenumber++;
        }
        else if (jpeg != NULL)
        {
            fwrite(buffer, 1, BLOCK, jpeg);
        }
    }
    fclose(jpeg);
    fclose(card);
    return 0;
}
