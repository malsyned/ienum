#include <stdlib.h>

#define concat(a, b) a ## b
#define econcat(a, b) concat(a, b)

#define stringify(a) #a
#define estringify(a) stringify(a)

#define MEMBER_BODY(x) econcat(IENUM_NAME, econcat(_, x)),

#define IENUM MEMBER_BODY
enum {
IENUM_MEMBERS
} IENUM_NAME;
#undef IENUM

extern const char *econcat(IENUM_NAME, _name);
extern const char *econcat(IENUM_NAME, _names)[];
extern const size_t econcat(IENUM_NAME, _count);
