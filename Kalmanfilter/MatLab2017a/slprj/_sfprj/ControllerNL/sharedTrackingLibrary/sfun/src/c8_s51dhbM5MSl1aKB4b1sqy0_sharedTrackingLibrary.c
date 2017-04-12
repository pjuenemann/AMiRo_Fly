/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary.h"
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
static const char * c8_s51dhbM5MSl1aKB4b1sqy0_debug_family_names[10] = {
  "MeasurementFcn", "pM", "nargin", "nargout", "x", "P", "yMeas", "R", "xNew",
  "PNew" };

/* Function Declarations */
static void initialize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initialize_params_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void enable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void disable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_s51dhbM5MSl1aKB4b1sqy0_update_debugger_state_c8_s51dhbM5MSl1a
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void set_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_st);
static void finalize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void sf_gateway_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void mdl_start_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initSimStructsc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_w[5], real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[5]);
static void init_script_number_translation(uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_machineNumber, uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_chartNumber, uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_instanceNumber);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static void c8_s51dhbM5MSl1aKB4b1sqy0_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew, const char_T
   *c8_s51dhbM5MSl1aKB4b1sqy0_identifier, real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[144]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_b_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[144]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static void c8_s51dhbM5MSl1aKB4b1sqy0_c_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew, const char_T
   *c8_s51dhbM5MSl1aKB4b1sqy0_identifier, real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[12]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_d_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[12]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static void c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static void c8_s51dhbM5MSl1aKB4b1sqy0_EKFCorrectorNonAdditive_correct
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_zcov[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12],
   real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_P[144], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_c_x[12], real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_P[144]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_numericJacobian
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_s51dhbM5MSl1aKB4b1sqy0_cell_2
   *c8_s51dhbM5MSl1aKB4b1sqy0_vec, real_T c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[60]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_b_numericJacobian
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_s51dhbM5MSl1aKB4b1sqy0_cell_2
   *c8_s51dhbM5MSl1aKB4b1sqy0_vec, real_T c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[25]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_mrdivide
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_A[60], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_B[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[60]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_overflow);
static void c8_s51dhbM5MSl1aKB4b1sqy0_warning
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData);
static int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static void c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData);
static c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE
  c8_s51dhbM5MSl1aKB4b1sqy0_g_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static void c8_s51dhbM5MSl1aKB4b1sqy0_h_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, char_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[19]);
static void c8_s51dhbM5MSl1aKB4b1sqy0_i_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_j_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static void c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData);
static uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_k_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_s51dhbM5MSl1aKB4b1sqy0_b_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_, const
   char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier);
static uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_l_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId);
static void c8_s51dhbM5MSl1aKB4b1sqy0_b_EKFCorrectorNonAdditive_correct
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_zcov[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12],
   real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_P[144]);
static void init_dsm_address_info
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void init_simulink_io_address
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sh
    = 0U;
}

static void initialize_params_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_m0 = NULL;
  static const char * c8_s51dhbM5MSl1aKB4b1sqy0_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxField;
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE c8_s51dhbM5MSl1aKB4b1sqy0_r0;
  c8_s51dhbM5MSl1aKB4b1sqy0_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c8_s51dhbM5MSl1aKB4b1sqy0_m0, 4,
    c8_s51dhbM5MSl1aKB4b1sqy0_fieldNames, "sex2lFeEcOPeDeDewnWtFVE");
  c8_s51dhbM5MSl1aKB4b1sqy0_mxField = sf_mex_getfield
    (c8_s51dhbM5MSl1aKB4b1sqy0_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_mxField),
                      c8_s51dhbM5MSl1aKB4b1sqy0_r0.FcnName, 1, 10, 0U, 1, 0U, 2,
                      1, 19);
  c8_s51dhbM5MSl1aKB4b1sqy0_mxField = sf_mex_getfield
    (c8_s51dhbM5MSl1aKB4b1sqy0_m0, "JacobianFcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_mxField), NULL,
                      1, 10, 0U, 1, 0U, 2, 0, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_mxField = sf_mex_getfield
    (c8_s51dhbM5MSl1aKB4b1sqy0_m0, "HasJacobian", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_mxField),
                      &c8_s51dhbM5MSl1aKB4b1sqy0_r0.HasJacobian, 1, 11, 0U, 0,
                      0U, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_mxField = sf_mex_getfield
    (c8_s51dhbM5MSl1aKB4b1sqy0_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_mxField),
                      &c8_s51dhbM5MSl1aKB4b1sqy0_r0.HasAdditiveNoise, 1, 11, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_m0);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_pM = c8_s51dhbM5MSl1aKB4b1sqy0_r0;
}

static void enable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_update_debugger_state_c8_s51dhbM5MSl1a
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_st;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_hoistedGlobal;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_d_y = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_st = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_st = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_createcellmatrix(3, 1),
                false);
  c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_b_y, sf_mex_create("y",
    *chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c8_s51dhbM5MSl1aKB4b1sqy0_y, 0, c8_s51dhbM5MSl1aKB4b1sqy0_b_y);
  c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_c_y, sf_mex_create("y",
    *chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c8_s51dhbM5MSl1aKB4b1sqy0_y, 1, c8_s51dhbM5MSl1aKB4b1sqy0_c_y);
  c8_s51dhbM5MSl1aKB4b1sqy0_hoistedGlobal =
    chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sh;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_d_y, sf_mex_create("y",
    &c8_s51dhbM5MSl1aKB4b1sqy0_hoistedGlobal, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_s51dhbM5MSl1aKB4b1sqy0_y, 2, c8_s51dhbM5MSl1aKB4b1sqy0_d_y);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_st, c8_s51dhbM5MSl1aKB4b1sqy0_y,
                false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_st;
}

static void set_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_st)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dv0[144];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dv1[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i1;
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_doneDoubleBufferReInit = true;
  c8_s51dhbM5MSl1aKB4b1sqy0_u = sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_st);
  c8_s51dhbM5MSl1aKB4b1sqy0_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PNew", c8_s51dhbM5MSl1aKB4b1sqy0_u, 0)), "PNew",
    c8_s51dhbM5MSl1aKB4b1sqy0_dv0);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i0 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i0 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i0++) {
    (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i0] =
      c8_s51dhbM5MSl1aKB4b1sqy0_dv0[c8_s51dhbM5MSl1aKB4b1sqy0_i0];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xNew", c8_s51dhbM5MSl1aKB4b1sqy0_u, 1)), "xNew",
    c8_s51dhbM5MSl1aKB4b1sqy0_dv1);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i1 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i1 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i1++) {
    (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i1] =
      c8_s51dhbM5MSl1aKB4b1sqy0_dv1[c8_s51dhbM5MSl1aKB4b1sqy0_i1];
  }

  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sh
    = c8_s51dhbM5MSl1aKB4b1sqy0_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary",
                    c8_s51dhbM5MSl1aKB4b1sqy0_u, 2)),
    "is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary");
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  c8_s51dhbM5MSl1aKB4b1sqy0_update_debugger_state_c8_s51dhbM5MSl1a(chartInstance);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_st);
}

static void finalize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i2;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i3;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i4;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i5;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i6;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i7;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i8;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_P[144];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i9;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_yMeas[5];
  uint32_T c8_s51dhbM5MSl1aKB4b1sqy0_debug_family_var_map[10];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_R[25];
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE
    c8_s51dhbM5MSl1aKB4b1sqy0_b_pM;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_nargin = 4.0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_nargout = 2.0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew[12];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew[144];
  static c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE
    c8_s51dhbM5MSl1aKB4b1sqy0_r1 = { { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'm',
      'e', 'n', 't', 'D', 'r', 'o', 'n', 'e', 'F', 'c', 'n' },/* FcnName */
    false,                             /* HasJacobian */
    false                              /* HasAdditiveNoise */
  };

  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i10;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i11;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i12;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i13;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_xNew[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i14;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_PNew[144];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i15;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_yMeas[5];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_R[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i16;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i17;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i18;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i19;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i20;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i2 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i2 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_R)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i2], 3U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i3 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i3 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_yMeas)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i3], 2U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i4 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i4 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_P)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i4], 1U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i5 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i5 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_x)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i5], 0U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }

  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i6 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i6 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i6++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i6] =
      (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_x)[c8_s51dhbM5MSl1aKB4b1sqy0_i6];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i7 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i7 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i7++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_P[c8_s51dhbM5MSl1aKB4b1sqy0_i7] =
      (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_P)[c8_s51dhbM5MSl1aKB4b1sqy0_i7];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i8 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i8 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i8++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_yMeas[c8_s51dhbM5MSl1aKB4b1sqy0_i8] =
      (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_yMeas)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i8];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i9 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i9 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i9++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_R[c8_s51dhbM5MSl1aKB4b1sqy0_i9] =
      (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_R)[c8_s51dhbM5MSl1aKB4b1sqy0_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U,
    c8_s51dhbM5MSl1aKB4b1sqy0_debug_family_names,
    c8_s51dhbM5MSl1aKB4b1sqy0_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U, c8_s51dhbM5MSl1aKB4b1sqy0_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_s51dhbM5MSl1aKB4b1sqy0_b_pM, 1U,
    c8_s51dhbM5MSl1aKB4b1sqy0_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_s51dhbM5MSl1aKB4b1sqy0_nargin, 2U,
    c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallOut,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_s51dhbM5MSl1aKB4b1sqy0_nargout, 3U,
    c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallOut,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s51dhbM5MSl1aKB4b1sqy0_b_x, 4U,
    c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s51dhbM5MSl1aKB4b1sqy0_b_P, 5U,
    c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s51dhbM5MSl1aKB4b1sqy0_b_yMeas, 6U,
    c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_s51dhbM5MSl1aKB4b1sqy0_b_R, 7U,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew, 8U,
    c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut,
    c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew, 9U,
    c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut,
    c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallIn);
  c8_s51dhbM5MSl1aKB4b1sqy0_b_pM = c8_s51dhbM5MSl1aKB4b1sqy0_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 7);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i10 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i10 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i10++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew[c8_s51dhbM5MSl1aKB4b1sqy0_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 8);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i11 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i11 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i11++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew[c8_s51dhbM5MSl1aKB4b1sqy0_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 9);
  CV_EML_IF(0, 1, 1, false);
  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 18);
  CV_EML_IF(0, 1, 3, false);
  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, 22);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i12 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i12 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i12++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_xNew[c8_s51dhbM5MSl1aKB4b1sqy0_i12] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i12];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i13 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i13 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i13++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_PNew[c8_s51dhbM5MSl1aKB4b1sqy0_i13] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_P[c8_s51dhbM5MSl1aKB4b1sqy0_i13];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i14 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i14 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i14++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_yMeas[c8_s51dhbM5MSl1aKB4b1sqy0_i14] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_yMeas[c8_s51dhbM5MSl1aKB4b1sqy0_i14];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i15 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i15 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i15++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_R[c8_s51dhbM5MSl1aKB4b1sqy0_i15] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_R[c8_s51dhbM5MSl1aKB4b1sqy0_i15];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_EKFCorrectorNonAdditive_correct(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_yMeas, c8_s51dhbM5MSl1aKB4b1sqy0_c_R,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_xNew, c8_s51dhbM5MSl1aKB4b1sqy0_c_PNew);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i16 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i16 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i16++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew[c8_s51dhbM5MSl1aKB4b1sqy0_i16] =
      c8_s51dhbM5MSl1aKB4b1sqy0_c_xNew[c8_s51dhbM5MSl1aKB4b1sqy0_i16];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i17 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i17 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i17++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew[c8_s51dhbM5MSl1aKB4b1sqy0_i17] =
      c8_s51dhbM5MSl1aKB4b1sqy0_c_PNew[c8_s51dhbM5MSl1aKB4b1sqy0_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i18 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i18 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i18++) {
    (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i18] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew[c8_s51dhbM5MSl1aKB4b1sqy0_i18];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i19 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i19 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i19++) {
    (*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i19] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew[c8_s51dhbM5MSl1aKB4b1sqy0_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i20 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i20 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i20], 4U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i21 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i21 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew)
                          [c8_s51dhbM5MSl1aKB4b1sqy0_i21], 5U, 1U, 0U,
                          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_sfEvent,
                          false);
  }
}

