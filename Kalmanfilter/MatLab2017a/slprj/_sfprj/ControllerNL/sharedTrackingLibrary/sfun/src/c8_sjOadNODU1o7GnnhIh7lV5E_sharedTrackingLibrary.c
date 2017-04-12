/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary.h"
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
static const char * c8_sjOadNODU1o7GnnhIh7lV5E_debug_family_names[10] = {
  "MeasurementFcn", "pM", "nargin", "nargout", "x", "P", "yMeas", "R", "xNew",
  "PNew" };

/* Function Declarations */
static void initialize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initialize_params_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void enable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void disable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sjOadNODU1o7GnnhIh7lV5E_update_debugger_state_c8_sjOadNODU1o7
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void set_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_st);
static void finalize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void sf_gateway_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void mdl_start_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initSimStructsc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_w[3], real_T c8_sjOadNODU1o7GnnhIh7lV5E_y[3]);
static void init_script_number_translation(uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_machineNumber, uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_chartNumber, uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_instanceNumber);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static void c8_sjOadNODU1o7GnnhIh7lV5E_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[144]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_b_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[144]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static void c8_sjOadNODU1o7GnnhIh7lV5E_c_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[12]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_d_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[12]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static real_T c8_sjOadNODU1o7GnnhIh7lV5E_e_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static void c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static void c8_sjOadNODU1o7GnnhIh7lV5E_EKFCorrectorNonAdditive_correct
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_z[3], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_zcov[9], real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12],
   real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_P[144], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_c_x[12], real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_P[144]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_warning
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData);
static int32_T c8_sjOadNODU1o7GnnhIh7lV5E_f_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static void c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData);
static c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
  c8_sjOadNODU1o7GnnhIh7lV5E_g_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static void c8_sjOadNODU1o7GnnhIh7lV5E_h_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, char_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[17]);
static void c8_sjOadNODU1o7GnnhIh7lV5E_i_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_j_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static void c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData);
static uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_k_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sjOadNODU1o7GnnhIh7lV5E_b_is_active_c8_sjOadNODU1o7GnnhIh7lV5, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier);
static uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_l_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId);
static void c8_sjOadNODU1o7GnnhIh7lV5E_b_EKFCorrectorNonAdditive_correct
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_z[3], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_zcov[9], real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12],
   real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_P[144]);
static void init_dsm_address_info
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void init_simulink_io_address
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_is_active_c8_sjOadNODU1o7GnnhIh7lV5E_
    = 0U;
}

static void initialize_params_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_m0 = NULL;
  static const char * c8_sjOadNODU1o7GnnhIh7lV5E_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxField;
  c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_r0;
  c8_sjOadNODU1o7GnnhIh7lV5E_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c8_sjOadNODU1o7GnnhIh7lV5E_m0, 4,
    c8_sjOadNODU1o7GnnhIh7lV5E_fieldNames, "sJc0LrpsE91c2htQpVlRXsE");
  c8_sjOadNODU1o7GnnhIh7lV5E_mxField = sf_mex_getfield
    (c8_sjOadNODU1o7GnnhIh7lV5E_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_mxField),
                      c8_sjOadNODU1o7GnnhIh7lV5E_r0.FcnName, 1, 10, 0U, 1, 0U, 2,
                      1, 17);
  c8_sjOadNODU1o7GnnhIh7lV5E_mxField = sf_mex_getfield
    (c8_sjOadNODU1o7GnnhIh7lV5E_m0, "JacobianFcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_mxField), NULL,
                      1, 10, 0U, 1, 0U, 2, 0, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_mxField = sf_mex_getfield
    (c8_sjOadNODU1o7GnnhIh7lV5E_m0, "HasJacobian", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_mxField),
                      &c8_sjOadNODU1o7GnnhIh7lV5E_r0.HasJacobian, 1, 11, 0U, 0,
                      0U, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_mxField = sf_mex_getfield
    (c8_sjOadNODU1o7GnnhIh7lV5E_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_mxField),
                      &c8_sjOadNODU1o7GnnhIh7lV5E_r0.HasAdditiveNoise, 1, 11, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_m0);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_pM = c8_sjOadNODU1o7GnnhIh7lV5E_r0;
}

static void enable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_update_debugger_state_c8_sjOadNODU1o7
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_st;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_hoistedGlobal;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_d_y = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_st = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_st = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_createcellmatrix(3, 1),
                false);
  c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_b_y, sf_mex_create("y",
    *chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c8_sjOadNODU1o7GnnhIh7lV5E_y, 0, c8_sjOadNODU1o7GnnhIh7lV5E_b_y);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_c_y, sf_mex_create("y",
    *chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew, 0, 0U, 1U, 0U, 1, 12),
                false);
  sf_mex_setcell(c8_sjOadNODU1o7GnnhIh7lV5E_y, 1, c8_sjOadNODU1o7GnnhIh7lV5E_c_y);
  c8_sjOadNODU1o7GnnhIh7lV5E_hoistedGlobal =
    chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_is_active_c8_sjOadNODU1o7GnnhIh7lV5E_;
  c8_sjOadNODU1o7GnnhIh7lV5E_d_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_d_y, sf_mex_create("y",
    &c8_sjOadNODU1o7GnnhIh7lV5E_hoistedGlobal, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_sjOadNODU1o7GnnhIh7lV5E_y, 2, c8_sjOadNODU1o7GnnhIh7lV5E_d_y);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_st, c8_sjOadNODU1o7GnnhIh7lV5E_y,
                false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_st;
}

static void set_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_st)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dv0[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i0;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dv1[12];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i1;
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_doneDoubleBufferReInit = true;
  c8_sjOadNODU1o7GnnhIh7lV5E_u = sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_st);
  c8_sjOadNODU1o7GnnhIh7lV5E_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PNew", c8_sjOadNODU1o7GnnhIh7lV5E_u, 0)), "PNew",
    c8_sjOadNODU1o7GnnhIh7lV5E_dv0);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i0 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i0 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i0++) {
    (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i0] =
      c8_sjOadNODU1o7GnnhIh7lV5E_dv0[c8_sjOadNODU1o7GnnhIh7lV5E_i0];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xNew", c8_sjOadNODU1o7GnnhIh7lV5E_u, 1)), "xNew",
    c8_sjOadNODU1o7GnnhIh7lV5E_dv1);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i1 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i1 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i1++) {
    (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i1] =
      c8_sjOadNODU1o7GnnhIh7lV5E_dv1[c8_sjOadNODU1o7GnnhIh7lV5E_i1];
  }

  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_is_active_c8_sjOadNODU1o7GnnhIh7lV5E_
    = c8_sjOadNODU1o7GnnhIh7lV5E_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_active_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary",
                    c8_sjOadNODU1o7GnnhIh7lV5E_u, 2)),
    "is_active_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary");
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  c8_sjOadNODU1o7GnnhIh7lV5E_update_debugger_state_c8_sjOadNODU1o7(chartInstance);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_st);
}

