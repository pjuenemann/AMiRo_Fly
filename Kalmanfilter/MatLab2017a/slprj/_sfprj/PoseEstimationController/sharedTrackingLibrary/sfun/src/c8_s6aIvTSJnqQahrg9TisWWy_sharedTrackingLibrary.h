#ifndef __c8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibrary_h__
#define __c8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibrary_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c8_s6aIvTSJnqQahrg9TisWWy_cell_wrap_2
#define typedef_c8_s6aIvTSJnqQahrg9TisWWy_cell_wrap_2

typedef struct {
  real_T f1[12];
} c8_s6aIvTSJnqQahrg9TisWWy_cell_wrap_2;

#endif                                 /*typedef_c8_s6aIvTSJnqQahrg9TisWWy_cell_wrap_2*/

#ifndef struct_tag_sex2lFeEcOPeDeDewnWtFVE
#define struct_tag_sex2lFeEcOPeDeDewnWtFVE

struct tag_sex2lFeEcOPeDeDewnWtFVE
{
  char_T FcnName[19];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_c8_s6aIvTSJnqQahrg9TisWWy_sex2lFeEcOPeDeDewnWtFVE
#define typedef_c8_s6aIvTSJnqQahrg9TisWWy_sex2lFeEcOPeDeDewnWtFVE

typedef struct tag_sex2lFeEcOPeDeDewnWtFVE
  c8_s6aIvTSJnqQahrg9TisWWy_sex2lFeEcOPeDeDewnWtFVE;

#endif                                 /*typedef_c8_s6aIvTSJnqQahrg9TisWWy_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_SFc8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibraryInstanceStruct
#define typedef_SFc8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_s6aIvTSJnqQahrg9TisWWy_sfEvent;
  boolean_T c8_s6aIvTSJnqQahrg9TisWWy_doneDoubleBufferReInit;
  uint8_T c8_s6aIvTSJnqQahrg9TisWWy_is_active_c8_s6aIvTSJnqQahrg9TisWWy_sh;
  c8_s6aIvTSJnqQahrg9TisWWy_sex2lFeEcOPeDeDewnWtFVE c8_s6aIvTSJnqQahrg9TisWWy_pM;
  void *c8_s6aIvTSJnqQahrg9TisWWy_fEmlrtCtx;
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_x)[12];
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_xNew)[12];
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_P)[144];
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_PNew)[144];
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_yMeas)[5];
  real_T (*c8_s6aIvTSJnqQahrg9TisWWy_R)[25];
} SFc8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibrary_get_check_sum
  (mxArray *plhs[]);
extern void c8_s6aIvTSJnqQahrg9TisWWy_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
