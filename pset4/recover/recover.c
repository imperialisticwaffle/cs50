/* Even though JPEGs are more complicated than BMPs, JPEGs have “signatures,” patterns of bytes that can distinguish them from other file formats. Specifically, the first three bytes of JPEGs
are:

0xff 0xd8 0xff (255, 216, 255)

from first byte to third byte, left to right. The fourth byte, meanwhile, is either 0xe0 (224), 0xe1 (225), 0xe2 (226), 0xe3 (227), 0xe4 (228), 0xe5 (229), 0xe6 (230), 0xe7 (231), 0xe8 (232),
0xe9 (233), 0xea (234), 0xeb (235), 0xec (236), 0xed (237), 0xee (238), or 0xef (239). Put another way, the fourth byte’s first four bits are 1110.

Odds are, if you find this pattern of four bytes on media known to store photos (e.g., my memory card), they demarcate the start of a JPEG. To be fair, you might encounter these patterns on
some disk purely by chance, so data recovery isn’t an exact science.

Fortunately, digital cameras tend to store photographs contiguously on memory cards, whereby each photo is stored immediately after the previously taken photo. Accordingly, the start of a JPEG
usually demarks the end of another. However, digital cameras often initialize cards with a FAT file system whose “block size” is 512 bytes (B). The implication is that these cameras only write
to those cards in units of 512 B. A photo that’s 1 MB (i.e., 1,048,576 B) thus takes up 1048576 ÷ 512 = 2048 “blocks” on a memory card. But so does a photo that’s, say, one byte smaller (i.e.,
1,048,575 B)! The wasted space on disk is called “slack space.” Forensic investigators often look at slack space for remnants of suspicious data.

The implication of all these details is that you, the investigator, can probably write a program that iterates over a copy of my memory card, looking for JPEGs’ signatures. Each time you find a
signature, you can open a new file for writing and start filling that file with bytes from my memory card, closing that file only once you encounter another signature. Moreover, rather than
read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for efficiency’s sake. Thanks to FAT, you can trust that JPEGs’ signatures will be “block-aligned.”
That is, you need only look for those signatures in a block’s first four bytes.

Realize, of course, that JPEGs can span contiguous blocks. Otherwise, no JPEG could be larger than 512 B. But the last byte of a JPEG might not fall at the very end of a block. Recall the
possibility of slack space. But not to worry. Because this memory card was brand-new when I started snapping photos, odds are it’d been “zeroed” (i.e., filled with 0s) by the manufacturer,
in which case any slack space will be filled with 0s. It’s okay if those trailing 0s end up in the JPEGs you recover; they should still be viewable.

For ref:
1 Block = 512 bytes
1 MB = 1,048,576 bytes
1 byte = 8 bits
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 1;
    }
    FILE *outptr = NULL;
    int pic_num = 0;
    char picname[8];

    if (argc != 2)
    {
        fprintf(stderr, "Invalid usage: excessive or insufficient command line arguments\n");
        return 1;
    }
    else
    {
        BYTE buffer[512];     // 512 bytes for buffer

        while (fread(buffer, 512, 1, inptr))     // While reading 512 bytes into buffer works
        {
            if (feof(inptr))
            {
                break;
            }
            else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))    // Characteristic first 4 bytes of new jpg using bitwise arithmetic
            {
                if (pic_num == 0)
                {
                    sprintf(picname, "%03i.jpg", pic_num);      // Convert int to string with leading zeros as necessary for filename
                    outptr = fopen(picname, "w");    // Create first output file
                    fwrite(buffer, 512, 1, outptr);
                    pic_num++;
                }
                else
                {
                    fclose(outptr);     // Close previous jpeg
                    sprintf(picname, "%03i.jpg", pic_num);      // Convert int to string with leading zeros as necessary for filename
                    outptr = fopen(picname, "w");    // Create first output file
                    fwrite(buffer, 512, 1, outptr);
                    pic_num++;
                }
            }
            else if (pic_num > 0)       // Avoid writing data until we have reached the first jpeg signature
            {
                fwrite(buffer, 512, 1, outptr);      // Write 512 byte blocks to specific jpg file outptr defined in above else if statement
            }
        }
        fclose(inptr);
        fclose(outptr);
    }
    return 0;
}