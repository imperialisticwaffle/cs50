#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int pic_num = 0;
    char picname[4];
    string ext = ".jpg";
    sprintf(picname, "%03d", pic_num);
    printf("%s\n", picname);
    char filespec[strlen(picname) + strlen(ext) + 1];
    snprintf(filespec, sizeof(filespec), "%s%s", picname, ext);
    printf("%s\n", filespec);
    
    sprintf(picname, "%03d.jpg", pic_num);
    printf("%s\n", picname);
}