static void finalize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i2;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i3;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i4;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i5;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i6;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i7;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i8;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_P[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i9;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_yMeas[3];
  uint32_T c8_sjOadNODU1o7GnnhIh7lV5E_debug_family_var_map[10];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_R[9];
  c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_b_pM;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_nargin = 4.0;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_nargout = 2.0;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew[12];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew[144];
  static c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_r1 = { { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'm',
      'e', 'n', 't', 'T', 'W', 'B', 'F', 'c', 'n' },/* FcnName */
    false,                             /* HasJacobian */
    false                              /* HasAdditiveNoise */
  };

  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i10;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i11;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i12;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i13;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_xNew[12];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i14;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_PNew[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i15;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_yMeas[3];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_R[9];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i16;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i17;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i18;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i19;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i20;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i2 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i2 < 9;
       c8_sjOadNODU1o7GnnhIh7lV5E_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_R)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i2], 3U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i3 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i3 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_yMeas)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i3], 2U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i4 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i4 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_P)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i4], 1U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i5 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i5 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_x)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i5], 0U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }

  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i6 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i6 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i6++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i6] =
      (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_x)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i6];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i7 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i7 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i7++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i7] =
      (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_P)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i7];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i8 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i8 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i8++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_yMeas[c8_sjOadNODU1o7GnnhIh7lV5E_i8] =
      (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_yMeas)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i8];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i9 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i9 < 9;
       c8_sjOadNODU1o7GnnhIh7lV5E_i9++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_R[c8_sjOadNODU1o7GnnhIh7lV5E_i9] =
      (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_R)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U,
    c8_sjOadNODU1o7GnnhIh7lV5E_debug_family_names,
    c8_sjOadNODU1o7GnnhIh7lV5E_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U,
    c8_sjOadNODU1o7GnnhIh7lV5E_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_sjOadNODU1o7GnnhIh7lV5E_b_pM, 1U,
    c8_sjOadNODU1o7GnnhIh7lV5E_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sjOadNODU1o7GnnhIh7lV5E_nargin, 2U,
    c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallOut,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sjOadNODU1o7GnnhIh7lV5E_nargout, 3U,
    c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallOut,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sjOadNODU1o7GnnhIh7lV5E_b_x, 4U,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sjOadNODU1o7GnnhIh7lV5E_b_P, 5U,
    c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sjOadNODU1o7GnnhIh7lV5E_b_yMeas, 6U,
    c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sjOadNODU1o7GnnhIh7lV5E_b_R, 7U,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew, 8U,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew, 9U,
    c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut,
    c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallIn);
  c8_sjOadNODU1o7GnnhIh7lV5E_b_pM = c8_sjOadNODU1o7GnnhIh7lV5E_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 7);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i10 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i10 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i10++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew[c8_sjOadNODU1o7GnnhIh7lV5E_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 8);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i11 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i11 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i11++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew[c8_sjOadNODU1o7GnnhIh7lV5E_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 9);
  CV_EML_IF(0, 1, 1, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 18);
  CV_EML_IF(0, 1, 3, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, 22);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i12 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i12 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i12++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_xNew[c8_sjOadNODU1o7GnnhIh7lV5E_i12] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i12];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i13 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i13 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i13++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_PNew[c8_sjOadNODU1o7GnnhIh7lV5E_i13] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i13];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i14 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i14 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i14++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_yMeas[c8_sjOadNODU1o7GnnhIh7lV5E_i14] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_yMeas[c8_sjOadNODU1o7GnnhIh7lV5E_i14];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i15 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i15 < 9;
       c8_sjOadNODU1o7GnnhIh7lV5E_i15++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_R[c8_sjOadNODU1o7GnnhIh7lV5E_i15] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_R[c8_sjOadNODU1o7GnnhIh7lV5E_i15];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_b_EKFCorrectorNonAdditive_correct(chartInstance,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_yMeas, c8_sjOadNODU1o7GnnhIh7lV5E_c_R,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_xNew, c8_sjOadNODU1o7GnnhIh7lV5E_c_PNew);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i16 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i16 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i16++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew[c8_sjOadNODU1o7GnnhIh7lV5E_i16] =
      c8_sjOadNODU1o7GnnhIh7lV5E_c_xNew[c8_sjOadNODU1o7GnnhIh7lV5E_i16];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i17 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i17 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i17++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew[c8_sjOadNODU1o7GnnhIh7lV5E_i17] =
      c8_sjOadNODU1o7GnnhIh7lV5E_c_PNew[c8_sjOadNODU1o7GnnhIh7lV5E_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i18 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i18 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i18++) {
    (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i18] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew[c8_sjOadNODU1o7GnnhIh7lV5E_i18];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i19 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i19 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i19++) {
    (*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i19] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew[c8_sjOadNODU1o7GnnhIh7lV5E_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i20 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i20 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i20], 4U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i21 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i21 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew)
                          [c8_sjOadNODU1o7GnnhIh7lV5E_i21], 5U, 1U, 0U,
                          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_sfEvent,
                          false);
  }
}

static void mdl_start_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_w[3], real_T c8_sjOadNODU1o7GnnhIh7lV5E_y[3])
{
  _ssFcnCallExecArgInfo c8_sjOadNODU1o7GnnhIh7lV5E_args[3];
  c8_sjOadNODU1o7GnnhIh7lV5E_args[0U].dataPtr = (void *)
    c8_sjOadNODU1o7GnnhIh7lV5E_b_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_args[1U].dataPtr = (void *)
    c8_sjOadNODU1o7GnnhIh7lV5E_w;
  c8_sjOadNODU1o7GnnhIh7lV5E_args[2U].dataPtr = (void *)
    c8_sjOadNODU1o7GnnhIh7lV5E_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "measurementTWBFcn",
    &c8_sjOadNODU1o7GnnhIh7lV5E_args[0U]);
}

