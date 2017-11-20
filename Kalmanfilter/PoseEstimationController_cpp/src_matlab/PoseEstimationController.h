//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PoseEstimationController.h
//
// Code generated for Simulink model 'PoseEstimationController'.
//
// Model version                  : 1.20
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Sun Sep 17 13:23:59 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_PoseEstimationController_h_
#define RTW_HEADER_PoseEstimationController_h_
#include "rtwtypes.h"
#include <cmath>
#include <string.h>
#ifndef PoseEstimationController_COMMON_INCLUDES_
# define PoseEstimationController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // PoseEstimationController_COMMON_INCLUDES_ 

// Child system includes
#include "PoseEstimationController.h"
#include "PoseEstimationController.h"
#include "PoseEstimationController.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define PoseEstimationController_M     (rtM)

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Custom Type definition for MATLAB Function: '<S10>/Correct'
#ifndef struct_tag_sJc0LrpsE91c2htQpVlRXsE
#define struct_tag_sJc0LrpsE91c2htQpVlRXsE

struct tag_sJc0LrpsE91c2htQpVlRXsE
{
  char_T FcnName[17];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 //struct_tag_sJc0LrpsE91c2htQpVlRXsE

#ifndef typedef_sJc0LrpsE91c2htQpVlRXsE
#define typedef_sJc0LrpsE91c2htQpVlRXsE

typedef struct tag_sJc0LrpsE91c2htQpVlRXsE sJc0LrpsE91c2htQpVlRXsE;

#endif                                 //typedef_sJc0LrpsE91c2htQpVlRXsE

// Custom Type definition for MATLAB Function: '<S11>/Correct'
#ifndef struct_tag_sex2lFeEcOPeDeDewnWtFVE
#define struct_tag_sex2lFeEcOPeDeDewnWtFVE

struct tag_sex2lFeEcOPeDeDewnWtFVE
{
  char_T FcnName[19];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 //struct_tag_sex2lFeEcOPeDeDewnWtFVE

#ifndef typedef_sex2lFeEcOPeDeDewnWtFVE
#define typedef_sex2lFeEcOPeDeDewnWtFVE

typedef struct tag_sex2lFeEcOPeDeDewnWtFVE sex2lFeEcOPeDeDewnWtFVE;

#endif                                 //typedef_sex2lFeEcOPeDeDewnWtFVE

// Custom Type definition for MATLAB Function: '<S13>/Predict'
#ifndef struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD
#define struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD

struct tag_sSJPS9Vsi6dADyZ4t3tkTWD
{
  char_T FcnName[18];
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 //struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD

#ifndef typedef_sSJPS9Vsi6dADyZ4t3tkTWD
#define typedef_sSJPS9Vsi6dADyZ4t3tkTWD

typedef struct tag_sSJPS9Vsi6dADyZ4t3tkTWD sSJPS9Vsi6dADyZ4t3tkTWD;

#endif                                 //typedef_sSJPS9Vsi6dADyZ4t3tkTWD

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE[12];         // '<S1>/Unit Delay'
  real_T UnitDelay_DSTATE_b[3];        // '<S9>/Unit Delay'
  real_T P_j[144];                     // '<S2>/DataStoreMemory - P'
  real_T x[12];                        // '<S2>/DataStoreMemory - x'
  real_T Jacobian[144];
  real_T Jacobian_m[144];
  real_T dHdx[60];
  real_T gain[60];
  real_T dHdx_c[60];
  real_T dHdx_k[36];
  real_T Pxy[36];
  real_T gain_c[36];
  real_T dHdx_b[25];
  real_T dv0[24];
  real_T b_A[25];
  real_T TmpSignalConversionAtSFunct[15];// '<S9>/MATLAB Function'
  real_T imvec[12];
  real_T z[12];
  real_T imz[12];
  real_T UnitDelay[12];                // '<S1>/Unit Delay'
  real_T R[9];
  real_T dv1[6];
  real_T b_z[5];
  real_T imz_p[5];
  real_T FunctionCaller[5];            // '<S3>/Function Caller'
  real_T rtb_UnitDelay_f_c[5];
  real_T step[4];
  real_T b_z_f[3];
  real_T imz_g[3];
  real_T UnitDelay_f[3];               // '<S9>/Unit Delay'
  real_T Add6;                         // '<S8>/Add6'
  real_T Add5;                         // '<S8>/Add5'
  real_T Add4;                         // '<S8>/Add4'
  real_T Add3;                         // '<S8>/Add3'
  real_T c_t;
  real_T cos_g;                        // '<S8>/cos'
  real_T rtb_acc_scale_m;
  real_T ab_idx_0;
  real_T b_idx_1;
  real_T b_idx_2;
  real_T ab_idx_1;
  real_T ab_idx_2;
  real_T ab_idx_3;
  real_T h_idx_3;
  real_T accelerometer_idx_0;
  real_T accelerometer_idx_1;
  real_T accelerometer_idx_2;
  real_T magnetometer_idx_0;
  real_T magnetometer_idx_1;
  real_T y_idx_0;
  real_T y_idx_1;
  real_T y_idx_2;
  real_T AHRS_Quaternion_idx_3;
  real_T rtb_TWB_gain_idx_0;
  real_T rtb_TWB_gain_idx_1;
  real_T rtb_TWB_gain_idx_2;
  real_T rtb_acc_scale_idx_0;
  real_T rtb_acc_scale_idx_1;
  real_T temp;
  real_T s;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int32_T i;
  int32_T i0;
  int32_T i1;
  int32_T jp;
  int32_T j;
  int8_T ipiv[5];
} DW;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T TWB_data[3];                  // '<Root>/TWB_data '
  real_T drone_raw_data[11];           // '<Root>/drone_raw_data'
  real_T x_desired[4];                 // '<Root>/x_desired'
  boolean_T enableTWB;                 // '<Root>/enableTWB'
  boolean_T enableDrone;               // '<Root>/enableDrone'
} ExtU;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T x[12];                        // '<Root>/x'
  real_T u[4];                         // '<Root>/u'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
};

// Block signals and states (auto storage)
extern DW rtDW;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with auto storage)
  extern ExtU rtU;

  // External outputs (root outports fed by signals with auto storage)
  extern ExtY rtY;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PoseEstimationController_initialize(void);
  extern void PoseEstimationController_step(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S10>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S11>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S2>/DataTypeConversion_uMeas1' : Unused code path elimination
//  Block '<S2>/DataTypeConversion_uMeas2' : Unused code path elimination
//  Block '<S2>/DataTypeConversion_uState' : Unused code path elimination
//  Block '<S2>/MeasurementFcn1Inputs' : Unused code path elimination
//  Block '<S2>/MeasurementFcn2Inputs' : Unused code path elimination
//  Block '<S13>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S2>/StateTransitionFcnInputs' : Unused code path elimination
//  Block '<S2>/checkMeasurementFcn1Signals' : Unused code path elimination
//  Block '<S2>/checkMeasurementFcn2Signals' : Unused code path elimination
//  Block '<S2>/checkStateTransitionFcnSignals' : Unused code path elimination
//  Block '<S9>/To Workspace' : Unused code path elimination
//  Block '<S2>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_Enable2' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_Q' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_R1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_R2' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_y1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_y2' : Eliminate redundant data type conversion
//  Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
//  Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PoseEstimationController'
//  '<S1>'   : 'PoseEstimationController/ExtendedKalmanFilter '
//  '<S2>'   : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter'
//  '<S3>'   : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementDrone'
//  '<S4>'   : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementTWB'
//  '<S5>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function1'
//  '<S6>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function2'
//  '<S7>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3'
//  '<S8>'   : 'PoseEstimationController/ExtendedKalmanFilter /generateU'
//  '<S9>'   : 'PoseEstimationController/ExtendedKalmanFilter /raw_to_real_data'
//  '<S10>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct1'
//  '<S11>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct2'
//  '<S12>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Output'
//  '<S13>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Predict'
//  '<S14>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct1/Correct'
//  '<S15>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct2/Correct'
//  '<S16>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Predict/Predict'
//  '<S17>'  : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3/g(x,u)'
//  '<S18>'  : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3/v_p'
//  '<S19>'  : 'PoseEstimationController/ExtendedKalmanFilter /raw_to_real_data/MATLAB Function'

#endif                                 // RTW_HEADER_PoseEstimationController_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
