/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary.h"
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
static const char * c8_sJUjlCK20kX4xC834REUQpG_debug_family_names[10] = {
  "MeasurementFcn", "pM", "nargin", "nargout", "x", "P", "yMeas", "R", "xNew",
  "PNew" };

/* Function Declarations */
static void initialize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initialize_params_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void enable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void disable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sJUjlCK20kX4xC834REUQpG_update_debugger_state_c8_sJUjlCK20kX4
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray
  *get_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void set_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_st);
static void finalize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void sf_gateway_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void mdl_start_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void initSimStructsc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sJUjlCK20kX4xC834REUQpG_measurementDroneFcn_invoke
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12]);
static void init_script_number_translation(uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_machineNumber, uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_chartNumber, uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_instanceNumber);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static void c8_sJUjlCK20kX4xC834REUQpG_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_PNew, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_b_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static void c8_sJUjlCK20kX4xC834REUQpG_c_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_xNew, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12]);
static void c8_sJUjlCK20kX4xC834REUQpG_d_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12]);
static void c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static real_T c8_sJUjlCK20kX4xC834REUQpG_e_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static void c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static void c8_sJUjlCK20kX4xC834REUQpG_EKFCorrectorAdditive_correct
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_z[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zcov[144], real_T c8_sJUjlCK20kX4xC834REUQpG_b_x
   [12], real_T c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_c_x[12], real_T c8_sJUjlCK20kX4xC834REUQpG_c_P[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_numericJacobian
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2
   c8_sJUjlCK20kX4xC834REUQpG_vec[1], real_T
   c8_sJUjlCK20kX4xC834REUQpG_inputToDerive, real_T
   c8_sJUjlCK20kX4xC834REUQpG_jacobian[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_EKFCorrector_correctStateAndCovarianc
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zEstimated[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zMeasured[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_Pxy[144], real_T c8_sJUjlCK20kX4xC834REUQpG_Pyy
   [144], real_T c8_sJUjlCK20kX4xC834REUQpG_dHdx[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_c_x[12], real_T c8_sJUjlCK20kX4xC834REUQpG_c_P[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_mrdivide
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_B[144], real_T c8_sJUjlCK20kX4xC834REUQpG_y[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_xgetrf
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_A[144], int32_T c8_sJUjlCK20kX4xC834REUQpG_ipiv
   [12], int32_T *c8_sJUjlCK20kX4xC834REUQpG_info);
static void c8_sJUjlCK20kX4xC834REUQpG_error
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void c8_sJUjlCK20kX4xC834REUQpG_b_error
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, int32_T c8_sJUjlCK20kX4xC834REUQpG_varargin_2);
static void c8_sJUjlCK20kX4xC834REUQpG_warning
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData);
static int32_T c8_sJUjlCK20kX4xC834REUQpG_f_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static void c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData);
static c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
  c8_sJUjlCK20kX4xC834REUQpG_g_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static void c8_sJUjlCK20kX4xC834REUQpG_h_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, char_T
   c8_sJUjlCK20kX4xC834REUQpG_y[19]);
static void c8_sJUjlCK20kX4xC834REUQpG_i_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static boolean_T c8_sJUjlCK20kX4xC834REUQpG_j_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static void c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData);
static uint8_T c8_sJUjlCK20kX4xC834REUQpG_k_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sJUjlCK20kX4xC834REUQpG_b_is_active_c8_sJUjlCK20kX4xC834REUQp, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier);
static uint8_T c8_sJUjlCK20kX4xC834REUQpG_l_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId);
static void c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrectorAdditive_correct
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_z[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zcov[144], real_T c8_sJUjlCK20kX4xC834REUQpG_b_x
   [12], real_T c8_sJUjlCK20kX4xC834REUQpG_b_P[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrector_correctStateAndCovaria
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zEstimated[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zMeasured[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_Pxy[144], real_T c8_sJUjlCK20kX4xC834REUQpG_Pyy
   [144], real_T c8_sJUjlCK20kX4xC834REUQpG_dHdx[144]);
static void c8_sJUjlCK20kX4xC834REUQpG_b_xgetrf
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], int32_T
   c8_sJUjlCK20kX4xC834REUQpG_ipiv[12], int32_T *c8_sJUjlCK20kX4xC834REUQpG_info);
static void init_dsm_address_info
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);
static void init_simulink_io_address
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance);

/* Function Definitions */
static void initialize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_is_active_c8_sJUjlCK20kX4xC834REUQpG_
    = 0U;
}

static void initialize_params_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_m0 = NULL;
  static const char * c8_sJUjlCK20kX4xC834REUQpG_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxField;
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_r0;
  c8_sJUjlCK20kX4xC834REUQpG_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c8_sJUjlCK20kX4xC834REUQpG_m0, 4,
    c8_sJUjlCK20kX4xC834REUQpG_fieldNames, "sex2lFeEcOPeDeDewnWtFVE");
  c8_sJUjlCK20kX4xC834REUQpG_mxField = sf_mex_getfield
    (c8_sJUjlCK20kX4xC834REUQpG_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_mxField),
                      c8_sJUjlCK20kX4xC834REUQpG_r0.FcnName, 1, 10, 0U, 1, 0U, 2,
                      1, 19);
  c8_sJUjlCK20kX4xC834REUQpG_mxField = sf_mex_getfield
    (c8_sJUjlCK20kX4xC834REUQpG_m0, "JacobianFcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_mxField), NULL,
                      1, 10, 0U, 1, 0U, 2, 0, 0);
  c8_sJUjlCK20kX4xC834REUQpG_mxField = sf_mex_getfield
    (c8_sJUjlCK20kX4xC834REUQpG_m0, "HasJacobian", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_mxField),
                      &c8_sJUjlCK20kX4xC834REUQpG_r0.HasJacobian, 1, 11, 0U, 0,
                      0U, 0);
  c8_sJUjlCK20kX4xC834REUQpG_mxField = sf_mex_getfield
    (c8_sJUjlCK20kX4xC834REUQpG_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_mxField),
                      &c8_sJUjlCK20kX4xC834REUQpG_r0.HasAdditiveNoise, 1, 11, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_m0);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_pM = c8_sJUjlCK20kX4xC834REUQpG_r0;
}

static void enable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_sJUjlCK20kX4xC834REUQpG_update_debugger_state_c8_sJUjlCK20kX4
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static const mxArray
  *get_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_st;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  uint8_T c8_sJUjlCK20kX4xC834REUQpG_hoistedGlobal;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_d_y = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_st = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_st = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_createcellmatrix(3, 1),
                false);
  c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_b_y, sf_mex_create("y",
    *chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew, 0, 0U, 1U, 0U, 2, 12, 12),
                false);
  sf_mex_setcell(c8_sJUjlCK20kX4xC834REUQpG_y, 0, c8_sJUjlCK20kX4xC834REUQpG_b_y);
  c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_c_y, sf_mex_create("y",
    *chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew, 0, 0U, 1U, 0U, 1, 12),
                false);
  sf_mex_setcell(c8_sJUjlCK20kX4xC834REUQpG_y, 1, c8_sJUjlCK20kX4xC834REUQpG_c_y);
  c8_sJUjlCK20kX4xC834REUQpG_hoistedGlobal =
    chartInstance->c8_sJUjlCK20kX4xC834REUQpG_is_active_c8_sJUjlCK20kX4xC834REUQpG_;
  c8_sJUjlCK20kX4xC834REUQpG_d_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_d_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_hoistedGlobal, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_sJUjlCK20kX4xC834REUQpG_y, 2, c8_sJUjlCK20kX4xC834REUQpG_d_y);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_st, c8_sJUjlCK20kX4xC834REUQpG_y,
                false);
  return c8_sJUjlCK20kX4xC834REUQpG_st;
}

static void set_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_st)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u;
  real_T c8_sJUjlCK20kX4xC834REUQpG_dv0[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i0;
  real_T c8_sJUjlCK20kX4xC834REUQpG_dv1[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i1;
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_doneDoubleBufferReInit = true;
  c8_sJUjlCK20kX4xC834REUQpG_u = sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_st);
  c8_sJUjlCK20kX4xC834REUQpG_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PNew", c8_sJUjlCK20kX4xC834REUQpG_u, 0)), "PNew",
    c8_sJUjlCK20kX4xC834REUQpG_dv0);
  for (c8_sJUjlCK20kX4xC834REUQpG_i0 = 0; c8_sJUjlCK20kX4xC834REUQpG_i0 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i0++) {
    (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew)
      [c8_sJUjlCK20kX4xC834REUQpG_i0] =
      c8_sJUjlCK20kX4xC834REUQpG_dv0[c8_sJUjlCK20kX4xC834REUQpG_i0];
  }

  c8_sJUjlCK20kX4xC834REUQpG_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("xNew", c8_sJUjlCK20kX4xC834REUQpG_u, 1)), "xNew",
    c8_sJUjlCK20kX4xC834REUQpG_dv1);
  for (c8_sJUjlCK20kX4xC834REUQpG_i1 = 0; c8_sJUjlCK20kX4xC834REUQpG_i1 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i1++) {
    (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew)
      [c8_sJUjlCK20kX4xC834REUQpG_i1] =
      c8_sJUjlCK20kX4xC834REUQpG_dv1[c8_sJUjlCK20kX4xC834REUQpG_i1];
  }

  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_is_active_c8_sJUjlCK20kX4xC834REUQpG_
    = c8_sJUjlCK20kX4xC834REUQpG_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_active_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary",
                    c8_sJUjlCK20kX4xC834REUQpG_u, 2)),
    "is_active_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary");
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  c8_sJUjlCK20kX4xC834REUQpG_update_debugger_state_c8_sJUjlCK20kX4(chartInstance);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_st);
}