static void init_script_number_translation(uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_machineNumber, uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_chartNumber, uint32_T
  c8_sjOadNODU1o7GnnhIh7lV5E_instanceNumber)
{
  (void)(c8_sjOadNODU1o7GnnhIh7lV5E_machineNumber);
  (void)(c8_sjOadNODU1o7GnnhIh7lV5E_chartNumber);
  (void)(c8_sjOadNODU1o7GnnhIh7lV5E_instanceNumber);
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i22;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i23;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i24;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u[144];
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_i22 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i23 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i23 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i23++) {
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i24 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i24 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i24++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_u[c8_sjOadNODU1o7GnnhIh7lV5E_i24 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i22] = (*(real_T (*)[144])
        c8_sjOadNODU1o7GnnhIh7lV5E_inData)[c8_sjOadNODU1o7GnnhIh7lV5E_i24 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i22];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i22 += 12;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[144])
{
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId,
    c8_sjOadNODU1o7GnnhIh7lV5E_y);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_b_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[144])
{
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dv2[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i25;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), c8_sjOadNODU1o7GnnhIh7lV5E_dv2,
                1, 0, 0U, 1, 0U, 2, 12, 12);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i25 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i25 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i25++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_y[c8_sjOadNODU1o7GnnhIh7lV5E_i25] =
      c8_sjOadNODU1o7GnnhIh7lV5E_dv2[c8_sjOadNODU1o7GnnhIh7lV5E_i25];
  }

  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew;
  const char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i26;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i27;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i28;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew = sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
  c8_sjOadNODU1o7GnnhIh7lV5E_identifier = c8_sjOadNODU1o7GnnhIh7lV5E_varName;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId,
    c8_sjOadNODU1o7GnnhIh7lV5E_y);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_PNew);
  c8_sjOadNODU1o7GnnhIh7lV5E_i26 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i27 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i27 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i27++) {
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i28 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i28 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i28++) {
      (*(real_T (*)[144])c8_sjOadNODU1o7GnnhIh7lV5E_outData)
        [c8_sjOadNODU1o7GnnhIh7lV5E_i28 + c8_sjOadNODU1o7GnnhIh7lV5E_i26] =
        c8_sjOadNODU1o7GnnhIh7lV5E_y[c8_sjOadNODU1o7GnnhIh7lV5E_i28 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i26];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i26 += 12;
  }

  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i29;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u[12];
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i29 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i29 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i29++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_u[c8_sjOadNODU1o7GnnhIh7lV5E_i29] = (*(real_T (*)
      [12])c8_sjOadNODU1o7GnnhIh7lV5E_inData)[c8_sjOadNODU1o7GnnhIh7lV5E_i29];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_c_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[12])
{
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId,
    c8_sjOadNODU1o7GnnhIh7lV5E_y);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_d_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[12])
{
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dv3[12];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i30;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), c8_sjOadNODU1o7GnnhIh7lV5E_dv3,
                1, 0, 0U, 1, 0U, 1, 12);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i30 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i30 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i30++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_y[c8_sjOadNODU1o7GnnhIh7lV5E_i30] =
      c8_sjOadNODU1o7GnnhIh7lV5E_dv3[c8_sjOadNODU1o7GnnhIh7lV5E_i30];
  }

  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew;
  const char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y[12];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i31;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew = sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
  c8_sjOadNODU1o7GnnhIh7lV5E_identifier = c8_sjOadNODU1o7GnnhIh7lV5E_varName;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId,
    c8_sjOadNODU1o7GnnhIh7lV5E_y);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_xNew);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i31 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i31 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i31++) {
    (*(real_T (*)[12])c8_sjOadNODU1o7GnnhIh7lV5E_outData)
      [c8_sjOadNODU1o7GnnhIh7lV5E_i31] =
      c8_sjOadNODU1o7GnnhIh7lV5E_y[c8_sjOadNODU1o7GnnhIh7lV5E_i31];
  }

  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i32;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i33;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i34;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u[9];
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_i32 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i33 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i33 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i33++) {
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i34 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i34 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i34++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_u[c8_sjOadNODU1o7GnnhIh7lV5E_i34 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i32] = (*(real_T (*)[9])
        c8_sjOadNODU1o7GnnhIh7lV5E_inData)[c8_sjOadNODU1o7GnnhIh7lV5E_i34 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i32];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i32 += 3;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i35;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u[3];
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i35 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i35 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i35++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_u[c8_sjOadNODU1o7GnnhIh7lV5E_i35] = (*(real_T (*)
      [3])c8_sjOadNODU1o7GnnhIh7lV5E_inData)[c8_sjOadNODU1o7GnnhIh7lV5E_i35];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_u = *(real_T *)c8_sjOadNODU1o7GnnhIh7lV5E_inData;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    &c8_sjOadNODU1o7GnnhIh7lV5E_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static real_T c8_sjOadNODU1o7GnnhIh7lV5E_e_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d0;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), &c8_sjOadNODU1o7GnnhIh7lV5E_d0,
                1, 0, 0U, 0, 0U, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_d0;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_nargout;
  const char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_nargout = sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
  c8_sjOadNODU1o7GnnhIh7lV5E_identifier = c8_sjOadNODU1o7GnnhIh7lV5E_varName;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_nargout),
     &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_nargout);
  *(real_T *)c8_sjOadNODU1o7GnnhIh7lV5E_outData = c8_sjOadNODU1o7GnnhIh7lV5E_y;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_u;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i36;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  char_T c8_sjOadNODU1o7GnnhIh7lV5E_b_u[17];
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_c_u;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_d_y = NULL;
  boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_d_u;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_e_y = NULL;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_u =
    *(c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE *)
    c8_sjOadNODU1o7GnnhIh7lV5E_inData;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_createstruct("structure",
    2, 1, 1), false);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i36 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i36 < 17;
       c8_sjOadNODU1o7GnnhIh7lV5E_i36++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_u[c8_sjOadNODU1o7GnnhIh7lV5E_i36] =
      c8_sjOadNODU1o7GnnhIh7lV5E_u.FcnName[c8_sjOadNODU1o7GnnhIh7lV5E_i36];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_b_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_b_u, 10, 0U, 1U, 0U, 2, 1, 17), false);
  sf_mex_addfield(c8_sjOadNODU1o7GnnhIh7lV5E_y, c8_sjOadNODU1o7GnnhIh7lV5E_b_y,
                  "FcnName", "FcnName", 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_c_y, sf_mex_create("y", NULL, 10, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_addfield(c8_sjOadNODU1o7GnnhIh7lV5E_y, c8_sjOadNODU1o7GnnhIh7lV5E_c_y,
                  "JacobianFcnName", "JacobianFcnName", 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_u = c8_sjOadNODU1o7GnnhIh7lV5E_u.HasJacobian;
  c8_sjOadNODU1o7GnnhIh7lV5E_d_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_d_y, sf_mex_create("y",
    &c8_sjOadNODU1o7GnnhIh7lV5E_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sjOadNODU1o7GnnhIh7lV5E_y, c8_sjOadNODU1o7GnnhIh7lV5E_d_y,
                  "HasJacobian", "HasJacobian", 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_d_u = c8_sjOadNODU1o7GnnhIh7lV5E_u.HasAdditiveNoise;
  c8_sjOadNODU1o7GnnhIh7lV5E_e_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_e_y, sf_mex_create("y",
    &c8_sjOadNODU1o7GnnhIh7lV5E_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sjOadNODU1o7GnnhIh7lV5E_y, c8_sjOadNODU1o7GnnhIh7lV5E_e_y,
                  "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  (void)c8_sjOadNODU1o7GnnhIh7lV5E_inData;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y", NULL, 0, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

const mxArray
  *sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_nameCaptureInfo = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_nameCaptureInfo, sf_mex_create(
    "nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1), false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_nameCaptureInfo;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_EKFCorrectorNonAdditive_correct
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_z[3], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_zcov[9], real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12],
   real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_P[144], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_c_x[12], real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_P[144])
{
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i37;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i38;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i39;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i40;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_z[3];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_zcov[9];
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i37 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i37 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i37++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_x[c8_sjOadNODU1o7GnnhIh7lV5E_i37] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i37];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i38 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i38 < 144;
       c8_sjOadNODU1o7GnnhIh7lV5E_i38++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_P[c8_sjOadNODU1o7GnnhIh7lV5E_i38] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i38];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i39 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i39 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i39++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_z[c8_sjOadNODU1o7GnnhIh7lV5E_i39] =
      c8_sjOadNODU1o7GnnhIh7lV5E_z[c8_sjOadNODU1o7GnnhIh7lV5E_i39];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i40 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i40 < 9;
       c8_sjOadNODU1o7GnnhIh7lV5E_i40++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_zcov[c8_sjOadNODU1o7GnnhIh7lV5E_i40] =
      c8_sjOadNODU1o7GnnhIh7lV5E_zcov[c8_sjOadNODU1o7GnnhIh7lV5E_i40];
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_b_EKFCorrectorNonAdditive_correct(chartInstance,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_z, c8_sjOadNODU1o7GnnhIh7lV5E_b_zcov,
    c8_sjOadNODU1o7GnnhIh7lV5E_c_x, c8_sjOadNODU1o7GnnhIh7lV5E_c_P);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_warning
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  static char_T c8_sjOadNODU1o7GnnhIh7lV5E_cv0[7] = { 'w', 'a', 'r', 'n', 'i',
    'n', 'g' };

  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  static char_T c8_sjOadNODU1o7GnnhIh7lV5E_cv1[7] = { 'm', 'e', 's', 's', 'a',
    'g', 'e' };

  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  static char_T c8_sjOadNODU1o7GnnhIh7lV5E_msgID[27] = { 'C', 'o', 'd', 'e', 'r',
    ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_cv0, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sjOadNODU1o7GnnhIh7lV5E_b_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_b_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_cv1, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_c_y, sf_mex_create("y",
    c8_sjOadNODU1o7GnnhIh7lV5E_msgID, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14,
                    c8_sjOadNODU1o7GnnhIh7lV5E_y, 14, sf_mex_call_debug
                    (sfGlobalDebugInstanceStruct, "feval", 1U, 2U, 14,
                     c8_sjOadNODU1o7GnnhIh7lV5E_b_y, 14,
                     c8_sjOadNODU1o7GnnhIh7lV5E_c_y));
}

static const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sjOadNODU1o7GnnhIh7lV5E_inData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_u;
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_u = *(int32_T *)c8_sjOadNODU1o7GnnhIh7lV5E_inData;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = NULL;
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_y, sf_mex_create("y",
    &c8_sjOadNODU1o7GnnhIh7lV5E_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData,
                c8_sjOadNODU1o7GnnhIh7lV5E_y, false);
  return c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayOutData;
}

static int32_T c8_sjOadNODU1o7GnnhIh7lV5E_f_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i41;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), &c8_sjOadNODU1o7GnnhIh7lV5E_i41,
                1, 6, 0U, 0, 0U, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_i41;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_sfEvent;
  const char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_sfEvent = sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
  c8_sjOadNODU1o7GnnhIh7lV5E_identifier = c8_sjOadNODU1o7GnnhIh7lV5E_varName;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_b_sfEvent),
     &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_sfEvent);
  *(int32_T *)c8_sjOadNODU1o7GnnhIh7lV5E_outData = c8_sjOadNODU1o7GnnhIh7lV5E_y;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
}

