#ifndef __c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_h__
#define __c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#ifndef typedef_c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2
#define typedef_c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2

typedef struct {
  real_T f1[12];
} c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2;

#endif                                 /*typedef_c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2*/

#ifndef struct_tag_sex2lFeEcOPeDeDewnWtFVE
#define struct_tag_sex2lFeEcOPeDeDewnWtFVE

struct tag_sex2lFeEcOPeDeDewnWtFVE
{
  char_T FcnName[19];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
#define typedef_c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE

typedef struct tag_sex2lFeEcOPeDeDewnWtFVE
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE;

#endif                                 /*typedef_c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
#define typedef_SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_sfEvent;
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_doneDoubleBufferReInit;
  uint8_T c8_sJUjlCK20kX4xC834REUQpG_is_active_c8_sJUjlCK20kX4xC834REUQpG_;
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_pM;
  void *c8_sJUjlCK20kX4xC834REUQpG_fEmlrtCtx;
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_x)[12];
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_xNew)[12];
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_P)[144];
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_PNew)[144];
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_yMeas)[12];
  real_T (*c8_sJUjlCK20kX4xC834REUQpG_R)[144];
} SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_check_sum
  (mxArray *plhs[]);
extern void c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
