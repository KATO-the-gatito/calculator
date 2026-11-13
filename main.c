#include "common.h"
#include "process.h"
#include "flags.h"

extern struct Flags flags;

int main(int argc, char **argv)
{
    size_t arg_len = strlen(argv[1]);
    char *expr_str = malloc((arg_len + 3) * sizeof(char));
    char *input_expr = NULL;

    if (!process_flags(argc, argv, &input_expr)) {
        printf("Error: Incorrect flags\n");
        return -1;
    }
    if (!reformat(expr_str, input_expr, arg_len)){
        printf("Error: Incorrect expression\n");
        return -1;
    }

    if (flags.steps_f)
        printf("given expr: %s\n", expr_str);

    double result = process(expr_str, expr_str + arg_len + 3);

    if (flags.clean_f && !flags.steps_f) {
        printf("%.17g\n", result);
        return 0;
    }
    printf("result: %.17g\n", result);

    free(expr_str);

    return 0;
}









