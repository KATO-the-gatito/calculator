#include "common.h"
#include "process.h"

struct {
    bool clean_f : 1;
} flags = {0};

int main(int argc, char **argv)
{
    for (char **arg = argv; *arg != NULL; ++arg) {
        if (!strcmp(*arg, "-c") || !strcmp(*arg, "--clean")) {
            flags.clean_f = true;
        }
    }

    size_t arg_len = strlen(argv[1]);
    char expr_str[arg_len + 3];

    if (!reformat(expr_str, argv[1], arg_len)){
        printf("Error: Incorrect expression\n");
        return -1;
    }

    // printf("%s\n", expr_str);

    double result = process(expr_str, expr_str + arg_len + 3);

    if (flags.clean_f) {
        printf("%.17g\n", result);
        return 0;
    }
    printf("result: %.17g\n", result);

    return 0;
}









