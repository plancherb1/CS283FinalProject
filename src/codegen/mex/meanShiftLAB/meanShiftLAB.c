/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLAB.c
 *
 * Code generation for function 'meanShiftLAB'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLAB.h"
#include "meanShiftLAB_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "meanShiftLAB_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8,     /* lineNo */
  "meanShiftLAB",                      /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 14,  /* lineNo */
  "meanShiftLAB",                      /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 9,   /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 58,  /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 121, /* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  19,                                  /* colNo */
  "meanShiftLAB",                      /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  32,                                  /* colNo */
  "activeIndicies",                    /* aName */
  "meanShiftLAB",                      /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 8,     /* lineNo */
  28,                                  /* colNo */
  "meanShiftLAB",                      /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  28,                                  /* colNo */
  "currX",                             /* aName */
  "meanShiftLAB",                      /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  16,                                  /* colNo */
  "newX",                              /* aName */
  "meanShiftLAB",                      /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftLAB.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void meanShiftLAB(const emlrtStack *sp, const emxArray_real_T *X, const
                  emxArray_real_T *currX, real_T bandwidth, const
                  emxArray_real_T *activeIndicies, emxArray_real_T *newX)
{
  int32_T j;
  int32_T i;
  int32_T b_i;
  emxArray_real_T *x;
  real_T K;
  int32_T vlen;
  real_T a[3];
  real_T y[3];
  boolean_T overflow;
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
  newX->size[0] = 3;
  newX->size[1] = currX->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)newX, j, sizeof(real_T), &emlrtRTEI);
  i = currX->size[0] * currX->size[1];
  for (j = 0; j < i; j++) {
    newX->data[j] = currX->data[j];
  }

  b_i = 0;
  emxInit_real_T(sp, &x, 2, &emlrtRTEI, true);
  while (b_i <= activeIndicies->size[1] - 1) {
    j = activeIndicies->size[1];
    i = b_i + 1;
    if (!((i >= 1) && (i <= j))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, j, &emlrtBCI, sp);
    }

    st.site = &emlrtRSI;
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
      a[j] = X->data[j] - currX->data[j + currX->size[0] * (vlen - 1)];
    }

    b_st.site = &c_emlrtRSI;
    for (i = 0; i < 3; i++) {
      y[i] = a[i] * a[i];
    }

    K = y[0];
    for (i = 0; i < 2; i++) {
      K += y[i + 1];
    }

    /*  then compute the kernel of D (including /bandwidth) */
    K = 0.3989422804014327 * muDoubleScalarExp(-0.5 * (K / bandwidth));

    /*  then compute the vectorized mean shift */
    j = x->size[0] * x->size[1];
    x->size[0] = 3;
    x->size[1] = X->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)x, j, sizeof(real_T), &emlrtRTEI);
    i = X->size[0] * X->size[1];
    for (j = 0; j < i; j++) {
      x->data[j] = X->data[j] * K;
    }

    st.site = &b_emlrtRSI;
    b_st.site = &d_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    if (x->size[1] == 0) {
      for (i = 0; i < 3; i++) {
        y[i] = 0.0;
      }
    } else {
      vlen = x->size[1];
      overflow = ((!(2 > vlen)) && (vlen > 2147483646));
      for (j = 0; j < 3; j++) {
        s = x->data[j];
        d_st.site = &f_emlrtRSI;
        if (overflow) {
          e_st.site = &g_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (i = 2; i <= vlen; i++) {
          s += x->data[j + (i - 1) * 3];
        }

        y[j] = s;
      }
    }

    i = newX->size[1];
    vlen = (int32_T)activeIndicies->data[b_i];
    if (!((vlen >= 1) && (vlen <= i))) {
      emlrtDynamicBoundsCheckR2012b(vlen, 1, i, &c_emlrtBCI, sp);
    }

    for (j = 0; j < 3; j++) {
      newX->data[j + newX->size[0] * (vlen - 1)] = y[j] / K;
    }

    b_i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meanShiftLAB.c) */
