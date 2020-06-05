#include <stdio.h>

#include "my_enum.h"
#include "other_enum.h"

int main(void)
{
    enum other_enum i;

    printf("%s has %d members: %s %s %s\n",
           my_enum.name,
           (int)my_enum.count,
           my_enum.names[my_enum_foo],
           my_enum.names[my_enum_bar],
           my_enum.names[my_enum_baz]);
    printf("\n");

    printf("%s has %d members\n", other_enum.name, (int)other_enum.count);
    for (i = 0; i < other_enum.count; i++) {
        printf("%s == %d\n", other_enum.names[i], i);
    }

    return 0;
}
