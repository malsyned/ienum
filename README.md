# ienum #

A C Preprocessor API for creating introspectable enums at compile time

# About #

When creating an introspectable enum (for example, `foo` with values `bar` and `baz`), **ienum** will define a standard C `enum` like:
```C
    enum foo {
       foo_bar,
       foo_baz
    };
```

It will also create a `const struct ienum` named after your enum (`const struct ienum foo` in this example) with the following members:
member|description
-|-
`size_t count` | the number of enum values defined (2 in this example)
`char *name` | the name of the enum (`"foo"` in this example)
`char **names` |the names of each value (`"bar"` and `"baz"` in this example)

NOTE: **ienum** is currently limited to creating enumerations whose members start at 0 and go up sequentially.

# Using #

To create an introspectable enumeration, you will need a `.c`/`.h` file pair for it. Note that **ienum** only supports one introspectable enumeration per file.

## Populating the `.h` file ##

Your C header file for your enumeration should start with standard multiple-include guards
```C
    #ifndef FOO_H
    #define FOO_H
```

Then undefine `IENUM_NAME` and `IENUM_MEMBERS` to prevent warnings if multiple introspectable enumeration headers are included in a single source file. Then, define `IENUM_NAME` as the C identifier that names your enum, and `IENUM_MEMBERS` as a whitespace-separated list of value names, surrounded by a call to the `IENUM()` macro:
```C
    #undef IENUM_NAME
    #undef IENUM_MEMBERS
    #define IENUM_NAME foo
    #define IENUM_MEMBERS  \
                IENUM(bar) \
                IENUM(baz)
```

Then, `#include` the header file *"ienum_decl.h"* and close your multiple-inclusion guard:
```C
    #include "ienum_decl.h"

    #endif /* !defined(FOO_H) */
```

## Populating the `.c` file ##

The C source file for your enumeration only needs to contain two lines. The first includes your header file, and the second includes *"ienum_def.h"*:
```C
    #include "foo.h"
    #include "ienum_def.h"
```

That's it!

## Using your enumeration ##

Simply include your enumeration's C header file and use the enumeration as you would any other enumeration in code. Remember that their names have been automatically prefixed with your enumeration's name and an underscore, so `IENUM(baz)` creates `foo_baz` in `enum foo`.

Additionally you can use your enumeration's introspection struct to access upper bounds for your enumeration or print out helpful debugging messages:
```C
    #include "foo.h"
    /* ... */
        enum foo x = foo_baz;
        if (x < foo.count)
            printf("%s_%s == %d\n", foo.name, foo.names[x], x)
```

# Optional Configuration #

name|description
-|-
`IENUM_SEP`|<p>Define this to a string in your enum's C file before including *ienum_decl.h* to change how your enum's `.names` strings are formatted. Without `IENUM_SEP`, names are just stringifications of whatever identifier was written inside `IENUM()` in `IENUM_MEMBERS`. With it, names are prefixed with the enum's name followed by IENUM_SEP.<p>For example, if you `#define IENUM_SEP "::"` then `foo.names[i]` will be `"foo::baz"` instead of just `"baz"`.<p>**NOTE**: `IENUM_SEP` can be defined for an entire project using the `-D` argument to most C compilers, or by including it in a project-wide configuration header.
