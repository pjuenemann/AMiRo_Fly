/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kalmanfilter.h
 *
 * Code generation for function 'kalmanfilter'
 *
 */

#ifndef __KALMANFILTER_H__
#define __KALMANFILTER_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "kalmanfilter_types.h"

/* Function Declarations */
extern void kalmanfilter(const emlrtStack *sp, const real_T z[6], const real_T
  u[4], real_T y[6]);
extern void kalmanfilter_init(void);
extern void p_est_not_empty_init(void);
extern void x_est_not_empty_init(void);

#endif

/* End of code generation (kalmanfilter.h) */
