#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "aoc-d02.h"

int horizontal = 0;
int depth = 0;

void split(char str[])
{
    char piece1[10], piece2[10];
    char *p;

    p = strtok(str, " "); // call the strtok with str as 1st arg for the 1st time.
    if (p != NULL)        // check if we got a token.
    {
        strcpy(piece1, p);     // save the token.
        p = strtok(NULL, " "); // subsequent call should have NULL as 1st arg.
        if (p != NULL)         // check if we got a token.
            strcpy(piece2, p); // save the token.
    }

    int result;
    result = strcmp(piece1, "forward");
    if (result == 0)
    {
        horizontal += atoi(piece2);
    }

    result = strcmp(piece1, "up");
    if (result == 0)
    {
        depth -= atoi(piece2);
    }

    result = strcmp(piece1, "down");
    if (result == 0)
    {
        depth += atoi(piece2);
    }
}

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("input-d02.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        int linelen = strlen(line);
        char arr[10];
        strncpy(arr, line, linelen);
        split(arr);
    }
    printf("depth * horizontal_position: %d", horizontal*depth);
    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}