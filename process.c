#include "common.h"
#include "process.h"
#include "calculate.h"

double process(char *expr_str, char *expr_end) {
    // printf("%s\n", expr_str);
    ptrdiff_t expr_len = expr_end - expr_str;
    char buff_str[expr_len];

    char *ptr = expr_str;
    for (; *ptr != '\0'; ++ptr) {
        if (*ptr == ')') {
            char *end_ptr = ptr, *begin_ptr = ptr;
            for (; *begin_ptr != '('; --begin_ptr);

            size_t size = count_ops(begin_ptr, end_ptr) + 1;
            Pair *expr_par = (Pair *)malloc(sizeof(Pair) * size);

            parse(begin_ptr, end_ptr, expr_par);
            // print_parsed(expr_par, size);
            calc(expr_par, &size);
            // print_parsed(expr_par, size);

            char num_str[NUM_SIZE];
            snprintf(num_str, NUM_SIZE, "%.17g", expr_par->num);

            strcpy(buff_str, num_str);
            strcpy(buff_str + strlen(num_str), end_ptr + 1);

            strcpy(begin_ptr, buff_str);

            // printf("%.*s\n",  (int)(expr_end - expr_str), expr_str);

            free(expr_par);
            ptr = expr_str;
        }

    }
    return strtod(expr_str, NULL);
}

bool reformat(char *dest_str, char *src_str, size_t src_len) {
    int cntr = 0;
    for (char *ptr = src_str; *ptr != '\0'; ++ptr) {
        if (*ptr == '(') {
            if (ptr[1] == ')') return false;
            ++cntr;
        }
        if (*ptr == ')') --cntr;
        if (!isdigit(*ptr) && !is_op(*ptr) && *ptr != '.' &&
            *ptr != ' ' && *ptr != ',') return false;
        if (*ptr == ',') *ptr = '.';

    }
    if (cntr) return false;

    *dest_str = '(';
    for (int i = 0, j = 1; src_str[i] != '\0'; ++i) {
        if (src_str[i] != ' ') {
            dest_str[j] = src_str[i];
            ++j;
        }
    }

    dest_str[strlen(dest_str)] = ')';
    dest_str[strlen(dest_str) + 1] = '\0';

    return true;
}









