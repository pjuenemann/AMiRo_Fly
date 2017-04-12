/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kalmanfilter.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 16-Feb-2017 15:10:16
 */

#ifndef __KALMANFILTER_H__
#define __KALMANFILTER_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "kalmanfilter_types.h"

/* Function Declarations */
extern void kalmanfilter(const double z[6], const double u[4], double y[6]);
extern void kalmanfilter_init(void);

#endif

/*
 * File trailer for kalmanfilter.h
 *
 * [EOF]
 */
