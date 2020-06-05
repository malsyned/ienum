#include <stdio.h>

#define IENUM_NAME my_enum
#define IENUM_HEADER "ienum_my_enum.h"
#include "ienum_create.h"
#undef IENUM_NAME
#undef IENUM_HEADER

int main(void)
{
    printf("%zd members: %s %s %s\n",
           my_enum_count,
           my_enum_names[my_enum_foo],
           my_enum_names[my_enum_bar],
           my_enum_names[my_enum_baz]);

    return 0;
}
