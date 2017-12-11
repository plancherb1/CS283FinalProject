/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "power.h"
#include "meanShiftSegmentLABXY_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "meanShiftSegmentLABXY_data.h"

/* Function Definitions */
void b_power(const real32_T a[2], real32_T y[2])
{
  int32_T k;
  for (k = 0; k < 2; k++) {
    y[k] = a[k] * a[k];
  }
}

void c_power(const emlrtStack *sp, const emxArray_real32_T *a, emxArray_real32_T
             *y)
{
  int32_T n;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &db_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  n = y->size[0] * y->size[1];
  y->size[0] = 3;
  y->size[1] = a->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)y, n, sizeof(real32_T),
                    &b_emlrtRTEI);
  if (!dimagree(y, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &r_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  n = 3 * a->size[1];
  c_st.site = &fb_emlrtRSI;
  if ((!(1 > n)) && (n > 2147483646)) {
    d_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

void power(const real32_T a[3], real32_T y[3])
{
  int32_T k;
  for (k = 0; k < 3; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
