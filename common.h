#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stddef.h>

#define CNT_OF_STDOPS 8

typedef struct {
    double num;
    char op;
} Pair;

void print_parsed(Pair *expr_par, size_t size);
void print_str(Pair *expr_par, size_t size);

#endif // COMMON_H
