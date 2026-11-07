#include "common.h"

void print_parsed(Pair *expr_par, size_t size) {
    for (int i = 0; i < size; ++i) {
        printf("(%lf, '%c'{%d}) ", expr_par[i].num, expr_par[i].op, (int)expr_par[i].op);
    }
    printf("\n");
}

void print_str(Pair *expr_par, size_t size) {
    for (int i = 0; i < size; ++i) {
        printf("%d%c", (int)expr_par[i].num, expr_par[i].op);
    }
    printf("\n");
}