static void finalize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i2;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i3;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i4;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i5;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i6;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i7;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i8;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_P[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i9;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_yMeas[12];
  uint32_T c8_sJUjlCK20kX4xC834REUQpG_debug_family_var_map[10];
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_R[144];
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_b_pM;
  real_T c8_sJUjlCK20kX4xC834REUQpG_nargin = 4.0;
  real_T c8_sJUjlCK20kX4xC834REUQpG_nargout = 2.0;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_xNew[12];
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_PNew[144];
  static c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_r1 = { { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'm',
      'e', 'n', 't', 'D', 'r', 'o', 'n', 'e', 'F', 'c', 'n' },/* FcnName */
    false,                             /* HasJacobian */
    true                               /* HasAdditiveNoise */
  };

  int32_T c8_sJUjlCK20kX4xC834REUQpG_i10;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i11;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i12;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i13;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_xNew[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i14;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_PNew[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i15;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_yMeas[12];
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_R[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i16;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i17;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i18;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i19;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i20;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U,
               chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent);
  for (c8_sJUjlCK20kX4xC834REUQpG_i2 = 0; c8_sJUjlCK20kX4xC834REUQpG_i2 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_R)
                          [c8_sJUjlCK20kX4xC834REUQpG_i2], 3U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i3 = 0; c8_sJUjlCK20kX4xC834REUQpG_i3 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_yMeas)
                          [c8_sJUjlCK20kX4xC834REUQpG_i3], 2U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i4 = 0; c8_sJUjlCK20kX4xC834REUQpG_i4 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_P)
                          [c8_sJUjlCK20kX4xC834REUQpG_i4], 1U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i5 = 0; c8_sJUjlCK20kX4xC834REUQpG_i5 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_x)
                          [c8_sJUjlCK20kX4xC834REUQpG_i5], 0U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }

  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U,
               chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent);
  for (c8_sJUjlCK20kX4xC834REUQpG_i6 = 0; c8_sJUjlCK20kX4xC834REUQpG_i6 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i6++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i6] =
      (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_x)
      [c8_sJUjlCK20kX4xC834REUQpG_i6];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i7 = 0; c8_sJUjlCK20kX4xC834REUQpG_i7 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i7++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_P[c8_sJUjlCK20kX4xC834REUQpG_i7] =
      (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_P)
      [c8_sJUjlCK20kX4xC834REUQpG_i7];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i8 = 0; c8_sJUjlCK20kX4xC834REUQpG_i8 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i8++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_yMeas[c8_sJUjlCK20kX4xC834REUQpG_i8] =
      (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_yMeas)
      [c8_sJUjlCK20kX4xC834REUQpG_i8];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i9 = 0; c8_sJUjlCK20kX4xC834REUQpG_i9 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i9++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_R[c8_sJUjlCK20kX4xC834REUQpG_i9] =
      (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_R)
      [c8_sJUjlCK20kX4xC834REUQpG_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U,
    c8_sJUjlCK20kX4xC834REUQpG_debug_family_names,
    c8_sJUjlCK20kX4xC834REUQpG_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U,
    c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_sJUjlCK20kX4xC834REUQpG_b_pM, 1U,
    c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sJUjlCK20kX4xC834REUQpG_nargin, 2U,
    c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallOut,
    c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_sJUjlCK20kX4xC834REUQpG_nargout, 3U,
    c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallOut,
    c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sJUjlCK20kX4xC834REUQpG_b_x, 4U,
    c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sJUjlCK20kX4xC834REUQpG_b_P, 5U,
    c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sJUjlCK20kX4xC834REUQpG_b_yMeas, 6U,
    c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_sJUjlCK20kX4xC834REUQpG_b_R, 7U,
    c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sJUjlCK20kX4xC834REUQpG_b_xNew, 8U,
    c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut,
    c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_sJUjlCK20kX4xC834REUQpG_b_PNew, 9U,
    c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut,
    c8_sJUjlCK20kX4xC834REUQpG_sf_marshallIn);
  c8_sJUjlCK20kX4xC834REUQpG_b_pM = c8_sJUjlCK20kX4xC834REUQpG_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 3);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 7);
  for (c8_sJUjlCK20kX4xC834REUQpG_i10 = 0; c8_sJUjlCK20kX4xC834REUQpG_i10 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i10++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_xNew[c8_sJUjlCK20kX4xC834REUQpG_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 8);
  for (c8_sJUjlCK20kX4xC834REUQpG_i11 = 0; c8_sJUjlCK20kX4xC834REUQpG_i11 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i11++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_PNew[c8_sJUjlCK20kX4xC834REUQpG_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 9);
  CV_EML_IF(0, 1, 1, true);
  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 10);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, 14);
  for (c8_sJUjlCK20kX4xC834REUQpG_i12 = 0; c8_sJUjlCK20kX4xC834REUQpG_i12 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i12++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_xNew[c8_sJUjlCK20kX4xC834REUQpG_i12] =
      c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i12];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i13 = 0; c8_sJUjlCK20kX4xC834REUQpG_i13 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i13++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_PNew[c8_sJUjlCK20kX4xC834REUQpG_i13] =
      c8_sJUjlCK20kX4xC834REUQpG_b_P[c8_sJUjlCK20kX4xC834REUQpG_i13];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i14 = 0; c8_sJUjlCK20kX4xC834REUQpG_i14 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i14++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_yMeas[c8_sJUjlCK20kX4xC834REUQpG_i14] =
      c8_sJUjlCK20kX4xC834REUQpG_b_yMeas[c8_sJUjlCK20kX4xC834REUQpG_i14];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i15 = 0; c8_sJUjlCK20kX4xC834REUQpG_i15 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i15++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_R[c8_sJUjlCK20kX4xC834REUQpG_i15] =
      c8_sJUjlCK20kX4xC834REUQpG_b_R[c8_sJUjlCK20kX4xC834REUQpG_i15];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_c_yMeas, c8_sJUjlCK20kX4xC834REUQpG_c_R,
    c8_sJUjlCK20kX4xC834REUQpG_c_xNew, c8_sJUjlCK20kX4xC834REUQpG_c_PNew);
  for (c8_sJUjlCK20kX4xC834REUQpG_i16 = 0; c8_sJUjlCK20kX4xC834REUQpG_i16 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i16++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_xNew[c8_sJUjlCK20kX4xC834REUQpG_i16] =
      c8_sJUjlCK20kX4xC834REUQpG_c_xNew[c8_sJUjlCK20kX4xC834REUQpG_i16];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i17 = 0; c8_sJUjlCK20kX4xC834REUQpG_i17 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i17++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_PNew[c8_sJUjlCK20kX4xC834REUQpG_i17] =
      c8_sJUjlCK20kX4xC834REUQpG_c_PNew[c8_sJUjlCK20kX4xC834REUQpG_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_sJUjlCK20kX4xC834REUQpG_i18 = 0; c8_sJUjlCK20kX4xC834REUQpG_i18 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i18++) {
    (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew)
      [c8_sJUjlCK20kX4xC834REUQpG_i18] =
      c8_sJUjlCK20kX4xC834REUQpG_b_xNew[c8_sJUjlCK20kX4xC834REUQpG_i18];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i19 = 0; c8_sJUjlCK20kX4xC834REUQpG_i19 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i19++) {
    (*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew)
      [c8_sJUjlCK20kX4xC834REUQpG_i19] =
      c8_sJUjlCK20kX4xC834REUQpG_b_PNew[c8_sJUjlCK20kX4xC834REUQpG_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U,
               chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_sJUjlCK20kX4xC834REUQpG_i20 = 0; c8_sJUjlCK20kX4xC834REUQpG_i20 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i20++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew)
                          [c8_sJUjlCK20kX4xC834REUQpG_i20], 4U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i21 = 0; c8_sJUjlCK20kX4xC834REUQpG_i21 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew)
                          [c8_sJUjlCK20kX4xC834REUQpG_i21], 5U, 1U, 0U,
                          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_sfEvent,
                          false);
  }
}

static void mdl_start_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void c8_sJUjlCK20kX4xC834REUQpG_measurementDroneFcn_invoke
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12])
{
  _ssFcnCallExecArgInfo c8_sJUjlCK20kX4xC834REUQpG_args[2];
  c8_sJUjlCK20kX4xC834REUQpG_args[0U].dataPtr = (void *)
    c8_sJUjlCK20kX4xC834REUQpG_b_x;
  c8_sJUjlCK20kX4xC834REUQpG_args[1U].dataPtr = (void *)
    c8_sJUjlCK20kX4xC834REUQpG_y;
  slcsInvokeSimulinkFunction(chartInstance->S, "measurementDroneFcn",
    &c8_sJUjlCK20kX4xC834REUQpG_args[0U]);
}

static void init_script_number_translation(uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_machineNumber, uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_chartNumber, uint32_T
  c8_sJUjlCK20kX4xC834REUQpG_instanceNumber)
{
  (void)(c8_sJUjlCK20kX4xC834REUQpG_machineNumber);
  (void)(c8_sJUjlCK20kX4xC834REUQpG_chartNumber);
  (void)(c8_sJUjlCK20kX4xC834REUQpG_instanceNumber);
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i22;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i23;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i24;
  real_T c8_sJUjlCK20kX4xC834REUQpG_u[144];
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_i22 = 0;
  for (c8_sJUjlCK20kX4xC834REUQpG_i23 = 0; c8_sJUjlCK20kX4xC834REUQpG_i23 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i23++) {
    for (c8_sJUjlCK20kX4xC834REUQpG_i24 = 0; c8_sJUjlCK20kX4xC834REUQpG_i24 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i24++) {
      c8_sJUjlCK20kX4xC834REUQpG_u[c8_sJUjlCK20kX4xC834REUQpG_i24 +
        c8_sJUjlCK20kX4xC834REUQpG_i22] = (*(real_T (*)[144])
        c8_sJUjlCK20kX4xC834REUQpG_inData)[c8_sJUjlCK20kX4xC834REUQpG_i24 +
        c8_sJUjlCK20kX4xC834REUQpG_i22];
    }

    c8_sJUjlCK20kX4xC834REUQpG_i22 += 12;
  }

  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_u, 0, 0U, 1U, 0U, 2, 12, 12), false);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

