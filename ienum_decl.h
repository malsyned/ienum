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
#include "pputil.h"

#define IENUM_MEMBER_BODY(x) econcat(IENUM_NAME, concat(_, x)),

#define IENUM IENUM_MEMBER_BODY
enum IENUM_NAME {
    IENUM_MEMBERS
};
#undef IENUM

extern const struct ienum IENUM_NAME;
