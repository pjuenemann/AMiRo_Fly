/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kalmanfilter.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2017 15:10:16
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "mldivide.h"

/* Variable Definitions */
static double x_est[8];
static double p_est[64];

/* Function Definitions */

/*
 * UNTITLED3 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double z[6]
 *                const double u[4]
 *                double y[6]
 * Return Type  : void
 */
void kalmanfilter(const double z[6], const double u[4], double y[6])
{
  signed char Q[64];
  int k;
  double dv0[32];
  static const signed char iv0[4] = { 0, 0, 1, 0 };

  static const signed char iv1[4] = { 0, 0, 0, 1 };

  double a[8];
  double dv1[8];
  double b_a[64];
  double x_prd[8];
  double p_prd[64];
  int i0;
  static const double c_a[64] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0 };

  int i1;
  double d0;
  static const double b[64] = { 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  double d_a[36];
  double e_a[48];
  double dv2[48];
  static const signed char f_a[48] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char b_b[48] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0 };

  static const short R[36] = { 1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0,
    1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 1000
  };

  double b_z[6];
  double klm_gain[48];
  memset(&Q[0], 0, sizeof(signed char) << 6);
  for (k = 0; k < 8; k++) {
    Q[k + (k << 3)] = 1;
  }

  /*  Initial state conditions */
  /*  Predicted state and covariance */
  dv0[4] = cos(x_est[3]);
  dv0[12] = -sin(x_est[3]);
  dv0[20] = 0.0;
  dv0[28] = 0.0;
  dv0[5] = sin(x_est[3]);
  dv0[13] = cos(x_est[3]);
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
      a[k] += c_a[k + (i0 << 3)] * x_est[i0];
    }

    dv1[k] = 0.0;
    for (i0 = 0; i0 < 4; i0++) {
      dv1[k] += dv0[k + (i0 << 3)] * u[i0];
    }

    x_prd[k] = a[k] + dv1[k];
    for (i0 = 0; i0 < 8; i0++) {
      b_a[k + (i0 << 3)] = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        b_a[k + (i0 << 3)] += c_a[k + (i1 << 3)] * p_est[i1 + (i0 << 3)];
      }
    }

    for (i0 = 0; i0 < 8; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        d0 += b_a[k + (i1 << 3)] * b[i1 + (i0 << 3)];
      }

      p_prd[k + (i0 << 3)] = d0 + (double)Q[k + (i0 << 3)];
    }
  }

  /*  Estimation */
  for (k = 0; k < 6; k++) {
    for (i0 = 0; i0 < 8; i0++) {
      dv2[k + 6 * i0] = 0.0;
      e_a[k + 6 * i0] = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        dv2[k + 6 * i0] += (double)f_a[k + 6 * i1] * p_prd[i0 + (i1 << 3)];
        e_a[k + 6 * i0] += (double)f_a[k + 6 * i1] * p_prd[i0 + (i1 << 3)];
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        d0 += e_a[k + 6 * i1] * (double)b_b[i1 + (i0 << 3)];
      }

      d_a[k + 6 * i0] = d0 + (double)R[k + 6 * i0];
    }
  }

  mldivide(d_a, dv2);

  /*  Estimated state and covariance */
  for (k = 0; k < 6; k++) {
    d0 = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
      klm_gain[i0 + (k << 3)] = dv2[k + 6 * i0];
      d0 += (double)f_a[k + 6 * i0] * x_prd[i0];
    }

    b_z[k] = z[k] - d0;
  }

  for (k = 0; k < 8; k++) {
    d0 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      d0 += klm_gain[k + (i0 << 3)] * b_z[i0];
    }

    x_est[k] = x_prd[k] + d0;
    for (i0 = 0; i0 < 8; i0++) {
      b_a[k + (i0 << 3)] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        b_a[k + (i0 << 3)] += klm_gain[k + (i1 << 3)] * (double)f_a[i1 + 6 * i0];
      }
    }

    for (i0 = 0; i0 < 8; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 8; i1++) {
        d0 += b_a[k + (i1 << 3)] * p_prd[i1 + (i0 << 3)];
      }

      p_est[k + (i0 << 3)] = p_prd[k + (i0 << 3)] - d0;
    }
  }

  /*  Compute the estimated measurements */
  for (k = 0; k < 6; k++) {
    y[k] = 0.0;
    for (i0 = 0; i0 < 8; i0++) {
      y[k] += (double)f_a[k + 6 * i0] * x_est[i0];
    }
  }

  /*  of the function */
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void kalmanfilter_init(void)
{
  memset(&x_est[0], 0, sizeof(double) << 3);

  /*  x_est=[x,y,z,chi,x_p,y_p,z_p,chi_p]' */
  memset(&p_est[0], 0, sizeof(double) << 6);
}

/*
 * File trailer for kalmanfilter.c
 *
 * [EOF]
 */
