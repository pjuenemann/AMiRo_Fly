/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: iecjgdjeaimokfcj_mrdivide.c
 *
 * Code generated for Simulink model 'PoseEstimationController'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Jun 12 11:18:41 2017
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "iecjgdjeaimokfcj_mrdivide.h"

/* Function for MATLAB Function: '<S11>/Correct' */
void iecjgdjeaimokfcj_mrdivide(real_T A[60], const real_T B_0[25])
{
  int32_T jp;
  real_T temp;
  real_T b_A[25];
  int8_T ipiv[5];
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T b_jAcol;
  int32_T b_kBcol;
  memcpy(&b_A[0], &B_0[0], 25U * sizeof(real_T));
  for (j = 0; j < 5; j++) {
    ipiv[j] = (int8_T)(1 + j);
  }

  for (j = 0; j < 4; j++) {
    jp = j * 6;
    b_jAcol = 0;
    ix = jp;
    temp = fabs(b_A[jp]);
    for (b_kBcol = 2; b_kBcol <= 5 - j; b_kBcol++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        b_jAcol = b_kBcol - 1;
        temp = s;
      }
    }

    if (b_A[jp + b_jAcol] != 0.0) {
      if (b_jAcol != 0) {
        ipiv[j] = (int8_T)((j + b_jAcol) + 1);
        ix = j;
        b_jAcol += j;
        for (b_kBcol = 0; b_kBcol < 5; b_kBcol++) {
          temp = b_A[ix];
          b_A[ix] = b_A[b_jAcol];
          b_A[b_jAcol] = temp;
          ix += 5;
          b_jAcol += 5;
        }
      }

      b_jAcol = (jp - j) + 5;
      for (ix = jp + 1; ix + 1 <= b_jAcol; ix++) {
        b_A[ix] /= b_A[jp];
      }
    }

    b_jAcol = jp;
    ix = jp + 5;
    for (b_kBcol = 1; b_kBcol <= 4 - j; b_kBcol++) {
      temp = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = jp + 1;
        d = (b_jAcol - j) + 10;
        for (ijA = 6 + b_jAcol; ijA + 1 <= d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -temp;
          c_ix++;
        }
      }

      ix += 5;
      b_jAcol += 5;
    }
  }

  for (j = 0; j < 5; j++) {
    jp = 12 * j;
    b_jAcol = 5 * j;
    for (ix = 1; ix <= j; ix++) {
      b_kBcol = (ix - 1) * 12;
      if (b_A[(ix + b_jAcol) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 12; c_ix++) {
          A[c_ix + jp] -= b_A[(ix + b_jAcol) - 1] * A[c_ix + b_kBcol];
        }
      }
    }

    temp = 1.0 / b_A[j + b_jAcol];
    for (b_jAcol = 0; b_jAcol < 12; b_jAcol++) {
      A[b_jAcol + jp] *= temp;
    }
  }

  for (j = 4; j >= 0; j += -1) {
    jp = 12 * j;
    b_jAcol = 5 * j - 1;
    for (ix = j + 2; ix < 6; ix++) {
      b_kBcol = (ix - 1) * 12;
      if (b_A[ix + b_jAcol] != 0.0) {
        for (c_ix = 0; c_ix < 12; c_ix++) {
          A[c_ix + jp] -= b_A[ix + b_jAcol] * A[c_ix + b_kBcol];
        }
      }
    }
  }

  for (j = 3; j >= 0; j += -1) {
    if (j + 1 != ipiv[j]) {
      jp = ipiv[j] - 1;
      for (b_jAcol = 0; b_jAcol < 12; b_jAcol++) {
        temp = A[12 * j + b_jAcol];
        A[b_jAcol + 12 * j] = A[12 * jp + b_jAcol];
        A[b_jAcol + 12 * jp] = temp;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