static void mdl_start_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_w[5], real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[5])
{
  _ssFcnCallExecArgInfo c8_s51dhbM5MSl1aKB4b1sqy0_args[3];
  c8_s51dhbM5MSl1aKB4b1sqy0_args[0U].dataPtr = (void *)
    c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
  c8_s51dhbM5MSl1aKB4b1sqy0_args[1U].dataPtr = (void *)
    c8_s51dhbM5MSl1aKB4b1sqy0_w;
  c8_s51dhbM5MSl1aKB4b1sqy0_args[2U].dataPtr = (void *)
    c8_s51dhbM5MSl1aKB4b1sqy0_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "measurementDroneFcn",
    &c8_s51dhbM5MSl1aKB4b1sqy0_args[0U]);
}

static void init_script_number_translation(uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_machineNumber, uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_chartNumber, uint32_T
  c8_s51dhbM5MSl1aKB4b1sqy0_instanceNumber)
{
  (void)(c8_s51dhbM5MSl1aKB4b1sqy0_machineNumber);
  (void)(c8_s51dhbM5MSl1aKB4b1sqy0_chartNumber);
  (void)(c8_s51dhbM5MSl1aKB4b1sqy0_instanceNumber);
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i22;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i23;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i24;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_u[144];
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_i22 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i23 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i23 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i23++) {
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i24 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i24 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i24++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_u[c8_s51dhbM5MSl1aKB4b1sqy0_i24 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i22] = (*(real_T (*)[144])
        c8_s51dhbM5MSl1aKB4b1sqy0_inData)[c8_s51dhbM5MSl1aKB4b1sqy0_i24 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i22];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i22 += 12;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew, const char_T
   *c8_s51dhbM5MSl1aKB4b1sqy0_identifier, real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[144])
{
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId,
    c8_s51dhbM5MSl1aKB4b1sqy0_y);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_b_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[144])
{
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dv2[144];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i25;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), c8_s51dhbM5MSl1aKB4b1sqy0_dv2, 1,
                0, 0U, 1, 0U, 2, 12, 12);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i25 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i25 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i25++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i25] =
      c8_s51dhbM5MSl1aKB4b1sqy0_dv2[c8_s51dhbM5MSl1aKB4b1sqy0_i25];
  }

  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew;
  const char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[144];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i26;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i27;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i28;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew = sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
  c8_s51dhbM5MSl1aKB4b1sqy0_identifier = c8_s51dhbM5MSl1aKB4b1sqy0_varName;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId,
    c8_s51dhbM5MSl1aKB4b1sqy0_y);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_PNew);
  c8_s51dhbM5MSl1aKB4b1sqy0_i26 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i27 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i27 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i27++) {
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i28 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i28 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i28++) {
      (*(real_T (*)[144])c8_s51dhbM5MSl1aKB4b1sqy0_outData)
        [c8_s51dhbM5MSl1aKB4b1sqy0_i28 + c8_s51dhbM5MSl1aKB4b1sqy0_i26] =
        c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i28 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i26];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i26 += 12;
  }

  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i29;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_u[12];
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i29 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i29 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i29++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_u[c8_s51dhbM5MSl1aKB4b1sqy0_i29] = (*(real_T (*)
      [12])c8_s51dhbM5MSl1aKB4b1sqy0_inData)[c8_s51dhbM5MSl1aKB4b1sqy0_i29];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_c_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew, const char_T
   *c8_s51dhbM5MSl1aKB4b1sqy0_identifier, real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[12])
{
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId,
    c8_s51dhbM5MSl1aKB4b1sqy0_y);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_d_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[12])
{
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dv3[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i30;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), c8_s51dhbM5MSl1aKB4b1sqy0_dv3, 1,
                0, 0U, 1, 0U, 1, 12);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i30 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i30 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i30++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i30] =
      c8_s51dhbM5MSl1aKB4b1sqy0_dv3[c8_s51dhbM5MSl1aKB4b1sqy0_i30];
  }

  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew;
  const char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i31;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew = sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
  c8_s51dhbM5MSl1aKB4b1sqy0_identifier = c8_s51dhbM5MSl1aKB4b1sqy0_varName;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId,
    c8_s51dhbM5MSl1aKB4b1sqy0_y);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_xNew);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i31 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i31 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i31++) {
    (*(real_T (*)[12])c8_s51dhbM5MSl1aKB4b1sqy0_outData)
      [c8_s51dhbM5MSl1aKB4b1sqy0_i31] =
      c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i31];
  }

  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i32;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i33;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i34;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_u[25];
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_i32 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i33 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i33 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i33++) {
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i34 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i34 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i34++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_u[c8_s51dhbM5MSl1aKB4b1sqy0_i34 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i32] = (*(real_T (*)[25])
        c8_s51dhbM5MSl1aKB4b1sqy0_inData)[c8_s51dhbM5MSl1aKB4b1sqy0_i34 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i32];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i32 += 5;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_u, 0, 0U, 1U, 0U, 2, 5, 5), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i35;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_u[5];
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i35 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i35 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i35++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_u[c8_s51dhbM5MSl1aKB4b1sqy0_i35] = (*(real_T (*)[5])
      c8_s51dhbM5MSl1aKB4b1sqy0_inData)[c8_s51dhbM5MSl1aKB4b1sqy0_i35];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_u;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_u = *(real_T *)c8_s51dhbM5MSl1aKB4b1sqy0_inData;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    &c8_s51dhbM5MSl1aKB4b1sqy0_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d0;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), &c8_s51dhbM5MSl1aKB4b1sqy0_d0, 1,
                0, 0U, 0, 0U, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_d0;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_nargout;
  const char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_nargout = sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
  c8_s51dhbM5MSl1aKB4b1sqy0_identifier = c8_s51dhbM5MSl1aKB4b1sqy0_varName;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_nargout),
     &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_nargout);
  *(real_T *)c8_s51dhbM5MSl1aKB4b1sqy0_outData = c8_s51dhbM5MSl1aKB4b1sqy0_y;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE c8_s51dhbM5MSl1aKB4b1sqy0_u;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i36;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_b_u[19];
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_c_u;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_d_y = NULL;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_d_u;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_e_y = NULL;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_u =
    *(c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE *)
    c8_s51dhbM5MSl1aKB4b1sqy0_inData;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_createstruct("structure", 2,
    1, 1), false);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i36 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i36 < 19;
       c8_s51dhbM5MSl1aKB4b1sqy0_i36++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_u[c8_s51dhbM5MSl1aKB4b1sqy0_i36] =
      c8_s51dhbM5MSl1aKB4b1sqy0_u.FcnName[c8_s51dhbM5MSl1aKB4b1sqy0_i36];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_b_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_b_u, 10, 0U, 1U, 0U, 2, 1, 19), false);
  sf_mex_addfield(c8_s51dhbM5MSl1aKB4b1sqy0_y, c8_s51dhbM5MSl1aKB4b1sqy0_b_y,
                  "FcnName", "FcnName", 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_c_y, sf_mex_create("y", NULL, 10, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_addfield(c8_s51dhbM5MSl1aKB4b1sqy0_y, c8_s51dhbM5MSl1aKB4b1sqy0_c_y,
                  "JacobianFcnName", "JacobianFcnName", 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_c_u = c8_s51dhbM5MSl1aKB4b1sqy0_u.HasJacobian;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_d_y, sf_mex_create("y",
    &c8_s51dhbM5MSl1aKB4b1sqy0_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_s51dhbM5MSl1aKB4b1sqy0_y, c8_s51dhbM5MSl1aKB4b1sqy0_d_y,
                  "HasJacobian", "HasJacobian", 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_d_u = c8_s51dhbM5MSl1aKB4b1sqy0_u.HasAdditiveNoise;
  c8_s51dhbM5MSl1aKB4b1sqy0_e_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_e_y, sf_mex_create("y",
    &c8_s51dhbM5MSl1aKB4b1sqy0_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_s51dhbM5MSl1aKB4b1sqy0_y, c8_s51dhbM5MSl1aKB4b1sqy0_e_y,
                  "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  (void)c8_s51dhbM5MSl1aKB4b1sqy0_inData;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y", NULL, 0, 0U, 1U,
    0U, 2, 0, 0), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

const mxArray
  *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_nameCaptureInfo = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_nameCaptureInfo, sf_mex_create(
    "nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1), false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_nameCaptureInfo;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_EKFCorrectorNonAdditive_correct
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_zcov[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12],
   real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_P[144], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_c_x[12], real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_P[144])
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i37;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i38;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i39;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i40;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_z[5];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_zcov[25];
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i37 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i37 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i37++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_x[c8_s51dhbM5MSl1aKB4b1sqy0_i37] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i37];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i38 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i38 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i38++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_P[c8_s51dhbM5MSl1aKB4b1sqy0_i38] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_P[c8_s51dhbM5MSl1aKB4b1sqy0_i38];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i39 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i39 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i39++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_z[c8_s51dhbM5MSl1aKB4b1sqy0_i39] =
      c8_s51dhbM5MSl1aKB4b1sqy0_z[c8_s51dhbM5MSl1aKB4b1sqy0_i39];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i40 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i40 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i40++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_zcov[c8_s51dhbM5MSl1aKB4b1sqy0_i40] =
      c8_s51dhbM5MSl1aKB4b1sqy0_zcov[c8_s51dhbM5MSl1aKB4b1sqy0_i40];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_EKFCorrectorNonAdditive_correct(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_b_z, c8_s51dhbM5MSl1aKB4b1sqy0_b_zcov,
    c8_s51dhbM5MSl1aKB4b1sqy0_c_x, c8_s51dhbM5MSl1aKB4b1sqy0_c_P);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_numericJacobian
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_s51dhbM5MSl1aKB4b1sqy0_cell_2
   *c8_s51dhbM5MSl1aKB4b1sqy0_vec, real_T c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[60])
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i41;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i42;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_imvec[12];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2[5];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5];
  c8_s51dhbM5MSl1aKB4b1sqy0_cell_2 c8_s51dhbM5MSl1aKB4b1sqy0_specvec;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_j;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i43;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_varargin_2;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_maxval;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i44;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i45;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i46;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_imz[5];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i47;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_B;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_f_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i48;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i41 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i41 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i41++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i41] =
      c8_s51dhbM5MSl1aKB4b1sqy0_vec->f1[c8_s51dhbM5MSl1aKB4b1sqy0_i41];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i42 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i42 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i42++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2[c8_s51dhbM5MSl1aKB4b1sqy0_i42] =
      c8_s51dhbM5MSl1aKB4b1sqy0_vec->f2[c8_s51dhbM5MSl1aKB4b1sqy0_i42];
  }

  CV_EML_FCN(0, 6);
  c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_imvec, c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2,
    c8_s51dhbM5MSl1aKB4b1sqy0_z);
  c8_s51dhbM5MSl1aKB4b1sqy0_specvec = *c8_s51dhbM5MSl1aKB4b1sqy0_vec;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_j = 0; c8_s51dhbM5MSl1aKB4b1sqy0_j < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_j++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_j = 1.0 + (real_T)c8_s51dhbM5MSl1aKB4b1sqy0_j;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i43 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i43 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i43++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i43] =
        c8_s51dhbM5MSl1aKB4b1sqy0_vec->f1[c8_s51dhbM5MSl1aKB4b1sqy0_i43];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_b_x =
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 12) - 1];
    c8_s51dhbM5MSl1aKB4b1sqy0_c_x = c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_x = c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
    c8_s51dhbM5MSl1aKB4b1sqy0_y = muDoubleScalarAbs
      (c8_s51dhbM5MSl1aKB4b1sqy0_d_x);
    c8_s51dhbM5MSl1aKB4b1sqy0_b_varargin_2 = 1.4901161193847656E-8 *
      c8_s51dhbM5MSl1aKB4b1sqy0_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3 =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_varargin_2;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_y = c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_y = c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_y = c8_s51dhbM5MSl1aKB4b1sqy0_c_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_s51dhbM5MSl1aKB4b1sqy0_d_y);
    c8_s51dhbM5MSl1aKB4b1sqy0_epsilon = c8_s51dhbM5MSl1aKB4b1sqy0_maxval;
    c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 12) - 1] =
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 12) - 1] +
      c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i44 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i44 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i44++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f1[c8_s51dhbM5MSl1aKB4b1sqy0_i44] =
        c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i44];
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_i45 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i45 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i45++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i45] =
        c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f1[c8_s51dhbM5MSl1aKB4b1sqy0_i45];
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_i46 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i46 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i46++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2[c8_s51dhbM5MSl1aKB4b1sqy0_i46] =
        c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f2[c8_s51dhbM5MSl1aKB4b1sqy0_i46];
    }

    CV_EML_FCN(0, 6);
    c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke(chartInstance,
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec, c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2,
      c8_s51dhbM5MSl1aKB4b1sqy0_imz);
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i47 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i47 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i47++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imz[c8_s51dhbM5MSl1aKB4b1sqy0_i47] -=
        c8_s51dhbM5MSl1aKB4b1sqy0_z[c8_s51dhbM5MSl1aKB4b1sqy0_i47];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_B = c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_y = c8_s51dhbM5MSl1aKB4b1sqy0_B;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_y = c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 12) - 1;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i48 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i48 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i48++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[c8_s51dhbM5MSl1aKB4b1sqy0_i48 + 5 *
        c8_s51dhbM5MSl1aKB4b1sqy0_c_j] =
        c8_s51dhbM5MSl1aKB4b1sqy0_imz[c8_s51dhbM5MSl1aKB4b1sqy0_i48] /
        c8_s51dhbM5MSl1aKB4b1sqy0_f_y;
    }
  }
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_b_numericJacobian
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_s51dhbM5MSl1aKB4b1sqy0_cell_2
   *c8_s51dhbM5MSl1aKB4b1sqy0_vec, real_T c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[25])
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i49;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i50;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_varargin_1[12];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_imvec[5];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5];
  c8_s51dhbM5MSl1aKB4b1sqy0_cell_2 c8_s51dhbM5MSl1aKB4b1sqy0_specvec;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_j;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i51;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_maxval;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i52;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i53;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i54;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_imz[5];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i55;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_B;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_f_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i56;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i49 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i49 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i49++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_1[c8_s51dhbM5MSl1aKB4b1sqy0_i49] =
      c8_s51dhbM5MSl1aKB4b1sqy0_vec->f1[c8_s51dhbM5MSl1aKB4b1sqy0_i49];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i50 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i50 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i50++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i50] =
      c8_s51dhbM5MSl1aKB4b1sqy0_vec->f2[c8_s51dhbM5MSl1aKB4b1sqy0_i50];
  }

  CV_EML_FCN(0, 6);
  c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_1, c8_s51dhbM5MSl1aKB4b1sqy0_imvec,
    c8_s51dhbM5MSl1aKB4b1sqy0_z);
  c8_s51dhbM5MSl1aKB4b1sqy0_specvec = *c8_s51dhbM5MSl1aKB4b1sqy0_vec;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_j = 0; c8_s51dhbM5MSl1aKB4b1sqy0_j < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_j++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_j = 1.0 + (real_T)c8_s51dhbM5MSl1aKB4b1sqy0_j;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i51 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i51 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i51++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i51] =
        c8_s51dhbM5MSl1aKB4b1sqy0_vec->f2[c8_s51dhbM5MSl1aKB4b1sqy0_i51];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_b_x =
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 5) - 1];
    c8_s51dhbM5MSl1aKB4b1sqy0_c_x = c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_x = c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
    c8_s51dhbM5MSl1aKB4b1sqy0_y = muDoubleScalarAbs
      (c8_s51dhbM5MSl1aKB4b1sqy0_d_x);
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2 = 1.4901161193847656E-8 *
      c8_s51dhbM5MSl1aKB4b1sqy0_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3 = c8_s51dhbM5MSl1aKB4b1sqy0_varargin_2;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_y = c8_s51dhbM5MSl1aKB4b1sqy0_varargin_3;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_y = c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_y = c8_s51dhbM5MSl1aKB4b1sqy0_c_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_s51dhbM5MSl1aKB4b1sqy0_d_y);
    c8_s51dhbM5MSl1aKB4b1sqy0_epsilon = c8_s51dhbM5MSl1aKB4b1sqy0_maxval;
    c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 5) - 1] =
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 5) - 1] +
      c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i52 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i52 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i52++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f2[c8_s51dhbM5MSl1aKB4b1sqy0_i52] =
        c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i52];
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_i53 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i53 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i53++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_varargin_1[c8_s51dhbM5MSl1aKB4b1sqy0_i53] =
        c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f1[c8_s51dhbM5MSl1aKB4b1sqy0_i53];
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_i54 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i54 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i54++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imvec[c8_s51dhbM5MSl1aKB4b1sqy0_i54] =
        c8_s51dhbM5MSl1aKB4b1sqy0_specvec.f2[c8_s51dhbM5MSl1aKB4b1sqy0_i54];
    }

    CV_EML_FCN(0, 6);
    c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke(chartInstance,
      c8_s51dhbM5MSl1aKB4b1sqy0_varargin_1, c8_s51dhbM5MSl1aKB4b1sqy0_imvec,
      c8_s51dhbM5MSl1aKB4b1sqy0_imz);
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i55 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i55 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i55++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_imz[c8_s51dhbM5MSl1aKB4b1sqy0_i55] -=
        c8_s51dhbM5MSl1aKB4b1sqy0_z[c8_s51dhbM5MSl1aKB4b1sqy0_i55];
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_B = c8_s51dhbM5MSl1aKB4b1sqy0_epsilon;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_y = c8_s51dhbM5MSl1aKB4b1sqy0_B;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_y = c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_j), 1, 5) - 1;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i56 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i56 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i56++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_jacobian[c8_s51dhbM5MSl1aKB4b1sqy0_i56 + 5 *
        c8_s51dhbM5MSl1aKB4b1sqy0_c_j] =
        c8_s51dhbM5MSl1aKB4b1sqy0_imz[c8_s51dhbM5MSl1aKB4b1sqy0_i56] /
        c8_s51dhbM5MSl1aKB4b1sqy0_f_y;
    }
  }
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_mrdivide
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_A[60], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_B[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[60])
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i57;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i58;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_A[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_info;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_ipiv[5];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jm1;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_info;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_mmj;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i59;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jj;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jp1j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jBcol;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_n;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jAcol;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i60;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_n;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_xj;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_jBcol;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_jAcol;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i61;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_idxmax;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_b_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jp;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_ix;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_xi;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_k;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_k;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_a;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_b;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_temp;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_kBcol;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jpiv;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_kBcol;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_temp;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_i;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_f_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_i;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_g_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_g_a;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_h_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_h_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_g_b;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_c;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_smax;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_j_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_h_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_j_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_k_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_k_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i62;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jrow;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_c_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_g_c;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_l_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_m_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_m;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_l_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_m_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_n;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_n_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jprow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_k;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_n_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_iy0;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_d_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_iy0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_ia0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_o_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_m;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_iy0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_n;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_i;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_ix;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_i_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_iy;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_j_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_iy0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_k;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_k_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_b_ia0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_l_x;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_m_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_m;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_f_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_n;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_z;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_temp;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_n_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_g_ix0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_o_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_e_iy0;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_p_x;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_ia0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_p_a;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_g_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_m;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_s;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_n;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_q_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_h_ix0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_iy0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_ia0;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_r_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_jy;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_o_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_p_b;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_e_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_d_j;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_yjy;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_temp;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_s_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_c_ix;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_q_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_t_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i63;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_u_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_r_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i64;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_v_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_s_b;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_w_a;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_t_b;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_f_overflow;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_ijA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_x_a;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i57 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i57 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i57++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_i57] =
      c8_s51dhbM5MSl1aKB4b1sqy0_B[c8_s51dhbM5MSl1aKB4b1sqy0_i57];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i58 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i58 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i58++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_ipiv[c8_s51dhbM5MSl1aKB4b1sqy0_i58] = 1 +
      c8_s51dhbM5MSl1aKB4b1sqy0_i58;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_info = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_j = 1; c8_s51dhbM5MSl1aKB4b1sqy0_j < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_j++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_a = c8_s51dhbM5MSl1aKB4b1sqy0_j - 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_jm1 = c8_s51dhbM5MSl1aKB4b1sqy0_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_b = c8_s51dhbM5MSl1aKB4b1sqy0_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_mmj = 5 - c8_s51dhbM5MSl1aKB4b1sqy0_b;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_a = c8_s51dhbM5MSl1aKB4b1sqy0_jm1;
    c8_s51dhbM5MSl1aKB4b1sqy0_c = c8_s51dhbM5MSl1aKB4b1sqy0_b_a * 6;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_b = c8_s51dhbM5MSl1aKB4b1sqy0_c + 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_jj = c8_s51dhbM5MSl1aKB4b1sqy0_b_b;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_a = c8_s51dhbM5MSl1aKB4b1sqy0_jj + 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_jp1j = c8_s51dhbM5MSl1aKB4b1sqy0_c_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_a = c8_s51dhbM5MSl1aKB4b1sqy0_mmj + 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_c = c8_s51dhbM5MSl1aKB4b1sqy0_d_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_n = c8_s51dhbM5MSl1aKB4b1sqy0_b_c;
    c8_s51dhbM5MSl1aKB4b1sqy0_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_jj;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_n = c8_s51dhbM5MSl1aKB4b1sqy0_n;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_ix0;
    if (c8_s51dhbM5MSl1aKB4b1sqy0_b_n < 1) {
      c8_s51dhbM5MSl1aKB4b1sqy0_idxmax = 0;
    } else {
      c8_s51dhbM5MSl1aKB4b1sqy0_idxmax = 1;
      if (c8_s51dhbM5MSl1aKB4b1sqy0_b_n > 1) {
        c8_s51dhbM5MSl1aKB4b1sqy0_ix = c8_s51dhbM5MSl1aKB4b1sqy0_b_ix0;
        c8_s51dhbM5MSl1aKB4b1sqy0_b_x =
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_ix0 - 1];
        c8_s51dhbM5MSl1aKB4b1sqy0_c_x = c8_s51dhbM5MSl1aKB4b1sqy0_b_x;
        c8_s51dhbM5MSl1aKB4b1sqy0_d_x = c8_s51dhbM5MSl1aKB4b1sqy0_c_x;
        c8_s51dhbM5MSl1aKB4b1sqy0_e_x = c8_s51dhbM5MSl1aKB4b1sqy0_d_x;
        c8_s51dhbM5MSl1aKB4b1sqy0_c_y = muDoubleScalarAbs
          (c8_s51dhbM5MSl1aKB4b1sqy0_e_x);
        c8_s51dhbM5MSl1aKB4b1sqy0_f_x = 0.0;
        c8_s51dhbM5MSl1aKB4b1sqy0_g_x = c8_s51dhbM5MSl1aKB4b1sqy0_f_x;
        c8_s51dhbM5MSl1aKB4b1sqy0_h_x = c8_s51dhbM5MSl1aKB4b1sqy0_g_x;
        c8_s51dhbM5MSl1aKB4b1sqy0_d_y = muDoubleScalarAbs
          (c8_s51dhbM5MSl1aKB4b1sqy0_h_x);
        c8_s51dhbM5MSl1aKB4b1sqy0_smax = c8_s51dhbM5MSl1aKB4b1sqy0_c_y +
          c8_s51dhbM5MSl1aKB4b1sqy0_d_y;
        c8_s51dhbM5MSl1aKB4b1sqy0_h_b = c8_s51dhbM5MSl1aKB4b1sqy0_b_n;
        c8_s51dhbM5MSl1aKB4b1sqy0_k_b = c8_s51dhbM5MSl1aKB4b1sqy0_h_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_c_overflow = ((!(2 >
          c8_s51dhbM5MSl1aKB4b1sqy0_k_b)) && (c8_s51dhbM5MSl1aKB4b1sqy0_k_b >
          2147483646));
        if (c8_s51dhbM5MSl1aKB4b1sqy0_c_overflow) {
          c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
            c8_s51dhbM5MSl1aKB4b1sqy0_c_overflow);
        }

        for (c8_s51dhbM5MSl1aKB4b1sqy0_c_k = 2; c8_s51dhbM5MSl1aKB4b1sqy0_c_k <=
             c8_s51dhbM5MSl1aKB4b1sqy0_b_n; c8_s51dhbM5MSl1aKB4b1sqy0_c_k++) {
          c8_s51dhbM5MSl1aKB4b1sqy0_o_a = c8_s51dhbM5MSl1aKB4b1sqy0_ix + 1;
          c8_s51dhbM5MSl1aKB4b1sqy0_ix = c8_s51dhbM5MSl1aKB4b1sqy0_o_a;
          c8_s51dhbM5MSl1aKB4b1sqy0_i_x =
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_ix - 1];
          c8_s51dhbM5MSl1aKB4b1sqy0_j_x = c8_s51dhbM5MSl1aKB4b1sqy0_i_x;
          c8_s51dhbM5MSl1aKB4b1sqy0_k_x = c8_s51dhbM5MSl1aKB4b1sqy0_j_x;
          c8_s51dhbM5MSl1aKB4b1sqy0_m_x = c8_s51dhbM5MSl1aKB4b1sqy0_k_x;
          c8_s51dhbM5MSl1aKB4b1sqy0_f_y = muDoubleScalarAbs
            (c8_s51dhbM5MSl1aKB4b1sqy0_m_x);
          c8_s51dhbM5MSl1aKB4b1sqy0_n_x = 0.0;
          c8_s51dhbM5MSl1aKB4b1sqy0_o_x = c8_s51dhbM5MSl1aKB4b1sqy0_n_x;
          c8_s51dhbM5MSl1aKB4b1sqy0_p_x = c8_s51dhbM5MSl1aKB4b1sqy0_o_x;
          c8_s51dhbM5MSl1aKB4b1sqy0_g_y = muDoubleScalarAbs
            (c8_s51dhbM5MSl1aKB4b1sqy0_p_x);
          c8_s51dhbM5MSl1aKB4b1sqy0_s = c8_s51dhbM5MSl1aKB4b1sqy0_f_y +
            c8_s51dhbM5MSl1aKB4b1sqy0_g_y;
          if (c8_s51dhbM5MSl1aKB4b1sqy0_s > c8_s51dhbM5MSl1aKB4b1sqy0_smax) {
            c8_s51dhbM5MSl1aKB4b1sqy0_idxmax = c8_s51dhbM5MSl1aKB4b1sqy0_c_k;
            c8_s51dhbM5MSl1aKB4b1sqy0_smax = c8_s51dhbM5MSl1aKB4b1sqy0_s;
          }
        }
      }
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_e_a = c8_s51dhbM5MSl1aKB4b1sqy0_idxmax - 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset = c8_s51dhbM5MSl1aKB4b1sqy0_e_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_a = c8_s51dhbM5MSl1aKB4b1sqy0_jj;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_b = c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset;
    c8_s51dhbM5MSl1aKB4b1sqy0_jpiv = (c8_s51dhbM5MSl1aKB4b1sqy0_f_a +
      c8_s51dhbM5MSl1aKB4b1sqy0_e_b) - 1;
    if (c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_jpiv] != 0.0) {
      if (c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset != 0) {
        c8_s51dhbM5MSl1aKB4b1sqy0_g_a = c8_s51dhbM5MSl1aKB4b1sqy0_j;
        c8_s51dhbM5MSl1aKB4b1sqy0_g_b = c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset;
        c8_s51dhbM5MSl1aKB4b1sqy0_e_c = c8_s51dhbM5MSl1aKB4b1sqy0_g_a +
          c8_s51dhbM5MSl1aKB4b1sqy0_g_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_ipiv[c8_s51dhbM5MSl1aKB4b1sqy0_j - 1] =
          c8_s51dhbM5MSl1aKB4b1sqy0_e_c;
        c8_s51dhbM5MSl1aKB4b1sqy0_j_b = c8_s51dhbM5MSl1aKB4b1sqy0_jm1 + 1;
        c8_s51dhbM5MSl1aKB4b1sqy0_jrow = c8_s51dhbM5MSl1aKB4b1sqy0_j_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_m_a = c8_s51dhbM5MSl1aKB4b1sqy0_jrow;
        c8_s51dhbM5MSl1aKB4b1sqy0_m_b = c8_s51dhbM5MSl1aKB4b1sqy0_jpiv_offset;
        c8_s51dhbM5MSl1aKB4b1sqy0_jprow = c8_s51dhbM5MSl1aKB4b1sqy0_m_a +
          c8_s51dhbM5MSl1aKB4b1sqy0_m_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_d_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_jrow;
        c8_s51dhbM5MSl1aKB4b1sqy0_b_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_jprow;
        c8_s51dhbM5MSl1aKB4b1sqy0_e_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_d_ix0;
        c8_s51dhbM5MSl1aKB4b1sqy0_c_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_b_iy0;
        c8_s51dhbM5MSl1aKB4b1sqy0_b_ix = c8_s51dhbM5MSl1aKB4b1sqy0_e_ix0;
        c8_s51dhbM5MSl1aKB4b1sqy0_iy = c8_s51dhbM5MSl1aKB4b1sqy0_c_iy0;
        for (c8_s51dhbM5MSl1aKB4b1sqy0_d_k = 1; c8_s51dhbM5MSl1aKB4b1sqy0_d_k <
             6; c8_s51dhbM5MSl1aKB4b1sqy0_d_k++) {
          c8_s51dhbM5MSl1aKB4b1sqy0_c_temp =
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_ix - 1];
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_ix - 1] =
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_iy - 1];
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_iy - 1] =
            c8_s51dhbM5MSl1aKB4b1sqy0_c_temp;
          c8_s51dhbM5MSl1aKB4b1sqy0_p_a = c8_s51dhbM5MSl1aKB4b1sqy0_b_ix + 5;
          c8_s51dhbM5MSl1aKB4b1sqy0_b_ix = c8_s51dhbM5MSl1aKB4b1sqy0_p_a;
          c8_s51dhbM5MSl1aKB4b1sqy0_q_a = c8_s51dhbM5MSl1aKB4b1sqy0_iy + 5;
          c8_s51dhbM5MSl1aKB4b1sqy0_iy = c8_s51dhbM5MSl1aKB4b1sqy0_q_a;
        }
      }

      c8_s51dhbM5MSl1aKB4b1sqy0_h_a = c8_s51dhbM5MSl1aKB4b1sqy0_mmj - 1;
      c8_s51dhbM5MSl1aKB4b1sqy0_d_c = c8_s51dhbM5MSl1aKB4b1sqy0_h_a;
      c8_s51dhbM5MSl1aKB4b1sqy0_j_a = c8_s51dhbM5MSl1aKB4b1sqy0_jp1j;
      c8_s51dhbM5MSl1aKB4b1sqy0_i_b = c8_s51dhbM5MSl1aKB4b1sqy0_d_c;
      c8_s51dhbM5MSl1aKB4b1sqy0_i62 = c8_s51dhbM5MSl1aKB4b1sqy0_j_a +
        c8_s51dhbM5MSl1aKB4b1sqy0_i_b;
      c8_s51dhbM5MSl1aKB4b1sqy0_l_a = c8_s51dhbM5MSl1aKB4b1sqy0_jp1j;
      c8_s51dhbM5MSl1aKB4b1sqy0_l_b = c8_s51dhbM5MSl1aKB4b1sqy0_i62;
      c8_s51dhbM5MSl1aKB4b1sqy0_n_a = c8_s51dhbM5MSl1aKB4b1sqy0_l_a;
      c8_s51dhbM5MSl1aKB4b1sqy0_n_b = c8_s51dhbM5MSl1aKB4b1sqy0_l_b;
      c8_s51dhbM5MSl1aKB4b1sqy0_d_overflow = ((!(c8_s51dhbM5MSl1aKB4b1sqy0_n_a >
        c8_s51dhbM5MSl1aKB4b1sqy0_n_b)) && (c8_s51dhbM5MSl1aKB4b1sqy0_n_b >
        2147483646));
      if (c8_s51dhbM5MSl1aKB4b1sqy0_d_overflow) {
        c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
          c8_s51dhbM5MSl1aKB4b1sqy0_d_overflow);
      }

      for (c8_s51dhbM5MSl1aKB4b1sqy0_d_i = c8_s51dhbM5MSl1aKB4b1sqy0_jp1j - 1;
           c8_s51dhbM5MSl1aKB4b1sqy0_d_i + 1 <= c8_s51dhbM5MSl1aKB4b1sqy0_i62;
           c8_s51dhbM5MSl1aKB4b1sqy0_d_i++) {
        c8_s51dhbM5MSl1aKB4b1sqy0_l_x =
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_d_i];
        c8_s51dhbM5MSl1aKB4b1sqy0_e_y =
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_jj - 1];
        c8_s51dhbM5MSl1aKB4b1sqy0_z = c8_s51dhbM5MSl1aKB4b1sqy0_l_x /
          c8_s51dhbM5MSl1aKB4b1sqy0_e_y;
        c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_d_i] =
          c8_s51dhbM5MSl1aKB4b1sqy0_z;
      }
    } else {
      c8_s51dhbM5MSl1aKB4b1sqy0_info = c8_s51dhbM5MSl1aKB4b1sqy0_j;
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_f_b = c8_s51dhbM5MSl1aKB4b1sqy0_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_c = 5 - c8_s51dhbM5MSl1aKB4b1sqy0_f_b;
    c8_s51dhbM5MSl1aKB4b1sqy0_i_a = c8_s51dhbM5MSl1aKB4b1sqy0_jj + 5;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_c = c8_s51dhbM5MSl1aKB4b1sqy0_i_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_k_a = c8_s51dhbM5MSl1aKB4b1sqy0_jj + 6;
    c8_s51dhbM5MSl1aKB4b1sqy0_g_c = c8_s51dhbM5MSl1aKB4b1sqy0_k_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_m = c8_s51dhbM5MSl1aKB4b1sqy0_mmj;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_n = c8_s51dhbM5MSl1aKB4b1sqy0_c_c;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_jp1j;
    c8_s51dhbM5MSl1aKB4b1sqy0_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_f_c;
    c8_s51dhbM5MSl1aKB4b1sqy0_ia0 = c8_s51dhbM5MSl1aKB4b1sqy0_g_c;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_m = c8_s51dhbM5MSl1aKB4b1sqy0_m;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_n = c8_s51dhbM5MSl1aKB4b1sqy0_c_n;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_c_ix0;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_iy0;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_ia0 = c8_s51dhbM5MSl1aKB4b1sqy0_ia0;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_m = c8_s51dhbM5MSl1aKB4b1sqy0_b_m;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_n = c8_s51dhbM5MSl1aKB4b1sqy0_d_n;
    c8_s51dhbM5MSl1aKB4b1sqy0_g_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_f_ix0;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_d_iy0;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_ia0 = c8_s51dhbM5MSl1aKB4b1sqy0_b_ia0;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_m = c8_s51dhbM5MSl1aKB4b1sqy0_c_m;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_n = c8_s51dhbM5MSl1aKB4b1sqy0_e_n;
    c8_s51dhbM5MSl1aKB4b1sqy0_h_ix0 = c8_s51dhbM5MSl1aKB4b1sqy0_g_ix0;
    c8_s51dhbM5MSl1aKB4b1sqy0_f_iy0 = c8_s51dhbM5MSl1aKB4b1sqy0_e_iy0;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_ia0 = c8_s51dhbM5MSl1aKB4b1sqy0_c_ia0;
    c8_s51dhbM5MSl1aKB4b1sqy0_r_a = c8_s51dhbM5MSl1aKB4b1sqy0_d_ia0 - 1;
    c8_s51dhbM5MSl1aKB4b1sqy0_jA = c8_s51dhbM5MSl1aKB4b1sqy0_r_a;
    c8_s51dhbM5MSl1aKB4b1sqy0_jy = c8_s51dhbM5MSl1aKB4b1sqy0_f_iy0;
    c8_s51dhbM5MSl1aKB4b1sqy0_o_b = c8_s51dhbM5MSl1aKB4b1sqy0_f_n;
    c8_s51dhbM5MSl1aKB4b1sqy0_p_b = c8_s51dhbM5MSl1aKB4b1sqy0_o_b;
    c8_s51dhbM5MSl1aKB4b1sqy0_e_overflow = ((!(1 > c8_s51dhbM5MSl1aKB4b1sqy0_p_b))
      && (c8_s51dhbM5MSl1aKB4b1sqy0_p_b > 2147483646));
    if (c8_s51dhbM5MSl1aKB4b1sqy0_e_overflow) {
      c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
        c8_s51dhbM5MSl1aKB4b1sqy0_e_overflow);
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_d_j = 1; c8_s51dhbM5MSl1aKB4b1sqy0_d_j <=
         c8_s51dhbM5MSl1aKB4b1sqy0_f_n; c8_s51dhbM5MSl1aKB4b1sqy0_d_j++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_yjy =
        c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_jy - 1];
      if (c8_s51dhbM5MSl1aKB4b1sqy0_yjy != 0.0) {
        c8_s51dhbM5MSl1aKB4b1sqy0_d_temp = -c8_s51dhbM5MSl1aKB4b1sqy0_yjy;
        c8_s51dhbM5MSl1aKB4b1sqy0_c_ix = c8_s51dhbM5MSl1aKB4b1sqy0_h_ix0;
        c8_s51dhbM5MSl1aKB4b1sqy0_q_b = c8_s51dhbM5MSl1aKB4b1sqy0_jA + 1;
        c8_s51dhbM5MSl1aKB4b1sqy0_i63 = c8_s51dhbM5MSl1aKB4b1sqy0_q_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_u_a = c8_s51dhbM5MSl1aKB4b1sqy0_d_m;
        c8_s51dhbM5MSl1aKB4b1sqy0_r_b = c8_s51dhbM5MSl1aKB4b1sqy0_jA;
        c8_s51dhbM5MSl1aKB4b1sqy0_i64 = c8_s51dhbM5MSl1aKB4b1sqy0_u_a +
          c8_s51dhbM5MSl1aKB4b1sqy0_r_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_v_a = c8_s51dhbM5MSl1aKB4b1sqy0_i63;
        c8_s51dhbM5MSl1aKB4b1sqy0_s_b = c8_s51dhbM5MSl1aKB4b1sqy0_i64;
        c8_s51dhbM5MSl1aKB4b1sqy0_w_a = c8_s51dhbM5MSl1aKB4b1sqy0_v_a;
        c8_s51dhbM5MSl1aKB4b1sqy0_t_b = c8_s51dhbM5MSl1aKB4b1sqy0_s_b;
        c8_s51dhbM5MSl1aKB4b1sqy0_f_overflow = ((!(c8_s51dhbM5MSl1aKB4b1sqy0_w_a
          > c8_s51dhbM5MSl1aKB4b1sqy0_t_b)) && (c8_s51dhbM5MSl1aKB4b1sqy0_t_b >
          2147483646));
        if (c8_s51dhbM5MSl1aKB4b1sqy0_f_overflow) {
          c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
            c8_s51dhbM5MSl1aKB4b1sqy0_f_overflow);
        }

        for (c8_s51dhbM5MSl1aKB4b1sqy0_ijA = c8_s51dhbM5MSl1aKB4b1sqy0_i63 - 1;
             c8_s51dhbM5MSl1aKB4b1sqy0_ijA + 1 <= c8_s51dhbM5MSl1aKB4b1sqy0_i64;
             c8_s51dhbM5MSl1aKB4b1sqy0_ijA++) {
          c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_ijA] +=
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_c_ix - 1] *
            c8_s51dhbM5MSl1aKB4b1sqy0_d_temp;
          c8_s51dhbM5MSl1aKB4b1sqy0_x_a = c8_s51dhbM5MSl1aKB4b1sqy0_c_ix + 1;
          c8_s51dhbM5MSl1aKB4b1sqy0_c_ix = c8_s51dhbM5MSl1aKB4b1sqy0_x_a;
        }
      }

      c8_s51dhbM5MSl1aKB4b1sqy0_s_a = c8_s51dhbM5MSl1aKB4b1sqy0_jy + 5;
      c8_s51dhbM5MSl1aKB4b1sqy0_jy = c8_s51dhbM5MSl1aKB4b1sqy0_s_a;
      c8_s51dhbM5MSl1aKB4b1sqy0_t_a = c8_s51dhbM5MSl1aKB4b1sqy0_jA + 5;
      c8_s51dhbM5MSl1aKB4b1sqy0_jA = c8_s51dhbM5MSl1aKB4b1sqy0_t_a;
    }
  }

  if (((real_T)c8_s51dhbM5MSl1aKB4b1sqy0_info == 0.0) &&
      (!(c8_s51dhbM5MSl1aKB4b1sqy0_b_A[24] != 0.0))) {
    c8_s51dhbM5MSl1aKB4b1sqy0_info = 5;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_info = c8_s51dhbM5MSl1aKB4b1sqy0_info;
  if ((real_T)c8_s51dhbM5MSl1aKB4b1sqy0_b_info > 0.0) {
    c8_s51dhbM5MSl1aKB4b1sqy0_warning(chartInstance);
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i59 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i59 < 60;
       c8_s51dhbM5MSl1aKB4b1sqy0_i59++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i59] =
      c8_s51dhbM5MSl1aKB4b1sqy0_A[c8_s51dhbM5MSl1aKB4b1sqy0_i59];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_b_j = 0; c8_s51dhbM5MSl1aKB4b1sqy0_b_j + 1 < 6;
       c8_s51dhbM5MSl1aKB4b1sqy0_b_j++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_jBcol = 12 * c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_jAcol = 5 * c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_i60 = c8_s51dhbM5MSl1aKB4b1sqy0_b_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_c_b = c8_s51dhbM5MSl1aKB4b1sqy0_i60;
    c8_s51dhbM5MSl1aKB4b1sqy0_d_b = c8_s51dhbM5MSl1aKB4b1sqy0_c_b;
    c8_s51dhbM5MSl1aKB4b1sqy0_overflow = ((!(1 > c8_s51dhbM5MSl1aKB4b1sqy0_d_b))
      && (c8_s51dhbM5MSl1aKB4b1sqy0_d_b > 2147483646));
    if (c8_s51dhbM5MSl1aKB4b1sqy0_overflow) {
      c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
        c8_s51dhbM5MSl1aKB4b1sqy0_overflow);
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_k = 0; c8_s51dhbM5MSl1aKB4b1sqy0_k + 1 <=
         c8_s51dhbM5MSl1aKB4b1sqy0_i60; c8_s51dhbM5MSl1aKB4b1sqy0_k++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_kBcol = 12 * c8_s51dhbM5MSl1aKB4b1sqy0_k;
      if (c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_k +
          c8_s51dhbM5MSl1aKB4b1sqy0_jAcol] != 0.0) {
        for (c8_s51dhbM5MSl1aKB4b1sqy0_b_i = 0; c8_s51dhbM5MSl1aKB4b1sqy0_b_i +
             1 < 13; c8_s51dhbM5MSl1aKB4b1sqy0_b_i++) {
          c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_b_i +
            c8_s51dhbM5MSl1aKB4b1sqy0_jBcol] -=
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_k +
            c8_s51dhbM5MSl1aKB4b1sqy0_jAcol] *
            c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_b_i +
            c8_s51dhbM5MSl1aKB4b1sqy0_kBcol];
        }
      }
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_b_y =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_j +
      c8_s51dhbM5MSl1aKB4b1sqy0_jAcol];
    c8_s51dhbM5MSl1aKB4b1sqy0_b_temp = 1.0 / c8_s51dhbM5MSl1aKB4b1sqy0_b_y;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i + 1 < 13;
         c8_s51dhbM5MSl1aKB4b1sqy0_i++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i +
        c8_s51dhbM5MSl1aKB4b1sqy0_jBcol] *= c8_s51dhbM5MSl1aKB4b1sqy0_b_temp;
    }
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_c_j = 4; c8_s51dhbM5MSl1aKB4b1sqy0_c_j + 1 > 0;
       c8_s51dhbM5MSl1aKB4b1sqy0_c_j--) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_jBcol = 12 * c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_jAcol = 5 * c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_i61 = c8_s51dhbM5MSl1aKB4b1sqy0_c_j;
    c8_s51dhbM5MSl1aKB4b1sqy0_b_overflow = false;
    if (c8_s51dhbM5MSl1aKB4b1sqy0_b_overflow) {
      c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error(chartInstance,
        c8_s51dhbM5MSl1aKB4b1sqy0_b_overflow);
    }

    for (c8_s51dhbM5MSl1aKB4b1sqy0_b_k = c8_s51dhbM5MSl1aKB4b1sqy0_i61 + 1;
         c8_s51dhbM5MSl1aKB4b1sqy0_b_k + 1 < 6; c8_s51dhbM5MSl1aKB4b1sqy0_b_k++)
    {
      c8_s51dhbM5MSl1aKB4b1sqy0_b_kBcol = 12 * c8_s51dhbM5MSl1aKB4b1sqy0_b_k;
      if (c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_k +
          c8_s51dhbM5MSl1aKB4b1sqy0_b_jAcol] != 0.0) {
        for (c8_s51dhbM5MSl1aKB4b1sqy0_c_i = 0; c8_s51dhbM5MSl1aKB4b1sqy0_c_i +
             1 < 13; c8_s51dhbM5MSl1aKB4b1sqy0_c_i++) {
          c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_c_i +
            c8_s51dhbM5MSl1aKB4b1sqy0_b_jBcol] -=
            c8_s51dhbM5MSl1aKB4b1sqy0_b_A[c8_s51dhbM5MSl1aKB4b1sqy0_b_k +
            c8_s51dhbM5MSl1aKB4b1sqy0_b_jAcol] *
            c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_c_i +
            c8_s51dhbM5MSl1aKB4b1sqy0_b_kBcol];
        }
      }
    }
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_xj = 3; c8_s51dhbM5MSl1aKB4b1sqy0_xj + 1 > 0;
       c8_s51dhbM5MSl1aKB4b1sqy0_xj--) {
    if (c8_s51dhbM5MSl1aKB4b1sqy0_ipiv[c8_s51dhbM5MSl1aKB4b1sqy0_xj] !=
        c8_s51dhbM5MSl1aKB4b1sqy0_xj + 1) {
      c8_s51dhbM5MSl1aKB4b1sqy0_jp =
        c8_s51dhbM5MSl1aKB4b1sqy0_ipiv[c8_s51dhbM5MSl1aKB4b1sqy0_xj] - 1;
      for (c8_s51dhbM5MSl1aKB4b1sqy0_xi = 0; c8_s51dhbM5MSl1aKB4b1sqy0_xi + 1 <
           13; c8_s51dhbM5MSl1aKB4b1sqy0_xi++) {
        c8_s51dhbM5MSl1aKB4b1sqy0_temp =
          c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_xi + 12 *
          c8_s51dhbM5MSl1aKB4b1sqy0_xj];
        c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_xi + 12 *
          c8_s51dhbM5MSl1aKB4b1sqy0_xj] =
          c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_xi + 12 *
          c8_s51dhbM5MSl1aKB4b1sqy0_jp];
        c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_xi + 12 *
          c8_s51dhbM5MSl1aKB4b1sqy0_jp] = c8_s51dhbM5MSl1aKB4b1sqy0_temp;
      }
    }
  }
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_check_forloop_overflow_error
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_overflow)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  static char_T c8_s51dhbM5MSl1aKB4b1sqy0_cv0[34] = { 'C', 'o', 'd', 'e', 'r',
    ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o',
    'r', 'l', 'o', 'o', 'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  static char_T c8_s51dhbM5MSl1aKB4b1sqy0_cv1[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c8_s51dhbM5MSl1aKB4b1sqy0_overflow) {
  } else {
    c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
    sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
      c8_s51dhbM5MSl1aKB4b1sqy0_cv0, 10, 0U, 1U, 0U, 2, 1, 34), false);
    c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
    sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_b_y, sf_mex_create("y",
      c8_s51dhbM5MSl1aKB4b1sqy0_cv1, 10, 0U, 1U, 0U, 2, 1, 5), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c8_s51dhbM5MSl1aKB4b1sqy0_y, 14, c8_s51dhbM5MSl1aKB4b1sqy0_b_y));
  }
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_warning
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  static char_T c8_s51dhbM5MSl1aKB4b1sqy0_cv2[7] = { 'w', 'a', 'r', 'n', 'i',
    'n', 'g' };

  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  static char_T c8_s51dhbM5MSl1aKB4b1sqy0_cv3[7] = { 'm', 'e', 's', 's', 'a',
    'g', 'e' };

  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  static char_T c8_s51dhbM5MSl1aKB4b1sqy0_msgID[27] = { 'C', 'o', 'd', 'e', 'r',
    ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_cv2, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_s51dhbM5MSl1aKB4b1sqy0_b_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_b_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_cv3, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_s51dhbM5MSl1aKB4b1sqy0_c_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_c_y, sf_mex_create("y",
    c8_s51dhbM5MSl1aKB4b1sqy0_msgID, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14,
                    c8_s51dhbM5MSl1aKB4b1sqy0_y, 14, sf_mex_call_debug
                    (sfGlobalDebugInstanceStruct, "feval", 1U, 2U, 14,
                     c8_s51dhbM5MSl1aKB4b1sqy0_b_y, 14,
                     c8_s51dhbM5MSl1aKB4b1sqy0_c_y));
}

