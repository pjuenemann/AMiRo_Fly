/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c9_sharedTrackingLibrary.h"
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
static const char * c9_debug_family_names[9] = { "StateTransitionFcn", "pS",
  "nargin", "nargout", "x", "P", "Q", "xNew", "PNew" };

/* Function Declarations */
static void initialize_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initialize_params_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void enable_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void disable_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void set_sim_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void sf_gateway_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void mdl_start_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initSimStructsc9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance);
static void c9_stateTransitionFcn_invoke
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, real_T c9_b_x[12],
   real_T c9_y[12]);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_PNew, const char_T *c9_identifier, real_T
  c9_y[144]);
static void c9_b_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[144]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_xNew, const char_T *c9_identifier, real_T
  c9_y[12]);
static void c9_d_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[12]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_e_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_f_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_g_emlrt_marshallIn
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c9_u,
   const emlrtMsgIdentifier *c9_parentId);
static void c9_h_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[18]);
static void c9_i_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static boolean_T c9_j_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_k_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_sharedTrackingLibrary, const
  char_T *c9_identifier);
static uint8_T c9_l_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc9_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_sharedTrackingLibrary = 0U;
}

static void initialize_params_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c9_m0 = NULL;
  static const char * c9_fieldNames[4] = { "FcnName", "JacobianFcnName",
    "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c9_mxField;
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_r0;
  c9_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c9_m0, 4, c9_fieldNames, "sSJPS9Vsi6dADyZ4t3tkTWD");
  c9_mxField = sf_mex_getfield(c9_m0, "FcnName", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c9_mxField), c9_r0.FcnName, 1, 10, 0U, 1,
                      0U, 2, 1, 18);
  c9_mxField = sf_mex_getfield(c9_m0, "JacobianFcnName", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c9_mxField), NULL, 1, 10, 0U, 1, 0U, 2, 0,
                      0);
  c9_mxField = sf_mex_getfield(c9_m0, "HasJacobian", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c9_mxField), &c9_r0.HasJacobian, 1, 0, 0U,
                      0, 0U, 0);
  c9_mxField = sf_mex_getfield(c9_m0, "HasAdditiveNoise", "pS", 0);
  sf_mex_import_named("pS", sf_mex_dup(c9_mxField), &c9_r0.HasAdditiveNoise, 1,
                      11, 0U, 0, 0U, 0);
  sf_mex_destroy(&c9_m0);
  chartInstance->c9_pS = c9_r0;
}

