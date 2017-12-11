/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cat.c
 *
 * Code generation for function 'cat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "cat.h"
#include "meanShiftSegmentLABXY_emxutil.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "meanShiftSegmentLABXY_data.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 54,  /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/cat.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 63,  /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/cat.m"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/cat.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 56,/* lineNo */
  23,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/cat.m"/* pName */
};

/* Function Definitions */
void cat(const emlrtStack *sp, const emxArray_real32_T *varargin_1, const
         emxArray_real32_T *varargin_2, emxArray_real32_T *y)
{
  uint32_T ysize_idx_0;
  uint32_T ysize_idx_1;
  int32_T j;
  int32_T exitg1;
  boolean_T p;
  int32_T iy;
  int32_T b;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ysize_idx_0 = (uint32_T)varargin_1->size[0];
  ysize_idx_1 = (uint32_T)varargin_1->size[1];
  j = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = (int32_T)ysize_idx_0;
  y->size[1] = (int32_T)ysize_idx_1;
  y->size[2] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)y, j, sizeof(real32_T), &m_emlrtRTEI);
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    st.site = &v_emlrtRSI;
    b_error(&st);
  }

  j = 0;
  do {
    exitg1 = 0;
    if (j < 2) {
      if (y->size[j] != varargin_1->size[j]) {
        p = false;
        exitg1 = 1;
      } else {
        j++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &y_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0)) {
    st.site = &v_emlrtRSI;
    b_error(&st);
  }

  j = 0;
  do {
    exitg1 = 0;
    if (j < 2) {
      if (y->size[j] != varargin_2->size[j]) {
        p = false;
        exitg1 = 1;
      } else {
        j++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &y_emlrtRTEI,
      "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }

  iy = -1;
  b = varargin_1->size[0] * varargin_1->size[1];
  st.site = &w_emlrtRSI;
  if ((!(1 > b)) && (b > 2147483646)) {
    b_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= b; j++) {
    iy++;
    y->data[iy] = varargin_1->data[j - 1];
  }

  b = varargin_2->size[0] * varargin_2->size[1];
  st.site = &w_emlrtRSI;
  if ((!(1 > b)) && (b > 2147483646)) {
    b_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= b; j++) {
    iy++;
    y->data[iy] = varargin_2->data[j - 1];
  }
}

/* End of code generation (cat.c) */
