/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_meanShiftLABXY_api.c
 *
 * Code generation for function '_coder_meanShiftLABXY_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLABXY.h"
#include "_coder_meanShiftLABXY_api.h"
#include "meanShiftLABXY_emxutil.h"
#include "meanShiftLABXY_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_meanShiftLABXY_api",         /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *bandwidth, const char_T *identifier))[2];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *activeIndicies, const char_T *identifier, emxArray_real_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *bandwidth, const char_T *identifier))[2]
{
  real_T (*y)[2];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(bandwidth), &thisId);
  emlrtDestroyArray(&bandwidth);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *activeIndicies, const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(activeIndicies), &thisId, y);
  emlrtDestroyArray(&activeIndicies);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 5, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv1[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  real_T (*ret)[2];
  static const int32_T dims[2] = { 1, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[2])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv1[2] = { false, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void meanShiftLABXY_api(const mxArray * const prhs[4], const mxArray *plhs[1])
{
  emxArray_real_T *X;
  emxArray_real_T *currX;
  emxArray_real_T *activeIndicies;
  emxArray_real_T *newX;
  real_T (*bandwidth)[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &currX, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &activeIndicies, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &newX, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "currX", currX);
  bandwidth = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "bandwidth");
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "activeIndicies", activeIndicies);

  /* Invoke the target function */
  meanShiftLABXY(&st, X, currX, *bandwidth, activeIndicies, newX);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(newX);
  newX->canFreeData = false;
  emxFree_real_T(&newX);
  activeIndicies->canFreeData = false;
  emxFree_real_T(&activeIndicies);
  currX->canFreeData = false;
  emxFree_real_T(&currX);
  X->canFreeData = false;
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_meanShiftLABXY_api.c) */
