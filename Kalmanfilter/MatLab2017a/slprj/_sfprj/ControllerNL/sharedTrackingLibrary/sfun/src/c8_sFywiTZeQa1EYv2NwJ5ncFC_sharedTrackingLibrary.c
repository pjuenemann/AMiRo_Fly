/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary.h"
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
static const char * c8_sFywiTZeQa1EYv2NwJ5ncFC_debug_family_names[10] = {
  "MeasurementFcn", "pM", "nargin", "nargout", "x", "P", "yMeas", "R", "xNew",
  "PNew" };

/* Function Declarations */
static void initialize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initialize_params_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void enable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void disable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_update_debugger_state_c8_sFywiTZeQa1E
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void set_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_st);
static void finalize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void sf_gateway_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void mdl_start_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initSimStructsc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_measurementTWBFcn_invoke
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[3]);
static void init_script_number_translation(uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_machineNumber, uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_chartNumber, uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_instanceNumber);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[144]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[144]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_c_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[12]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_d_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[12]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_e_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_EKFCorrectorAdditive_correct
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_z[3], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[9], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12],
   real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[144], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x[12], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_P[144]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_warning
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData);
static int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_f_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData);
static c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
  c8_sFywiTZeQa1EYv2NwJ5ncFC_g_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_h_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, char_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[17]);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_i_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_j_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData);
static uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_k_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_is_active_c8_sFywiTZeQa1EYv2NwJ5ncF, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier);
static uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_l_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId);
static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_EKFCorrectorAdditive_correct
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_z[3], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[9], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12],
   real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[144]);
static void init_dsm_address_info
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void init_simulink_io_address
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_
    = 0U;
}

static void initialize_params_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_m0 = NULL;
  static const char * c8_sFywiTZeQa1EYv2NwJ5ncFC_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c8_sFywiTZeQa1EYv2NwJ5ncFC_m0, 4,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_fieldNames, "sJc0LrpsE91c2htQpVlRXsE");
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField = sf_mex_getfield
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField),
                      c8_sFywiTZeQa1EYv2NwJ5ncFC_r0.FcnName, 1, 10, 0U, 1, 0U, 2,
                      1, 17);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField = sf_mex_getfield
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_m0, "JacobianFcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField), NULL,
                      1, 10, 0U, 1, 0U, 2, 0, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField = sf_mex_getfield
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_m0, "HasJacobian", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField),
                      &c8_sFywiTZeQa1EYv2NwJ5ncFC_r0.HasJacobian, 1, 11, 0U, 0,
                      0U, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField = sf_mex_getfield
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_mxField),
                      &c8_sFywiTZeQa1EYv2NwJ5ncFC_r0.HasAdditiveNoise, 1, 11, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_m0);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_pM = c8_sFywiTZeQa1EYv2NwJ5ncFC_r0;
}

static void enable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_update_debugger_state_c8_sFywiTZeQa1E
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_st;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_hoistedGlobal;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_st = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_st = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_createcellmatrix(3, 1),
                false);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y, sf_mex_create("y",
    *chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, 0, c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y, sf_mex_create("y",
    *chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew, 0, 0U, 1U, 0U, 1, 12),
                false);
  sf_mex_setcell(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, 1, c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_hoistedGlobal =
    chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y, sf_mex_create("y",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_hoistedGlobal, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, 2, c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_st, c8_sFywiTZeQa1EYv2NwJ5ncFC_y,
                false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_st;
}

static void set_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_st)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_dv0[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i0;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_dv1[12];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i1;
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_doneDoubleBufferReInit = true;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u = sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_st);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PNew", c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0)), "PNew",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_dv0);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i0 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i0 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i0++) {
    (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i0] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_dv0[c8_sFywiTZeQa1EYv2NwJ5ncFC_i0];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xNew", c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 1)), "xNew",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_dv1);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i1 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i1 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i1++) {
    (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i1] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_dv1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i1];
  }

  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_
    = c8_sFywiTZeQa1EYv2NwJ5ncFC_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary",
                    c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 2)),
    "is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary");
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_update_debugger_state_c8_sFywiTZeQa1E(chartInstance);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_st);
}

