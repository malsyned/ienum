#ifndef MY_ENUM_H
#define MY_ENUM_H

#include "ienum_start.h"
#define IENUM_NAME my_enum
#define IENUM_MEMBERS                           \
    IENUM(foo)                                  \
    IENUM(bar)                                  \
    IENUM(baz)
#include "ienum_decl.h"

#endif /* !MY_ENUM_H */
