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
