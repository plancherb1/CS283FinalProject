/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_meanShiftSegmentLABXY_api.c
 *
 * Code generation for function '_coder_meanShiftSegmentLABXY_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "_coder_meanShiftSegmentLABXY_api.h"
#include "meanShiftSegmentLABXY_emxutil.h"
#include "meanShiftSegmentLABXY_data.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_meanShiftSegmentLABXY_api",  /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real32_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bandwidth,
  const char_T *identifier, real32_T y[2]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[2]);
static struct0_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *options,
  const char_T *identifier);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *pts, const
  char_T *identifier, emxArray_real32_T *y);
static struct0_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[2]);
static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  real32_T *pData;
  int32_T i1;
  int32_T i;
  int32_T b_i;
  int32_T c_i;
  y = NULL;
  m3 = emlrtCreateNumericArray(3, *(int32_T (*)[3])u->size, mxSINGLE_CLASS,
    mxREAL);
  pData = (real32_T *)mxGetData(m3);
  i1 = 0;
  for (i = 0; i < u->size[2]; i++) {
    for (b_i = 0; b_i < u->size[1]; b_i++) {
      for (c_i = 0; c_i < u->size[0]; c_i++) {
        pData[i1] = u->data[(c_i + u->size[0] * b_i) + u->size[0] * u->size[1] *
          i];
        i1++;
      }
    }
  }

  emlrtAssign(&y, m3);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bandwidth,
  const char_T *identifier, real32_T y[2])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(bandwidth), &thisId, y);
  emlrtDestroyArray(&bandwidth);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real32_T y[2])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct0_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *options,
  const char_T *identifier)
{
  struct0_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(options), &thisId);
  emlrtDestroyArray(&options);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *pts, const
  char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(pts), &thisId, y);
  emlrtDestroyArray(&pts);
}

static struct0_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct0_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "debug", "tolExit", "maxLoops" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "debug";
  y.debug = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "debug")), &thisId);
  thisId.fIdentifier = "tolExit";
  y.tolExit = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "tolExit")), &thisId);
  thisId.fIdentifier = "maxLoops";
  y.maxLoops = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "maxLoops")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static real32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real32_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  static const int32_T dims[3] = { -1, -1, 3 };

  const boolean_T bv0[3] = { true, true, false };

  int32_T iv7[3];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single|double", false, 3U, dims,
    &bv0[0], iv7);
  i2 = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  ret->size[2] = iv7[2];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i2, sizeof(real32_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real32_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 4, false);
  emlrtDestroyArray(&src);
}

static real32_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "single|double", false, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 4, false);
  emlrtDestroyArray(&src);
  return ret;
}

void meanShiftSegmentLABXY_api(const mxArray * const prhs[3], const mxArray
  *plhs[1])
{
  emxArray_real32_T *pts;
  emxArray_real32_T *pts_out;
  real32_T bandwidth[2];
  struct0_T options;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real32_T1(&st, &pts, 3, &n_emlrtRTEI, true);
  emxInit_real32_T1(&st, &pts_out, 3, &n_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "pts", pts);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "bandwidth", bandwidth);
  options = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "options");

  /* Invoke the target function */
  meanShiftSegmentLABXY(&st, pts, bandwidth, &options, pts_out);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(pts_out);
  emxFree_real32_T(&pts_out);
  emxFree_real32_T(&pts);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_meanShiftSegmentLABXY_api.c) */
