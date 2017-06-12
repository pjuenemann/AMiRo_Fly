/* Include files */

#include "ControllerForOriginSensordata_sfun.h"
#include "c2_ControllerForOriginSensordata.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ControllerForOriginSensordata_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c2_debug_family_names[11] = { "gyroscope", "accelerometer",
  "magnetometer", "quaternion", "euler", "data", "nargin", "nargout", "Z", "Y",
  "X" };

static const char * c2_b_debug_family_names[4] = { "varargin", "i", "nargin",
  "nargout" };

static const char * c2_c_debug_family_names[4] = { "nargin", "nargout", "q",
  "qConj" };

static const char * c2_d_debug_family_names[5] = { "nargin", "nargout", "a", "b",
  "ab" };

static const char * c2_e_debug_family_names[12] = { "q", "h", "b", "F", "J",
  "step", "qDot", "nargin", "nargout", "Gyroscope", "Accelerometer",
  "Magnetometer" };

static const char * c2_f_debug_family_names[8] = { "R", "phi", "theta", "psi",
  "nargin", "nargout", "q", "euler" };

/* Function Declarations */
static void initialize_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void initialize_params_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void enable_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void disable_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void set_sim_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void sf_gateway_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void mdl_start_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void c2_chartstep_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void initSimStructsc2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static c2_MadgwickAHRS *c2_MadgwickAHRS_MadgwickAHRS
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance,
   c2_MadgwickAHRS *c2_obj, real_T c2_varargin_2, real_T c2_varargin_4);
static void c2_quaternProd(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance, real_T c2_a[4], real_T c2_b[4], real_T c2_ab[4]);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_b_X, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[24]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_norm(SFc2_ControllerForOriginSensordataInstanceStruct
                      *chartInstance, real_T c2_x[3]);
static real_T c2_mpower(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance, real_T c2_a);
static void c2_error(SFc2_ControllerForOriginSensordataInstanceStruct
                     *chartInstance);
static void c2_b_error(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_j_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_k_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_ControllerForOriginSensordata, const char_T
   *c2_identifier);
static uint8_T c2_l_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_MadgwickAHRS_MadgwickAHRS
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance,
   c2_MadgwickAHRS **c2_obj, real_T c2_varargin_2, real_T c2_varargin_4);
static void init_dsm_address_info
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_ControllerForOriginSensordata(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_ControllerForOriginSensordata = 0U;
}

static void initialize_params_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(4, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_X;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_Y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *chartInstance->c2_Z;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal =
    chartInstance->c2_is_active_c2_ControllerForOriginSensordata;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_X = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("X", c2_u, 0)), "X");
  *chartInstance->c2_Y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Y", c2_u, 1)), "Y");
  *chartInstance->c2_Z = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Z", c2_u, 2)), "Z");
  chartInstance->c2_is_active_c2_ControllerForOriginSensordata =
    c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c2_ControllerForOriginSensordata", c2_u, 3)),
    "is_active_c2_ControllerForOriginSensordata");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ControllerForOriginSensordata(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 9; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_data)[c2_i0], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_ControllerForOriginSensordata(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_ControllerForOriginSensordataMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_Z, 1U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_Y, 2U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_X, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
}

