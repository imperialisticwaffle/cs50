#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)       // Get into the habit of checking if allocated memory is invalid
    {
        return 1;
    }
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4 * sizeof(int));     // Now we realized we want a fourth element, here we use the "copy everything into new array" method. Realloc copies everything over to "tmp"
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    tmp[3] = 4;
    free(list);

    list = tmp;     // Point old list to new list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    free(list);

}