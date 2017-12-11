/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "meanShiftSegmentLABXY_data.h"

/* Variable Definitions */
static emlrtRSInfo bb_emlrtRSI = { 121,/* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

/* Function Definitions */
real32_T b_sum(const real32_T x[2])
{
  return x[0] + x[1];
}

void c_sum(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y[3])
{
  int32_T vlen;
  boolean_T overflow;
  int32_T j;
  real32_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ab_emlrtRSI;
  if (x->size[1] == 0) {
    for (vlen = 0; vlen < 3; vlen++) {
      y[vlen] = 0.0F;
    }
  } else {
    vlen = x->size[1];
    overflow = ((!(2 > vlen)) && (vlen > 2147483646));
    for (j = 0; j < 3; j++) {
      s = x->data[j];
      c_st.site = &bb_emlrtRSI;
      if (overflow) {
        d_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 2; k <= vlen; k++) {
        s += x->data[j + (k - 1) * 3];
      }

      y[j] = s;
    }
  }
}

void d_sum(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y[2])
{
  int32_T vlen;
  boolean_T overflow;
  int32_T j;
  real32_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ab_emlrtRSI;
  if (x->size[1] == 0) {
    for (vlen = 0; vlen < 2; vlen++) {
      y[vlen] = 0.0F;
    }
  } else {
    vlen = x->size[1];
    overflow = ((!(2 > vlen)) && (vlen > 2147483646));
    for (j = 0; j < 2; j++) {
      s = x->data[j];
      c_st.site = &bb_emlrtRSI;
      if (overflow) {
        d_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 2; k <= vlen; k++) {
        s += x->data[j + ((k - 1) << 1)];
      }

      y[j] = s;
    }
  }
}

real32_T sum(const real32_T x[3])
{
  real32_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 2; k++) {
    y += x[k + 1];
  }

  return y;
}

/* End of code generation (sum.c) */
