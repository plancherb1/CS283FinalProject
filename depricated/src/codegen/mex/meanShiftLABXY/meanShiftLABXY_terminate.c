/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLABXY_terminate.c
 *
 * Code generation for function 'meanShiftLABXY_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLABXY.h"
#include "meanShiftLABXY_terminate.h"
#include "_coder_meanShiftLABXY_mex.h"
#include "meanShiftLABXY_data.h"

/* Function Definitions */
void meanShiftLABXY_atexit(void)
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

void meanShiftLABXY_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (meanShiftLABXY_terminate.c) */
