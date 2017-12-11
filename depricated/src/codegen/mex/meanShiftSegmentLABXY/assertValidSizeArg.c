/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "assertValidSizeArg.h"

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 53,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 44,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

/* Function Definitions */
void assertValidSizeArg(const emlrtStack *sp, real32_T varargin_1)
{
  boolean_T b0;
  real_T b_varargin_1;
  if ((!(varargin_1 != varargin_1)) && (!(varargin_1 >= 2.14748365E+9F))) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(sp, &u_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1 <= 0.0F) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }

  if (!(2.147483647E+9 >= b_varargin_1)) {
    emlrtErrorWithMessageIdR2012b(sp, &t_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

void b_assertValidSizeArg(const emlrtStack *sp, const real_T varargin_1[2])
{
  int32_T k;
  int32_T exitg1;
  boolean_T p;
  real_T n;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (varargin_1[k] != varargin_1[k]) {
        p = false;
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (p) {
    k = 0;
    do {
      exitg1 = 0;
      if (k < 2) {
        if (-2.147483648E+9 > varargin_1[k]) {
          p = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (p) {
      p = true;
    } else {
      p = false;
    }
  } else {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &x_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  n = 1.0;
  for (k = 0; k < 2; k++) {
    if (varargin_1[k] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[k];
    }
  }

  if (!(2.147483647E+9 >= n)) {
    emlrtErrorWithMessageIdR2012b(sp, &t_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

/* End of code generation (assertValidSizeArg.c) */
