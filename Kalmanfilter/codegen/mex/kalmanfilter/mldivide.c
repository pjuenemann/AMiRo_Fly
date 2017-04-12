/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "mldivide.h"
#include "warning.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = { 1, "mldivide",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRSInfo g_emlrtRSI = { 42, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo h_emlrtRSI = { 92, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo i_emlrtRSI = { 90, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo j_emlrtRSI = { 128, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo k_emlrtRSI = { 130, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo x_emlrtRSI = { 76, "lusolve",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[36], real_T B[48])
{
  real_T b_A[36];
  int32_T info;
  int32_T ipiv[6];
  int32_T jBcol;
  int32_T k;
  real_T temp;
  int32_T kAcol;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &g_emlrtRSI;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  c_st.site = &i_emlrtRSI;
  xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &h_emlrtRSI;
    d_st.site = &x_emlrtRSI;
    warning(&d_st);
  }

  for (info = 0; info < 5; info++) {
    if (ipiv[info] != info + 1) {
      jBcol = ipiv[info] - 1;
      for (k = 0; k < 8; k++) {
        temp = B[info + 6 * k];
        B[info + 6 * k] = B[jBcol + 6 * k];
        B[jBcol + 6 * k] = temp;
      }
    }
  }

  c_st.site = &j_emlrtRSI;
  for (info = 0; info < 8; info++) {
    jBcol = 6 * info;
    for (k = 0; k < 6; k++) {
      kAcol = 6 * k;
      if (B[k + jBcol] != 0.0) {
        for (i = k + 1; i + 1 < 7; i++) {
          B[i + jBcol] -= B[k + jBcol] * b_A[i + kAcol];
        }
      }
    }
  }

  c_st.site = &k_emlrtRSI;
  for (info = 0; info < 8; info++) {
    jBcol = 6 * info;
    for (k = 5; k >= 0; k += -1) {
      kAcol = 6 * k;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= b_A[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * b_A[i + kAcol];
        }
      }
    }
  }
}

/* End of code generation (mldivide.c) */