static void enable_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  const mxArray *c9_b_y = NULL;
  const mxArray *c9_c_y = NULL;
  uint8_T c9_hoistedGlobal;
  const mxArray *c9_d_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(3, 1), false);
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", *chartInstance->c9_PNew, 0, 0U, 1U,
    0U, 2, 12, 12), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", *chartInstance->c9_xNew, 0, 0U, 1U,
    0U, 1, 12), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_sharedTrackingLibrary;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[144];
  int32_T c9_i0;
  real_T c9_dv1[12];
  int32_T c9_i1;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("PNew", c9_u, 0)),
                      "PNew", c9_dv0);
  for (c9_i0 = 0; c9_i0 < 144; c9_i0++) {
    (*chartInstance->c9_PNew)[c9_i0] = c9_dv0[c9_i0];
  }

  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("xNew", c9_u, 1)),
                        "xNew", c9_dv1);
  for (c9_i1 = 0; c9_i1 < 12; c9_i1++) {
    (*chartInstance->c9_xNew)[c9_i1] = c9_dv1[c9_i1];
  }

  chartInstance->c9_is_active_c9_sharedTrackingLibrary = c9_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c9_sharedTrackingLibrary", c9_u, 2)),
     "is_active_c9_sharedTrackingLibrary");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_sharedTrackingLibrary(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  real_T c9_b_x[12];
  int32_T c9_i7;
  real_T c9_b_P[144];
  uint32_T c9_debug_family_var_map[9];
  real_T c9_b_Q[144];
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_b_pS;
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 2.0;
  real_T c9_b_xNew[12];
  real_T c9_b_PNew[144];
  static c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_r1 = { { 's', 't', 'a', 't', 'e', 'T',
      'r', 'a', 'n', 's', 'i', 't', 'i', 'o', 'n', 'F', 'c', 'n' },/* FcnName */
    0.0,                               /* HasJacobian */
    true                               /* HasAdditiveNoise */
  };

  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_c_Q[144];
  int32_T c9_i12;
  real_T c9_c_x[12];
  int32_T c9_i13;
  real_T c9_y[144];
  c9_cell_wrap_2 c9_vec[1];
  c9_cell_wrap_2 c9_r2;
  int32_T c9_i14;
  real_T c9_imvec[12];
  real_T c9_z[12];
  int32_T c9_j;
  real_T c9_alpha1;
  real_T c9_b_j;
  real_T c9_beta1;
  int32_T c9_i15;
  char_T c9_TRANSB;
  char_T c9_TRANSA;
  int32_T c9_i16;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  ptrdiff_t c9_m_t;
  real_T c9_b_y[144];
  real_T c9_c_y;
  ptrdiff_t c9_n_t;
  real_T c9_varargin_2;
  ptrdiff_t c9_k_t;
  real_T c9_varargin_3;
  ptrdiff_t c9_lda_t;
  real_T c9_d_y;
  ptrdiff_t c9_ldb_t;
  real_T c9_e_y;
  ptrdiff_t c9_ldc_t;
  real_T c9_f_y;
  real_T c9_Jacobian[144];
  real_T c9_maxval;
  int32_T c9_i17;
  real_T c9_epsilon;
  int32_T c9_i18;
  int32_T c9_i19;
  real_T c9_b_alpha1;
  int32_T c9_i20;
  real_T c9_b_beta1;
  int32_T c9_i21;
  int32_T c9_i22;
  c9_cell_wrap_2 c9_specvec[1];
  char_T c9_b_TRANSB;
  char_T c9_b_TRANSA;
  int32_T c9_i23;
  real_T c9_b[144];
  real_T c9_imz[12];
  int32_T c9_i24;
  ptrdiff_t c9_b_m_t;
  ptrdiff_t c9_b_n_t;
  ptrdiff_t c9_b_k_t;
  real_T c9_B;
  ptrdiff_t c9_b_lda_t;
  real_T c9_g_y;
  ptrdiff_t c9_b_ldb_t;
  real_T c9_h_y;
  ptrdiff_t c9_b_ldc_t;
  int32_T c9_c_j;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  int32_T c9_i33;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 144; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_Q)[c9_i2], 2U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  for (c9_i3 = 0; c9_i3 < 144; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_P)[c9_i3], 1U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  for (c9_i4 = 0; c9_i4 < 12; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_x)[c9_i4], 0U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  for (c9_i5 = 0; c9_i5 < 12; c9_i5++) {
    c9_b_x[c9_i5] = (*chartInstance->c9_x)[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 144; c9_i6++) {
    c9_b_P[c9_i6] = (*chartInstance->c9_P)[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 144; c9_i7++) {
    c9_b_Q[c9_i7] = (*chartInstance->c9_Q)[c9_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_b_pS, 1U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 2U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_x, 4U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_P, 5U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_Q, 6U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_xNew, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_PNew, 8U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  c9_b_pS = c9_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  for (c9_i8 = 0; c9_i8 < 12; c9_i8++) {
    c9_b_xNew[c9_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  for (c9_i9 = 0; c9_i9 < 144; c9_i9++) {
    c9_b_PNew[c9_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 10);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
  for (c9_i10 = 0; c9_i10 < 144; c9_i10++) {
    c9_c_Q[c9_i10] = c9_b_Q[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 12; c9_i11++) {
    c9_c_x[c9_i11] = c9_b_x[c9_i11];
  }

  for (c9_i12 = 0; c9_i12 < 144; c9_i12++) {
    c9_y[c9_i12] = c9_b_P[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 12; c9_i13++) {
    c9_r2.f1[c9_i13] = c9_c_x[c9_i13];
  }

  c9_vec[0] = c9_r2;
  for (c9_i14 = 0; c9_i14 < 12; c9_i14++) {
    c9_imvec[c9_i14] = c9_vec[0].f1[c9_i14];
  }

  CV_EML_FCN(0, 3);
  c9_stateTransitionFcn_invoke(chartInstance, c9_imvec, c9_z);
  for (c9_j = 0; c9_j < 12; c9_j++) {
    c9_b_j = 1.0 + (real_T)c9_j;
    for (c9_i15 = 0; c9_i15 < 12; c9_i15++) {
      c9_imvec[c9_i15] = c9_vec[0].f1[c9_i15];
    }

    c9_d_x = c9_imvec[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 489, 128, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 489U, 128U, c9_b_j), 1, 12) - 1];
    c9_e_x = c9_d_x;
    c9_f_x = c9_e_x;
    c9_c_y = muDoubleScalarAbs(c9_f_x);
    c9_varargin_2 = 1.4901161193847656E-8 * c9_c_y;
    c9_varargin_3 = c9_varargin_2;
    c9_d_y = c9_varargin_3;
    c9_e_y = c9_d_y;
    c9_f_y = c9_e_y;
    c9_maxval = muDoubleScalarMax(1.4901161193847656E-8, c9_f_y);
    c9_epsilon = c9_maxval;
    c9_imvec[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 489, 128, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 489U, 128U, c9_b_j), 1, 12) - 1] =
      c9_imvec[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 489, 128, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 489U, 128U, c9_b_j), 1, 12) - 1] + c9_epsilon;
    for (c9_i19 = 0; c9_i19 < 12; c9_i19++) {
      c9_specvec[0].f1[c9_i19] = c9_imvec[c9_i19];
    }

    for (c9_i22 = 0; c9_i22 < 12; c9_i22++) {
      c9_imvec[c9_i22] = c9_specvec[0].f1[c9_i22];
    }

    CV_EML_FCN(0, 3);
    c9_stateTransitionFcn_invoke(chartInstance, c9_imvec, c9_imz);
    for (c9_i24 = 0; c9_i24 < 12; c9_i24++) {
      c9_imz[c9_i24] -= c9_z[c9_i24];
    }

    c9_B = c9_epsilon;
    c9_g_y = c9_B;
    c9_h_y = c9_g_y;
    c9_c_j = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 489, 128, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 489U, 128U, c9_b_j), 1, 12) - 1;
    for (c9_i25 = 0; c9_i25 < 12; c9_i25++) {
      c9_Jacobian[c9_i25 + 12 * c9_c_j] = c9_imz[c9_i25] / c9_h_y;
    }
  }

  c9_alpha1 = 1.0;
  c9_beta1 = 0.0;
  c9_TRANSB = 'N';
  c9_TRANSA = 'N';
  for (c9_i16 = 0; c9_i16 < 144; c9_i16++) {
    c9_b_y[c9_i16] = 0.0;
  }

  c9_m_t = (ptrdiff_t)12;
  c9_n_t = (ptrdiff_t)12;
  c9_k_t = (ptrdiff_t)12;
  c9_lda_t = (ptrdiff_t)12;
  c9_ldb_t = (ptrdiff_t)12;
  c9_ldc_t = (ptrdiff_t)12;
  dgemm(&c9_TRANSA, &c9_TRANSB, &c9_m_t, &c9_n_t, &c9_k_t, &c9_alpha1,
        &c9_Jacobian[0], &c9_lda_t, &c9_y[0], &c9_ldb_t, &c9_beta1, &c9_b_y[0],
        &c9_ldc_t);
  c9_i17 = 0;
  for (c9_i18 = 0; c9_i18 < 12; c9_i18++) {
    c9_i20 = 0;
    for (c9_i21 = 0; c9_i21 < 12; c9_i21++) {
      c9_b[c9_i21 + c9_i17] = c9_Jacobian[c9_i20 + c9_i18];
      c9_i20 += 12;
    }

    c9_i17 += 12;
  }

  c9_b_alpha1 = 1.0;
  c9_b_beta1 = 0.0;
  c9_b_TRANSB = 'N';
  c9_b_TRANSA = 'N';
  for (c9_i23 = 0; c9_i23 < 144; c9_i23++) {
    c9_y[c9_i23] = 0.0;
  }

  c9_b_m_t = (ptrdiff_t)12;
  c9_b_n_t = (ptrdiff_t)12;
  c9_b_k_t = (ptrdiff_t)12;
  c9_b_lda_t = (ptrdiff_t)12;
  c9_b_ldb_t = (ptrdiff_t)12;
  c9_b_ldc_t = (ptrdiff_t)12;
  dgemm(&c9_b_TRANSA, &c9_b_TRANSB, &c9_b_m_t, &c9_b_n_t, &c9_b_k_t,
        &c9_b_alpha1, &c9_b_y[0], &c9_b_lda_t, &c9_b[0], &c9_b_ldb_t,
        &c9_b_beta1, &c9_y[0], &c9_b_ldc_t);
  for (c9_i26 = 0; c9_i26 < 144; c9_i26++) {
    c9_y[c9_i26] += c9_c_Q[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 12; c9_i27++) {
    c9_imvec[c9_i27] = c9_c_x[c9_i27];
  }

  CV_EML_FCN(0, 3);
  c9_stateTransitionFcn_invoke(chartInstance, c9_imvec, c9_c_x);
  for (c9_i28 = 0; c9_i28 < 12; c9_i28++) {
    c9_b_xNew[c9_i28] = c9_c_x[c9_i28];
  }

  for (c9_i29 = 0; c9_i29 < 144; c9_i29++) {
    c9_b_PNew[c9_i29] = c9_y[c9_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i30 = 0; c9_i30 < 12; c9_i30++) {
    (*chartInstance->c9_xNew)[c9_i30] = c9_b_xNew[c9_i30];
  }

  for (c9_i31 = 0; c9_i31 < 144; c9_i31++) {
    (*chartInstance->c9_PNew)[c9_i31] = c9_b_PNew[c9_i31];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c9_i32 = 0; c9_i32 < 12; c9_i32++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_xNew)[c9_i32], 3U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }

  for (c9_i33 = 0; c9_i33 < 144; c9_i33++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_PNew)[c9_i33], 4U, 1U, 0U,
                          chartInstance->c9_sfEvent, false);
  }
}

