#define concat(a, b) a ## b
#define econcat(a, b) concat(a, b)

#define stringify(a) #a
#define estringify(a) stringify(a)

#define MEMBER_BODY(x) econcat(IENUM_NAME, econcat(_, x)),
#define NAME_BODY(x) (estringify(IENUM_NAME) "::" #x),
#define COUNT_BODY(x) + 1

#define IENUM MEMBER_BODY
enum {
#include IENUM_HEADER
} IENUM_NAME;
#undef IENUM

#define IENUM NAME_BODY
const char *econcat(IENUM_NAME, _names)[] = 
{
#include IENUM_HEADER
};
#undef IENUM

#define IENUM COUNT_BODY
const size_t econcat(IENUM_NAME, _count) = 0
#include IENUM_HEADER
    ;
