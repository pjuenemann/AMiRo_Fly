/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kalmanfilter_initialize.c
 *
 * Code generation for function 'kalmanfilter_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "kalmanfilter_initialize.h"
#include "_coder_kalmanfilter_mex.h"
#include "kalmanfilter_data.h"

/* Function Declarations */
static void kalmanfilter_once(void);

/* Function Definitions */
static void kalmanfilter_once(void)
{
  p_est_not_empty_init();
  x_est_not_empty_init();
  kalmanfilter_init();
}

void kalmanfilter_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    kalmanfilter_once();
  }
}

/* End of code generation (kalmanfilter_initialize.c) */