static void mdl_start_c9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_sharedTrackingLibrary
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_stateTransitionFcn_invoke
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, real_T c9_b_x[12],
   real_T c9_y[12])
{
  _ssFcnCallExecArgInfo c9_args[2];
  c9_args[0U].dataPtr = (void *)c9_b_x;
  c9_args[1U].dataPtr = (void *)c9_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "stateTransitionFcn", &c9_args[0U]);
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)(c9_machineNumber);
  (void)(c9_chartNumber);
  (void)(c9_instanceNumber);
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  int32_T c9_i34;
  int32_T c9_i35;
  const mxArray *c9_y = NULL;
  int32_T c9_i36;
  real_T c9_u[144];
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_i34 = 0;
  for (c9_i35 = 0; c9_i35 < 12; c9_i35++) {
    for (c9_i36 = 0; c9_i36 < 12; c9_i36++) {
      c9_u[c9_i36 + c9_i34] = (*(real_T (*)[144])c9_inData)[c9_i36 + c9_i34];
    }

    c9_i34 += 12;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_PNew, const char_T *c9_identifier, real_T
  c9_y[144])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_PNew), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_PNew);
}

static void c9_b_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[144])
{
  real_T c9_dv2[144];
  int32_T c9_i37;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 2, 12,
                12);
  for (c9_i37 = 0; c9_i37 < 144; c9_i37++) {
    c9_y[c9_i37] = c9_dv2[c9_i37];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_PNew;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[144];
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_b_PNew = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_PNew), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_PNew);
  c9_i38 = 0;
  for (c9_i39 = 0; c9_i39 < 12; c9_i39++) {
    for (c9_i40 = 0; c9_i40 < 12; c9_i40++) {
      (*(real_T (*)[144])c9_outData)[c9_i40 + c9_i38] = c9_y[c9_i40 + c9_i38];
    }

    c9_i38 += 12;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  int32_T c9_i41;
  const mxArray *c9_y = NULL;
  real_T c9_u[12];
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i41 = 0; c9_i41 < 12; c9_i41++) {
    c9_u[c9_i41] = (*(real_T (*)[12])c9_inData)[c9_i41];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_xNew, const char_T *c9_identifier, real_T
  c9_y[12])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_xNew), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_xNew);
}

