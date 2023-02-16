/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * utils.h
 *
 */
#ifndef UTILS_H
#define UTILS_H

#define MAX_2_ELEMENTS(a, b)    \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define SUM_2_ELEMENTS(a, b) \
    ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        (_a + _b);  })

int find_max_rec(int array[], int n);
int sum_array_rec(int array[], int n);

#endif /* UTILS_H */