static void finalize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i2;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i3;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i4;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i5;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i6;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i7;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i8;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i9;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_yMeas[3];
  uint32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_debug_family_var_map[10];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_R[9];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_nargin = 4.0;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout = 2.0;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew[12];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew[144];
  static c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r1 = { { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'm',
      'e', 'n', 't', 'T', 'W', 'B', 'F', 'c', 'n' },/* FcnName */
    false,                             /* HasJacobian */
    true                               /* HasAdditiveNoise */
  };

  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i10;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i11;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i12;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i13;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_xNew[12];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i14;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_PNew[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i15;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_yMeas[3];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_R[9];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i16;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i17;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i18;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i19;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i20;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i2 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i2 < 9;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_R)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i2], 3U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i3 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i3 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_yMeas)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i3], 2U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i4 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i4 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_P)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i4], 1U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i5 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i5 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_x)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i5], 0U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }

  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i6 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i6 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i6++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i6] =
      (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_x)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i6];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i7 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i7 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i7++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i7] =
      (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_P)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i7];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i8 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i8 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i8++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_yMeas[c8_sFywiTZeQa1EYv2NwJ5ncFC_i8] =
      (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_yMeas)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i8];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i9 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i9 < 9;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i9++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_R[c8_sFywiTZeQa1EYv2NwJ5ncFC_i9] =
      (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_R)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_debug_family_names,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM, 1U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sFywiTZeQa1EYv2NwJ5ncFC_nargin, 2U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallOut,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout, 3U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallOut,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x, 4U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P, 5U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_yMeas, 6U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_R, 7U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew, 8U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew, 9U,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallIn);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM = c8_sFywiTZeQa1EYv2NwJ5ncFC_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 7);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i10 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i10 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i10++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 8);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i11 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i11 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i11++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 9);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 10);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, 14);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i12 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i12 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i12++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_xNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i12] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i12];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i13 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i13 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i13++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_PNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i13] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i13];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i14 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i14 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i14++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_yMeas[c8_sFywiTZeQa1EYv2NwJ5ncFC_i14] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_yMeas[c8_sFywiTZeQa1EYv2NwJ5ncFC_i14];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i15 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i15 < 9;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i15++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_R[c8_sFywiTZeQa1EYv2NwJ5ncFC_i15] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_R[c8_sFywiTZeQa1EYv2NwJ5ncFC_i15];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_yMeas, c8_sFywiTZeQa1EYv2NwJ5ncFC_c_R,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_xNew, c8_sFywiTZeQa1EYv2NwJ5ncFC_c_PNew);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i16 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i16 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i16++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i16] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_c_xNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i16];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i17 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i17 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i17++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i17] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_c_PNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i18 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i18 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i18++) {
    (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i18] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i18];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i19 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i19 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i19++) {
    (*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i19] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew[c8_sFywiTZeQa1EYv2NwJ5ncFC_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i20 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i20 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i20], 4U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i21 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i21 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew)
                          [c8_sFywiTZeQa1EYv2NwJ5ncFC_i21], 5U, 1U, 0U,
                          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_sfEvent,
                          false);
  }
}

