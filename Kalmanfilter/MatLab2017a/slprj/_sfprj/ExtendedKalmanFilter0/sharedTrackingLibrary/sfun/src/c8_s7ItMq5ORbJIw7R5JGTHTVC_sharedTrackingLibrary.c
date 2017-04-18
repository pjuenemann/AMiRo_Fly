/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sharedTrackingLibrary_sfun_debug_macros.h"
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
static const char * c8_s7ItMq5ORbJIw7R5JGTHTVC_debug_family_names[10] = {
  "MeasurementFcn", "pM", "nargin", "nargout", "x", "P", "yMeas", "R", "xNew",
  "PNew" };

/* Function Declarations */
static void initialize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initialize_params_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void enable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void disable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_update_debugger_state_c8_s7ItMq5ORbJI
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void set_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_st);
static void finalize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void sf_gateway_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void mdl_start_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initSimStructsc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_measurementDroneFcn_invoke
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[5]);
static void init_script_number_translation(uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_machineNumber, uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_chartNumber, uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_instanceNumber);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[144]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[144]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_c_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[12]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_d_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[12]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_EKFCorrectorAdditive_correct
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_z[5], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12],
   real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[144], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x[12], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_P[144]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_mrdivide
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_A[60], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_B[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y[60]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_warning
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData);
static int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData);
static c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
  c8_s7ItMq5ORbJIw7R5JGTHTVC_g_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_h_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, char_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[19]);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_i_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData);
static uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_is_active_c8_s7ItMq5ORbJIw7R5JGTHTV, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier);
static uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_l_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId);
static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_EKFCorrectorAdditive_correct
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_z[5], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12],
   real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[144]);
static void init_dsm_address_info
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void init_simulink_io_address
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_
    = 0U;
}

static void initialize_params_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_m0 = NULL;
  static const char * c8_s7ItMq5ORbJIw7R5JGTHTVC_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_r0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c8_s7ItMq5ORbJIw7R5JGTHTVC_m0, 4,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_fieldNames, "sex2lFeEcOPeDeDewnWtFVE");
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField = sf_mex_getfield
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField),
                      c8_s7ItMq5ORbJIw7R5JGTHTVC_r0.FcnName, 1, 10, 0U, 1, 0U, 2,
                      1, 19);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField = sf_mex_getfield
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_m0, "JacobianFcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField), NULL,
                      1, 10, 0U, 1, 0U, 2, 0, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField = sf_mex_getfield
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_m0, "HasJacobian", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField),
                      &c8_s7ItMq5ORbJIw7R5JGTHTVC_r0.HasJacobian, 1, 11, 0U, 0,
                      0U, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField = sf_mex_getfield
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_mxField),
                      &c8_s7ItMq5ORbJIw7R5JGTHTVC_r0.HasAdditiveNoise, 1, 11, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_m0);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_pM = c8_s7ItMq5ORbJIw7R5JGTHTVC_r0;
}

static void enable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_update_debugger_state_c8_s7ItMq5ORbJI
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_st;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_hoistedGlobal;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_st = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_st = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_createcellmatrix(3, 1),
                false);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y, sf_mex_create("y",
    *chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, 0, c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y, sf_mex_create("y",
    *chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew, 0, 0U, 1U, 0U, 1, 12),
                false);
  sf_mex_setcell(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, 1, c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_hoistedGlobal =
    chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y, sf_mex_create("y",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_hoistedGlobal, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, 2, c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_st, c8_s7ItMq5ORbJIw7R5JGTHTVC_y,
                false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_st;
}

static void set_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_st)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_dv0[144];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_dv1[12];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i1;
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_doneDoubleBufferReInit = true;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_u = sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_st);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PNew", c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0)), "PNew",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_dv0);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i0 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i0 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i0++) {
    (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i0] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_dv0[c8_s7ItMq5ORbJIw7R5JGTHTVC_i0];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xNew", c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 1)), "xNew",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_dv1);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i1 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i1 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i1++) {
    (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i1] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_dv1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i1];
  }

  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_
    = c8_s7ItMq5ORbJIw7R5JGTHTVC_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary",
                    c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 2)),
    "is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary");
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_update_debugger_state_c8_s7ItMq5ORbJI(chartInstance);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_st);
}

static void finalize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i2;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i3;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i4;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i5;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i6;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i7;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i8;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[144];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i9;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_yMeas[5];
  uint32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_debug_family_var_map[10];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_R[25];
  c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_nargin = 4.0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout = 2.0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew[12];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew[144];
  static c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_r1 = { { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'm',
      'e', 'n', 't', 'D', 'r', 'o', 'n', 'e', 'F', 'c', 'n' },/* FcnName */
    false,                             /* HasJacobian */
    true                               /* HasAdditiveNoise */
  };

  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i10;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i11;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i12;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i13;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_xNew[12];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i14;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_PNew[144];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i15;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_yMeas[5];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_R[25];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i16;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i17;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i18;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i19;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i20;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i2 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i2 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_R)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i2], 3U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i3 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i3 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_yMeas)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i3], 2U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i4 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i4 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_P)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i4], 1U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i5 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i5 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_x)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i5], 0U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }

  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i6 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i6 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i6++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i6] =
      (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_x)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i6];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i7 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i7 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i7++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[c8_s7ItMq5ORbJIw7R5JGTHTVC_i7] =
      (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_P)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i7];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i8 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i8 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i8++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_yMeas[c8_s7ItMq5ORbJIw7R5JGTHTVC_i8] =
      (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_yMeas)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i8];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i9 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i9 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i9++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_R[c8_s7ItMq5ORbJIw7R5JGTHTVC_i9] =
      (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_R)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_debug_family_names,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM, 1U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_s7ItMq5ORbJIw7R5JGTHTVC_nargin, 2U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallOut,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout, 3U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallOut,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x, 4U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P, 5U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_yMeas, 6U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_R, 7U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew, 8U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew, 9U,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallIn);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM = c8_s7ItMq5ORbJIw7R5JGTHTVC_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 7);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i10 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i10 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i10++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 8);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i11 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i11 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i11++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 9);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 10);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, 14);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i12 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i12 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i12++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_xNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i12] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i12];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i13 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i13 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i13++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_PNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i13] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[c8_s7ItMq5ORbJIw7R5JGTHTVC_i13];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i14 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i14 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i14++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_yMeas[c8_s7ItMq5ORbJIw7R5JGTHTVC_i14] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_yMeas[c8_s7ItMq5ORbJIw7R5JGTHTVC_i14];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i15 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i15 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i15++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_R[c8_s7ItMq5ORbJIw7R5JGTHTVC_i15] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_R[c8_s7ItMq5ORbJIw7R5JGTHTVC_i15];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_yMeas, c8_s7ItMq5ORbJIw7R5JGTHTVC_c_R,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_xNew, c8_s7ItMq5ORbJIw7R5JGTHTVC_c_PNew);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i16 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i16 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i16++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i16] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_c_xNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i16];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i17 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i17 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i17++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i17] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_c_PNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i18 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i18 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i18++) {
    (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i18] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i18];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i19 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i19 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i19++) {
    (*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i19] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew[c8_s7ItMq5ORbJIw7R5JGTHTVC_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i20 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i20 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i20], 4U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i21 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i21 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew)
                          [c8_s7ItMq5ORbJIw7R5JGTHTVC_i21], 5U, 1U, 0U,
                          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_sfEvent,
                          false);
  }
}

