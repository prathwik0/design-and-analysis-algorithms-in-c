#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100], pattern[10];
    printf("Enter the String: ");
    scanf("%s", string);
    printf("Enter the Pattern: ");
    scanf("%s", pattern);

    for (int i = 0; i <= strlen(string) - strlen(pattern); i++)
    {
        int j;
        for (j = 0; j < strlen(pattern); j++)
        {
            if (pattern[j] != string[i + j])
                break;
        }
        if (j == strlen(pattern))
        {
            printf("Pattern found at location: %d\n", i);
            exit(0);
        }
    }
    printf("Pattern not found\n");

    return 0;
}