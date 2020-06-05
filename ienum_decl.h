/* To use:
   I. Create a header file for your enumeration
      1) Undefine IENUM_NAME and IENUM_MEMBERS
      2) Define IENUM_NAME to the C identifier prefix for your enum
      3) Define IENUM_MEMBERS to a sequence of calls to IENUM() with
         the identifiers for your enumeration, without the prefix
      4) Include "ienum_decl.h"
   II. Create a C file for your enumeration
      1) Include your header file
      2) Optionally define IENUM_SEP to a string to use to separate
         the enum name from member names in the member name
         strings. If IENUM_SEP is left undefined, member names will
         not be prefixed with their enum name.
      3) Include "ienum_def.h"

   NOTE: IENUM_SEP can also be configured site-wide by passing its
         definition in on the compile command line via build scripts.
   NOTE: You can only create ienums that increase sequentially from 0
   NOTE: You can only declare one introspectable enumeration per file
   this way.
 */

#include "ienum.h"

enum IENUM_NAME {
#define IENUM(x) IENUM_ECONCAT(IENUM_NAME, IENUM_CONCAT(_, x)),
    IENUM_MEMBERS
#undef IENUM

#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)
    /* For C89 compliance, makes sure enum isn't comma-terminated */
    IENUM_ECONCAT(IENUM_NAME, _DUMMY) = 0
#endif
};

extern const struct ienum IENUM_NAME;
