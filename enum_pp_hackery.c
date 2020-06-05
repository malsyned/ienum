#include <stdio.h>

#include "my_enum.h"

int main(void)
{
    printf("%zd members: %s %s %s\n",
           my_enum_count,
           my_enum_names[my_enum_foo],
           my_enum_names[my_enum_bar],
           my_enum_names[my_enum_baz]);

    return 0;
}