static void mdl_start_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  uint32_T c2_debug_family_var_map[11];
  real_T c2_b_data[9];
  real_T c2_gyroscope[3];
  real_T c2_accelerometer[3];
  real_T c2_magnetometer[3];
  real_T c2_quaternion[4];
  real_T c2_euler[3];
  real_T c2_c_data[9];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 3.0;
  real_T c2_b_Z;
  real_T c2_b_Y;
  real_T c2_b_X;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  c2_MadgwickAHRS c2_AHRS;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  real_T c2_a[3];
  c2_MadgwickAHRS *c2_obj;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T c2_Gyroscope[3];
  int32_T c2_i11;
  real_T c2_Accelerometer[3];
  uint32_T c2_b_debug_family_var_map[12];
  real_T c2_Magnetometer[3];
  real_T c2_q[4];
  real_T c2_h[4];
  real_T c2_b[4];
  real_T c2_F[6];
  real_T c2_J[24];
  real_T c2_step[4];
  real_T c2_qDot[4];
  real_T c2_b_nargin = 4.0;
  real_T c2_b_nargout = 0.0;
  c2_MadgwickAHRS *c2_b_obj;
  int32_T c2_i12;
  int32_T c2_i13;
  real_T c2_c_obj[4];
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_b_Accelerometer[3];
  real_T c2_c_Accelerometer[3];
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_B;
  real_T c2_d_Accelerometer[3];
  real_T c2_y;
  real_T c2_b_y;
  int32_T c2_i19;
  int32_T c2_i20;
  uint32_T c2_c_debug_family_var_map[4];
  real_T c2_b_q[4];
  real_T c2_c_nargin = 1.0;
  int32_T c2_i21;
  real_T c2_c_nargout = 1.0;
  real_T c2_qConj[4];
  int32_T c2_i22;
  real_T c2_b_Magnetometer[3];
  real_T c2_c_Magnetometer[3];
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_b_B;
  real_T c2_d_Magnetometer[3];
  uint32_T c2_d_debug_family_var_map[8];
  real_T c2_c_q[4];
  real_T c2_c_y;
  real_T c2_R[9];
  real_T c2_d_y;
  real_T c2_phi;
  int32_T c2_i26;
  real_T c2_theta;
  real_T c2_psi;
  real_T c2_d_nargin = 1.0;
  real_T c2_d_nargout = 1.0;
  int32_T c2_i27;
  real_T c2_b_euler[3];
  real_T c2_d_q[4];
  real_T c2_e_nargin = 1.0;
  int32_T c2_i28;
  real_T c2_e_nargout = 1.0;
  real_T c2_b_qConj[4];
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_x;
  real_T c2_d_a;
  real_T c2_e_y;
  boolean_T c2_p;
  real_T c2_dv0[4];
  real_T c2_e_a;
  int32_T c2_i29;
  real_T c2_f_a;
  real_T c2_b_x;
  real_T c2_g_a;
  int32_T c2_i30;
  real_T c2_f_y;
  boolean_T c2_b_p;
  real_T c2_c_qConj[4];
  real_T c2_b_b[4];
  int32_T c2_i31;
  real_T c2_e_q[4];
  real_T c2_dv1[4];
  int32_T c2_i32;
  real_T c2_c_x[2];
  real_T c2_h_a;
  real_T c2_i_a;
  real_T c2_g_y;
  real_T c2_d_x;
  real_T c2_scale;
  real_T c2_j_a;
  int32_T c2_k;
  real_T c2_h_y;
  boolean_T c2_c_p;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_k_a;
  real_T c2_g_x;
  real_T c2_l_a;
  real_T c2_absxk;
  real_T c2_h_x;
  real_T c2_m_a;
  real_T c2_t;
  real_T c2_i_y;
  real_T c2_d0;
  boolean_T c2_d_p;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_d3;
  real_T c2_d4;
  real_T c2_d5;
  real_T c2_j_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_y;
  real_T c2_l_y;
  real_T c2_k_x;
  real_T c2_n_a;
  real_T c2_o_a;
  real_T c2_l_x;
  real_T c2_p_a;
  real_T c2_m_y;
  boolean_T c2_e_p;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  boolean_T c2_f_p;
  boolean_T c2_g_p;
  real_T c2_p_x;
  real_T c2_n_y;
  real_T c2_q_x;
  real_T c2_o_y;
  real_T c2_z;
  real_T c2_r_x;
  real_T c2_s_x;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T c2_p_y;
  real_T c2_t_x;
  real_T c2_u_x;
  int32_T c2_i35;
  int32_T c2_i36;
  real_T c2_q_y;
  int32_T c2_i37;
  real_T c2_r_y;
  real_T c2_v_x;
  int32_T c2_i38;
  real_T c2_c_b[6];
  real_T c2_q_a[24];
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  real_T c2_s_y;
  real_T c2_w_x[4];
  int32_T c2_i44;
  real_T c2_b_scale;
  int32_T c2_b_k;
  real_T c2_x_x;
  int32_T c2_i45;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_b_absxk;
  real_T c2_c_B;
  real_T c2_t_y;
  real_T c2_b_t;
  real_T c2_u_y;
  int32_T c2_i46;
  int32_T c2_i47;
  real_T c2_dv2[4];
  real_T c2_f_q[4];
  int32_T c2_i48;
  real_T c2_r_a;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_d_b[4];
  int32_T c2_i51;
  int32_T c2_i52;
  real_T c2_e_b;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  real_T c2_v_y;
  real_T c2_c_scale;
  int32_T c2_c_k;
  real_T c2_bb_x;
  int32_T c2_i56;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_c_absxk;
  real_T c2_d_B;
  real_T c2_w_y;
  real_T c2_c_t;
  real_T c2_x_y;
  int32_T c2_i57;
  int32_T c2_i58;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 9; c2_i1++) {
    c2_b_data[c2_i1] = (*chartInstance->c2_data)[c2_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 12U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_gyroscope, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_accelerometer, 1U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_magnetometer, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_quaternion, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_euler, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_c_data, MAX_uint32_T,
    c2_c_sf_marshallOut, c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_data, 5U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_Z, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_Y, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_X, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i2 = 0; c2_i2 < 9; c2_i2++) {
    c2_c_data[c2_i2] = c2_b_data[c2_i2];
  }

  _SFD_SYMBOL_SWITCH(5U, 5U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_gyroscope[c2_i3] = c2_c_data[c2_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_accelerometer[c2_i4] = c2_c_data[c2_i4 + 3];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_magnetometer[c2_i5] = c2_c_data[c2_i5 + 6];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_MadgwickAHRS_MadgwickAHRS(chartInstance, &c2_AHRS, 0.00390625, 0.1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_quaternion[c2_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_a[c2_i7] = c2_gyroscope[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_a[c2_i8] *= 0.017453292519943295;
  }

  c2_obj = &c2_AHRS;
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_Gyroscope[c2_i9] = c2_a[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_Accelerometer[c2_i10] = c2_accelerometer[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_Magnetometer[c2_i11] = c2_magnetometer[c2_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c2_e_debug_family_names,
    c2_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q, 0U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_h, 1U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_F, 3U, c2_i_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_J, 4U, c2_h_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_step, 5U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_qDot, 6U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargin, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_nargout, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Gyroscope, 9U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Accelerometer, 10U,
    c2_d_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Magnetometer, 11U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  c2_b_obj = c2_obj;
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 29);
  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_c_obj[c2_i12] = c2_b_obj->Quaternion[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_q[c2_i13] = c2_c_obj[c2_i13];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 32);
  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_b_Accelerometer[c2_i14] = c2_Accelerometer[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_c_Accelerometer[c2_i15] = c2_Accelerometer[c2_i15];
  }

  if (CV_SCRIPT_IF(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 0, c2_norm(chartInstance,
         c2_b_Accelerometer), 0.0, -1, 0U, c2_norm(chartInstance,
         c2_c_Accelerometer) == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 32);
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 33);
    for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
      c2_a[c2_i16] = c2_Accelerometer[c2_i16];
    }

    for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
      c2_d_Accelerometer[c2_i17] = c2_Accelerometer[c2_i17];
    }

    c2_B = c2_norm(chartInstance, c2_d_Accelerometer);
    c2_y = c2_B;
    c2_b_y = c2_y;
    for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
      c2_Accelerometer[c2_i20] = c2_a[c2_i20] / c2_b_y;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 36);
    for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
      c2_b_Magnetometer[c2_i21] = c2_Magnetometer[c2_i21];
    }

    for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
      c2_c_Magnetometer[c2_i22] = c2_Magnetometer[c2_i22];
    }

    if (CV_SCRIPT_IF(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 1, c2_norm(chartInstance,
           c2_b_Magnetometer), 0.0, -1, 0U, c2_norm(chartInstance,
           c2_c_Magnetometer) == 0.0))) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 36);
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 37);
      for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
        c2_a[c2_i23] = c2_Magnetometer[c2_i23];
      }

      for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
        c2_d_Magnetometer[c2_i24] = c2_Magnetometer[c2_i24];
      }

      c2_b_B = c2_norm(chartInstance, c2_d_Magnetometer);
      c2_c_y = c2_b_B;
      c2_d_y = c2_c_y;
      for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
        c2_Magnetometer[c2_i26] = c2_a[c2_i26] / c2_d_y;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 40);
      for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
        c2_d_q[c2_i27] = c2_q[c2_i27];
      }

      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_c_debug_family_names,
        c2_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargin, 0U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_e_nargout, 1U, c2_sf_marshallOut,
        c2_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_d_q, 2U, c2_e_sf_marshallOut,
        c2_d_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_qConj, 3U, c2_e_sf_marshallOut,
        c2_d_sf_marshallIn);
      CV_SCRIPT_FCN(1, 0);
      _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
      c2_b_qConj[0] = c2_d_q[0];
      c2_b_qConj[1] = -c2_d_q[1];
      c2_b_qConj[2] = -c2_d_q[2];
      c2_b_qConj[3] = -c2_d_q[3];
      _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -14);
      _SFD_SYMBOL_SCOPE_POP();
      c2_dv0[0] = 0.0;
      for (c2_i29 = 0; c2_i29 < 3; c2_i29++) {
        c2_dv0[c2_i29 + 1] = c2_Magnetometer[c2_i29];
      }

      for (c2_i30 = 0; c2_i30 < 4; c2_i30++) {
        c2_c_qConj[c2_i30] = c2_b_qConj[c2_i30];
      }

      c2_quaternProd(chartInstance, c2_dv0, c2_c_qConj, c2_b_b);
      for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
        c2_e_q[c2_i31] = c2_q[c2_i31];
      }

      c2_quaternProd(chartInstance, c2_e_q, c2_b_b, c2_dv1);
      for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
        c2_h[c2_i32] = c2_dv1[c2_i32];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 41);
      c2_c_x[0] = c2_h[1];
      c2_c_x[1] = c2_h[2];
      c2_g_y = 0.0;
      c2_scale = 2.2250738585072014E-308;
      for (c2_k = 0; c2_k + 1 < 3; c2_k++) {
        c2_e_x = c2_c_x[c2_k];
        c2_f_x = c2_e_x;
        c2_g_x = c2_f_x;
        c2_absxk = muDoubleScalarAbs(c2_g_x);
        if (c2_absxk > c2_scale) {
          c2_t = c2_scale / c2_absxk;
          c2_g_y = 1.0 + c2_g_y * c2_t * c2_t;
          c2_scale = c2_absxk;
        } else {
          c2_t = c2_absxk / c2_scale;
          c2_g_y += c2_t * c2_t;
        }
      }

      c2_g_y = c2_scale * muDoubleScalarSqrt(c2_g_y);
      c2_b[0] = 0.0;
      c2_b[1] = c2_g_y;
      c2_b[2] = 0.0;
      c2_b[3] = c2_h[3];
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 44);
      c2_d0 = c2_mpower(chartInstance, c2_q[1]);
      c2_d1 = c2_mpower(chartInstance, c2_q[2]);
      c2_d2 = c2_mpower(chartInstance, c2_q[2]);
      c2_d3 = c2_mpower(chartInstance, c2_q[3]);
      c2_d4 = c2_mpower(chartInstance, c2_q[1]);
      c2_d5 = c2_mpower(chartInstance, c2_q[2]);
      c2_F[0] = 2.0 * (c2_q[1] * c2_q[3] - c2_q[0] * c2_q[2]) -
        c2_Accelerometer[0];
      c2_F[1] = 2.0 * (c2_q[0] * c2_q[1] + c2_q[2] * c2_q[3]) -
        c2_Accelerometer[1];
      c2_F[2] = 2.0 * ((0.5 - c2_d0) - c2_d1) - c2_Accelerometer[2];
      c2_F[3] = (2.0 * c2_b[1] * ((0.5 - c2_d2) - c2_d3) + 2.0 * c2_b[3] *
                 (c2_q[1] * c2_q[3] - c2_q[0] * c2_q[2])) - c2_Magnetometer[0];
      c2_F[4] = (2.0 * c2_b[1] * (c2_q[1] * c2_q[2] - c2_q[0] * c2_q[3]) + 2.0 *
                 c2_b[3] * (c2_q[0] * c2_q[1] + c2_q[2] * c2_q[3])) -
        c2_Magnetometer[1];
      c2_F[5] = (2.0 * c2_b[1] * (c2_q[0] * c2_q[2] + c2_q[1] * c2_q[3]) + 2.0 *
                 c2_b[3] * ((0.5 - c2_d4) - c2_d5)) - c2_Magnetometer[2];
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 50);
      c2_J[0] = -2.0 * c2_q[2];
      c2_J[6] = 2.0 * c2_q[3];
      c2_J[12] = -2.0 * c2_q[0];
      c2_J[18] = 2.0 * c2_q[1];
      c2_J[1] = 2.0 * c2_q[1];
      c2_J[7] = 2.0 * c2_q[0];
      c2_J[13] = 2.0 * c2_q[3];
      c2_J[19] = 2.0 * c2_q[2];
      c2_J[2] = 0.0;
      c2_J[8] = -4.0 * c2_q[1];
      c2_J[14] = -4.0 * c2_q[2];
      c2_J[20] = 0.0;
      c2_J[3] = -2.0 * c2_b[3] * c2_q[2];
      c2_J[9] = 2.0 * c2_b[3] * c2_q[3];
      c2_J[15] = -4.0 * c2_b[1] * c2_q[2] - 2.0 * c2_b[3] * c2_q[0];
      c2_J[21] = -4.0 * c2_b[1] * c2_q[3] + 2.0 * c2_b[3] * c2_q[1];
      c2_J[4] = -2.0 * c2_b[1] * c2_q[3] + 2.0 * c2_b[3] * c2_q[1];
      c2_J[10] = 2.0 * c2_b[1] * c2_q[2] + 2.0 * c2_b[3] * c2_q[0];
      c2_J[16] = 2.0 * c2_b[1] * c2_q[1] + 2.0 * c2_b[3] * c2_q[3];
      c2_J[22] = -2.0 * c2_b[1] * c2_q[0] + 2.0 * c2_b[3] * c2_q[2];
      c2_J[5] = 2.0 * c2_b[1] * c2_q[2];
      c2_J[11] = 2.0 * c2_b[1] * c2_q[3] - 4.0 * c2_b[3] * c2_q[1];
      c2_J[17] = 2.0 * c2_b[1] * c2_q[0] - 4.0 * c2_b[3] * c2_q[2];
      c2_J[23] = 2.0 * c2_b[1] * c2_q[1];
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_i33 = 0;
      for (c2_i34 = 0; c2_i34 < 6; c2_i34++) {
        c2_i36 = 0;
        for (c2_i37 = 0; c2_i37 < 4; c2_i37++) {
          c2_q_a[c2_i37 + c2_i33] = c2_J[c2_i36 + c2_i34];
          c2_i36 += 6;
        }

        c2_i33 += 4;
      }

      for (c2_i35 = 0; c2_i35 < 6; c2_i35++) {
        c2_c_b[c2_i35] = c2_F[c2_i35];
      }

      for (c2_i38 = 0; c2_i38 < 4; c2_i38++) {
        c2_step[c2_i38] = 0.0;
      }

      for (c2_i39 = 0; c2_i39 < 4; c2_i39++) {
        c2_step[c2_i39] = 0.0;
        c2_i41 = 0;
        for (c2_i43 = 0; c2_i43 < 6; c2_i43++) {
          c2_step[c2_i39] += c2_q_a[c2_i41 + c2_i39] * c2_c_b[c2_i43];
          c2_i41 += 4;
        }
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 57);
      for (c2_i40 = 0; c2_i40 < 4; c2_i40++) {
        c2_w_x[c2_i40] = c2_step[c2_i40];
      }

      c2_s_y = 0.0;
      c2_b_scale = 2.2250738585072014E-308;
      for (c2_b_k = 0; c2_b_k + 1 < 5; c2_b_k++) {
        c2_x_x = c2_w_x[c2_b_k];
        c2_y_x = c2_x_x;
        c2_ab_x = c2_y_x;
        c2_b_absxk = muDoubleScalarAbs(c2_ab_x);
        if (c2_b_absxk > c2_b_scale) {
          c2_b_t = c2_b_scale / c2_b_absxk;
          c2_s_y = 1.0 + c2_s_y * c2_b_t * c2_b_t;
          c2_b_scale = c2_b_absxk;
        } else {
          c2_b_t = c2_b_absxk / c2_b_scale;
          c2_s_y += c2_b_t * c2_b_t;
        }
      }

      c2_s_y = c2_b_scale * muDoubleScalarSqrt(c2_s_y);
      for (c2_i45 = 0; c2_i45 < 4; c2_i45++) {
        c2_w_x[c2_i45] = c2_step[c2_i45];
      }

      c2_c_B = c2_s_y;
      c2_t_y = c2_c_B;
      c2_u_y = c2_t_y;
      for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
        c2_step[c2_i46] = c2_w_x[c2_i46] / c2_u_y;
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 60);
      for (c2_i47 = 0; c2_i47 < 4; c2_i47++) {
        c2_f_q[c2_i47] = c2_q[c2_i47];
      }

      c2_dv2[0] = 0.0;
      c2_dv2[1] = c2_Gyroscope[0];
      c2_dv2[2] = c2_Gyroscope[1];
      c2_dv2[3] = c2_Gyroscope[2];
      c2_quaternProd(chartInstance, c2_f_q, c2_dv2, c2_b_b);
      for (c2_i48 = 0; c2_i48 < 4; c2_i48++) {
        c2_b_b[c2_i48] *= 0.5;
      }

      c2_r_a = c2_b_obj->Beta;
      for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
        c2_d_b[c2_i49] = c2_step[c2_i49];
      }

      for (c2_i50 = 0; c2_i50 < 4; c2_i50++) {
        c2_d_b[c2_i50] *= c2_r_a;
      }

      for (c2_i51 = 0; c2_i51 < 4; c2_i51++) {
        c2_qDot[c2_i51] = c2_b_b[c2_i51] - c2_d_b[c2_i51];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 63);
      for (c2_i52 = 0; c2_i52 < 4; c2_i52++) {
        c2_b_b[c2_i52] = c2_qDot[c2_i52];
      }

      c2_e_b = c2_b_obj->SamplePeriod;
      for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
        c2_b_b[c2_i53] *= c2_e_b;
      }

      for (c2_i54 = 0; c2_i54 < 4; c2_i54++) {
        c2_q[c2_i54] += c2_b_b[c2_i54];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 64);
      for (c2_i55 = 0; c2_i55 < 4; c2_i55++) {
        c2_b_b[c2_i55] = c2_q[c2_i55];
      }

      c2_v_y = 0.0;
      c2_c_scale = 2.2250738585072014E-308;
      for (c2_c_k = 0; c2_c_k + 1 < 5; c2_c_k++) {
        c2_bb_x = c2_b_b[c2_c_k];
        c2_cb_x = c2_bb_x;
        c2_db_x = c2_cb_x;
        c2_c_absxk = muDoubleScalarAbs(c2_db_x);
        if (c2_c_absxk > c2_c_scale) {
          c2_c_t = c2_c_scale / c2_c_absxk;
          c2_v_y = 1.0 + c2_v_y * c2_c_t * c2_c_t;
          c2_c_scale = c2_c_absxk;
        } else {
          c2_c_t = c2_c_absxk / c2_c_scale;
          c2_v_y += c2_c_t * c2_c_t;
        }
      }

      c2_v_y = c2_c_scale * muDoubleScalarSqrt(c2_v_y);
      for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
        c2_b_b[c2_i56] = c2_q[c2_i56];
      }

      c2_d_B = c2_v_y;
      c2_w_y = c2_d_B;
      c2_x_y = c2_w_y;
      for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
        c2_b_b[c2_i57] /= c2_x_y;
      }

      for (c2_i58 = 0; c2_i58 < 4; c2_i58++) {
        c2_b_obj->Quaternion[c2_i58] = c2_b_b[c2_i58];
      }
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -64);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    c2_quaternion[c2_i18] = c2_AHRS.Quaternion[c2_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  for (c2_i19 = 0; c2_i19 < 4; c2_i19++) {
    c2_b_q[c2_i19] = c2_quaternion[c2_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_c_debug_family_names,
    c2_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_c_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_q, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_qConj, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
  c2_qConj[0] = c2_b_q[0];
  c2_qConj[1] = -c2_b_q[1];
  c2_qConj[2] = -c2_b_q[2];
  c2_qConj[3] = -c2_b_q[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
    c2_c_q[c2_i25] = c2_qConj[c2_i25];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_f_debug_family_names,
    c2_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_R, 0U, c2_j_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_phi, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_theta, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_psi, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargin, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d_nargout, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_c_q, 6U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_euler, 7U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 14);
  for (c2_i28 = 0; c2_i28 < 9; c2_i28++) {
    c2_R[c2_i28] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 15);
  c2_b_a = c2_c_q[0];
  c2_c_a = c2_b_a;
  c2_x = c2_c_a;
  c2_d_a = c2_x;
  c2_e_y = c2_d_a * c2_d_a;
  c2_p = false;
  if (c2_p) {
    c2_error(chartInstance);
  }

  c2_e_a = c2_c_q[1];
  c2_f_a = c2_e_a;
  c2_b_x = c2_f_a;
  c2_g_a = c2_b_x;
  c2_f_y = c2_g_a * c2_g_a;
  c2_b_p = false;
  if (c2_b_p) {
    c2_error(chartInstance);
  }

  c2_R[0] = (2.0 * c2_e_y - 1.0) + 2.0 * c2_f_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 16);
  c2_R[1] = 2.0 * (c2_c_q[1] * c2_c_q[2] - c2_c_q[0] * c2_c_q[3]);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 17);
  c2_R[2] = 2.0 * (c2_c_q[1] * c2_c_q[3] + c2_c_q[0] * c2_c_q[2]);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 18);
  c2_R[5] = 2.0 * (c2_c_q[2] * c2_c_q[3] - c2_c_q[0] * c2_c_q[1]);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 19);
  c2_h_a = c2_c_q[0];
  c2_i_a = c2_h_a;
  c2_d_x = c2_i_a;
  c2_j_a = c2_d_x;
  c2_h_y = c2_j_a * c2_j_a;
  c2_c_p = false;
  if (c2_c_p) {
    c2_error(chartInstance);
  }

  c2_k_a = c2_c_q[3];
  c2_l_a = c2_k_a;
  c2_h_x = c2_l_a;
  c2_m_a = c2_h_x;
  c2_i_y = c2_m_a * c2_m_a;
  c2_d_p = false;
  if (c2_d_p) {
    c2_error(chartInstance);
  }

  c2_R[8] = (2.0 * c2_h_y - 1.0) + 2.0 * c2_i_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 21);
  c2_j_y = c2_R[5];
  c2_i_x = c2_R[8];
  c2_j_x = c2_j_y;
  c2_k_y = c2_i_x;
  c2_l_y = c2_j_x;
  c2_k_x = c2_k_y;
  c2_phi = muDoubleScalarAtan2(c2_l_y, c2_k_x);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 22);
  c2_n_a = c2_R[2];
  c2_o_a = c2_n_a;
  c2_l_x = c2_o_a;
  c2_p_a = c2_l_x;
  c2_m_y = c2_p_a * c2_p_a;
  c2_e_p = false;
  if (c2_e_p) {
    c2_error(chartInstance);
  }

  c2_m_x = 1.0 - c2_m_y;
  c2_n_x = c2_m_x;
  c2_o_x = c2_n_x;
  c2_f_p = (c2_o_x < 0.0);
  c2_g_p = c2_f_p;
  if (c2_g_p) {
    c2_b_error(chartInstance);
  }

  c2_n_x = muDoubleScalarSqrt(c2_n_x);
  c2_p_x = c2_R[2];
  c2_n_y = c2_n_x;
  c2_q_x = c2_p_x;
  c2_o_y = c2_n_y;
  c2_z = c2_q_x / c2_o_y;
  c2_r_x = c2_z;
  c2_s_x = c2_r_x;
  c2_s_x = muDoubleScalarAtan(c2_s_x);
  c2_theta = -c2_s_x;
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 23);
  c2_p_y = c2_R[1];
  c2_t_x = c2_R[0];
  c2_u_x = c2_p_y;
  c2_q_y = c2_t_x;
  c2_r_y = c2_u_x;
  c2_v_x = c2_q_y;
  c2_psi = muDoubleScalarAtan2(c2_r_y, c2_v_x);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 25);
  c2_b_euler[0] = c2_phi;
  c2_b_euler[1] = c2_theta;
  c2_b_euler[2] = c2_psi;
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
    c2_a[c2_i42] = c2_b_euler[c2_i42];
  }

  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    c2_euler[c2_i44] = c2_a[c2_i44] * 57.295779513082323;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_b_Z = c2_euler[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_b_Y = c2_euler[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_b_X = c2_euler[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_Z = c2_b_Z;
  *chartInstance->c2_Y = c2_b_Y;
  *chartInstance->c2_X = c2_b_X;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_ControllerForOriginSensordata
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static c2_MadgwickAHRS *c2_MadgwickAHRS_MadgwickAHRS
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance,
   c2_MadgwickAHRS *c2_obj, real_T c2_varargin_2, real_T c2_varargin_4)
{
  c2_MadgwickAHRS *c2_b_obj;
  c2_b_obj = c2_obj;
  c2_b_MadgwickAHRS_MadgwickAHRS(chartInstance, &c2_b_obj, c2_varargin_2,
    c2_varargin_4);
  return c2_b_obj;
}

static void c2_quaternProd(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance, real_T c2_a[4], real_T c2_b[4], real_T c2_ab[4])
{
  uint32_T c2_debug_family_var_map[5];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i59;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c2_d_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_a, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ab, 4U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 13);
  for (c2_i59 = 0; c2_i59 < 4; c2_i59++) {
    c2_ab[c2_i59] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 14);
  c2_ab[0] = ((c2_a[0] * c2_b[0] - c2_a[1] * c2_b[1]) - c2_a[2] * c2_b[2]) -
    c2_a[3] * c2_b[3];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 15);
  c2_ab[1] = ((c2_a[0] * c2_b[1] + c2_a[1] * c2_b[0]) + c2_a[2] * c2_b[3]) -
    c2_a[3] * c2_b[2];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 16);
  c2_ab[2] = ((c2_a[0] * c2_b[2] - c2_a[1] * c2_b[3]) + c2_a[2] * c2_b[0]) +
    c2_a[3] * c2_b[1];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 17);
  c2_ab[3] = ((c2_a[0] * c2_b[3] + c2_a[1] * c2_b[2]) - c2_a[2] * c2_b[1]) +
    c2_a[3] * c2_b[0];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\MadgwickAHRS.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\quaternConj.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\quaternProd.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\quatern2euler.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_b_X, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_X), &c2_thisId);
  sf_mex_destroy(&c2_b_X);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d6;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d6, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d6;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_X;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_b_X = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_X), &c2_thisId);
  sf_mex_destroy(&c2_b_X);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i60;
  const mxArray *c2_y = NULL;
  real_T c2_u[9];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i60 = 0; c2_i60 < 9; c2_i60++) {
    c2_u[c2_i60] = (*(real_T (*)[9])c2_inData)[c2_i60];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i61;
  const mxArray *c2_y = NULL;
  real_T c2_u[9];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i61 = 0; c2_i61 < 9; c2_i61++) {
    c2_u[c2_i61] = (*(real_T (*)[9])c2_inData)[c2_i61];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv3[9];
  int32_T c2_i62;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c2_i62 = 0; c2_i62 < 9; c2_i62++) {
    c2_y[c2_i62] = c2_dv3[c2_i62];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i63;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_b_data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_data), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_data);
  for (c2_i63 = 0; c2_i63 < 9; c2_i63++) {
    (*(real_T (*)[9])c2_outData)[c2_i63] = c2_y[c2_i63];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i64;
  const mxArray *c2_y = NULL;
  real_T c2_u[3];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i64 = 0; c2_i64 < 3; c2_i64++) {
    c2_u[c2_i64] = (*(real_T (*)[3])c2_inData)[c2_i64];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv4[3];
  int32_T c2_i65;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i65 = 0; c2_i65 < 3; c2_i65++) {
    c2_y[c2_i65] = c2_dv4[c2_i65];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_euler;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i66;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_euler = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_euler), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_euler);
  for (c2_i66 = 0; c2_i66 < 3; c2_i66++) {
    (*(real_T (*)[3])c2_outData)[c2_i66] = c2_y[c2_i66];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i67;
  const mxArray *c2_y = NULL;
  real_T c2_u[4];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i67 = 0; c2_i67 < 4; c2_i67++) {
    c2_u[c2_i67] = (*(real_T (*)[4])c2_inData)[c2_i67];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv5[4];
  int32_T c2_i68;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c2_i68 = 0; c2_i68 < 4; c2_i68++) {
    c2_y[c2_i68] = c2_dv5[c2_i68];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_quaternion;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i69;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_quaternion = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_quaternion), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_quaternion);
  for (c2_i69 = 0; c2_i69 < 4; c2_i69++) {
    (*(real_T (*)[4])c2_outData)[c2_i69] = c2_y[c2_i69];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i70;
  const mxArray *c2_y = NULL;
  void *c2_u[4];
  int32_T c2_i71;
  const mxArray *c2_b_y = NULL;
  char_T c2_b_u[12];
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i72;
  const mxArray *c2_d_y = NULL;
  char_T c2_d_u[4];
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i70 = 0; c2_i70 < 4; c2_i70++) {
    c2_u[c2_i70] = (*(void *(*)[4])c2_inData)[c2_i70];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(4, 1), false);
  for (c2_i71 = 0; c2_i71 < 12; c2_i71++) {
    c2_b_u[c2_i71] = (*(char_T (*)[12])c2_u[0])[c2_i71];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_c_u = *(real_T *)c2_u[1];
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i72 = 0; c2_i72 < 4; c2_i72++) {
    c2_d_u[c2_i72] = (*(char_T (*)[4])c2_u[2])[c2_i72];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_d_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_e_u = *(real_T *)c2_u[3];
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i73;
  const mxArray *c2_y = NULL;
  real_T c2_u[4];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i73 = 0; c2_i73 < 4; c2_i73++) {
    c2_u[c2_i73] = (*(real_T (*)[4])c2_inData)[c2_i73];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv6[4];
  int32_T c2_i74;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i74 = 0; c2_i74 < 4; c2_i74++) {
    c2_y[c2_i74] = c2_dv6[c2_i74];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_step;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i75;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_step = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_step), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_step);
  for (c2_i75 = 0; c2_i75 < 4; c2_i75++) {
    (*(real_T (*)[4])c2_outData)[c2_i75] = c2_y[c2_i75];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i76;
  int32_T c2_i77;
  const mxArray *c2_y = NULL;
  int32_T c2_i78;
  real_T c2_u[24];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i76 = 0;
  for (c2_i77 = 0; c2_i77 < 4; c2_i77++) {
    for (c2_i78 = 0; c2_i78 < 6; c2_i78++) {
      c2_u[c2_i78 + c2_i76] = (*(real_T (*)[24])c2_inData)[c2_i78 + c2_i76];
    }

    c2_i76 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 4), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[24])
{
  real_T c2_dv7[24];
  int32_T c2_i79;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c2_i79 = 0; c2_i79 < 24; c2_i79++) {
    c2_y[c2_i79] = c2_dv7[c2_i79];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_J;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[24];
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_J = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_J), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_J);
  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 4; c2_i81++) {
    for (c2_i82 = 0; c2_i82 < 6; c2_i82++) {
      (*(real_T (*)[24])c2_outData)[c2_i82 + c2_i80] = c2_y[c2_i82 + c2_i80];
    }

    c2_i80 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i83;
  const mxArray *c2_y = NULL;
  real_T c2_u[6];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i83 = 0; c2_i83 < 6; c2_i83++) {
    c2_u[c2_i83] = (*(real_T (*)[6])c2_inData)[c2_i83];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv8[6];
  int32_T c2_i84;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i84 = 0; c2_i84 < 6; c2_i84++) {
    c2_y[c2_i84] = c2_dv8[c2_i84];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_F;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i85;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_F = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_F), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_F);
  for (c2_i85 = 0; c2_i85 < 6; c2_i85++) {
    (*(real_T (*)[6])c2_outData)[c2_i85] = c2_y[c2_i85];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i86;
  int32_T c2_i87;
  const mxArray *c2_y = NULL;
  int32_T c2_i88;
  real_T c2_u[9];
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i86 = 0;
  for (c2_i87 = 0; c2_i87 < 3; c2_i87++) {
    for (c2_i88 = 0; c2_i88 < 3; c2_i88++) {
      c2_u[c2_i88 + c2_i86] = (*(real_T (*)[9])c2_inData)[c2_i88 + c2_i86];
    }

    c2_i86 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_i_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv9[9];
  int32_T c2_i89;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i89 = 0; c2_i89 < 9; c2_i89++) {
    c2_y[c2_i89] = c2_dv9[c2_i89];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_R;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_R = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_R), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_R);
  c2_i90 = 0;
  for (c2_i91 = 0; c2_i91 < 3; c2_i91++) {
    for (c2_i92 = 0; c2_i92 < 3; c2_i92++) {
      (*(real_T (*)[9])c2_outData)[c2_i92 + c2_i90] = c2_y[c2_i92 + c2_i90];
    }

    c2_i90 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_ControllerForOriginSensordata_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  const char * c2_b_data[7] = {
    "789ced59cb6ed340149db4a5a2e2a1ac58015f50d5a1156dc42aa9dd17793669699b0a296367d238f6d8ced86e022b7e02567c044b966cf805c4e7e0c471620f"
    "8c1ce1c821c5578a6e8ecff81efbeafa689c80d44929050078ec7c569dcfcf6760148fdc04d2e3bc028241f3a971be47613039be1638cfe33f8fb3a46b161a58",
    "2e50650d956d2c22e2000d623429d3d2b1ac41cd3a7b67204090a9abb7a83562dab28ace648c8aba0f1ccb0ec0873e6a0286d4f03bdf419252b731201d737ab9"
    "aa1f005f7f9a8cfb5f0be90f1d747fe875617aeb217a2946f66203dcf7a1a7394fcf60d40bbb3faffe43865e9ae24bb075d39725257f5cab0f71d4fea6a875bf",
    "ebbb8cd481c4aff735a2de29532fc85ff36ff957dcb98988c9553bb22a1b06272053b174832b41d342c4207a17291657802a869a33c1ce3187b28a50dccebcd8"
    "839cbf655b785c37be39f9566f977fe4e39dcbb89f83c5e90d18f5669dc3270cbd34c5b785c145b992c1b82f4ae466ffe8a5d2a8150ea7d7510dd109bb0ec0c0",
    "71d54f9ee73f672f82f327cccdf71f30f4d214dfb3a1d3078dd7b5ee08cfcbf7d7293cd57799966e8b2a9aea7d89a857a530a0d679fcf541e439f1b56c0b277e"
    "7f37f4e2f27b9eef9577c59af23adf1078a972d1abed550e84c4efff35bf67f9efacf3b742612f36a8f56e94736e5e98ff5789eebeb625fe3fabff0f5b16a7ff",
    "e7be7fac24febfecfe8f84ddfa4eb628762fc9d569c1387f2f95b23bfb77c7ff9b8cf397fbf798cd645ffe977ac9be7cde7a6efc2f7ac9be7c3ef59b8cf3135f"
    "0e1e67dd9fc78f4d661bd9eae8df9045f972d4f7ac1a532fc8cfcf97dd96792f5af1cdc987e79f927df3f2fbb36835de9093bedd81b09eb92a64c9e56dfe68f9",
    "fdf91737cc85ad", "" };

  c2_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c2_b_data, 7664U, &c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static real_T c2_norm(SFc2_ControllerForOriginSensordataInstanceStruct
                      *chartInstance, real_T c2_x[3])
{
  real_T c2_y;
  real_T c2_scale;
  int32_T c2_k;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_absxk;
  real_T c2_t;
  (void)chartInstance;
  c2_y = 0.0;
  c2_scale = 2.2250738585072014E-308;
  for (c2_k = 0; c2_k + 1 < 4; c2_k++) {
    c2_b_x = c2_x[c2_k];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    c2_absxk = muDoubleScalarAbs(c2_d_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static real_T c2_mpower(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance, real_T c2_a)
{
  real_T c2_c;
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_x;
  real_T c2_d_a;
  boolean_T c2_p;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_x = c2_c_a;
  c2_d_a = c2_x;
  c2_c = c2_d_a * c2_d_a;
  c2_p = false;
  if (c2_p) {
    c2_error(chartInstance);
  }

  return c2_c;
}

static void c2_error(SFc2_ControllerForOriginSensordataInstanceStruct
                     *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv0, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static void c2_b_error(SFc2_ControllerForOriginSensordataInstanceStruct
  *chartInstance)
{
  const mxArray *c2_y = NULL;
  static char_T c2_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c2_b_y = NULL;
  static char_T c2_cv2[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_cv1, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_cv2, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_j_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i93;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i93, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i93;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_k_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_ControllerForOriginSensordata, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_ControllerForOriginSensordata), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_ControllerForOriginSensordata);
  return c2_y;
}

static uint8_T c2_l_emlrt_marshallIn
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_MadgwickAHRS_MadgwickAHRS
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance,
   c2_MadgwickAHRS **c2_obj, real_T c2_varargin_2, real_T c2_varargin_4)
{
  uint32_T c2_debug_family_var_map[4];
  void *c2_varargin[4];
  real_T c2_i;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  char_T c2_varargin_1[12];
  char_T c2_varargin_3[4];
  int32_T c2_i94;
  int32_T c2_i95;
  static char_T c2_cv3[4] = { 'B', 'e', 't', 'a' };

  int32_T c2_i96;
  static char_T c2_cv4[12] = { 'S', 'a', 'm', 'p', 'l', 'e', 'P', 'e', 'r', 'i',
    'o', 'd' };

  static real_T c2_dv10[4] = { 1.0, 0.0, 0.0, 0.0 };

  c2_MadgwickAHRS *c2_this;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_varargin, 0U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_i, 1U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  c2_varargin[0] = (void *)&c2_varargin_1;
  c2_varargin[1] = (void *)&c2_varargin_2;
  c2_varargin[2] = (void *)&c2_varargin_3;
  c2_varargin[3] = (void *)&c2_varargin_4;
  for (c2_i94 = 0; c2_i94 < 4; c2_i94++) {
    c2_varargin_3[c2_i94] = c2_cv3[c2_i94];
  }

  for (c2_i95 = 0; c2_i95 < 12; c2_i95++) {
    c2_varargin_1[c2_i95] = c2_cv4[c2_i95];
  }

  for (c2_i96 = 0; c2_i96 < 4; c2_i96++) {
    (*c2_obj)->Quaternion[c2_i96] = c2_dv10[c2_i96];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 1);
  c2_this = *c2_obj;
  *c2_obj = c2_this;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_i = 1.0;
  c2_i = 1.0;
  CV_SCRIPT_FOR(0, 0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  CV_SCRIPT_IF(0, 0, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  (*c2_obj)->SamplePeriod = c2_varargin_2;
  c2_i = 3.0;
  CV_SCRIPT_FOR(0, 0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  CV_SCRIPT_IF(0, 0, false);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 22);
  CV_SCRIPT_IF(0, 1, false);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 23);
  CV_SCRIPT_IF(0, 2, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 23);
  (*c2_obj)->Beta = c2_varargin_4;
  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_dsm_address_info
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_data = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_Z = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c2_Y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c2_X = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_ControllerForOriginSensordata_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3461251703U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2045499631U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3503778712U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(367554636U);
}

mxArray* sf_c2_ControllerForOriginSensordata_get_post_codegen_info(void);
mxArray *sf_c2_ControllerForOriginSensordata_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AAAivM2iVlbenyE7PWVGZ");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_ControllerForOriginSensordata_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_ControllerForOriginSensordata_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_ControllerForOriginSensordata_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_ControllerForOriginSensordata_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_ControllerForOriginSensordata_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_ControllerForOriginSensordata
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"X\",},{M[1],M[8],T\"Y\",},{M[1],M[5],T\"Z\",},{M[8],M[0],T\"is_active_c2_ControllerForOriginSensordata\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ControllerForOriginSensordata_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance =
      (SFc2_ControllerForOriginSensordataInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ControllerForOriginSensordataMachineNumber_,
           2,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           4,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_ControllerForOriginSensordataMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _ControllerForOriginSensordataMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ControllerForOriginSensordataMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"data");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Z");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Y");
          _SFD_SET_DATA_PROPS(3,2,0,1,"X");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,697);
        _SFD_CV_INIT_SCRIPT(0,3,0,6,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"MadgwickAHRS_MadgwickAHRS",599,-1,1025);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"MadgwickAHRS_Update",1034,-1,3409);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"MadgwickAHRS_UpdateIMU",3418,-1,4576);
        _SFD_CV_INIT_SCRIPT_IF(0,0,684,723,775,996);
        _SFD_CV_INIT_SCRIPT_IF(0,1,775,816,866,996);
        _SFD_CV_INIT_SCRIPT_IF(0,2,866,901,945,996);
        _SFD_CV_INIT_SCRIPT_IF(0,3,1240,1268,1444,1484);
        _SFD_CV_INIT_SCRIPT_IF(0,4,1444,1471,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(0,5,3613,3641,-1,-2);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,649,668,1012);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,1243,1267,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,1447,1470,-1,0);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"quaternConj",0,-1,377);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"quaternProd",0,-1,664);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"quatern2euler",0,-1,880);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ControllerForOriginSensordataMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance =
      (SFc2_ControllerForOriginSensordataInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_data);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_Z);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_Y);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c2_X);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sBN8spUFbMLIeg4fn8lhyxB";
}