static void mdl_start_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_measurementDroneFcn_invoke
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[5])
{
  _ssFcnCallExecArgInfo c8_s7ItMq5ORbJIw7R5JGTHTVC_args[2];
  c8_s7ItMq5ORbJIw7R5JGTHTVC_args[0U].dataPtr = (void *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_args[1U].dataPtr = (void *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "measurementDroneFcn",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_args[0U]);
}

static void init_script_number_translation(uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_machineNumber, uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_chartNumber, uint32_T
  c8_s7ItMq5ORbJIw7R5JGTHTVC_instanceNumber)
{
  (void)(c8_s7ItMq5ORbJIw7R5JGTHTVC_machineNumber);
  (void)(c8_s7ItMq5ORbJIw7R5JGTHTVC_chartNumber);
  (void)(c8_s7ItMq5ORbJIw7R5JGTHTVC_instanceNumber);
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i22;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i23;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i24;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u[144];
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_i22 = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i23 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i23 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i23++) {
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i24 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i24 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i24++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_u[c8_s7ItMq5ORbJIw7R5JGTHTVC_i24 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i22] = (*(real_T (*)[144])
        c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)[c8_s7ItMq5ORbJIw7R5JGTHTVC_i24 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i22];
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_i22 += 12;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[144])
{
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[144])
{
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_dv2[144];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i25;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), c8_s7ItMq5ORbJIw7R5JGTHTVC_dv2,
                1, 0, 0U, 1, 0U, 2, 12, 12);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i25 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i25 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i25++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i25] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_dv2[c8_s7ItMq5ORbJIw7R5JGTHTVC_i25];
  }

  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew;
  const char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y[144];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i26;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i27;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i28;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew = sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier = c8_s7ItMq5ORbJIw7R5JGTHTVC_varName;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_PNew);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_i26 = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i27 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i27 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i27++) {
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i28 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i28 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i28++) {
      (*(real_T (*)[144])c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
        [c8_s7ItMq5ORbJIw7R5JGTHTVC_i28 + c8_s7ItMq5ORbJIw7R5JGTHTVC_i26] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i28 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i26];
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_i26 += 12;
  }

  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i29;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u[12];
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i29 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i29 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i29++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u[c8_s7ItMq5ORbJIw7R5JGTHTVC_i29] = (*(real_T (*)
      [12])c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)[c8_s7ItMq5ORbJIw7R5JGTHTVC_i29];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_c_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[12])
{
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_d_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[12])
{
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_dv3[12];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i30;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), c8_s7ItMq5ORbJIw7R5JGTHTVC_dv3,
                1, 0, 0U, 1, 0U, 1, 12);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i30 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i30 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i30++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i30] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_dv3[c8_s7ItMq5ORbJIw7R5JGTHTVC_i30];
  }

  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew;
  const char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y[12];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i31;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew = sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier = c8_s7ItMq5ORbJIw7R5JGTHTVC_varName;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_xNew);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i31 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i31 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i31++) {
    (*(real_T (*)[12])c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
      [c8_s7ItMq5ORbJIw7R5JGTHTVC_i31] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i31];
  }

  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i32;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i33;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i34;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u[25];
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_i32 = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i33 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i33 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i33++) {
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i34 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i34 < 5;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i34++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_u[c8_s7ItMq5ORbJIw7R5JGTHTVC_i34 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i32] = (*(real_T (*)[25])
        c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)[c8_s7ItMq5ORbJIw7R5JGTHTVC_i34 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i32];
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_i32 += 5;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0, 0U, 1U, 0U, 2, 5, 5), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i35;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u[5];
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i35 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i35 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i35++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u[c8_s7ItMq5ORbJIw7R5JGTHTVC_i35] = (*(real_T (*)
      [5])c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)[c8_s7ItMq5ORbJIw7R5JGTHTVC_i35];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_u = *(real_T *)c8_s7ItMq5ORbJIw7R5JGTHTVC_inData;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d0;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), &c8_s7ItMq5ORbJIw7R5JGTHTVC_d0,
                1, 0, 0U, 0, 0U, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_d0;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout;
  const char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout = sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier = c8_s7ItMq5ORbJIw7R5JGTHTVC_varName;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout),
     &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_nargout);
  *(real_T *)c8_s7ItMq5ORbJIw7R5JGTHTVC_outData = c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_u;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i36;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_u[19];
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_u;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = NULL;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_u;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y = NULL;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_u =
    *(c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_inData;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_createstruct("structure",
    2, 1, 1), false);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i36 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i36 < 19;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i36++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_u[c8_s7ItMq5ORbJIw7R5JGTHTVC_i36] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_u.FcnName[c8_s7ItMq5ORbJIw7R5JGTHTVC_i36];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_u, 10, 0U, 1U, 0U, 2, 1, 19), false);
  sf_mex_addfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y,
                  "FcnName", "FcnName", 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y, sf_mex_create("y", NULL, 10, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_addfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y,
                  "JacobianFcnName", "JacobianFcnName", 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_u = c8_s7ItMq5ORbJIw7R5JGTHTVC_u.HasJacobian;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y, sf_mex_create("y",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y,
                  "HasJacobian", "HasJacobian", 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_u = c8_s7ItMq5ORbJIw7R5JGTHTVC_u.HasAdditiveNoise;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y, sf_mex_create("y",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_y, c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y,
                  "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  (void)c8_s7ItMq5ORbJIw7R5JGTHTVC_inData;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y", NULL, 0, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

const mxArray
  *sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_nameCaptureInfo = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_nameCaptureInfo, sf_mex_create(
    "nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1), false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_nameCaptureInfo;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_EKFCorrectorAdditive_correct
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_z[5], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12],
   real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[144], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x[12], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_P[144])
{
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i37;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i38;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i39;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i40;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[5];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_zcov[25];
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i37 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i37 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i37++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i37] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i37];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i38 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i38 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i38++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_P[c8_s7ItMq5ORbJIw7R5JGTHTVC_i38] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[c8_s7ItMq5ORbJIw7R5JGTHTVC_i38];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i39 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i39 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i39++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i39] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i39];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i40 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i40 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i40++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_zcov[c8_s7ItMq5ORbJIw7R5JGTHTVC_i40] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[c8_s7ItMq5ORbJIw7R5JGTHTVC_i40];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z, c8_s7ItMq5ORbJIw7R5JGTHTVC_b_zcov,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x, c8_s7ItMq5ORbJIw7R5JGTHTVC_c_P);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_mrdivide
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_A[60], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_B[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y[60])
{
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i41;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i42;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[25];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_info;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_ipiv[5];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jm1;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_info;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_mmj;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i43;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jj;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jBcol;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_n;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jAcol;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i44;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_xj;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jBcol;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jAcol;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i45;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_idxmax;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jp;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_ix;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_xi;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_a;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_b;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_temp;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_kBcol;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_kBcol;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_temp;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_a;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_h_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_h_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_b;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_c;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_smax;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_h_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i46;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jrow;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_c;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_l_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_m_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_m;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_l_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_m_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_n_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jprow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_n_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_iy0;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_iy0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_ia0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_o_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_iy0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_iy;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_iy0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ia0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_l_x;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_m_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_n;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_z;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_temp;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_n_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_ix0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_o_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_iy0;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_p_x;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ia0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_p_a;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_s;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_n;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_q_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_h_ix0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_iy0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ia0;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_r_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jA;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_jy;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_o_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_p_b;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_j;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_yjy;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_temp;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_s_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_q_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_t_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i47;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_r_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i48;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_v_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_s_b;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_w_a;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_t_b;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_overflow;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_ijA;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_x_a;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i41 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i41 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i41++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_i41] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_B[c8_s7ItMq5ORbJIw7R5JGTHTVC_i41];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i42 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i42 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i42++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_ipiv[c8_s7ItMq5ORbJIw7R5JGTHTVC_i42] = 1 +
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i42;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_info = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_j = 1; c8_s7ItMq5ORbJIw7R5JGTHTVC_j < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_j++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_j - 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jm1 = c8_s7ItMq5ORbJIw7R5JGTHTVC_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_mmj = 5 - c8_s7ItMq5ORbJIw7R5JGTHTVC_b;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jm1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_a * 6;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_c + 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jj = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_b;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jj + 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_mmj + 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_c;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_jj;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_n;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_ix0;
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n < 1) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_idxmax = 0;
    } else {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_idxmax = 1;
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n > 1) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix0 - 1];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = muDoubleScalarAbs
          (c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x);
        c8_s7ItMq5ORbJIw7R5JGTHTVC_f_x = 0.0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_g_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_x;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_h_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_g_x;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = muDoubleScalarAbs
          (c8_s7ItMq5ORbJIw7R5JGTHTVC_h_x);
        c8_s7ItMq5ORbJIw7R5JGTHTVC_smax = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_h_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_k_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_h_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_overflow = ((!(2 >
          c8_s7ItMq5ORbJIw7R5JGTHTVC_k_b)) && (c8_s7ItMq5ORbJIw7R5JGTHTVC_k_b >
          2147483646));
        if (c8_s7ItMq5ORbJIw7R5JGTHTVC_c_overflow) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
            c8_s7ItMq5ORbJIw7R5JGTHTVC_c_overflow);
        }

        for (c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k = 2; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k <=
             c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k++) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_o_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_ix + 1;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_o_a;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_i_x =
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_ix - 1];
          c8_s7ItMq5ORbJIw7R5JGTHTVC_j_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_i_x;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_k_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_j_x;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_m_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_k_x;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y = muDoubleScalarAbs
            (c8_s7ItMq5ORbJIw7R5JGTHTVC_m_x);
          c8_s7ItMq5ORbJIw7R5JGTHTVC_n_x = 0.0;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_o_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_n_x;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_p_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_o_x;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y = muDoubleScalarAbs
            (c8_s7ItMq5ORbJIw7R5JGTHTVC_p_x);
          c8_s7ItMq5ORbJIw7R5JGTHTVC_s = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y;
          if (c8_s7ItMq5ORbJIw7R5JGTHTVC_s > c8_s7ItMq5ORbJIw7R5JGTHTVC_smax) {
            c8_s7ItMq5ORbJIw7R5JGTHTVC_idxmax = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k;
            c8_s7ItMq5ORbJIw7R5JGTHTVC_smax = c8_s7ItMq5ORbJIw7R5JGTHTVC_s;
          }
        }
      }
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_idxmax - 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset = c8_s7ItMq5ORbJIw7R5JGTHTVC_e_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jj;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv = (c8_s7ItMq5ORbJIw7R5JGTHTVC_f_a +
      c8_s7ItMq5ORbJIw7R5JGTHTVC_e_b) - 1;
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv] != 0.0)
    {
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset != 0) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_g_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_g_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_e_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_g_a +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_g_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_ipiv[c8_s7ItMq5ORbJIw7R5JGTHTVC_j - 1] =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_e_c;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_j_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jm1 + 1;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_jrow = c8_s7ItMq5ORbJIw7R5JGTHTVC_j_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_m_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jrow;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_m_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jpiv_offset;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_jprow = c8_s7ItMq5ORbJIw7R5JGTHTVC_m_a +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_m_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_jrow;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_jprow;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_e_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ix0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_iy0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_e_ix0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_iy = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_iy0;
        for (c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k = 1; c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k <
             6; c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k++) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_c_temp =
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix - 1];
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix - 1] =
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_iy - 1];
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_iy - 1] =
            c8_s7ItMq5ORbJIw7R5JGTHTVC_c_temp;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_p_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix + 5;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_p_a;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_q_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_iy + 5;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_iy = c8_s7ItMq5ORbJIw7R5JGTHTVC_q_a;
        }
      }

      c8_s7ItMq5ORbJIw7R5JGTHTVC_h_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_mmj - 1;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_d_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_h_a;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_j_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_c;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i46 = c8_s7ItMq5ORbJIw7R5JGTHTVC_j_a +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i_b;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_l_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_l_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_i46;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_n_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_l_a;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_n_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_l_b;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_d_overflow = ((!(c8_s7ItMq5ORbJIw7R5JGTHTVC_n_a
        > c8_s7ItMq5ORbJIw7R5JGTHTVC_n_b)) && (c8_s7ItMq5ORbJIw7R5JGTHTVC_n_b >
        2147483646));
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_d_overflow) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
          c8_s7ItMq5ORbJIw7R5JGTHTVC_d_overflow);
      }

      for (c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i = c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j - 1;
           c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i + 1 <= c8_s7ItMq5ORbJIw7R5JGTHTVC_i46;
           c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i++) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_l_x =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_jj - 1];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_z = c8_s7ItMq5ORbJIw7R5JGTHTVC_l_x /
          c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_d_i] =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_z;
      }
    } else {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_info = c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_c = 5 - c8_s7ItMq5ORbJIw7R5JGTHTVC_f_b;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jj + 5;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_i_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_k_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jj + 6;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_g_c = c8_s7ItMq5ORbJIw7R5JGTHTVC_k_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_m = c8_s7ItMq5ORbJIw7R5JGTHTVC_mmj;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_c;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_jp1j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_c;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_ia0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_g_c;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m = c8_s7ItMq5ORbJIw7R5JGTHTVC_m;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_iy0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ia0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_ia0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_g_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_ix0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_iy0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ia0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ia0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_n = c8_s7ItMq5ORbJIw7R5JGTHTVC_e_n;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_h_ix0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_g_ix0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_iy0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_e_iy0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ia0 = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ia0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_r_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ia0 - 1;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jA = c8_s7ItMq5ORbJIw7R5JGTHTVC_r_a;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jy = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_iy0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_o_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_n;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_p_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_o_b;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_overflow = ((!(1 >
      c8_s7ItMq5ORbJIw7R5JGTHTVC_p_b)) && (c8_s7ItMq5ORbJIw7R5JGTHTVC_p_b >
      2147483646));
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_e_overflow) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_e_overflow);
    }

    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_d_j = 1; c8_s7ItMq5ORbJIw7R5JGTHTVC_d_j <=
         c8_s7ItMq5ORbJIw7R5JGTHTVC_f_n; c8_s7ItMq5ORbJIw7R5JGTHTVC_d_j++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_yjy =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_jy - 1];
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_yjy != 0.0) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_d_temp = -c8_s7ItMq5ORbJIw7R5JGTHTVC_yjy;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_h_ix0;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_q_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jA + 1;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i47 = c8_s7ItMq5ORbJIw7R5JGTHTVC_q_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_u_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_r_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_jA;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i48 = c8_s7ItMq5ORbJIw7R5JGTHTVC_u_a +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_r_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_v_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_i47;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_s_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_i48;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_w_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_v_a;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_t_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_s_b;
        c8_s7ItMq5ORbJIw7R5JGTHTVC_f_overflow =
          ((!(c8_s7ItMq5ORbJIw7R5JGTHTVC_w_a > c8_s7ItMq5ORbJIw7R5JGTHTVC_t_b)) &&
           (c8_s7ItMq5ORbJIw7R5JGTHTVC_t_b > 2147483646));
        if (c8_s7ItMq5ORbJIw7R5JGTHTVC_f_overflow) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
            c8_s7ItMq5ORbJIw7R5JGTHTVC_f_overflow);
        }

        for (c8_s7ItMq5ORbJIw7R5JGTHTVC_ijA = c8_s7ItMq5ORbJIw7R5JGTHTVC_i47 - 1;
             c8_s7ItMq5ORbJIw7R5JGTHTVC_ijA + 1 <=
             c8_s7ItMq5ORbJIw7R5JGTHTVC_i48; c8_s7ItMq5ORbJIw7R5JGTHTVC_ijA++) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_ijA] +=
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix - 1] *
            c8_s7ItMq5ORbJIw7R5JGTHTVC_d_temp;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_x_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix + 1;
          c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ix = c8_s7ItMq5ORbJIw7R5JGTHTVC_x_a;
        }
      }

      c8_s7ItMq5ORbJIw7R5JGTHTVC_s_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jy + 5;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_jy = c8_s7ItMq5ORbJIw7R5JGTHTVC_s_a;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_t_a = c8_s7ItMq5ORbJIw7R5JGTHTVC_jA + 5;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_jA = c8_s7ItMq5ORbJIw7R5JGTHTVC_t_a;
    }
  }

  if (((real_T)c8_s7ItMq5ORbJIw7R5JGTHTVC_info == 0.0) &&
      (!(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[24] != 0.0))) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_info = 5;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_info = c8_s7ItMq5ORbJIw7R5JGTHTVC_info;
  if ((real_T)c8_s7ItMq5ORbJIw7R5JGTHTVC_b_info > 0.0) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_warning(chartInstance);
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i43 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i43 < 60;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i43++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i43] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_i43];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j + 1 <
       6; c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jBcol = 12 * c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_jAcol = 5 * c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i44 = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_i44;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_b = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_b;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow = ((!(1 > c8_s7ItMq5ORbJIw7R5JGTHTVC_d_b))
      && (c8_s7ItMq5ORbJIw7R5JGTHTVC_d_b > 2147483646));
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow);
    }

    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_k = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_k + 1 <=
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i44; c8_s7ItMq5ORbJIw7R5JGTHTVC_k++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_kBcol = 12 * c8_s7ItMq5ORbJIw7R5JGTHTVC_k;
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_k +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_jAcol] != 0.0) {
        for (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i
             + 1 < 13; c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i++) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_jBcol] -=
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_k +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_jAcol] *
            c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_i +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_kBcol];
        }
      }
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j +
      c8_s7ItMq5ORbJIw7R5JGTHTVC_jAcol];
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_temp = 1.0 / c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i + 1 < 13;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_jBcol] *= c8_s7ItMq5ORbJIw7R5JGTHTVC_b_temp;
    }
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j = 4; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j + 1 >
       0; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j--) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jBcol = 12 * c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jAcol = 5 * c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i45 = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_overflow = false;
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_overflow) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error(chartInstance,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_overflow);
    }

    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k = c8_s7ItMq5ORbJIw7R5JGTHTVC_i45 + 1;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k + 1 < 6; c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k
         ++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_kBcol = 12 * c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k;
      if (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jAcol] != 0.0) {
        for (c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i
             + 1 < 13; c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i++) {
          c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jBcol] -=
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_A[c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_jAcol] *
            c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_c_i +
            c8_s7ItMq5ORbJIw7R5JGTHTVC_b_kBcol];
        }
      }
    }
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_xj = 3; c8_s7ItMq5ORbJIw7R5JGTHTVC_xj + 1 > 0;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_xj--) {
    if (c8_s7ItMq5ORbJIw7R5JGTHTVC_ipiv[c8_s7ItMq5ORbJIw7R5JGTHTVC_xj] !=
        c8_s7ItMq5ORbJIw7R5JGTHTVC_xj + 1) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_jp =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_ipiv[c8_s7ItMq5ORbJIw7R5JGTHTVC_xj] - 1;
      for (c8_s7ItMq5ORbJIw7R5JGTHTVC_xi = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_xi + 1 <
           13; c8_s7ItMq5ORbJIw7R5JGTHTVC_xi++) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_temp =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_xi + 12 *
          c8_s7ItMq5ORbJIw7R5JGTHTVC_xj];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_xi + 12 *
          c8_s7ItMq5ORbJIw7R5JGTHTVC_xj] =
          c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_xi + 12 *
          c8_s7ItMq5ORbJIw7R5JGTHTVC_jp];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_xi + 12 *
          c8_s7ItMq5ORbJIw7R5JGTHTVC_jp] = c8_s7ItMq5ORbJIw7R5JGTHTVC_temp;
      }
    }
  }
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_check_forloop_overflow_error
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  static char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_cv0[34] = { 'C', 'o', 'd', 'e', 'r',
    ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o',
    'r', 'l', 'o', 'o', 'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  static char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_cv1[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c8_s7ItMq5ORbJIw7R5JGTHTVC_overflow) {
  } else {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
    sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
      c8_s7ItMq5ORbJIw7R5JGTHTVC_cv0, 10, 0U, 1U, 0U, 2, 1, 34), false);
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
    sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y, sf_mex_create("y",
      c8_s7ItMq5ORbJIw7R5JGTHTVC_cv1, 10, 0U, 1U, 0U, 2, 1, 5), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c8_s7ItMq5ORbJIw7R5JGTHTVC_y, 14,
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y));
  }
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_warning
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  static char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_cv2[7] = { 'w', 'a', 'r', 'n', 'i',
    'n', 'g' };

  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  static char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_cv3[7] = { 'm', 'e', 's', 's', 'a',
    'g', 'e' };

  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  static char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_msgID[27] = { 'C', 'o', 'd', 'e', 'r',
    ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_cv2, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_cv3, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y, sf_mex_create("y",
    c8_s7ItMq5ORbJIw7R5JGTHTVC_msgID, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14,
                    c8_s7ItMq5ORbJIw7R5JGTHTVC_y, 14, sf_mex_call_debug
                    (sfGlobalDebugInstanceStruct, "feval", 1U, 2U, 14,
                     c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y, 14,
                     c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y));
}