static void c8_sJUjlCK20kX4xC834REUQpG_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_PNew, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[144])
{
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_b_PNew), &c8_sJUjlCK20kX4xC834REUQpG_thisId,
    c8_sJUjlCK20kX4xC834REUQpG_y);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_PNew);
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[144])
{
  real_T c8_sJUjlCK20kX4xC834REUQpG_dv2[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i25;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), c8_sJUjlCK20kX4xC834REUQpG_dv2,
                1, 0, 0U, 1, 0U, 2, 12, 12);
  for (c8_sJUjlCK20kX4xC834REUQpG_i25 = 0; c8_sJUjlCK20kX4xC834REUQpG_i25 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i25++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i25] =
      c8_sJUjlCK20kX4xC834REUQpG_dv2[c8_sJUjlCK20kX4xC834REUQpG_i25];
  }

  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
}

static void c8_sJUjlCK20kX4xC834REUQpG_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_PNew;
  const char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i26;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i27;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i28;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_b_PNew = sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
  c8_sJUjlCK20kX4xC834REUQpG_identifier = c8_sJUjlCK20kX4xC834REUQpG_varName;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_b_PNew), &c8_sJUjlCK20kX4xC834REUQpG_thisId,
    c8_sJUjlCK20kX4xC834REUQpG_y);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_PNew);
  c8_sJUjlCK20kX4xC834REUQpG_i26 = 0;
  for (c8_sJUjlCK20kX4xC834REUQpG_i27 = 0; c8_sJUjlCK20kX4xC834REUQpG_i27 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i27++) {
    for (c8_sJUjlCK20kX4xC834REUQpG_i28 = 0; c8_sJUjlCK20kX4xC834REUQpG_i28 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i28++) {
      (*(real_T (*)[144])c8_sJUjlCK20kX4xC834REUQpG_outData)
        [c8_sJUjlCK20kX4xC834REUQpG_i28 + c8_sJUjlCK20kX4xC834REUQpG_i26] =
        c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i28 +
        c8_sJUjlCK20kX4xC834REUQpG_i26];
    }

    c8_sJUjlCK20kX4xC834REUQpG_i26 += 12;
  }

  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i29;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  real_T c8_sJUjlCK20kX4xC834REUQpG_u[12];
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  for (c8_sJUjlCK20kX4xC834REUQpG_i29 = 0; c8_sJUjlCK20kX4xC834REUQpG_i29 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i29++) {
    c8_sJUjlCK20kX4xC834REUQpG_u[c8_sJUjlCK20kX4xC834REUQpG_i29] = (*(real_T (*)
      [12])c8_sJUjlCK20kX4xC834REUQpG_inData)[c8_sJUjlCK20kX4xC834REUQpG_i29];
  }

  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

static void c8_sJUjlCK20kX4xC834REUQpG_c_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_xNew, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12])
{
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_b_xNew), &c8_sJUjlCK20kX4xC834REUQpG_thisId,
    c8_sJUjlCK20kX4xC834REUQpG_y);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_xNew);
}

static void c8_sJUjlCK20kX4xC834REUQpG_d_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, real_T
   c8_sJUjlCK20kX4xC834REUQpG_y[12])
{
  real_T c8_sJUjlCK20kX4xC834REUQpG_dv3[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i30;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), c8_sJUjlCK20kX4xC834REUQpG_dv3,
                1, 0, 0U, 1, 0U, 1, 12);
  for (c8_sJUjlCK20kX4xC834REUQpG_i30 = 0; c8_sJUjlCK20kX4xC834REUQpG_i30 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i30++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i30] =
      c8_sJUjlCK20kX4xC834REUQpG_dv3[c8_sJUjlCK20kX4xC834REUQpG_i30];
  }

  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_xNew;
  const char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i31;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_b_xNew = sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
  c8_sJUjlCK20kX4xC834REUQpG_identifier = c8_sJUjlCK20kX4xC834REUQpG_varName;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_b_xNew), &c8_sJUjlCK20kX4xC834REUQpG_thisId,
    c8_sJUjlCK20kX4xC834REUQpG_y);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_xNew);
  for (c8_sJUjlCK20kX4xC834REUQpG_i31 = 0; c8_sJUjlCK20kX4xC834REUQpG_i31 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i31++) {
    (*(real_T (*)[12])c8_sJUjlCK20kX4xC834REUQpG_outData)
      [c8_sJUjlCK20kX4xC834REUQpG_i31] =
      c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i31];
  }

  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
  real_T c8_sJUjlCK20kX4xC834REUQpG_u;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_u = *(real_T *)c8_sJUjlCK20kX4xC834REUQpG_inData;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

static real_T c8_sJUjlCK20kX4xC834REUQpG_e_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  real_T c8_sJUjlCK20kX4xC834REUQpG_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_d0;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), &c8_sJUjlCK20kX4xC834REUQpG_d0,
                1, 0, 0U, 0, 0U, 0);
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_d0;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static void c8_sJUjlCK20kX4xC834REUQpG_c_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_nargout;
  const char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_nargout = sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
  c8_sJUjlCK20kX4xC834REUQpG_identifier = c8_sJUjlCK20kX4xC834REUQpG_varName;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_nargout),
     &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_nargout);
  *(real_T *)c8_sJUjlCK20kX4xC834REUQpG_outData = c8_sJUjlCK20kX4xC834REUQpG_y;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_u;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i32;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_u[19];
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_c_u;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_d_y = NULL;
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_d_u;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_e_y = NULL;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_u =
    *(c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE *)
    c8_sJUjlCK20kX4xC834REUQpG_inData;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_createstruct("structure",
    2, 1, 1), false);
  for (c8_sJUjlCK20kX4xC834REUQpG_i32 = 0; c8_sJUjlCK20kX4xC834REUQpG_i32 < 19;
       c8_sJUjlCK20kX4xC834REUQpG_i32++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_u[c8_sJUjlCK20kX4xC834REUQpG_i32] =
      c8_sJUjlCK20kX4xC834REUQpG_u.FcnName[c8_sJUjlCK20kX4xC834REUQpG_i32];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_b_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_b_u, 10, 0U, 1U, 0U, 2, 1, 19), false);
  sf_mex_addfield(c8_sJUjlCK20kX4xC834REUQpG_y, c8_sJUjlCK20kX4xC834REUQpG_b_y,
                  "FcnName", "FcnName", 0);
  c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_c_y, sf_mex_create("y", NULL, 10, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_addfield(c8_sJUjlCK20kX4xC834REUQpG_y, c8_sJUjlCK20kX4xC834REUQpG_c_y,
                  "JacobianFcnName", "JacobianFcnName", 0);
  c8_sJUjlCK20kX4xC834REUQpG_c_u = c8_sJUjlCK20kX4xC834REUQpG_u.HasJacobian;
  c8_sJUjlCK20kX4xC834REUQpG_d_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_d_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sJUjlCK20kX4xC834REUQpG_y, c8_sJUjlCK20kX4xC834REUQpG_d_y,
                  "HasJacobian", "HasJacobian", 0);
  c8_sJUjlCK20kX4xC834REUQpG_d_u = c8_sJUjlCK20kX4xC834REUQpG_u.HasAdditiveNoise;
  c8_sJUjlCK20kX4xC834REUQpG_e_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_e_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c8_sJUjlCK20kX4xC834REUQpG_y, c8_sJUjlCK20kX4xC834REUQpG_e_y,
                  "HasAdditiveNoise", "HasAdditiveNoise", 0);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  (void)c8_sJUjlCK20kX4xC834REUQpG_inData;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y", NULL, 0, 0U,
    1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

const mxArray
  *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_nameCaptureInfo = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_nameCaptureInfo, sf_mex_create(
    "nameCaptureInfo", NULL, 0, 0U, 1U, 0U, 2, 0, 1), false);
  return c8_sJUjlCK20kX4xC834REUQpG_nameCaptureInfo;
}

