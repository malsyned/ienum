#include <stdlib.h>
#include "pputil.h"

#define IENUM_NAMES_ARRAY_NAME econcat(IENUM_NAME, _names)

static const char *IENUM_NAMES_ARRAY_NAME[] = {
#define IENUM(x) (estringify(IENUM_NAME) "::" #x),
    IENUM_MEMBERS
#undef IENUM
};

const struct ienum IENUM_NAME =
{
    estringify(IENUM_NAME),
    IENUM_NAMES_ARRAY_NAME,
    0
#define IENUM(x) + 1
    IENUM_MEMBERS
#undef IENUM
};
