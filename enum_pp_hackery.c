#include <stdio.h>

#define ENUM_PP_ITER_BODY(x) x,
#define ENUM_NAME_PP_ITER_BODY(x) (#x),
#define ENUM_COUNT_PP_ITER_BODY(x) + 1

#define PP_ITER_BODY ENUM_PP_ITER_BODY
enum {
#include "pp_iter_my_enum.h"
} my_enum;
#undef PP_ITER_BODY

#define PP_ITER_BODY ENUM_NAME_PP_ITER_BODY
const char *my_enum_names[] = {
#include "pp_iter_my_enum.h"
};
#undef PP_ITER_BODY

#define PP_ITER_BODY ENUM_COUNT_PP_ITER_BODY
const size_t my_enum_count = 0
#include "pp_iter_my_enum.h"
    ;

int main(void)
{
    printf("%zd members: %s %s %s\n",
           my_enum_count,
           my_enum_names[foo],
           my_enum_names[bar],
           my_enum_names[baz]);

    return 0;
}