static c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
  c8_sjOadNODU1o7GnnhIh7lV5E_g_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_y;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  static const char * c8_sjOadNODU1o7GnnhIh7lV5E_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent =
    c8_sjOadNODU1o7GnnhIh7lV5E_parentId;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_sjOadNODU1o7GnnhIh7lV5E_parentId,
                      c8_sjOadNODU1o7GnnhIh7lV5E_u, 4,
                      c8_sjOadNODU1o7GnnhIh7lV5E_fieldNames, 0U, NULL);
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = "FcnName";
  c8_sjOadNODU1o7GnnhIh7lV5E_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sjOadNODU1o7GnnhIh7lV5E_u, "FcnName", "FcnName", 0)),
    &c8_sjOadNODU1o7GnnhIh7lV5E_thisId, c8_sjOadNODU1o7GnnhIh7lV5E_y.FcnName);
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = "JacobianFcnName";
  c8_sjOadNODU1o7GnnhIh7lV5E_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sjOadNODU1o7GnnhIh7lV5E_u, "JacobianFcnName",
                     "JacobianFcnName", 0)), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = "HasJacobian";
  c8_sjOadNODU1o7GnnhIh7lV5E_y.HasJacobian =
    c8_sjOadNODU1o7GnnhIh7lV5E_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sjOadNODU1o7GnnhIh7lV5E_u, "HasJacobian", "HasJacobian",
                     0)), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = "HasAdditiveNoise";
  c8_sjOadNODU1o7GnnhIh7lV5E_y.HasAdditiveNoise =
    c8_sjOadNODU1o7GnnhIh7lV5E_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sjOadNODU1o7GnnhIh7lV5E_u, "HasAdditiveNoise",
                     "HasAdditiveNoise", 0)), &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_h_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId, char_T
   c8_sjOadNODU1o7GnnhIh7lV5E_y[17])
{
  char_T c8_sjOadNODU1o7GnnhIh7lV5E_cv2[17];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i42;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), c8_sjOadNODU1o7GnnhIh7lV5E_cv2,
                1, 10, 0U, 1, 0U, 2, 1, 17);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i42 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i42 < 17;
       c8_sjOadNODU1o7GnnhIh7lV5E_i42++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_y[c8_sjOadNODU1o7GnnhIh7lV5E_i42] =
      c8_sjOadNODU1o7GnnhIh7lV5E_cv2[c8_sjOadNODU1o7GnnhIh7lV5E_i42];
  }

  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_i_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
}

static boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_j_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  boolean_T c8_sjOadNODU1o7GnnhIh7lV5E_b0;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), &c8_sjOadNODU1o7GnnhIh7lV5E_b0,
                1, 11, 0U, 0, 0U, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_b0;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData, const char_T
  *c8_sjOadNODU1o7GnnhIh7lV5E_varName, void *c8_sjOadNODU1o7GnnhIh7lV5E_outData)
{
  const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_b_pM;
  const char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE
    c8_sjOadNODU1o7GnnhIh7lV5E_y;
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sjOadNODU1o7GnnhIh7lV5E_b_pM = sf_mex_dup
    (c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
  c8_sjOadNODU1o7GnnhIh7lV5E_identifier = c8_sjOadNODU1o7GnnhIh7lV5E_varName;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sjOadNODU1o7GnnhIh7lV5E_b_pM),
     &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_b_pM);
  *(c8_sjOadNODU1o7GnnhIh7lV5E_sJc0LrpsE91c2htQpVlRXsE *)
    c8_sjOadNODU1o7GnnhIh7lV5E_outData = c8_sjOadNODU1o7GnnhIh7lV5E_y;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_mxArrayInData);
}

static uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_k_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sjOadNODU1o7GnnhIh7lV5E_b_is_active_c8_sjOadNODU1o7GnnhIh7lV5, const
   char_T *c8_sjOadNODU1o7GnnhIh7lV5E_identifier)
{
  uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  emlrtMsgIdentifier c8_sjOadNODU1o7GnnhIh7lV5E_thisId;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fIdentifier = (const char *)
    c8_sjOadNODU1o7GnnhIh7lV5E_identifier;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.fParent = NULL;
  c8_sjOadNODU1o7GnnhIh7lV5E_thisId.bParentIsCell = false;
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c8_sjOadNODU1o7GnnhIh7lV5E_b_is_active_c8_sjOadNODU1o7GnnhIh7lV5),
     &c8_sjOadNODU1o7GnnhIh7lV5E_thisId);
  sf_mex_destroy
    (&c8_sjOadNODU1o7GnnhIh7lV5E_b_is_active_c8_sjOadNODU1o7GnnhIh7lV5);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_l_emlrt_marshallIn
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sjOadNODU1o7GnnhIh7lV5E_u, const
   emlrtMsgIdentifier *c8_sjOadNODU1o7GnnhIh7lV5E_parentId)
{
  uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  uint8_T c8_sjOadNODU1o7GnnhIh7lV5E_u0;
  (void)chartInstance;
  sf_mex_import(c8_sjOadNODU1o7GnnhIh7lV5E_parentId, sf_mex_dup
                (c8_sjOadNODU1o7GnnhIh7lV5E_u), &c8_sjOadNODU1o7GnnhIh7lV5E_u0,
                1, 3, 0U, 0, 0U, 0);
  c8_sjOadNODU1o7GnnhIh7lV5E_y = c8_sjOadNODU1o7GnnhIh7lV5E_u0;
  sf_mex_destroy(&c8_sjOadNODU1o7GnnhIh7lV5E_u);
  return c8_sjOadNODU1o7GnnhIh7lV5E_y;
}

