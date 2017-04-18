/*
 * ExtendedKalmanFilter0_private.h
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

#ifndef RTW_HEADER_ExtendedKalmanFilter0_private_h_
#define RTW_HEADER_ExtendedKalmanFilter0_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "ExtendedKalmanFilter0.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void ExtendedKalma_measurementTWBFcn(const real_T rtu_x[12], real_T
  rty_y[3]);
extern void ExtendedKal_measurementDroneFcn(const real_T rtu_x[12], real_T
  rty_y[5]);
extern void ExtendedKalm_stateTransitionFcn(const real_T rtu_x[12], real_T
  rty_y[12]);

#endif                                 /* RTW_HEADER_ExtendedKalmanFilter0_private_h_ */
