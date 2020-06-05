#include <stdio.h>

#include "my_enum.h"
#include "other_enum.h"

int main(void)
{
    int i;

    printf("%s has %zd members: %s %s %s\n",
           my_enum_name,
           my_enum_count,
           my_enum_names[my_enum_foo],
           my_enum_names[my_enum_bar],
           my_enum_names[my_enum_baz]);
    printf("\n");

    printf("%s has %zd members\n", other_enum_name, other_enum_count);
    for (i = 0; i < other_enum_count; i++) {
        printf("%s == %d\n", other_enum_names[i], i);
    }

    return 0;
}
