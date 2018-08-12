/**
 * Resizes a 24-bit BMP image by a factor of n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile size\n");
        return 1;
    }

    // save the factor to resize in a variable.
    int n = atoi(argv[3]);

    // ensure that n is in the specified bound.
    if (n < 0 || n > 100)
    {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

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

    // create separate variable for outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPINFOHEADER out_bi;
    BITMAPFILEHEADER out_bf;

    memcpy(&out_bi, &bi, sizeof(BITMAPINFOHEADER));
    memcpy(&out_bf, &bf, sizeof(BITMAPFILEHEADER));

    // update outfile's BITMAPINFOHEADER
    out_bi.biWidth = bi.biWidth * n;
    out_bi.biHeight = bi.biHeight * n;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    out_bi.biSizeImage = ((sizeof(RGBTRIPLE) * out_bi.biWidth) + out_padding) * abs(out_bi.biHeight);

    // update outfile's BITMAPFILEHEADER
    out_bf.bfSize = out_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int in_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // store pixels here.
        RGBTRIPLE pixels[n];

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write pixel to array n times
            for (int k = 0; k < n; k++)
            {
                pixels[k] = triple;
            }

        }

        for (int l = 0; l < n; l++)
        {
            // write array to outfile.
            for (int m = 0; m < n; m++)
            {
                fwrite(&pixels[m], sizeof(RGBTRIPLE), 1, outptr);
            }

            // write outfile padding
            for (int o = 0; o < out_padding; o++)
            {
                fputc(0x00, outptr);
            }
        }

        // skip over infile padding.
        fseek(inptr, in_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}