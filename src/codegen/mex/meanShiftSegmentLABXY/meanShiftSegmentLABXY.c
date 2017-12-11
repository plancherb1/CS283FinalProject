/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftSegmentLABXY.c
 *
 * Code generation for function 'meanShiftSegmentLABXY'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "power.h"
#include "meanShiftSegmentLABXY_emxutil.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "assertValidSizeArg.h"
#include "scalexpAlloc.h"
#include "cat.h"
#include "meshgrid.h"
#include "meanShiftSegmentLABXY_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 14,    /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 18,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 19,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 33,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 34,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 41,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 42,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 47,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 52,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 65,  /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 33,  /* lineNo */
  "reshape",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/reshape.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 54,  /* lineNo */
  "reshape",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/reshape.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 101, /* lineNo */
  "reshape",                           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/reshape.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 6,  /* lineNo */
  "ReplaceOperators.cpp:118",          /* fcnName */
  "src/ReplaceOperators.cpp:118"       /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 107,/* lineNo */
  "combine_vector_elements",           /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 12, /* lineNo */
  "toLogicalCheck",                    /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 53,    /* lineNo */
  23,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 53,  /* lineNo */
  59,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 53,  /* lineNo */
  18,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtMCInfo d_emlrtMCI = { 53,  /* lineNo */
  13,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  22,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 14,/* lineNo */
  5,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 18,/* lineNo */
  6,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 18,/* lineNo */
  9,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 29,/* lineNo */
  9,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 30,/* lineNo */
  9,                                   /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 25,/* lineNo */
  11,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 31,/* lineNo */
  19,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  42,                                  /* colNo */
  "currX",                             /* aName */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  42,                                  /* colNo */
  "currS",                             /* aName */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = { 59,/* lineNo */
  15,                                  /* colNo */
  "reshape",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/reshape.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "dts_binary_op",                     /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/coder/float2fixed/dtslib/dts_binary_op.p"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 108,/* lineNo */
  9,                                   /* colNo */
  "reshape",                           /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/reshape.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  24,                                  /* colNo */
  "newX",                              /* aName */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  24,                                  /* colNo */
  "newS",                              /* aName */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 23,    /* lineNo */
  29,                                  /* colNo */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  31,                                  /* colNo */
  "activeIndicies",                    /* aName */
  "meanShiftSegmentLABXY",             /* fName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo ib_emlrtRSI = { 53, /* lineNo */
  "meanShiftSegmentLABXY",             /* fcnName */
  "/home/brian/Desktop/Final Project/src/meanShiftSegmentLABXY.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 18, /* lineNo */
  "indexDivide",                       /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/eml/+coder/+internal/indexDivide.m"/* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static const mxArray *emlrt_marshallOut(const real32_T u);
static const mxArray *horzcat(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *sprintfc(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      absNumerator = ~(uint32_T)numerator + 1U;
    } else {
      absNumerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(uint32_T)denominator + 1U;
    } else {
      absDenominator = (uint32_T)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

static const mxArray *emlrt_marshallOut(const real32_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)mxGetData(m2) = u;
  emlrtAssign(&y, m2);
  return y;
}

static const mxArray *horzcat(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 4, pArrays, "horzcat", true, location);
}

static const mxArray *sprintfc(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m4;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m4, 2, pArrays, "sprintfc", true,
    location);
}

void meanShiftSegmentLABXY(const emlrtStack *sp, const emxArray_real32_T *pts,
  const real32_T bandwidth[2], const struct0_T *options, emxArray_real32_T
  *pts_out)
{
  real32_T s;
  int32_T nx;
  int32_T i0;
  int32_T xoffset;
  uint32_T varargin_1[3];
  int32_T maxdimlen;
  emxArray_real32_T *X;
  emxArray_real32_T *currX;
  emxArray_real32_T *y;
  emxArray_real32_T *b_y;
  emxArray_real32_T *Xs;
  emxArray_real32_T *Ys;
  emxArray_real32_T *fcnOutput;
  emxArray_real32_T *S;
  emxArray_real32_T *currS;
  emxArray_boolean_T *activeIndicies;
  real_T d0;
  emxArray_real32_T *newX;
  emxArray_real32_T *newS;
  emxArray_real32_T *x;
  emxArray_real32_T *b_currX;
  emxArray_real32_T *b_S;
  emxArray_real32_T *b_X;
  emxArray_real32_T *c_X;
  emxArray_real32_T *c_S;
  boolean_T exitg1;
  emxArray_real32_T *b_x;
  int32_T calclen;
  int32_T c_currX[2];
  int32_T b_newX[2];
  real32_T d_X[3];
  real32_T b_fcnOutput[3];
  real32_T d_S[2];
  real32_T c_fcnOutput[2];
  real32_T K;
  boolean_T overflow;
  const mxArray *c_y;
  const mxArray *m0;
  const mxArray *d_y;
  static const int32_T iv0[2] = { 1, 2 };

  static const char_T u[2] = { '%', 'd' };

  const mxArray *e_y;
  static const int32_T iv1[2] = { 1, 15 };

  static const char_T b_u[15] = { ']', ' ', 'c', 'o', 'u', 'n', 't', 'A', 'c',
    't', 'i', 'v', 'e', ':', ' ' };

  const mxArray *f_y;
  static const int32_T iv2[2] = { 1, 2 };

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

  /*  Compute the mean shift procedure on the input data and return the segmented data labels */
  /*  */
  /*  Adapted from: */
  /*  Comaniciu and Meer. "Mean Shift: A Robust Approach Toward Feature Space */
  /*  Analysis" IEE Transactions on Pattern Analysis and Machine Intelligence. */
  /*  Vol. 24, No. 5, May 2002. */
  /*  start by flattening to list of vectors */
  s = (real32_T)pts->size[0] * (real32_T)pts->size[1];
  st.site = &emlrtRSI;
  nx = pts->size[0] * pts->size[1] * 3;
  b_st.site = &k_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  assertValidSizeArg(&c_st, s);
  for (i0 = 0; i0 < 3; i0++) {
    varargin_1[i0] = (uint32_T)pts->size[i0];
  }

  xoffset = (int32_T)varargin_1[0];
  for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
    if ((int32_T)varargin_1[maxdimlen + 1] > xoffset) {
      xoffset = (int32_T)varargin_1[maxdimlen + 1];
    }
  }

  maxdimlen = muIntScalarMax_sint32(nx, xoffset);
  if ((int32_T)s > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if (3 > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if ((int32_T)s * 3 != nx) {
    emlrtErrorWithMessageIdR2012b(&st, &q_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real32_T(&st, &X, 2, &c_emlrtRTEI, true);
  i0 = X->size[0] * X->size[1];
  X->size[0] = 3;
  X->size[1] = (int32_T)s;
  emxEnsureCapacity(sp, (emxArray__common *)X, i0, sizeof(real32_T), &emlrtRTEI);
  xoffset = (int32_T)s;
  for (i0 = 0; i0 < xoffset; i0++) {
    for (maxdimlen = 0; maxdimlen < 3; maxdimlen++) {
      X->data[maxdimlen + X->size[0] * i0] = pts->data[i0 + (int32_T)s *
        maxdimlen];
    }
  }

  emxInit_real32_T(sp, &currX, 2, &d_emlrtRTEI, true);
  i0 = currX->size[0] * currX->size[1];
  currX->size[0] = 3;
  currX->size[1] = X->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)currX, i0, sizeof(real32_T),
                    &emlrtRTEI);
  xoffset = X->size[0] * X->size[1];
  for (i0 = 0; i0 < xoffset; i0++) {
    currX->data[i0] = X->data[i0];
  }

  /*  then compute spatial list */
  emxInit_real32_T(sp, &y, 2, &emlrtRTEI, true);
  if (pts->size[0] < 1.0F) {
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)y, i0, sizeof(real32_T),
                      &emlrtRTEI);
  } else {
    s = (real32_T)pts->size[0];
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)(s - 1.0F) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)y, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = (int32_T)(s - 1.0F);
    for (i0 = 0; i0 <= xoffset; i0++) {
      y->data[y->size[0] * i0] = 1.0F + (real32_T)i0;
    }
  }

  emxInit_real32_T(sp, &b_y, 2, &emlrtRTEI, true);
  if (pts->size[1] < 1.0F) {
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i0, sizeof(real32_T),
                      &emlrtRTEI);
  } else {
    s = (real32_T)pts->size[1];
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = (int32_T)(s - 1.0F) + 1;
    emxEnsureCapacity(sp, (emxArray__common *)b_y, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = (int32_T)(s - 1.0F);
    for (i0 = 0; i0 <= xoffset; i0++) {
      b_y->data[b_y->size[0] * i0] = 1.0F + (real32_T)i0;
    }
  }

  emxInit_real32_T(sp, &Xs, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &Ys, 2, &f_emlrtRTEI, true);
  emxInit_real32_T1(sp, &fcnOutput, 3, &emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  meshgrid(&st, y, b_y, Xs, Ys);
  st.site = &c_emlrtRSI;
  cat(&st, Xs, Ys, fcnOutput);
  s = (real32_T)pts->size[0] * (real32_T)pts->size[1];
  st.site = &c_emlrtRSI;
  nx = fcnOutput->size[0] * fcnOutput->size[1] << 1;
  b_st.site = &k_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  assertValidSizeArg(&c_st, s);
  emxFree_real32_T(&Ys);
  emxFree_real32_T(&Xs);
  for (i0 = 0; i0 < 3; i0++) {
    varargin_1[i0] = (uint32_T)fcnOutput->size[i0];
  }

  xoffset = (int32_T)varargin_1[0];
  for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
    if ((int32_T)varargin_1[maxdimlen + 1] > xoffset) {
      xoffset = (int32_T)varargin_1[maxdimlen + 1];
    }
  }

  maxdimlen = muIntScalarMax_sint32(nx, xoffset);
  if ((int32_T)s > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if (2 > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if ((int32_T)s << 1 != nx) {
    emlrtErrorWithMessageIdR2012b(&st, &q_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  emxInit_real32_T(&st, &S, 2, &g_emlrtRTEI, true);
  i0 = S->size[0] * S->size[1];
  S->size[0] = 2;
  S->size[1] = (int32_T)s;
  emxEnsureCapacity(sp, (emxArray__common *)S, i0, sizeof(real32_T), &emlrtRTEI);
  xoffset = (int32_T)s;
  for (i0 = 0; i0 < xoffset; i0++) {
    for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
      S->data[maxdimlen + S->size[0] * i0] = fcnOutput->data[i0 + (int32_T)s *
        maxdimlen];
    }
  }

  emxFree_real32_T(&fcnOutput);
  emxInit_real32_T(sp, &currS, 2, &h_emlrtRTEI, true);
  i0 = currS->size[0] * currS->size[1];
  currS->size[0] = 2;
  currS->size[1] = S->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)currS, i0, sizeof(real32_T),
                    &emlrtRTEI);
  xoffset = S->size[0] * S->size[1];
  for (i0 = 0; i0 < xoffset; i0++) {
    currS->data[i0] = S->data[i0];
  }

  emxInit_boolean_T(sp, &activeIndicies, 2, &i_emlrtRTEI, true);

  /*  loop until done shifting */
  s = (real32_T)pts->size[0] * (real32_T)pts->size[1];
  i0 = activeIndicies->size[0] * activeIndicies->size[1];
  activeIndicies->size[0] = 1;
  d0 = s;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
  }

  activeIndicies->size[1] = (int32_T)(real32_T)d0;
  emxEnsureCapacity(sp, (emxArray__common *)activeIndicies, i0, sizeof(boolean_T),
                    &emlrtRTEI);
  d0 = s;
  if (d0 != (int32_T)d0) {
    emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
  }

  xoffset = (int32_T)(real32_T)d0;
  for (i0 = 0; i0 < xoffset; i0++) {
    activeIndicies->data[i0] = true;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, options->maxLoops, mxSINGLE_CLASS,
    (int32_T)options->maxLoops, &o_emlrtRTEI, sp);
  nx = 0;
  emxInit_real32_T(sp, &newX, 2, &j_emlrtRTEI, true);
  emxInit_real32_T(sp, &newS, 2, &k_emlrtRTEI, true);
  emxInit_real32_T(sp, &x, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &b_currX, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &b_S, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &b_X, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &c_X, 2, &emlrtRTEI, true);
  emxInit_real32_T(sp, &c_S, 2, &emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (nx <= (int32_T)options->maxLoops - 1)) {
    /*  use mean shift on the points */
    /*  loop for now because vectored is too big */
    i0 = newX->size[0] * newX->size[1];
    newX->size[0] = 3;
    newX->size[1] = currX->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)newX, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = currX->size[0] * currX->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      newX->data[i0] = currX->data[i0];
    }

    i0 = newS->size[0] * newS->size[1];
    newS->size[0] = 2;
    newS->size[1] = currS->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)newS, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = currS->size[0] * currS->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      newS->data[i0] = currS->data[i0];
    }

    s = (real32_T)pts->size[0] * (real32_T)pts->size[1];
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, s, mxSINGLE_CLASS, (int32_T)s,
      &p_emlrtRTEI, sp);
    calclen = 0;
    while (calclen <= (int32_T)s - 1) {
      i0 = activeIndicies->size[1];
      maxdimlen = (int32_T)(1.0F + (real32_T)calclen);
      if (!((maxdimlen >= 1) && (maxdimlen <= i0))) {
        emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i0, &e_emlrtBCI, sp);
      }

      if (activeIndicies->data[(int32_T)(real32_T)maxdimlen - 1]) {
        i0 = currX->size[1];
        maxdimlen = (int32_T)(1.0F + (real32_T)calclen);
        if (!((maxdimlen >= 1) && (maxdimlen <= i0))) {
          emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i0, &emlrtBCI, sp);
        }

        xoffset = X->size[1];
        i0 = c_X->size[0] * c_X->size[1];
        c_X->size[0] = 3;
        c_X->size[1] = xoffset;
        emxEnsureCapacity(sp, (emxArray__common *)c_X, i0, sizeof(real32_T),
                          &emlrtRTEI);
        for (i0 = 0; i0 < xoffset; i0++) {
          for (maxdimlen = 0; maxdimlen < 3; maxdimlen++) {
            c_X->data[maxdimlen + c_X->size[0] * i0] = X->data[maxdimlen +
              X->size[0] * i0];
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          d_X[i0] = c_X->data[i0] - currX->data[i0 + currX->size[0] * ((int32_T)
            (1.0F + (real32_T)calclen) - 1)];
        }

        st.site = &d_emlrtRSI;
        power(d_X, b_fcnOutput);
        i0 = currS->size[1];
        maxdimlen = (int32_T)(1.0F + (real32_T)calclen);
        if (!((maxdimlen >= 1) && (maxdimlen <= i0))) {
          emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, i0, &b_emlrtBCI, sp);
        }

        xoffset = S->size[1];
        i0 = c_S->size[0] * c_S->size[1];
        c_S->size[0] = 2;
        c_S->size[1] = xoffset;
        emxEnsureCapacity(sp, (emxArray__common *)c_S, i0, sizeof(real32_T),
                          &emlrtRTEI);
        for (i0 = 0; i0 < xoffset; i0++) {
          for (maxdimlen = 0; maxdimlen < 2; maxdimlen++) {
            c_S->data[maxdimlen + c_S->size[0] * i0] = S->data[maxdimlen +
              S->size[0] * i0];
          }
        }

        for (i0 = 0; i0 < 2; i0++) {
          d_S[i0] = c_S->data[i0] - currS->data[i0 + currS->size[0] * ((int32_T)
            (1.0F + (real32_T)calclen) - 1)];
        }

        st.site = &e_emlrtRSI;
        b_power(d_S, c_fcnOutput);

        /*  then compute the kernel of D (including /bandwidth) */
        K = 0.398942262F * muSingleScalarExp(-0.5F * (sum(b_fcnOutput) /
          bandwidth[0])) * (0.398942262F * muSingleScalarExp(-0.5F * (b_sum
          (c_fcnOutput) / bandwidth[1])));

        /*  then compute the vectorized mean shift */
        i0 = b_X->size[0] * b_X->size[1];
        b_X->size[0] = 3;
        b_X->size[1] = X->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_X, i0, sizeof(real32_T),
                          &emlrtRTEI);
        xoffset = X->size[0] * X->size[1];
        for (i0 = 0; i0 < xoffset; i0++) {
          b_X->data[i0] = X->data[i0] * K;
        }

        st.site = &f_emlrtRSI;
        c_sum(&st, b_X, b_fcnOutput);
        maxdimlen = newX->size[1];
        i0 = (int32_T)(1.0F + (real32_T)calclen);
        if (!((i0 >= 1) && (i0 <= maxdimlen))) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, maxdimlen, &c_emlrtBCI, sp);
        }

        for (i0 = 0; i0 < 3; i0++) {
          newX->data[i0 + newX->size[0] * ((int32_T)(1.0F + (real32_T)calclen) -
            1)] = b_fcnOutput[i0] / K;
        }

        i0 = b_S->size[0] * b_S->size[1];
        b_S->size[0] = 2;
        b_S->size[1] = S->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)b_S, i0, sizeof(real32_T),
                          &emlrtRTEI);
        xoffset = S->size[0] * S->size[1];
        for (i0 = 0; i0 < xoffset; i0++) {
          b_S->data[i0] = S->data[i0] * K;
        }

        st.site = &g_emlrtRSI;
        d_sum(&st, b_S, c_fcnOutput);
        maxdimlen = newS->size[1];
        i0 = (int32_T)(1.0F + (real32_T)calclen);
        if (!((i0 >= 1) && (i0 <= maxdimlen))) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, maxdimlen, &d_emlrtBCI, sp);
        }

        for (i0 = 0; i0 < 2; i0++) {
          newS->data[i0 + newS->size[0] * ((int32_T)(1.0F + (real32_T)calclen) -
            1)] = c_fcnOutput[i0] / K;
        }
      }

      calclen++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  see how many indicies are still active and update */
    st.site = &h_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    for (i0 = 0; i0 < 2; i0++) {
      c_currX[i0] = currX->size[i0];
      b_newX[i0] = newX->size[i0];
    }

    if ((c_currX[0] != b_newX[0]) || (c_currX[1] != b_newX[1])) {
      emlrtSizeEqCheckNDR2012b(&c_currX[0], &b_newX[0], &emlrtECI, &b_st);
    }

    i0 = b_currX->size[0] * b_currX->size[1];
    b_currX->size[0] = 3;
    b_currX->size[1] = currX->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)b_currX, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = currX->size[0] * currX->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      b_currX->data[i0] = currX->data[i0] - newX->data[i0];
    }

    st.site = &h_emlrtRSI;
    c_power(&st, b_currX, currX);
    st.site = &h_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    for (i0 = 0; i0 < 2; i0++) {
      c_currX[i0] = currS->size[i0];
      b_newX[i0] = newS->size[i0];
    }

    if ((c_currX[0] != b_newX[0]) || (c_currX[1] != b_newX[1])) {
      emlrtSizeEqCheckNDR2012b(&c_currX[0], &b_newX[0], &emlrtECI, &b_st);
    }

    i0 = currS->size[0] * currS->size[1];
    currS->size[0] = 2;
    emxEnsureCapacity(&b_st, (emxArray__common *)currS, i0, sizeof(real32_T),
                      &emlrtRTEI);
    maxdimlen = currS->size[0];
    xoffset = currS->size[1];
    xoffset *= maxdimlen;
    for (i0 = 0; i0 < xoffset; i0++) {
      currS->data[i0] -= newS->data[i0];
    }

    st.site = &h_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    d_st.site = &eb_emlrtRSI;
    i0 = x->size[0] * x->size[1];
    x->size[0] = 2;
    x->size[1] = currS->size[1];
    emxEnsureCapacity(&d_st, (emxArray__common *)x, i0, sizeof(real32_T),
                      &b_emlrtRTEI);
    if (!b_dimagree(x, currS)) {
      emlrtErrorWithMessageIdR2012b(&d_st, &r_emlrtRTEI, "MATLAB:dimagree", 0);
    }

    maxdimlen = currS->size[1] << 1;
    d_st.site = &fb_emlrtRSI;
    if ((!(1 > maxdimlen)) && (maxdimlen > 2147483646)) {
      e_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (calclen = 0; calclen + 1 <= maxdimlen; calclen++) {
      x->data[calclen] = currS->data[calclen] * currS->data[calclen];
    }

    st.site = &h_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    i0 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = currX->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)y, i0, sizeof(real32_T),
                      &emlrtRTEI);
    if (currX->size[1] == 0) {
      i0 = y->size[0] * y->size[1];
      y->size[0] = 1;
      emxEnsureCapacity(&c_st, (emxArray__common *)y, i0, sizeof(real32_T),
                        &emlrtRTEI);
      xoffset = y->size[1];
      for (i0 = 0; i0 < xoffset; i0++) {
        y->data[y->size[0] * i0] = 0.0F;
      }
    } else {
      d_st.site = &gb_emlrtRSI;
      overflow = (currX->size[1] > 2147483646);
      if (overflow) {
        e_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (maxdimlen = 0; maxdimlen + 1 <= currX->size[1]; maxdimlen++) {
        xoffset = maxdimlen * 3;
        s = currX->data[xoffset];
        for (calclen = 0; calclen < 2; calclen++) {
          s += currX->data[(xoffset + calclen) + 1];
        }

        y->data[maxdimlen] = s;
      }
    }

    st.site = &h_emlrtRSI;
    b_st.site = &y_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    i0 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = x->size[1];
    emxEnsureCapacity(&c_st, (emxArray__common *)b_y, i0, sizeof(real32_T),
                      &emlrtRTEI);
    if (x->size[1] == 0) {
      i0 = b_y->size[0] * b_y->size[1];
      b_y->size[0] = 1;
      emxEnsureCapacity(&c_st, (emxArray__common *)b_y, i0, sizeof(real32_T),
                        &emlrtRTEI);
      xoffset = b_y->size[1];
      for (i0 = 0; i0 < xoffset; i0++) {
        b_y->data[b_y->size[0] * i0] = 0.0F;
      }
    } else {
      d_st.site = &gb_emlrtRSI;
      overflow = (x->size[1] > 2147483646);
      if (overflow) {
        e_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (maxdimlen = 0; maxdimlen + 1 <= x->size[1]; maxdimlen++) {
        b_y->data[maxdimlen] = x->data[maxdimlen << 1] + x->data[(maxdimlen << 1)
          + 1];
      }
    }

    st.site = &h_emlrtRSI;
    b_st.site = &cb_emlrtRSI;
    for (i0 = 0; i0 < 2; i0++) {
      c_currX[i0] = y->size[i0];
      b_newX[i0] = b_y->size[i0];
    }

    if ((c_currX[0] != b_newX[0]) || (c_currX[1] != b_newX[1])) {
      emlrtSizeEqCheckNDR2012b(&c_currX[0], &b_newX[0], &emlrtECI, &b_st);
    }

    i0 = activeIndicies->size[0] * activeIndicies->size[1];
    activeIndicies->size[0] = 1;
    activeIndicies->size[1] = y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)activeIndicies, i0, sizeof
                      (boolean_T), &emlrtRTEI);
    xoffset = y->size[0] * y->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      activeIndicies->data[i0] = (y->data[i0] + b_y->data[i0] > options->tolExit);
    }

    maxdimlen = 0;
    for (calclen = 0; calclen < activeIndicies->size[1]; calclen++) {
      if (activeIndicies->data[calclen]) {
        maxdimlen++;
      }
    }

    /*  if debug display stats on iter */
    st.site = &i_emlrtRSI;
    if (muSingleScalarIsNaN(options->debug)) {
      b_st.site = &hb_emlrtRSI;
      c_error(&b_st);
    }

    if (options->debug != 0.0F) {
      c_y = NULL;
      m0 = emlrtCreateString1('[');
      emlrtAssign(&c_y, m0);
      d_y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(sp, 2, m0, &u[0]);
      emlrtAssign(&d_y, m0);
      e_y = NULL;
      m0 = emlrtCreateCharArray(2, iv1);
      emlrtInitCharArrayR2013a(sp, 15, m0, &b_u[0]);
      emlrtAssign(&e_y, m0);
      f_y = NULL;
      m0 = emlrtCreateCharArray(2, iv2);
      emlrtInitCharArrayR2013a(sp, 2, m0, &u[0]);
      emlrtAssign(&f_y, m0);
      st.site = &ib_emlrtRSI;
      disp(&st, horzcat(&st, c_y, sprintfc(&st, d_y, emlrt_marshallOut(1.0F +
              (real32_T)nx), &emlrtMCI), e_y, sprintfc(&st, f_y,
             emlrt_marshallOut((real32_T)maxdimlen), &b_emlrtMCI), &c_emlrtMCI),
           &d_emlrtMCI);
    }

    /*  update variables */
    i0 = currX->size[0] * currX->size[1];
    currX->size[0] = 3;
    currX->size[1] = newX->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)currX, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = newX->size[0] * newX->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      currX->data[i0] = newX->data[i0];
    }

    i0 = currS->size[0] * currS->size[1];
    currS->size[0] = 2;
    currS->size[1] = newS->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)currS, i0, sizeof(real32_T),
                      &emlrtRTEI);
    xoffset = newS->size[0] * newS->size[1];
    for (i0 = 0; i0 < xoffset; i0++) {
      currS->data[i0] = newS->data[i0];
    }

    /*  exit if done */
    if (maxdimlen == 0.0F) {
      exitg1 = true;
    } else {
      nx++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emxFree_real32_T(&c_S);
  emxFree_real32_T(&c_X);
  emxFree_real32_T(&b_X);
  emxFree_real32_T(&b_S);
  emxFree_real32_T(&b_currX);
  emxFree_real32_T(&x);
  emxFree_real32_T(&b_y);
  emxFree_real32_T(&y);
  emxFree_real32_T(&newS);
  emxFree_real32_T(&newX);
  emxFree_boolean_T(&activeIndicies);
  emxFree_real32_T(&currS);
  emxFree_real32_T(&S);
  emxFree_real32_T(&X);
  emxInit_real32_T(sp, &b_x, 2, &emlrtRTEI, true);
  st.site = &j_emlrtRSI;
  xoffset = currX->size[1];
  i0 = b_x->size[0] * b_x->size[1];
  b_x->size[0] = xoffset;
  b_x->size[1] = 3;
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i0, sizeof(real32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < 3; i0++) {
    for (maxdimlen = 0; maxdimlen < xoffset; maxdimlen++) {
      b_x->data[maxdimlen + b_x->size[0] * i0] = currX->data[i0 + currX->size[0]
        * maxdimlen];
    }
  }

  emxFree_real32_T(&currX);
  nx = b_x->size[0] * 3;
  b_st.site = &k_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  assertValidSizeArg(&c_st, (real32_T)pts->size[0]);
  c_st.site = &m_emlrtRSI;
  assertValidSizeArg(&c_st, (real32_T)pts->size[1]);
  maxdimlen = (int32_T)(real32_T)pts->size[0] * (int32_T)(real32_T)pts->size[1];
  if (maxdimlen > 0) {
    c_st.site = &kb_emlrtRSI;
    calclen = div_s32(&c_st, nx, maxdimlen);
    if (!(calclen <= nx)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &s_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }
  } else {
    calclen = 0;
  }

  xoffset = b_x->size[0];
  if (3 > xoffset) {
    xoffset = 3;
  }

  maxdimlen = muIntScalarMax_sint32(nx, xoffset);
  if ((int32_T)(real32_T)pts->size[0] > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if ((int32_T)(real32_T)pts->size[1] > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if (calclen > maxdimlen) {
    b_st.site = &l_emlrtRSI;
    error(&b_st);
  }

  if ((int32_T)(real32_T)pts->size[0] * (int32_T)(real32_T)pts->size[1] *
      calclen != nx) {
    emlrtErrorWithMessageIdR2012b(&st, &q_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  i0 = pts_out->size[0] * pts_out->size[1] * pts_out->size[2];
  pts_out->size[0] = (int32_T)(real32_T)pts->size[0];
  pts_out->size[1] = (int32_T)(real32_T)pts->size[1];
  pts_out->size[2] = calclen;
  emxEnsureCapacity(&st, (emxArray__common *)pts_out, i0, sizeof(real32_T),
                    &emlrtRTEI);
  xoffset = (int32_T)(real32_T)pts->size[0] * (int32_T)(real32_T)pts->size[1] *
    calclen;
  for (i0 = 0; i0 < xoffset; i0++) {
    pts_out->data[i0] = b_x->data[i0];
  }

  emxFree_real32_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meanShiftSegmentLABXY.c) */
