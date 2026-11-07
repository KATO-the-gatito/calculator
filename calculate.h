#ifndef CALCULATE_H
#define CALCULATE_H

#include "common.h"

int count_ops(char *, char *);
bool is_op(char ch);
void parse(char *, char *, Pair *);
double get_num(char *expr_ptr);
void calc(Pair *expr_par, size_t *size);
Pair calc_pair(Pair pl, Pair pr);

#endif // CALCULATE_H