static void c8_sjOadNODU1o7GnnhIh7lV5E_b_EKFCorrectorNonAdditive_correct
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sjOadNODU1o7GnnhIh7lV5E_z[3], real_T
   c8_sjOadNODU1o7GnnhIh7lV5E_zcov[9], real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_x[12],
   real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_P[144])
{
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i43;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i44;
  c8_sjOadNODU1o7GnnhIh7lV5E_cell_2 c8_sjOadNODU1o7GnnhIh7lV5E_vec;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i45;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i46;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_imvec[12];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[3];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_z[3];
  c8_sjOadNODU1o7GnnhIh7lV5E_cell_2 c8_sjOadNODU1o7GnnhIh7lV5E_specvec;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i47;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i48;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i49;
  c8_sjOadNODU1o7GnnhIh7lV5E_cell_2 c8_sjOadNODU1o7GnnhIh7lV5E_b_vec;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i50;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_e_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_varargin_2;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i51;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_varargin_3;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_maxval;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_epsilon;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_c_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i52;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i53;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i54;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i55;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i56;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i57;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i58;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_f_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i59;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i60;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_g_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_h_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i61;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i62;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_e_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i63;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_gain[36];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[36];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_2;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_imz[3];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_3;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i64;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i65;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i66;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_f_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i67;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i68;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[36];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_g_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i69;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i70;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_h_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_B;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i71;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_maxval;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_i_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i72;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i73;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_epsilon;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_j_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i74;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_k_y[36];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_e_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i75;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i76;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i77;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i78;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i79;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i80;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i81;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i82;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i83;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i84;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i85;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i86;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i87;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[9];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i88;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i89;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i90;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i91;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_l_y[9];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i92;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i93;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i94;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i95;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i96;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i97;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i98;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i99;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b[9];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[9];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i100;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_B;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_m_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i101;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_n_y;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i102;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_f_j;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i103;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i104;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dv4[3];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_r1;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_r2;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_r3;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_i_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_j_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_k_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_l_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_o_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_m_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_n_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_o_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_p_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_maxval;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_p_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_q_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_r_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_s_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_q_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_t_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_v_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_r_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_a21;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_w_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_x_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ab_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_s_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_bb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_cb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_db_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_t_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_eb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_u_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_fb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_v_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_z;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_gb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_w_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_hb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_x_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_d_z;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ib_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_jb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_kb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_lb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_y_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_mb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_nb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ob_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ab_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_b_d;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_pb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_qb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_rb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_sb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_bb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_tb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ub_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_vb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_cb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_c_d;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_rtemp;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_wb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_db_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_xb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_eb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_e_z;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_k;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i105;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_yb_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_fb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ac_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i106;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_gb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_f_z;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i107;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i108;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i109;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_bc_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i110;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_hb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_cc_x;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ib_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_alpha1;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i111;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_g_z;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_beta1;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i112;
  char_T c8_sjOadNODU1o7GnnhIh7lV5E_TRANSB;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i113;
  char_T c8_sjOadNODU1o7GnnhIh7lV5E_TRANSA;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_dc_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i114;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_jb_y;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_kb_y[144];
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_ec_x;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i115;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_lb_y;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_m_t;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_mb_y[144];
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i116;
  real_T c8_sjOadNODU1o7GnnhIh7lV5E_h_z;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_n_t;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_k_t;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_lda_t;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_ldb_t;
  ptrdiff_t c8_sjOadNODU1o7GnnhIh7lV5E_ldc_t;
  int32_T c8_sjOadNODU1o7GnnhIh7lV5E_i117;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i43 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i43 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i43++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_vec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i43] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i43];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i44 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i44 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i44++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_vec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i44] = 0.0;
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i45 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i45 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i45++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i45] =
      c8_sjOadNODU1o7GnnhIh7lV5E_vec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i45];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i46 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i46 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i46++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i46] =
      c8_sjOadNODU1o7GnnhIh7lV5E_vec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i46];
  }

  CV_EML_FCN(0, 6);
  c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke(chartInstance,
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec, c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_z);
  c8_sjOadNODU1o7GnnhIh7lV5E_specvec = c8_sjOadNODU1o7GnnhIh7lV5E_vec;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_j = 0; c8_sjOadNODU1o7GnnhIh7lV5E_j < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_j++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_j = 1.0 + (real_T)c8_sjOadNODU1o7GnnhIh7lV5E_j;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i48 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i48 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i48++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i48] =
        c8_sjOadNODU1o7GnnhIh7lV5E_vec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i48];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_c_x =
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_b_j), 1, 12) - 1];
    c8_sjOadNODU1o7GnnhIh7lV5E_d_x = c8_sjOadNODU1o7GnnhIh7lV5E_c_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_e_x = c8_sjOadNODU1o7GnnhIh7lV5E_d_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_y = muDoubleScalarAbs
      (c8_sjOadNODU1o7GnnhIh7lV5E_e_x);
    c8_sjOadNODU1o7GnnhIh7lV5E_varargin_2 = 1.4901161193847656E-8 *
      c8_sjOadNODU1o7GnnhIh7lV5E_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_varargin_3 =
      c8_sjOadNODU1o7GnnhIh7lV5E_varargin_2;
    c8_sjOadNODU1o7GnnhIh7lV5E_b_y = c8_sjOadNODU1o7GnnhIh7lV5E_varargin_3;
    c8_sjOadNODU1o7GnnhIh7lV5E_c_y = c8_sjOadNODU1o7GnnhIh7lV5E_b_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_d_y = c8_sjOadNODU1o7GnnhIh7lV5E_c_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_sjOadNODU1o7GnnhIh7lV5E_d_y);
    c8_sjOadNODU1o7GnnhIh7lV5E_epsilon = c8_sjOadNODU1o7GnnhIh7lV5E_maxval;
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_b_j), 1, 12) - 1] =
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_b_j), 1, 12) - 1] +
      c8_sjOadNODU1o7GnnhIh7lV5E_epsilon;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i52 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i52 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i52++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i52] =
        c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i52];
    }

    for (c8_sjOadNODU1o7GnnhIh7lV5E_i56 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i56 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i56++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i56] =
        c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i56];
    }

    for (c8_sjOadNODU1o7GnnhIh7lV5E_i59 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i59 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i59++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i59] =
        c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i59];
    }

    CV_EML_FCN(0, 6);
    c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke(chartInstance,
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec, c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec,
      c8_sjOadNODU1o7GnnhIh7lV5E_imz);
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i64 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i64 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i64++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imz[c8_sjOadNODU1o7GnnhIh7lV5E_i64] -=
        c8_sjOadNODU1o7GnnhIh7lV5E_b_z[c8_sjOadNODU1o7GnnhIh7lV5E_i64];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_B = c8_sjOadNODU1o7GnnhIh7lV5E_epsilon;
    c8_sjOadNODU1o7GnnhIh7lV5E_i_y = c8_sjOadNODU1o7GnnhIh7lV5E_B;
    c8_sjOadNODU1o7GnnhIh7lV5E_j_y = c8_sjOadNODU1o7GnnhIh7lV5E_i_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_e_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_b_j), 1, 12) - 1;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i77 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i77 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i77++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[c8_sjOadNODU1o7GnnhIh7lV5E_i77 + 3 *
        c8_sjOadNODU1o7GnnhIh7lV5E_e_j] =
        c8_sjOadNODU1o7GnnhIh7lV5E_imz[c8_sjOadNODU1o7GnnhIh7lV5E_i77] /
        c8_sjOadNODU1o7GnnhIh7lV5E_j_y;
    }
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i47 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i47 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i47++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_vec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i47] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i47];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i49 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i49 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i49++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_vec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i49] = 0.0;
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i50 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i50 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i50++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i50] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_vec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i50];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i51 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i51 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i51++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i51] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_vec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i51];
  }

  CV_EML_FCN(0, 6);
  c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke(chartInstance,
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec, c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_z);
  c8_sjOadNODU1o7GnnhIh7lV5E_specvec = c8_sjOadNODU1o7GnnhIh7lV5E_b_vec;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_c_j = 0; c8_sjOadNODU1o7GnnhIh7lV5E_c_j < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_c_j++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_d_j = 1.0 + (real_T)
      c8_sjOadNODU1o7GnnhIh7lV5E_c_j;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i55 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i55 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i55++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i55] =
        c8_sjOadNODU1o7GnnhIh7lV5E_b_vec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i55];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_f_x =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_d_j), 1, 3) - 1];
    c8_sjOadNODU1o7GnnhIh7lV5E_g_x = c8_sjOadNODU1o7GnnhIh7lV5E_f_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_h_x = c8_sjOadNODU1o7GnnhIh7lV5E_g_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_e_y = muDoubleScalarAbs
      (c8_sjOadNODU1o7GnnhIh7lV5E_h_x);
    c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_2 = 1.4901161193847656E-8 *
      c8_sjOadNODU1o7GnnhIh7lV5E_e_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_3 =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_2;
    c8_sjOadNODU1o7GnnhIh7lV5E_f_y = c8_sjOadNODU1o7GnnhIh7lV5E_b_varargin_3;
    c8_sjOadNODU1o7GnnhIh7lV5E_g_y = c8_sjOadNODU1o7GnnhIh7lV5E_f_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_h_y = c8_sjOadNODU1o7GnnhIh7lV5E_g_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_b_maxval = muDoubleScalarMax
      (1.4901161193847656E-8, c8_sjOadNODU1o7GnnhIh7lV5E_h_y);
    c8_sjOadNODU1o7GnnhIh7lV5E_b_epsilon = c8_sjOadNODU1o7GnnhIh7lV5E_b_maxval;
    c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_d_j), 1, 3) - 1] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_d_j), 1, 3) - 1] +
      c8_sjOadNODU1o7GnnhIh7lV5E_b_epsilon;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i76 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i76 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i76++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i76] =
        c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i76];
    }

    for (c8_sjOadNODU1o7GnnhIh7lV5E_i83 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i83 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i83++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i83] =
        c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f1[c8_sjOadNODU1o7GnnhIh7lV5E_i83];
    }

    for (c8_sjOadNODU1o7GnnhIh7lV5E_i88 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i88 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i88++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i88] =
        c8_sjOadNODU1o7GnnhIh7lV5E_specvec.f2[c8_sjOadNODU1o7GnnhIh7lV5E_i88];
    }

    CV_EML_FCN(0, 6);
    c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke(chartInstance,
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec, c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec,
      c8_sjOadNODU1o7GnnhIh7lV5E_imz);
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i98 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i98 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i98++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imz[c8_sjOadNODU1o7GnnhIh7lV5E_i98] -=
        c8_sjOadNODU1o7GnnhIh7lV5E_b_z[c8_sjOadNODU1o7GnnhIh7lV5E_i98];
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_b_B = c8_sjOadNODU1o7GnnhIh7lV5E_b_epsilon;
    c8_sjOadNODU1o7GnnhIh7lV5E_m_y = c8_sjOadNODU1o7GnnhIh7lV5E_b_B;
    c8_sjOadNODU1o7GnnhIh7lV5E_n_y = c8_sjOadNODU1o7GnnhIh7lV5E_m_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_f_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sjOadNODU1o7GnnhIh7lV5E_d_j), 1, 3) - 1;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i104 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i104 <
         3; c8_sjOadNODU1o7GnnhIh7lV5E_i104++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i104 + 3 *
        c8_sjOadNODU1o7GnnhIh7lV5E_f_j] =
        c8_sjOadNODU1o7GnnhIh7lV5E_imz[c8_sjOadNODU1o7GnnhIh7lV5E_i104] /
        c8_sjOadNODU1o7GnnhIh7lV5E_n_y;
    }
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_i53 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i54 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i54 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i54++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i58 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i60 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i60 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i60++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i60 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i53] =
        c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[c8_sjOadNODU1o7GnnhIh7lV5E_i58 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i54];
      c8_sjOadNODU1o7GnnhIh7lV5E_i58 += 3;
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i53 += 12;
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i57 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i57 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i57++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i62 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i63 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i63 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i63++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[c8_sjOadNODU1o7GnnhIh7lV5E_i62 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i57] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i70 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i71 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i71 <
           12; c8_sjOadNODU1o7GnnhIh7lV5E_i71++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[c8_sjOadNODU1o7GnnhIh7lV5E_i62 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i57] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i70 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i57] *
          c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i71 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i62];
        c8_sjOadNODU1o7GnnhIh7lV5E_i70 += 12;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i62 += 12;
    }
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i61 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i61 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i61++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i66 = 0;
    c8_sjOadNODU1o7GnnhIh7lV5E_i68 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i69 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i69 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i69++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_k_y[c8_sjOadNODU1o7GnnhIh7lV5E_i66 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i61] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i75 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i80 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i80 <
           12; c8_sjOadNODU1o7GnnhIh7lV5E_i80++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_k_y[c8_sjOadNODU1o7GnnhIh7lV5E_i66 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i61] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[c8_sjOadNODU1o7GnnhIh7lV5E_i75 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i61] *
          c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i80 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i68];
        c8_sjOadNODU1o7GnnhIh7lV5E_i75 += 3;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i66 += 3;
      c8_sjOadNODU1o7GnnhIh7lV5E_i68 += 12;
    }
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_i65 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i67 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i67 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i67++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i73 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i74 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i74 < 12;
         c8_sjOadNODU1o7GnnhIh7lV5E_i74++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i74 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i65] =
        c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[c8_sjOadNODU1o7GnnhIh7lV5E_i73 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i67];
      c8_sjOadNODU1o7GnnhIh7lV5E_i73 += 3;
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i65 += 12;
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i72 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i72 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i72++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i79 = 0;
    c8_sjOadNODU1o7GnnhIh7lV5E_i81 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i82 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i82 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i82++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_i79 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i72] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i89 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i92 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i92 <
           12; c8_sjOadNODU1o7GnnhIh7lV5E_i92++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_i79 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i72] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_k_y[c8_sjOadNODU1o7GnnhIh7lV5E_i89 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i72] *
          c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i92 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i81];
        c8_sjOadNODU1o7GnnhIh7lV5E_i89 += 3;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i79 += 3;
      c8_sjOadNODU1o7GnnhIh7lV5E_i81 += 12;
    }
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i78 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i78 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i78++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i85 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i87 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i87 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i87++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_l_y[c8_sjOadNODU1o7GnnhIh7lV5E_i85 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i78] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i94 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i95 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i95 <
           3; c8_sjOadNODU1o7GnnhIh7lV5E_i95++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_l_y[c8_sjOadNODU1o7GnnhIh7lV5E_i85 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i78] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i94 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i78] *
          c8_sjOadNODU1o7GnnhIh7lV5E_zcov[c8_sjOadNODU1o7GnnhIh7lV5E_i95 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i85];
        c8_sjOadNODU1o7GnnhIh7lV5E_i94 += 3;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i85 += 3;
    }
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_i84 = 0;
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i86 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i86 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i86++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i91 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i93 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i93 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i93++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_b[c8_sjOadNODU1o7GnnhIh7lV5E_i93 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i84] =
        c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i91 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i86];
      c8_sjOadNODU1o7GnnhIh7lV5E_i91 += 3;
    }

    c8_sjOadNODU1o7GnnhIh7lV5E_i84 += 3;
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i90 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i90 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i90++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i97 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i99 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i99 < 3;
         c8_sjOadNODU1o7GnnhIh7lV5E_i99++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i97 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i90] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i101 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i102 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i102 <
           3; c8_sjOadNODU1o7GnnhIh7lV5E_i102++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i97 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i90] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_l_y[c8_sjOadNODU1o7GnnhIh7lV5E_i101 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i90] *
          c8_sjOadNODU1o7GnnhIh7lV5E_b[c8_sjOadNODU1o7GnnhIh7lV5E_i102 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i97];
        c8_sjOadNODU1o7GnnhIh7lV5E_i101 += 3;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i97 += 3;
    }
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i96 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i96 < 9;
       c8_sjOadNODU1o7GnnhIh7lV5E_i96++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_i96] +=
      c8_sjOadNODU1o7GnnhIh7lV5E_dHdv[c8_sjOadNODU1o7GnnhIh7lV5E_i96];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i100 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i100 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i100++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i100] =
      c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i100];
  }

  CV_EML_FCN(0, 6);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i103 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i103 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i103++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_dv4[c8_sjOadNODU1o7GnnhIh7lV5E_i103] = 0.0;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_measurementTWBFcn_invoke(chartInstance,
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec, c8_sjOadNODU1o7GnnhIh7lV5E_dv4,
    c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec);
  c8_sjOadNODU1o7GnnhIh7lV5E_r1 = 0;
  c8_sjOadNODU1o7GnnhIh7lV5E_r2 = 1;
  c8_sjOadNODU1o7GnnhIh7lV5E_r3 = 2;
  c8_sjOadNODU1o7GnnhIh7lV5E_i_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[0];
  c8_sjOadNODU1o7GnnhIh7lV5E_j_x = c8_sjOadNODU1o7GnnhIh7lV5E_i_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_k_x = c8_sjOadNODU1o7GnnhIh7lV5E_j_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_l_x = c8_sjOadNODU1o7GnnhIh7lV5E_k_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_o_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_l_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_m_x = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_n_x = c8_sjOadNODU1o7GnnhIh7lV5E_m_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_o_x = c8_sjOadNODU1o7GnnhIh7lV5E_n_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_p_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_o_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_maxval = c8_sjOadNODU1o7GnnhIh7lV5E_o_y +
    c8_sjOadNODU1o7GnnhIh7lV5E_p_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_p_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[1];
  c8_sjOadNODU1o7GnnhIh7lV5E_q_x = c8_sjOadNODU1o7GnnhIh7lV5E_p_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_r_x = c8_sjOadNODU1o7GnnhIh7lV5E_q_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_s_x = c8_sjOadNODU1o7GnnhIh7lV5E_r_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_q_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_s_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_t_x = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_u_x = c8_sjOadNODU1o7GnnhIh7lV5E_t_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_v_x = c8_sjOadNODU1o7GnnhIh7lV5E_u_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_r_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_v_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_a21 = c8_sjOadNODU1o7GnnhIh7lV5E_q_y +
    c8_sjOadNODU1o7GnnhIh7lV5E_r_y;
  if (c8_sjOadNODU1o7GnnhIh7lV5E_a21 > c8_sjOadNODU1o7GnnhIh7lV5E_c_maxval) {
    c8_sjOadNODU1o7GnnhIh7lV5E_c_maxval = c8_sjOadNODU1o7GnnhIh7lV5E_a21;
    c8_sjOadNODU1o7GnnhIh7lV5E_r1 = 1;
    c8_sjOadNODU1o7GnnhIh7lV5E_r2 = 0;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_w_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[2];
  c8_sjOadNODU1o7GnnhIh7lV5E_x_x = c8_sjOadNODU1o7GnnhIh7lV5E_w_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_y_x = c8_sjOadNODU1o7GnnhIh7lV5E_x_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_ab_x = c8_sjOadNODU1o7GnnhIh7lV5E_y_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_s_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_ab_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_bb_x = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_cb_x = c8_sjOadNODU1o7GnnhIh7lV5E_bb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_db_x = c8_sjOadNODU1o7GnnhIh7lV5E_cb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_t_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_db_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_d = c8_sjOadNODU1o7GnnhIh7lV5E_s_y +
    c8_sjOadNODU1o7GnnhIh7lV5E_t_y;
  if (c8_sjOadNODU1o7GnnhIh7lV5E_d > c8_sjOadNODU1o7GnnhIh7lV5E_c_maxval) {
    c8_sjOadNODU1o7GnnhIh7lV5E_r1 = 2;
    c8_sjOadNODU1o7GnnhIh7lV5E_r2 = 1;
    c8_sjOadNODU1o7GnnhIh7lV5E_r3 = 0;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_eb_x =
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r2];
  c8_sjOadNODU1o7GnnhIh7lV5E_u_y =
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_fb_x = c8_sjOadNODU1o7GnnhIh7lV5E_eb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_v_y = c8_sjOadNODU1o7GnnhIh7lV5E_u_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_c_z = c8_sjOadNODU1o7GnnhIh7lV5E_fb_x /
    c8_sjOadNODU1o7GnnhIh7lV5E_v_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r2] =
    c8_sjOadNODU1o7GnnhIh7lV5E_c_z;
  c8_sjOadNODU1o7GnnhIh7lV5E_gb_x =
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r3];
  c8_sjOadNODU1o7GnnhIh7lV5E_w_y =
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_hb_x = c8_sjOadNODU1o7GnnhIh7lV5E_gb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_x_y = c8_sjOadNODU1o7GnnhIh7lV5E_w_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_d_z = c8_sjOadNODU1o7GnnhIh7lV5E_hb_x /
    c8_sjOadNODU1o7GnnhIh7lV5E_x_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r3] =
    c8_sjOadNODU1o7GnnhIh7lV5E_d_z;
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r2] -=
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r2] *
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] -=
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r3] *
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r2] -=
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r2] *
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] -=
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r3] *
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r1];
  c8_sjOadNODU1o7GnnhIh7lV5E_ib_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
    c8_sjOadNODU1o7GnnhIh7lV5E_r3];
  c8_sjOadNODU1o7GnnhIh7lV5E_jb_x = c8_sjOadNODU1o7GnnhIh7lV5E_ib_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_kb_x = c8_sjOadNODU1o7GnnhIh7lV5E_jb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_lb_x = c8_sjOadNODU1o7GnnhIh7lV5E_kb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_y_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_lb_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_mb_x = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_nb_x = c8_sjOadNODU1o7GnnhIh7lV5E_mb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_ob_x = c8_sjOadNODU1o7GnnhIh7lV5E_nb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_ab_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_ob_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_b_d = c8_sjOadNODU1o7GnnhIh7lV5E_y_y +
    c8_sjOadNODU1o7GnnhIh7lV5E_ab_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_pb_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
    c8_sjOadNODU1o7GnnhIh7lV5E_r2];
  c8_sjOadNODU1o7GnnhIh7lV5E_qb_x = c8_sjOadNODU1o7GnnhIh7lV5E_pb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_rb_x = c8_sjOadNODU1o7GnnhIh7lV5E_qb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_sb_x = c8_sjOadNODU1o7GnnhIh7lV5E_rb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_bb_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_sb_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_tb_x = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_ub_x = c8_sjOadNODU1o7GnnhIh7lV5E_tb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_vb_x = c8_sjOadNODU1o7GnnhIh7lV5E_ub_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_cb_y = muDoubleScalarAbs
    (c8_sjOadNODU1o7GnnhIh7lV5E_vb_x);
  c8_sjOadNODU1o7GnnhIh7lV5E_c_d = c8_sjOadNODU1o7GnnhIh7lV5E_bb_y +
    c8_sjOadNODU1o7GnnhIh7lV5E_cb_y;
  if (c8_sjOadNODU1o7GnnhIh7lV5E_b_d > c8_sjOadNODU1o7GnnhIh7lV5E_c_d) {
    c8_sjOadNODU1o7GnnhIh7lV5E_rtemp = c8_sjOadNODU1o7GnnhIh7lV5E_r2 + 1;
    c8_sjOadNODU1o7GnnhIh7lV5E_r2 = c8_sjOadNODU1o7GnnhIh7lV5E_r3;
    c8_sjOadNODU1o7GnnhIh7lV5E_r3 = c8_sjOadNODU1o7GnnhIh7lV5E_rtemp - 1;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_wb_x = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
    c8_sjOadNODU1o7GnnhIh7lV5E_r3];
  c8_sjOadNODU1o7GnnhIh7lV5E_db_y = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
    c8_sjOadNODU1o7GnnhIh7lV5E_r2];
  c8_sjOadNODU1o7GnnhIh7lV5E_xb_x = c8_sjOadNODU1o7GnnhIh7lV5E_wb_x;
  c8_sjOadNODU1o7GnnhIh7lV5E_eb_y = c8_sjOadNODU1o7GnnhIh7lV5E_db_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_e_z = c8_sjOadNODU1o7GnnhIh7lV5E_xb_x /
    c8_sjOadNODU1o7GnnhIh7lV5E_eb_y;
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] =
    c8_sjOadNODU1o7GnnhIh7lV5E_e_z;
  c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] -=
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] *
    c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r2];
  if ((c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r1] == 0.0) ||
      (c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 + c8_sjOadNODU1o7GnnhIh7lV5E_r2] == 0.0)
      || (c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 + c8_sjOadNODU1o7GnnhIh7lV5E_r3] ==
          0.0)) {
    c8_sjOadNODU1o7GnnhIh7lV5E_warning(chartInstance);
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_k = 0; c8_sjOadNODU1o7GnnhIh7lV5E_k + 1 < 13;
       c8_sjOadNODU1o7GnnhIh7lV5E_k++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_yb_x =
      c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[c8_sjOadNODU1o7GnnhIh7lV5E_k];
    c8_sjOadNODU1o7GnnhIh7lV5E_fb_y =
      c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r1];
    c8_sjOadNODU1o7GnnhIh7lV5E_ac_x = c8_sjOadNODU1o7GnnhIh7lV5E_yb_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_gb_y = c8_sjOadNODU1o7GnnhIh7lV5E_fb_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_f_z = c8_sjOadNODU1o7GnnhIh7lV5E_ac_x /
      c8_sjOadNODU1o7GnnhIh7lV5E_gb_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r1] = c8_sjOadNODU1o7GnnhIh7lV5E_f_z;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2] = c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[12 +
      c8_sjOadNODU1o7GnnhIh7lV5E_k] -
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r1] * c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r1];
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3] = c8_sjOadNODU1o7GnnhIh7lV5E_Pxy[24 +
      c8_sjOadNODU1o7GnnhIh7lV5E_k] -
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r1] * c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r1];
    c8_sjOadNODU1o7GnnhIh7lV5E_bc_x =
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2];
    c8_sjOadNODU1o7GnnhIh7lV5E_hb_y = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r2];
    c8_sjOadNODU1o7GnnhIh7lV5E_cc_x = c8_sjOadNODU1o7GnnhIh7lV5E_bc_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_ib_y = c8_sjOadNODU1o7GnnhIh7lV5E_hb_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_g_z = c8_sjOadNODU1o7GnnhIh7lV5E_cc_x /
      c8_sjOadNODU1o7GnnhIh7lV5E_ib_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2] = c8_sjOadNODU1o7GnnhIh7lV5E_g_z;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3] -=
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2] * c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r2];
    c8_sjOadNODU1o7GnnhIh7lV5E_dc_x =
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3];
    c8_sjOadNODU1o7GnnhIh7lV5E_jb_y = c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[6 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r3];
    c8_sjOadNODU1o7GnnhIh7lV5E_ec_x = c8_sjOadNODU1o7GnnhIh7lV5E_dc_x;
    c8_sjOadNODU1o7GnnhIh7lV5E_lb_y = c8_sjOadNODU1o7GnnhIh7lV5E_jb_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_h_z = c8_sjOadNODU1o7GnnhIh7lV5E_ec_x /
      c8_sjOadNODU1o7GnnhIh7lV5E_lb_y;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3] = c8_sjOadNODU1o7GnnhIh7lV5E_h_z;
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2] -=
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3] * c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[3 +
      c8_sjOadNODU1o7GnnhIh7lV5E_r3];
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r1] -=
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r3] *
      c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r3];
    c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r1] -=
      c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_k + 12 *
      c8_sjOadNODU1o7GnnhIh7lV5E_r2] *
      c8_sjOadNODU1o7GnnhIh7lV5E_Pyy[c8_sjOadNODU1o7GnnhIh7lV5E_r2];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i105 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i105 < 3;
       c8_sjOadNODU1o7GnnhIh7lV5E_i105++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i105] =
      c8_sjOadNODU1o7GnnhIh7lV5E_z[c8_sjOadNODU1o7GnnhIh7lV5E_i105] -
      c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i105];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i106 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i106 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i106++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i106] = 0.0;
    c8_sjOadNODU1o7GnnhIh7lV5E_i108 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i109 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i109 <
         3; c8_sjOadNODU1o7GnnhIh7lV5E_i109++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i106] +=
        c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i108 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i106] *
        c8_sjOadNODU1o7GnnhIh7lV5E_b_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i109];
      c8_sjOadNODU1o7GnnhIh7lV5E_i108 += 12;
    }
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i107 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i107 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i107++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_x[c8_sjOadNODU1o7GnnhIh7lV5E_i107] +=
      c8_sjOadNODU1o7GnnhIh7lV5E_imvec[c8_sjOadNODU1o7GnnhIh7lV5E_i107];
  }

  for (c8_sjOadNODU1o7GnnhIh7lV5E_i110 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i110 < 12;
       c8_sjOadNODU1o7GnnhIh7lV5E_i110++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_i111 = 0;
    c8_sjOadNODU1o7GnnhIh7lV5E_i112 = 0;
    for (c8_sjOadNODU1o7GnnhIh7lV5E_i113 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i113 <
         12; c8_sjOadNODU1o7GnnhIh7lV5E_i113++) {
      c8_sjOadNODU1o7GnnhIh7lV5E_kb_y[c8_sjOadNODU1o7GnnhIh7lV5E_i111 +
        c8_sjOadNODU1o7GnnhIh7lV5E_i110] = 0.0;
      c8_sjOadNODU1o7GnnhIh7lV5E_i115 = 0;
      for (c8_sjOadNODU1o7GnnhIh7lV5E_i116 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i116 <
           3; c8_sjOadNODU1o7GnnhIh7lV5E_i116++) {
        c8_sjOadNODU1o7GnnhIh7lV5E_kb_y[c8_sjOadNODU1o7GnnhIh7lV5E_i111 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i110] +=
          c8_sjOadNODU1o7GnnhIh7lV5E_gain[c8_sjOadNODU1o7GnnhIh7lV5E_i115 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i110] *
          c8_sjOadNODU1o7GnnhIh7lV5E_dHdx[c8_sjOadNODU1o7GnnhIh7lV5E_i116 +
          c8_sjOadNODU1o7GnnhIh7lV5E_i112];
        c8_sjOadNODU1o7GnnhIh7lV5E_i115 += 12;
      }

      c8_sjOadNODU1o7GnnhIh7lV5E_i111 += 12;
      c8_sjOadNODU1o7GnnhIh7lV5E_i112 += 3;
    }
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_alpha1 = 1.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_beta1 = 0.0;
  c8_sjOadNODU1o7GnnhIh7lV5E_TRANSB = 'N';
  c8_sjOadNODU1o7GnnhIh7lV5E_TRANSA = 'N';
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i114 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i114 <
       144; c8_sjOadNODU1o7GnnhIh7lV5E_i114++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_mb_y[c8_sjOadNODU1o7GnnhIh7lV5E_i114] = 0.0;
  }

  c8_sjOadNODU1o7GnnhIh7lV5E_m_t = (ptrdiff_t)12;
  c8_sjOadNODU1o7GnnhIh7lV5E_n_t = (ptrdiff_t)12;
  c8_sjOadNODU1o7GnnhIh7lV5E_k_t = (ptrdiff_t)12;
  c8_sjOadNODU1o7GnnhIh7lV5E_lda_t = (ptrdiff_t)12;
  c8_sjOadNODU1o7GnnhIh7lV5E_ldb_t = (ptrdiff_t)12;
  c8_sjOadNODU1o7GnnhIh7lV5E_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sjOadNODU1o7GnnhIh7lV5E_TRANSA, &c8_sjOadNODU1o7GnnhIh7lV5E_TRANSB,
        &c8_sjOadNODU1o7GnnhIh7lV5E_m_t, &c8_sjOadNODU1o7GnnhIh7lV5E_n_t,
        &c8_sjOadNODU1o7GnnhIh7lV5E_k_t, &c8_sjOadNODU1o7GnnhIh7lV5E_alpha1,
        &c8_sjOadNODU1o7GnnhIh7lV5E_kb_y[0], &c8_sjOadNODU1o7GnnhIh7lV5E_lda_t,
        &c8_sjOadNODU1o7GnnhIh7lV5E_b_P[0], &c8_sjOadNODU1o7GnnhIh7lV5E_ldb_t,
        &c8_sjOadNODU1o7GnnhIh7lV5E_beta1, &c8_sjOadNODU1o7GnnhIh7lV5E_mb_y[0],
        &c8_sjOadNODU1o7GnnhIh7lV5E_ldc_t);
  for (c8_sjOadNODU1o7GnnhIh7lV5E_i117 = 0; c8_sjOadNODU1o7GnnhIh7lV5E_i117 <
       144; c8_sjOadNODU1o7GnnhIh7lV5E_i117++) {
    c8_sjOadNODU1o7GnnhIh7lV5E_b_P[c8_sjOadNODU1o7GnnhIh7lV5E_i117] -=
      c8_sjOadNODU1o7GnnhIh7lV5E_mb_y[c8_sjOadNODU1o7GnnhIh7lV5E_i117];
  }
}

