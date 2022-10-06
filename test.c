#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split(char *string, char *seperators, int *count);

char **strtow(char *str)
{
  int count_strings = 0;
  char **split_strings = split(str, " ", &count_strings);

  // print out the substrings, which should be each word of the sentence above
 // for (int i = 0; i < count_strings; i++)
   // printf("%s\n", split_strings[i]);

  // free the dynamically allocated space for each string
  for (int i = 0; i < count_strings; i++)
    free(split_strings[i]);

  // free the dynamically allocated space for the array of pointers to strings
  free(split_strings);

  return (split_strings);
}

char **split(char *string, char *seperators, int *count)
{
  int len = strlen(string);


  *count = 0;
  int i = 0;
  while (i < len)
  {

    while (i < len)
    {
      if (strchr(seperators, string[i]) == NULL)
        break;
      i++;
    }

    int old_i = i;
    while (i < len)
    {
      if (strchr(seperators, string[i]) != NULL)
        break;
      i++;
    }

    if (i > old_i)
        *count = *count + 1;
  }

  char **strings = malloc(sizeof(char *) * *count);

  i = 0;

  char buffer[16384];
  int string_index = 0;
  while (i < len)
  {

    while (i < len)
    {
      if (strchr(seperators, string[i]) == NULL)
        break;
      i++;
    }

    int j = 0;
    while (i < len)
    {
      if (strchr(seperators, string[i]) != NULL)
        break;

      buffer[j] = string[i];
      i++;
      j++;
    }

    if (j > 0)
    {
      buffer[j] = '\0';

      int to_allocate = sizeof(char) * (strlen(buffer) + 1);

      strings[string_index] = malloc(to_allocate);

      strcpy(strings[string_index], buffer);

      string_index++;
    }
  }

  return strings;
}


void print_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i)
    {
        printf("%s\n", tab[i]);
    }
}


int main(void)
{
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Failed\n");
        return (1);
    }
    print_tab(tab);
    return (0);
}