static void c8_sJUjlCK20kX4xC834REUQpG_EKFCorrectorAdditive_correct
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_z[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zcov[144], real_T c8_sJUjlCK20kX4xC834REUQpG_b_x
   [12], real_T c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_c_x[12], real_T c8_sJUjlCK20kX4xC834REUQpG_c_P[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i33;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i34;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i35;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i36;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_z[12];
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_zcov[144];
  for (c8_sJUjlCK20kX4xC834REUQpG_i33 = 0; c8_sJUjlCK20kX4xC834REUQpG_i33 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i33++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_x[c8_sJUjlCK20kX4xC834REUQpG_i33] =
      c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i33];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i34 = 0; c8_sJUjlCK20kX4xC834REUQpG_i34 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i34++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_P[c8_sJUjlCK20kX4xC834REUQpG_i34] =
      c8_sJUjlCK20kX4xC834REUQpG_b_P[c8_sJUjlCK20kX4xC834REUQpG_i34];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i35 = 0; c8_sJUjlCK20kX4xC834REUQpG_i35 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i35++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_z[c8_sJUjlCK20kX4xC834REUQpG_i35] =
      c8_sJUjlCK20kX4xC834REUQpG_z[c8_sJUjlCK20kX4xC834REUQpG_i35];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i36 = 0; c8_sJUjlCK20kX4xC834REUQpG_i36 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i36++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_zcov[c8_sJUjlCK20kX4xC834REUQpG_i36] =
      c8_sJUjlCK20kX4xC834REUQpG_zcov[c8_sJUjlCK20kX4xC834REUQpG_i36];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrectorAdditive_correct(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_b_z, c8_sJUjlCK20kX4xC834REUQpG_b_zcov,
    c8_sJUjlCK20kX4xC834REUQpG_c_x, c8_sJUjlCK20kX4xC834REUQpG_c_P);
}

static void c8_sJUjlCK20kX4xC834REUQpG_numericJacobian
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2
   c8_sJUjlCK20kX4xC834REUQpG_vec[1], real_T
   c8_sJUjlCK20kX4xC834REUQpG_inputToDerive, real_T
   c8_sJUjlCK20kX4xC834REUQpG_jacobian[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i37;
  real_T c8_sJUjlCK20kX4xC834REUQpG_imvec[12];
  real_T c8_sJUjlCK20kX4xC834REUQpG_z[12];
  c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2 c8_sJUjlCK20kX4xC834REUQpG_specvec[1];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_j;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_j;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i38;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_x;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_x;
  real_T c8_sJUjlCK20kX4xC834REUQpG_d_x;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_varargin_2;
  real_T c8_sJUjlCK20kX4xC834REUQpG_varargin_3;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_d_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_maxval;
  real_T c8_sJUjlCK20kX4xC834REUQpG_epsilon;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i39;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i40;
  real_T c8_sJUjlCK20kX4xC834REUQpG_imz[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i41;
  real_T c8_sJUjlCK20kX4xC834REUQpG_B;
  real_T c8_sJUjlCK20kX4xC834REUQpG_e_y;
  real_T c8_sJUjlCK20kX4xC834REUQpG_f_y;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_c_j;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i42;
  sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0,
    0, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
    c8_sJUjlCK20kX4xC834REUQpG_inputToDerive) - 1, 0, 0);
  for (c8_sJUjlCK20kX4xC834REUQpG_i37 = 0; c8_sJUjlCK20kX4xC834REUQpG_i37 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i37++) {
    c8_sJUjlCK20kX4xC834REUQpG_imvec[c8_sJUjlCK20kX4xC834REUQpG_i37] =
      c8_sJUjlCK20kX4xC834REUQpG_vec[0].f1[c8_sJUjlCK20kX4xC834REUQpG_i37];
  }

  CV_EML_FCN(0, 3);
  c8_sJUjlCK20kX4xC834REUQpG_measurementDroneFcn_invoke(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_imvec, c8_sJUjlCK20kX4xC834REUQpG_z);
  sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0,
    0, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
    c8_sJUjlCK20kX4xC834REUQpG_inputToDerive) - 1, 0, 0);
  sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0,
    0, MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
    c8_sJUjlCK20kX4xC834REUQpG_inputToDerive) - 1, 0, 0);
  c8_sJUjlCK20kX4xC834REUQpG_specvec[0] = c8_sJUjlCK20kX4xC834REUQpG_vec[0];
  for (c8_sJUjlCK20kX4xC834REUQpG_j = 0; c8_sJUjlCK20kX4xC834REUQpG_j < 12;
       c8_sJUjlCK20kX4xC834REUQpG_j++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_j = 1.0 + (real_T)c8_sJUjlCK20kX4xC834REUQpG_j;
    for (c8_sJUjlCK20kX4xC834REUQpG_i38 = 0; c8_sJUjlCK20kX4xC834REUQpG_i38 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i38++) {
      c8_sJUjlCK20kX4xC834REUQpG_imvec[c8_sJUjlCK20kX4xC834REUQpG_i38] =
        c8_sJUjlCK20kX4xC834REUQpG_vec[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
          c8_sJUjlCK20kX4xC834REUQpG_inputToDerive) - 1, 0, 0)]
        .f1[c8_sJUjlCK20kX4xC834REUQpG_i38];
    }

    c8_sJUjlCK20kX4xC834REUQpG_b_x =
      c8_sJUjlCK20kX4xC834REUQpG_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sJUjlCK20kX4xC834REUQpG_b_j), 1, 12) - 1];
    c8_sJUjlCK20kX4xC834REUQpG_c_x = c8_sJUjlCK20kX4xC834REUQpG_b_x;
    c8_sJUjlCK20kX4xC834REUQpG_d_x = c8_sJUjlCK20kX4xC834REUQpG_c_x;
    c8_sJUjlCK20kX4xC834REUQpG_y = muDoubleScalarAbs
      (c8_sJUjlCK20kX4xC834REUQpG_d_x);
    c8_sJUjlCK20kX4xC834REUQpG_varargin_2 = 1.4901161193847656E-8 *
      c8_sJUjlCK20kX4xC834REUQpG_y;
    c8_sJUjlCK20kX4xC834REUQpG_varargin_3 =
      c8_sJUjlCK20kX4xC834REUQpG_varargin_2;
    c8_sJUjlCK20kX4xC834REUQpG_b_y = c8_sJUjlCK20kX4xC834REUQpG_varargin_3;
    c8_sJUjlCK20kX4xC834REUQpG_c_y = c8_sJUjlCK20kX4xC834REUQpG_b_y;
    c8_sJUjlCK20kX4xC834REUQpG_d_y = c8_sJUjlCK20kX4xC834REUQpG_c_y;
    c8_sJUjlCK20kX4xC834REUQpG_maxval = muDoubleScalarMax(1.4901161193847656E-8,
      c8_sJUjlCK20kX4xC834REUQpG_d_y);
    c8_sJUjlCK20kX4xC834REUQpG_epsilon = c8_sJUjlCK20kX4xC834REUQpG_maxval;
    c8_sJUjlCK20kX4xC834REUQpG_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sJUjlCK20kX4xC834REUQpG_b_j), 1, 12) - 1] =
      c8_sJUjlCK20kX4xC834REUQpG_imvec[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sJUjlCK20kX4xC834REUQpG_b_j), 1, 12) - 1] +
      c8_sJUjlCK20kX4xC834REUQpG_epsilon;
    for (c8_sJUjlCK20kX4xC834REUQpG_i39 = 0; c8_sJUjlCK20kX4xC834REUQpG_i39 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i39++) {
      c8_sJUjlCK20kX4xC834REUQpG_specvec[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
          c8_sJUjlCK20kX4xC834REUQpG_inputToDerive) - 1, 0, 0)]
        .f1[c8_sJUjlCK20kX4xC834REUQpG_i39] =
        c8_sJUjlCK20kX4xC834REUQpG_imvec[c8_sJUjlCK20kX4xC834REUQpG_i39];
    }

    for (c8_sJUjlCK20kX4xC834REUQpG_i40 = 0; c8_sJUjlCK20kX4xC834REUQpG_i40 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i40++) {
      c8_sJUjlCK20kX4xC834REUQpG_imvec[c8_sJUjlCK20kX4xC834REUQpG_i40] =
        c8_sJUjlCK20kX4xC834REUQpG_specvec[0].f1[c8_sJUjlCK20kX4xC834REUQpG_i40];
    }

    CV_EML_FCN(0, 3);
    c8_sJUjlCK20kX4xC834REUQpG_measurementDroneFcn_invoke(chartInstance,
      c8_sJUjlCK20kX4xC834REUQpG_imvec, c8_sJUjlCK20kX4xC834REUQpG_imz);
    for (c8_sJUjlCK20kX4xC834REUQpG_i41 = 0; c8_sJUjlCK20kX4xC834REUQpG_i41 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i41++) {
      c8_sJUjlCK20kX4xC834REUQpG_imz[c8_sJUjlCK20kX4xC834REUQpG_i41] -=
        c8_sJUjlCK20kX4xC834REUQpG_z[c8_sJUjlCK20kX4xC834REUQpG_i41];
    }

    c8_sJUjlCK20kX4xC834REUQpG_B = c8_sJUjlCK20kX4xC834REUQpG_epsilon;
    c8_sJUjlCK20kX4xC834REUQpG_e_y = c8_sJUjlCK20kX4xC834REUQpG_B;
    c8_sJUjlCK20kX4xC834REUQpG_f_y = c8_sJUjlCK20kX4xC834REUQpG_e_y;
    c8_sJUjlCK20kX4xC834REUQpG_c_j = sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
        c8_sJUjlCK20kX4xC834REUQpG_b_j), 1, 12) - 1;
    for (c8_sJUjlCK20kX4xC834REUQpG_i42 = 0; c8_sJUjlCK20kX4xC834REUQpG_i42 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i42++) {
      c8_sJUjlCK20kX4xC834REUQpG_jacobian[c8_sJUjlCK20kX4xC834REUQpG_i42 + 12 *
        c8_sJUjlCK20kX4xC834REUQpG_c_j] =
        c8_sJUjlCK20kX4xC834REUQpG_imz[c8_sJUjlCK20kX4xC834REUQpG_i42] /
        c8_sJUjlCK20kX4xC834REUQpG_f_y;
    }
  }
}