static const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_s51dhbM5MSl1aKB4b1sqy0_inData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_u;
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_u = *(int32_T *)c8_s51dhbM5MSl1aKB4b1sqy0_inData;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = NULL;
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_y, sf_mex_create("y",
    &c8_s51dhbM5MSl1aKB4b1sqy0_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData,
                c8_s51dhbM5MSl1aKB4b1sqy0_y, false);
  return c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayOutData;
}

static int32_T c8_s51dhbM5MSl1aKB4b1sqy0_f_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i65;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), &c8_s51dhbM5MSl1aKB4b1sqy0_i65, 1,
                6, 0U, 0, 0U, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_i65;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_sfEvent;
  const char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_sfEvent = sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
  c8_s51dhbM5MSl1aKB4b1sqy0_identifier = c8_s51dhbM5MSl1aKB4b1sqy0_varName;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_b_sfEvent),
     &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_sfEvent);
  *(int32_T *)c8_s51dhbM5MSl1aKB4b1sqy0_outData = c8_s51dhbM5MSl1aKB4b1sqy0_y;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
}

static c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE
  c8_s51dhbM5MSl1aKB4b1sqy0_g_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE c8_s51dhbM5MSl1aKB4b1sqy0_y;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  static const char * c8_s51dhbM5MSl1aKB4b1sqy0_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = c8_s51dhbM5MSl1aKB4b1sqy0_parentId;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_s51dhbM5MSl1aKB4b1sqy0_parentId,
                      c8_s51dhbM5MSl1aKB4b1sqy0_u, 4,
                      c8_s51dhbM5MSl1aKB4b1sqy0_fieldNames, 0U, NULL);
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = "FcnName";
  c8_s51dhbM5MSl1aKB4b1sqy0_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s51dhbM5MSl1aKB4b1sqy0_u, "FcnName", "FcnName", 0)),
    &c8_s51dhbM5MSl1aKB4b1sqy0_thisId, c8_s51dhbM5MSl1aKB4b1sqy0_y.FcnName);
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = "JacobianFcnName";
  c8_s51dhbM5MSl1aKB4b1sqy0_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s51dhbM5MSl1aKB4b1sqy0_u, "JacobianFcnName",
                     "JacobianFcnName", 0)), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = "HasJacobian";
  c8_s51dhbM5MSl1aKB4b1sqy0_y.HasJacobian =
    c8_s51dhbM5MSl1aKB4b1sqy0_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s51dhbM5MSl1aKB4b1sqy0_u, "HasJacobian", "HasJacobian",
                     0)), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = "HasAdditiveNoise";
  c8_s51dhbM5MSl1aKB4b1sqy0_y.HasAdditiveNoise =
    c8_s51dhbM5MSl1aKB4b1sqy0_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_s51dhbM5MSl1aKB4b1sqy0_u, "HasAdditiveNoise",
                     "HasAdditiveNoise", 0)), &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_h_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId, char_T
   c8_s51dhbM5MSl1aKB4b1sqy0_y[19])
{
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_cv4[19];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i66;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), c8_s51dhbM5MSl1aKB4b1sqy0_cv4, 1,
                10, 0U, 1, 0U, 2, 1, 19);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i66 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i66 < 19;
       c8_s51dhbM5MSl1aKB4b1sqy0_i66++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i66] =
      c8_s51dhbM5MSl1aKB4b1sqy0_cv4[c8_s51dhbM5MSl1aKB4b1sqy0_i66];
  }

  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_i_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
}

static boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_j_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  boolean_T c8_s51dhbM5MSl1aKB4b1sqy0_b0;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), &c8_s51dhbM5MSl1aKB4b1sqy0_b0, 1,
                11, 0U, 0, 0U, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_b0;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData, const char_T
  *c8_s51dhbM5MSl1aKB4b1sqy0_varName, void *c8_s51dhbM5MSl1aKB4b1sqy0_outData)
{
  const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_b_pM;
  const char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE c8_s51dhbM5MSl1aKB4b1sqy0_y;
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_pM = sf_mex_dup
    (c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
  c8_s51dhbM5MSl1aKB4b1sqy0_identifier = c8_s51dhbM5MSl1aKB4b1sqy0_varName;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_s51dhbM5MSl1aKB4b1sqy0_b_pM),
     &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_b_pM);
  *(c8_s51dhbM5MSl1aKB4b1sqy0_sex2lFeEcOPeDeDewnWtFVE *)
    c8_s51dhbM5MSl1aKB4b1sqy0_outData = c8_s51dhbM5MSl1aKB4b1sqy0_y;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_mxArrayInData);
}

static uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_k_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_s51dhbM5MSl1aKB4b1sqy0_b_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_, const
   char_T *c8_s51dhbM5MSl1aKB4b1sqy0_identifier)
{
  uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  emlrtMsgIdentifier c8_s51dhbM5MSl1aKB4b1sqy0_thisId;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fIdentifier = (const char *)
    c8_s51dhbM5MSl1aKB4b1sqy0_identifier;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.fParent = NULL;
  c8_s51dhbM5MSl1aKB4b1sqy0_thisId.bParentIsCell = false;
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c8_s51dhbM5MSl1aKB4b1sqy0_b_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_),
     &c8_s51dhbM5MSl1aKB4b1sqy0_thisId);
  sf_mex_destroy
    (&c8_s51dhbM5MSl1aKB4b1sqy0_b_is_active_c8_s51dhbM5MSl1aKB4b1sqy0_);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_l_emlrt_marshallIn
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_s51dhbM5MSl1aKB4b1sqy0_u, const
   emlrtMsgIdentifier *c8_s51dhbM5MSl1aKB4b1sqy0_parentId)
{
  uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_y;
  uint8_T c8_s51dhbM5MSl1aKB4b1sqy0_u0;
  (void)chartInstance;
  sf_mex_import(c8_s51dhbM5MSl1aKB4b1sqy0_parentId, sf_mex_dup
                (c8_s51dhbM5MSl1aKB4b1sqy0_u), &c8_s51dhbM5MSl1aKB4b1sqy0_u0, 1,
                3, 0U, 0, 0U, 0);
  c8_s51dhbM5MSl1aKB4b1sqy0_y = c8_s51dhbM5MSl1aKB4b1sqy0_u0;
  sf_mex_destroy(&c8_s51dhbM5MSl1aKB4b1sqy0_u);
  return c8_s51dhbM5MSl1aKB4b1sqy0_y;
}

