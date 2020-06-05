#include <stdlib.h>

#define NAME_BODY(x) (estringify(IENUM_NAME) "::" #x),
#define COUNT_BODY(x) + 1

const char *econcat(IENUM_NAME, _name) = estringify(IENUM_NAME);

#define IENUM NAME_BODY
const char *econcat(IENUM_NAME, _names)[] =
{
IENUM_MEMBERS
};
#undef IENUM

#define IENUM COUNT_BODY
const size_t econcat(IENUM_NAME, _count) = 0
IENUM_MEMBERS
    ;
