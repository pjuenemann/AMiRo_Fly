/*
 * ExtendedKalmanFilter0.c
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
#include "iecjgdjeaimokfcj_mrdivide.h"

/* Block signals (auto storage) */
B_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_B;

/* Block states (auto storage) */
DW_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_ExtendedKalmanFilter0_T ExtendedKalmanFilter0_Y;

/* Real-time model */
RT_MODEL_ExtendedKalmanFilter_T ExtendedKalmanFilter0_M_;
RT_MODEL_ExtendedKalmanFilter_T *const ExtendedKalmanFilter0_M =
  &ExtendedKalmanFilter0_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[1])++;
  if ((ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[2])++;
  if ((ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [1.0s, 0.0s] */
    ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[2] = 0;
  }

  (ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[3])++;
  if ((ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[3]) > 199) {/* Sample time: [2.0s, 0.0s] */
    ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Output and update for Simulink Function: '<S1>/Simulink Function1' */
void ExtendedKalma_measurementTWBFcn(const real_T rtu_x[12], real_T rty_y[3])
{
  int32_T i;
  int32_T i_0;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtyInport1' incorporates:
   *  Constant: '<S5>/A'
   *  Product: '<S5>/Product2'
   *  SignalConversion: '<S5>/TmpSignal ConversionAtxOutport1'
   */
  for (i = 0; i < 3; i++) {
    rty_y[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      rty_y[i] += ExtendedKalmanFilter0_P.H_TWB[3 * i_0 + i] * rtu_x[i_0];
    }
  }

  /* End of SignalConversion: '<S5>/TmpSignal ConversionAtyInport1' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function2' */
void ExtendedKal_measurementDroneFcn(const real_T rtu_x[12], real_T rty_y[5])
{
  int32_T i;
  int32_T i_0;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtyInport1' incorporates:
   *  Constant: '<S6>/A'
   *  Product: '<S6>/Product2'
   *  SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'
   */
  for (i = 0; i < 5; i++) {
    rty_y[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      rty_y[i] += ExtendedKalmanFilter0_P.H_Drone[5 * i_0 + i] * rtu_x[i_0];
    }
  }

  /* End of SignalConversion: '<S6>/TmpSignal ConversionAtyInport1' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function3' */
void ExtendedKalm_stateTransitionFcn(const real_T rtu_x[12], real_T rty_y[12])
{
  real_T rtb_Add3_m;
  real_T rtb_Add2_a;
  real_T rtb_Add6_i;
  real_T rtb_Add5_k;
  real_T rtb_Add8_a;

  /* Trigonometry: '<S7>/Trigonometric Function' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add3_m = cos(rtu_x[10]);

  /* Trigonometry: '<S7>/Trigonometric Function1' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add2_a = sin(rtu_x[10]);

  /* Trigonometry: '<S19>/Trigonometric Function5' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add6_i = sin(rtu_x[10]);

  /* Trigonometry: '<S19>/Trigonometric Function6' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add5_k = cos(rtu_x[9]);

  /* Trigonometry: '<S19>/Trigonometric Function7' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add8_a = cos(rtu_x[10]);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtyInport1' incorporates:
   *  Constant: '<S18>/K10'
   *  Constant: '<S18>/K11'
   *  Constant: '<S18>/K12'
   *  Constant: '<S18>/K5'
   *  Constant: '<S18>/K6'
   *  Constant: '<S18>/K7'
   *  Constant: '<S18>/K8'
   *  Constant: '<S18>/K9'
   *  Constant: '<S19>/K1'
   *  Constant: '<S19>/K2'
   *  Constant: '<S19>/K3'
   *  Constant: '<S19>/K4'
   *  Constant: '<S7>/dt'
   *  Constant: '<S7>/dt1'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Product: '<S18>/Product2'
   *  Product: '<S18>/Product3'
   *  Product: '<S18>/Product4'
   *  Product: '<S18>/Product5'
   *  Product: '<S18>/Product6'
   *  Product: '<S18>/Product7'
   *  Product: '<S19>/Product13'
   *  Product: '<S19>/Product14'
   *  Product: '<S19>/Product15'
   *  Product: '<S19>/Product16'
   *  Product: '<S19>/Product17'
   *  Product: '<S19>/Product5'
   *  Product: '<S19>/Product6'
   *  Product: '<S19>/Product7'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product10'
   *  Product: '<S7>/Product11'
   *  Product: '<S7>/Product12'
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   *  Product: '<S7>/Product4'
   *  Product: '<S7>/Product5'
   *  Product: '<S7>/Product8'
   *  Product: '<S7>/Product9'
   *  SignalConversion: '<S7>/TmpLatchAtIn1Outport1'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   *  Sum: '<S18>/Add'
   *  Sum: '<S18>/Add1'
   *  Sum: '<S18>/Add2'
   *  Sum: '<S18>/Add3'
   *  Sum: '<S19>/Add5'
   *  Sum: '<S19>/Add6'
   *  Sum: '<S19>/Add7'
   *  Sum: '<S19>/Add8'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add2'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Add4'
   *  Sum: '<S7>/Add5'
   *  Sum: '<S7>/Add6'
   *  Sum: '<S7>/Add7'
   *  Sum: '<S7>/Add8'
   *  Trigonometry: '<S19>/Trigonometric Function2'
   *  Trigonometry: '<S19>/Trigonometric Function3'
   *  Trigonometry: '<S19>/Trigonometric Function4'
   */
  rty_y[0] = ExtendedKalmanFilter0_P.dt * rtu_x[3] + rtu_x[0];
  rty_y[1] = ExtendedKalmanFilter0_P.dt * rtu_x[4] + rtu_x[1];
  rty_y[2] = ExtendedKalmanFilter0_P.dt * rtu_x[5] + rtu_x[2];
  rty_y[3] = rtb_Add3_m * rtu_x[6] - rtb_Add2_a * rtu_x[7];
  rty_y[4] = rtb_Add2_a * rtu_x[6] + rtb_Add3_m * rtu_x[7];
  rty_y[5] = (ExtendedKalmanFilter0_P.k5 * ExtendedKalmanFilter0_B.Add3 - rtu_x
              [5] * ExtendedKalmanFilter0_P.k6) * ExtendedKalmanFilter0_P.dt +
    rtu_x[5];
  rty_y[6] = (rtb_Add6_i * rtb_Add5_k * cos(rtu_x[8]) + rtb_Add8_a * sin(rtu_x[9]))
    * ExtendedKalmanFilter0_P.k1 - ExtendedKalmanFilter0_P.k2 * rtu_x[6];
  rty_y[7] = (rtb_Add6_i * rtb_Add5_k - rtb_Add8_a * sin(rtu_x[8]) * rtb_Add5_k)
    * ExtendedKalmanFilter0_P.k3 - ExtendedKalmanFilter0_P.k4 * rtu_x[7];
  rty_y[8] = (ExtendedKalmanFilter0_P.k9 * ExtendedKalmanFilter0_B.Add5 - rtu_x
              [8] * ExtendedKalmanFilter0_P.k10) * ExtendedKalmanFilter0_P.dt +
    rtu_x[8];
  rty_y[9] = (ExtendedKalmanFilter0_P.k11 * ExtendedKalmanFilter0_B.Add6 -
              rtu_x[9] * ExtendedKalmanFilter0_P.k12) *
    ExtendedKalmanFilter0_P.dt + rtu_x[9];
  rty_y[10] = rtu_x[11] * ExtendedKalmanFilter0_P.dt + rtu_x[10];
  rty_y[11] = (ExtendedKalmanFilter0_P.k7 * ExtendedKalmanFilter0_B.Add4 -
               rtu_x[11] * ExtendedKalmanFilter0_P.k8) *
    ExtendedKalmanFilter0_P.dt + rtu_x[11];
}

/* Model step function */
void ExtendedKalmanFilter0_step(void)
{
  real_T PNew[144];
  real_T zcov[9];
  real_T dHdx[36];
  real_T Pxy[36];
  real_T Pyy[9];
  real_T b_f1[12];
  real_T b_z[3];
  real_T imvec[12];
  real_T imz[3];
  real_T gain[36];
  int32_T r1;
  int32_T r2;
  int32_T rtemp;
  real_T zcov_0[25];
  real_T dHdx_0[60];
  real_T b_z_0[5];
  real_T imz_0[5];
  real_T gain_0[60];
  real_T Jacobian[144];
  real_T z[12];
  real_T imz_1[12];
  real_T rtb_UnitDelay[12];
  real_T rtb_Add_a[3];
  real_T rtb_Add_c[5];
  real_T rtb_TrigonometricFunction;
  real_T rtb_TrigonometricFunction3_h;
  real_T rtb_DataStoreRead[12];
  int32_T i;
  real_T dHdx_1[25];
  real_T gain_1[144];
  real_T dHdx_2[60];
  real_T Jacobian_0[144];
  real_T rtb_Add_k_idx_3;
  real_T rtb_Add_k_idx_0;
  real_T rtb_Add_k_idx_1;
  real_T rtb_Add_k_idx_2;

  /* UnitDelay: '<S1>/Unit Delay' */
  memcpy(&rtb_UnitDelay[0], &ExtendedKalmanFilter0_DW.UnitDelay_DSTATE[0], 12U *
         sizeof(real_T));

  /* FunctionCaller: '<S4>/Function Caller' */
  ExtendedKalma_measurementTWBFcn(rtb_UnitDelay, rtb_Add_a);

  /* Sum: '<S4>/Add' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_Add_a[0] = ExtendedKalmanFilter0_U.In1[0] - rtb_Add_a[0];
  rtb_Add_a[1] = ExtendedKalmanFilter0_U.In1[1] - rtb_Add_a[1];
  rtb_Add_a[2] = ExtendedKalmanFilter0_U.In1[2] - rtb_Add_a[2];

  /* RateTransition: '<S1>/Rate Transition' */
  if (ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[3] == 0) {
    ExtendedKalmanFilter0_B.RateTransition[0] = rtb_Add_a[0];
    ExtendedKalmanFilter0_B.RateTransition[1] = rtb_Add_a[1];
    ExtendedKalmanFilter0_B.RateTransition[2] = rtb_Add_a[2];
  }

  /* End of RateTransition: '<S1>/Rate Transition' */

  /* FunctionCaller: '<S3>/Function Caller' */
  ExtendedKal_measurementDroneFcn(rtb_UnitDelay, rtb_Add_c);

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/In2'
   */
  for (r2 = 0; r2 < 5; r2++) {
    rtb_Add_c[r2] = ExtendedKalmanFilter0_U.In2[r2] - rtb_Add_c[r2];
  }

  /* End of Sum: '<S3>/Add' */

  /* RateTransition: '<S1>/Rate Transition1' */
  if (ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[2] == 0) {
    for (i = 0; i < 5; i++) {
      ExtendedKalmanFilter0_B.RateTransition1[i] = rtb_Add_c[i];
    }
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Trigonometry: '<S8>/Trigonometric Function' */
  rtb_TrigonometricFunction = cos(rtb_UnitDelay[10]);

  /* Sum: '<S8>/Add' incorporates:
   *  Inport: '<Root>/In4'
   */
  rtb_Add_k_idx_0 = ExtendedKalmanFilter0_U.In4[0] - rtb_UnitDelay[0];
  rtb_Add_k_idx_1 = ExtendedKalmanFilter0_U.In4[1] - rtb_UnitDelay[1];
  rtb_Add_k_idx_2 = ExtendedKalmanFilter0_U.In4[2] - rtb_UnitDelay[2];
  rtb_Add_k_idx_3 = ExtendedKalmanFilter0_U.In4[3] - rtb_UnitDelay[10];

  /* Sum: '<S8>/Add1' incorporates:
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain4'
   */
  rtb_Add_k_idx_0 = ExtendedKalmanFilter0_P.kp1 * rtb_Add_k_idx_0 -
    ExtendedKalmanFilter0_P.kd1 * rtb_UnitDelay[3];

  /* Trigonometry: '<S8>/Trigonometric Function3' */
  rtb_TrigonometricFunction3_h = sin(rtb_UnitDelay[10]);

  /* Sum: '<S8>/Add2' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain5'
   */
  rtb_Add_k_idx_1 = ExtendedKalmanFilter0_P.kp2 * rtb_Add_k_idx_1 -
    ExtendedKalmanFilter0_P.kd2 * rtb_UnitDelay[4];

  /* Sum: '<S8>/Add6' incorporates:
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product3'
   */
  ExtendedKalmanFilter0_B.Add6 = rtb_TrigonometricFunction * rtb_Add_k_idx_0 +
    rtb_TrigonometricFunction3_h * rtb_Add_k_idx_1;

  /* Sum: '<S8>/Add5' incorporates:
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   */
  ExtendedKalmanFilter0_B.Add5 = rtb_TrigonometricFunction3_h * rtb_Add_k_idx_0
    - rtb_TrigonometricFunction * rtb_Add_k_idx_1;

  /* Sum: '<S8>/Add4' incorporates:
   *  Gain: '<S8>/Gain3'
   *  Gain: '<S8>/Gain7'
   */
  ExtendedKalmanFilter0_B.Add4 = ExtendedKalmanFilter0_P.kp4 * rtb_Add_k_idx_3 -
    ExtendedKalmanFilter0_P.kd4 * rtb_UnitDelay[11];

  /* Sum: '<S8>/Add3' incorporates:
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain6'
   */
  ExtendedKalmanFilter0_B.Add3 = ExtendedKalmanFilter0_P.kp3 * rtb_Add_k_idx_2 -
    ExtendedKalmanFilter0_P.kd3 * rtb_UnitDelay[5];

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* Constant: '<S2>/Enable1' */
  if ((ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[3] == 0) &&
      ExtendedKalmanFilter0_P.Enable1_Value) {
    /* MATLAB Function: '<S9>/Correct' incorporates:
     *  Constant: '<S2>/R1'
     *  DataStoreRead: '<S9>/Data Store ReadP'
     *  DataStoreRead: '<S9>/Data Store ReadX'
     */
    /* MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S13>:1' */
    rtb_Add_a[0] = ExtendedKalmanFilter0_B.RateTransition[0];
    rtb_Add_a[1] = ExtendedKalmanFilter0_B.RateTransition[1];
    rtb_Add_a[2] = ExtendedKalmanFilter0_B.RateTransition[2];
    memcpy(&zcov[0], &ExtendedKalmanFilter0_P.R1_Value[0], 9U * sizeof(real_T));
    memcpy(&PNew[0], &ExtendedKalmanFilter0_DW.P[0], 144U * sizeof(real_T));
    memcpy(&rtb_UnitDelay[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof
           (real_T));

    /* '<S13>:1:15' */
    memcpy(&b_f1[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

    /* DataStoreRead: '<S9>/Data Store ReadX' */
    memcpy(&imvec[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

    /* MATLAB Function: '<S9>/Correct' */
    ExtendedKalma_measurementTWBFcn(imvec, b_z);
    for (r1 = 0; r1 < 12; r1++) {
      memcpy(&imvec[0], &b_f1[0], 12U * sizeof(real_T));
      rtb_TrigonometricFunction = fmax(1.4901161193847656E-8,
        1.4901161193847656E-8 * fabs(b_f1[r1]));
      imvec[r1] = b_f1[r1] + rtb_TrigonometricFunction;

      /* '<S13>:1:15' */
      ExtendedKalma_measurementTWBFcn(imvec, imz);
      dHdx[3 * r1] = (imz[0] - b_z[0]) / rtb_TrigonometricFunction;
      dHdx[1 + 3 * r1] = (imz[1] - b_z[1]) / rtb_TrigonometricFunction;
      dHdx[2 + 3 * r1] = (imz[2] - b_z[2]) / rtb_TrigonometricFunction;
    }

    for (r2 = 0; r2 < 12; r2++) {
      for (r1 = 0; r1 < 3; r1++) {
        Pxy[r2 + 12 * r1] = 0.0;
        for (i = 0; i < 12; i++) {
          Pxy[r2 + 12 * r1] += PNew[12 * i + r2] * dHdx[3 * i + r1];
        }
      }
    }

    for (r2 = 0; r2 < 3; r2++) {
      for (r1 = 0; r1 < 12; r1++) {
        gain[r2 + 3 * r1] = 0.0;
        for (i = 0; i < 12; i++) {
          gain[r2 + 3 * r1] += dHdx[3 * i + r2] * PNew[12 * r1 + i];
        }
      }

      for (r1 = 0; r1 < 3; r1++) {
        rtb_TrigonometricFunction = 0.0;
        for (i = 0; i < 12; i++) {
          rtb_TrigonometricFunction += gain[3 * i + r2] * dHdx[3 * i + r1];
        }

        Pyy[r2 + 3 * r1] = zcov[3 * r1 + r2] + rtb_TrigonometricFunction;
      }
    }

    /* '<S13>:1:15' */
    memcpy(&b_f1[0], &rtb_UnitDelay[0], 12U * sizeof(real_T));
    ExtendedKalma_measurementTWBFcn(b_f1, b_z);
    r1 = 0;
    r2 = 1;
    i = 2;
    rtb_TrigonometricFunction = fabs(Pyy[0]);
    rtb_Add_k_idx_0 = fabs(Pyy[1]);
    if (rtb_Add_k_idx_0 > rtb_TrigonometricFunction) {
      rtb_TrigonometricFunction = rtb_Add_k_idx_0;
      r1 = 1;
      r2 = 0;
    }

    if (fabs(Pyy[2]) > rtb_TrigonometricFunction) {
      r1 = 2;
      r2 = 1;
      i = 0;
    }

    Pyy[r2] /= Pyy[r1];
    Pyy[i] /= Pyy[r1];
    Pyy[3 + r2] -= Pyy[3 + r1] * Pyy[r2];
    Pyy[3 + i] -= Pyy[3 + r1] * Pyy[i];
    Pyy[6 + r2] -= Pyy[6 + r1] * Pyy[r2];
    Pyy[6 + i] -= Pyy[6 + r1] * Pyy[i];
    if (fabs(Pyy[3 + i]) > fabs(Pyy[3 + r2])) {
      rtemp = r2;
      r2 = i;
      i = rtemp;
    }

    Pyy[3 + i] /= Pyy[3 + r2];
    Pyy[6 + i] -= Pyy[3 + i] * Pyy[6 + r2];
    for (rtemp = 0; rtemp < 12; rtemp++) {
      gain[rtemp + 12 * r1] = Pxy[rtemp] / Pyy[r1];
      gain[rtemp + 12 * r2] = Pxy[12 + rtemp] - gain[12 * r1 + rtemp] * Pyy[3 +
        r1];
      gain[rtemp + 12 * i] = Pxy[24 + rtemp] - gain[12 * r1 + rtemp] * Pyy[6 +
        r1];
      gain[rtemp + 12 * r2] /= Pyy[3 + r2];
      gain[rtemp + 12 * i] -= gain[12 * r2 + rtemp] * Pyy[6 + r2];
      gain[rtemp + 12 * i] /= Pyy[6 + i];
      gain[rtemp + 12 * r2] -= gain[12 * i + rtemp] * Pyy[3 + i];
      gain[rtemp + 12 * r1] -= gain[12 * i + rtemp] * Pyy[i];
      gain[rtemp + 12 * r1] -= gain[12 * r2 + rtemp] * Pyy[r2];
    }

    /* '<S13>:1:14' */
    rtb_TrigonometricFunction = rtb_Add_a[0] - b_z[0];
    rtb_Add_k_idx_2 = rtb_Add_a[1] - b_z[1];
    rtb_Add_k_idx_3 = rtb_Add_a[2] - b_z[2];
    for (r2 = 0; r2 < 12; r2++) {
      /* DataStoreWrite: '<S9>/Data Store WriteX' incorporates:
       *  MATLAB Function: '<S9>/Correct'
       */
      ExtendedKalmanFilter0_DW.x[r2] = ((gain[r2 + 12] * rtb_Add_k_idx_2 +
        gain[r2] * rtb_TrigonometricFunction) + gain[r2 + 24] * rtb_Add_k_idx_3)
        + rtb_UnitDelay[r2];
    }

    for (r2 = 0; r2 < 12; r2++) {
      /* MATLAB Function: '<S9>/Correct' */
      for (r1 = 0; r1 < 12; r1++) {
        gain_1[r2 + 12 * r1] = 0.0;
        gain_1[r2 + 12 * r1] += dHdx[3 * r1] * gain[r2];
        gain_1[r2 + 12 * r1] += dHdx[3 * r1 + 1] * gain[r2 + 12];
        gain_1[r2 + 12 * r1] += dHdx[3 * r1 + 2] * gain[r2 + 24];
      }

      /* DataStoreWrite: '<S9>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S9>/Correct'
       */
      for (r1 = 0; r1 < 12; r1++) {
        rtb_TrigonometricFunction = 0.0;
        for (i = 0; i < 12; i++) {
          rtb_TrigonometricFunction += gain_1[12 * i + r2] * PNew[12 * r1 + i];
        }

        ExtendedKalmanFilter0_DW.P[r2 + 12 * r1] = PNew[12 * r1 + r2] -
          rtb_TrigonometricFunction;
      }

      /* End of DataStoreWrite: '<S9>/Data Store WriteP' */
    }
  }

  /* End of Constant: '<S2>/Enable1' */
  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outputs for Enabled SubSystem: '<S2>/Correct2' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* Constant: '<S2>/Enable2' */
  if ((ExtendedKalmanFilter0_M->Timing.TaskCounters.TID[2] == 0) &&
      ExtendedKalmanFilter0_P.Enable2_Value) {
    /* MATLAB Function: '<S10>/Correct' incorporates:
     *  Constant: '<S2>/R2'
     *  DataStoreRead: '<S10>/Data Store ReadP'
     *  DataStoreRead: '<S10>/Data Store ReadX'
     */
    /* MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S14>:1' */
    for (i = 0; i < 5; i++) {
      rtb_Add_c[i] = ExtendedKalmanFilter0_B.RateTransition1[i];
    }

    memcpy(&zcov_0[0], &ExtendedKalmanFilter0_P.R2_Value[0], 25U * sizeof(real_T));
    memcpy(&PNew[0], &ExtendedKalmanFilter0_DW.P[0], 144U * sizeof(real_T));
    memcpy(&rtb_UnitDelay[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof
           (real_T));

    /* '<S14>:1:15' */
    memcpy(&b_f1[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

    /* DataStoreRead: '<S10>/Data Store ReadX' */
    memcpy(&imvec[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

    /* MATLAB Function: '<S10>/Correct' */
    ExtendedKal_measurementDroneFcn(imvec, b_z_0);
    for (r1 = 0; r1 < 12; r1++) {
      memcpy(&imvec[0], &b_f1[0], 12U * sizeof(real_T));
      rtb_TrigonometricFunction = fmax(1.4901161193847656E-8,
        1.4901161193847656E-8 * fabs(b_f1[r1]));
      imvec[r1] = b_f1[r1] + rtb_TrigonometricFunction;

      /* '<S14>:1:15' */
      ExtendedKal_measurementDroneFcn(imvec, imz_0);
      for (r2 = 0; r2 < 5; r2++) {
        dHdx_0[r2 + 5 * r1] = (imz_0[r2] - b_z_0[r2]) /
          rtb_TrigonometricFunction;
      }
    }

    /* '<S14>:1:15' */
    memcpy(&b_f1[0], &rtb_UnitDelay[0], 12U * sizeof(real_T));
    ExtendedKal_measurementDroneFcn(b_f1, b_z_0);
    for (r2 = 0; r2 < 12; r2++) {
      for (r1 = 0; r1 < 5; r1++) {
        gain_0[r2 + 12 * r1] = 0.0;
        for (i = 0; i < 12; i++) {
          gain_0[r2 + 12 * r1] += PNew[12 * i + r2] * dHdx_0[5 * i + r1];
        }
      }
    }

    for (r2 = 0; r2 < 5; r2++) {
      for (r1 = 0; r1 < 12; r1++) {
        dHdx_2[r2 + 5 * r1] = 0.0;
        for (i = 0; i < 12; i++) {
          dHdx_2[r2 + 5 * r1] += dHdx_0[5 * i + r2] * PNew[12 * r1 + i];
        }
      }

      for (r1 = 0; r1 < 5; r1++) {
        rtb_TrigonometricFunction = 0.0;
        for (i = 0; i < 12; i++) {
          rtb_TrigonometricFunction += dHdx_2[5 * i + r2] * dHdx_0[5 * i + r1];
        }

        dHdx_1[r2 + 5 * r1] = zcov_0[5 * r1 + r2] + rtb_TrigonometricFunction;
      }
    }

    iecjgdjeaimokfcj_mrdivide(gain_0, dHdx_1);

    /* '<S14>:1:14' */
    for (r2 = 0; r2 < 5; r2++) {
      imz_0[r2] = rtb_Add_c[r2] - b_z_0[r2];
    }

    for (r2 = 0; r2 < 12; r2++) {
      /* DataStoreWrite: '<S10>/Data Store WriteX' incorporates:
       *  MATLAB Function: '<S10>/Correct'
       */
      rtb_TrigonometricFunction = 0.0;
      for (r1 = 0; r1 < 5; r1++) {
        rtb_TrigonometricFunction += gain_0[12 * r1 + r2] * imz_0[r1];
      }

      ExtendedKalmanFilter0_DW.x[r2] = rtb_UnitDelay[r2] +
        rtb_TrigonometricFunction;

      /* End of DataStoreWrite: '<S10>/Data Store WriteX' */
    }

    for (r2 = 0; r2 < 12; r2++) {
      /* MATLAB Function: '<S10>/Correct' */
      for (r1 = 0; r1 < 12; r1++) {
        gain_1[r2 + 12 * r1] = 0.0;
        for (i = 0; i < 5; i++) {
          gain_1[r2 + 12 * r1] += gain_0[12 * i + r2] * dHdx_0[5 * r1 + i];
        }
      }

      /* DataStoreWrite: '<S10>/Data Store WriteP' incorporates:
       *  MATLAB Function: '<S10>/Correct'
       */
      for (r1 = 0; r1 < 12; r1++) {
        rtb_TrigonometricFunction = 0.0;
        for (i = 0; i < 12; i++) {
          rtb_TrigonometricFunction += gain_1[12 * i + r2] * PNew[12 * r1 + i];
        }

        ExtendedKalmanFilter0_DW.P[r2 + 12 * r1] = PNew[12 * r1 + r2] -
          rtb_TrigonometricFunction;
      }

      /* End of DataStoreWrite: '<S10>/Data Store WriteP' */
    }
  }

  /* End of Constant: '<S2>/Enable2' */
  /* End of Outputs for SubSystem: '<S2>/Correct2' */

  /* Outputs for Atomic SubSystem: '<S2>/Output' */
  /* DataStoreRead: '<S11>/Data Store Read' */
  memcpy(&rtb_DataStoreRead[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof
         (real_T));

  /* End of Outputs for SubSystem: '<S2>/Output' */

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  /* MATLAB Function: '<S12>/Predict' incorporates:
   *  Constant: '<S2>/Q'
   *  DataStoreRead: '<S12>/Data Store ReadP'
   *  DataStoreRead: '<S12>/Data Store ReadX'
   */
  /* MATLAB Function 'Extras/EKFPredict_SLFcn_0Input/Predict': '<S15>:1' */
  memcpy(&gain_1[0], &ExtendedKalmanFilter0_P.Q_Value[0], 144U * sizeof(real_T));
  memcpy(&PNew[0], &ExtendedKalmanFilter0_DW.P[0], 144U * sizeof(real_T));
  memcpy(&rtb_UnitDelay[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

  /* '<S15>:1:15' */
  memcpy(&b_f1[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

  /* DataStoreRead: '<S12>/Data Store ReadX' */
  memcpy(&imvec[0], &ExtendedKalmanFilter0_DW.x[0], 12U * sizeof(real_T));

  /* MATLAB Function: '<S12>/Predict' */
  ExtendedKalm_stateTransitionFcn(imvec, z);
  for (r1 = 0; r1 < 12; r1++) {
    memcpy(&imvec[0], &b_f1[0], 12U * sizeof(real_T));
    rtb_TrigonometricFunction = fmax(1.4901161193847656E-8,
      1.4901161193847656E-8 * fabs(b_f1[r1]));
    imvec[r1] = b_f1[r1] + rtb_TrigonometricFunction;

    /* '<S15>:1:15' */
    ExtendedKalm_stateTransitionFcn(imvec, imz_1);
    for (r2 = 0; r2 < 12; r2++) {
      Jacobian[r2 + 12 * r1] = (imz_1[r2] - z[r2]) / rtb_TrigonometricFunction;
    }
  }

  /* '<S15>:1:15' */
  memcpy(&b_f1[0], &rtb_UnitDelay[0], 12U * sizeof(real_T));
  ExtendedKalm_stateTransitionFcn(b_f1, rtb_UnitDelay);

  /* DataStoreWrite: '<S12>/Data Store WriteX' incorporates:
   *  MATLAB Function: '<S12>/Predict'
   */
  /* '<S15>:1:14' */
  memcpy(&ExtendedKalmanFilter0_DW.x[0], &rtb_UnitDelay[0], 12U * sizeof(real_T));

  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter' */

  /* Outport: '<Root>/Out2' */
  ExtendedKalmanFilter0_Y.Out2[0] = ExtendedKalmanFilter0_B.Add3;
  ExtendedKalmanFilter0_Y.Out2[1] = ExtendedKalmanFilter0_B.Add4;
  ExtendedKalmanFilter0_Y.Out2[2] = ExtendedKalmanFilter0_B.Add5;
  ExtendedKalmanFilter0_Y.Out2[3] = ExtendedKalmanFilter0_B.Add6;

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  for (i = 0; i < 12; i++) {
    /* MATLAB Function: '<S12>/Predict' */
    for (r2 = 0; r2 < 12; r2++) {
      Jacobian_0[i + 12 * r2] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        Jacobian_0[i + 12 * r2] += Jacobian[12 * r1 + i] * PNew[12 * r2 + r1];
      }
    }

    /* DataStoreWrite: '<S12>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S12>/Predict'
     */
    for (r2 = 0; r2 < 12; r2++) {
      rtb_TrigonometricFunction = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        rtb_TrigonometricFunction += Jacobian_0[12 * r1 + i] * Jacobian[12 * r1
          + r2];
      }

      ExtendedKalmanFilter0_DW.P[i + 12 * r2] = gain_1[12 * r2 + i] +
        rtb_TrigonometricFunction;
    }

    /* End of DataStoreWrite: '<S12>/Data Store WriteP' */

    /* Outport: '<Root>/Out1' */
    ExtendedKalmanFilter0_Y.Out1[i] = rtb_DataStoreRead[i];

    /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
     *  Update for Inport: '<Root>/In3'
     */
    ExtendedKalmanFilter0_DW.UnitDelay_DSTATE[i] = ExtendedKalmanFilter0_U.x[i];
  }

  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(ExtendedKalmanFilter0_M->rtwLogInfo,
                      (&ExtendedKalmanFilter0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(ExtendedKalmanFilter0_M)!=-1) &&
        !((rtmGetTFinal(ExtendedKalmanFilter0_M)-
           ExtendedKalmanFilter0_M->Timing.taskTime0) >
          ExtendedKalmanFilter0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ExtendedKalmanFilter0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ExtendedKalmanFilter0_M->Timing.clockTick0)) {
    ++ExtendedKalmanFilter0_M->Timing.clockTickH0;
  }

  ExtendedKalmanFilter0_M->Timing.taskTime0 =
    ExtendedKalmanFilter0_M->Timing.clockTick0 *
    ExtendedKalmanFilter0_M->Timing.stepSize0 +
    ExtendedKalmanFilter0_M->Timing.clockTickH0 *
    ExtendedKalmanFilter0_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void ExtendedKalmanFilter0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ExtendedKalmanFilter0_M, 0,
                sizeof(RT_MODEL_ExtendedKalmanFilter_T));
  rtmSetTFinal(ExtendedKalmanFilter0_M, 10.0);
  ExtendedKalmanFilter0_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ExtendedKalmanFilter0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ExtendedKalmanFilter0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ExtendedKalmanFilter0_M->rtwLogInfo, (NULL));
    rtliSetLogT(ExtendedKalmanFilter0_M->rtwLogInfo, "tout");
    rtliSetLogX(ExtendedKalmanFilter0_M->rtwLogInfo, "");
    rtliSetLogXFinal(ExtendedKalmanFilter0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ExtendedKalmanFilter0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ExtendedKalmanFilter0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(ExtendedKalmanFilter0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(ExtendedKalmanFilter0_M->rtwLogInfo, 1);
    rtliSetLogY(ExtendedKalmanFilter0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ExtendedKalmanFilter0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ExtendedKalmanFilter0_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &ExtendedKalmanFilter0_B), 0,
                sizeof(B_ExtendedKalmanFilter0_T));

  /* states (dwork) */
  (void) memset((void *)&ExtendedKalmanFilter0_DW, 0,
                sizeof(DW_ExtendedKalmanFilter0_T));

  /* external inputs */
  (void)memset((void *)&ExtendedKalmanFilter0_U, 0, sizeof
               (ExtU_ExtendedKalmanFilter0_T));

  /* external outputs */
  (void) memset((void *)&ExtendedKalmanFilter0_Y, 0,
                sizeof(ExtY_ExtendedKalmanFilter0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(ExtendedKalmanFilter0_M->rtwLogInfo, 0.0,
    rtmGetTFinal(ExtendedKalmanFilter0_M),
    ExtendedKalmanFilter0_M->Timing.stepSize0, (&rtmGetErrorStatus
    (ExtendedKalmanFilter0_M)));

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  memcpy(&ExtendedKalmanFilter0_DW.P[0],
         &ExtendedKalmanFilter0_P.DataStoreMemoryP_InitialValue[0], 144U *
         sizeof(real_T));

  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - x' */
  memcpy(&ExtendedKalmanFilter0_DW.x[0],
         &ExtendedKalmanFilter0_P.DataStoreMemoryx_InitialValue[0], 12U * sizeof
         (real_T));

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter' */
  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
    for (i = 0; i < 12; i++) {
      ExtendedKalmanFilter0_DW.UnitDelay_DSTATE[i] =
        ExtendedKalmanFilter0_P.UnitDelay_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  }
}

/* Model terminate function */
void ExtendedKalmanFilter0_terminate(void)
{
  /* (no terminate code required) */
}
