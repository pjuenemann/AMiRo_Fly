/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mldivide.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2017 15:10:16
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "mldivide.h"

/* Function Definitions */

/*
 * Arguments    : const double A[36]
 *                double B[48]
 * Return Type  : void
 */
void mldivide(const double A[36], double B[48])
{
  double b_A[36];
  signed char ipiv[6];
  int i2;
  int j;
  int c;
  int jBcol;
  int ix;
  double smax;
  int k;
  double s;
  int i;
  int kAcol;
  memcpy(&b_A[0], &A[0], 36U * sizeof(double));
  for (i2 = 0; i2 < 6; i2++) {
    ipiv[i2] = (signed char)(1 + i2);
  }

  for (j = 0; j < 5; j++) {
    c = j * 7;
    jBcol = 0;
    ix = c;
    smax = fabs(b_A[c]);
    for (k = 2; k <= 6 - j; k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        jBcol = k - 1;
        smax = s;
      }
    }

    if (b_A[c + jBcol] != 0.0) {
      if (jBcol != 0) {
        ipiv[j] = (signed char)((j + jBcol) + 1);
        ix = j;
        jBcol += j;
        for (k = 0; k < 6; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[jBcol];
          b_A[jBcol] = smax;
          ix += 6;
          jBcol += 6;
        }
      }

      i2 = (c - j) + 6;
      for (i = c + 1; i + 1 <= i2; i++) {
        b_A[i] /= b_A[c];
      }
    }

    jBcol = c;
    kAcol = c + 6;
    for (i = 1; i <= 5 - j; i++) {
      smax = b_A[kAcol];
      if (b_A[kAcol] != 0.0) {
        ix = c + 1;
        i2 = (jBcol - j) + 12;
        for (k = 7 + jBcol; k + 1 <= i2; k++) {
          b_A[k] += b_A[ix] * -smax;
          ix++;
        }
      }

      kAcol += 6;
      jBcol += 6;
    }

    if (ipiv[j] != j + 1) {
      jBcol = ipiv[j] - 1;
      for (kAcol = 0; kAcol < 8; kAcol++) {
        smax = B[j + 6 * kAcol];
        B[j + 6 * kAcol] = B[jBcol + 6 * kAcol];
        B[jBcol + 6 * kAcol] = smax;
      }
    }
  }

  for (j = 0; j < 8; j++) {
    jBcol = 6 * j;
    for (k = 0; k < 6; k++) {
      kAcol = 6 * k;
      if (B[k + jBcol] != 0.0) {
        for (i = k + 1; i + 1 < 7; i++) {
          B[i + jBcol] -= B[k + jBcol] * b_A[i + kAcol];
        }
      }
    }
  }

  for (j = 0; j < 8; j++) {
    jBcol = 6 * j;
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

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
