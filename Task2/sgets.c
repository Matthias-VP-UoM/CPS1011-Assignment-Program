/*
 * sgets.c
 *
 *  Created on: Nov 21, 2014
 *      Author: mvella
 */
#include <stdio.h>
#include <string.h>
#include "sgets.h"

char *sgets(char *str, int size)
{

    char *ret;

    ret = fgets(str, size, stdin);

    if(!ret)
        return ret;

    if(str[strlen(str)-1] == '\n')
    {
        str[strlen(str)-1] = '\0';

    } else {
        while(getchar() != '\n');
    }

    return ret;
}