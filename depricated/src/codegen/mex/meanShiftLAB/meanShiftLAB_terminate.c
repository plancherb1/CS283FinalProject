/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meanShiftLAB_terminate.c
 *
 * Code generation for function 'meanShiftLAB_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLAB.h"
#include "meanShiftLAB_terminate.h"
#include "_coder_meanShiftLAB_mex.h"
#include "meanShiftLAB_data.h"

/* Function Definitions */
void meanShiftLAB_atexit(void)
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

void meanShiftLAB_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (meanShiftLAB_terminate.c) */
