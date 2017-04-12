/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kalmanfilter.c
 *
 * Code generation for function 'kalmanfilter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "mldivide.h"

/* Variable Definitions */
static real_T x_est[8];
static real_T p_est[64];
static emlrtRSInfo b_emlrtRSI = { 50, "kalmanfilter",
  "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\kalmanfilter.m" };

/* Function Definitions */
void kalmanfilter(const emlrtStack *sp, const real_T z[6], const real_T u[4],
                  real_T y[6])
{
  int8_T Q[64];
  int32_T k;
  real_T dv0[32];
  static const int8_T iv0[4] = { 0, 0, 1, 0 };

  static const int8_T iv1[4] = { 0, 0, 0, 1 };

  real_T a[8];
  real_T dv1[8];
  real_T x_prd[8];
  int32_T i0;
  static const real_T b_a[64] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0 };

  real_T alpha1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  real_T c_a[64];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T p_prd[64];
  static const real_T b[64] = { 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  real_T d_a[36];
  real_T e_a[48];
  real_T dv2[48];
  int32_T i1;
  static const int8_T f_a[48] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 };

  static const int8_T b_b[48] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0 };

  static const int16_T R[36] = { 1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0,
    1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 1000
  };

  real_T b_z[6];
  real_T klm_gain[48];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  memset(&Q[0], 0, sizeof(int8_T) << 6);
  for (k = 0; k < 8; k++) {
    Q[k + (k << 3)] = 1;
  }

  /*  Initial state conditions */
  /*  Predicted state and covariance */
  dv0[4] = muDoubleScalarCos(x_est[3]);
  dv0[12] = -muDoubleScalarSin(x_est[3]);
  dv0[20] = 0.0;
  dv0[28] = 0.0;
  dv0[5] = muDoubleScalarSin(x_est[3]);
  dv0[13] = muDoubleScalarCos(x_est[3]);
  dv0[21] = 0.0;
  dv0[29] = 0.0;
  for (k = 0; k < 4; k++) {
    dv0[k << 3] = 0.0;
    dv0[1 + (k << 3)] = 0.0;
    dv0[2 + (k << 3)] = 0.0;
    dv0[3 + (k << 3)] = 0.0;
    dv0[6 + (k << 3)] = iv0[k];
    dv0[7 + (k << 3)] = iv1[k];
  }

  for (k = 0; k < 8; k++) {
    a[k] = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
      a[k] += b_a[k + (i0 << 3)] * x_est[i0];
    }

    dv1[k] = 0.0;
    for (i0 = 0; i0 < 4; i0++) {
      dv1[k] += dv0[k + (i0 << 3)] * u[i0];
    }

    x_prd[k] = a[k] + dv1[k];
  }

  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB = 'N';
  TRANSA = 'N';
  memset(&c_a[0], 0, sizeof(real_T) << 6);
  m_t = (ptrdiff_t)8;
  n_t = (ptrdiff_t)8;
  k_t = (ptrdiff_t)8;
  lda_t = (ptrdiff_t)8;
  ldb_t = (ptrdiff_t)8;
  ldc_t = (ptrdiff_t)8;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a[0], &lda_t, &p_est[0],
        &ldb_t, &beta1, &c_a[0], &ldc_t);
  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB = 'N';
  TRANSA = 'N';
  memset(&p_prd[0], 0, sizeof(real_T) << 6);
  m_t = (ptrdiff_t)8;
  n_t = (ptrdiff_t)8;
  k_t = (ptrdiff_t)8;
  lda_t = (ptrdiff_t)8;
  ldb_t = (ptrdiff_t)8;
  ldc_t = (ptrdiff_t)8;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &c_a[0], &lda_t, &b[0],
        &ldb_t, &beta1, &p_prd[0], &ldc_t);
  for (k = 0; k < 64; k++) {
    p_prd[k] += (real_T)Q[k];
  }

  /*  Estimation */
  for (k = 0; k < 6; k++) {
    for (i0 = 0; i0 < 8; i0++) {
      dv2[k + 6 * i0] = 0.0;
      e_a[k + 6 * i0] = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        dv2[k + 6 * i0] += (real_T)f_a[k + 6 * i1] * p_prd[i0 + (i1 << 3)];
        e_a[k + 6 * i0] += (real_T)f_a[k + 6 * i1] * p_prd[i0 + (i1 << 3)];
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      alpha1 = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        alpha1 += e_a[k + 6 * i1] * (real_T)b_b[i1 + (i0 << 3)];
      }

      d_a[k + 6 * i0] = alpha1 + (real_T)R[k + 6 * i0];
    }
  }

  st.site = &b_emlrtRSI;
  mldivide(&st, d_a, dv2);

  /*  Estimated state and covariance */
  for (k = 0; k < 6; k++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
      klm_gain[i0 + (k << 3)] = dv2[k + 6 * i0];
      alpha1 += (real_T)f_a[k + 6 * i0] * x_prd[i0];
    }

    b_z[k] = z[k] - alpha1;
  }

  for (k = 0; k < 8; k++) {
    alpha1 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      alpha1 += klm_gain[k + (i0 << 3)] * b_z[i0];
    }

    x_est[k] = x_prd[k] + alpha1;
    for (i0 = 0; i0 < 8; i0++) {
      c_a[k + (i0 << 3)] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        c_a[k + (i0 << 3)] += klm_gain[k + (i1 << 3)] * (real_T)f_a[i1 + 6 * i0];
      }
    }
  }

  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB = 'N';
  TRANSA = 'N';
  memset(&p_est[0], 0, sizeof(real_T) << 6);
  m_t = (ptrdiff_t)8;
  n_t = (ptrdiff_t)8;
  k_t = (ptrdiff_t)8;
  lda_t = (ptrdiff_t)8;
  ldb_t = (ptrdiff_t)8;
  ldc_t = (ptrdiff_t)8;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &c_a[0], &lda_t, &p_prd[0],
        &ldb_t, &beta1, &p_est[0], &ldc_t);
  for (k = 0; k < 64; k++) {
    p_est[k] = p_prd[k] - p_est[k];
  }

  /*  Compute the estimated measurements */
  for (k = 0; k < 6; k++) {
    y[k] = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
open_system('sfundemos');
      y[k] += (real_T)f_a[k + 6 * i0] * x_est[i0];
    }
  }

  /*  of the function */
}

void kalmanfilter_init(void)
{
  memset(&x_est[0], 0, sizeof(real_T) << 3);

  /*  x_est=[x,y,z,chi,x_p,y_p,z_p,chi_p]' */
  memset(&p_est[0], 0, sizeof(real_T) << 6);
}

void p_est_not_empty_init(void)
{
}

void x_est_not_empty_init(void)
{
}

/* End of code generation (kalmanfilter.c) */
