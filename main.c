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

        right--;
    }



    return 1;
}



int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}



/*
int next_permutation(int num_strings, char **strings)
{
    int index_i = num_strings - 2;


    while (index_i >= 0 && strcmp(strings[index_i], strings[index_i + 1]) >= 0)
    {
        index_i--;
    }

    if (index_i < 0)
    {
       return 0;
    }

    int index_j = num_strings - 1;

    while (index_j > index_i && strcmp(strings[index_j], strings[index_i]) <= 0)
        {
            index_j--;
        }

    char *temp = strings[index_i];
    strings[index_i] = strings[index_j];
    strings[index_j] = temp;

    int left = index_i + 1;
    int right = num_strings - 1;
    while (left < right) {
        temp = strings[left];
        strings[left] = strings[right];
        strings[right] = temp;
        left++;
        right--;
    }

    return 1;
}*/
