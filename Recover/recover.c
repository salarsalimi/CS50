#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc == 1 || argc > 2)
    {
        printf("please specify recover file as argument.\n./recovery file.raw ");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[512];
    int count_jpeg = 0;
    FILE *outptr = NULL;
    char filename[8] = {0};

    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", count_jpeg++);

            outptr = fopen(filename, "w");
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
    // close last opened outptr
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(file);

    return 0;
}
