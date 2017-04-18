#ifndef __c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_h__
#define __c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2
#define typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2

typedef struct {
  real_T f1[12];
} c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2;

#endif                                 /*typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2*/

#ifndef struct_tag_sJc0LrpsE91c2htQpVlRXsE
#define struct_tag_sJc0LrpsE91c2htQpVlRXsE

struct tag_sJc0LrpsE91c2htQpVlRXsE
{
  char_T FcnName[17];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sJc0LrpsE91c2htQpVlRXsE*/

#ifndef typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
#define typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE

typedef struct tag_sJc0LrpsE91c2htQpVlRXsE
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE;

#endif                                 /*typedef_c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE*/

#ifndef typedef_SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
#define typedef_SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent;
  boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_doneDoubleBufferReInit;
  uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_pM;
  void *c8_sFywiTZeQa1EYv2NwJ5ncFC_fEmlrtCtx;
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_x)[12];
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew)[12];
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_P)[144];
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew)[144];
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_yMeas)[3];
  real_T (*c8_sFywiTZeQa1EYv2NwJ5ncFC_R)[9];
} SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_check_sum
  (mxArray *plhs[]);
extern void c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
