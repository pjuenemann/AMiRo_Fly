//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PoseEstimationController.cpp
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
#include "PoseEstimationController.h"
#include "dbiemohljmgdohdb_norm.h"
#include "rt_atan2d_snf.h"
#include <MSG.h>


// Block signals and states (auto storage)
DW rtDW;

// External inputs (root inport signals with auto storage)
ExtU rtU;

// External outputs (root outports fed by signals with auto storage)
ExtY rtY;

// Real-time model
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const real_T rtCP_pooled_XyLjpsXjcyos[9];
extern const real_T rtCP_pooled_299Jb13UAswe[25];
extern const real_T rtCP_pooled_wKVRBqsAl7SO[144];
extern const real_T rtCP_pooled_dEObodluTwti[144];
extern const real_T rtCP_pooled_gVsoQfjsu5wl[36];
extern const real_T rtCP_pooled_TXrxOtAA33B0[60];

#define rtCP_R1_Value                  rtCP_pooled_XyLjpsXjcyos  // Expression: p.R{1}
                                                                 //  Referenced by: '<S2>/R1'

#define rtCP_R2_Value                  rtCP_pooled_299Jb13UAswe  // Expression: p.R{2}
                                                                 //  Referenced by: '<S2>/R2'

#define rtCP_Q_Value                   rtCP_pooled_wKVRBqsAl7SO  // Expression: p.Q
                                                                 //  Referenced by: '<S2>/Q'

#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_dEObodluTwti // Expression: p.InitialCovariance
                                                                 //  Referenced by: '<S2>/DataStoreMemory - P'

#define rtCP_H_TWB_Value               rtCP_pooled_gVsoQfjsu5wl  // Expression: H_TWB
                                                                 //  Referenced by: '<S5>/H_TWB'

#define rtCP_H_drone_Value             rtCP_pooled_TXrxOtAA33B0  // Expression: H_Drone
                                                                 //  Referenced by: '<S6>/H_drone'


extern void measurementTWBFcn_h(const real_T rtu_x[12], real_T rty_y[3]);
extern void measurementDroneFcn_o(const real_T rtu_x[12], real_T rty_y[5]);
extern void stateTransitionFcn(const real_T rtu_x[12], real_T rty_y[12]);

// Forward declaration for local functions
static void iecjgdjeaimokfcj_mrdivide(real_T A[60], const real_T B_0[25]);

// Output and update for Simulink Function: '<S1>/Simulink Function1'
void measurementTWBFcn_h(const real_T rtu_x[12], real_T rty_y[3])
{
  int32_T i;
  int32_T i_0;

  // SignalConversion: '<S5>/TmpSignal ConversionAtyInport1' incorporates:
  //   Constant: '<S5>/H_TWB'
  //   Product: '<S5>/Product2'
  //   SignalConversion: '<S5>/TmpSignal ConversionAtxOutport1'

  for (i = 0; i < 3; i++) {
    rty_y[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      rty_y[i] += rtCP_H_TWB_Value[3 * i_0 + i] * rtu_x[i_0];
    }
  }

  // End of SignalConversion: '<S5>/TmpSignal ConversionAtyInport1'
}

// Output and update for Simulink Function: '<S1>/Simulink Function2'
void measurementDroneFcn_o(const real_T rtu_x[12], real_T rty_y[5])
{
  int32_T i;
  int32_T i_0;

  // SignalConversion: '<S6>/TmpSignal ConversionAtyInport1' incorporates:
  //   Constant: '<S6>/H_drone'
  //   Product: '<S6>/Product2'
  //   SignalConversion: '<S6>/TmpSignal ConversionAtxOutport1'

  for (i = 0; i < 5; i++) {
    rty_y[i] = 0.0;
    for (i_0 = 0; i_0 < 12; i_0++) {
      rty_y[i] += rtCP_H_drone_Value[5 * i_0 + i] * rtu_x[i_0];
    }
  }

  // End of SignalConversion: '<S6>/TmpSignal ConversionAtyInport1'
}

// Output and update for Simulink Function: '<S1>/Simulink Function3'
void stateTransitionFcn(const real_T rtu_x[12], real_T rty_y[12])
{
  real_T rtb_Add3_c;
  real_T rtb_Add2_b;
  real_T rtb_Add6_m;
  real_T rtb_Add5_k;
  real_T rtb_Add8_e;

  // Trigonometry: '<S7>/cos' incorporates:
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'

  rtb_Add3_c = std::cos(rtu_x[10]);

  // Trigonometry: '<S7>/sin' incorporates:
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'

  rtb_Add2_b = std::sin(rtu_x[10]);

  // Trigonometry: '<S18>/sin3' incorporates:
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'

  rtb_Add6_m = std::sin(rtu_x[10]);

  // Trigonometry: '<S18>/cos2' incorporates:
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'

  rtb_Add5_k = std::cos(rtu_x[9]);

  // Trigonometry: '<S18>/cos3' incorporates:
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'

  rtb_Add8_e = std::cos(rtu_x[10]);

  // SignalConversion: '<S7>/TmpSignal ConversionAtyInport1' incorporates:
  //   Constant: '<S17>/K10'
  //   Constant: '<S17>/K11'
  //   Constant: '<S17>/K12'
  //   Constant: '<S17>/K5'
  //   Constant: '<S17>/K6'
  //   Constant: '<S17>/K7'
  //   Constant: '<S17>/K8'
  //   Constant: '<S17>/K9'
  //   Constant: '<S18>/K1'
  //   Constant: '<S18>/K2'
  //   Constant: '<S18>/K3'
  //   Constant: '<S18>/K4'
  //   Constant: '<S7>/dt'
  //   Constant: '<S7>/dt1'
  //   Product: '<S17>/Product'
  //   Product: '<S17>/Product1'
  //   Product: '<S17>/Product2'
  //   Product: '<S17>/Product3'
  //   Product: '<S17>/Product4'
  //   Product: '<S17>/Product5'
  //   Product: '<S17>/Product6'
  //   Product: '<S17>/Product7'
  //   Product: '<S18>/Product13'
  //   Product: '<S18>/Product14'
  //   Product: '<S18>/Product15'
  //   Product: '<S18>/Product16'
  //   Product: '<S18>/Product17'
  //   Product: '<S18>/Product5'
  //   Product: '<S18>/Product6'
  //   Product: '<S18>/Product7'
  //   Product: '<S7>/Product1'
  //   Product: '<S7>/Product10'
  //   Product: '<S7>/Product11'
  //   Product: '<S7>/Product12'
  //   Product: '<S7>/Product2'
  //   Product: '<S7>/Product3'
  //   Product: '<S7>/Product4'
  //   Product: '<S7>/Product5'
  //   Product: '<S7>/Product8'
  //   Product: '<S7>/Product9'
  //   SignalConversion: '<S7>/TmpLatchAtuOutport1'
  //   SignalConversion: '<S7>/TmpSignal ConversionAtxOutport1'
  //   Sum: '<S17>/Add'
  //   Sum: '<S17>/Add1'
  //   Sum: '<S17>/Add2'
  //   Sum: '<S17>/Add3'
  //   Sum: '<S18>/Add5'
  //   Sum: '<S18>/Add6'
  //   Sum: '<S18>/Add7'
  //   Sum: '<S18>/Add8'
  //   Sum: '<S7>/Add1'
  //   Sum: '<S7>/Add2'
  //   Sum: '<S7>/Add3'
  //   Sum: '<S7>/Add4'
  //   Sum: '<S7>/Add5'
  //   Sum: '<S7>/Add6'
  //   Sum: '<S7>/Add7'
  //   Sum: '<S7>/Add8'
  //   Trigonometry: '<S18>/cos1'
  //   Trigonometry: '<S18>/sin1'
  //   Trigonometry: '<S18>/sin2'

  rty_y[0] = 0.01 * rtu_x[3] + rtu_x[0];
  rty_y[1] = 0.01 * rtu_x[4] + rtu_x[1];
  rty_y[2] = 0.01 * rtu_x[5] + rtu_x[2];
  rty_y[3] = rtb_Add3_c * rtu_x[6] - rtb_Add2_b * rtu_x[7];
  rty_y[4] = rtb_Add2_b * rtu_x[6] + rtb_Add3_c * rtu_x[7];
  rty_y[5] = (5.234 * rtDW.Add3 - rtu_x[5] * 6.234) * 0.01 + rtu_x[5];
  rty_y[6] = (rtb_Add6_m * rtb_Add5_k * std::cos(rtu_x[8]) + rtb_Add8_e * std::
              sin(rtu_x[9])) * 1.234 - 2.234 * rtu_x[6];
  rty_y[7] = (rtb_Add6_m * rtb_Add5_k - rtb_Add8_e * std::sin(rtu_x[8]) *
              rtb_Add5_k) * 3.234 - 4.234 * rtu_x[7];
  rty_y[8] = (9.234 * rtDW.Add5 - rtu_x[8] * 10.234) * 0.01 + rtu_x[8];
  rty_y[9] = (11.234 * rtDW.Add6 - rtu_x[9] * 12.234) * 0.01 + rtu_x[9];
  rty_y[10] = rtu_x[11] * 0.01 + rtu_x[10];
  rty_y[11] = (7.234 * rtDW.Add4 - rtu_x[11] * 8.234) * 0.01 + rtu_x[11];
}