static const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_inData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u;
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_u = *(int32_T *)c8_s7ItMq5ORbJIw7R5JGTHTVC_inData;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = NULL;
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_y, sf_mex_create("y",
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData,
                c8_s7ItMq5ORbJIw7R5JGTHTVC_y, false);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayOutData;
}

static int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i49;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), &c8_s7ItMq5ORbJIw7R5JGTHTVC_i49,
                1, 6, 0U, 0, 0U, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_i49;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sfEvent;
  const char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sfEvent = sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier = c8_s7ItMq5ORbJIw7R5JGTHTVC_varName;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sfEvent),
     &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sfEvent);
  *(int32_T *)c8_s7ItMq5ORbJIw7R5JGTHTVC_outData = c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
}

static c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
  c8_s7ItMq5ORbJIw7R5JGTHTVC_g_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  static const char * c8_s7ItMq5ORbJIw7R5JGTHTVC_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent =
    c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId,
                      c8_s7ItMq5ORbJIw7R5JGTHTVC_u, 4,
                      c8_s7ItMq5ORbJIw7R5JGTHTVC_fieldNames, 0U, NULL);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = "FcnName";
  c8_s7ItMq5ORbJIw7R5JGTHTVC_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_u, "FcnName", "FcnName", 0)),
    &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId, c8_s7ItMq5ORbJIw7R5JGTHTVC_y.FcnName);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = "JacobianFcnName";
  c8_s7ItMq5ORbJIw7R5JGTHTVC_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_u, "JacobianFcnName",
                     "JacobianFcnName", 0)), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = "HasJacobian";
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y.HasJacobian =
    c8_s7ItMq5ORbJIw7R5JGTHTVC_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_u, "HasJacobian", "HasJacobian",
                     0)), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = "HasAdditiveNoise";
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y.HasAdditiveNoise =
    c8_s7ItMq5ORbJIw7R5JGTHTVC_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s7ItMq5ORbJIw7R5JGTHTVC_u, "HasAdditiveNoise",
                     "HasAdditiveNoise", 0)), &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_h_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, char_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_y[19])
{
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_cv4[19];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i50;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), c8_s7ItMq5ORbJIw7R5JGTHTVC_cv4,
                1, 10, 0U, 1, 0U, 2, 1, 19);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i50 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i50 < 19;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i50++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i50] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_cv4[c8_s7ItMq5ORbJIw7R5JGTHTVC_i50];
  }

  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_i_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
}

static boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  boolean_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b0;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), &c8_s7ItMq5ORbJIw7R5JGTHTVC_b0,
                1, 11, 0U, 0, 0U, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_b0;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData, const char_T
  *c8_s7ItMq5ORbJIw7R5JGTHTVC_varName, void *c8_s7ItMq5ORbJIw7R5JGTHTVC_outData)
{
  const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM;
  const char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM = sf_mex_dup
    (c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier = c8_s7ItMq5ORbJIw7R5JGTHTVC_varName;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM),
     &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_pM);
  *(c8_s7ItMq5ORbJIw7R5JGTHTVC_sex2lFeEcOPeDeDewnWtFVE *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_outData = c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_mxArrayInData);
}

static uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_k_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_s7ItMq5ORbJIw7R5JGTHTVC_b_is_active_c8_s7ItMq5ORbJIw7R5JGTHTV, const
   char_T *c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier)
{
  uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  emlrtMsgIdentifier c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fIdentifier = (const char *)
    c8_s7ItMq5ORbJIw7R5JGTHTVC_identifier;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.fParent = NULL;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId.bParentIsCell = false;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c8_s7ItMq5ORbJIw7R5JGTHTVC_b_is_active_c8_s7ItMq5ORbJIw7R5JGTHTV),
     &c8_s7ItMq5ORbJIw7R5JGTHTVC_thisId);
  sf_mex_destroy
    (&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_is_active_c8_s7ItMq5ORbJIw7R5JGTHTV);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_l_emlrt_marshallIn
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s7ItMq5ORbJIw7R5JGTHTVC_u, const
   emlrtMsgIdentifier *c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId)
{
  uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  uint8_T c8_s7ItMq5ORbJIw7R5JGTHTVC_u0;
  (void)chartInstance;
  sf_mex_import(c8_s7ItMq5ORbJIw7R5JGTHTVC_parentId, sf_mex_dup
                (c8_s7ItMq5ORbJIw7R5JGTHTVC_u), &c8_s7ItMq5ORbJIw7R5JGTHTVC_u0,
                1, 3, 0U, 0, 0U, 0);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_u0;
  sf_mex_destroy(&c8_s7ItMq5ORbJIw7R5JGTHTVC_u);
  return c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
}

