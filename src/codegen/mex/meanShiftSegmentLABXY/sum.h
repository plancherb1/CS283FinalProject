/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef SUM_H
#define SUM_H

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
extern real32_T b_sum(const real32_T x[2]);

#ifdef __WATCOMC__

#pragma aux b_sum value [8087];

#endif

extern void c_sum(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y[3]);
extern void d_sum(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y[2]);
extern real32_T sum(const real32_T x[3]);

#ifdef __WATCOMC__

#pragma aux sum value [8087];

#endif
#endif

/* End of code generation (sum.h) */