static void mdl_start_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_measurementTWBFcn_invoke
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[3])
{
  _ssFcnCallExecArgInfo c8_sFywiTZeQa1EYv2NwJ5ncFC_args[2];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_args[0U].dataPtr = (void *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_args[1U].dataPtr = (void *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "measurementTWBFcn",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_args[0U]);
}

static void init_script_number_translation(uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_machineNumber, uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_chartNumber, uint32_T
  c8_sFywiTZeQa1EYv2NwJ5ncFC_instanceNumber)
{
  (void)(c8_sFywiTZeQa1EYv2NwJ5ncFC_machineNumber);
  (void)(c8_sFywiTZeQa1EYv2NwJ5ncFC_chartNumber);
  (void)(c8_sFywiTZeQa1EYv2NwJ5ncFC_instanceNumber);
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i22;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i23;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i24;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u[144];
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i22 = 0;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i23 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i23 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i23++) {
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i24 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i24 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i24++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_u[c8_sFywiTZeQa1EYv2NwJ5ncFC_i24 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i22] = (*(real_T (*)[144])
        c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)[c8_sFywiTZeQa1EYv2NwJ5ncFC_i24 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i22];
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_i22 += 12;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[144])
{
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[144])
{
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_dv2[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i25;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), c8_sFywiTZeQa1EYv2NwJ5ncFC_dv2,
                1, 0, 0U, 1, 0U, 2, 12, 12);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i25 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i25 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i25++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i25] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_dv2[c8_sFywiTZeQa1EYv2NwJ5ncFC_i25];
  }

  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew;
  const char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i26;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i27;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i28;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew = sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier = c8_sFywiTZeQa1EYv2NwJ5ncFC_varName;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_PNew);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i26 = 0;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i27 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i27 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i27++) {
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i28 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i28 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i28++) {
      (*(real_T (*)[144])c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
        [c8_sFywiTZeQa1EYv2NwJ5ncFC_i28 + c8_sFywiTZeQa1EYv2NwJ5ncFC_i26] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i28 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i26];
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_i26 += 12;
  }

  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i29;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u[12];
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i29 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i29 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i29++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u[c8_sFywiTZeQa1EYv2NwJ5ncFC_i29] = (*(real_T (*)
      [12])c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)[c8_sFywiTZeQa1EYv2NwJ5ncFC_i29];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_c_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[12])
{
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_d_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[12])
{
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_dv3[12];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i30;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), c8_sFywiTZeQa1EYv2NwJ5ncFC_dv3,
                1, 0, 0U, 1, 0U, 1, 12);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i30 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i30 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i30++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i30] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_dv3[c8_sFywiTZeQa1EYv2NwJ5ncFC_i30];
  }

  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew;
  const char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y[12];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i31;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew = sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier = c8_sFywiTZeQa1EYv2NwJ5ncFC_varName;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_xNew);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i31 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i31 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i31++) {
    (*(real_T (*)[12])c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
      [c8_sFywiTZeQa1EYv2NwJ5ncFC_i31] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i31];
  }

  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i32;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i33;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i34;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u[9];
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i32 = 0;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i33 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i33 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i33++) {
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i34 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i34 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i34++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_u[c8_sFywiTZeQa1EYv2NwJ5ncFC_i34 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i32] = (*(real_T (*)[9])
        c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)[c8_sFywiTZeQa1EYv2NwJ5ncFC_i34 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i32];
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_i32 += 3;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i35;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u[3];
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i35 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i35 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i35++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u[c8_sFywiTZeQa1EYv2NwJ5ncFC_i35] = (*(real_T (*)
      [3])c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)[c8_sFywiTZeQa1EYv2NwJ5ncFC_i35];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u = *(real_T *)c8_sFywiTZeQa1EYv2NwJ5ncFC_inData;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_e_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d0;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), &c8_sFywiTZeQa1EYv2NwJ5ncFC_d0,
                1, 0, 0U, 0, 0U, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_d0;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout;
  const char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout = sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier = c8_sFywiTZeQa1EYv2NwJ5ncFC_varName;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout),
     &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_nargout);
  *(real_T *)c8_sFywiTZeQa1EYv2NwJ5ncFC_outData = c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i36;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_u[17];
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_u;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y = NULL;
  boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d_u;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y = NULL;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u =
    *(c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_inData;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_createstruct("structure",
    2, 1, 1), false);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i36 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i36 < 17;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i36++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_u[c8_sFywiTZeQa1EYv2NwJ5ncFC_i36] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_u.FcnName[c8_sFywiTZeQa1EYv2NwJ5ncFC_i36];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_u, 10, 0U, 1U, 0U, 2, 1, 17), false);
  sf_mex_addfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y,
                  "FcnName", "FcnName", 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y, sf_mex_create("y", NULL, 10, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_addfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y,
                  "JacobianFcnName", "JacobianFcnName", 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_u = c8_sFywiTZeQa1EYv2NwJ5ncFC_u.HasJacobian;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y, sf_mex_create("y",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y,
                  "HasJacobian", "HasJacobian", 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_u = c8_sFywiTZeQa1EYv2NwJ5ncFC_u.HasAdditiveNoise;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y, sf_mex_create("y",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_y, c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y,
                  "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_g_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  (void)c8_sFywiTZeQa1EYv2NwJ5ncFC_inData;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y", NULL, 0, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

const mxArray
  *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_nameCaptureInfo = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_nameCaptureInfo, sf_mex_create(
    "nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1), false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_nameCaptureInfo;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_EKFCorrectorAdditive_correct
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_z[3], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[9], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12],
   real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[144], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x[12], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_P[144])
{
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i37;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i38;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i39;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i40;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[3];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_zcov[9];
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i37 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i37 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i37++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i37] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i37];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i38 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i38 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i38++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i38] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i38];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i39 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i39 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i39++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i39] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i39];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i40 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i40 < 9;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i40++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_zcov[c8_sFywiTZeQa1EYv2NwJ5ncFC_i40] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[c8_sFywiTZeQa1EYv2NwJ5ncFC_i40];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z, c8_sFywiTZeQa1EYv2NwJ5ncFC_b_zcov,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x, c8_sFywiTZeQa1EYv2NwJ5ncFC_c_P);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_warning
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  static char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_cv0[7] = { 'w', 'a', 'r', 'n', 'i',
    'n', 'g' };

  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  static char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_cv1[7] = { 'm', 'e', 's', 's', 'a',
    'g', 'e' };

  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  static char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_msgID[27] = { 'C', 'o', 'd', 'e', 'r',
    ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_cv0, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_cv1, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y, sf_mex_create("y",
    c8_sFywiTZeQa1EYv2NwJ5ncFC_msgID, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14,
                    c8_sFywiTZeQa1EYv2NwJ5ncFC_y, 14, sf_mex_call_debug
                    (sfGlobalDebugInstanceStruct, "feval", 1U, 2U, 14,
                     c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y, 14,
                     c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y));
}