static void c8_s7ItMq5ORbJIw7R5JGTHTVC_b_EKFCorrectorAdditive_correct
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_z[5], real_T
   c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[25], real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[12],
   real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[144])
{
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i51;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_cell_wrap_2 c8_s7ItMq5ORbJIw7R5JGTHTVC_vec[1];
  c8_s7ItMq5ORbJIw7R5JGTHTVC_cell_wrap_2 c8_s7ItMq5ORbJIw7R5JGTHTVC_r2;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i52;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[12];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[5];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i53;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i54;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i55;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_alpha1;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i56;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_beta1;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i57;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSB;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSA;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i58;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[60];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[60];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_2;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_3;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_m_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_Pxy[60];
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_n_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_k_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_maxval;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_lda_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_epsilon;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_ldb_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_ldc_t;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i59;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_alpha1;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_beta1;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i60;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_cell_wrap_2 c8_s7ItMq5ORbJIw7R5JGTHTVC_specvec[1];
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSB;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSA;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i61;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_imz[5];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i62;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y[60];
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_B;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_lda_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldb_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldc_t;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i63;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i64;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i65;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i66;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i67;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i68;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i69;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i70;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i71;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i72;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i73;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_Pyy[25];
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i74;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i75;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i76;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i77;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i78;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i79;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i80;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_alpha1;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_beta1;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSB;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSA;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i81;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_h_y[144];
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_lda_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldb_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldc_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_alpha1;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_beta1;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSB;
  char_T c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSA;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i82;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m_t;
  real_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i_y[144];
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_lda_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldb_t;
  ptrdiff_t c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldc_t;
  int32_T c8_s7ItMq5ORbJIw7R5JGTHTVC_i83;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i51 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i51 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i51++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_r2.f1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i51] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i51];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_vec[0] = c8_s7ItMq5ORbJIw7R5JGTHTVC_r2;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i52 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i52 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i52++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i52] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_vec[0].f1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i52];
  }

  CV_EML_FCN(0, 3);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_measurementDroneFcn_invoke(chartInstance,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec, c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_j = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_j < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_j++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j = 1.0 + (real_T)c8_s7ItMq5ORbJIw7R5JGTHTVC_j;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i55 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i55 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i55++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i55] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_vec[0].f1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i55];
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j), 1, 12) - 1];
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_x;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x = c8_s7ItMq5ORbJIw7R5JGTHTVC_d_x;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_y = muDoubleScalarAbs
      (c8_s7ItMq5ORbJIw7R5JGTHTVC_e_x);
    c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_2 = 1.4901161193847656E-8 *
      c8_s7ItMq5ORbJIw7R5JGTHTVC_y;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_3 =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_2;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_varargin_3;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_b_y;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_c_y;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_s7ItMq5ORbJIw7R5JGTHTVC_d_y);
    c8_s7ItMq5ORbJIw7R5JGTHTVC_epsilon = c8_s7ItMq5ORbJIw7R5JGTHTVC_maxval;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j), 1, 12) - 1] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j), 1, 12) - 1] +
      c8_s7ItMq5ORbJIw7R5JGTHTVC_epsilon;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i59 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i59 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i59++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_specvec[0].f1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i59] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i59];
    }

    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i60 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i60 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i60++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i60] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_specvec[0].f1[c8_s7ItMq5ORbJIw7R5JGTHTVC_i60];
    }

    CV_EML_FCN(0, 3);
    c8_s7ItMq5ORbJIw7R5JGTHTVC_measurementDroneFcn_invoke(chartInstance,
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec, c8_s7ItMq5ORbJIw7R5JGTHTVC_imz);
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i62 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i62 < 5;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i62++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imz[c8_s7ItMq5ORbJIw7R5JGTHTVC_i62] -=
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i62];
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_B = c8_s7ItMq5ORbJIw7R5JGTHTVC_epsilon;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_B;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y = c8_s7ItMq5ORbJIw7R5JGTHTVC_f_y;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_j), 1, 12) - 1;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i63 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i63 < 5;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i63++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[c8_s7ItMq5ORbJIw7R5JGTHTVC_i63 + 5 *
        c8_s7ItMq5ORbJIw7R5JGTHTVC_c_j] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_imz[c8_s7ItMq5ORbJIw7R5JGTHTVC_i63] /
        c8_s7ItMq5ORbJIw7R5JGTHTVC_g_y;
    }
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_i53 = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i54 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i54 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i54++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i56 = 0;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i57 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i57 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i57++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[c8_s7ItMq5ORbJIw7R5JGTHTVC_i57 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i53] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[c8_s7ItMq5ORbJIw7R5JGTHTVC_i56 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i54];
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i56 += 5;
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_i53 += 12;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_alpha1 = 1.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_beta1 = 0.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSB = 'N';
  c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSA = 'N';
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i58 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i58 < 60;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i58++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_Pxy[c8_s7ItMq5ORbJIw7R5JGTHTVC_i58] = 0.0;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_m_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_n_t = (ptrdiff_t)5;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_k_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_lda_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_ldb_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSA, &c8_s7ItMq5ORbJIw7R5JGTHTVC_TRANSB,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_m_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_n_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_k_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_alpha1,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[0], &c8_s7ItMq5ORbJIw7R5JGTHTVC_lda_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[0], &c8_s7ItMq5ORbJIw7R5JGTHTVC_ldb_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_beta1, &c8_s7ItMq5ORbJIw7R5JGTHTVC_Pxy[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_ldc_t);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_alpha1 = 1.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_beta1 = 0.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSB = 'N';
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSA = 'N';
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i61 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i61 < 60;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i61++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i61] = 0.0;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m_t = (ptrdiff_t)5;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_lda_t = (ptrdiff_t)5;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldb_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldc_t = (ptrdiff_t)5;
  dgemm(&c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSA,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_TRANSB, &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_m_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_n_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_k_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_alpha1, &c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_lda_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldb_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_beta1,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y[0], &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_ldc_t);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_i64 = 0;
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i65 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i65 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i65++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i67 = 0;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i68 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i68 < 12;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i68++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[c8_s7ItMq5ORbJIw7R5JGTHTVC_i68 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i64] =
        c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[c8_s7ItMq5ORbJIw7R5JGTHTVC_i67 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i65];
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i67 += 5;
    }

    c8_s7ItMq5ORbJIw7R5JGTHTVC_i64 += 12;
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i66 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i66 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i66++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i70 = 0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i71 = 0;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i72 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i72 < 5;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i72++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_Pyy[c8_s7ItMq5ORbJIw7R5JGTHTVC_i70 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i66] = 0.0;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i74 = 0;
      for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i75 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i75 <
           12; c8_s7ItMq5ORbJIw7R5JGTHTVC_i75++) {
        c8_s7ItMq5ORbJIw7R5JGTHTVC_Pyy[c8_s7ItMq5ORbJIw7R5JGTHTVC_i70 +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_i66] +=
          c8_s7ItMq5ORbJIw7R5JGTHTVC_e_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i74 +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_i66] *
          c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[c8_s7ItMq5ORbJIw7R5JGTHTVC_i75 +
          c8_s7ItMq5ORbJIw7R5JGTHTVC_i71];
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i74 += 5;
      }

      c8_s7ItMq5ORbJIw7R5JGTHTVC_i70 += 5;
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i71 += 12;
    }
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i69 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i69 < 25;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i69++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_Pyy[c8_s7ItMq5ORbJIw7R5JGTHTVC_i69] +=
      c8_s7ItMq5ORbJIw7R5JGTHTVC_zcov[c8_s7ItMq5ORbJIw7R5JGTHTVC_i69];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i73 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i73 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i73++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i73] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i73];
  }

  CV_EML_FCN(0, 3);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_measurementDroneFcn_invoke(chartInstance,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec, c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_mrdivide(chartInstance,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_Pxy, c8_s7ItMq5ORbJIw7R5JGTHTVC_Pyy,
    c8_s7ItMq5ORbJIw7R5JGTHTVC_gain);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i76 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i76 < 5;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i76++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i76] =
      c8_s7ItMq5ORbJIw7R5JGTHTVC_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i76] -
      c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i76];
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i77 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i77 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i77++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i77] = 0.0;
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i79 = 0;
    for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i80 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i80 < 5;
         c8_s7ItMq5ORbJIw7R5JGTHTVC_i80++) {
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i77] +=
        c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[c8_s7ItMq5ORbJIw7R5JGTHTVC_i79 +
        c8_s7ItMq5ORbJIw7R5JGTHTVC_i77] *
        c8_s7ItMq5ORbJIw7R5JGTHTVC_b_z[c8_s7ItMq5ORbJIw7R5JGTHTVC_i80];
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i79 += 12;
    }
  }

  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i78 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i78 < 12;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i78++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_x[c8_s7ItMq5ORbJIw7R5JGTHTVC_i78] +=
      c8_s7ItMq5ORbJIw7R5JGTHTVC_imvec[c8_s7ItMq5ORbJIw7R5JGTHTVC_i78];
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_alpha1 = 1.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_beta1 = 0.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSB = 'N';
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSA = 'N';
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i81 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i81 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i81++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_h_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i81] = 0.0;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k_t = (ptrdiff_t)5;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_lda_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldb_t = (ptrdiff_t)5;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSA,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_TRANSB, &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_m_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_n_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_k_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_alpha1, &c8_s7ItMq5ORbJIw7R5JGTHTVC_gain[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_lda_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_dHdx[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldb_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_beta1,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_h_y[0], &c8_s7ItMq5ORbJIw7R5JGTHTVC_c_ldc_t);
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_alpha1 = 1.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_beta1 = 0.0;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSB = 'N';
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSA = 'N';
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i82 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i82 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i82++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_i_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i82] = 0.0;
  }

  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_lda_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldb_t = (ptrdiff_t)12;
  c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSA,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_TRANSB, &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_m_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_n_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_k_t,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_alpha1, &c8_s7ItMq5ORbJIw7R5JGTHTVC_h_y[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_lda_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[0],
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldb_t, &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_beta1,
        &c8_s7ItMq5ORbJIw7R5JGTHTVC_i_y[0], &c8_s7ItMq5ORbJIw7R5JGTHTVC_d_ldc_t);
  for (c8_s7ItMq5ORbJIw7R5JGTHTVC_i83 = 0; c8_s7ItMq5ORbJIw7R5JGTHTVC_i83 < 144;
       c8_s7ItMq5ORbJIw7R5JGTHTVC_i83++) {
    c8_s7ItMq5ORbJIw7R5JGTHTVC_b_P[c8_s7ItMq5ORbJIw7R5JGTHTVC_i83] -=
      c8_s7ItMq5ORbJIw7R5JGTHTVC_i_y[c8_s7ItMq5ORbJIw7R5JGTHTVC_i83];
  }
}

