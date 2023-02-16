/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * utils.c
 *
 */
#include <stdio.h>

#include "utils.h"

int find_max_rec(int array[], int n)
{
    if (n == 1) return array[0];
    return (MAX_2_ELEMENTS(array[n-1], find_max_rec(array, n-1)));
}

int sum_array_rec(int array[], int n)
{
    if (n == 1) return array[0];
    return (SUM_2_ELEMENTS(array[n-1], sum_array_rec(array, n-1)));
}