static void c9_d_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[12])
{
  real_T c9_dv3[12];
  int32_T c9_i42;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv3, 1, 0, 0U, 1, 0U, 1, 12);
  for (c9_i42 = 0; c9_i42 < 12; c9_i42++) {
    c9_y[c9_i42] = c9_dv3[c9_i42];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_xNew;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[12];
  int32_T c9_i43;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_b_xNew = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_xNew), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_xNew);
  for (c9_i43 = 0; c9_i43 < 12; c9_i43++) {
    (*(real_T (*)[12])c9_outData)[c9_i43] = c9_y[c9_i43];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_e_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_u;
  const mxArray *c9_y = NULL;
  int32_T c9_i44;
  const mxArray *c9_b_y = NULL;
  char_T c9_b_u[18];
  const mxArray *c9_c_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  boolean_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(c9_sSJPS9Vsi6dADyZ4t3tkTWD *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c9_i44 = 0; c9_i44 < 18; c9_i44++) {
    c9_b_u[c9_i44] = c9_u.FcnName[c9_i44];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 18),
                false);
  sf_mex_addfield(c9_y, c9_b_y, "FcnName", "FcnName", 0);
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", NULL, 10, 0U, 1U, 0U, 2, 0, 0),
                false);
  sf_mex_addfield(c9_y, c9_c_y, "JacobianFcnName", "JacobianFcnName", 0);
  c9_c_u = c9_u.HasJacobian;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_d_y, "HasJacobian", "HasJacobian", 0);
  c9_d_u = c9_u.HasAdditiveNoise;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c9_y, c9_e_y, "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  const mxArray *c9_y = NULL;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  (void)c9_inData;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_sharedTrackingLibrary_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_f_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i45;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i45, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i45;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_g_emlrt_marshallIn
  (SFc9_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c9_u,
   const emlrtMsgIdentifier *c9_parentId)
{
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_y;
  emlrtMsgIdentifier c9_thisId;
  static const char * c9_fieldNames[4] = { "FcnName", "JacobianFcnName",
    "HasJacobian", "HasAdditiveNoise" };

  c9_thisId.fParent = c9_parentId;
  c9_thisId.bParentIsCell = false;
  sf_mex_check_struct(c9_parentId, c9_u, 4, c9_fieldNames, 0U, NULL);
  c9_thisId.fIdentifier = "FcnName";
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "FcnName", "FcnName", 0)), &c9_thisId, c9_y.FcnName);
  c9_thisId.fIdentifier = "JacobianFcnName";
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c9_u,
    "JacobianFcnName", "JacobianFcnName", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "HasJacobian";
  c9_y.HasJacobian = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "HasJacobian", "HasJacobian", 0)), &c9_thisId);
  c9_thisId.fIdentifier = "HasAdditiveNoise";
  c9_y.HasAdditiveNoise = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c9_u, "HasAdditiveNoise", "HasAdditiveNoise", 0)),
    &c9_thisId);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_h_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[18])
{
  char_T c9_cv0[18];
  int32_T c9_i46;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv0, 1, 10, 0U, 1, 0U, 2, 1,
                18);
  for (c9_i46 = 0; c9_i46 < 18; c9_i46++) {
    c9_y[c9_i46] = c9_cv0[c9_i46];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_i_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c9_u);
}