static const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_h_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_inData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u;
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u = *(int32_T *)c8_sFywiTZeQa1EYv2NwJ5ncFC_inData;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = NULL;
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_y, sf_mex_create("y",
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData,
                c8_sFywiTZeQa1EYv2NwJ5ncFC_y, false);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayOutData;
}

static int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_f_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i41;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), &c8_sFywiTZeQa1EYv2NwJ5ncFC_i41,
                1, 6, 0U, 0, 0U, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_i41;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sfEvent;
  const char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sfEvent = sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier = c8_sFywiTZeQa1EYv2NwJ5ncFC_varName;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sfEvent),
     &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sfEvent);
  *(int32_T *)c8_sFywiTZeQa1EYv2NwJ5ncFC_outData = c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
}

static c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
  c8_sFywiTZeQa1EYv2NwJ5ncFC_g_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  static const char * c8_sFywiTZeQa1EYv2NwJ5ncFC_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId,
                      c8_sFywiTZeQa1EYv2NwJ5ncFC_u, 4,
                      c8_sFywiTZeQa1EYv2NwJ5ncFC_fieldNames, 0U, NULL);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = "FcnName";
  c8_sFywiTZeQa1EYv2NwJ5ncFC_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_u, "FcnName", "FcnName", 0)),
    &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId, c8_sFywiTZeQa1EYv2NwJ5ncFC_y.FcnName);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = "JacobianFcnName";
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_u, "JacobianFcnName",
                     "JacobianFcnName", 0)), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = "HasJacobian";
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y.HasJacobian =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_u, "HasJacobian", "HasJacobian",
                     0)), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = "HasAdditiveNoise";
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y.HasAdditiveNoise =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sFywiTZeQa1EYv2NwJ5ncFC_u, "HasAdditiveNoise",
                     "HasAdditiveNoise", 0)), &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_h_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, char_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_y[17])
{
  char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_cv2[17];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i42;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), c8_sFywiTZeQa1EYv2NwJ5ncFC_cv2,
                1, 10, 0U, 1, 0U, 2, 1, 17);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i42 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i42 < 17;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i42++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i42] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_cv2[c8_sFywiTZeQa1EYv2NwJ5ncFC_i42];
  }

  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_i_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
}

static boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_j_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  boolean_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b0;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), &c8_sFywiTZeQa1EYv2NwJ5ncFC_b0,
                1, 11, 0U, 0, 0U, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_b0;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData, const char_T
  *c8_sFywiTZeQa1EYv2NwJ5ncFC_varName, void *c8_sFywiTZeQa1EYv2NwJ5ncFC_outData)
{
  const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM;
  const char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM = sf_mex_dup
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier = c8_sFywiTZeQa1EYv2NwJ5ncFC_varName;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM),
     &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_pM);
  *(c8_sFywiTZeQa1EYv2NwJ5ncFC_sJc0LrpsE91c2htQpVlRXsE *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_outData = c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_mxArrayInData);
}

static uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_k_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sFywiTZeQa1EYv2NwJ5ncFC_b_is_active_c8_sFywiTZeQa1EYv2NwJ5ncF, const
   char_T *c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier)
{
  uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  emlrtMsgIdentifier c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fIdentifier = (const char *)
    c8_sFywiTZeQa1EYv2NwJ5ncFC_identifier;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.fParent = NULL;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId.bParentIsCell = false;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_is_active_c8_sFywiTZeQa1EYv2NwJ5ncF),
     &c8_sFywiTZeQa1EYv2NwJ5ncFC_thisId);
  sf_mex_destroy
    (&c8_sFywiTZeQa1EYv2NwJ5ncFC_b_is_active_c8_sFywiTZeQa1EYv2NwJ5ncF);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_l_emlrt_marshallIn
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sFywiTZeQa1EYv2NwJ5ncFC_u, const
   emlrtMsgIdentifier *c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId)
{
  uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  uint8_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u0;
  (void)chartInstance;
  sf_mex_import(c8_sFywiTZeQa1EYv2NwJ5ncFC_parentId, sf_mex_dup
                (c8_sFywiTZeQa1EYv2NwJ5ncFC_u), &c8_sFywiTZeQa1EYv2NwJ5ncFC_u0,
                1, 3, 0U, 0, 0U, 0);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_u0;
  sf_mex_destroy(&c8_sFywiTZeQa1EYv2NwJ5ncFC_u);
  return c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
}

