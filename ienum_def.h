#include <stdlib.h>
#include "pputil.h"

#define IENUM_NAME_BODY(x) (estringify(IENUM_NAME) "::" #x),
#define IENUM_COUNT_BODY(x) + 1

const char *econcat(IENUM_NAME, _name) = estringify(IENUM_NAME);

#define IENUM IENUM_NAME_BODY
const char *econcat(IENUM_NAME, _names)[] =
{
    IENUM_MEMBERS
};
#undef IENUM

#define IENUM IENUM_COUNT_BODY
const size_t econcat(IENUM_NAME, _count) = 0
    IENUM_MEMBERS
    ;