static void c8_sJUjlCK20kX4xC834REUQpG_EKFCorrector_correctStateAndCovarianc
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zEstimated[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zMeasured[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_Pxy[144], real_T c8_sJUjlCK20kX4xC834REUQpG_Pyy
   [144], real_T c8_sJUjlCK20kX4xC834REUQpG_dHdx[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_c_x[12], real_T c8_sJUjlCK20kX4xC834REUQpG_c_P[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i43;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i44;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i45;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i46;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_zEstimated[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i47;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_zMeasured[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i48;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_Pxy[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i49;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_Pyy[144];
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_dHdx[144];
  for (c8_sJUjlCK20kX4xC834REUQpG_i43 = 0; c8_sJUjlCK20kX4xC834REUQpG_i43 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i43++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_x[c8_sJUjlCK20kX4xC834REUQpG_i43] =
      c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i43];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i44 = 0; c8_sJUjlCK20kX4xC834REUQpG_i44 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i44++) {
    c8_sJUjlCK20kX4xC834REUQpG_c_P[c8_sJUjlCK20kX4xC834REUQpG_i44] =
      c8_sJUjlCK20kX4xC834REUQpG_b_P[c8_sJUjlCK20kX4xC834REUQpG_i44];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i45 = 0; c8_sJUjlCK20kX4xC834REUQpG_i45 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i45++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_zEstimated[c8_sJUjlCK20kX4xC834REUQpG_i45] =
      c8_sJUjlCK20kX4xC834REUQpG_zEstimated[c8_sJUjlCK20kX4xC834REUQpG_i45];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i46 = 0; c8_sJUjlCK20kX4xC834REUQpG_i46 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i46++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_zMeasured[c8_sJUjlCK20kX4xC834REUQpG_i46] =
      c8_sJUjlCK20kX4xC834REUQpG_zMeasured[c8_sJUjlCK20kX4xC834REUQpG_i46];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i47 = 0; c8_sJUjlCK20kX4xC834REUQpG_i47 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i47++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_Pxy[c8_sJUjlCK20kX4xC834REUQpG_i47] =
      c8_sJUjlCK20kX4xC834REUQpG_Pxy[c8_sJUjlCK20kX4xC834REUQpG_i47];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i48 = 0; c8_sJUjlCK20kX4xC834REUQpG_i48 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i48++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i48] =
      c8_sJUjlCK20kX4xC834REUQpG_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i48];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i49 = 0; c8_sJUjlCK20kX4xC834REUQpG_i49 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i49++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_dHdx[c8_sJUjlCK20kX4xC834REUQpG_i49] =
      c8_sJUjlCK20kX4xC834REUQpG_dHdx[c8_sJUjlCK20kX4xC834REUQpG_i49];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrector_correctStateAndCovaria(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_c_x, c8_sJUjlCK20kX4xC834REUQpG_c_P,
    c8_sJUjlCK20kX4xC834REUQpG_b_zEstimated,
    c8_sJUjlCK20kX4xC834REUQpG_b_zMeasured, c8_sJUjlCK20kX4xC834REUQpG_b_Pxy,
    c8_sJUjlCK20kX4xC834REUQpG_b_Pyy, c8_sJUjlCK20kX4xC834REUQpG_b_dHdx);
}

static void c8_sJUjlCK20kX4xC834REUQpG_mrdivide
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_B[144], real_T c8_sJUjlCK20kX4xC834REUQpG_y[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i50;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_A[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_ipiv[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_info;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i51;
  real_T c8_sJUjlCK20kX4xC834REUQpG_alpha1;
  char_T c8_sJUjlCK20kX4xC834REUQpG_DIAGA;
  char_T c8_sJUjlCK20kX4xC834REUQpG_TRANSA;
  char_T c8_sJUjlCK20kX4xC834REUQpG_UPLO;
  char_T c8_sJUjlCK20kX4xC834REUQpG_SIDE;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_m_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ldb_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_alpha1;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_DIAGA;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_UPLO;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_SIDE;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_m_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_xj;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_jp;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_xi;
  real_T c8_sJUjlCK20kX4xC834REUQpG_temp;
  for (c8_sJUjlCK20kX4xC834REUQpG_i50 = 0; c8_sJUjlCK20kX4xC834REUQpG_i50 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i50++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_A[c8_sJUjlCK20kX4xC834REUQpG_i50] =
      c8_sJUjlCK20kX4xC834REUQpG_B[c8_sJUjlCK20kX4xC834REUQpG_i50];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_xgetrf(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_b_A, c8_sJUjlCK20kX4xC834REUQpG_ipiv,
    &c8_sJUjlCK20kX4xC834REUQpG_info);
  if ((real_T)c8_sJUjlCK20kX4xC834REUQpG_info > 0.0) {
    c8_sJUjlCK20kX4xC834REUQpG_warning(chartInstance);
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i51 = 0; c8_sJUjlCK20kX4xC834REUQpG_i51 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i51++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i51] =
      c8_sJUjlCK20kX4xC834REUQpG_A[c8_sJUjlCK20kX4xC834REUQpG_i51];
  }

  c8_sJUjlCK20kX4xC834REUQpG_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_DIAGA = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_TRANSA = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_UPLO = 'U';
  c8_sJUjlCK20kX4xC834REUQpG_SIDE = 'R';
  c8_sJUjlCK20kX4xC834REUQpG_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_ldb_t = (ptrdiff_t)12;
  dtrsm(&c8_sJUjlCK20kX4xC834REUQpG_SIDE, &c8_sJUjlCK20kX4xC834REUQpG_UPLO,
        &c8_sJUjlCK20kX4xC834REUQpG_TRANSA, &c8_sJUjlCK20kX4xC834REUQpG_DIAGA,
        &c8_sJUjlCK20kX4xC834REUQpG_m_t, &c8_sJUjlCK20kX4xC834REUQpG_n_t,
        &c8_sJUjlCK20kX4xC834REUQpG_alpha1, &c8_sJUjlCK20kX4xC834REUQpG_b_A[0],
        &c8_sJUjlCK20kX4xC834REUQpG_lda_t, &c8_sJUjlCK20kX4xC834REUQpG_y[0],
        &c8_sJUjlCK20kX4xC834REUQpG_ldb_t);
  c8_sJUjlCK20kX4xC834REUQpG_b_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_b_DIAGA = 'U';
  c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_b_UPLO = 'L';
  c8_sJUjlCK20kX4xC834REUQpG_b_SIDE = 'R';
  c8_sJUjlCK20kX4xC834REUQpG_b_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t = (ptrdiff_t)12;
  dtrsm(&c8_sJUjlCK20kX4xC834REUQpG_b_SIDE, &c8_sJUjlCK20kX4xC834REUQpG_b_UPLO,
        &c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA,
        &c8_sJUjlCK20kX4xC834REUQpG_b_DIAGA, &c8_sJUjlCK20kX4xC834REUQpG_b_m_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b_n_t, &c8_sJUjlCK20kX4xC834REUQpG_b_alpha1,
        &c8_sJUjlCK20kX4xC834REUQpG_b_A[0], &c8_sJUjlCK20kX4xC834REUQpG_b_lda_t,
        &c8_sJUjlCK20kX4xC834REUQpG_y[0], &c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t);
  for (c8_sJUjlCK20kX4xC834REUQpG_xj = 10; c8_sJUjlCK20kX4xC834REUQpG_xj + 1 > 0;
       c8_sJUjlCK20kX4xC834REUQpG_xj--) {
    if (c8_sJUjlCK20kX4xC834REUQpG_ipiv[c8_sJUjlCK20kX4xC834REUQpG_xj] !=
        c8_sJUjlCK20kX4xC834REUQpG_xj + 1) {
      c8_sJUjlCK20kX4xC834REUQpG_jp =
        c8_sJUjlCK20kX4xC834REUQpG_ipiv[c8_sJUjlCK20kX4xC834REUQpG_xj] - 1;
      for (c8_sJUjlCK20kX4xC834REUQpG_xi = 0; c8_sJUjlCK20kX4xC834REUQpG_xi + 1 <
           13; c8_sJUjlCK20kX4xC834REUQpG_xi++) {
        c8_sJUjlCK20kX4xC834REUQpG_temp =
          c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_xi + 12 *
          c8_sJUjlCK20kX4xC834REUQpG_xj];
        c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_xi + 12 *
          c8_sJUjlCK20kX4xC834REUQpG_xj] =
          c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_xi + 12 *
          c8_sJUjlCK20kX4xC834REUQpG_jp];
        c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_xi + 12 *
          c8_sJUjlCK20kX4xC834REUQpG_jp] = c8_sJUjlCK20kX4xC834REUQpG_temp;
      }
    }
  }
}

static void c8_sJUjlCK20kX4xC834REUQpG_xgetrf
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_A[144], int32_T c8_sJUjlCK20kX4xC834REUQpG_ipiv
   [12], int32_T *c8_sJUjlCK20kX4xC834REUQpG_info)
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i52;
  for (c8_sJUjlCK20kX4xC834REUQpG_i52 = 0; c8_sJUjlCK20kX4xC834REUQpG_i52 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i52++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_A[c8_sJUjlCK20kX4xC834REUQpG_i52] =
      c8_sJUjlCK20kX4xC834REUQpG_A[c8_sJUjlCK20kX4xC834REUQpG_i52];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_xgetrf(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_b_A, c8_sJUjlCK20kX4xC834REUQpG_ipiv,
    c8_sJUjlCK20kX4xC834REUQpG_info);
}

static void c8_sJUjlCK20kX4xC834REUQpG_error
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_cv0[12] = { 'M', 'A', 'T', 'L', 'A',
    'B', ':', 'n', 'o', 'm', 'e', 'm' };

  (void)chartInstance;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_cv0, 10, 0U, 1U, 0U, 2, 1, 12), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c8_sJUjlCK20kX4xC834REUQpG_y));
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_error
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, int32_T c8_sJUjlCK20kX4xC834REUQpG_varargin_2)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_cv1[33] = { 'C', 'o', 'd', 'e', 'r',
    ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K',
    'C', 'a', 'l', 'l', 'E', 'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_cv2[19] = { 'L', 'A', 'P', 'A', 'C',
    'K', 'E', '_', 'd', 'g', 'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  (void)chartInstance;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_cv1, 10, 0U, 1U, 0U, 2, 1, 33), false);
  c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_b_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_cv2, 10, 0U, 1U, 0U, 2, 1, 19), false);
  c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_c_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_varargin_2, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c8_sJUjlCK20kX4xC834REUQpG_y, 14, c8_sJUjlCK20kX4xC834REUQpG_b_y, 14,
    c8_sJUjlCK20kX4xC834REUQpG_c_y));
}

static void c8_sJUjlCK20kX4xC834REUQpG_warning
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_cv3[7] = { 'w', 'a', 'r', 'n', 'i',
    'n', 'g' };

  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_cv4[7] = { 'm', 'e', 's', 's', 'a',
    'g', 'e' };

  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  static char_T c8_sJUjlCK20kX4xC834REUQpG_msgID[27] = { 'C', 'o', 'd', 'e', 'r',
    ':', 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a',
    'r', 'M', 'a', 't', 'r', 'i', 'x' };

  (void)chartInstance;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_cv3, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sJUjlCK20kX4xC834REUQpG_b_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_b_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_cv4, 10, 0U, 1U, 0U, 2, 1, 7), false);
  c8_sJUjlCK20kX4xC834REUQpG_c_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_c_y, sf_mex_create("y",
    c8_sJUjlCK20kX4xC834REUQpG_msgID, 10, 0U, 1U, 0U, 2, 1, 27), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14,
                    c8_sJUjlCK20kX4xC834REUQpG_y, 14, sf_mex_call_debug
                    (sfGlobalDebugInstanceStruct, "feval", 1U, 2U, 14,
                     c8_sJUjlCK20kX4xC834REUQpG_b_y, 14,
                     c8_sJUjlCK20kX4xC834REUQpG_c_y));
}

static const mxArray *c8_sJUjlCK20kX4xC834REUQpG_f_sf_marshallOut(void
  *chartInstanceVoid, void *c8_sJUjlCK20kX4xC834REUQpG_inData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_u;
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_u = *(int32_T *)c8_sJUjlCK20kX4xC834REUQpG_inData;
  c8_sJUjlCK20kX4xC834REUQpG_y = NULL;
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_y, sf_mex_create("y",
    &c8_sJUjlCK20kX4xC834REUQpG_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData,
                c8_sJUjlCK20kX4xC834REUQpG_y, false);
  return c8_sJUjlCK20kX4xC834REUQpG_mxArrayOutData;
}