// Function for MATLAB Function: '<S11>/Correct'
static void iecjgdjeaimokfcj_mrdivide(real_T A[60], const real_T B_0[25])
{
  int32_T ix;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T b_jAcol;
  int32_T b_kBcol;
  memcpy(&rtDW.b_A[0], &B_0[0], 25U * sizeof(real_T));
  for (rtDW.j = 0; rtDW.j < 5; rtDW.j++) {
    rtDW.ipiv[rtDW.j] = (int8_T)(1 + rtDW.j);
  }

  for (rtDW.j = 0; rtDW.j < 4; rtDW.j++) {
    rtDW.jp = rtDW.j * 6;
    b_jAcol = 0;
    ix = rtDW.jp;
    rtDW.temp = std::abs(rtDW.b_A[rtDW.jp]);
    for (b_kBcol = 2; b_kBcol <= 5 - rtDW.j; b_kBcol++) {
      ix++;
      rtDW.s = std::abs(rtDW.b_A[ix]);
      if (rtDW.s > rtDW.temp) {
        b_jAcol = b_kBcol - 1;
        rtDW.temp = rtDW.s;
      }
    }

    if (rtDW.b_A[rtDW.jp + b_jAcol] != 0.0) {
      if (b_jAcol != 0) {
        rtDW.ipiv[rtDW.j] = (int8_T)((rtDW.j + b_jAcol) + 1);
        ix = rtDW.j;
        b_jAcol += rtDW.j;
        for (b_kBcol = 0; b_kBcol < 5; b_kBcol++) {
          rtDW.temp = rtDW.b_A[ix];
          rtDW.b_A[ix] = rtDW.b_A[b_jAcol];
          rtDW.b_A[b_jAcol] = rtDW.temp;
          ix += 5;
          b_jAcol += 5;
        }
      }

      b_jAcol = (rtDW.jp - rtDW.j) + 5;
      for (ix = rtDW.jp + 1; ix + 1 <= b_jAcol; ix++) {
        rtDW.b_A[ix] /= rtDW.b_A[rtDW.jp];
      }
    }

    b_jAcol = rtDW.jp;
    ix = rtDW.jp + 5;
    for (b_kBcol = 1; b_kBcol <= 4 - rtDW.j; b_kBcol++) {
      rtDW.temp = rtDW.b_A[ix];
      if (rtDW.b_A[ix] != 0.0) {
        c_ix = rtDW.jp + 1;
        d = (b_jAcol - rtDW.j) + 10;
        for (ijA = 6 + b_jAcol; ijA + 1 <= d; ijA++) {
          rtDW.b_A[ijA] += rtDW.b_A[c_ix] * -rtDW.temp;
          c_ix++;
        }
      }

      ix += 5;
      b_jAcol += 5;
    }
  }

  for (rtDW.j = 0; rtDW.j < 5; rtDW.j++) {
    rtDW.jp = 12 * rtDW.j;
    b_jAcol = 5 * rtDW.j;
    for (ix = 1; ix <= rtDW.j; ix++) {
      b_kBcol = (ix - 1) * 12;
      if (rtDW.b_A[(ix + b_jAcol) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 12; c_ix++) {
          A[c_ix + rtDW.jp] -= rtDW.b_A[(ix + b_jAcol) - 1] * A[c_ix + b_kBcol];
        }
      }
    }

    rtDW.temp = 1.0 / rtDW.b_A[rtDW.j + b_jAcol];
    for (b_jAcol = 0; b_jAcol < 12; b_jAcol++) {
      A[b_jAcol + rtDW.jp] *= rtDW.temp;
    }
  }

  for (rtDW.j = 4; rtDW.j >= 0; rtDW.j += -1) {
    rtDW.jp = 12 * rtDW.j;
    b_jAcol = 5 * rtDW.j - 1;
    for (ix = rtDW.j + 2; ix < 6; ix++) {
      b_kBcol = (ix - 1) * 12;
      if (rtDW.b_A[ix + b_jAcol] != 0.0) {
        for (c_ix = 0; c_ix < 12; c_ix++) {
          A[c_ix + rtDW.jp] -= rtDW.b_A[ix + b_jAcol] * A[c_ix + b_kBcol];
        }
      }
    }
  }

  for (rtDW.j = 3; rtDW.j >= 0; rtDW.j += -1) {
    if (rtDW.j + 1 != rtDW.ipiv[rtDW.j]) {
      rtDW.jp = rtDW.ipiv[rtDW.j] - 1;
      for (b_jAcol = 0; b_jAcol < 12; b_jAcol++) {
        rtDW.temp = A[12 * rtDW.j + b_jAcol];
        A[b_jAcol + 12 * rtDW.j] = A[12 * rtDW.jp + b_jAcol];
        A[b_jAcol + 12 * rtDW.jp] = rtDW.temp;
      }
    }
  }
}

