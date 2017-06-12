/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PoseEstimationController.c
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

#include "PoseEstimationController.h"
#include "dbiemohljmgdohdb_norm.h"
#include "iecjgdjeaimokfcj_mrdivide.h"
#include "rt_atan2d_snf.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const real_T rtCP_pooled_XyLjpsXjcyos[9];
extern const real_T rtCP_pooled_299Jb13UAswe[25];
extern const real_T rtCP_pooled_wKVRBqsAl7SO[144];
extern const real_T rtCP_pooled_dEObodluTwti[144];
extern const real_T rtCP_pooled_gVsoQfjsu5wl[36];
extern const real_T rtCP_pooled_TXrxOtAA33B0[60];

#define rtCP_R1_Value                  rtCP_pooled_XyLjpsXjcyos  /* Expression: p.R{1}
                                                                  * Referenced by: '<S2>/R1'
                                                                  */
#define rtCP_R2_Value                  rtCP_pooled_299Jb13UAswe  /* Expression: p.R{2}
                                                                  * Referenced by: '<S2>/R2'
                                                                  */
#define rtCP_Q_Value                   rtCP_pooled_wKVRBqsAl7SO  /* Expression: p.Q
                                                                  * Referenced by: '<S2>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_dEObodluTwti /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S2>/DataStoreMemory - P'
                                                                  */
#define rtCP_A_Value                   rtCP_pooled_gVsoQfjsu5wl  /* Expression: H_TWB
                                                                  * Referenced by: '<S5>/A'
                                                                  */
#define rtCP_A_Value_g                 rtCP_pooled_TXrxOtAA33B0  /* Expression: H_Drone
                                                                  * Referenced by: '<S6>/A'
                                                                  */

extern void measurementTWBFcn_h(const real_T rtu_x[12], real_T rty_y[3]);
extern void measurementDroneFcn_o(const real_T rtu_x[12], real_T rty_y[5]);
extern void stateTransitionFcn(const real_T rtu_x[12], real_T rty_y[12]);
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
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for Simulink Function: '<S1>/Simulink Function1' */
void measurementTWBFcn_h(const real_T rtu_x[12], real_T rty_y[3])
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
      rty_y[i] += rtCP_A_Value[3 * i_0 + i] * rtu_x[i_0];
    }
  }

  /* End of SignalConversion: '<S5>/TmpSignal ConversionAtyInport1' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function2' */
void measurementDroneFcn_o(const real_T rtu_x[12], real_T rty_y[5])
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
      rty_y[i] += rtCP_A_Value_g[5 * i_0 + i] * rtu_x[i_0];
    }
  }

  /* End of SignalConversion: '<S6>/TmpSignal ConversionAtyInport1' */
}

/* Output and update for Simulink Function: '<S1>/Simulink Function3' */
void stateTransitionFcn(const real_T rtu_x[12], real_T rty_y[12])
{
  real_T rtb_Add3_c;
  real_T rtb_Add2_b;
  real_T rtb_Add6_m;
  real_T rtb_Add5_k;
  real_T rtb_Add8_e;

  /* Trigonometry: '<S7>/Trigonometric Function' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add3_c = cos(rtu_x[10]);

  /* Trigonometry: '<S7>/Trigonometric Function1' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add2_b = sin(rtu_x[10]);

  /* Trigonometry: '<S20>/Trigonometric Function5' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add6_m = sin(rtu_x[10]);

  /* Trigonometry: '<S20>/Trigonometric Function6' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add5_k = cos(rtu_x[9]);

  /* Trigonometry: '<S20>/Trigonometric Function7' incorporates:
   *  SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
   */
  rtb_Add8_e = cos(rtu_x[10]);

  /* SignalConversion: '<S7>/TmpSignal ConversionAtyInport1' incorporates:
   *  Constant: '<S7>/dt'
   *  Constant: '<S7>/dt1'
   *  Product: '<S19>/Product4'
   *  Product: '<S19>/Product5'
   *  Product: '<S19>/Product6'
   *  Product: '<S19>/Product7'
   *  Product: '<S20>/Product13'
   *  Product: '<S20>/Product16'
   *  Product: '<S20>/Product17'
   *  Product: '<S20>/Product5'
   *  Product: '<S20>/Product6'
   *  Product: '<S20>/Product7'
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
   *  Sum: '<S19>/Add'
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Add2'
   *  Sum: '<S19>/Add3'
   *  Sum: '<S20>/Add5'
   *  Sum: '<S20>/Add6'
   *  Sum: '<S20>/Add7'
   *  Sum: '<S20>/Add8'
   *  Sum: '<S7>/Add1'
   *  Sum: '<S7>/Add2'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Add4'
   *  Sum: '<S7>/Add5'
   *  Sum: '<S7>/Add6'
   *  Sum: '<S7>/Add7'
   *  Sum: '<S7>/Add8'
   *  Trigonometry: '<S20>/Trigonometric Function2'
   *  Trigonometry: '<S20>/Trigonometric Function3'
   *  Trigonometry: '<S20>/Trigonometric Function4'
   */
  rty_y[0] = 0.01 * rtu_x[3] + rtu_x[0];
  rty_y[1] = 0.01 * rtu_x[4] + rtu_x[1];
  rty_y[2] = 0.01 * rtu_x[5] + rtu_x[2];
  rty_y[3] = rtb_Add3_c * rtu_x[6] - rtb_Add2_b * rtu_x[7];
  rty_y[4] = rtb_Add2_b * rtu_x[6] + rtb_Add3_c * rtu_x[7];
  rty_y[5] = (rtDW.Add3 - rtu_x[5]) * 0.01 + rtu_x[5];
  rty_y[6] = (rtb_Add6_m * rtb_Add5_k * cos(rtu_x[8]) + rtb_Add8_e * sin(rtu_x[9]))
    - rtu_x[6];
  rty_y[7] = (rtb_Add6_m * rtb_Add5_k - rtb_Add8_e * sin(rtu_x[8]) * rtb_Add5_k)
    - rtu_x[7];
  rty_y[8] = (rtDW.Add5 - rtu_x[8]) * 0.01 + rtu_x[8];
  rty_y[9] = (rtDW.Add6 - rtu_x[9]) * 0.01 + rtu_x[9];
  rty_y[10] = rtu_x[11] * 0.01 + rtu_x[10];
  rty_y[11] = (rtDW.Add4 - rtu_x[11]) * 0.01 + rtu_x[11];
}

