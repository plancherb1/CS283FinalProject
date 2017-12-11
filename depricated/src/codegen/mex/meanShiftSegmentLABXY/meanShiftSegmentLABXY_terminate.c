/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftSegmentLABXY_terminate.c
 *
 * Code generation for function 'meanShiftSegmentLABXY_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftSegmentLABXY.h"
#include "meanShiftSegmentLABXY_terminate.h"
#include "_coder_meanShiftSegmentLABXY_mex.h"
#include "meanShiftSegmentLABXY_data.h"

/* Function Definitions */
void meanShiftSegmentLABXY_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void meanShiftSegmentLABXY_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (meanShiftSegmentLABXY_terminate.c) */
