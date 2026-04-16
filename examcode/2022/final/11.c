#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compareLines(const char *lineOne, const char *lineTwo)
{
    if(*lineOne == '\0' && *lineTwo == '\0') return true;
    if(*lineOne == ' ' || *lineOne == '.') return compareLines(lineOne + 1, lineTwo);
    if(*lineTwo == ' ' || *lineTwo == '.') return compareLines(lineOne, lineTwo + 1);
    if(*lineOne == '\0' || *lineTwo == '\0') return false;
    if(*lineOne == *lineTwo) return compareLines(lineOne + 1, lineTwo + 1);
    return false;
}