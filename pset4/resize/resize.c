// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
    int n = atoi(argv[1]);
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // make new headers
    BITMAPFILEHEADER bf2 = bf;
    BITMAPINFOHEADER bi2 = bi;

    // new width = old width * n
    bi2.biWidth = bi.biWidth * n;
    // new height = old height * n
    bi2.biHeight = bi.biHeight * n;
    printf("oldwidth%i\n", bi.biWidth);
    printf("newwidth%i\n", bi2.biWidth);

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // new padding uses bi2 width
    int newPadding = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

//   new biSizeIMage use new width, and new padding
    bi2.biSizeImage = ((sizeof(RGBTRIPLE) * bi2.biWidth) + newPadding) * abs(bi2.biHeight);

    // new bf size uses new biSize image and sizeof both new headers
    bf2.bfSize = bi2.biSizeImage + sizeof(bf2) + sizeof(bi2);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        printf("scanline up%i\n", i);
        RGBTRIPLE arr[100];
        int arrayIndex = 0;

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            printf("across old width:%i\n", j);
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write each triple into array above

            for (int k = 0; k < n; k++)
            {
                // put each triple into the row n times/
                arr[arrayIndex] = triple;
                printf("k%i n%i\n", k, n);
                printf("AR%i push triple\n", arrayIndex);
                arrayIndex++;
            }

        }

        // iterate
        for (int row = 0; row < n; row++)
        {
            printf("row:%i\n", row);
            //write tripls to width of new width
            for (int tripl = 0; tripl < arrayIndex; tripl++)
            {
                printf("tripl:%i\n", tripl);
                printf("AR:%i\n", arrayIndex);


                fwrite(&arr[tripl], sizeof(RGBTRIPLE), 1, outptr);
                printf("written to fwrite\n");
            }

            if (newPadding > 0)
            {
                for (int padCount = 0; padCount < newPadding; padCount++)
                {
                    printf("Pad%i\n", padCount);
                    // padding take width of file (width * n)
                    fputc(0x00, outptr);
                }
            }
        }
        arrayIndex = 0;
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
