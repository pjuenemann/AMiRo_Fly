#ifndef __c9_sharedTrackingLibrary_h__
#define __c9_sharedTrackingLibrary_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c9_cell_wrap_2
#define typedef_c9_cell_wrap_2

typedef struct {
  real_T f1[12];
} c9_cell_wrap_2;

#endif                                 /*typedef_c9_cell_wrap_2*/

#ifndef struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD
#define struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD

struct tag_sSJPS9Vsi6dADyZ4t3tkTWD
{
  char_T FcnName[18];
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD*/

#ifndef typedef_c9_sSJPS9Vsi6dADyZ4t3tkTWD
#define typedef_c9_sSJPS9Vsi6dADyZ4t3tkTWD

typedef struct tag_sSJPS9Vsi6dADyZ4t3tkTWD c9_sSJPS9Vsi6dADyZ4t3tkTWD;

#endif                                 /*typedef_c9_sSJPS9Vsi6dADyZ4t3tkTWD*/

#ifndef typedef_SFc9_sharedTrackingLibraryInstanceStruct
#define typedef_SFc9_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_sharedTrackingLibrary;
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_pS;
  void *c9_fEmlrtCtx;
  real_T (*c9_x)[12];
  real_T (*c9_xNew)[12];
  real_T (*c9_P)[144];
  real_T (*c9_Q)[144];
  real_T (*c9_PNew)[144];
} SFc9_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc9_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_sharedTrackingLibrary_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_sharedTrackingLibrary_get_check_sum(mxArray *plhs[]);
extern void c9_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
