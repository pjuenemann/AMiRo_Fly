/*
 * ExtendedKalmanFilter0_data.c
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

#include "ExtendedKalmanFilter0.h"
#include "ExtendedKalmanFilter0_private.h"

/* Block parameters (auto storage) */
P_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_P = {
  /*  Variable: H_Drone
   * Referenced by: '<S6>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: H_TWB
   * Referenced by: '<S5>/A'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.01,                                /* Variable: dt
                                        * Referenced by:
                                        *   '<S7>/dt'
                                        *   '<S7>/dt1'
                                        */
  0.2,                                 /* Variable: k1
                                        * Referenced by: '<S19>/K1'
                                        */
  0.2,                                 /* Variable: k10
                                        * Referenced by: '<S18>/K10'
                                        */
  0.2,                                 /* Variable: k11
                                        * Referenced by: '<S18>/K11'
                                        */
  0.2,                                 /* Variable: k12
                                        * Referenced by: '<S18>/K12'
                                        */
  0.2,                                 /* Variable: k2
                                        * Referenced by: '<S19>/K2'
                                        */
  0.2,                                 /* Variable: k3
                                        * Referenced by: '<S19>/K3'
                                        */
  0.2,                                 /* Variable: k4
                                        * Referenced by: '<S19>/K4'
                                        */
  0.2,                                 /* Variable: k5
                                        * Referenced by: '<S18>/K5'
                                        */
  0.2,                                 /* Variable: k6
                                        * Referenced by: '<S18>/K6'
                                        */
  0.2,                                 /* Variable: k7
                                        * Referenced by: '<S18>/K7'
                                        */
  0.2,                                 /* Variable: k8
                                        * Referenced by: '<S18>/K8'
                                        */
  0.2,                                 /* Variable: k9
                                        * Referenced by: '<S18>/K9'
                                        */
  50.0,                                /* Variable: kd1
                                        * Referenced by: '<S8>/Gain4'
                                        */
  50.0,                                /* Variable: kd2
                                        * Referenced by: '<S8>/Gain5'
                                        */
  50.0,                                /* Variable: kd3
                                        * Referenced by: '<S8>/Gain6'
                                        */
  50.0,                                /* Variable: kd4
                                        * Referenced by: '<S8>/Gain7'
                                        */
  100.0,                               /* Variable: kp1
                                        * Referenced by: '<S8>/Gain'
                                        */
  100.0,                               /* Variable: kp2
                                        * Referenced by: '<S8>/Gain1'
                                        */
  100.0,                               /* Variable: kp3
                                        * Referenced by: '<S8>/Gain2'
                                        */
  100.0,                               /* Variable: kp4
                                        * Referenced by: '<S8>/Gain3'
                                        */

  /*  Expression: p.R{1}
   * Referenced by: '<S2>/R1'
   */
  { 0.000114037489420717, -2.82089891064414E-6, 1.40417613824518E-5,
    -2.82089891064414E-6, 0.000115657032079071, 1.08946618253263E-6,
    1.40417613824518E-5, 1.08946618253263E-6, 0.00137780347424666 },

  /*  Expression: p.R{2}
   * Referenced by: '<S2>/R2'
   */
  { 7.40493968128454E-7, 4.00871171116695E-8, 2.64850251168023E-7,
    4.81776544321576E-8, 1.70610840898493E-7, 4.00871171116695E-8,
    1.12410457478521E-6, -8.65404287048207E-8, -1.99569229909733E-7,
    2.12891815399967E-7, 2.64850251168023E-7, -8.65404287048207E-8,
    3.89370394407336E-5, -1.56813743542319E-6, -2.34614557587901E-6,
    4.81776544321576E-8, -1.99569229909733E-7, -1.56813743542319E-6,
    3.83263259074627E-5, 1.99513110891507E-6, 1.70610840898493E-7,
    2.12891815399967E-7, -2.34614557587901E-6, 1.99513110891507E-6,
    2.60130783647397E-5 },

  /*  Expression: p.Q
   * Referenced by: '<S2>/Q'
   */
  { 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5 },

  /*  Expression: p.InitialCovariance
   * Referenced by: '<S2>/DataStoreMemory - P'
   */
  { 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0 },

  /*  Expression: p.InitialState
   * Referenced by: '<S2>/DataStoreMemory - x'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  1,                                   /* Expression: true()
                                        * Referenced by: '<S2>/Enable1'
                                        */
  1                                    /* Expression: true()
                                        * Referenced by: '<S2>/Enable2'
                                        */
};