static int32_T c8_sJUjlCK20kX4xC834REUQpG_f_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_y;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i53;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), &c8_sJUjlCK20kX4xC834REUQpG_i53,
                1, 6, 0U, 0, 0U, 0);
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_i53;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static void c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_sfEvent;
  const char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_y;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_b_sfEvent = sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
  c8_sJUjlCK20kX4xC834REUQpG_identifier = c8_sJUjlCK20kX4xC834REUQpG_varName;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_b_sfEvent),
     &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_sfEvent);
  *(int32_T *)c8_sJUjlCK20kX4xC834REUQpG_outData = c8_sJUjlCK20kX4xC834REUQpG_y;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
}

static c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
  c8_sJUjlCK20kX4xC834REUQpG_g_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_y;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  static const char * c8_sJUjlCK20kX4xC834REUQpG_fieldNames[4] = { "FcnName",
    "JacobianFcnName", "HasJacobian", "HasAdditiveNoise" };

  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent =
    c8_sJUjlCK20kX4xC834REUQpG_parentId;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_sJUjlCK20kX4xC834REUQpG_parentId,
                      c8_sJUjlCK20kX4xC834REUQpG_u, 4,
                      c8_sJUjlCK20kX4xC834REUQpG_fieldNames, 0U, NULL);
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = "FcnName";
  c8_sJUjlCK20kX4xC834REUQpG_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sJUjlCK20kX4xC834REUQpG_u, "FcnName", "FcnName", 0)),
    &c8_sJUjlCK20kX4xC834REUQpG_thisId, c8_sJUjlCK20kX4xC834REUQpG_y.FcnName);
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = "JacobianFcnName";
  c8_sJUjlCK20kX4xC834REUQpG_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sJUjlCK20kX4xC834REUQpG_u, "JacobianFcnName",
                     "JacobianFcnName", 0)), &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = "HasJacobian";
  c8_sJUjlCK20kX4xC834REUQpG_y.HasJacobian =
    c8_sJUjlCK20kX4xC834REUQpG_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sJUjlCK20kX4xC834REUQpG_u, "HasJacobian", "HasJacobian",
                     0)), &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = "HasAdditiveNoise";
  c8_sJUjlCK20kX4xC834REUQpG_y.HasAdditiveNoise =
    c8_sJUjlCK20kX4xC834REUQpG_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_sJUjlCK20kX4xC834REUQpG_u, "HasAdditiveNoise",
                     "HasAdditiveNoise", 0)), &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static void c8_sJUjlCK20kX4xC834REUQpG_h_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId, char_T
   c8_sJUjlCK20kX4xC834REUQpG_y[19])
{
  char_T c8_sJUjlCK20kX4xC834REUQpG_cv5[19];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i54;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), c8_sJUjlCK20kX4xC834REUQpG_cv5,
                1, 10, 0U, 1, 0U, 2, 1, 19);
  for (c8_sJUjlCK20kX4xC834REUQpG_i54 = 0; c8_sJUjlCK20kX4xC834REUQpG_i54 < 19;
       c8_sJUjlCK20kX4xC834REUQpG_i54++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i54] =
      c8_sJUjlCK20kX4xC834REUQpG_cv5[c8_sJUjlCK20kX4xC834REUQpG_i54];
  }

  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
}

static void c8_sJUjlCK20kX4xC834REUQpG_i_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), NULL, 1, 10, 0U, 1, 0U, 2, 0, 0);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
}

static boolean_T c8_sJUjlCK20kX4xC834REUQpG_j_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_y;
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_b0;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), &c8_sJUjlCK20kX4xC834REUQpG_b0,
                1, 11, 0U, 0, 0U, 0);
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_b0;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static void c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallIn(void *chartInstanceVoid,
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData, const char_T
  *c8_sJUjlCK20kX4xC834REUQpG_varName, void *c8_sJUjlCK20kX4xC834REUQpG_outData)
{
  const mxArray *c8_sJUjlCK20kX4xC834REUQpG_b_pM;
  const char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE
    c8_sJUjlCK20kX4xC834REUQpG_y;
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
    chartInstanceVoid;
  c8_sJUjlCK20kX4xC834REUQpG_b_pM = sf_mex_dup
    (c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
  c8_sJUjlCK20kX4xC834REUQpG_identifier = c8_sJUjlCK20kX4xC834REUQpG_varName;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(c8_sJUjlCK20kX4xC834REUQpG_b_pM),
     &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_b_pM);
  *(c8_sJUjlCK20kX4xC834REUQpG_sex2lFeEcOPeDeDewnWtFVE *)
    c8_sJUjlCK20kX4xC834REUQpG_outData = c8_sJUjlCK20kX4xC834REUQpG_y;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_mxArrayInData);
}

