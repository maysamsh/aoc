#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aoc-d01.h"

int previous = -1;
int current = -1;
int counter = 0;

void swap(int number)
{
    previous = current;
    current = number;
}

void count()
{
    if (current > previous)
    {
        counter++;
    }
}

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index = 0;

    fp = fopen("input-d01.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (index == 0)
        {
            previous = atoi(line);
        }
        else if (index == 1)
        {
            current = atoi(line);
            count();
        }
        else
        {
            swap(atoi(line));
            count();
        }
        index++;
    }

    fclose(fp);
    if (line)
        free(line);
    printf("Count of inputs which are larger than their previous measurement: %d", counter);
    exit(EXIT_SUCCESS);
}