static boolean_T c9_j_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_pS;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  c9_sSJPS9Vsi6dADyZ4t3tkTWD c9_y;
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c9_b_pS = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_pS), &c9_thisId);
  sf_mex_destroy(&c9_b_pS);
  *(c9_sSJPS9Vsi6dADyZ4t3tkTWD *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_k_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_sharedTrackingLibrary, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_y = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_sharedTrackingLibrary), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_sharedTrackingLibrary);
  return c9_y;
}

static uint8_T c9_l_emlrt_marshallIn(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  chartInstance->c9_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c9_x = (real_T (*)[12])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_xNew = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_P = (real_T (*)[144])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_Q = (real_T (*)[144])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_PNew = (real_T (*)[144])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c9_sharedTrackingLibrary_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(462429665U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4152807403U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(844129607U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2820893393U);
}

mxArray* sf_c9_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray *sf_c9_sharedTrackingLibrary_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aTczqHQqvfqMmPD2yKjjDC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(12);
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
      sf_c9_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_sharedTrackingLibrary_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c9_sharedTrackingLibrary_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("client_server");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("stateTransitionFcn");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c9_sharedTrackingLibrary_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "R5MkcfE0n1rk2h2JIOORVH");
    mwSize exp_dims[2] = { 1, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);

    {
      mxArray* mxFcnName = mxCreateString("stateTransitionFcn");
      mxSetCell(mxExportedFunctionsUsedByThisChart, 0, mxFcnName);
    }

    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c9_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[13],T\"xNew\",},{M[8],M[0],T\"is_active_c9_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc9_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _sharedTrackingLibraryMachineNumber_,
           9,
           1,
           1,
           0,
           6,
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
          _SFD_SET_DATA_PROPS(2,1,1,0,"Q");
          _SFD_SET_DATA_PROPS(3,2,0,1,"xNew");
          _SFD_SET_DATA_PROPS(4,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(5,10,0,0,"pS");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1011);
        _SFD_CV_INIT_EML_FCN(0,1,"",405,-1,432);
        _SFD_CV_INIT_EML_FCN(0,2,"",434,-1,469);
        _SFD_CV_INIT_EML_FCN(0,3,"",585,-1,612);
        _SFD_CV_INIT_EML_FCN(0,4,"",761,-1,794);
        _SFD_CV_INIT_EML_FCN(0,5,"",796,-1,837);
        _SFD_CV_INIT_EML_FCN(0,6,"",956,-1,989);
        _SFD_CV_INIT_EML_IF(0,1,0,93,110,-1,190);
        _SFD_CV_INIT_EML_IF(0,1,1,256,278,627,1007);
        _SFD_CV_INIT_EML_IF(0,1,2,283,300,476,626);
        _SFD_CV_INIT_EML_IF(0,1,3,636,653,844,1003);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)c9_e_sf_marshallIn);
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
    SFc9_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc9_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c9_x);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c9_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c9_P);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c9_Q);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c9_PNew);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)&chartInstance->c9_pS);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sH67H5rpwduK8hr62k27AJ";
}

