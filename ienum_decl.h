#include "ienum.h"

enum IENUM_NAME {
#define IENUM(x) IENUM_ECONCAT(IENUM_NAME, IENUM_CONCAT(_, x)),
    IENUM_MEMBERS
#undef IENUM

#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)
    /* For C89 compliance, makes sure enum isn't comma-terminated */
    IENUM_ECONCAT(IENUM_NAME, _DUMMY) = 0
#endif
};

extern const struct ienum IENUM_NAME;
