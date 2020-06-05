#ifndef IENUM_H
#define IENUM_H

#include <stdlib.h>

struct ienum {
    const char *name;
    const char **names;
    size_t count;
};

#endif /* !IENUM_H */
