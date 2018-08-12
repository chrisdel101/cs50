# Questions

## What's `stdint.h`?
A standard used to provide consistency and adjusted the size/widths of integer types,
such as 32 or 64 bit. By importing the library the sizes can be set with functions to be a fixed width
whereever it is used.


TODO

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
These set an unsigned integer to represent exaclty the amount of bits that they are set to.
TODO

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
A BYTE is 8 bits, a DWORD is 32(8 bytes) bit unsigned integer with no first bit signed, LONG is 32(8 bytes) bit signed integer, and WORD is another 32(8 bytes`)
bit unsigned int.
TODO

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

TODO

## What's the difference between `bfSize` and `biSize`?
size of bitmap = bfsize / bi.sizeImage + sizeof(BMfileheader) + sizeof(BMinfoheader)
TODO

## What does it mean if `biHeight` is negative?

TODO

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

TODO

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

TODO

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO
