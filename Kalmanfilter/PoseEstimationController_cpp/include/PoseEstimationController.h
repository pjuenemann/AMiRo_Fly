/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PoseEstimationController.h
 *
 * Code generated for Simulink model 'PoseEstimationController'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Jun 12 11:18:41 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PoseEstimationController_h_
#define RTW_HEADER_PoseEstimationController_h_
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef PoseEstimationController_COMMON_INCLUDES_
# define PoseEstimationController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PoseEstimationController_COMMON_INCLUDES_ */

/* Child system includes */
#include "PoseEstimationController.h"
#include "PoseEstimationController.h"
#include "PoseEstimationController.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Custom Type definition for MATLAB Function: '<S10>/Correct' */
#ifndef struct_tag_sJc0LrpsE91c2htQpVlRXsE
#define struct_tag_sJc0LrpsE91c2htQpVlRXsE

struct tag_sJc0LrpsE91c2htQpVlRXsE
{
  char_T FcnName[17];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sJc0LrpsE91c2htQpVlRXsE*/

#ifndef typedef_sJc0LrpsE91c2htQpVlRXsE
#define typedef_sJc0LrpsE91c2htQpVlRXsE

typedef struct tag_sJc0LrpsE91c2htQpVlRXsE sJc0LrpsE91c2htQpVlRXsE;

#endif                                 /*typedef_sJc0LrpsE91c2htQpVlRXsE*/

/* Custom Type definition for MATLAB Function: '<S11>/Correct' */
#ifndef struct_tag_sex2lFeEcOPeDeDewnWtFVE
#define struct_tag_sex2lFeEcOPeDeDewnWtFVE

struct tag_sex2lFeEcOPeDeDewnWtFVE
{
  char_T FcnName[19];
  boolean_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sex2lFeEcOPeDeDewnWtFVE*/

#ifndef typedef_sex2lFeEcOPeDeDewnWtFVE
#define typedef_sex2lFeEcOPeDeDewnWtFVE

typedef struct tag_sex2lFeEcOPeDeDewnWtFVE sex2lFeEcOPeDeDewnWtFVE;

#endif                                 /*typedef_sex2lFeEcOPeDeDewnWtFVE*/

/* Custom Type definition for MATLAB Function: '<S13>/Predict' */
#ifndef struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD
#define struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD

struct tag_sSJPS9Vsi6dADyZ4t3tkTWD
{
  char_T FcnName[18];
  real_T HasJacobian;
  boolean_T HasAdditiveNoise;
};

#endif                                 /*struct_tag_sSJPS9Vsi6dADyZ4t3tkTWD*/

#ifndef typedef_sSJPS9Vsi6dADyZ4t3tkTWD
#define typedef_sSJPS9Vsi6dADyZ4t3tkTWD

typedef struct tag_sSJPS9Vsi6dADyZ4t3tkTWD sSJPS9Vsi6dADyZ4t3tkTWD;

#endif                                 /*typedef_sSJPS9Vsi6dADyZ4t3tkTWD*/

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[12];         /* '<S1>/Unit Delay' */
  real_T P_j[144];                     /* '<S2>/DataStoreMemory - P' */
  real_T x[12];                        /* '<S2>/DataStoreMemory - x' */
  real_T Add6;                         /* '<S9>/Add6' */
  real_T Add5;                         /* '<S9>/Add5' */
  real_T Add4;                         /* '<S9>/Add4' */
  real_T Add3;                         /* '<S9>/Add3' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2[11];                      /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[12];                     /* '<Root>/Out1' */
  real_T Out2[4];                      /* '<Root>/Out2' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void PoseEstimationController_initialize(void);
extern void PoseEstimationController_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S11>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_uMeas1' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_uMeas2' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_uState' : Unused code path elimination
 * Block '<S2>/MeasurementFcn1Inputs' : Unused code path elimination
 * Block '<S2>/MeasurementFcn2Inputs' : Unused code path elimination
 * Block '<S13>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S2>/StateTransitionFcnInputs' : Unused code path elimination
 * Block '<S2>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S2>/checkMeasurementFcn2Signals' : Unused code path elimination
 * Block '<S2>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<S17>/Output' : Unused code path elimination
 * Block '<S17>/White Noise' : Unused code path elimination
 * Block '<S18>/Output' : Unused code path elimination
 * Block '<S18>/White Noise' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S9>/To Workspace1' : Unused code path elimination
 * Block '<S2>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_Enable2' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_R2' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 * Block '<S2>/DataTypeConversion_y2' : Eliminate redundant data type conversion
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PoseEstimationController'
 * '<S1>'   : 'PoseEstimationController/ExtendedKalmanFilter '
 * '<S2>'   : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter'
 * '<S3>'   : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementDrone'
 * '<S4>'   : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementTWB'
 * '<S5>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function1'
 * '<S6>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function2'
 * '<S7>'   : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3'
 * '<S8>'   : 'PoseEstimationController/ExtendedKalmanFilter /Subsystem'
 * '<S9>'   : 'PoseEstimationController/ExtendedKalmanFilter /generateU'
 * '<S10>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct1'
 * '<S11>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct2'
 * '<S12>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Output'
 * '<S13>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Predict'
 * '<S14>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct1/Correct'
 * '<S15>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Correct2/Correct'
 * '<S16>'  : 'PoseEstimationController/ExtendedKalmanFilter /Extended Kalman Filter/Predict/Predict'
 * '<S17>'  : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementDrone/Band-Limited White Noise1'
 * '<S18>'  : 'PoseEstimationController/ExtendedKalmanFilter /MeasurementTWB/Band-Limited White Noise1'
 * '<S19>'  : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3/g(x,u)'
 * '<S20>'  : 'PoseEstimationController/ExtendedKalmanFilter /Simulink Function3/v_p'
 * '<S21>'  : 'PoseEstimationController/ExtendedKalmanFilter /Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_PoseEstimationController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
