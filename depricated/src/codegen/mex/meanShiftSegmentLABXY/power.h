/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef POWER_H
#define POWER_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "meanShiftSegmentLABXY_types.h"

/* Function Declarations */
extern void b_power(const real32_T a[2], real32_T y[2]);
extern void c_power(const emlrtStack *sp, const emxArray_real32_T *a,
                    emxArray_real32_T *y);
extern void power(const real32_T a[3], real32_T y[3]);

#endif

/* End of code generation (power.h) */