static void sf_opaque_initialize_c2_ControllerForOriginSensordata(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_ControllerForOriginSensordataInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
  initialize_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_ControllerForOriginSensordata(void
  *chartInstanceVar)
{
  enable_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_ControllerForOriginSensordata(void
  *chartInstanceVar)
{
  disable_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_ControllerForOriginSensordata(void
  *chartInstanceVar)
{
  sf_gateway_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_ControllerForOriginSensordata
  (SimStruct* S)
{
  return get_sim_state_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_ControllerForOriginSensordata(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_ControllerForOriginSensordata(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_ControllerForOriginSensordataInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ControllerForOriginSensordata_optimization_info();
    }

    finalize_c2_ControllerForOriginSensordata
      ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_ControllerForOriginSensordata
    ((SFc2_ControllerForOriginSensordataInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ControllerForOriginSensordata(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ControllerForOriginSensordata
      ((SFc2_ControllerForOriginSensordataInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_ControllerForOriginSensordata(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ControllerForOriginSensordata_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(281651420U));
  ssSetChecksum1(S,(3317275510U));
  ssSetChecksum2(S,(2346233737U));
  ssSetChecksum3(S,(1785557398U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_ControllerForOriginSensordata(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ControllerForOriginSensordata(SimStruct *S)
{
  SFc2_ControllerForOriginSensordataInstanceStruct *chartInstance;
  chartInstance = (SFc2_ControllerForOriginSensordataInstanceStruct *)utMalloc
    (sizeof(SFc2_ControllerForOriginSensordataInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc2_ControllerForOriginSensordataInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_ControllerForOriginSensordata;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_ControllerForOriginSensordata(chartInstance);
}

void c2_ControllerForOriginSensordata_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ControllerForOriginSensordata(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ControllerForOriginSensordata(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ControllerForOriginSensordata(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ControllerForOriginSensordata_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
