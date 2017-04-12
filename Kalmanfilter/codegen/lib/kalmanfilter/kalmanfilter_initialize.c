/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kalmanfilter_initialize.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2017 15:10:16
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "kalmanfilter_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void kalmanfilter_initialize(void)
{
  rt_InitInfAndNaN(8U);
  kalmanfilter_init();
}

/*
 * File trailer for kalmanfilter_initialize.c
 *
 * [EOF]
 */
