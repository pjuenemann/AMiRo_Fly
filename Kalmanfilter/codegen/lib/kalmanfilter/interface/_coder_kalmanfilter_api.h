/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_kalmanfilter_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2017 15:10:16
 */

#ifndef ___CODER_KALMANFILTER_API_H__
#define ___CODER_KALMANFILTER_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_kalmanfilter_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void kalmanfilter(real_T z[6], real_T u[4], real_T y[6]);
extern void kalmanfilter_api(const mxArray *prhs[2], const mxArray *plhs[1]);
extern void kalmanfilter_atexit(void);
extern void kalmanfilter_initialize(void);
extern void kalmanfilter_terminate(void);
extern void kalmanfilter_xil_terminate(void);

#endif

/*
 * File trailer for _coder_kalmanfilter_api.h
 *
 * [EOF]
 */
