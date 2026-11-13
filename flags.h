#ifndef FLAGS_H
#define FLAGS_H

#include "common.h"

struct Flags {
    bool clean_f : 1;
    bool steps_f : 1;
};

bool process_flags(int, char **, char **);


#endif // FLAGS_H