static void c8_s51dhbM5MSl1aKB4b1sqy0_b_EKFCorrectorNonAdditive_correct
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_s51dhbM5MSl1aKB4b1sqy0_z[5], real_T
   c8_s51dhbM5MSl1aKB4b1sqy0_zcov[25], real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_x[12],
   real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_P[144])
{
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i67;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i68;
  c8_s51dhbM5MSl1aKB4b1sqy0_cell_2 c8_s51dhbM5MSl1aKB4b1sqy0_r2;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dHdx[60];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i69;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i70;
  c8_s51dhbM5MSl1aKB4b1sqy0_cell_2 c8_s51dhbM5MSl1aKB4b1sqy0_r3;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i71;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i72;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_alpha1;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i73;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_beta1;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i74;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_TRANSB;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_TRANSA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i75;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_gain[60];
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_m_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_Pxy[60];
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_n_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_k_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_lda_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_ldb_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_ldc_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_alpha1;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_beta1;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSB;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i76;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_m_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_y[60];
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_n_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_k_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_lda_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_ldb_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_b_ldc_t;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i77;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i78;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i79;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i80;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i81;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i82;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i83;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i84;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i85;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i86;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i87;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i88;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i89;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_Pyy[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i90;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i91;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i92;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b_y[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i93;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i94;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i95;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i96;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i97;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i98;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i99;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_b[25];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i100;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i101;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_xx[12];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i102;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i103;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_dv4[5];
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_zEstimated[5];
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i104;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i105;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i106;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i107;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i108;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_alpha1;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_beta1;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSB;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i109;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_m_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_c_y[144];
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_n_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_k_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_lda_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_ldb_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_c_ldc_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_alpha1;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_beta1;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSB;
  char_T c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSA;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i110;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_m_t;
  real_T c8_s51dhbM5MSl1aKB4b1sqy0_d_y[144];
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_n_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_k_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_lda_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_ldb_t;
  ptrdiff_t c8_s51dhbM5MSl1aKB4b1sqy0_d_ldc_t;
  int32_T c8_s51dhbM5MSl1aKB4b1sqy0_i111;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i67 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i67 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i67++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_r2.f1[c8_s51dhbM5MSl1aKB4b1sqy0_i67] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i67];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i68 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i68 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i68++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_r2.f2[c8_s51dhbM5MSl1aKB4b1sqy0_i68] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_numericJacobian(chartInstance,
    &c8_s51dhbM5MSl1aKB4b1sqy0_r2, c8_s51dhbM5MSl1aKB4b1sqy0_dHdx);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i69 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i69 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i69++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_r3.f1[c8_s51dhbM5MSl1aKB4b1sqy0_i69] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i69];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i70 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i70 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i70++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_r3.f2[c8_s51dhbM5MSl1aKB4b1sqy0_i70] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_numericJacobian(chartInstance,
    &c8_s51dhbM5MSl1aKB4b1sqy0_r3, c8_s51dhbM5MSl1aKB4b1sqy0_dHdv);
  c8_s51dhbM5MSl1aKB4b1sqy0_i71 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i72 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i72 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i72++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i73 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i74 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i74 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i74++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_gain[c8_s51dhbM5MSl1aKB4b1sqy0_i74 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i71] =
        c8_s51dhbM5MSl1aKB4b1sqy0_dHdx[c8_s51dhbM5MSl1aKB4b1sqy0_i73 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i72];
      c8_s51dhbM5MSl1aKB4b1sqy0_i73 += 5;
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i71 += 12;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_alpha1 = 1.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_beta1 = 0.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_TRANSB = 'N';
  c8_s51dhbM5MSl1aKB4b1sqy0_TRANSA = 'N';
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i75 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i75 < 60;
       c8_s51dhbM5MSl1aKB4b1sqy0_i75++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_Pxy[c8_s51dhbM5MSl1aKB4b1sqy0_i75] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_m_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_n_t = (ptrdiff_t)5;
  c8_s51dhbM5MSl1aKB4b1sqy0_k_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_lda_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_ldb_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s51dhbM5MSl1aKB4b1sqy0_TRANSA, &c8_s51dhbM5MSl1aKB4b1sqy0_TRANSB,
        &c8_s51dhbM5MSl1aKB4b1sqy0_m_t, &c8_s51dhbM5MSl1aKB4b1sqy0_n_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_k_t, &c8_s51dhbM5MSl1aKB4b1sqy0_alpha1,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_P[0], &c8_s51dhbM5MSl1aKB4b1sqy0_lda_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_gain[0], &c8_s51dhbM5MSl1aKB4b1sqy0_ldb_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_beta1, &c8_s51dhbM5MSl1aKB4b1sqy0_Pxy[0],
        &c8_s51dhbM5MSl1aKB4b1sqy0_ldc_t);
  c8_s51dhbM5MSl1aKB4b1sqy0_b_alpha1 = 1.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_beta1 = 0.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSB = 'N';
  c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSA = 'N';
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i76 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i76 < 60;
       c8_s51dhbM5MSl1aKB4b1sqy0_i76++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i76] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_b_m_t = (ptrdiff_t)5;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_n_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_k_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_lda_t = (ptrdiff_t)5;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_ldb_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_b_ldc_t = (ptrdiff_t)5;
  dgemm(&c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSA, &c8_s51dhbM5MSl1aKB4b1sqy0_b_TRANSB,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_m_t, &c8_s51dhbM5MSl1aKB4b1sqy0_b_n_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_k_t, &c8_s51dhbM5MSl1aKB4b1sqy0_b_alpha1,
        &c8_s51dhbM5MSl1aKB4b1sqy0_dHdx[0], &c8_s51dhbM5MSl1aKB4b1sqy0_b_lda_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_P[0], &c8_s51dhbM5MSl1aKB4b1sqy0_b_ldb_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_beta1, &c8_s51dhbM5MSl1aKB4b1sqy0_y[0],
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_ldc_t);
  c8_s51dhbM5MSl1aKB4b1sqy0_i77 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i78 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i78 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i78++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i80 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i81 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i81 < 12;
         c8_s51dhbM5MSl1aKB4b1sqy0_i81++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_gain[c8_s51dhbM5MSl1aKB4b1sqy0_i81 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i77] =
        c8_s51dhbM5MSl1aKB4b1sqy0_dHdx[c8_s51dhbM5MSl1aKB4b1sqy0_i80 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i78];
      c8_s51dhbM5MSl1aKB4b1sqy0_i80 += 5;
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i77 += 12;
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i79 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i79 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i79++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i83 = 0;
    c8_s51dhbM5MSl1aKB4b1sqy0_i84 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i85 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i85 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i85++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_Pyy[c8_s51dhbM5MSl1aKB4b1sqy0_i83 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i79] = 0.0;
      c8_s51dhbM5MSl1aKB4b1sqy0_i90 = 0;
      for (c8_s51dhbM5MSl1aKB4b1sqy0_i93 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i93 < 12;
           c8_s51dhbM5MSl1aKB4b1sqy0_i93++) {
        c8_s51dhbM5MSl1aKB4b1sqy0_Pyy[c8_s51dhbM5MSl1aKB4b1sqy0_i83 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i79] +=
          c8_s51dhbM5MSl1aKB4b1sqy0_y[c8_s51dhbM5MSl1aKB4b1sqy0_i90 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i79] *
          c8_s51dhbM5MSl1aKB4b1sqy0_gain[c8_s51dhbM5MSl1aKB4b1sqy0_i93 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i84];
        c8_s51dhbM5MSl1aKB4b1sqy0_i90 += 5;
      }

      c8_s51dhbM5MSl1aKB4b1sqy0_i83 += 5;
      c8_s51dhbM5MSl1aKB4b1sqy0_i84 += 12;
    }
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i82 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i82 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i82++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i87 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i89 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i89 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i89++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_b_y[c8_s51dhbM5MSl1aKB4b1sqy0_i87 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i82] = 0.0;
      c8_s51dhbM5MSl1aKB4b1sqy0_i95 = 0;
      for (c8_s51dhbM5MSl1aKB4b1sqy0_i96 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i96 < 5;
           c8_s51dhbM5MSl1aKB4b1sqy0_i96++) {
        c8_s51dhbM5MSl1aKB4b1sqy0_b_y[c8_s51dhbM5MSl1aKB4b1sqy0_i87 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i82] +=
          c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[c8_s51dhbM5MSl1aKB4b1sqy0_i95 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i82] *
          c8_s51dhbM5MSl1aKB4b1sqy0_zcov[c8_s51dhbM5MSl1aKB4b1sqy0_i96 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i87];
        c8_s51dhbM5MSl1aKB4b1sqy0_i95 += 5;
      }

      c8_s51dhbM5MSl1aKB4b1sqy0_i87 += 5;
    }
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_i86 = 0;
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i88 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i88 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i88++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i92 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i94 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i94 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i94++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_b[c8_s51dhbM5MSl1aKB4b1sqy0_i94 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i86] =
        c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[c8_s51dhbM5MSl1aKB4b1sqy0_i92 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i88];
      c8_s51dhbM5MSl1aKB4b1sqy0_i92 += 5;
    }

    c8_s51dhbM5MSl1aKB4b1sqy0_i86 += 5;
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i91 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i91 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i91++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_i98 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i99 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i99 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i99++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[c8_s51dhbM5MSl1aKB4b1sqy0_i98 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i91] = 0.0;
      c8_s51dhbM5MSl1aKB4b1sqy0_i101 = 0;
      for (c8_s51dhbM5MSl1aKB4b1sqy0_i102 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i102 <
           5; c8_s51dhbM5MSl1aKB4b1sqy0_i102++) {
        c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[c8_s51dhbM5MSl1aKB4b1sqy0_i98 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i91] +=
          c8_s51dhbM5MSl1aKB4b1sqy0_b_y[c8_s51dhbM5MSl1aKB4b1sqy0_i101 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i91] *
          c8_s51dhbM5MSl1aKB4b1sqy0_b[c8_s51dhbM5MSl1aKB4b1sqy0_i102 +
          c8_s51dhbM5MSl1aKB4b1sqy0_i98];
        c8_s51dhbM5MSl1aKB4b1sqy0_i101 += 5;
      }

      c8_s51dhbM5MSl1aKB4b1sqy0_i98 += 5;
    }
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i97 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i97 < 25;
       c8_s51dhbM5MSl1aKB4b1sqy0_i97++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_Pyy[c8_s51dhbM5MSl1aKB4b1sqy0_i97] +=
      c8_s51dhbM5MSl1aKB4b1sqy0_dHdv[c8_s51dhbM5MSl1aKB4b1sqy0_i97];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i100 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i100 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i100++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_xx[c8_s51dhbM5MSl1aKB4b1sqy0_i100] =
      c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i100];
  }

  CV_EML_FCN(0, 6);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i103 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i103 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i103++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_dv4[c8_s51dhbM5MSl1aKB4b1sqy0_i103] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_measurementDroneFcn_invoke(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_xx, c8_s51dhbM5MSl1aKB4b1sqy0_dv4,
    c8_s51dhbM5MSl1aKB4b1sqy0_zEstimated);
  c8_s51dhbM5MSl1aKB4b1sqy0_mrdivide(chartInstance,
    c8_s51dhbM5MSl1aKB4b1sqy0_Pxy, c8_s51dhbM5MSl1aKB4b1sqy0_Pyy,
    c8_s51dhbM5MSl1aKB4b1sqy0_gain);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i104 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i104 < 5;
       c8_s51dhbM5MSl1aKB4b1sqy0_i104++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_zEstimated[c8_s51dhbM5MSl1aKB4b1sqy0_i104] =
      c8_s51dhbM5MSl1aKB4b1sqy0_z[c8_s51dhbM5MSl1aKB4b1sqy0_i104] -
      c8_s51dhbM5MSl1aKB4b1sqy0_zEstimated[c8_s51dhbM5MSl1aKB4b1sqy0_i104];
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i105 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i105 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i105++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_xx[c8_s51dhbM5MSl1aKB4b1sqy0_i105] = 0.0;
    c8_s51dhbM5MSl1aKB4b1sqy0_i107 = 0;
    for (c8_s51dhbM5MSl1aKB4b1sqy0_i108 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i108 < 5;
         c8_s51dhbM5MSl1aKB4b1sqy0_i108++) {
      c8_s51dhbM5MSl1aKB4b1sqy0_xx[c8_s51dhbM5MSl1aKB4b1sqy0_i105] +=
        c8_s51dhbM5MSl1aKB4b1sqy0_gain[c8_s51dhbM5MSl1aKB4b1sqy0_i107 +
        c8_s51dhbM5MSl1aKB4b1sqy0_i105] *
        c8_s51dhbM5MSl1aKB4b1sqy0_zEstimated[c8_s51dhbM5MSl1aKB4b1sqy0_i108];
      c8_s51dhbM5MSl1aKB4b1sqy0_i107 += 12;
    }
  }

  for (c8_s51dhbM5MSl1aKB4b1sqy0_i106 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i106 < 12;
       c8_s51dhbM5MSl1aKB4b1sqy0_i106++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_x[c8_s51dhbM5MSl1aKB4b1sqy0_i106] +=
      c8_s51dhbM5MSl1aKB4b1sqy0_xx[c8_s51dhbM5MSl1aKB4b1sqy0_i106];
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_c_alpha1 = 1.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_beta1 = 0.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSB = 'N';
  c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSA = 'N';
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i109 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i109 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i109++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_c_y[c8_s51dhbM5MSl1aKB4b1sqy0_i109] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_c_m_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_n_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_k_t = (ptrdiff_t)5;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_lda_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_ldb_t = (ptrdiff_t)5;
  c8_s51dhbM5MSl1aKB4b1sqy0_c_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSA, &c8_s51dhbM5MSl1aKB4b1sqy0_c_TRANSB,
        &c8_s51dhbM5MSl1aKB4b1sqy0_c_m_t, &c8_s51dhbM5MSl1aKB4b1sqy0_c_n_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_c_k_t, &c8_s51dhbM5MSl1aKB4b1sqy0_c_alpha1,
        &c8_s51dhbM5MSl1aKB4b1sqy0_gain[0], &c8_s51dhbM5MSl1aKB4b1sqy0_c_lda_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_dHdx[0], &c8_s51dhbM5MSl1aKB4b1sqy0_c_ldb_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_c_beta1, &c8_s51dhbM5MSl1aKB4b1sqy0_c_y[0],
        &c8_s51dhbM5MSl1aKB4b1sqy0_c_ldc_t);
  c8_s51dhbM5MSl1aKB4b1sqy0_d_alpha1 = 1.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_beta1 = 0.0;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSB = 'N';
  c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSA = 'N';
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i110 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i110 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i110++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_d_y[c8_s51dhbM5MSl1aKB4b1sqy0_i110] = 0.0;
  }

  c8_s51dhbM5MSl1aKB4b1sqy0_d_m_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_n_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_k_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_lda_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_ldb_t = (ptrdiff_t)12;
  c8_s51dhbM5MSl1aKB4b1sqy0_d_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSA, &c8_s51dhbM5MSl1aKB4b1sqy0_d_TRANSB,
        &c8_s51dhbM5MSl1aKB4b1sqy0_d_m_t, &c8_s51dhbM5MSl1aKB4b1sqy0_d_n_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_d_k_t, &c8_s51dhbM5MSl1aKB4b1sqy0_d_alpha1,
        &c8_s51dhbM5MSl1aKB4b1sqy0_c_y[0], &c8_s51dhbM5MSl1aKB4b1sqy0_d_lda_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_b_P[0], &c8_s51dhbM5MSl1aKB4b1sqy0_d_ldb_t,
        &c8_s51dhbM5MSl1aKB4b1sqy0_d_beta1, &c8_s51dhbM5MSl1aKB4b1sqy0_d_y[0],
        &c8_s51dhbM5MSl1aKB4b1sqy0_d_ldc_t);
  for (c8_s51dhbM5MSl1aKB4b1sqy0_i111 = 0; c8_s51dhbM5MSl1aKB4b1sqy0_i111 < 144;
       c8_s51dhbM5MSl1aKB4b1sqy0_i111++) {
    c8_s51dhbM5MSl1aKB4b1sqy0_b_P[c8_s51dhbM5MSl1aKB4b1sqy0_i111] -=
      c8_s51dhbM5MSl1aKB4b1sqy0_d_y[c8_s51dhbM5MSl1aKB4b1sqy0_i111];
  }
}

