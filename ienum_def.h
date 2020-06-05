#include <stdlib.h>
#include "pputil.h"

#define IENUM_NAME_BODY(x) (estringify(IENUM_NAME) "::" #x),
#define IENUM_COUNT_BODY(x) + 1

#define IENUM_NAMES_ARRAY_NAME econcat(IENUM_NAME, _names)

static const char *IENUM_NAMES_ARRAY_NAME[] = {
#define IENUM IENUM_NAME_BODY
    IENUM_MEMBERS
#undef IENUM
};

const struct ienum IENUM_NAME =
{
    estringify(IENUM_NAME),
    IENUM_NAMES_ARRAY_NAME,
    0
#define IENUM IENUM_COUNT_BODY
    IENUM_MEMBERS
#undef IENUM
};
