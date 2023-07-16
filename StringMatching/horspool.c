#include <stdio.h>
#include <string.h>

#define MAX 500
int Table[MAX];

void shifttable(char pattern[])
{
    int i, j, len;
    len = strlen(pattern);

    for (i = 0; i < MAX; i++)
        Table[i] = len;

    for (j = 0; j < len - 1; j++)
        Table[pattern[j]] = len - 1 - j;
}

int horspool(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    printf("Length of text is %d\n", n);
    printf("Length of pattern is %d\n", m);

    int i = m - 1;
    while (i < n)
    {
        int j = 0;
        while ((j < m) && (pattern[m - 1 - j] == text[i - j]))
            j++;

        if (j == m)
            return (i - m + 1);
        else
            i += Table[text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[100];
    printf("Enter the Text string: ");
    gets(text);
    printf("Enter the Pattern: ");
    gets(pattern);

    shifttable(pattern);

    int pos = horspool(text, pattern);

    if (pos >= 0)
        printf("Pattern found at location: %d\n", pos);
    else
        printf("Pattern not found\n");
    return 0;
}