#include "common.h"

void print_parsed(Pair *expr_par, size_t size) {
    for (int i = 0; i < size; ++i) {
        printf("(%lf, '%c'{%d}) ", expr_par[i].num, expr_par[i].op, (int)expr_par[i].op);
    }
    printf("\n");
}

void print_str(Pair *expr_par, size_t size) {
    printf("  ");
    for (int i = 0; i < size; ++i) {
        if (expr_par[i].op != ')')
            printf("%.10g%c", expr_par[i].num, expr_par[i].op);
        else
            printf("%.10g", expr_par[i].num);
    }
    printf("\n");
}