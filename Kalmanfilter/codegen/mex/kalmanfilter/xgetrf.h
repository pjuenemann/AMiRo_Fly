/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.h
 *
 * Code generation for function 'xgetrf'
 *
 */

#ifndef __XGETRF_H__
#define __XGETRF_H__

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
extern void xgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6], int32_T *
                   info);

#endif

/* End of code generation (xgetrf.h) */
