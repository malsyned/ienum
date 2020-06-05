#ifndef OTHER_ENUM_H
#define OTHER_ENUM_H

#undef IENUM_NAME
#undef IENUM_MEMBERS
#define IENUM_NAME other_enum
#define IENUM_MEMBERS                           \
    IENUM(baz)                                  \
    IENUM(foo)                                  \
    IENUM(bar)                                  \
    IENUM(quux)
#include "ienum_decl.h"

#endif /* !OTHER_ENUM_H */