static void sf_opaque_initialize_c9_sharedTrackingLibrary(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_sharedTrackingLibrary
    ((SFc9_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
  initialize_c9_sharedTrackingLibrary((SFc9_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_sharedTrackingLibrary(void *chartInstanceVar)
{
  enable_c9_sharedTrackingLibrary((SFc9_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_sharedTrackingLibrary(void *chartInstanceVar)
{
  disable_c9_sharedTrackingLibrary((SFc9_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_sharedTrackingLibrary(void *chartInstanceVar)
{
  sf_gateway_c9_sharedTrackingLibrary((SFc9_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_sharedTrackingLibrary(SimStruct*
  S)
{
  return get_sim_state_c9_sharedTrackingLibrary
    ((SFc9_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_sharedTrackingLibrary(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c9_sharedTrackingLibrary
    ((SFc9_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c9_sharedTrackingLibrary(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_sharedTrackingLibraryInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c9_sharedTrackingLibrary((SFc9_sharedTrackingLibraryInstanceStruct*)
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
  initSimStructsc9_sharedTrackingLibrary
    ((SFc9_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_sharedTrackingLibrary(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_sharedTrackingLibrary
      ((SFc9_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c9_sharedTrackingLibrary(SimStruct *S)
{
  /* Actual parameters from chart:
     pS
   */
  const char_T *rtParamNames[] = { "pS" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sharedTrackingLibrary_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 9);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3493165437U));
  ssSetChecksum1(S,(1087071997U));
  ssSetChecksum2(S,(1612968661U));
  ssSetChecksum3(S,(783538492U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c9_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_sharedTrackingLibrary(SimStruct *S)
{
  SFc9_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc9_sharedTrackingLibraryInstanceStruct *)utMalloc(sizeof
    (SFc9_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc9_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_sharedTrackingLibrary;
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
  mdl_start_c9_sharedTrackingLibrary(chartInstance);
}

void c9_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
