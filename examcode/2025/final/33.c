#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isStringRotation(char* s1, char* s2)
{
    if (strlen(s1) != strlen(s2)) return false;

    int len = strlen(s1);
    char* temp = malloc((2 * len + 1) * sizeof(char));
    if (temp == NULL) return false;

    strcpy(temp, s1);
    strcat(temp, s1);

    bool result = (strstr(temp, s2) != NULL);

    free(temp);
    return result;
}