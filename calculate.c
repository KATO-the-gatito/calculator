#include "common.h"
#include "calculate.h"
#include "flags.h"

const char operations[CNT_OF_STDOPS] = {'^', '/', '*', '%', '-', '+', '(', ')'};
extern struct Flags flags;

int count_ops(char* begin_ptr, char *end_ptr) {
    size_t cnt = 0;
    for (int i = 0; begin_ptr + i != end_ptr; ++i) {
        if (is_op(begin_ptr[i]) && !(begin_ptr[i] == '-' && is_op(begin_ptr[i - 1]))) ++cnt;
    }
    return cnt - 1;
}

bool is_op(char ch) {
    for (int i = 0; i < CNT_OF_STDOPS; ++i) {
        if (ch == operations[i]) return true;
    }
    return false;
}

void parse(char *begin_ptr, char *end_ptr, Pair *expr_par) {
    ++begin_ptr;
    int i = 0;
    for (; begin_ptr != end_ptr; ++begin_ptr) {
        if (is_op(*begin_ptr) && !(*(begin_ptr) == '-' && is_op(*(begin_ptr - 1)))) {
            expr_par[i].op = *begin_ptr;
            expr_par[i].num = get_num(begin_ptr);
            ++i;
        }
    }
    expr_par[i].op = *begin_ptr;
    expr_par[i].num = get_num(begin_ptr);
}

double get_num(char *expr_ptr) {
    do {--expr_ptr;} while (!is_op(*(expr_ptr - 1)));
    if (*(expr_ptr - 1) == '-' && is_op(*(expr_ptr - 2))) --expr_ptr;
    return strtod(expr_ptr, NULL);
}

////////////////////////////////////////////////////////

void calc(Pair *expr_par, size_t *size) {
    if (flags.steps_f)
        print_str(expr_par, *size);
    for (int ops_i = 0; ops_i < CNT_OF_STDOPS - 1; ++ops_i) {
        for (int i = 0; i < *size; ++i) {
            if (expr_par[i].op == operations[ops_i]) {
                --(*size);
                expr_par[i] = calc_pair(expr_par[i], expr_par[i + 1]);
                for (int j = i + 1; j < *size; ++j) {
                    expr_par[j] = expr_par[j + 1];
                }
                --i;

                if (flags.steps_f)
                    print_str(expr_par, *size);
            }
        }
    }
}

Pair calc_pair(Pair pl, Pair pr) {
    double val = 0;

    switch (pl.op)
    {
    case '^':
        val = pow(pl.num, pr.num);
        break;
    case '*':
        val = pl.num * pr.num;
        break;
    case '/':
        val = pl.num / pr.num;
        break;
    case '%':
        val = (int)pl.num % (int)pr.num;
        break;
    case '-':
        val = pl.num - pr.num;
        break;
    case '+':
        val = pl.num + pr.num;
        break;
    default:
        return (Pair){0, '!'};
    }

    return (Pair){val, pr.op};
}