/* To use:
   I. Create a header file for your enumeration
      1) Undefine IENUM_NAME and IENUM_MEMBERS
      2) Define IENUM_NAME to the C identifier prefix for your enum
      3) Define IENUM_MEMBERS to a sequence of calls to IENUM() with
      the identifiers for your enumeration, without the prefix
      4) Include "ienum_decl.h"
   II. Create a C file for your enumeration
      1) Include your header file
      2) Include "ienum_def.h"

   NOTE: You can only declare one introspectable enumeration per file
   this way.
 */

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
