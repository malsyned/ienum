#ifndef THIRD_ENUM_H
#define THIRD_ENUM_H

#undef IENUM_NAME
#undef IENUM_MEMBERS
#define IENUM_NAME third_enum
#define IENUM_MEMBERS                           \
    IENUM(some)                                 \
    IENUM(different)                            \
    IENUM(members)

#include "ienum_decl.h"

#endif /* !THIRD_ENUM_H */