static uint8_T c8_sJUjlCK20kX4xC834REUQpG_k_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray
   *c8_sJUjlCK20kX4xC834REUQpG_b_is_active_c8_sJUjlCK20kX4xC834REUQp, const
   char_T *c8_sJUjlCK20kX4xC834REUQpG_identifier)
{
  uint8_T c8_sJUjlCK20kX4xC834REUQpG_y;
  emlrtMsgIdentifier c8_sJUjlCK20kX4xC834REUQpG_thisId;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fIdentifier = (const char *)
    c8_sJUjlCK20kX4xC834REUQpG_identifier;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.fParent = NULL;
  c8_sJUjlCK20kX4xC834REUQpG_thisId.bParentIsCell = false;
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup
     (c8_sJUjlCK20kX4xC834REUQpG_b_is_active_c8_sJUjlCK20kX4xC834REUQp),
     &c8_sJUjlCK20kX4xC834REUQpG_thisId);
  sf_mex_destroy
    (&c8_sJUjlCK20kX4xC834REUQpG_b_is_active_c8_sJUjlCK20kX4xC834REUQp);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static uint8_T c8_sJUjlCK20kX4xC834REUQpG_l_emlrt_marshallIn
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, const mxArray *c8_sJUjlCK20kX4xC834REUQpG_u, const
   emlrtMsgIdentifier *c8_sJUjlCK20kX4xC834REUQpG_parentId)
{
  uint8_T c8_sJUjlCK20kX4xC834REUQpG_y;
  uint8_T c8_sJUjlCK20kX4xC834REUQpG_u0;
  (void)chartInstance;
  sf_mex_import(c8_sJUjlCK20kX4xC834REUQpG_parentId, sf_mex_dup
                (c8_sJUjlCK20kX4xC834REUQpG_u), &c8_sJUjlCK20kX4xC834REUQpG_u0,
                1, 3, 0U, 0, 0U, 0);
  c8_sJUjlCK20kX4xC834REUQpG_y = c8_sJUjlCK20kX4xC834REUQpG_u0;
  sf_mex_destroy(&c8_sJUjlCK20kX4xC834REUQpG_u);
  return c8_sJUjlCK20kX4xC834REUQpG_y;
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrectorAdditive_correct
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_z[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zcov[144], real_T c8_sJUjlCK20kX4xC834REUQpG_b_x
   [12], real_T c8_sJUjlCK20kX4xC834REUQpG_b_P[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i55;
  c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2 c8_sJUjlCK20kX4xC834REUQpG_rv0[1];
  c8_sJUjlCK20kX4xC834REUQpG_cell_wrap_2 c8_sJUjlCK20kX4xC834REUQpG_r2;
  real_T c8_sJUjlCK20kX4xC834REUQpG_dHdx[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i56;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i57;
  real_T c8_sJUjlCK20kX4xC834REUQpG_alpha1;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i58;
  real_T c8_sJUjlCK20kX4xC834REUQpG_beta1;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i59;
  char_T c8_sJUjlCK20kX4xC834REUQpG_TRANSB;
  char_T c8_sJUjlCK20kX4xC834REUQpG_TRANSA;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i60;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b[144];
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_m_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_Pxy[144];
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_k_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ldb_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ldc_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_alpha1;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_beta1;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i61;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_m_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y[144];
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_k_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i62;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i63;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_alpha1;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i64;
  real_T c8_sJUjlCK20kX4xC834REUQpG_c_beta1;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i65;
  char_T c8_sJUjlCK20kX4xC834REUQpG_c_TRANSB;
  char_T c8_sJUjlCK20kX4xC834REUQpG_c_TRANSA;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i66;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_m_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_Pyy[144];
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_k_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_ldb_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_c_ldc_t;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i67;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i68;
  real_T c8_sJUjlCK20kX4xC834REUQpG_xx[12];
  real_T c8_sJUjlCK20kX4xC834REUQpG_zEstimated[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i69;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_z[12];
  for (c8_sJUjlCK20kX4xC834REUQpG_i55 = 0; c8_sJUjlCK20kX4xC834REUQpG_i55 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i55++) {
    c8_sJUjlCK20kX4xC834REUQpG_r2.f1[c8_sJUjlCK20kX4xC834REUQpG_i55] =
      c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i55];
  }

  c8_sJUjlCK20kX4xC834REUQpG_rv0[0] = c8_sJUjlCK20kX4xC834REUQpG_r2;
  c8_sJUjlCK20kX4xC834REUQpG_numericJacobian(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_rv0, 1.0, c8_sJUjlCK20kX4xC834REUQpG_dHdx);
  c8_sJUjlCK20kX4xC834REUQpG_i56 = 0;
  for (c8_sJUjlCK20kX4xC834REUQpG_i57 = 0; c8_sJUjlCK20kX4xC834REUQpG_i57 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i57++) {
    c8_sJUjlCK20kX4xC834REUQpG_i58 = 0;
    for (c8_sJUjlCK20kX4xC834REUQpG_i59 = 0; c8_sJUjlCK20kX4xC834REUQpG_i59 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i59++) {
      c8_sJUjlCK20kX4xC834REUQpG_b[c8_sJUjlCK20kX4xC834REUQpG_i59 +
        c8_sJUjlCK20kX4xC834REUQpG_i56] =
        c8_sJUjlCK20kX4xC834REUQpG_dHdx[c8_sJUjlCK20kX4xC834REUQpG_i58 +
        c8_sJUjlCK20kX4xC834REUQpG_i57];
      c8_sJUjlCK20kX4xC834REUQpG_i58 += 12;
    }

    c8_sJUjlCK20kX4xC834REUQpG_i56 += 12;
  }

  c8_sJUjlCK20kX4xC834REUQpG_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_beta1 = 0.0;
  c8_sJUjlCK20kX4xC834REUQpG_TRANSB = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_TRANSA = 'N';
  for (c8_sJUjlCK20kX4xC834REUQpG_i60 = 0; c8_sJUjlCK20kX4xC834REUQpG_i60 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i60++) {
    c8_sJUjlCK20kX4xC834REUQpG_Pxy[c8_sJUjlCK20kX4xC834REUQpG_i60] = 0.0;
  }

  c8_sJUjlCK20kX4xC834REUQpG_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_k_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_ldb_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sJUjlCK20kX4xC834REUQpG_TRANSA, &c8_sJUjlCK20kX4xC834REUQpG_TRANSB,
        &c8_sJUjlCK20kX4xC834REUQpG_m_t, &c8_sJUjlCK20kX4xC834REUQpG_n_t,
        &c8_sJUjlCK20kX4xC834REUQpG_k_t, &c8_sJUjlCK20kX4xC834REUQpG_alpha1,
        &c8_sJUjlCK20kX4xC834REUQpG_b_P[0], &c8_sJUjlCK20kX4xC834REUQpG_lda_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b[0], &c8_sJUjlCK20kX4xC834REUQpG_ldb_t,
        &c8_sJUjlCK20kX4xC834REUQpG_beta1, &c8_sJUjlCK20kX4xC834REUQpG_Pxy[0],
        &c8_sJUjlCK20kX4xC834REUQpG_ldc_t);
  c8_sJUjlCK20kX4xC834REUQpG_b_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_b_beta1 = 0.0;
  c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA = 'N';
  for (c8_sJUjlCK20kX4xC834REUQpG_i61 = 0; c8_sJUjlCK20kX4xC834REUQpG_i61 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i61++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i61] = 0.0;
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_k_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA,
        &c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB, &c8_sJUjlCK20kX4xC834REUQpG_b_m_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b_n_t, &c8_sJUjlCK20kX4xC834REUQpG_b_k_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b_alpha1, &c8_sJUjlCK20kX4xC834REUQpG_dHdx[0],
        &c8_sJUjlCK20kX4xC834REUQpG_b_lda_t, &c8_sJUjlCK20kX4xC834REUQpG_b_P[0],
        &c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t, &c8_sJUjlCK20kX4xC834REUQpG_b_beta1,
        &c8_sJUjlCK20kX4xC834REUQpG_y[0], &c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t);
  c8_sJUjlCK20kX4xC834REUQpG_i62 = 0;
  for (c8_sJUjlCK20kX4xC834REUQpG_i63 = 0; c8_sJUjlCK20kX4xC834REUQpG_i63 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i63++) {
    c8_sJUjlCK20kX4xC834REUQpG_i64 = 0;
    for (c8_sJUjlCK20kX4xC834REUQpG_i65 = 0; c8_sJUjlCK20kX4xC834REUQpG_i65 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i65++) {
      c8_sJUjlCK20kX4xC834REUQpG_b[c8_sJUjlCK20kX4xC834REUQpG_i65 +
        c8_sJUjlCK20kX4xC834REUQpG_i62] =
        c8_sJUjlCK20kX4xC834REUQpG_dHdx[c8_sJUjlCK20kX4xC834REUQpG_i64 +
        c8_sJUjlCK20kX4xC834REUQpG_i63];
      c8_sJUjlCK20kX4xC834REUQpG_i64 += 12;
    }

    c8_sJUjlCK20kX4xC834REUQpG_i62 += 12;
  }

  c8_sJUjlCK20kX4xC834REUQpG_c_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_c_beta1 = 0.0;
  c8_sJUjlCK20kX4xC834REUQpG_c_TRANSB = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_c_TRANSA = 'N';
  for (c8_sJUjlCK20kX4xC834REUQpG_i66 = 0; c8_sJUjlCK20kX4xC834REUQpG_i66 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i66++) {
    c8_sJUjlCK20kX4xC834REUQpG_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i66] = 0.0;
  }

  c8_sJUjlCK20kX4xC834REUQpG_c_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_c_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_c_k_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_c_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_c_ldb_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_c_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sJUjlCK20kX4xC834REUQpG_c_TRANSA,
        &c8_sJUjlCK20kX4xC834REUQpG_c_TRANSB, &c8_sJUjlCK20kX4xC834REUQpG_c_m_t,
        &c8_sJUjlCK20kX4xC834REUQpG_c_n_t, &c8_sJUjlCK20kX4xC834REUQpG_c_k_t,
        &c8_sJUjlCK20kX4xC834REUQpG_c_alpha1, &c8_sJUjlCK20kX4xC834REUQpG_y[0],
        &c8_sJUjlCK20kX4xC834REUQpG_c_lda_t, &c8_sJUjlCK20kX4xC834REUQpG_b[0],
        &c8_sJUjlCK20kX4xC834REUQpG_c_ldb_t, &c8_sJUjlCK20kX4xC834REUQpG_c_beta1,
        &c8_sJUjlCK20kX4xC834REUQpG_Pyy[0], &c8_sJUjlCK20kX4xC834REUQpG_c_ldc_t);
  for (c8_sJUjlCK20kX4xC834REUQpG_i67 = 0; c8_sJUjlCK20kX4xC834REUQpG_i67 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i67++) {
    c8_sJUjlCK20kX4xC834REUQpG_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i67] +=
      c8_sJUjlCK20kX4xC834REUQpG_zcov[c8_sJUjlCK20kX4xC834REUQpG_i67];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i68 = 0; c8_sJUjlCK20kX4xC834REUQpG_i68 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i68++) {
    c8_sJUjlCK20kX4xC834REUQpG_xx[c8_sJUjlCK20kX4xC834REUQpG_i68] =
      c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i68];
  }

  CV_EML_FCN(0, 3);
  c8_sJUjlCK20kX4xC834REUQpG_measurementDroneFcn_invoke(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_xx, c8_sJUjlCK20kX4xC834REUQpG_zEstimated);
  for (c8_sJUjlCK20kX4xC834REUQpG_i69 = 0; c8_sJUjlCK20kX4xC834REUQpG_i69 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i69++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_z[c8_sJUjlCK20kX4xC834REUQpG_i69] =
      c8_sJUjlCK20kX4xC834REUQpG_z[c8_sJUjlCK20kX4xC834REUQpG_i69];
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrector_correctStateAndCovaria(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_b_x, c8_sJUjlCK20kX4xC834REUQpG_b_P,
    c8_sJUjlCK20kX4xC834REUQpG_zEstimated, c8_sJUjlCK20kX4xC834REUQpG_b_z,
    c8_sJUjlCK20kX4xC834REUQpG_Pxy, c8_sJUjlCK20kX4xC834REUQpG_Pyy,
    c8_sJUjlCK20kX4xC834REUQpG_dHdx);
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_EKFCorrector_correctStateAndCovaria
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_b_x[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_b_P[144], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zEstimated[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_zMeasured[12], real_T
   c8_sJUjlCK20kX4xC834REUQpG_Pxy[144], real_T c8_sJUjlCK20kX4xC834REUQpG_Pyy
   [144], real_T c8_sJUjlCK20kX4xC834REUQpG_dHdx[144])
{
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i70;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i71;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_Pxy[144];
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_Pyy[144];
  real_T c8_sJUjlCK20kX4xC834REUQpG_gain[144];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i72;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i73;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i74;
  real_T c8_sJUjlCK20kX4xC834REUQpG_y[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i75;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i76;
  real_T c8_sJUjlCK20kX4xC834REUQpG_alpha1;
  real_T c8_sJUjlCK20kX4xC834REUQpG_beta1;
  char_T c8_sJUjlCK20kX4xC834REUQpG_TRANSB;
  char_T c8_sJUjlCK20kX4xC834REUQpG_TRANSA;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i77;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_m_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_y[144];
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_k_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ldb_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ldc_t;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_alpha1;
  real_T c8_sJUjlCK20kX4xC834REUQpG_b_beta1;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB;
  char_T c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i78;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_m_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_k_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_i79;
  for (c8_sJUjlCK20kX4xC834REUQpG_i70 = 0; c8_sJUjlCK20kX4xC834REUQpG_i70 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i70++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_Pxy[c8_sJUjlCK20kX4xC834REUQpG_i70] =
      c8_sJUjlCK20kX4xC834REUQpG_Pxy[c8_sJUjlCK20kX4xC834REUQpG_i70];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i71 = 0; c8_sJUjlCK20kX4xC834REUQpG_i71 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i71++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i71] =
      c8_sJUjlCK20kX4xC834REUQpG_Pyy[c8_sJUjlCK20kX4xC834REUQpG_i71];
  }

  c8_sJUjlCK20kX4xC834REUQpG_mrdivide(chartInstance,
    c8_sJUjlCK20kX4xC834REUQpG_b_Pxy, c8_sJUjlCK20kX4xC834REUQpG_b_Pyy,
    c8_sJUjlCK20kX4xC834REUQpG_gain);
  for (c8_sJUjlCK20kX4xC834REUQpG_i72 = 0; c8_sJUjlCK20kX4xC834REUQpG_i72 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i72++) {
    c8_sJUjlCK20kX4xC834REUQpG_b[c8_sJUjlCK20kX4xC834REUQpG_i72] =
      c8_sJUjlCK20kX4xC834REUQpG_zMeasured[c8_sJUjlCK20kX4xC834REUQpG_i72] -
      c8_sJUjlCK20kX4xC834REUQpG_zEstimated[c8_sJUjlCK20kX4xC834REUQpG_i72];
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i73 = 0; c8_sJUjlCK20kX4xC834REUQpG_i73 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i73++) {
    c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i73] = 0.0;
    c8_sJUjlCK20kX4xC834REUQpG_i75 = 0;
    for (c8_sJUjlCK20kX4xC834REUQpG_i76 = 0; c8_sJUjlCK20kX4xC834REUQpG_i76 < 12;
         c8_sJUjlCK20kX4xC834REUQpG_i76++) {
      c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i73] +=
        c8_sJUjlCK20kX4xC834REUQpG_gain[c8_sJUjlCK20kX4xC834REUQpG_i75 +
        c8_sJUjlCK20kX4xC834REUQpG_i73] *
        c8_sJUjlCK20kX4xC834REUQpG_b[c8_sJUjlCK20kX4xC834REUQpG_i76];
      c8_sJUjlCK20kX4xC834REUQpG_i75 += 12;
    }
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_i74 = 0; c8_sJUjlCK20kX4xC834REUQpG_i74 < 12;
       c8_sJUjlCK20kX4xC834REUQpG_i74++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_x[c8_sJUjlCK20kX4xC834REUQpG_i74] +=
      c8_sJUjlCK20kX4xC834REUQpG_y[c8_sJUjlCK20kX4xC834REUQpG_i74];
  }

  c8_sJUjlCK20kX4xC834REUQpG_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_beta1 = 0.0;
  c8_sJUjlCK20kX4xC834REUQpG_TRANSB = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_TRANSA = 'N';
  for (c8_sJUjlCK20kX4xC834REUQpG_i77 = 0; c8_sJUjlCK20kX4xC834REUQpG_i77 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i77++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_y[c8_sJUjlCK20kX4xC834REUQpG_i77] = 0.0;
  }

  c8_sJUjlCK20kX4xC834REUQpG_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_k_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_ldb_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sJUjlCK20kX4xC834REUQpG_TRANSA, &c8_sJUjlCK20kX4xC834REUQpG_TRANSB,
        &c8_sJUjlCK20kX4xC834REUQpG_m_t, &c8_sJUjlCK20kX4xC834REUQpG_n_t,
        &c8_sJUjlCK20kX4xC834REUQpG_k_t, &c8_sJUjlCK20kX4xC834REUQpG_alpha1,
        &c8_sJUjlCK20kX4xC834REUQpG_gain[0], &c8_sJUjlCK20kX4xC834REUQpG_lda_t,
        &c8_sJUjlCK20kX4xC834REUQpG_dHdx[0], &c8_sJUjlCK20kX4xC834REUQpG_ldb_t,
        &c8_sJUjlCK20kX4xC834REUQpG_beta1, &c8_sJUjlCK20kX4xC834REUQpG_b_y[0],
        &c8_sJUjlCK20kX4xC834REUQpG_ldc_t);
  c8_sJUjlCK20kX4xC834REUQpG_b_alpha1 = 1.0;
  c8_sJUjlCK20kX4xC834REUQpG_b_beta1 = 0.0;
  c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB = 'N';
  c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA = 'N';
  for (c8_sJUjlCK20kX4xC834REUQpG_i78 = 0; c8_sJUjlCK20kX4xC834REUQpG_i78 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i78++) {
    c8_sJUjlCK20kX4xC834REUQpG_gain[c8_sJUjlCK20kX4xC834REUQpG_i78] = 0.0;
  }

  c8_sJUjlCK20kX4xC834REUQpG_b_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_k_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t = (ptrdiff_t)12;
  dgemm(&c8_sJUjlCK20kX4xC834REUQpG_b_TRANSA,
        &c8_sJUjlCK20kX4xC834REUQpG_b_TRANSB, &c8_sJUjlCK20kX4xC834REUQpG_b_m_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b_n_t, &c8_sJUjlCK20kX4xC834REUQpG_b_k_t,
        &c8_sJUjlCK20kX4xC834REUQpG_b_alpha1, &c8_sJUjlCK20kX4xC834REUQpG_b_y[0],
        &c8_sJUjlCK20kX4xC834REUQpG_b_lda_t, &c8_sJUjlCK20kX4xC834REUQpG_b_P[0],
        &c8_sJUjlCK20kX4xC834REUQpG_b_ldb_t, &c8_sJUjlCK20kX4xC834REUQpG_b_beta1,
        &c8_sJUjlCK20kX4xC834REUQpG_gain[0], &c8_sJUjlCK20kX4xC834REUQpG_b_ldc_t);
  for (c8_sJUjlCK20kX4xC834REUQpG_i79 = 0; c8_sJUjlCK20kX4xC834REUQpG_i79 < 144;
       c8_sJUjlCK20kX4xC834REUQpG_i79++) {
    c8_sJUjlCK20kX4xC834REUQpG_b_P[c8_sJUjlCK20kX4xC834REUQpG_i79] -=
      c8_sJUjlCK20kX4xC834REUQpG_gain[c8_sJUjlCK20kX4xC834REUQpG_i79];
  }
}