static void c8_sFywiTZeQa1EYv2NwJ5ncFC_b_EKFCorrectorAdditive_correct
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_z[3], real_T
   c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[9], real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[12],
   real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[144])
{
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i43;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2 c8_sFywiTZeQa1EYv2NwJ5ncFC_vec[1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2 c8_sFywiTZeQa1EYv2NwJ5ncFC_r2;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i44;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[12];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[3];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_j;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i45;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i46;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i47;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i48;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i49;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i50;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_e_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i51;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i52;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i53;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[36];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[36];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_2;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_3;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i54;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i55;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i56;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i57;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[36];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i58;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i59;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i60;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_maxval;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i61;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i62;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_epsilon;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i63;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y[36];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i64;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i65;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i66;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i67;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i68;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i69;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i70;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i71;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_cell_wrap_2 c8_sFywiTZeQa1EYv2NwJ5ncFC_specvec[1];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i72;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[9];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i73;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_imz[3];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i74;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i75;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_r1;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_r3;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_B;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_f_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_f_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_g_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_g_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_h_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_j;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i76;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_h_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_j_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_k_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_l_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_maxval;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_m_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_n_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_o_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_p_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_j_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_q_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_r_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_s_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_k_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_a21;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_t_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_v_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_w_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_l_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_x_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_m_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_n_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_o_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_z;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_db_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_p_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_q_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_d_z;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_gb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_hb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ib_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_r_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_jb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_kb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_lb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_s_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_b_d;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_mb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_nb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ob_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_pb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_t_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_qb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_rb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_sb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_u_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_c_d;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_rtemp;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_tb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_v_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ub_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_w_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_e_z;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_k;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i77;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_vb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_x_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_wb_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i78;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_y_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_f_z;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i79;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i80;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i81;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_xb_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i82;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_yb_x;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_alpha1;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i83;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_g_z;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_beta1;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i84;
  char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSB;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i85;
  char_T c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSA;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_ac_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i86;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_y;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_db_y[144];
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_bc_x;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i87;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_y;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_m_t;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_y[144];
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i88;
  real_T c8_sFywiTZeQa1EYv2NwJ5ncFC_h_z;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_n_t;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_k_t;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_lda_t;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_ldb_t;
  ptrdiff_t c8_sFywiTZeQa1EYv2NwJ5ncFC_ldc_t;
  int32_T c8_sFywiTZeQa1EYv2NwJ5ncFC_i89;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i43 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i43 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i43++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r2.f1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i43] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i43];
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_vec[0] = c8_sFywiTZeQa1EYv2NwJ5ncFC_r2;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i44 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i44 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i44++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i44] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_vec[0].f1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i44];
  }

  CV_EML_FCN(0, 3);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_measurementTWBFcn_invoke(chartInstance,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec, c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_j = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_j < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_j++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j = 1.0 + (real_T)c8_sFywiTZeQa1EYv2NwJ5ncFC_j;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i47 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i47 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i47++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i47] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_vec[0].f1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i47];
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j), 1, 12) - 1];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_d_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_c_x;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_e_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_d_x;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y = muDoubleScalarAbs
      (c8_sFywiTZeQa1EYv2NwJ5ncFC_e_x);
    c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_2 = 1.4901161193847656E-8 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_3 =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_2;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_varargin_3;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_b_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_c_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_sFywiTZeQa1EYv2NwJ5ncFC_d_y);
    c8_sFywiTZeQa1EYv2NwJ5ncFC_epsilon = c8_sFywiTZeQa1EYv2NwJ5ncFC_maxval;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j), 1, 12) - 1] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j), 1, 12) - 1] +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_epsilon;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i65 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i65 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i65++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_specvec[0].f1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i65] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i65];
    }

    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i71 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i71 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i71++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i71] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_specvec[0].f1[c8_sFywiTZeQa1EYv2NwJ5ncFC_i71];
    }

    CV_EML_FCN(0, 3);
    c8_sFywiTZeQa1EYv2NwJ5ncFC_measurementTWBFcn_invoke(chartInstance,
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec, c8_sFywiTZeQa1EYv2NwJ5ncFC_imz);
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i75 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i75 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i75++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imz[c8_sFywiTZeQa1EYv2NwJ5ncFC_i75] -=
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i75];
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_B = c8_sFywiTZeQa1EYv2NwJ5ncFC_epsilon;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_f_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_B;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_g_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_f_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_j), 1, 12) - 1;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i76 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i76 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i76++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[c8_sFywiTZeQa1EYv2NwJ5ncFC_i76 + 3 *
        c8_sFywiTZeQa1EYv2NwJ5ncFC_c_j] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_imz[c8_sFywiTZeQa1EYv2NwJ5ncFC_i76] /
        c8_sFywiTZeQa1EYv2NwJ5ncFC_g_y;
    }
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_i45 = 0;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i46 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i46 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i46++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i49 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i50 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i50 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i50++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i50 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i45] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[c8_sFywiTZeQa1EYv2NwJ5ncFC_i49 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i46];
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i49 += 3;
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_i45 += 12;
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i48 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i48 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i48++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i52 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i53 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i53 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i53++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[c8_sFywiTZeQa1EYv2NwJ5ncFC_i52 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i48] = 0.0;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i59 = 0;
      for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i60 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i60 <
           12; c8_sFywiTZeQa1EYv2NwJ5ncFC_i60++) {
        c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[c8_sFywiTZeQa1EYv2NwJ5ncFC_i52 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i48] +=
          c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i59 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i48] *
          c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i60 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i52];
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i59 += 12;
      }

      c8_sFywiTZeQa1EYv2NwJ5ncFC_i52 += 12;
    }
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i51 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i51 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i51++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i55 = 0;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i57 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i58 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i58 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i58++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i55 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i51] = 0.0;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i64 = 0;
      for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i68 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i68 <
           12; c8_sFywiTZeQa1EYv2NwJ5ncFC_i68++) {
        c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i55 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i51] +=
          c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[c8_sFywiTZeQa1EYv2NwJ5ncFC_i64 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i51] *
          c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i68 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i57];
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i64 += 3;
      }

      c8_sFywiTZeQa1EYv2NwJ5ncFC_i55 += 3;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i57 += 12;
    }
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_i54 = 0;
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i56 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i56 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i56++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i62 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i63 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i63 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i63++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i63 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i54] =
        c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[c8_sFywiTZeQa1EYv2NwJ5ncFC_i62 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i56];
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i62 += 3;
    }

    c8_sFywiTZeQa1EYv2NwJ5ncFC_i54 += 12;
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i61 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i61 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i61++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i67 = 0;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i69 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i70 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i70 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i70++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_i67 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i61] = 0.0;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i73 = 0;
      for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i74 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i74 <
           12; c8_sFywiTZeQa1EYv2NwJ5ncFC_i74++) {
        c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_i67 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i61] +=
          c8_sFywiTZeQa1EYv2NwJ5ncFC_e_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i73 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i61] *
          c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i74 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i69];
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i73 += 3;
      }

      c8_sFywiTZeQa1EYv2NwJ5ncFC_i67 += 3;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i69 += 12;
    }
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i66 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i66 < 9;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i66++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_i66] +=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_zcov[c8_sFywiTZeQa1EYv2NwJ5ncFC_i66];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i72 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i72 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i72++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i72] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i72];
  }

  CV_EML_FCN(0, 3);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_measurementTWBFcn_invoke(chartInstance,
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec, c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_r1 = 0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2 = 1;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_r3 = 2;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_f_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[0];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_g_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_f_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_h_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_g_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_h_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_h_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_i_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_j_x = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_k_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_j_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_l_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_k_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_i_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_l_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_maxval = c8_sFywiTZeQa1EYv2NwJ5ncFC_h_y +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_m_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_n_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_m_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_o_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_n_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_p_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_o_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_j_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_p_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_q_x = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_r_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_q_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_s_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_r_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_k_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_s_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_a21 = c8_sFywiTZeQa1EYv2NwJ5ncFC_j_y +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_k_y;
  if (c8_sFywiTZeQa1EYv2NwJ5ncFC_a21 > c8_sFywiTZeQa1EYv2NwJ5ncFC_b_maxval) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_maxval = c8_sFywiTZeQa1EYv2NwJ5ncFC_a21;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r1 = 1;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2 = 0;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_t_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[2];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_t_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_v_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_u_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_w_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_v_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_l_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_w_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_x_x = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_y_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_x_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_y_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_m_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d = c8_sFywiTZeQa1EYv2NwJ5ncFC_l_y +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_m_y;
  if (c8_sFywiTZeQa1EYv2NwJ5ncFC_d > c8_sFywiTZeQa1EYv2NwJ5ncFC_b_maxval) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r1 = 2;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2 = 1;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r3 = 0;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_x =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_n_y =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_o_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_n_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_x /
    c8_sFywiTZeQa1EYv2NwJ5ncFC_o_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_c_z;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_db_x =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_p_y =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_db_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_q_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_p_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_d_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_x /
    c8_sFywiTZeQa1EYv2NwJ5ncFC_q_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_d_z;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] -=
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] *
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] -=
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] *
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] -=
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] *
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] -=
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] *
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_gb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_hb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_gb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ib_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_hb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_r_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_ib_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_jb_x = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_kb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_jb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_lb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_kb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_s_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_lb_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_b_d = c8_sFywiTZeQa1EYv2NwJ5ncFC_r_y +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_s_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_mb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_nb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_mb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ob_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_nb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_pb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_ob_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_t_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_pb_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_qb_x = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_rb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_qb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_sb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_rb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_u_y = muDoubleScalarAbs
    (c8_sFywiTZeQa1EYv2NwJ5ncFC_sb_x);
  c8_sFywiTZeQa1EYv2NwJ5ncFC_c_d = c8_sFywiTZeQa1EYv2NwJ5ncFC_t_y +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_u_y;
  if (c8_sFywiTZeQa1EYv2NwJ5ncFC_b_d > c8_sFywiTZeQa1EYv2NwJ5ncFC_c_d) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_rtemp = c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2 + 1;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2 = c8_sFywiTZeQa1EYv2NwJ5ncFC_r3;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r3 = c8_sFywiTZeQa1EYv2NwJ5ncFC_rtemp - 1;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_tb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_v_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ub_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_tb_x;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_w_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_v_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_e_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_ub_x /
    c8_sFywiTZeQa1EYv2NwJ5ncFC_w_y;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] =
    c8_sFywiTZeQa1EYv2NwJ5ncFC_e_z;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] -=
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] *
    c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
  if ((c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] == 0.0) ||
      (c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 + c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] ==
       0.0) || (c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 + c8_sFywiTZeQa1EYv2NwJ5ncFC_r3]
                == 0.0)) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_warning(chartInstance);
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_k = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 1 < 13;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_k++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_vb_x =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[c8_sFywiTZeQa1EYv2NwJ5ncFC_k];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_x_y =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_wb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_vb_x;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_y_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_x_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_f_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_wb_x /
      c8_sFywiTZeQa1EYv2NwJ5ncFC_y_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] = c8_sFywiTZeQa1EYv2NwJ5ncFC_f_z;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[12 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_k] -
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] * c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pxy[24 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_k] -
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] * c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_xb_x =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_yb_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_xb_x;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_ab_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_g_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_yb_x /
      c8_sFywiTZeQa1EYv2NwJ5ncFC_bb_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] = c8_sFywiTZeQa1EYv2NwJ5ncFC_g_z;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] -=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] * c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_ac_x =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[6 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_bc_x = c8_sFywiTZeQa1EYv2NwJ5ncFC_ac_x;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_y = c8_sFywiTZeQa1EYv2NwJ5ncFC_cb_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_h_z = c8_sFywiTZeQa1EYv2NwJ5ncFC_bc_x /
      c8_sFywiTZeQa1EYv2NwJ5ncFC_eb_y;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] = c8_sFywiTZeQa1EYv2NwJ5ncFC_h_z;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] -=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] * c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[3 +
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] -=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r3] *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_r3];
    c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_r1] -=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_k + 12 *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2] *
      c8_sFywiTZeQa1EYv2NwJ5ncFC_Pyy[c8_sFywiTZeQa1EYv2NwJ5ncFC_b_r2];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i77 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i77 < 3;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i77++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i77] =
      c8_sFywiTZeQa1EYv2NwJ5ncFC_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i77] -
      c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i77];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i78 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i78 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i78++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i78] = 0.0;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i80 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i81 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i81 < 3;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i81++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i78] +=
        c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i80 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i78] *
        c8_sFywiTZeQa1EYv2NwJ5ncFC_b_z[c8_sFywiTZeQa1EYv2NwJ5ncFC_i81];
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i80 += 12;
    }
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i79 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i79 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i79++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_x[c8_sFywiTZeQa1EYv2NwJ5ncFC_i79] +=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_imvec[c8_sFywiTZeQa1EYv2NwJ5ncFC_i79];
  }

  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i82 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i82 < 12;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i82++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i83 = 0;
    c8_sFywiTZeQa1EYv2NwJ5ncFC_i84 = 0;
    for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i85 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i85 < 12;
         c8_sFywiTZeQa1EYv2NwJ5ncFC_i85++) {
      c8_sFywiTZeQa1EYv2NwJ5ncFC_db_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i83 +
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i82] = 0.0;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i87 = 0;
      for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i88 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i88 <
           3; c8_sFywiTZeQa1EYv2NwJ5ncFC_i88++) {
        c8_sFywiTZeQa1EYv2NwJ5ncFC_db_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i83 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i82] +=
          c8_sFywiTZeQa1EYv2NwJ5ncFC_gain[c8_sFywiTZeQa1EYv2NwJ5ncFC_i87 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i82] *
          c8_sFywiTZeQa1EYv2NwJ5ncFC_dHdx[c8_sFywiTZeQa1EYv2NwJ5ncFC_i88 +
          c8_sFywiTZeQa1EYv2NwJ5ncFC_i84];
        c8_sFywiTZeQa1EYv2NwJ5ncFC_i87 += 12;
      }

      c8_sFywiTZeQa1EYv2NwJ5ncFC_i83 += 12;
      c8_sFywiTZeQa1EYv2NwJ5ncFC_i84 += 3;
    }
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_alpha1 = 1.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_beta1 = 0.0;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSB = 'N';
  c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSA = 'N';
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i86 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i86 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i86++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i86] = 0.0;
  }

  c8_sFywiTZeQa1EYv2NwJ5ncFC_m_t = (ptrdiff_t)12;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_n_t = (ptrdiff_t)12;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_k_t = (ptrdiff_t)12;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_lda_t = (ptrdiff_t)12;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ldb_t = (ptrdiff_t)12;
  c8_sFywiTZeQa1EYv2NwJ5ncFC_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSA, &c8_sFywiTZeQa1EYv2NwJ5ncFC_TRANSB,
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_m_t, &c8_sFywiTZeQa1EYv2NwJ5ncFC_n_t,
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_k_t, &c8_sFywiTZeQa1EYv2NwJ5ncFC_alpha1,
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_db_y[0], &c8_sFywiTZeQa1EYv2NwJ5ncFC_lda_t,
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[0], &c8_sFywiTZeQa1EYv2NwJ5ncFC_ldb_t,
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_beta1, &c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_y[0],
        &c8_sFywiTZeQa1EYv2NwJ5ncFC_ldc_t);
  for (c8_sFywiTZeQa1EYv2NwJ5ncFC_i89 = 0; c8_sFywiTZeQa1EYv2NwJ5ncFC_i89 < 144;
       c8_sFywiTZeQa1EYv2NwJ5ncFC_i89++) {
    c8_sFywiTZeQa1EYv2NwJ5ncFC_b_P[c8_sFywiTZeQa1EYv2NwJ5ncFC_i89] -=
      c8_sFywiTZeQa1EYv2NwJ5ncFC_fb_y[c8_sFywiTZeQa1EYv2NwJ5ncFC_i89];
  }
}

