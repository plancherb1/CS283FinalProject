/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLAB.h
 *
 * Code generation for function 'meanShiftLAB'
 *
 */

#ifndef MEANSHIFTLAB_H
#define MEANSHIFTLAB_H

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
#include "meanShiftLAB_types.h"

/* Function Declarations */
extern void meanShiftLAB(const emlrtStack *sp, const emxArray_real_T *X, const
  emxArray_real_T *currX, real_T bandwidth, const emxArray_real_T
  *activeIndicies, emxArray_real_T *newX);

#endif

/* End of code generation (meanShiftLAB.h) */
