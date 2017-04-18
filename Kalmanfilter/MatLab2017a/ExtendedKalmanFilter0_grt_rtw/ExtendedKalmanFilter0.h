/*
 * ExtendedKalmanFilter0.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ExtendedKalmanFilter0".
 *
 * Model version              : 1.22
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Apr 18 13:26:33 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ExtendedKalmanFilter0_h_
#define RTW_HEADER_ExtendedKalmanFilter0_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef ExtendedKalmanFilter0_COMMON_INCLUDES_
# define ExtendedKalmanFilter0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* ExtendedKalmanFilter0_COMMON_INCLUDES_ */

#include "ExtendedKalmanFilter0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T RateTransition[3];            /* '<S1>/Rate Transition' */
  real_T RateTransition1[5];           /* '<S1>/Rate Transition1' */
  real_T Add6;                         /* '<S8>/Add6' */
  real_T Add5;                         /* '<S8>/Add5' */
  real_T Add4;                         /* '<S8>/Add4' */
  real_T Add3;                         /* '<S8>/Add3' */
} B_ExtendedKalmanFilter0_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[12];         /* '<S1>/Unit Delay' */
  real_T P[144];                       /* '<S2>/DataStoreMemory - P' */
  real_T x[12];                        /* '<S2>/DataStoreMemory - x' */
} DW_ExtendedKalmanFilter0_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[3];                       /* '<Root>/In1' */
  real_T In2[5];                       /* '<Root>/In2' */
  real_T x[12];                        /* '<Root>/In3' */
  real_T In4[4];                       /* '<Root>/In4' */
} ExtU_ExtendedKalmanFilter0_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1[12];                     /* '<Root>/Out1' */
  real_T Out2[4];                      /* '<Root>/Out2' */
} ExtY_ExtendedKalmanFilter0_T;

/* Parameters (auto storage) */
struct P_ExtendedKalmanFilter0_T_ {
  real_T H_Drone[60];                  /* Variable: H_Drone
                                        * Referenced by: '<S6>/A'
                                        */
  real_T H_TWB[36];                    /* Variable: H_TWB
                                        * Referenced by: '<S5>/A'
                                        */
  real_T dt;                           /* Variable: dt
                                        * Referenced by:
                                        *   '<S7>/dt'
                                        *   '<S7>/dt1'
                                        */
  real_T k1;                           /* Variable: k1
                                        * Referenced by: '<S19>/K1'
                                        */
  real_T k10;                          /* Variable: k10
                                        * Referenced by: '<S18>/K10'
                                        */
  real_T k11;                          /* Variable: k11
                                        * Referenced by: '<S18>/K11'
                                        */
  real_T k12;                          /* Variable: k12
                                        * Referenced by: '<S18>/K12'
                                        */
  real_T k2;                           /* Variable: k2
                                        * Referenced by: '<S19>/K2'
                                        */
  real_T k3;                           /* Variable: k3
                                        * Referenced by: '<S19>/K3'
                                        */
  real_T k4;                           /* Variable: k4
                                        * Referenced by: '<S19>/K4'
                                        */
  real_T k5;                           /* Variable: k5
                                        * Referenced by: '<S18>/K5'
                                        */
  real_T k6;                           /* Variable: k6
                                        * Referenced by: '<S18>/K6'
                                        */
  real_T k7;                           /* Variable: k7
                                        * Referenced by: '<S18>/K7'
                                        */
  real_T k8;                           /* Variable: k8
                                        * Referenced by: '<S18>/K8'
                                        */
  real_T k9;                           /* Variable: k9
                                        * Referenced by: '<S18>/K9'
                                        */
  real_T kd1;                          /* Variable: kd1
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T kd2;                          /* Variable: kd2
                                        * Referenced by: '<S8>/Gain5'
                                        */
  real_T kd3;                          /* Variable: kd3
                                        * Referenced by: '<S8>/Gain6'
                                        */
  real_T kd4;                          /* Variable: kd4
                                        * Referenced by: '<S8>/Gain7'
                                        */
  real_T kp1;                          /* Variable: kp1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T kp2;                          /* Variable: kp2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T kp3;                          /* Variable: kp3
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T kp4;                          /* Variable: kp4
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T R1_Value[9];                  /* Expression: p.R{1}
                                        * Referenced by: '<S2>/R1'
                                        */
  real_T R2_Value[25];                 /* Expression: p.R{2}
                                        * Referenced by: '<S2>/R2'
                                        */
  real_T Q_Value[144];                 /* Expression: p.Q
                                        * Referenced by: '<S2>/Q'
                                        */
  real_T DataStoreMemoryP_InitialValue[144];/* Expression: p.InitialCovariance
                                             * Referenced by: '<S2>/DataStoreMemory - P'
                                             */
  real_T DataStoreMemoryx_InitialValue[12];/* Expression: p.InitialState
                                            * Referenced by: '<S2>/DataStoreMemory - x'
                                            */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  boolean_T Enable1_Value;             /* Expression: true()
                                        * Referenced by: '<S2>/Enable1'
                                        */
  boolean_T Enable2_Value;             /* Expression: true()
                                        * Referenced by: '<S2>/Enable2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ExtendedKalmanFilter0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint16_T TID[4];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_P;

/* Block signals (auto storage) */
extern B_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_B;

/* Block states (auto storage) */
extern DW_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_Y;

/* Model entry point functions */
extern void ExtendedKalmanFilter0_initialize(void);
extern void ExtendedKalmanFilter0_step(void);
extern void ExtendedKalmanFilter0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ExtendedKalmanFilter_T *const ExtendedKalmanFilter0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ControllerNL/ExtendedKalmanFilter ')    - opens subsystem ControllerNL/ExtendedKalmanFilter
 * hilite_system('ControllerNL/ExtendedKalmanFilter /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControllerNL'
 * '<S1>'   : 'ControllerNL/ExtendedKalmanFilter '
 * '<S2>'   : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter'
 * '<S3>'   : 'ControllerNL/ExtendedKalmanFilter /MeasurementDrone'
 * '<S4>'   : 'ControllerNL/ExtendedKalmanFilter /MeasurementTWB'
 * '<S5>'   : 'ControllerNL/ExtendedKalmanFilter /Simulink Function1'
 * '<S6>'   : 'ControllerNL/ExtendedKalmanFilter /Simulink Function2'
 * '<S7>'   : 'ControllerNL/ExtendedKalmanFilter /Simulink Function3'
 * '<S8>'   : 'ControllerNL/ExtendedKalmanFilter /generateU'
 * '<S9>'   : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Correct1'
 * '<S10>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Correct2'
 * '<S11>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Output'
 * '<S12>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Predict'
 * '<S13>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Correct1/Correct'
 * '<S14>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Correct2/Correct'
 * '<S15>'  : 'ControllerNL/ExtendedKalmanFilter /Extended Kalman Filter/Predict/Predict'
 * '<S16>'  : 'ControllerNL/ExtendedKalmanFilter /MeasurementDrone/Band-Limited White Noise1'
 * '<S17>'  : 'ControllerNL/ExtendedKalmanFilter /MeasurementTWB/Band-Limited White Noise1'
 * '<S18>'  : 'ControllerNL/ExtendedKalmanFilter /Simulink Function3/g(x,u)'
 * '<S19>'  : 'ControllerNL/ExtendedKalmanFilter /Simulink Function3/v_p'
 */
#endif                                 /* RTW_HEADER_ExtendedKalmanFilter0_h_ */
