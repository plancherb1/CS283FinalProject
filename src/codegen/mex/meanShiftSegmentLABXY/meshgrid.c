/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.c
 *
 * Code generation for function 'meshgrid'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "meshgrid.h"
#include "meanShiftSegmentLABXY_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "assertValidSizeArg.h"
#include "meanShiftSegmentLABXY_data.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 17,  /* lineNo */
  "meshgrid",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 18,  /* lineNo */
  "meshgrid",                          /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 18,  /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 112, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 114, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 117, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 119, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtMCInfo e_emlrtMCI = { 37,  /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 1, /* lineNo */
  23,                                  /* colNo */
  "meshgrid",                          /* fName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pName */
};

static emlrtRSInfo jb_emlrtRSI = { 37, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2017a/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

/* Function Declarations */
static void d_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static void d_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void meshgrid(const emlrtStack *sp, const emxArray_real32_T *x, const
              emxArray_real32_T *y, emxArray_real32_T *xx, emxArray_real32_T *yy)
{
  emxArray_real32_T *a;
  int32_T ntilerows;
  int32_T outsize_idx_1;
  real_T varargin_1[2];
  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 15 };

  static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  static const int32_T iv4[2] = { 1, 15 };

  int32_T ibtile;
  int32_T ibmat;
  int32_T itilerow;
  static const int32_T iv5[2] = { 1, 15 };

  static const int32_T iv6[2] = { 1, 15 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real32_T(sp, &a, 2, &l_emlrtRTEI, true);
  if ((x->size[1] == 0) || (y->size[1] == 0)) {
    ntilerows = xx->size[0] * xx->size[1];
    xx->size[0] = 0;
    xx->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)xx, ntilerows, sizeof(real32_T),
                      &l_emlrtRTEI);
    ntilerows = yy->size[0] * yy->size[1];
    yy->size[0] = 0;
    yy->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)yy, ntilerows, sizeof(real32_T),
                      &l_emlrtRTEI);
  } else {
    st.site = &n_emlrtRSI;
    outsize_idx_1 = x->size[1];
    ntilerows = a->size[0] * a->size[1];
    a->size[0] = 1;
    a->size[1] = outsize_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)a, ntilerows, sizeof(real32_T),
                      &l_emlrtRTEI);
    for (ntilerows = 0; ntilerows < outsize_idx_1; ntilerows++) {
      a->data[a->size[0] * ntilerows] = x->data[ntilerows];
    }

    varargin_1[0] = y->size[1];
    varargin_1[1] = 1.0;
    b_st.site = &p_emlrtRSI;
    b_assertValidSizeArg(&b_st, varargin_1);
    if (!(varargin_1[0] == varargin_1[0])) {
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&st, 15, m1, &u[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &jb_emlrtRSI;
      d_error(&b_st, b_y, &e_emlrtMCI);
    }

    outsize_idx_1 = a->size[1];
    if (outsize_idx_1 != a->size[1]) {
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv4);
      emlrtInitCharArrayR2013a(&st, 15, m1, &u[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &jb_emlrtRSI;
      d_error(&b_st, b_y, &e_emlrtMCI);
    }

    ntilerows = xx->size[0] * xx->size[1];
    xx->size[0] = (int32_T)varargin_1[0];
    xx->size[1] = outsize_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)xx, ntilerows, sizeof(real32_T),
                      &l_emlrtRTEI);
    outsize_idx_1 = a->size[1];
    ntilerows = (int32_T)varargin_1[0];
    b_st.site = &q_emlrtRSI;
    b_st.site = &r_emlrtRSI;
    if (outsize_idx_1 > 2147483646) {
      c_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (ibtile = 0; ibtile + 1 <= outsize_idx_1; ibtile++) {
      ibmat = ibtile * ntilerows;
      b_st.site = &s_emlrtRSI;
      if (ntilerows > 2147483646) {
        c_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (itilerow = 1; itilerow <= ntilerows; itilerow++) {
        xx->data[(ibmat + itilerow) - 1] = a->data[ibtile];
      }
    }

    st.site = &o_emlrtRSI;
    varargin_1[0] = 1.0;
    varargin_1[1] = x->size[1];
    b_st.site = &p_emlrtRSI;
    b_assertValidSizeArg(&b_st, varargin_1);
    outsize_idx_1 = y->size[1];
    if (outsize_idx_1 != y->size[1]) {
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv5);
      emlrtInitCharArrayR2013a(&st, 15, m1, &u[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &jb_emlrtRSI;
      d_error(&b_st, b_y, &e_emlrtMCI);
    }

    if (!(varargin_1[1] == varargin_1[1])) {
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv6);
      emlrtInitCharArrayR2013a(&st, 15, m1, &u[0]);
      emlrtAssign(&b_y, m1);
      b_st.site = &jb_emlrtRSI;
      d_error(&b_st, b_y, &e_emlrtMCI);
    }

    ntilerows = yy->size[0] * yy->size[1];
    yy->size[0] = outsize_idx_1;
    yy->size[1] = (int32_T)varargin_1[1];
    emxEnsureCapacity(&st, (emxArray__common *)yy, ntilerows, sizeof(real32_T),
                      &l_emlrtRTEI);
    outsize_idx_1 = y->size[1];
    b_st.site = &q_emlrtRSI;
    if (varargin_1[1] > 2.147483646E+9) {
      c_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (ntilerows = 1; ntilerows <= (int32_T)varargin_1[1]; ntilerows++) {
      ibtile = (ntilerows - 1) * outsize_idx_1;
      b_st.site = &s_emlrtRSI;
      b_st.site = &u_emlrtRSI;
      if (outsize_idx_1 > 2147483646) {
        c_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ibmat = 1; ibmat <= outsize_idx_1; ibmat++) {
        yy->data[(ibtile + ibmat) - 1] = y->data[ibmat - 1];
      }
    }
  }

  emxFree_real32_T(&a);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (meshgrid.c) */
