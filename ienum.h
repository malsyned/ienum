#ifndef IENUM_H
#define IENUM_H

#include <stdlib.h>

#define IENUM_CONCAT(a, b) a ## b
#define IENUM_ECONCAT(a, b) IENUM_CONCAT(a, b)

#define IENUM_STRINGIFY(a) #a
#define IENUM_ESTRINGIFY(a) IENUM_STRINGIFY(a)

struct ienum {
    const char *name;
    const char **names;
    size_t count;
};

#endif /* !IENUM_H */