// Model step function
void PoseEstimationController_step(void)
{
  // Gain: '<S4>/TWB_gain' incorporates:
  //   Inport: '<Root>/TWB_data '

  rtDW.rtb_TWB_gain_idx_0 = 2.0 * rtU.TWB_data[0];
  rtDW.rtb_TWB_gain_idx_1 = 2.0 * rtU.TWB_data[1];
  rtDW.rtb_TWB_gain_idx_2 = 2.0 * rtU.TWB_data[2];

  // UnitDelay: '<S1>/Unit Delay'
  memcpy(&rtDW.UnitDelay[0], &rtDW.UnitDelay_DSTATE[0], 12U * sizeof(real_T));

  // FunctionCaller: '<S4>/Function Caller'
  measurementTWBFcn_h(rtDW.UnitDelay, rtDW.UnitDelay_f);

  // Gain: '<S9>/acc_scale' incorporates:
  //   Inport: '<Root>/drone_raw_data'

  rtDW.rtb_acc_scale_m = 0.0047900390625 * rtU.drone_raw_data[3];

  // SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   Gain: '<S9>/gyro_scale'
  //   Inport: '<Root>/drone_raw_data'
  //   MATLAB Function: '<S9>/MATLAB Function'

  rtDW.TmpSignalConversionAtSFunct[0] = 0.060975609756097567 *
    rtU.drone_raw_data[0];
  rtDW.TmpSignalConversionAtSFunct[3] = rtDW.rtb_acc_scale_m;

  // Sum: '<S4>/Add'
  rtDW.rtb_TWB_gain_idx_0 -= rtDW.UnitDelay_f[0];

  // UnitDelay: '<S9>/Unit Delay'
  rtDW.UnitDelay_f[0] = rtDW.UnitDelay_DSTATE_b[0];

  // Gain: '<S9>/acc_scale' incorporates:
  //   Inport: '<Root>/drone_raw_data'

  rtDW.rtb_acc_scale_idx_0 = rtDW.rtb_acc_scale_m;
  rtDW.rtb_acc_scale_m = 0.0047900390625 * rtU.drone_raw_data[4];

  // SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   Gain: '<S9>/gyro_scale'
  //   Inport: '<Root>/drone_raw_data'
  //   MATLAB Function: '<S9>/MATLAB Function'

  rtDW.TmpSignalConversionAtSFunct[1] = 0.060975609756097567 *
    rtU.drone_raw_data[1];
  rtDW.TmpSignalConversionAtSFunct[4] = rtDW.rtb_acc_scale_m;

  // Sum: '<S4>/Add'
  rtDW.rtb_TWB_gain_idx_1 -= rtDW.UnitDelay_f[1];

  // UnitDelay: '<S9>/Unit Delay'
  rtDW.UnitDelay_f[1] = rtDW.UnitDelay_DSTATE_b[1];

  // Gain: '<S9>/acc_scale' incorporates:
  //   Inport: '<Root>/drone_raw_data'

  rtDW.rtb_acc_scale_idx_1 = rtDW.rtb_acc_scale_m;
  rtDW.rtb_acc_scale_m = 0.0047900390625 * rtU.drone_raw_data[5];

  // SignalConversion: '<S19>/TmpSignal ConversionAt SFunction Inport1' incorporates:
  //   Gain: '<S9>/gyro_scale'
  //   Gain: '<S9>/mag_scale'
  //   Inport: '<Root>/drone_raw_data'
  //   MATLAB Function: '<S9>/MATLAB Function'

  rtDW.TmpSignalConversionAtSFunct[2] = 0.060975609756097567 *
    rtU.drone_raw_data[2];
  rtDW.TmpSignalConversionAtSFunct[5] = rtDW.rtb_acc_scale_m;
  for (rtDW.i = 0; rtDW.i < 9; rtDW.i++) {
    rtDW.TmpSignalConversionAtSFunct[rtDW.i + 6] = 6.0E-7 *
      rtU.drone_raw_data[rtDW.i];
  }

  // MATLAB Function: '<S9>/MATLAB Function'
  //     %% Process sensor data through algorithm
  // MATLAB Function 'ExtendedKalmanFilter /raw_to_real_data/MATLAB Function': '<S19>:1' 
  // '<S19>:1:3' data = data';
  // '<S19>:1:4' gyroscope = data(1,[1:3]);
  // '<S19>:1:5' accelerometer = data(1,[4:6]);
  // '<S19>:1:6' magnetometer = data(1,[7:9]);
  // '<S19>:1:7' AHRS = MadgwickAHRS('SamplePeriod', 1/256, 'Beta', 0.1);
  rtDW.b_idx_1 = 1.0;
  rtDW.b_idx_2 = 0.0;
  rtDW.c_t = 0.0;
  rtDW.AHRS_Quaternion_idx_3 = 0.0;

  // MADGWICKAHRS Implementation of Madgwick's IMU and AHRS algorithms
  //
  //    For more information see:
  //    http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms
  //
  //    Date          Author          Notes
  //    28/09/2011    SOH Madgwick    Initial release
  //     %% Public properties
  //  output quaternion describing the Earth relative to the sensor
  //  algorithm gain
  //     %% Public methods
  // 'MadgwickAHRS:20' for i = 1:2:nargin
  // 'MadgwickAHRS:21' if  strcmp(varargin{i}, 'SamplePeriod')
  // 'MadgwickAHRS:21' obj.SamplePeriod = varargin{i+1};
  // 'MadgwickAHRS:21' if  strcmp(varargin{i}, 'SamplePeriod')
  // 'MadgwickAHRS:23' elseif  strcmp(varargin{i}, 'Beta')
  // 'MadgwickAHRS:23' obj.Beta = varargin{i+1};
  //  AHRS = MahonyAHRS('SamplePeriod', 1/256, 'Kp', 0.5);
  // '<S19>:1:10' quaternion = zeros(1, 4);
  // '<S19>:1:11' AHRS.Update(gyroscope(1,:) * (pi/180), accelerometer(1,:), magnetometer(1,:)); 
  rtDW.y_idx_0 = rtDW.TmpSignalConversionAtSFunct[0] * 0.017453292519943295;
  rtDW.y_idx_1 = rtDW.TmpSignalConversionAtSFunct[1] * 0.017453292519943295;
  rtDW.y_idx_2 = rtDW.TmpSignalConversionAtSFunct[2] * 0.017453292519943295;

  // 'MadgwickAHRS:29' q = obj.Quaternion;
  //  short name local variable for readability
  //  Normalise accelerometer measurement
  // 'MadgwickAHRS:32' if(norm(Accelerometer) == 0)
  if (!(dbiemohljmgdohdb_norm(&rtDW.TmpSignalConversionAtSFunct[3]) == 0.0)) {
    //  handle NaN
    // 'MadgwickAHRS:33' Accelerometer = Accelerometer / norm(Accelerometer);
    rtDW.cos_g = dbiemohljmgdohdb_norm(&rtDW.TmpSignalConversionAtSFunct[3]);
    rtDW.accelerometer_idx_0 = rtDW.TmpSignalConversionAtSFunct[3] / rtDW.cos_g;
    rtDW.accelerometer_idx_1 = rtDW.TmpSignalConversionAtSFunct[4] / rtDW.cos_g;
    rtDW.accelerometer_idx_2 = rtDW.TmpSignalConversionAtSFunct[5] / rtDW.cos_g;

    //  normalise magnitude
    //  Normalise magnetometer measurement
    // 'MadgwickAHRS:36' if(norm(Magnetometer) == 0)
    if (!(dbiemohljmgdohdb_norm(&rtDW.TmpSignalConversionAtSFunct[6]) == 0.0)) {
      //  handle NaN
      // 'MadgwickAHRS:37' Magnetometer = Magnetometer / norm(Magnetometer);
      rtDW.cos_g = dbiemohljmgdohdb_norm(&rtDW.TmpSignalConversionAtSFunct[6]);

      //  normalise magnitude
      //  Reference direction of Earth's magnetic feild
      // 'MadgwickAHRS:40' h = quaternProd(q, quaternProd([0 Magnetometer], quaternConj(q))); 
      // QUATERN2ROTMAT Converts a quaternion to its conjugate
      //
      //    qConj = quaternConj(q)
      //
      //    Converts a quaternion to its conjugate.
      //
      //    For more information see:
      //    http://www.x-io.co.uk/node/8#quaternions
      //
      // 	Date          Author          Notes
      // 	27/09/2011    SOH Madgwick    Initial release
      // 'quaternConj:14' qConj = [q(:,1) -q(:,2) -q(:,3) -q(:,4)];
      rtDW.AHRS_Quaternion_idx_3 = rtDW.TmpSignalConversionAtSFunct[6] /
        rtDW.cos_g;
      rtDW.b_idx_1 = rtDW.AHRS_Quaternion_idx_3;
      rtDW.magnetometer_idx_0 = rtDW.AHRS_Quaternion_idx_3;
      rtDW.AHRS_Quaternion_idx_3 = rtDW.TmpSignalConversionAtSFunct[7] /
        rtDW.cos_g;
      rtDW.b_idx_2 = rtDW.AHRS_Quaternion_idx_3;
      rtDW.magnetometer_idx_1 = rtDW.AHRS_Quaternion_idx_3;
      rtDW.AHRS_Quaternion_idx_3 = rtDW.TmpSignalConversionAtSFunct[8] /
        rtDW.cos_g;

      // QUATERNPROD Calculates the quaternion product
      //
      //    ab = quaternProd(a, b)
      //
      //    Calculates the quaternion product of quaternion a and b.
      //
      //    For more information see:
      //    http://www.x-io.co.uk/node/8#quaternions
      //
      // 	Date          Author          Notes
      // 	27/09/2011    SOH Madgwick    Initial release
      // 'quaternProd:13' ab = zeros(size(a));
      // 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); 
      rtDW.ab_idx_0 = ((0.0 - rtDW.b_idx_1 * -0.0) - rtDW.b_idx_2 * -0.0) -
        rtDW.AHRS_Quaternion_idx_3 * -0.0;

      // 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); 
      rtDW.ab_idx_1 = (rtDW.b_idx_2 * -0.0 + rtDW.b_idx_1) -
        rtDW.AHRS_Quaternion_idx_3 * -0.0;

      // 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); 
      rtDW.ab_idx_2 = ((-0.0 - rtDW.b_idx_1 * -0.0) + rtDW.b_idx_2) +
        rtDW.AHRS_Quaternion_idx_3 * -0.0;

      // 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); 
      rtDW.ab_idx_3 = (rtDW.b_idx_1 * -0.0 - rtDW.b_idx_2 * -0.0) +
        rtDW.AHRS_Quaternion_idx_3;

      // QUATERNPROD Calculates the quaternion product
      //
      //    ab = quaternProd(a, b)
      //
      //    Calculates the quaternion product of quaternion a and b.
      //
      //    For more information see:
      //    http://www.x-io.co.uk/node/8#quaternions
      //
      // 	Date          Author          Notes
      // 	27/09/2011    SOH Madgwick    Initial release
      // 'quaternProd:13' ab = zeros(size(a));
      // 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); 
      // 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); 
      // 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); 
      // 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); 
      rtDW.h_idx_3 = ((0.0 * rtDW.ab_idx_2 + rtDW.ab_idx_3) - 0.0 *
                      rtDW.ab_idx_1) + 0.0 * rtDW.ab_idx_0;

      // 'MadgwickAHRS:41' b = [0 norm([h(2) h(3)]) 0 h(4)];
      rtDW.b_idx_1 = 2.2250738585072014E-308;
      rtDW.b_idx_2 = std::abs(((0.0 * rtDW.ab_idx_0 + rtDW.ab_idx_1) + 0.0 *
        rtDW.ab_idx_3) - 0.0 * rtDW.ab_idx_2);
      if (rtDW.b_idx_2 > 2.2250738585072014E-308) {
        rtDW.cos_g = 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / 2.2250738585072014E-308;
        rtDW.cos_g = rtDW.c_t * rtDW.c_t;
      }

      rtDW.b_idx_2 = std::abs(((rtDW.ab_idx_2 - 0.0 * rtDW.ab_idx_3) + 0.0 *
        rtDW.ab_idx_0) + 0.0 * rtDW.ab_idx_1);
      if (rtDW.b_idx_2 > rtDW.b_idx_1) {
        rtDW.c_t = rtDW.b_idx_1 / rtDW.b_idx_2;
        rtDW.cos_g = rtDW.cos_g * rtDW.c_t * rtDW.c_t + 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / rtDW.b_idx_1;
        rtDW.cos_g += rtDW.c_t * rtDW.c_t;
      }

      rtDW.cos_g = rtDW.b_idx_1 * std::sqrt(rtDW.cos_g);

      //  Gradient decent algorithm corrective step
      // 'MadgwickAHRS:44' F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
      // 'MadgwickAHRS:45'                 2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2) 
      // 'MadgwickAHRS:46'                 2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3) 
      // 'MadgwickAHRS:47'                 2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3)) - Magnetometer(1) 
      // 'MadgwickAHRS:48'                 2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4)) - Magnetometer(2) 
      // 'MadgwickAHRS:49'                 2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2) - Magnetometer(3)]; 
      // 'MadgwickAHRS:50' J = [-2*q(3),                 	2*q(4),                    -2*q(1),                         2*q(2) 
      // 'MadgwickAHRS:51'                 2*q(2),                 	2*q(1),                    	2*q(4),                         2*q(3) 
      // 'MadgwickAHRS:52'                 0,                         -4*q(2),                    -4*q(3),                         0 
      // 'MadgwickAHRS:53'                 -2*b(4)*q(3),               2*b(4)*q(4),               -4*b(2)*q(3)-2*b(4)*q(1),       -4*b(2)*q(4)+2*b(4)*q(2) 
      // 'MadgwickAHRS:54'                 -2*b(2)*q(4)+2*b(4)*q(2),	2*b(2)*q(3)+2*b(4)*q(1),	2*b(2)*q(2)+2*b(4)*q(4),       -2*b(2)*q(1)+2*b(4)*q(3) 
      // 'MadgwickAHRS:55'                 2*b(2)*q(3),                2*b(2)*q(4)-4*b(4)*q(2),	2*b(2)*q(1)-4*b(4)*q(3),        2*b(2)*q(2)]; 
      // 'MadgwickAHRS:56' step = (J'*F);
      rtDW.dv0[0] = -0.0;
      rtDW.dv0[1] = 0.0;
      rtDW.dv0[2] = -2.0;
      rtDW.dv0[3] = 0.0;
      rtDW.dv0[4] = 0.0;
      rtDW.dv0[5] = 2.0;
      rtDW.dv0[6] = 0.0;
      rtDW.dv0[7] = 0.0;
      rtDW.dv0[8] = 0.0;
      rtDW.dv0[9] = -0.0;
      rtDW.dv0[10] = -0.0;
      rtDW.dv0[11] = 0.0;
      rtDW.dv0[12] = -2.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[13] = 2.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[14] = -4.0 * rtDW.cos_g * 0.0 - 2.0 * rtDW.h_idx_3;
      rtDW.dv0[15] = -4.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[16] = -2.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[17] = 2.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3;
      rtDW.dv0[18] = 2.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[19] = 2.0 * rtDW.h_idx_3 * 0.0 + -2.0 * rtDW.cos_g;
      rtDW.dv0[20] = 2.0 * rtDW.cos_g * 0.0;
      rtDW.dv0[21] = 2.0 * rtDW.cos_g * 0.0 - 4.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[22] = 2.0 * rtDW.cos_g - 4.0 * rtDW.h_idx_3 * 0.0;
      rtDW.dv0[23] = 2.0 * rtDW.cos_g * 0.0;
      rtDW.dv1[0] = 0.0 - rtDW.accelerometer_idx_0;
      rtDW.dv1[1] = 0.0 - rtDW.accelerometer_idx_1;
      rtDW.dv1[2] = 1.0 - rtDW.accelerometer_idx_2;
      rtDW.dv1[3] = (2.0 * rtDW.cos_g * 0.5 + 2.0 * rtDW.h_idx_3 * 0.0) -
        rtDW.magnetometer_idx_0;
      rtDW.dv1[4] = (2.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3 * 0.0) -
        rtDW.magnetometer_idx_1;
      rtDW.dv1[5] = (2.0 * rtDW.cos_g * 0.0 + 2.0 * rtDW.h_idx_3 * 0.5) -
        rtDW.AHRS_Quaternion_idx_3;

      // 'MadgwickAHRS:57' step = step / norm(step);
      rtDW.cos_g = 0.0;
      rtDW.b_idx_1 = 2.2250738585072014E-308;
      for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
        rtDW.step[rtDW.i] = 0.0;
        for (rtDW.i0 = 0; rtDW.i0 < 6; rtDW.i0++) {
          rtDW.step[rtDW.i] += rtDW.dv0[(rtDW.i0 << 2) + rtDW.i] *
            rtDW.dv1[rtDW.i0];
        }

        rtDW.b_idx_2 = std::abs(rtDW.step[rtDW.i]);
        if (rtDW.b_idx_2 > rtDW.b_idx_1) {
          rtDW.c_t = rtDW.b_idx_1 / rtDW.b_idx_2;
          rtDW.cos_g = rtDW.cos_g * rtDW.c_t * rtDW.c_t + 1.0;
          rtDW.b_idx_1 = rtDW.b_idx_2;
        } else {
          rtDW.c_t = rtDW.b_idx_2 / rtDW.b_idx_1;
          rtDW.cos_g += rtDW.c_t * rtDW.c_t;
        }
      }

      rtDW.cos_g = rtDW.b_idx_1 * std::sqrt(rtDW.cos_g);

      //  normalise step magnitude
      //  Compute rate of change of quaternion
      // 'MadgwickAHRS:60' qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; 
      // QUATERNPROD Calculates the quaternion product
      //
      //    ab = quaternProd(a, b)
      //
      //    Calculates the quaternion product of quaternion a and b.
      //
      //    For more information see:
      //    http://www.x-io.co.uk/node/8#quaternions
      //
      // 	Date          Author          Notes
      // 	27/09/2011    SOH Madgwick    Initial release
      // 'quaternProd:13' ab = zeros(size(a));
      // 'quaternProd:14' ab(:,1) = a(:,1).*b(:,1)-a(:,2).*b(:,2)-a(:,3).*b(:,3)-a(:,4).*b(:,4); 
      // 'quaternProd:15' ab(:,2) = a(:,1).*b(:,2)+a(:,2).*b(:,1)+a(:,3).*b(:,4)-a(:,4).*b(:,3); 
      // 'quaternProd:16' ab(:,3) = a(:,1).*b(:,3)-a(:,2).*b(:,4)+a(:,3).*b(:,1)+a(:,4).*b(:,2); 
      // 'quaternProd:17' ab(:,4) = a(:,1).*b(:,4)+a(:,2).*b(:,3)-a(:,3).*b(:,2)+a(:,4).*b(:,1); 
      //  Integrate to yield quaternion
      // 'MadgwickAHRS:63' q = q + qDot * obj.SamplePeriod;
      rtDW.accelerometer_idx_2 = ((((0.0 - 0.0 * rtDW.y_idx_0) - 0.0 *
        rtDW.y_idx_1) - 0.0 * rtDW.y_idx_2) * 0.5 - rtDW.step[0] / rtDW.cos_g *
        0.1) * 0.00390625 + 1.0;
      rtDW.accelerometer_idx_1 = (((0.0 * rtDW.y_idx_2 + rtDW.y_idx_0) - 0.0 *
        rtDW.y_idx_1) * 0.5 - rtDW.step[1] / rtDW.cos_g * 0.1) * 0.00390625;
      rtDW.accelerometer_idx_0 = (((rtDW.y_idx_1 - 0.0 * rtDW.y_idx_2) + 0.0 *
        rtDW.y_idx_0) * 0.5 - rtDW.step[2] / rtDW.cos_g * 0.1) * 0.00390625;
      rtDW.y_idx_0 = (((0.0 * rtDW.y_idx_1 + rtDW.y_idx_2) - 0.0 * rtDW.y_idx_0)
                      * 0.5 - rtDW.step[3] / rtDW.cos_g * 0.1) * 0.00390625;

      // 'MadgwickAHRS:64' obj.Quaternion = q / norm(q);
      rtDW.b_idx_1 = 2.2250738585072014E-308;
      rtDW.b_idx_2 = std::abs(rtDW.accelerometer_idx_2);
      if (rtDW.b_idx_2 > 2.2250738585072014E-308) {
        rtDW.cos_g = 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / 2.2250738585072014E-308;
        rtDW.cos_g = rtDW.c_t * rtDW.c_t;
      }

      rtDW.b_idx_2 = std::abs(rtDW.accelerometer_idx_1);
      if (rtDW.b_idx_2 > rtDW.b_idx_1) {
        rtDW.c_t = rtDW.b_idx_1 / rtDW.b_idx_2;
        rtDW.cos_g = rtDW.cos_g * rtDW.c_t * rtDW.c_t + 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / rtDW.b_idx_1;
        rtDW.cos_g += rtDW.c_t * rtDW.c_t;
      }

      rtDW.b_idx_2 = std::abs(rtDW.accelerometer_idx_0);
      if (rtDW.b_idx_2 > rtDW.b_idx_1) {
        rtDW.c_t = rtDW.b_idx_1 / rtDW.b_idx_2;
        rtDW.cos_g = rtDW.cos_g * rtDW.c_t * rtDW.c_t + 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / rtDW.b_idx_1;
        rtDW.cos_g += rtDW.c_t * rtDW.c_t;
      }

      rtDW.b_idx_2 = std::abs(rtDW.y_idx_0);
      if (rtDW.b_idx_2 > rtDW.b_idx_1) {
        rtDW.c_t = rtDW.b_idx_1 / rtDW.b_idx_2;
        rtDW.cos_g = rtDW.cos_g * rtDW.c_t * rtDW.c_t + 1.0;
        rtDW.b_idx_1 = rtDW.b_idx_2;
      } else {
        rtDW.c_t = rtDW.b_idx_2 / rtDW.b_idx_1;
        rtDW.cos_g += rtDW.c_t * rtDW.c_t;
      }

      rtDW.cos_g = rtDW.b_idx_1 * std::sqrt(rtDW.cos_g);
      rtDW.b_idx_1 = rtDW.accelerometer_idx_2 / rtDW.cos_g;
      rtDW.b_idx_2 = rtDW.accelerometer_idx_1 / rtDW.cos_g;
      rtDW.c_t = rtDW.accelerometer_idx_0 / rtDW.cos_g;
      rtDW.AHRS_Quaternion_idx_3 = rtDW.y_idx_0 / rtDW.cos_g;

      //  normalise quaternion
    }
  }

  //  gyroscope units must be radians
  // '<S19>:1:12' quaternion = AHRS.Quaternion;
  // '<S19>:1:14' euler = quatern2euler(quaternConj(quaternion));
  // QUATERN2ROTMAT Converts a quaternion to its conjugate
  //
  //    qConj = quaternConj(q)
  //
  //    Converts a quaternion to its conjugate.
  //
  //    For more information see:
  //    http://www.x-io.co.uk/node/8#quaternions
  //
  // 	Date          Author          Notes
  // 	27/09/2011    SOH Madgwick    Initial release
  // 'quaternConj:14' qConj = [q(:,1) -q(:,2) -q(:,3) -q(:,4)];
  // QUATERN2EULER Converts a quaternion orientation to ZYX Euler angles
  //
  //    q = quatern2euler(q)
  //
  //    Converts a quaternion orientation to ZYX Euler angles where phi is a
  //    rotation around X, theta around Y and psi around Z.
  //
  //    For more information see:
  //    http://www.x-io.co.uk/node/8#quaternions
  //
  // 	Date          Author          Notes
  // 	27/09/2011    SOH Madgwick    Initial release
  // 'quatern2euler:14' R = zeros(3,3,(size(q,1)));
  // 'quatern2euler:15' R(1,1,:) = 2.*q(:,1).^2-1+2.*q(:,2).^2;
  rtDW.R[0] = (rtDW.b_idx_1 * rtDW.b_idx_1 * 2.0 - 1.0) + -rtDW.b_idx_2 *
    -rtDW.b_idx_2 * 2.0;

  // 'quatern2euler:16' R(2,1,:) = 2.*(q(:,2).*q(:,3)-q(:,1).*q(:,4));
  rtDW.R[1] = (-rtDW.b_idx_2 * -rtDW.c_t - rtDW.b_idx_1 *
               -rtDW.AHRS_Quaternion_idx_3) * 2.0;

  // 'quatern2euler:17' R(3,1,:) = 2.*(q(:,2).*q(:,4)+q(:,1).*q(:,3));
  rtDW.R[2] = (-rtDW.b_idx_2 * -rtDW.AHRS_Quaternion_idx_3 + rtDW.b_idx_1 *
               -rtDW.c_t) * 2.0;

  // 'quatern2euler:18' R(3,2,:) = 2.*(q(:,3).*q(:,4)-q(:,1).*q(:,2));
  rtDW.R[5] = (-rtDW.c_t * -rtDW.AHRS_Quaternion_idx_3 - rtDW.b_idx_1 *
               -rtDW.b_idx_2) * 2.0;

  // 'quatern2euler:19' R(3,3,:) = 2.*q(:,1).^2-1+2.*q(:,4).^2;
  rtDW.R[8] = (rtDW.b_idx_1 * rtDW.b_idx_1 * 2.0 - 1.0) +
    -rtDW.AHRS_Quaternion_idx_3 * -rtDW.AHRS_Quaternion_idx_3 * 2.0;

  // 'quatern2euler:21' phi = atan2(R(3,2,:), R(3,3,:) );
  // 'quatern2euler:22' theta = -atan(R(3,1,:) ./ sqrt(1-R(3,1,:).^2) );
  // 'quatern2euler:23' psi = atan2(R(2,1,:), R(1,1,:) );
  // 'quatern2euler:25' euler = [phi(1,:)' theta(1,:)' psi(1,:)'];
  rtDW.accelerometer_idx_0 = rt_atan2d_snf(rtDW.R[5], rtDW.R[8]);
  rtDW.accelerometer_idx_1 = -std::atan(rtDW.R[2] / std::sqrt(1.0 - rtDW.R[2] *
    rtDW.R[2]));
  rtDW.accelerometer_idx_2 = rt_atan2d_snf(rtDW.R[1], rtDW.R[0]);

  // FunctionCaller: '<S3>/Function Caller'
  //  use conjugate for sensor frame relative to Earth. Unit is rad.
  // '<S19>:1:15' Z = euler(1,1);
  // '<S19>:1:16' Y = euler(1,2);
  // '<S19>:1:17' X = euler(1,3);
  //  function obj = MadgwickAHRS(varargin)
  //      for i = 1:2:nargin
  //          if  strcmp(varargin{i}, 'SamplePeriod'), obj.SamplePeriod = varargin{i+1}; 
  //          elseif  strcmp(varargin{i}, 'Quaternion'), obj.Quaternion = varargin{i+1}; 
  //          elseif  strcmp(varargin{i}, 'Beta'), obj.Beta = varargin{i+1};
  //          else error('Invalid argument');
  //          end
  //      end;
  //  end
  //  function obj = Update(obj, Gyroscope, Accelerometer, Magnetometer)
  //      q = obj.Quaternion; % short name local variable for readability
  //
  //      % Normalise accelerometer measurement
  //      if(norm(Accelerometer) == 0), return; end	% handle NaN
  //      Accelerometer = Accelerometer / norm(Accelerometer);	% normalise magnitude 
  //
  //      % Normalise magnetometer measurement
  //      if(norm(Magnetometer) == 0), return; end	% handle NaN
  //      Magnetometer = Magnetometer / norm(Magnetometer);	% normalise magnitude 
  //
  //      % Reference direction of Earth's magnetic feild
  //      h = quaternProd(q, quaternProd([0 Magnetometer], quaternConj(q)));
  //      b = [0 norm([h(2) h(3)]) 0 h(4)];
  //
  //      % Gradient decent algorithm corrective step
  //      F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
  //          2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2)
  //          2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)
  //          2*b(2)*(0.5 - q(3)^2 - q(4)^2) + 2*b(4)*(q(2)*q(4) - q(1)*q(3)) - Magnetometer(1) 
  //          2*b(2)*(q(2)*q(3) - q(1)*q(4)) + 2*b(4)*(q(1)*q(2) + q(3)*q(4)) - Magnetometer(2) 
  //          2*b(2)*(q(1)*q(3) + q(2)*q(4)) + 2*b(4)*(0.5 - q(2)^2 - q(3)^2) - Magnetometer(3)]; 
  //      J = [-2*q(3),                 	2*q(4),                    -2*q(1),                         2*q(2) 
  //          2*q(2),                 	2*q(1),                    	2*q(4),                         2*q(3) 
  //          0,                         -4*q(2),                    -4*q(3),                         0 
  //          -2*b(4)*q(3),               2*b(4)*q(4),               -4*b(2)*q(3)-2*b(4)*q(1),       -4*b(2)*q(4)+2*b(4)*q(2) 
  //          -2*b(2)*q(4)+2*b(4)*q(2),	2*b(2)*q(3)+2*b(4)*q(1),	2*b(2)*q(2)+2*b(4)*q(4),       -2*b(2)*q(1)+2*b(4)*q(3) 
  //          2*b(2)*q(3),                2*b(2)*q(4)-4*b(4)*q(2),	2*b(2)*q(1)-4*b(4)*q(3),        2*b(2)*q(2)]; 
  //      step = (J'*F);
  //      step = step / norm(step);	% normalise step magnitude
  //
  //      % Compute rate of change of quaternion
  //      qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; 
  //
  //      % Integrate to yield quaternion
  //      q = q + qDot * obj.SamplePeriod;
  //      obj.Quaternion = q / norm(q); % normalise quaternion
  //  end
  //
  //  function obj = UpdateIMU(obj, Gyroscope, Accelerometer)
  //      q = obj.Quaternion; % short name local variable for readability
  //
  //      % Normalise accelerometer measurement
  //      if(norm(Accelerometer) == 0), return; end	% handle NaN
  //      Accelerometer = Accelerometer / norm(Accelerometer);	% normalise magnitude 
  //
  //      % Gradient decent algorithm corrective step
  //      F = [2*(q(2)*q(4) - q(1)*q(3)) - Accelerometer(1)
  //          2*(q(1)*q(2) + q(3)*q(4)) - Accelerometer(2)
  //          2*(0.5 - q(2)^2 - q(3)^2) - Accelerometer(3)];
  //      J = [-2*q(3),	2*q(4),    -2*q(1),	2*q(2)
  //          2*q(2),     2*q(1),     2*q(4),	2*q(3)
  //          0,         -4*q(2),    -4*q(3),	0    ];
  //      step = (J'*F);
  //      step = step / norm(step);	% normalise step magnitude
  //
  //      % Compute rate of change of quaternion
  //      qDot = 0.5 * quaternProd(q, [0 Gyroscope(1) Gyroscope(2) Gyroscope(3)]) - obj.Beta * step'; 
  //
  //      % Integrate to yield quaternion
  //      q = q + qDot * obj.SamplePeriod;
  //      obj.Quaternion = q / norm(q); % normalise quaternion
  //  end
  measurementDroneFcn_o(rtDW.UnitDelay, rtDW.FunctionCaller);

  // Trigonometry: '<S8>/cos'
  rtDW.cos_g = std::cos(rtDW.UnitDelay[10]);

  // Sum: '<S8>/Add1' incorporates:
  //   Gain: '<S8>/Kd1'
  //   Gain: '<S8>/Kp1'
  //   Inport: '<Root>/x_desired'
  //   Sum: '<S8>/Add'

  rtDW.b_idx_1 = (rtU.x_desired[0] - rtDW.UnitDelay[0]) * 5.0 - 10.0 *
    rtDW.UnitDelay[3];

  // Trigonometry: '<S8>/sin'
  rtDW.b_idx_2 = std::sin(rtDW.UnitDelay[10]);

  // Sum: '<S8>/Add2' incorporates:
  //   Gain: '<S8>/Kd2'
  //   Gain: '<S8>/Kp2'
  //   Inport: '<Root>/x_desired'
  //   Sum: '<S8>/Add'

  rtDW.c_t = (rtU.x_desired[1] - rtDW.UnitDelay[1]) * 5.0 - 10.0 *
    rtDW.UnitDelay[4];

  // Sum: '<S8>/Add6' incorporates:
  //   Product: '<S8>/Product'
  //   Product: '<S8>/Product3'

  rtDW.Add6 = rtDW.cos_g * rtDW.b_idx_1 + rtDW.b_idx_2 * rtDW.c_t;

  // Sum: '<S8>/Add5' incorporates:
  //   Product: '<S8>/Product1'
  //   Product: '<S8>/Product2'

  rtDW.Add5 = rtDW.b_idx_2 * rtDW.b_idx_1 - rtDW.cos_g * rtDW.c_t;

  // Sum: '<S8>/Add4' incorporates:
  //   Gain: '<S8>/Kd4'
  //   Gain: '<S8>/Kp4'
  //   Inport: '<Root>/x_desired'
  //   Sum: '<S8>/Add'

  rtDW.Add4 = (rtU.x_desired[3] - rtDW.UnitDelay[10]) * 5.0 - 10.0 *
    rtDW.UnitDelay[11];

  // Sum: '<S8>/Add3' incorporates:
  //   Gain: '<S8>/Kd3'
  //   Gain: '<S8>/Kp3'
  //   Inport: '<Root>/x_desired'
  //   Sum: '<S8>/Add'

  rtDW.Add3 = (rtU.x_desired[2] - rtDW.UnitDelay[2]) * 5.0 - 10.0 *
    rtDW.UnitDelay[5];

  // Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter'
  // Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Inport: '<Root>/enableTWB'
  if (rtU.enableTWB) {
    // MATLAB Function: '<S10>/Correct' incorporates:
    //   Constant: '<S2>/R1'
    //   DataStoreRead: '<S10>/Data Store ReadP'
    //   DataStoreRead: '<S10>/Data Store ReadX'
    //   DataStoreWrite: '<S10>/Data Store WriteP'
    //   Sum: '<S4>/Add'

    // MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S14>:1'
    // '<S14>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName));
    // '<S14>:1:3' if pM.HasJacobian
    // '<S14>:1:7' xNew = zeros(size(x),'like',x);
    // '<S14>:1:8' PNew = zeros(size(P),'like',x);
    // '<S14>:1:9' if pM.HasAdditiveNoise
    // '<S14>:1:10' if pM.HasJacobian
    // '<S14>:1:13' else
    // '<S14>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... 
    // '<S14>:1:15'             yMeas,R,x,P,@(xx)MeasurementFcn(xx),[]);
    measurementTWBFcn_h(rtDW.x, rtDW.b_z_f);
    for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
      memcpy(&rtDW.imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
      rtDW.cos_g = 1.4901161193847656E-8 * std::abs(rtDW.x[rtDW.i]);
      if ((1.4901161193847656E-8 > rtDW.cos_g) || rtIsNaN(rtDW.cos_g)) {
        rtDW.cos_g = 1.4901161193847656E-8;
      }

      rtDW.imvec[rtDW.i] = rtDW.x[rtDW.i] + rtDW.cos_g;
      measurementTWBFcn_h(rtDW.imvec, rtDW.imz_g);
      rtDW.dHdx_k[3 * rtDW.i] = (rtDW.imz_g[0] - rtDW.b_z_f[0]) / rtDW.cos_g;
      rtDW.dHdx_k[1 + 3 * rtDW.i] = (rtDW.imz_g[1] - rtDW.b_z_f[1]) / rtDW.cos_g;
      rtDW.dHdx_k[2 + 3 * rtDW.i] = (rtDW.imz_g[2] - rtDW.b_z_f[2]) / rtDW.cos_g;
    }

    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      for (rtDW.i1 = 0; rtDW.i1 < 3; rtDW.i1++) {
        rtDW.Pxy[rtDW.i0 + 12 * rtDW.i1] = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.Pxy[rtDW.i0 + 12 * rtDW.i1] += rtDW.P_j[12 * rtDW.i + rtDW.i0] *
            rtDW.dHdx_k[3 * rtDW.i + rtDW.i1];
        }
      }
    }

    for (rtDW.i0 = 0; rtDW.i0 < 3; rtDW.i0++) {
      for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
        rtDW.gain_c[rtDW.i0 + 3 * rtDW.i1] = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.gain_c[rtDW.i0 + 3 * rtDW.i1] += rtDW.dHdx_k[3 * rtDW.i + rtDW.i0]
            * rtDW.P_j[12 * rtDW.i1 + rtDW.i];
        }
      }

      for (rtDW.i1 = 0; rtDW.i1 < 3; rtDW.i1++) {
        rtDW.cos_g = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.cos_g += rtDW.gain_c[3 * rtDW.i + rtDW.i0] * rtDW.dHdx_k[3 *
            rtDW.i + rtDW.i1];
        }

        rtDW.R[rtDW.i0 + 3 * rtDW.i1] = rtCP_R1_Value[3 * rtDW.i1 + rtDW.i0] +
          rtDW.cos_g;
      }
    }

    measurementTWBFcn_h(rtDW.x, rtDW.b_z_f);
    rtDW.i = 0;
    rtDW.r2 = 1;
    rtDW.r3 = 2;
    rtDW.cos_g = std::abs(rtDW.R[0]);
    rtDW.b_idx_1 = std::abs(rtDW.R[1]);
    if (rtDW.b_idx_1 > rtDW.cos_g) {
      rtDW.cos_g = rtDW.b_idx_1;
      rtDW.i = 1;
      rtDW.r2 = 0;
    }

    if (std::abs(rtDW.R[2]) > rtDW.cos_g) {
      rtDW.i = 2;
      rtDW.r2 = 1;
      rtDW.r3 = 0;
    }

    rtDW.R[rtDW.r2] /= rtDW.R[rtDW.i];
    rtDW.R[rtDW.r3] /= rtDW.R[rtDW.i];
    rtDW.R[3 + rtDW.r2] -= rtDW.R[3 + rtDW.i] * rtDW.R[rtDW.r2];
    rtDW.R[3 + rtDW.r3] -= rtDW.R[3 + rtDW.i] * rtDW.R[rtDW.r3];
    rtDW.R[6 + rtDW.r2] -= rtDW.R[6 + rtDW.i] * rtDW.R[rtDW.r2];
    rtDW.R[6 + rtDW.r3] -= rtDW.R[6 + rtDW.i] * rtDW.R[rtDW.r3];
    if (std::abs(rtDW.R[3 + rtDW.r3]) > std::abs(rtDW.R[3 + rtDW.r2])) {
      rtDW.rtemp = rtDW.r2;
      rtDW.r2 = rtDW.r3;
      rtDW.r3 = rtDW.rtemp;
    }

    rtDW.R[3 + rtDW.r3] /= rtDW.R[3 + rtDW.r2];
    rtDW.R[6 + rtDW.r3] -= rtDW.R[3 + rtDW.r3] * rtDW.R[6 + rtDW.r2];
    for (rtDW.rtemp = 0; rtDW.rtemp < 12; rtDW.rtemp++) {
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.i] = rtDW.Pxy[rtDW.rtemp] /
        rtDW.R[rtDW.i];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r2] = rtDW.Pxy[12 + rtDW.rtemp] -
        rtDW.gain_c[12 * rtDW.i + rtDW.rtemp] * rtDW.R[3 + rtDW.i];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r3] = rtDW.Pxy[24 + rtDW.rtemp] -
        rtDW.gain_c[12 * rtDW.i + rtDW.rtemp] * rtDW.R[6 + rtDW.i];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r2] /= rtDW.R[3 + rtDW.r2];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r3] -= rtDW.gain_c[12 * rtDW.r2 +
        rtDW.rtemp] * rtDW.R[6 + rtDW.r2];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r3] /= rtDW.R[6 + rtDW.r3];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.r2] -= rtDW.gain_c[12 * rtDW.r3 +
        rtDW.rtemp] * rtDW.R[3 + rtDW.r3];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.i] -= rtDW.gain_c[12 * rtDW.r3 +
        rtDW.rtemp] * rtDW.R[rtDW.r3];
      rtDW.gain_c[rtDW.rtemp + 12 * rtDW.i] -= rtDW.gain_c[12 * rtDW.r2 +
        rtDW.rtemp] * rtDW.R[rtDW.r2];
      for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
        rtDW.Jacobian[rtDW.rtemp + 12 * rtDW.i0] = 0.0;
        rtDW.Jacobian[rtDW.rtemp + 12 * rtDW.i0] += rtDW.dHdx_k[3 * rtDW.i0] *
          rtDW.gain_c[rtDW.rtemp];
        rtDW.Jacobian[rtDW.rtemp + 12 * rtDW.i0] += rtDW.dHdx_k[3 * rtDW.i0 + 1]
          * rtDW.gain_c[rtDW.rtemp + 12];
        rtDW.Jacobian[rtDW.rtemp + 12 * rtDW.i0] += rtDW.dHdx_k[3 * rtDW.i0 + 2]
          * rtDW.gain_c[rtDW.rtemp + 24];
      }

      for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
        rtDW.cos_g = 0.0;
        for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
          rtDW.cos_g += rtDW.Jacobian[12 * rtDW.i1 + rtDW.rtemp] * rtDW.P_j[12 *
            rtDW.i0 + rtDW.i1];
        }

        rtDW.Jacobian_m[rtDW.rtemp + 12 * rtDW.i0] = rtDW.P_j[12 * rtDW.i0 +
          rtDW.rtemp] - rtDW.cos_g;
      }
    }

    rtDW.rtb_TWB_gain_idx_0 -= rtDW.b_z_f[0];
    rtDW.rtb_TWB_gain_idx_1 -= rtDW.b_z_f[1];
    rtDW.rtb_TWB_gain_idx_2 = (rtDW.rtb_TWB_gain_idx_2 - rtDW.UnitDelay_f[2]) -
      rtDW.b_z_f[2];
    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      // DataStoreWrite: '<S10>/Data Store WriteP' incorporates:
      //   MATLAB Function: '<S10>/Correct'

      memcpy(&rtDW.P_j[rtDW.i0 * 12], &rtDW.Jacobian_m[rtDW.i0 * 12], 12U *
             sizeof(real_T));

      // DataStoreWrite: '<S10>/Data Store WriteX' incorporates:
      //   DataStoreRead: '<S10>/Data Store ReadX'
      //   MATLAB Function: '<S10>/Correct'

      rtDW.x[rtDW.i0] += (rtDW.gain_c[rtDW.i0 + 12] * rtDW.rtb_TWB_gain_idx_1 +
                          rtDW.gain_c[rtDW.i0] * rtDW.rtb_TWB_gain_idx_0) +
        rtDW.gain_c[rtDW.i0 + 24] * rtDW.rtb_TWB_gain_idx_2;
    }
  }

  // End of Inport: '<Root>/enableTWB'
  // End of Outputs for SubSystem: '<S2>/Correct1'

  // Outputs for Enabled SubSystem: '<S2>/Correct2' incorporates:
  //   EnablePort: '<S11>/Enable'

  // Inport: '<Root>/enableDrone'
  if (rtU.enableDrone) {
    // MATLAB Function: '<S11>/Correct' incorporates:
    //   Constant: '<S2>/R2'
    //   DataStoreRead: '<S11>/Data Store ReadP'
    //   DataStoreRead: '<S11>/Data Store ReadX'
    //   DataStoreWrite: '<S11>/Data Store WriteP'

    // MATLAB Function 'Extras/EKFCorrect_SLFcn_0Input/Correct': '<S15>:1'
    // '<S15>:1:2' MeasurementFcn = coder.const(str2func(pM.FcnName));
    // '<S15>:1:3' if pM.HasJacobian
    // '<S15>:1:7' xNew = zeros(size(x),'like',x);
    // '<S15>:1:8' PNew = zeros(size(P),'like',x);
    // '<S15>:1:9' if pM.HasAdditiveNoise
    // '<S15>:1:10' if pM.HasJacobian
    // '<S15>:1:13' else
    // '<S15>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFCorrectorAdditive.correct(... 
    // '<S15>:1:15'             yMeas,R,x,P,@(xx)MeasurementFcn(xx),[]);
    measurementDroneFcn_o(rtDW.x, rtDW.b_z);
    for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
      memcpy(&rtDW.imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
      rtDW.cos_g = 1.4901161193847656E-8 * std::abs(rtDW.x[rtDW.i]);
      if ((1.4901161193847656E-8 > rtDW.cos_g) || rtIsNaN(rtDW.cos_g)) {
        rtDW.cos_g = 1.4901161193847656E-8;
      }

      rtDW.imvec[rtDW.i] = rtDW.x[rtDW.i] + rtDW.cos_g;
      measurementDroneFcn_o(rtDW.imvec, rtDW.imz_p);
      for (rtDW.i0 = 0; rtDW.i0 < 5; rtDW.i0++) {
        rtDW.dHdx[rtDW.i0 + 5 * rtDW.i] = (rtDW.imz_p[rtDW.i0] -
          rtDW.b_z[rtDW.i0]) / rtDW.cos_g;
      }
    }

    measurementDroneFcn_o(rtDW.x, rtDW.b_z);
    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      for (rtDW.i1 = 0; rtDW.i1 < 5; rtDW.i1++) {
        rtDW.gain[rtDW.i0 + 12 * rtDW.i1] = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.gain[rtDW.i0 + 12 * rtDW.i1] += rtDW.P_j[12 * rtDW.i + rtDW.i0] *
            rtDW.dHdx[5 * rtDW.i + rtDW.i1];
        }
      }
    }

    for (rtDW.i0 = 0; rtDW.i0 < 5; rtDW.i0++) {
      for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
        rtDW.dHdx_c[rtDW.i0 + 5 * rtDW.i1] = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.dHdx_c[rtDW.i0 + 5 * rtDW.i1] += rtDW.dHdx[5 * rtDW.i + rtDW.i0] *
            rtDW.P_j[12 * rtDW.i1 + rtDW.i];
        }
      }

      for (rtDW.i1 = 0; rtDW.i1 < 5; rtDW.i1++) {
        rtDW.cos_g = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.cos_g += rtDW.dHdx_c[5 * rtDW.i + rtDW.i0] * rtDW.dHdx[5 * rtDW.i
            + rtDW.i1];
        }

        rtDW.dHdx_b[rtDW.i0 + 5 * rtDW.i1] = rtCP_R2_Value[5 * rtDW.i1 + rtDW.i0]
          + rtDW.cos_g;
      }
    }

    iecjgdjeaimokfcj_mrdivide(rtDW.gain, rtDW.dHdx_b);
    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
        rtDW.Jacobian[rtDW.i0 + 12 * rtDW.i1] = 0.0;
        for (rtDW.i = 0; rtDW.i < 5; rtDW.i++) {
          rtDW.Jacobian[rtDW.i0 + 12 * rtDW.i1] += rtDW.gain[12 * rtDW.i +
            rtDW.i0] * rtDW.dHdx[5 * rtDW.i1 + rtDW.i];
        }
      }

      for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
        rtDW.cos_g = 0.0;
        for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
          rtDW.cos_g += rtDW.Jacobian[12 * rtDW.i + rtDW.i0] * rtDW.P_j[12 *
            rtDW.i1 + rtDW.i];
        }

        rtDW.Jacobian_m[rtDW.i0 + 12 * rtDW.i1] = rtDW.P_j[12 * rtDW.i1 +
          rtDW.i0] - rtDW.cos_g;
      }
    }

    // DataStoreWrite: '<S11>/Data Store WriteP' incorporates:
    //   MATLAB Function: '<S11>/Correct'

    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      memcpy(&rtDW.P_j[rtDW.i0 * 12], &rtDW.Jacobian_m[rtDW.i0 * 12], 12U *
             sizeof(real_T));
    }

    // Sum: '<S3>/Add' incorporates:
    //   MATLAB Function: '<S9>/MATLAB Function'

    rtDW.imz_p[0] = rtDW.UnitDelay_f[0];
    rtDW.imz_p[1] = rtDW.UnitDelay_f[1];
    rtDW.imz_p[2] = rtDW.accelerometer_idx_0;
    rtDW.imz_p[3] = rtDW.accelerometer_idx_1;
    rtDW.imz_p[4] = rtDW.accelerometer_idx_2;

    // MATLAB Function: '<S11>/Correct' incorporates:
    //   Sum: '<S3>/Add'

    for (rtDW.i0 = 0; rtDW.i0 < 5; rtDW.i0++) {
      rtDW.rtb_UnitDelay_f_c[rtDW.i0] = (rtDW.imz_p[rtDW.i0] -
        rtDW.FunctionCaller[rtDW.i0]) - rtDW.b_z[rtDW.i0];
    }

    // DataStoreWrite: '<S11>/Data Store WriteX' incorporates:
    //   DataStoreRead: '<S11>/Data Store ReadX'
    //   MATLAB Function: '<S11>/Correct'

    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      rtDW.cos_g = 0.0;
      for (rtDW.i1 = 0; rtDW.i1 < 5; rtDW.i1++) {
        rtDW.cos_g += rtDW.gain[12 * rtDW.i1 + rtDW.i0] *
          rtDW.rtb_UnitDelay_f_c[rtDW.i1];
      }

      rtDW.x[rtDW.i0] += rtDW.cos_g;
    }

    // End of DataStoreWrite: '<S11>/Data Store WriteX'
  }

  // End of Inport: '<Root>/enableDrone'
  // End of Outputs for SubSystem: '<S2>/Correct2'

  // Outputs for Atomic SubSystem: '<S2>/Output'
  // DataStoreRead: '<S12>/Data Store Read'
  memcpy(&rtDW.UnitDelay[0], &rtDW.x[0], 12U * sizeof(real_T));

  // End of Outputs for SubSystem: '<S2>/Output'

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // MATLAB Function: '<S13>/Predict' incorporates:
  //   DataStoreRead: '<S13>/Data Store ReadP'
  //   DataStoreRead: '<S13>/Data Store ReadX'

  // MATLAB Function 'Extras/EKFPredict_SLFcn_0Input/Predict': '<S16>:1'
  // '<S16>:1:2' StateTransitionFcn = coder.const(str2func(pS.FcnName));
  // '<S16>:1:3' if pS.HasJacobian
  // '<S16>:1:7' xNew = zeros(size(x),'like',x);
  // '<S16>:1:8' PNew = zeros(size(P),'like',x);
  // '<S16>:1:9' if pS.HasAdditiveNoise
  // '<S16>:1:10' if pS.HasJacobian
  // '<S16>:1:13' else
  // '<S16>:1:14' [xNew,PNew] = matlabshared.tracking.internal.EKFPredictorAdditive.predict(... 
  // '<S16>:1:15'             Q,x,P,@(xx)StateTransitionFcn(xx), []);
  stateTransitionFcn(rtDW.x, rtDW.z);
  for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
    memcpy(&rtDW.imvec[0], &rtDW.x[0], 12U * sizeof(real_T));
    rtDW.cos_g = 1.4901161193847656E-8 * std::abs(rtDW.x[rtDW.i]);
    if ((1.4901161193847656E-8 > rtDW.cos_g) || rtIsNaN(rtDW.cos_g)) {
      rtDW.cos_g = 1.4901161193847656E-8;
    }

    rtDW.imvec[rtDW.i] = rtDW.x[rtDW.i] + rtDW.cos_g;
    stateTransitionFcn(rtDW.imvec, rtDW.imz);
    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      rtDW.Jacobian[rtDW.i0 + 12 * rtDW.i] = (rtDW.imz[rtDW.i0] - rtDW.z[rtDW.i0])
        / rtDW.cos_g;
    }
  }

  stateTransitionFcn(rtDW.x, rtDW.imvec);
  for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
    for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
      rtDW.Jacobian_m[rtDW.i1 + 12 * rtDW.i0] = 0.0;
      for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
        rtDW.Jacobian_m[rtDW.i1 + 12 * rtDW.i0] += rtDW.Jacobian[12 * rtDW.i +
          rtDW.i1] * rtDW.P_j[12 * rtDW.i0 + rtDW.i];
      }
    }
  }

  // End of Outputs for SubSystem: '<S2>/Predict'
  // End of Outputs for SubSystem: '<S1>/Extended Kalman Filter'

  // Bias: '<S1>/Bias' incorporates:
  //   Gain: '<S1>/Gain8'
  printf("V: %i\n", rtDW.Add3);
  rtDW.rtb_TWB_gain_idx_0 = 10.0 * rtDW.Add3 + 1500.0;
  printf("N: %i\n", rtDW.rtb_TWB_gain_idx_0);

  // Saturate: '<S1>/Saturation'
  if (rtDW.rtb_TWB_gain_idx_0 > 3000.0) {
    // Outport: '<Root>/u'
    rtY.u[0] = 3000.0;
  } else if (rtDW.rtb_TWB_gain_idx_0 < 0.0) {
    // Outport: '<Root>/u'
    rtY.u[0] = 0.0;
  } else {
    // Outport: '<Root>/u'
    rtY.u[0] = rtDW.rtb_TWB_gain_idx_0;
  }
  printf("u: %i\n", rtY.u[0]);
  // Bias: '<S1>/Bias' incorporates:
  //   Gain: '<S1>/Gain8'

  rtDW.rtb_TWB_gain_idx_0 = 30.0 * rtDW.Add4 + 1500.0;

  // Saturate: '<S1>/Saturation'
  if (rtDW.rtb_TWB_gain_idx_0 > 3000.0) {
    // Outport: '<Root>/u'
    rtY.u[1] = 3000.0;
  } else if (rtDW.rtb_TWB_gain_idx_0 < 0.0) {
    // Outport: '<Root>/u'
    rtY.u[1] = 0.0;
  } else {
    // Outport: '<Root>/u'
    rtY.u[1] = rtDW.rtb_TWB_gain_idx_0;
  }

  // Bias: '<S1>/Bias' incorporates:
  //   Gain: '<S1>/Gain8'

  rtDW.rtb_TWB_gain_idx_0 = 30.0 * rtDW.Add5 + 1500.0;

  // Saturate: '<S1>/Saturation'
  if (rtDW.rtb_TWB_gain_idx_0 > 3000.0) {
    // Outport: '<Root>/u'
    rtY.u[2] = 3000.0;
  } else if (rtDW.rtb_TWB_gain_idx_0 < 0.0) {
    // Outport: '<Root>/u'
    rtY.u[2] = 0.0;
  } else {
    // Outport: '<Root>/u'
    rtY.u[2] = rtDW.rtb_TWB_gain_idx_0;
  }

  // Bias: '<S1>/Bias' incorporates:
  //   Gain: '<S1>/Gain8'

  rtDW.rtb_TWB_gain_idx_0 = 30.0 * rtDW.Add6 + 1500.0;

  // Saturate: '<S1>/Saturation'
  if (rtDW.rtb_TWB_gain_idx_0 > 3000.0) {
    // Outport: '<Root>/u'
    rtY.u[3] = 3000.0;
  } else if (rtDW.rtb_TWB_gain_idx_0 < 0.0) {
    // Outport: '<Root>/u'
    rtY.u[3] = 0.0;
  } else {
    // Outport: '<Root>/u'
    rtY.u[3] = rtDW.rtb_TWB_gain_idx_0;
  }

  // Outputs for Atomic SubSystem: '<S1>/Extended Kalman Filter'
  // Outputs for Atomic SubSystem: '<S2>/Predict'
  for (rtDW.i = 0; rtDW.i < 12; rtDW.i++) {
    // DataStoreWrite: '<S13>/Data Store WriteP' incorporates:
    //   Constant: '<S2>/Q'
    //   MATLAB Function: '<S13>/Predict'

    for (rtDW.i0 = 0; rtDW.i0 < 12; rtDW.i0++) {
      rtDW.cos_g = 0.0;
      for (rtDW.i1 = 0; rtDW.i1 < 12; rtDW.i1++) {
        rtDW.cos_g += rtDW.Jacobian_m[12 * rtDW.i1 + rtDW.i] * rtDW.Jacobian[12 *
          rtDW.i1 + rtDW.i0];
      }

      rtDW.P_j[rtDW.i + 12 * rtDW.i0] = rtCP_Q_Value[12 * rtDW.i0 + rtDW.i] +
        rtDW.cos_g;
    }

    // End of DataStoreWrite: '<S13>/Data Store WriteP'

    // DataStoreWrite: '<S13>/Data Store WriteX' incorporates:
    //   MATLAB Function: '<S13>/Predict'

    rtDW.x[rtDW.i] = rtDW.imvec[rtDW.i];

    // Outport: '<Root>/x'
    rtY.x[rtDW.i] = rtDW.UnitDelay[rtDW.i];

    // Update for UnitDelay: '<S1>/Unit Delay'
    rtDW.UnitDelay_DSTATE[rtDW.i] = rtDW.UnitDelay[rtDW.i];
  }

  // End of Outputs for SubSystem: '<S2>/Predict'
  // End of Outputs for SubSystem: '<S1>/Extended Kalman Filter'

  // Update for UnitDelay: '<S9>/Unit Delay'
  rtDW.UnitDelay_DSTATE_b[0] = rtDW.rtb_acc_scale_idx_0;
  rtDW.UnitDelay_DSTATE_b[1] = rtDW.rtb_acc_scale_idx_1;
  rtDW.UnitDelay_DSTATE_b[2] = rtDW.rtb_acc_scale_m;
}

// Model initialize function
void PoseEstimationController_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for Atomic SubSystem: '<S1>/Extended Kalman Filter'
  // Start for DataStoreMemory: '<S2>/DataStoreMemory - P'
  memcpy(&rtDW.P_j[0], &rtCP_DataStoreMemoryP_InitialVa[0], 144U * sizeof(real_T));

  // End of Start for SubSystem: '<S1>/Extended Kalman Filter'
}

//
// File trailer for generated code.
//
// [EOF]
//