static void init_dsm_address_info
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_fEmlrtCtx = (void *)sfrtGetEmlrtCtx
    (chartInstance->S);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_x = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew = (real_T (*)[12])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_P = (real_T (*)[144])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew = (real_T (*)[144])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_yMeas = (real_T (*)[3])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_R = (real_T (*)[9])
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

void sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1379167854U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1118344407U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2170337140U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1510149085U);
}

mxArray*
  sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray
  *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yMteaEVEBGKUzvkUSN016C");
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
      sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_jit_fallback_info
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
  *sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray*
  sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "qHUERjAXild0COYNb26RcF");
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
  *sf_get_sim_state_info_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
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
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_d_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_c_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallOut,
            (MexInFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallOut,
            (MexInFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_f_sf_marshallOut,
          (MexInFcnForType)c8_sFywiTZeQa1EYv2NwJ5ncFC_e_sf_marshallIn);
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
    SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          &chartInstance->c8_sFywiTZeQa1EYv2NwJ5ncFC_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sFywiTZeQa1EYv2NwJ5ncFC";
}

static void
  sf_opaque_initialize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
  initialize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  enable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  disable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  sf_gateway_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SimStruct* S)
{
  return get_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void
  sf_opaque_set_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
      ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
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
  initSimStructsc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
    ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
      ((SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary
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
  ssSetChecksum0(S,(1379167854U));
  ssSetChecksum1(S,(1118344407U));
  ssSetChecksum2(S,(2170337140U));
  ssSetChecksum3(S,(1510149085U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(SimStruct *
  S)
{
  SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct *)utMalloc
    (sizeof(SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary;
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
  mdl_start_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(chartInstance);
}

void c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_sFywiTZeQa1EYv2NwJ5ncFC_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