/* Model step function */
void PoseEstimationController_step(void)
{
  real_T step[4];
  real_T c_t;
  real_T R[9];
  real_T dHdx[36];
  real_T Pxy[36];
  real_T imvec[12];
  real_T imz[3];
  real_T gain[36];
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  real_T dHdx_0[60];
  real_T imz_0[5];
  real_T gain_0[60];
  real_T Jacobian[144];
  real_T z[12];
  real_T imz_1[12];
  real_T rtb_Gain1;
  real_T rtb_UnitDelay[12];
  real_T rtb_Gain1_o[3];
  real_T rtb_FunctionCaller[5];
  real_T rtb_Add_m[5];
  real_T dHdx_1[25];
  real_T tmp[24];
  real_T tmp_0[6];
  int32_T r1;
  int32_T i;
  real_T dHdx_2[60];
  real_T Jacobian_0[144];
  int32_T i_0;
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
  real_T rtb_Add_p_idx_0;
  real_T rtb_Add_p_idx_1;
  real_T rtb_Add_p_idx_2;

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_Gain1 = 2.0 * rtU.In1;

  /* UnitDelay: '<S1>/Unit Delay' */
  memcpy(&rtb_UnitDelay[0], &rtDW.UnitDelay_DSTATE[0], 12U * sizeof(real_T));

  /* FunctionCaller: '<S4>/Function Caller' */
  measurementTWBFcn_h(rtb_UnitDelay, rtb_Gain1_o);

  /* Sum: '<S4>/Add' */
  rtb_Add_p_idx_0 = rtb_Gain1 - rtb_Gain1_o[0];

  /* Gain: '<S8>/Gain1' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtb_Gain1_o[0] = 0.0047900390625 * rtU.In2[3];

  /* Sum: '<S4>/Add' */
  rtb_Add_p_idx_1 = rtb_Gain1 - rtb_Gain1_o[1];

  /* Gain: '<S8>/Gain1' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtb_Gain1_o[1] = 0.0047900390625 * rtU.In2[4];

  /* Sum: '<S4>/Add' */
  rtb_Add_p_idx_2 = rtb_Gain1 - rtb_Gain1_o[2];

  /* Gain: '<S8>/Gain1' incorporates:
   *  Inport: '<Root>/In2'
   */
  rtb_Gain1_o[2] = 0.0047900390625 * rtU.In2[5];

  /* MATLAB Function: '<S8>/MATLAB Function' incorporates:
   *  Inport: '<Root>/In2'
   */
  /*     %% Process sensor data through algorithm */
  /* MATLAB Function 'ExtendedKalmanFilter /Subsystem/MATLAB Function': '<S21>:1' */
  /* '<S21>:1:3' data = data'; */
  /* '<S21>:1:4' gyroscope = data(1,[1:3]); */
  /* '<S21>:1:5' accelerometer = data(1,[4:6]); */
  /* '<S21>:1:6' magnetometer = data(1,[7:9]); */
  /* '<S21>:1:7' AHRS = MadgwickAHRS('SamplePeriod', 1/256, 'Beta', 0.1); */
  b_idx_1 = 1.0;
  b_idx_2 = 0.0;
  c_t = 0.0;
  AHRS_Quaternion_idx_3 = 0.0;

  /* MADGWICKAHRS Implementation of Madgwick's IMU and AHRS algorithms */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms */
  /*  */
  /*    Date          Author          Notes */
  /*    28/09/2011    SOH Madgwick    Initial release */
  /*     %% Public properties */
  /*  output quaternion describing the Earth relative to the sensor */
  /*  algorithm gain */
  /*     %% Public methods */
  /* 'MadgwickAHRS:20' for i = 1:2:nargin */
  /* 'MadgwickAHRS:21' if  strcmp(varargin{i}, 'SamplePeriod') */
  /* 'MadgwickAHRS:21' obj.SamplePeriod = varargin{i+1}; */
  /* 'MadgwickAHRS:21' if  strcmp(varargin{i}, 'SamplePeriod') */
  /* 'MadgwickAHRS:23' elseif  strcmp(varargin{i}, 'Beta') */
  /* 'MadgwickAHRS:23' obj.Beta = varargin{i+1}; */
  /*  AHRS = MahonyAHRS('SamplePeriod', 1/256, 'Kp', 0.5); */
  /* '<S21>:1:10' quaternion = zeros(1, 4); */
  /* '<S21>:1:11' AHRS.Update(gyroscope(1,:) * (pi/180), accelerometer(1,:), magnetometer(1,:)); */
  y_idx_0 = rtU.In2[0] * 0.017453292519943295;
  y_idx_1 = rtU.In2[1] * 0.017453292519943295;
  y_idx_2 = rtU.In2[2] * 0.017453292519943295;

  /* 'MadgwickAHRS:29' q = obj.Quaternion; */
  /*  short name local variable for readability */
  /*  Normalise accelerometer measurement */
  /* 'MadgwickAHRS:32' if(norm(Accelerometer) == 0) */
  if (!(dbiemohljmgdohdb_norm(&rtU.In2[3]) == 0.0)) {
    /*  handle NaN */
    /* 'MadgwickAHRS:33' Accelerometer = Accelerometer / norm(Accelerometer); */
    rtb_Gain1 = dbiemohljmgdohdb_norm(&rtU.In2[3]);
    accelerometer_idx_0 = rtU.In2[3] / rtb_Gain1;
    accelerometer_idx_1 = rtU.In2[4] / rtb_Gain1;
    accelerometer_idx_2 = rtU.In2[5] / rtb_Gain1;

    /*  normalise magnitude */
    /*  Normalise magnetometer measurement */
    /* 'MadgwickAHRS:36' if(norm(Magnetometer) == 0) */
    if (!(dbiemohljmgdohdb_norm(&rtU.In2[6]) == 0.0)) {
      /*  handle NaN */
      /* 'MadgwickAHRS:37' Magnetometer = Magnetometer / norm(Magnetometer); */
      rtb_Gain1 = dbiemohljmgdohdb_norm(&rtU.In2[6]);

      /*  normalise magnitude */
      /*  Reference direction of Earth's magnetic feild */
      /* 'MadgwickAHRS:40' h = quaternProd(q, quaternProd([0 Magnetometer], quaternConj(q))); */
      /* QUATERN2ROTMAT Converts a quaternion to its conjugate */
      /*  */
      /*    qConj = quaternConj(q) */
      /*  */
      /*    Converts a quaternion to its conjugate. */
      /*  */
      /*    For more information see: */
      /*    http://www.x-io.co.uk/node/8#quaternions */
      /*  */
      /* 	Date          Author          Notes */
      /* 	27/09/2011    SOH Madgwick    Initial release */
      /* 'quaternConj:14' qConj = [q(:,1) -q(:,2) -q(:,3) -q(:,4)]; */
      AHRS_Quaternion_idx_3 = rtU.In2[6] / rtb_Gain1;
      b_idx_1 = AHRS_Quaternion_idx_3;
      magnetometer_idx_0 = AHRS_Quaternion_idx_3;
      AHRS_Quaternion_idx_3 = rtU.In2[7] / rtb_Gain1;
      b_idx_2 = AHRS_Quaternion_idx_3;
      magnetometer_idx_1 = AHRS_Quaternion_idx_3;
      AHRS_Quaternion_idx_3 = rtU.In2[8] / rtb_Gain1;

      /* QUATERNPROD Calculates the quaternion product */
      /*  */
      /*    ab = quaternProd(a, b) */
      /*  */
      /*    Calculates the quaternion product of quaternion a and b. */
      /*  */
      /*    For more information see: */
      /*    http://www.x-io.co.uk/node/8#quaternions */
      /*  */
      /* 	Date          Author          Notes */
      /* 	27/09/2011    SOH Madgwick    Initial release */
      /* 'quaternProd:13' ab = zeros(size(a)); */
      /* 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); */
      ab_idx_0 = ((0.0 - b_idx_1 * -0.0) - b_idx_2 * -0.0) -
        AHRS_Quaternion_idx_3 * -0.0;

      /* 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); */
      ab_idx_1 = (b_idx_2 * -0.0 + b_idx_1) - AHRS_Quaternion_idx_3 * -0.0;

      /* 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); */
      ab_idx_2 = ((-0.0 - b_idx_1 * -0.0) + b_idx_2) + AHRS_Quaternion_idx_3 *
        -0.0;

      /* 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); */
      ab_idx_3 = (b_idx_1 * -0.0 - b_idx_2 * -0.0) + AHRS_Quaternion_idx_3;

      /* QUATERNPROD Calculates the quaternion product */
      /*  */
      /*    ab = quaternProd(a, b) */
      /*  */
      /*    Calculates the quaternion product of quaternion a and b. */
      /*  */
      /*    For more information see: */
      /*    http://www.x-io.co.uk/node/8#quaternions */
      /*  */
      /* 	Date          Author          Notes */
      /* 	27/09/2011    SOH Madgwick    Initial release */
      /* 'quaternProd:13' ab = zeros(size(a)); */
      /* 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); */
      /* 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); */
      /* 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); */
      /* 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); */
      h_idx_3 = ((0.0 * ab_idx_2 + ab_idx_3) - 0.0 * ab_idx_1) + 0.0 * ab_idx_0;

      /* 'MadgwickAHRS:41' b = [0 norm([h(2) h(3)]) 0 h(4)]; */
      b_idx_1 = 2.2250738585072014E-308;
      b_idx_2 = fabs(((0.0 * ab_idx_0 + ab_idx_1) + 0.0 * ab_idx_3) - 0.0 *
                     ab_idx_2);
      if (b_idx_2 > 2.2250738585072014E-308) {
        rtb_Gain1 = 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / 2.2250738585072014E-308;
        rtb_Gain1 = c_t * c_t;
      }

      b_idx_2 = fabs(((ab_idx_2 - 0.0 * ab_idx_3) + 0.0 * ab_idx_0) + 0.0 *
                     ab_idx_1);
      if (b_idx_2 > b_idx_1) {
        c_t = b_idx_1 / b_idx_2;
        rtb_Gain1 = rtb_Gain1 * c_t * c_t + 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / b_idx_1;
        rtb_Gain1 += c_t * c_t;
      }

      rtb_Gain1 = b_idx_1 * sqrt(rtb_Gain1);

      /*  Gradient decent algorithm corrective step */
      /* 'MadgwickAHRS:44' F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1) */
      /* 'MadgwickAHRS:45'                 2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2) */
      /* 'MadgwickAHRS:46'                 2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3) */
      /* 'MadgwickAHRS:47'                 2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3)) - Magnetometer(1) */
      /* 'MadgwickAHRS:48'                 2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4)) - Magnetometer(2) */
      /* 'MadgwickAHRS:49'                 2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2) - Magnetometer(3)]; */
      /* 'MadgwickAHRS:50' J = [-2*q(3),                 	2*q(4),                    -2*q(1),                         2*q(2) */
      /* 'MadgwickAHRS:51'                 2*q(2),                 	2*q(1),                    	2*q(4),                         2*q(3) */
      /* 'MadgwickAHRS:52'                 0,                         -4*q(2),                    -4*q(3),                         0 */
      /* 'MadgwickAHRS:53'                 -2*b(4)*q(3),               2*b(4)*q(4),               -4*b(2)*q(3)-2*b(4)*q(1),       -4*b(2)*q(4)+2*b(4)*q(2) */
      /* 'MadgwickAHRS:54'                 -2*b(2)*q(4)+2*b(4)*q(2),	2*b(2)*q(3)+2*b(4)*q(1),	2*b(2)*q(2)+2*b(4)*q(4),       -2*b(2)*q(1)+2*b(4)*q(3) */
      /* 'MadgwickAHRS:55'                 2*b(2)*q(3),                2*b(2)*q(4)-4*b(4)*q(2),	2*b(2)*q(1)-4*b(4)*q(3),        2*b(2)*q(2)]; */
      /* 'MadgwickAHRS:56' step = (J'*F); */
      tmp[0] = -0.0;
      tmp[1] = 0.0;
      tmp[2] = -2.0;
      tmp[3] = 0.0;
      tmp[4] = 0.0;
      tmp[5] = 2.0;
      tmp[6] = 0.0;
      tmp[7] = 0.0;
      tmp[8] = 0.0;
      tmp[9] = -0.0;
      tmp[10] = -0.0;
      tmp[11] = 0.0;
      tmp[12] = -2.0 * h_idx_3 * 0.0;
      tmp[13] = 2.0 * h_idx_3 * 0.0;
      tmp[14] = -4.0 * rtb_Gain1 * 0.0 - 2.0 * h_idx_3;
      tmp[15] = -4.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3 * 0.0;
      tmp[16] = -2.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3 * 0.0;
      tmp[17] = 2.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3;
      tmp[18] = 2.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3 * 0.0;
      tmp[19] = 2.0 * h_idx_3 * 0.0 + -2.0 * rtb_Gain1;
      tmp[20] = 2.0 * rtb_Gain1 * 0.0;
      tmp[21] = 2.0 * rtb_Gain1 * 0.0 - 4.0 * h_idx_3 * 0.0;
      tmp[22] = 2.0 * rtb_Gain1 - 4.0 * h_idx_3 * 0.0;
      tmp[23] = 2.0 * rtb_Gain1 * 0.0;
      tmp_0[0] = 0.0 - accelerometer_idx_0;
      tmp_0[1] = 0.0 - accelerometer_idx_1;
      tmp_0[2] = 1.0 - accelerometer_idx_2;
      tmp_0[3] = (2.0 * rtb_Gain1 * 0.5 + 2.0 * h_idx_3 * 0.0) -
        magnetometer_idx_0;
      tmp_0[4] = (2.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3 * 0.0) -
        magnetometer_idx_1;
      tmp_0[5] = (2.0 * rtb_Gain1 * 0.0 + 2.0 * h_idx_3 * 0.5) -
        AHRS_Quaternion_idx_3;

      /* 'MadgwickAHRS:57' step = step / norm(step); */
      rtb_Gain1 = 0.0;
      b_idx_1 = 2.2250738585072014E-308;
      for (r1 = 0; r1 < 4; r1++) {
        step[r1] = 0.0;
        for (i = 0; i < 6; i++) {
          step[r1] += tmp[(i << 2) + r1] * tmp_0[i];
        }

        b_idx_2 = fabs(step[r1]);
        if (b_idx_2 > b_idx_1) {
          c_t = b_idx_1 / b_idx_2;
          rtb_Gain1 = rtb_Gain1 * c_t * c_t + 1.0;
          b_idx_1 = b_idx_2;
        } else {
          c_t = b_idx_2 / b_idx_1;
          rtb_Gain1 += c_t * c_t;
        }
      }

      rtb_Gain1 = b_idx_1 * sqrt(rtb_Gain1);

      /*  normalise step magnitude */
      /*  Compute rate of change of quaternion */
      /* 'MadgwickAHRS:60' qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; */
      /* QUATERNPROD Calculates the quaternion product */
      /*  */
      /*    ab = quaternProd(a, b) */
      /*  */
      /*    Calculates the quaternion product of quaternion a and b. */
      /*  */
      /*    For more information see: */
      /*    http://www.x-io.co.uk/node/8#quaternions */
      /*  */
      /* 	Date          Author          Notes */
      /* 	27/09/2011    SOH Madgwick    Initial release */
      /* 'quaternProd:13' ab = zeros(size(a)); */
      /* 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); */
      /* 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); */
      /* 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); */
      /* 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); */
      /*  Integrate to yield quaternion */
      /* 'MadgwickAHRS:63' q = q + qDot * obj.SamplePeriod; */
      accelerometer_idx_2 = ((((0.0 - 0.0 * y_idx_0) - 0.0 * y_idx_1) - 0.0 *
        y_idx_2) * 0.5 - step[0] / rtb_Gain1 * 0.1) * 0.00390625 + 1.0;
      accelerometer_idx_1 = (((0.0 * y_idx_2 + y_idx_0) - 0.0 * y_idx_1) * 0.5 -
        step[1] / rtb_Gain1 * 0.1) * 0.00390625;
      accelerometer_idx_0 = (((y_idx_1 - 0.0 * y_idx_2) + 0.0 * y_idx_0) * 0.5 -
        step[2] / rtb_Gain1 * 0.1) * 0.00390625;
      y_idx_0 = (((0.0 * y_idx_1 + y_idx_2) - 0.0 * y_idx_0) * 0.5 - step[3] /
                 rtb_Gain1 * 0.1) * 0.00390625;

      /* 'MadgwickAHRS:64' obj.Quaternion = q / norm(q); */
      b_idx_1 = 2.2250738585072014E-308;
      b_idx_2 = fabs(accelerometer_idx_2);
      if (b_idx_2 > 2.2250738585072014E-308) {
        rtb_Gain1 = 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / 2.2250738585072014E-308;
        rtb_Gain1 = c_t * c_t;
      }

      b_idx_2 = fabs(accelerometer_idx_1);
      if (b_idx_2 > b_idx_1) {
        c_t = b_idx_1 / b_idx_2;
        rtb_Gain1 = rtb_Gain1 * c_t * c_t + 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / b_idx_1;
        rtb_Gain1 += c_t * c_t;
      }

      b_idx_2 = fabs(accelerometer_idx_0);
      if (b_idx_2 > b_idx_1) {
        c_t = b_idx_1 / b_idx_2;
        rtb_Gain1 = rtb_Gain1 * c_t * c_t + 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / b_idx_1;
        rtb_Gain1 += c_t * c_t;
      }

      b_idx_2 = fabs(y_idx_0);
      if (b_idx_2 > b_idx_1) {
        c_t = b_idx_1 / b_idx_2;
        rtb_Gain1 = rtb_Gain1 * c_t * c_t + 1.0;
        b_idx_1 = b_idx_2;
      } else {
        c_t = b_idx_2 / b_idx_1;
        rtb_Gain1 += c_t * c_t;
      }

      rtb_Gain1 = b_idx_1 * sqrt(rtb_Gain1);
      b_idx_1 = accelerometer_idx_2 / rtb_Gain1;
      b_idx_2 = accelerometer_idx_1 / rtb_Gain1;
      c_t = accelerometer_idx_0 / rtb_Gain1;
      AHRS_Quaternion_idx_3 = y_idx_0 / rtb_Gain1;

      /*  normalise quaternion */
    }
  }

  /*  gyroscope units must be radians */
  /* '<S21>:1:12' quaternion = AHRS.Quaternion; */
  /* '<S21>:1:14' euler = quatern2euler(quaternConj(quaternion)) * (180/pi); */
  /* QUATERN2ROTMAT Converts a quaternion to its conjugate */
  /*  */
  /*    qConj = quaternConj(q) */
  /*  */
  /*    Converts a quaternion to its conjugate. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* 'quaternConj:14' qConj = [q(:,1) -q(:,2) -q(:,3) -q(:,4)]; */
  /* QUATERN2EULER Converts a quaternion orientation to ZYX Euler angles */
  /*  */
  /*    q = quatern2euler(q) */
  /*  */
  /*    Converts a quaternion orientation to ZYX Euler angles where phi is a */
  /*    rotation around X, theta around Y and psi around Z. */
  /*  */
  /*    For more information see: */
  /*    http://www.x-io.co.uk/node/8#quaternions */
  /*  */
  /* 	Date          Author          Notes */
  /* 	27/09/2011    SOH Madgwick    Initial release */
  /* 'quatern2euler:14' R = zeros(3,3,(size(q,1))); */
  /* 'quatern2euler:15' R(1,1,:) = 2.*q(:,1).^2-1+2.*q(:,2).^2; */
  R[0] = (b_idx_1 * b_idx_1 * 2.0 - 1.0) + -b_idx_2 * -b_idx_2 * 2.0;

  /* 'quatern2euler:16' R(2,1,:) = 2.*(q(:,2).*q(:,3)-q(:,1).*q(:,4)); */
  R[1] = (-b_idx_2 * -c_t - b_idx_1 * -AHRS_Quaternion_idx_3) * 2.0;

  /* 'quatern2euler:17' R(3,1,:) = 2.*(q(:,2).*q(:,4)+q(:,1).*q(:,3)); */
  R[2] = (-b_idx_2 * -AHRS_Quaternion_idx_3 + b_idx_1 * -c_t) * 2.0;

  /* 'quatern2euler:18' R(3,2,:) = 2.*(q(:,3).*q(:,4)-q(:,1).*q(:,2)); */
  R[5] = (-c_t * -AHRS_Quaternion_idx_3 - b_idx_1 * -b_idx_2) * 2.0;

  /* 'quatern2euler:19' R(3,3,:) = 2.*q(:,1).^2-1+2.*q(:,4).^2; */
  R[8] = (b_idx_1 * b_idx_1 * 2.0 - 1.0) + -AHRS_Quaternion_idx_3 *
    -AHRS_Quaternion_idx_3 * 2.0;

  /* FunctionCaller: '<S3>/Function Caller' */
  /* 'quatern2euler:21' phi = atan2(R(3,2,:), R(3,3,:) ); */
  /* 'quatern2euler:22' theta = -atan(R(3,1,:) ./ sqrt(1-R(3,1,:).^2) ); */
  /* 'quatern2euler:23' psi = atan2(R(2,1,:), R(1,1,:) ); */
  /* 'quatern2euler:25' euler = [phi(1,:)' theta(1,:)' psi(1,:)']; */
  /*  use conjugate for sensor frame relative to Earth and convert to degrees. */
  /* '<S21>:1:15' Z = euler(1,1); */
  /* '<S21>:1:16' Y = euler(1,2); */
  /* '<S21>:1:17' X = euler(1,3); */
  /*  function obj = MadgwickAHRS(varargin) */
  /*      for i = 1:2:nargin */
  /*          if  strcmp(varargin{i}, 'SamplePeriod'), obj.SamplePeriod = varargin{i+1}; */
  /*          elseif  strcmp(varargin{i}, 'Quaternion'), obj.Quaternion = varargin{i+1}; */
  /*          elseif  strcmp(varargin{i}, 'Beta'), obj.Beta = varargin{i+1}; */
  /*          else error('Invalid argument'); */
  /*          end */
  /*      end; */
  /*  end */
  /*  function obj = Update(obj, Gyroscope, Accelerometer, Magnetometer) */
  /*      q = obj.Quaternion; % short name local variable for readability */
  /*   */
  /*      % Normalise accelerometer measurement */
  /*      if(norm(Accelerometer) == 0), return; end	% handle NaN */
  /*      Accelerometer = Accelerometer / norm(Accelerometer);	% normalise magnitude */
  /*   */
  /*      % Normalise magnetometer measurement */
  /*      if(norm(Magnetometer) == 0), return; end	% handle NaN */
  /*      Magnetometer = Magnetometer / norm(Magnetometer);	% normalise magnitude */
  /*   */
  /*      % Reference direction of Earth's magnetic feild */
  /*      h = quaternProd(q, quaternProd([0 Magnetometer], quaternConj(q))); */
  /*      b = [0 norm([h(2) h(3)]) 0 h(4)]; */
  /*   */
  /*      % Gradient decent algorithm corrective step */
  /*      F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1) */
  /*          2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2) */
  /*          2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3) */
  /*          2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3)) - Magnetometer(1) */
  /*          2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4)) - Magnetometer(2) */
  /*          2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2) - Magnetometer(3)]; */
  /*      J = [-2*q(3),                 	2*q(4),                    -2*q(1),                         2*q(2) */
  /*          2*q(2),                 	2*q(1),                    	2*q(4),                         2*q(3) */
  /*          0,                         -4*q(2),                    -4*q(3),                         0 */
  /*          -2*b(4)*q(3),               2*b(4)*q(4),               -4*b(2)*q(3)-2*b(4)*q(1),       -4*b(2)*q(4)+2*b(4)*q(2) */
  /*          -2*b(2)*q(4)+2*b(4)*q(2),	2*b(2)*q(3)+2*b(4)*q(1),	2*b(2)*q(2)+2*b(4)*q(4),       -2*b(2)*q(1)+2*b(4)*q(3) */
  /*          2*b(2)*q(3),                2*b(2)*q(4)-4*b(4)*q(2),	2*b(2)*q(1)-4*b(4)*q(3),        2*b(2)*q(2)]; */
  /*      step = (J'*F); */
  /*      step = step / norm(step);	% normalise step magnitude */
  /*   */
  /*      % Compute rate of change of quaternion */
  /*      qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; */
  /*   */
  /*      % Integrate to yield quaternion */
  /*      q = q + qDot * obj.SamplePeriod; */
  /*      obj.Quaternion = q / norm(q); % normalise quaternion */
  /*  end */
  /*  function obj = UpdateIMU(obj, Gyroscope, Accelerometer) */
  /*      q = obj.Quaternion; % short name local variable for readability */
  /*   */
  /*      % Normalise accelerometer measurement */
  /*      if(norm(Accelerometer) == 0), return; end	% handle NaN */
  /*      Accelerometer = Accelerometer / norm(Accelerometer);	% normalise magnitude */
  /*   */
  /*      % Gradient decent algorithm corrective step */
  /*      F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1) */
  /*          2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2) */
  /*          2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)]; */
  /*      J = [-2*q(3),	2*q(4),    -2*q(1),	2*q(2) */
  /*          2*q(2),     2*q(1),     2*q(4),	2*q(3) */
  /*          0,         -4*q(2),    -4*q(3),	0    ]; */
  /*      step = (J'*F); */
  /*      step = step / norm(step);	% normalise step magnitude */
  /*   */
  /*      % Compute rate of change of quaternion */
  /*      qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; */
  /*   */
  /*      % Integrate to yield quaternion */
  /*      q = q + qDot * obj.SamplePeriod; */
  /*      obj.Quaternion = q / norm(q); % normalise quaternion */
  /*  end */
  measurementDroneFcn_o(rtb_UnitDelay, rtb_FunctionCaller);

  /* Sum: '<S3>/Add' incorporates:
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain3'
   *  Gain: '<S8>/Gain4'
   *  MATLAB Function: '<S8>/MATLAB Function'
   */
  rtb_Add_m[0] = rtb_Gain1_o[0] - rtb_FunctionCaller[0];
  rtb_Add_m[1] = rtb_Gain1_o[1] - rtb_FunctionCaller[1];
  rtb_Add_m[2] = rt_atan2d_snf(R[5], R[8]) * 57.295779513082323 * 0.6 -
    rtb_FunctionCaller[2];
  rtb_Add_m[3] = -atan(R[2] / sqrt(1.0 - R[2] * R[2])) * 57.295779513082323 *
    0.6 - rtb_FunctionCaller[3];
  rtb_Add_m[4] = rt_atan2d_snf(R[1], R[0]) * 57.295779513082323 * 0.6 -
    rtb_FunctionCaller[4];

  /* Trigonometry: '<S9>/Trigonometric Function' */
  b_idx_2 = cos(rtb_UnitDelay[10]);

  /* Sum: '<S9>/Add1' incorporates:
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain4'
   *  Inport: '<Root>/In3'
   *  Sum: '<S9>/Add'
   */
  b_idx_1 = (rtU.In3 - rtb_UnitDelay[0]) * 5.0 - 10.0 * rtb_UnitDelay[3];

  /* Trigonometry: '<S9>/Trigonometric Function3' */
  rtb_Gain1 = sin(rtb_UnitDelay[10]);

  /* Sum: '<S9>/Add2' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain5'
   *  Inport: '<Root>/In3'
   *  Sum: '<S9>/Add'
   */
  c_t = (rtU.In3 - rtb_UnitDelay[1]) * 5.0 - 10.0 * rtb_UnitDelay[4];

  /* Sum: '<S9>/Add6' incorporates:
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product3'
   */
  rtDW.Add6 = b_idx_2 * b_idx_1 + rtb_Gain1 * c_t;

  /* Sum: '<S9>/Add5' incorporates:
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   */
  rtDW.Add5 = rtb_Gain1 * b_idx_1 - b_idx_2 * c_t;

  /* Sum: '<S9>/Add4' incorporates:
   *  Gain: '<S9>/Gain3'
   *  Gain: '<S9>/Gain7'
   *  Inport: '<Root>/In3'
   *  Sum: '<S9>/Add'
   */
  rtDW.Add4 = (rtU.In3 - rtb_UnitDelay[10]) * 5.0 - 10.0 * rtb_UnitDelay[11];

  /* Sum: '<S9>/Add3' incorporates:
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain6'
   *  Inport: '<Root>/In3'
   *  Sum: '<S9>/Add'
   */
  rtDW.Add3 = (rtU.In3 - rtb_UnitDelay[2]) * 5.0 - 10.0 * rtb_UnitDelay[5];

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* MATLAB Function: '<S10>/Correct' incorporates:
   *  Constant: '<S2>/R1'
   *  DataStoreRead: '<S10>/Data Store ReadP'
   *  DataStoreRead: '<S10>/Data Store ReadX'
   *  DataStoreWrite: '<S10>/Data Store WriteP'
   */
  /* MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S14>:1' */
  /* '<S14>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
  /* '<S14>:1:3' if pM.HasJacobian */
  /* '<S14>:1:7' xNew = zeros(size(x),'like',x); */
  /* '<S14>:1:8' PNew = zeros(size(P),'like',x); */
  /* '<S14>:1:9' if pM.HasAdditiveNoise */
  /* '<S14>:1:10' if pM.HasJacobian */
  /* '<S14>:1:13' else */
  /* '<S14>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
  /* '<S14>:1:15'             yMeas,R,x,P,@(xx)MeasurementFcn(xx),[]); */
  measurementTWBFcn_h(rtDW.x, rtb_Gain1_o);
  for (r1 = 0; r1 < 12; r1++) {
    memcpy(&imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
    rtb_Gain1 = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                     (rtDW.x[r1]));
    imvec[r1] = rtDW.x[r1] + rtb_Gain1;
    measurementTWBFcn_h(imvec, imz);
    dHdx[3 * r1] = (imz[0] - rtb_Gain1_o[0]) / rtb_Gain1;
    dHdx[1 + 3 * r1] = (imz[1] - rtb_Gain1_o[1]) / rtb_Gain1;
    dHdx[2 + 3 * r1] = (imz[2] - rtb_Gain1_o[2]) / rtb_Gain1;
  }

  for (i = 0; i < 12; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      Pxy[i + 12 * i_0] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        Pxy[i + 12 * i_0] += rtDW.P_j[12 * r1 + i] * dHdx[3 * r1 + i_0];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 12; i_0++) {
      gain[i + 3 * i_0] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        gain[i + 3 * i_0] += dHdx[3 * r1 + i] * rtDW.P_j[12 * i_0 + r1];
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Gain1 = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        rtb_Gain1 += gain[3 * r1 + i] * dHdx[3 * r1 + i_0];
      }

      R[i + 3 * i_0] = rtCP_R1_Value[3 * i_0 + i] + rtb_Gain1;
    }
  }

  measurementTWBFcn_h(rtDW.x, rtb_Gain1_o);
  r1 = 0;
  r2 = 1;
  r3 = 2;
  rtb_Gain1 = fabs(R[0]);
  b_idx_1 = fabs(R[1]);
  if (b_idx_1 > rtb_Gain1) {
    rtb_Gain1 = b_idx_1;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(R[2]) > rtb_Gain1) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  R[r2] /= R[r1];
  R[r3] /= R[r1];
  R[3 + r2] -= R[3 + r1] * R[r2];
  R[3 + r3] -= R[3 + r1] * R[r3];
  R[6 + r2] -= R[6 + r1] * R[r2];
  R[6 + r3] -= R[6 + r1] * R[r3];
  if (fabs(R[3 + r3]) > fabs(R[3 + r2])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  R[3 + r3] /= R[3 + r2];
  R[6 + r3] -= R[3 + r3] * R[6 + r2];
  for (rtemp = 0; rtemp < 12; rtemp++) {
    gain[rtemp + 12 * r1] = Pxy[rtemp] / R[r1];
    gain[rtemp + 12 * r2] = Pxy[12 + rtemp] - gain[12 * r1 + rtemp] * R[3 + r1];
    gain[rtemp + 12 * r3] = Pxy[24 + rtemp] - gain[12 * r1 + rtemp] * R[6 + r1];
    gain[rtemp + 12 * r2] /= R[3 + r2];
    gain[rtemp + 12 * r3] -= gain[12 * r2 + rtemp] * R[6 + r2];
    gain[rtemp + 12 * r3] /= R[6 + r3];
    gain[rtemp + 12 * r2] -= gain[12 * r3 + rtemp] * R[3 + r3];
    gain[rtemp + 12 * r1] -= gain[12 * r3 + rtemp] * R[r3];
    gain[rtemp + 12 * r1] -= gain[12 * r2 + rtemp] * R[r2];
    for (i = 0; i < 12; i++) {
      Jacobian[rtemp + 12 * i] = 0.0;
      Jacobian[rtemp + 12 * i] += dHdx[3 * i] * gain[rtemp];
      Jacobian[rtemp + 12 * i] += dHdx[3 * i + 1] * gain[rtemp + 12];
      Jacobian[rtemp + 12 * i] += dHdx[3 * i + 2] * gain[rtemp + 24];
    }

    for (i = 0; i < 12; i++) {
      rtb_Gain1 = 0.0;
      for (i_0 = 0; i_0 < 12; i_0++) {
        rtb_Gain1 += Jacobian[12 * i_0 + rtemp] * rtDW.P_j[12 * i + i_0];
      }

      Jacobian_0[rtemp + 12 * i] = rtDW.P_j[12 * i + rtemp] - rtb_Gain1;
    }
  }

  rtb_Add_p_idx_0 -= rtb_Gain1_o[0];
  rtb_Add_p_idx_1 -= rtb_Gain1_o[1];
  rtb_Add_p_idx_2 -= rtb_Gain1_o[2];
  for (i = 0; i < 12; i++) {
    /* DataStoreWrite: '<S10>/Data Store WriteP' incorporates:
     *  MATLAB Function: '<S10>/Correct'
     */
    memcpy(&rtDW.P_j[i * 12], &Jacobian_0[i * 12], 12U * sizeof(real_T));

    /* DataStoreWrite: '<S10>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S10>/Data Store ReadX'
     *  MATLAB Function: '<S10>/Correct'
     */
    rtDW.x[i] += (gain[i + 12] * rtb_Add_p_idx_1 + gain[i] * rtb_Add_p_idx_0) +
      gain[i + 24] * rtb_Add_p_idx_2;
  }

  /* End of Outputs for SubSystem: '<S2>/Correct1' */

  /* Outputs for Enabled SubSystem: '<S2>/Correct2' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* MATLAB Function: '<S11>/Correct' incorporates:
   *  Constant: '<S2>/R2'
   *  DataStoreRead: '<S11>/Data Store ReadP'
   *  DataStoreRead: '<S11>/Data Store ReadX'
   *  DataStoreWrite: '<S11>/Data Store WriteP'
   */
  /* MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S15>:1' */
  /* '<S15>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName)); */
  /* '<S15>:1:3' if pM.HasJacobian */
  /* '<S15>:1:7' xNew = zeros(size(x),'like',x); */
  /* '<S15>:1:8' PNew = zeros(size(P),'like',x); */
  /* '<S15>:1:9' if pM.HasAdditiveNoise */
  /* '<S15>:1:10' if pM.HasJacobian */
  /* '<S15>:1:13' else */
  /* '<S15>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... */
  /* '<S15>:1:15'             yMeas,R,x,P,@(xx)MeasurementFcn(xx),[]); */
  measurementDroneFcn_o(rtDW.x, rtb_FunctionCaller);
  for (r1 = 0; r1 < 12; r1++) {
    memcpy(&imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
    rtb_Gain1 = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                     (rtDW.x[r1]));
    imvec[r1] = rtDW.x[r1] + rtb_Gain1;
    measurementDroneFcn_o(imvec, imz_0);
    for (i = 0; i < 5; i++) {
      dHdx_0[i + 5 * r1] = (imz_0[i] - rtb_FunctionCaller[i]) / rtb_Gain1;
    }
  }

  measurementDroneFcn_o(rtDW.x, rtb_FunctionCaller);
  for (i = 0; i < 12; i++) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      gain_0[i + 12 * i_0] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        gain_0[i + 12 * i_0] += rtDW.P_j[12 * r1 + i] * dHdx_0[5 * r1 + i_0];
      }
    }
  }

  for (i = 0; i < 5; i++) {
    for (i_0 = 0; i_0 < 12; i_0++) {
      dHdx_2[i + 5 * i_0] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        dHdx_2[i + 5 * i_0] += dHdx_0[5 * r1 + i] * rtDW.P_j[12 * i_0 + r1];
      }
    }

    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Gain1 = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        rtb_Gain1 += dHdx_2[5 * r1 + i] * dHdx_0[5 * r1 + i_0];
      }

      dHdx_1[i + 5 * i_0] = rtCP_R2_Value[5 * i_0 + i] + rtb_Gain1;
    }
  }

  iecjgdjeaimokfcj_mrdivide(gain_0, dHdx_1);
  for (i = 0; i < 12; i++) {
    for (i_0 = 0; i_0 < 12; i_0++) {
      Jacobian[i + 12 * i_0] = 0.0;
      for (r1 = 0; r1 < 5; r1++) {
        Jacobian[i + 12 * i_0] += gain_0[12 * r1 + i] * dHdx_0[5 * i_0 + r1];
      }
    }

    for (i_0 = 0; i_0 < 12; i_0++) {
      rtb_Gain1 = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        rtb_Gain1 += Jacobian[12 * r1 + i] * rtDW.P_j[12 * i_0 + r1];
      }

      Jacobian_0[i + 12 * i_0] = rtDW.P_j[12 * i_0 + i] - rtb_Gain1;
    }
  }

  /* DataStoreWrite: '<S11>/Data Store WriteP' incorporates:
   *  MATLAB Function: '<S11>/Correct'
   */
  for (i = 0; i < 12; i++) {
    memcpy(&rtDW.P_j[i * 12], &Jacobian_0[i * 12], 12U * sizeof(real_T));
  }

  /* MATLAB Function: '<S11>/Correct' */
  for (i = 0; i < 5; i++) {
    imz_0[i] = rtb_Add_m[i] - rtb_FunctionCaller[i];
  }

  /* Outputs for Atomic SubSystem: '<S2>/Output' */
  for (r1 = 0; r1 < 12; r1++) {
    /* DataStoreWrite: '<S11>/Data Store WriteX' incorporates:
     *  DataStoreRead: '<S11>/Data Store ReadX'
     *  MATLAB Function: '<S11>/Correct'
     */
    rtb_Gain1 = 0.0;
    for (i = 0; i < 5; i++) {
      rtb_Gain1 += gain_0[12 * i + r1] * imz_0[i];
    }

    rtDW.x[r1] += rtb_Gain1;

    /* End of DataStoreWrite: '<S11>/Data Store WriteX' */

    /* DataStoreRead: '<S12>/Data Store Read' */
    rtb_UnitDelay[r1] = rtDW.x[r1];
  }

  /* End of Outputs for SubSystem: '<S2>/Output' */
  /* End of Outputs for SubSystem: '<S2>/Correct2' */

  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  /* MATLAB Function: '<S13>/Predict' incorporates:
   *  DataStoreRead: '<S13>/Data Store ReadP'
   *  DataStoreRead: '<S13>/Data Store ReadX'
   */
  /* MATLAB Function 'Extras/EKFPredict_SLFcn_0Input/Predict': '<S16>:1' */
  /* '<S16>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName)); */
  /* '<S16>:1:3' if pS.HasJacobian */
  /* '<S16>:1:7' xNew = zeros(size(x),'like',x); */
  /* '<S16>:1:8' PNew = zeros(size(P),'like',x); */
  /* '<S16>:1:9' if pS.HasAdditiveNoise */
  /* '<S16>:1:10' if pS.HasJacobian */
  /* '<S16>:1:13' else */
  /* '<S16>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFPredictorAdditive.predict(... */
  /* '<S16>:1:15'             Q,x,P,@(xx)StateTransitionFcn(xx), []); */
  stateTransitionFcn(rtDW.x, z);
  for (r1 = 0; r1 < 12; r1++) {
    memcpy(&imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
    rtb_Gain1 = fmax(1.4901161193847656E-8, 1.4901161193847656E-8 * fabs
                     (rtDW.x[r1]));
    imvec[r1] = rtDW.x[r1] + rtb_Gain1;
    stateTransitionFcn(imvec, imz_1);
    for (i = 0; i < 12; i++) {
      Jacobian[i + 12 * r1] = (imz_1[i] - z[i]) / rtb_Gain1;
    }
  }

  stateTransitionFcn(rtDW.x, imvec);
  for (i = 0; i < 12; i++) {
    for (i_0 = 0; i_0 < 12; i_0++) {
      Jacobian_0[i_0 + 12 * i] = 0.0;
      for (r1 = 0; r1 < 12; r1++) {
        Jacobian_0[i_0 + 12 * i] += Jacobian[12 * r1 + i_0] * rtDW.P_j[12 * i +
          r1];
      }
    }
  }

  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter' */

  /* Outport: '<Root>/Out2' */
  rtY.Out2[0] = rtDW.Add3;
  rtY.Out2[1] = rtDW.Add4;
  rtY.Out2[2] = rtDW.Add5;
  rtY.Out2[3] = rtDW.Add6;

  /* Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Outputs for Atomic SubSystem: '<S2>/Predict' */
  for (r1 = 0; r1 < 12; r1++) {
    /* DataStoreWrite: '<S13>/Data Store WriteP' incorporates:
     *  Constant: '<S2>/Q'
     *  MATLAB Function: '<S13>/Predict'
     */
    for (i = 0; i < 12; i++) {
      rtb_Gain1 = 0.0;
      for (i_0 = 0; i_0 < 12; i_0++) {
        rtb_Gain1 += Jacobian_0[12 * i_0 + r1] * Jacobian[12 * i_0 + i];
      }

      rtDW.P_j[r1 + 12 * i] = rtCP_Q_Value[12 * i + r1] + rtb_Gain1;
    }

    /* End of DataStoreWrite: '<S13>/Data Store WriteP' */

    /* DataStoreWrite: '<S13>/Data Store WriteX' incorporates:
     *  MATLAB Function: '<S13>/Predict'
     */
    rtDW.x[r1] = imvec[r1];

    /* Outport: '<Root>/Out1' */
    rtY.Out1[r1] = rtb_UnitDelay[r1];

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    rtDW.UnitDelay_DSTATE[r1] = rtb_UnitDelay[r1];
  }

  /* End of Outputs for SubSystem: '<S2>/Predict' */
  /* End of Outputs for SubSystem: '<S1>/Extended Kalman Filter' */
  rate_scheduler();
}

/* Model initialize function */
void PoseEstimationController_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for Atomic SubSystem: '<S1>/Extended Kalman Filter' */
  /* Start for DataStoreMemory: '<S2>/DataStoreMemory - P' */
  memcpy(&rtDW.P_j[0], &rtCP_DataStoreMemoryP_InitialVa[0], 144U * sizeof(real_T));

  /* End of Start for SubSystem: '<S1>/Extended Kalman Filter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
