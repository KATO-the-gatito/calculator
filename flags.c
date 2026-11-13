#include "flags.h"

struct Flags flags = {0};

bool process_flags(int argc, char **argv, char **input_expr) {
    for (char **arg = argv; *arg != NULL; ++arg) {
        if (**arg != '-') *input_expr = *arg;
        else for (char *f = *arg + 1; *f != '\0'; ++f) {
            switch (*f) {
            case 'c':
                flags.clean_f = true;
                break;
            case 's':
                flags.steps_f = true;
                break;
            default:
                return false;
            }
        }

    }

    return true;
}