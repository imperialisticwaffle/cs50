#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get height from user
    int n;
    do
    {
        n = get_int("Input height: ");
    }
    while (n < 1 || n > 8);

    // Print pyramid
    switch(n)
    {
        case 1:
            printf("#  #\n");
            break;
        case 2:
            printf(" #  #\n##  ##\n");
            break;
        case 3:
            printf("  #  #\n ##  ##\n###  ###\n");
            break;
        case 4:
            printf("   #  #\n  ##  ##\n ###  ###\n####  ####\n");
            break;
        case 5:
            printf("    #  #\n   ##  ##\n  ###  ###\n ####  ####\n#####  #####\n");
            break;
        case 6:
            printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n######  ######\n");
            break;
        case 7:
            printf("      #  #\n     ##  ##\n    ###  ###\n   ####  ####\n  #####  #####\n ######  ######\n#######  #######\n");
            break;
        case 8:
            printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
            break;
        default:
            printf("Input height: ");
    }
}



/*
    // Print out pyramid
    for (int row = 0; row < n; row++)
    {
        for (int spaces1 = (n - 1); spaces1 > 0; spaces1--)
        {
            printf(" ");
            for (int block = 0; block < n; block++)
            {
                printf("#");
                if (block >= 0)
                {
                    printf("  ");
                }
                for (int block2 = 0; block2 < n; block2++)
                {
                    printf("#");
                    printf("\n");
                }
            }
        }
    }
}

*/