static void init_dsm_address_info
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_fEmlrtCtx = (void *)sfrtGetEmlrtCtx
    (chartInstance->S);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_x = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew = (real_T (*)[12])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_P = (real_T (*)[144])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew = (real_T (*)[144])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_yMeas = (real_T (*)[5])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_R = (real_T (*)[25])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
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

void sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1132308401U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1978524795U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4086944743U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(703747926U);
}

mxArray*
  sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray
  *sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xEs6sKgumhCSAMWWWThzt");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(12);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(5);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_jit_fallback_info
  (void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("client_server");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("measurementDroneFcn");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray
  *sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray*
  sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "sghUe3cKswQmFYhNPjxNyE");
    mwSize exp_dims[2] = { 1, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);

    {
      mxArray* mxFcnName = mxCreateString("measurementDroneFcn");
      mxSetCell(mxExportedFunctionsUsedByThisChart, 0, mxFcnName);
    }

    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray
  *sf_get_sim_state_info_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _sharedTrackingLibraryMachineNumber_,
           8,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_sharedTrackingLibraryMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_sharedTrackingLibraryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _sharedTrackingLibraryMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"P");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yMeas");
          _SFD_SET_DATA_PROPS(3,1,1,0,"R");
          _SFD_SET_DATA_PROPS(4,2,0,1,"xNew");
          _SFD_SET_DATA_PROPS(5,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(6,10,0,0,"pM");
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
        _SFD_CV_INIT_EML(0,1,7,0,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1005);
        _SFD_CV_INIT_EML_FCN(0,1,"",409,-1,432);
        _SFD_CV_INIT_EML_FCN(0,2,"",433,-1,464);
        _SFD_CV_INIT_EML_FCN(0,3,"",586,-1,609);
        _SFD_CV_INIT_EML_FCN(0,4,"",763,-1,792);
        _SFD_CV_INIT_EML_FCN(0,5,"",793,-1,830);
        _SFD_CV_INIT_EML_FCN(0,6,"",955,-1,984);
        _SFD_CV_INIT_EML_IF(0,1,0,95,112,-1,188);
        _SFD_CV_INIT_EML_IF(0,1,1,254,276,623,1001);
        _SFD_CV_INIT_EML_IF(0,1,2,281,298,471,622);
        _SFD_CV_INIT_EML_IF(0,1,3,632,649,837,997);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_d_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 5U;
          dimVector[1]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_c_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallOut,
            (MexInFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallOut,
            (MexInFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_f_sf_marshallOut,
          (MexInFcnForType)c8_s7ItMq5ORbJIw7R5JGTHTVC_e_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _sharedTrackingLibraryMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          &chartInstance->c8_s7ItMq5ORbJIw7R5JGTHTVC_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s7ItMq5ORbJIw7R5JGTHTVC";
}

static void
  sf_opaque_initialize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
  initialize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  enable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  disable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  sf_gateway_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SimStruct* S)
{
  return get_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void
  sf_opaque_set_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
      ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
    ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
      ((SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary
  (SimStruct *S)
{
  /* Actual parameters from chart:
     pM
   */
  const char_T *rtParamNames[] = { "pM" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sharedTrackingLibrary_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 8);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1132308401U));
  ssSetChecksum1(S,(1978524795U));
  ssSetChecksum2(S,(4086944743U));
  ssSetChecksum3(S,(703747926U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(SimStruct *
  S)
{
  SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct *)utMalloc
    (sizeof(SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary;
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
  mdl_start_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(chartInstance);
}

void c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_s7ItMq5ORbJIw7R5JGTHTVC_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