static void init_dsm_address_info
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_fEmlrtCtx = (void *)sfrtGetEmlrtCtx
    (chartInstance->S);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_x = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew = (real_T (*)[12])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_P = (real_T (*)[144])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew = (real_T (*)[144])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_yMeas = (real_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_R = (real_T (*)[9])
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

void sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1116952890U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2832577031U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1015026614U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1036539119U);
}

mxArray*
  sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray
  *sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("s34UQQKnwGy0O39qiWAOYD");
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_jit_fallback_info
  (void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("client_server");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("measurementTWBFcn");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray
  *sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray*
  sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "IsFIIZlLLNrBUKg6wktOKD");
    mwSize exp_dims[2] = { 1, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);

    {
      mxArray* mxFcnName = mxCreateString("measurementTWBFcn");
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
  *sf_get_sim_state_info_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
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
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_d_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_c_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallOut,
            (MexInFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallOut,
            (MexInFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_f_sf_marshallOut,
          (MexInFcnForType)c8_sjOadNODU1o7GnnhIh7lV5E_e_sf_marshallIn);
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
    SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          &chartInstance->c8_sjOadNODU1o7GnnhIh7lV5E_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sjOadNODU1o7GnnhIh7lV5E";
}

static void
  sf_opaque_initialize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
  initialize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  enable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  disable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  sf_gateway_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SimStruct* S)
{
  return get_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void
  sf_opaque_set_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
      ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
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
  initSimStructsc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
    ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
      ((SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary
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
  ssSetChecksum0(S,(1116952890U));
  ssSetChecksum1(S,(2832577031U));
  ssSetChecksum2(S,(1015026614U));
  ssSetChecksum3(S,(1036539119U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(SimStruct *
  S)
{
  SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct *)utMalloc
    (sizeof(SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary;
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
  mdl_start_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(chartInstance);
}

void c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_sjOadNODU1o7GnnhIh7lV5E_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
