/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLABXY.h
 *
 * Code generation for function 'meanShiftLABXY'
 *
 */

#ifndef MEANSHIFTLABXY_H
#define MEANSHIFTLABXY_H

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
#include "meanShiftLABXY_types.h"

/* Function Declarations */
extern void meanShiftLABXY(const emlrtStack *sp, const emxArray_real_T *X, const
  emxArray_real_T *currX, const real_T bandwidth[2], const emxArray_real_T
  *activeIndicies, emxArray_real_T *newX);

#endif

/* End of code generation (meanShiftLABXY.h) */
