/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "xgetrf.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 28, "xgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"
};

static emlrtRSInfo m_emlrtRSI = { 36, "xzgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"
};

static emlrtRSInfo n_emlrtRSI = { 50, "xzgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"
};

static emlrtRSInfo o_emlrtRSI = { 58, "xzgetrf",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"
};

static emlrtRSInfo p_emlrtRSI = { 23, "ixamax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"
};

static emlrtRSInfo q_emlrtRSI = { 24, "ixamax",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"
};

static emlrtRSInfo r_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo s_emlrtRSI = { 45, "xgeru",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"
};

static emlrtRSInfo t_emlrtRSI = { 45, "xger",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"
};

static emlrtRSInfo u_emlrtRSI = { 15, "xger",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"
};

static emlrtRSInfo v_emlrtRSI = { 41, "xgerx",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"
};

static emlrtRSInfo w_emlrtRSI = { 54, "xgerx",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"
};

/* Function Definitions */
void xgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6], int32_T *info)
{
  int32_T iy;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T jy;
  real_T s;
  int32_T b;
  int32_T b_j;
  boolean_T b_iy;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  for (iy = 0; iy < 6; iy++) {
    ipiv[iy] = 1 + iy;
  }

  *info = 0;
  for (j = 0; j < 5; j++) {
    c = j * 7;
    b_st.site = &m_emlrtRSI;
    c_st.site = &p_emlrtRSI;
    iy = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    d_st.site = &q_emlrtRSI;
    for (jy = 2; jy <= 6 - j; jy++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (j + iy) + 1;
        ix = j;
        iy += j;
        for (jy = 0; jy < 6; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      b = (c - j) + 6;
      b_st.site = &n_emlrtRSI;
      for (iy = c + 1; iy + 1 <= b; iy++) {
        A[iy] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    b_st.site = &o_emlrtRSI;
    c_st.site = &s_emlrtRSI;
    d_st.site = &t_emlrtRSI;
    e_st.site = &u_emlrtRSI;
    iy = c;
    jy = c + 6;
    f_st.site = &v_emlrtRSI;
    for (b_j = 1; b_j <= 5 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (iy - j) + 12;
        f_st.site = &w_emlrtRSI;
        if (iy + 8 > b) {
          b_iy = false;
        } else {
          b_iy = (b > 2147483646);
        }

        if (b_iy) {
          g_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&g_st, true);
        }

        for (ijA = iy + 7; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 6;
      iy += 6;
    }
  }

  if ((*info == 0) && (!(A[35] != 0.0))) {
    *info = 6;
  }
}

/* End of code generation (xgetrf.c) */