static void c8_sJUjlCK20kX4xC834REUQpG_b_xgetrf
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance, real_T c8_sJUjlCK20kX4xC834REUQpG_A[144], int32_T
   c8_sJUjlCK20kX4xC834REUQpG_ipiv[12], int32_T *c8_sJUjlCK20kX4xC834REUQpG_info)
{
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_m_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_n_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_lda_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_info_t;
  ptrdiff_t c8_sJUjlCK20kX4xC834REUQpG_ipiv_t[12];
  int32_T c8_sJUjlCK20kX4xC834REUQpG_b_info;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_c_info;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_d_info;
  boolean_T c8_sJUjlCK20kX4xC834REUQpG_p;
  int32_T c8_sJUjlCK20kX4xC834REUQpG_k;
  c8_sJUjlCK20kX4xC834REUQpG_m_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_n_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_lda_t = (ptrdiff_t)12;
  c8_sJUjlCK20kX4xC834REUQpG_info_t = LAPACKE_dgetrf_work(102,
    c8_sJUjlCK20kX4xC834REUQpG_m_t, c8_sJUjlCK20kX4xC834REUQpG_n_t,
    &c8_sJUjlCK20kX4xC834REUQpG_A[0], c8_sJUjlCK20kX4xC834REUQpG_lda_t,
    &c8_sJUjlCK20kX4xC834REUQpG_ipiv_t[0]);
  c8_sJUjlCK20kX4xC834REUQpG_b_info = (int32_T)c8_sJUjlCK20kX4xC834REUQpG_info_t;
  c8_sJUjlCK20kX4xC834REUQpG_c_info = c8_sJUjlCK20kX4xC834REUQpG_b_info;
  c8_sJUjlCK20kX4xC834REUQpG_d_info = c8_sJUjlCK20kX4xC834REUQpG_c_info;
  c8_sJUjlCK20kX4xC834REUQpG_p = (c8_sJUjlCK20kX4xC834REUQpG_d_info < 0);
  if (c8_sJUjlCK20kX4xC834REUQpG_p) {
    if (c8_sJUjlCK20kX4xC834REUQpG_c_info == -1010) {
      c8_sJUjlCK20kX4xC834REUQpG_error(chartInstance);
    } else {
      c8_sJUjlCK20kX4xC834REUQpG_b_error(chartInstance,
        c8_sJUjlCK20kX4xC834REUQpG_c_info);
    }
  }

  for (c8_sJUjlCK20kX4xC834REUQpG_k = 0; c8_sJUjlCK20kX4xC834REUQpG_k < 12;
       c8_sJUjlCK20kX4xC834REUQpG_k++) {
    c8_sJUjlCK20kX4xC834REUQpG_ipiv[c8_sJUjlCK20kX4xC834REUQpG_k] = (int32_T)
      c8_sJUjlCK20kX4xC834REUQpG_ipiv_t[c8_sJUjlCK20kX4xC834REUQpG_k];
  }

  *c8_sJUjlCK20kX4xC834REUQpG_info = c8_sJUjlCK20kX4xC834REUQpG_b_info;
}

static void init_dsm_address_info
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
   *chartInstance)
{
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_fEmlrtCtx = (void *)sfrtGetEmlrtCtx
    (chartInstance->S);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_x = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew = (real_T (*)[12])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_P = (real_T (*)[144])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew = (real_T (*)[144])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_yMeas = (real_T (*)[12])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c8_sJUjlCK20kX4xC834REUQpG_R = (real_T (*)[144])
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

void sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_check_sum(mxArray
  *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(555079554U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(19973112U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(357107245U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1721079425U);
}

mxArray*
  sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray
  *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GmKuOYp8MN2yhShDIMzNDC");
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
      pr[0] = (double)(12);
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
      pr[0] = (double)(12);
      pr[1] = (double)(12);
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
      sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray
  *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_jit_fallback_info
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
  *sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray*
  sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
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
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut,
            (MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallOut,
            (MexInFcnForType)c8_sJUjlCK20kX4xC834REUQpG_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12U;
          dimVector[1]= 12U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_sf_marshallOut,
            (MexInFcnForType)c8_sJUjlCK20kX4xC834REUQpG_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sJUjlCK20kX4xC834REUQpG_d_sf_marshallOut,
          (MexInFcnForType)c8_sJUjlCK20kX4xC834REUQpG_e_sf_marshallIn);
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
    SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
      *chartInstance =
      (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)
          chartInstance->c8_sJUjlCK20kX4xC834REUQpG_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)
          &chartInstance->c8_sJUjlCK20kX4xC834REUQpG_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sJUjlCK20kX4xC834REUQpG";
}

static void
  sf_opaque_initialize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
  initialize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  enable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  disable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  sf_gateway_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SimStruct* S)
{
  return get_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void
  sf_opaque_set_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S =
      ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
       chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
      ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
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
  initSimStructsc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
    ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void
  mdlProcessParameters_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
      ((SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary
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
  ssSetChecksum0(S,(555079554U));
  ssSetChecksum1(S,(19973112U));
  ssSetChecksum2(S,(357107245U));
  ssSetChecksum3(S,(1721079425U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(SimStruct *
  S)
{
  SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct
    *chartInstance;
  chartInstance =
    (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct *)utMalloc
    (sizeof(SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary;
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
  mdl_start_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(chartInstance);
}

void c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_method_dispatcher
  (SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_sJUjlCK20kX4xC834REUQpG_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
