#ifndef __c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_h__
#define __c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c8_s51dhbM5MSl1aKB4b1sqy0_cell_2
#define typedef_c8_s51dhbM5MSl1aKB4b1sqy0_cell_2

typedef struct {
  real_T f1[12];
  real_T f2[5];
} c8_s51dhbM5MSl1aKB4b1sqy0_cell_2;

#endif                                 /*typedef_c8_s51dhbM5MSl1aKB4b1sqy0_cell_2*/

#ifndef struct_tag_sex2lFeEcOPeDeDewnWtFVE
#define struct_tag_sex2lFeEcOPeDeDewnWtFVE

struct tag_sex2lFeEcOPeDeDewnWtFVE
{
  char_T FcnName[19];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE
#define typedef_c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE

typedef struct tag_sex2lFeEcOPeDeDewnWtFVE
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE;

#endif                                 /*typedef_c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
#define typedef_SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_doneDoubleBufferReInit;
  uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sh;
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE c8_s51dhbM5MSl1aKB4b1sqy0_pM;
  void *c8_s51dhbM5MSl1aKB4b1sqy0_fEmlrtCtx;
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_x)[12];
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_xNew)[12];
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_P)[144];
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_PNew)[144];
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_yMeas)[5];
  real_T (*c8_s51dhbM5MSl1aKB4b1sqy0_R)[25];
} SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_check_sum
  (mxArray *plhs[]);
extern void c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