static void init_dsm_address_info
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_fEmlrtCtx = (void *)sfrtGetEmlrtCtx
    (chartInstance->S);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_x = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew = (real_T (*)[12])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_P = (real_T (*)[144])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew = (real_T (*)[144])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_yMeas = (real_T (*)[5])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_R = (real_T (*)[25])
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

void sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1741005656U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1080444525U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4205325505U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3993041781U);
}

mxArray*
  sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray
  *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lVtRs5qUIu1B5pscqTFzO");
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
      sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_jit_fallback_info
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
  *sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray*
  sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "I35LLMtd4OYaWlddPJQwb");
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
  *sf_get_sim_state_info_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
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
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_d_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 5U;
          dimVector[1]= 5U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_c_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallOut,
            (MexInFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallOut,
            (MexInFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_f_sf_marshallOut,
          (MexInFcnForType)c8_s51dhbM5MSl1aKB4b1sqy0_e_sf_marshallIn);
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
    SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          &chartInstance->c8_s51dhbM5MSl1aKB4b1sqy0_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s51dhbM5MSl1aKB4b1sqy0";
}

static void sf_opaque_initialize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
  initialize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  enable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  disable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  sf_gateway_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SimStruct* S)
{
  return get_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void
  sf_opaque_set_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
      ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
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
  initSimStructsc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
    ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
      ((SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary
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
  ssSetChecksum0(S,(1741005656U));
  ssSetChecksum1(S,(1080444525U));
  ssSetChecksum2(S,(4205325505U));
  ssSetChecksum3(S,(3993041781U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(SimStruct
  *S)
{
  SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance =
    (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct *)utMalloc
    (sizeof(SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary;
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
  mdl_start_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(chartInstance);
}

void c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_method_dispatcher(SimStruct
  *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_s51dhbM5MSl1aKB4b1sqy0_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
