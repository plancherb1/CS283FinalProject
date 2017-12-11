/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLABXY.c
 *
 * Code generation for function 'meanShiftLABXY'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLABXY.h"
#include "meanShiftLABXY_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "meanShiftLABXY_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "meanShiftLABXY",                    /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 10,  /* lineNo */
  "meanShiftLABXY",                    /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 17,  /* lineNo */
  "meanShiftLABXY",                    /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 9,   /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 58,  /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 121, /* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  19,                                  /* colNo */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  32,                                  /* colNo */
  "activeIndicies",                    /* aName */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 9,     /* lineNo */
  38,                                  /* colNo */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  9,                                   /* lineNo */
  38,                                  /* colNo */
  "currX",                             /* aName */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  10,                                  /* lineNo */
  38,                                  /* colNo */
  "currX",                             /* aName */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  16,                                  /* colNo */
  "newX",                              /* aName */
  "meanShiftLABXY",                    /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLABXY.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void meanShiftLABXY(const emlrtStack *sp, const emxArray_real_T *X, const
                    emxArray_real_T *currX, const real_T bandwidth[2], const
                    emxArray_real_T *activeIndicies, emxArray_real_T *newX)
{
  int32_T j;
  int32_T i;
  int32_T b_i;
  emxArray_real_T *x;
  emxArray_real_T *b_X;
  emxArray_real_T *c_X;
  int32_T vlen;
  real_T K;
  real_T a[3];
  real_T y[3];
  real_T b_a[2];
  real_T b_y[2];
  boolean_T overflow;
  real_T c_y[5];
  real_T s;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  loop for now because vectored is too big */
  j = newX->size[0] * newX->size[1];
  newX->size[0] = 5;
  newX->size[1] = currX->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)newX, j, sizeof(real_T), &emlrtRTEI);
  i = currX->size[0] * currX->size[1];
  for (j = 0; j < i; j++) {
    newX->data[j] = currX->data[j];
  }

  b_i = 0;
  emxInit_real_T(sp, &x, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_X, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &c_X, 2, &emlrtRTEI, true);
  while (b_i <= activeIndicies->size[1] - 1) {
    j = activeIndicies->size[1];
    vlen = b_i + 1;
    if (!((vlen >= 1) && (vlen <= j))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, j, &emlrtBCI, sp);
    }

    st.site = &emlrtRSI;
    i = X->size[1];
    j = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 3;
    b_X->size[1] = i;
    emxEnsureCapacity(&st, (emxArray__common *)b_X, j, sizeof(real_T),
                      &emlrtRTEI);
    for (j = 0; j < i; j++) {
      for (vlen = 0; vlen < 3; vlen++) {
        b_X->data[vlen + b_X->size[0] * j] = X->data[vlen + X->size[0] * j];
      }
    }

    K = activeIndicies->data[b_i];
    if (K != (int32_T)muDoubleScalarFloor(K)) {
      emlrtIntegerCheckR2012b(K, &emlrtDCI, &st);
    }

    j = currX->size[1];
    vlen = (int32_T)K;
    if (!((vlen >= 1) && (vlen <= j))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, j, &b_emlrtBCI, &st);
    }

    for (j = 0; j < 3; j++) {
      a[j] = b_X->data[j] - currX->data[j + currX->size[0] * (vlen - 1)];
    }

    b_st.site = &d_emlrtRSI;
    for (i = 0; i < 3; i++) {
      y[i] = a[i] * a[i];
    }

    K = y[0];
    for (i = 0; i < 2; i++) {
      K += y[i + 1];
    }

    st.site = &b_emlrtRSI;
    i = X->size[1];
    j = c_X->size[0] * c_X->size[1];
    c_X->size[0] = 2;
    c_X->size[1] = i;
    emxEnsureCapacity(&st, (emxArray__common *)c_X, j, sizeof(real_T),
                      &emlrtRTEI);
    for (j = 0; j < i; j++) {
      for (vlen = 0; vlen < 2; vlen++) {
        c_X->data[vlen + c_X->size[0] * j] = X->data[(vlen + X->size[0] * j) + 3];
      }
    }

    j = currX->size[1];
    vlen = (int32_T)activeIndicies->data[b_i];
    if (!((vlen >= 1) && (vlen <= j))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, j, &c_emlrtBCI, &st);
    }

    for (j = 0; j < 2; j++) {
      b_a[j] = c_X->data[j] - currX->data[(j + currX->size[0] * (vlen - 1)) + 3];
    }

    b_st.site = &d_emlrtRSI;
    for (i = 0; i < 2; i++) {
      b_y[i] = b_a[i] * b_a[i];
    }

    /*  then compute the kernel of D (including /bandwidth) */
    K = 0.3989422804014327 * muDoubleScalarExp(-0.5 * (K / bandwidth[0])) *
      (0.3989422804014327 * muDoubleScalarExp(-0.5 * ((b_y[0] + b_y[1]) /
         bandwidth[1])));

    /*  then compute the vectorized mean shift */
    j = x->size[0] * x->size[1];
    x->size[0] = 5;
    x->size[1] = X->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)x, j, sizeof(real_T), &emlrtRTEI);
    i = X->size[0] * X->size[1];
    for (j = 0; j < i; j++) {
      x->data[j] = X->data[j] * K;
    }

    st.site = &c_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    if (x->size[1] == 0) {
      for (i = 0; i < 5; i++) {
        c_y[i] = 0.0;
      }
    } else {
      vlen = x->size[1];
      overflow = ((!(2 > vlen)) && (vlen > 2147483646));
      for (j = 0; j < 5; j++) {
        s = x->data[j];
        d_st.site = &g_emlrtRSI;
        if (overflow) {
          e_st.site = &h_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (i = 2; i <= vlen; i++) {
          s += x->data[j + (i - 1) * 5];
        }

        c_y[j] = s;
      }
    }

    i = newX->size[1];
    vlen = (int32_T)activeIndicies->data[b_i];
    if (!((vlen >= 1) && (vlen <= i))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, i, &d_emlrtBCI, sp);
    }

    for (j = 0; j < 5; j++) {
      newX->data[j + newX->size[0] * (vlen - 1)] = c_y[j] / K;
    }

    b_i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_X);
  emxFree_real_T(&b_X);
  emxFree_real_T(&x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meanShiftLABXY.c) */
