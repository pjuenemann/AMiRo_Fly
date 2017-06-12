#ifndef __c2_ControllerForOriginSensordata_h__
#define __c2_ControllerForOriginSensordata_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c2_MadgwickAHRS
#define typedef_c2_MadgwickAHRS

typedef struct {
  real_T SamplePeriod;
  real_T Quaternion[4];
  real_T Beta;
} c2_MadgwickAHRS;

#endif                                 /*typedef_c2_MadgwickAHRS*/

#ifndef typedef_SFc2_ControllerForOriginSensordataInstanceStruct
#define typedef_SFc2_ControllerForOriginSensordataInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_ControllerForOriginSensordata;
  void *c2_fEmlrtCtx;
  real_T (*c2_data)[9];
  real_T *c2_Z;
  real_T *c2_Y;
  real_T *c2_X;
} SFc2_ControllerForOriginSensordataInstanceStruct;

#endif                                 /*typedef_SFc2_ControllerForOriginSensordataInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_ControllerForOriginSensordata_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_ControllerForOriginSensordata_get_check_sum(mxArray *plhs[]);
extern void c2_ControllerForOriginSensordata_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
