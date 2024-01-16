#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int size_string, char **string)
{
    int i = size_string - 2;
    int j = size_string - 1;
    char *temp;

    while (i >= 0 && strcmp(string[i], string[i+1]) >= 0)
    {
        i--;
    }

    if (i < 0)
    {
        return 0;
    }

    while (j >= 0 && strcmp(string[j], string[i]) <= 0)
    {
        j--;
    }

    temp = string[i];
    string[i] = string[j];
    string[j] = temp;

    int left = i + 1;
    int right = size_string - 1;
    while (left < right)
    {
        temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        left++;
        right--;
    }

    return 1;
}

int main()
{
    char **string;
    int size_string;

    scanf("%d", &size_string);

    string = (char**) calloc(size_string, sizeof(char*));

    for (int k = 0; k < size_string; k++)
    {
        string[k] = (char*) calloc(11, sizeof(char));
        scanf("%s", string[k]);
    }

    do
    {
        for (int i = 0; i < size_string; i++)
        {
            printf("%s%c",string[i], i == size_string - 1 ? '\n': ' ');
        }
    }

    while (next_permutation(size_string, string));

    for (int j = 0; j < size_string; j++)
		free(string[j]);
	free(string);

    return 0;
}

