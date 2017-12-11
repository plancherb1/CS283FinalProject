/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftSegmentLABXY.h
 *
 * Code generation for function 'meanShiftSegmentLABXY'
 *
 */

#ifndef MEANSHIFTSEGMENTLABXY_H
#define MEANSHIFTSEGMENTLABXY_H

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
extern void meanShiftSegmentLABXY(const emlrtStack *sp, const emxArray_real32_T *
  pts, const real32_T bandwidth[2], const struct0_T *options, emxArray_real32_T *
  pts_out);

#endif

/* End of code generation (meanShiftSegmentLABXY.h) */
