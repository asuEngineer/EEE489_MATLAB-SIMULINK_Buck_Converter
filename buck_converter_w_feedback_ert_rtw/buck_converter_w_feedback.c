/*
 * buck_converter_w_feedback.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter_w_feedback".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Feb 21 14:07:56 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buck_converter_w_feedback.h"
#include "buck_converter_w_feedback_private.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>

/* Block signals (default storage) */
B_buck_converter_w_feedback_T buck_converter_w_feedback_B;

/* Continuous states */
X_buck_converter_w_feedback_T buck_converter_w_feedback_X;

/* Disabled State Vector */
XDis_buck_converter_w_feedbac_T buck_converter_w_feedback_XDis;

/* Block states (default storage) */
DW_buck_converter_w_feedback_T buck_converter_w_feedback_DW;

/* Real-time model */
static RT_MODEL_buck_converter_w_fee_T buck_converter_w_feedback_M_;
RT_MODEL_buck_converter_w_fee_T *const buck_converter_w_feedback_M =
  &buck_converter_w_feedback_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  buck_converter_w_feedback_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  buck_converter_w_feedback_step();
  buck_converter_w_feedback_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  buck_converter_w_feedback_step();
  buck_converter_w_feedback_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void buck_converter_w_feedback_step(void)
{
  real_T u0;
  real32_T rtb_Sum;
  uint16_T b_varargout_1;
  uint8_T tmp_0;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(buck_converter_w_feedback_M)) {
    /* set solver stop time */
    if (!(buck_converter_w_feedback_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&buck_converter_w_feedback_M->solverInfo,
                            ((buck_converter_w_feedback_M->Timing.clockTickH0 +
        1) * buck_converter_w_feedback_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&buck_converter_w_feedback_M->solverInfo,
                            ((buck_converter_w_feedback_M->Timing.clockTick0 + 1)
        * buck_converter_w_feedback_M->Timing.stepSize0 +
        buck_converter_w_feedback_M->Timing.clockTickH0 *
        buck_converter_w_feedback_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(buck_converter_w_feedback_M)) {
    buck_converter_w_feedback_M->Timing.t[0] = rtsiGetT
      (&buck_converter_w_feedback_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(buck_converter_w_feedback_M);
  if (tmp) {
    /* MATLABSystem: '<Root>/Analog Input' */
    buck_converter_w_feedback_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(26U);
    MW_AnalogInSingle_ReadResult
      (buck_converter_w_feedback_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &b_varargout_1, MW_ANALOGIN_UINT16);

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<Root>/Vref'
     *  Gain: '<Root>/digital in to err'
     *  MATLABSystem: '<Root>/Analog Input'
     * */
    rtb_Sum = buck_converter_w_feedback_P.Vref_Value - (real32_T)((uint32_T)
      buck_converter_w_feedback_P.digitalintoerr_Gain * b_varargout_1) *
      5.96046448E-8F;

    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (rtb_Sum > buck_converter_w_feedback_P.Switch1_Threshold_a) {
      u0 = buck_converter_w_feedback_P.Constant_Value;
    } else {
      u0 = buck_converter_w_feedback_P.Constant1_Value;
    }

    /* MATLABSystem: '<Root>/Digital Output' incorporates:
     *  Switch: '<S1>/Switch1'
     */
    u0 = rt_roundd_snf(u0);
    if (u0 < 256.0) {
      if (u0 >= 0.0) {
        tmp_0 = (uint8_T)u0;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    writeDigitalPin(25, tmp_0);

    /* End of MATLABSystem: '<Root>/Digital Output' */
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Switch: '<S3>/Switch1'
   */
  if (buck_converter_w_feedback_X.Integrator_CSTATE >
      buck_converter_w_feedback_P.Switch_Threshold) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    buck_converter_w_feedback_B.Switch =
      buck_converter_w_feedback_P.Constant1_Value_k;
  } else if (buck_converter_w_feedback_X.Integrator_CSTATE >
             buck_converter_w_feedback_P.Switch1_Threshold_i) {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Switch: '<S3>/Switch'
     */
    buck_converter_w_feedback_B.Switch =
      buck_converter_w_feedback_X.Integrator_CSTATE;
  } else {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     */
    buck_converter_w_feedback_B.Switch =
      buck_converter_w_feedback_P.Constant_Value_f;
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLABSystem: '<Root>/PWM' */
  buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(16U);

  /* Gain: '<Root>/duty cycle to digital out' */
  u0 = buck_converter_w_feedback_P.dutycycletodigitalout_Gain *
    buck_converter_w_feedback_B.Switch;

  /* Start for MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle
    (buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, u0);
  if (tmp) {
    /* Gain: '<S1>/time constant' */
    buck_converter_w_feedback_B.timeconstant =
      buck_converter_w_feedback_P.timeconstant_Gain * rtb_Sum;
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Switch: '<S2>/Switch1'
   */
  if (buck_converter_w_feedback_X.Integrator_CSTATE >
      buck_converter_w_feedback_P.Switch_Threshold_g) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    buck_converter_w_feedback_B.Switch_n =
      buck_converter_w_feedback_P.Constant1_Value_m;
  } else if (buck_converter_w_feedback_X.Integrator_CSTATE >
             buck_converter_w_feedback_P.Switch1_Threshold) {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Switch: '<S2>/Switch'
     */
    buck_converter_w_feedback_B.Switch_n =
      buck_converter_w_feedback_B.timeconstant;
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     */
    buck_converter_w_feedback_B.Switch_n =
      buck_converter_w_feedback_P.Constant_Value_o;
  }

  /* End of Switch: '<S2>/Switch' */
  if (rtmIsMajorTimeStep(buck_converter_w_feedback_M)) {
    rt_ertODEUpdateContinuousStates(&buck_converter_w_feedback_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++buck_converter_w_feedback_M->Timing.clockTick0)) {
      ++buck_converter_w_feedback_M->Timing.clockTickH0;
    }

    buck_converter_w_feedback_M->Timing.t[0] = rtsiGetSolverStopTime
      (&buck_converter_w_feedback_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      buck_converter_w_feedback_M->Timing.clockTick1++;
      if (!buck_converter_w_feedback_M->Timing.clockTick1) {
        buck_converter_w_feedback_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void buck_converter_w_feedback_derivatives(void)
{
  XDot_buck_converter_w_feedbac_T *_rtXdot;
  _rtXdot = ((XDot_buck_converter_w_feedbac_T *)
             buck_converter_w_feedback_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = buck_converter_w_feedback_B.Switch_n;
}

/* Model initialize function */
void buck_converter_w_feedback_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)buck_converter_w_feedback_M, 0,
                sizeof(RT_MODEL_buck_converter_w_fee_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&buck_converter_w_feedback_M->solverInfo,
                          &buck_converter_w_feedback_M->Timing.simTimeStep);
    rtsiSetTPtr(&buck_converter_w_feedback_M->solverInfo, &rtmGetTPtr
                (buck_converter_w_feedback_M));
    rtsiSetStepSizePtr(&buck_converter_w_feedback_M->solverInfo,
                       &buck_converter_w_feedback_M->Timing.stepSize0);
    rtsiSetdXPtr(&buck_converter_w_feedback_M->solverInfo,
                 &buck_converter_w_feedback_M->derivs);
    rtsiSetContStatesPtr(&buck_converter_w_feedback_M->solverInfo, (real_T **)
                         &buck_converter_w_feedback_M->contStates);
    rtsiSetNumContStatesPtr(&buck_converter_w_feedback_M->solverInfo,
      &buck_converter_w_feedback_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&buck_converter_w_feedback_M->solverInfo,
      &buck_converter_w_feedback_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&buck_converter_w_feedback_M->solverInfo,
      &buck_converter_w_feedback_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&buck_converter_w_feedback_M->solverInfo,
      &buck_converter_w_feedback_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&buck_converter_w_feedback_M->solverInfo,
      (boolean_T**) &buck_converter_w_feedback_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&buck_converter_w_feedback_M->solverInfo,
                          (&rtmGetErrorStatus(buck_converter_w_feedback_M)));
    rtsiSetRTModelPtr(&buck_converter_w_feedback_M->solverInfo,
                      buck_converter_w_feedback_M);
  }

  rtsiSetSimTimeStep(&buck_converter_w_feedback_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&buck_converter_w_feedback_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&buck_converter_w_feedback_M->solverInfo, false);
  buck_converter_w_feedback_M->intgData.y = buck_converter_w_feedback_M->odeY;
  buck_converter_w_feedback_M->intgData.f[0] = buck_converter_w_feedback_M->
    odeF[0];
  buck_converter_w_feedback_M->intgData.f[1] = buck_converter_w_feedback_M->
    odeF[1];
  buck_converter_w_feedback_M->intgData.f[2] = buck_converter_w_feedback_M->
    odeF[2];
  buck_converter_w_feedback_M->contStates = ((X_buck_converter_w_feedback_T *)
    &buck_converter_w_feedback_X);
  buck_converter_w_feedback_M->contStateDisabled =
    ((XDis_buck_converter_w_feedbac_T *) &buck_converter_w_feedback_XDis);
  buck_converter_w_feedback_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&buck_converter_w_feedback_M->solverInfo, (void *)
                    &buck_converter_w_feedback_M->intgData);
  rtsiSetSolverName(&buck_converter_w_feedback_M->solverInfo,"ode3");
  rtmSetTPtr(buck_converter_w_feedback_M,
             &buck_converter_w_feedback_M->Timing.tArray[0]);
  buck_converter_w_feedback_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &buck_converter_w_feedback_B), 0,
                sizeof(B_buck_converter_w_feedback_T));

  /* states (continuous) */
  {
    (void) memset((void *)&buck_converter_w_feedback_X, 0,
                  sizeof(X_buck_converter_w_feedback_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&buck_converter_w_feedback_XDis, 0,
                  sizeof(XDis_buck_converter_w_feedbac_T));
  }

  /* states (dwork) */
  (void) memset((void *)&buck_converter_w_feedback_DW, 0,
                sizeof(DW_buck_converter_w_feedback_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  buck_converter_w_feedback_DW.obj_l.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_DW.objisempty_d = true;
  buck_converter_w_feedback_DW.obj_l.isInitialized = 1;
  buck_converter_w_feedback_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(26U);
  buck_converter_w_feedback_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  buck_converter_w_feedback_DW.obj.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_DW.objisempty_p = true;
  buck_converter_w_feedback_DW.obj.isInitialized = 1;
  digitalIOSetup(25, 1);
  buck_converter_w_feedback_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  buck_converter_w_feedback_DW.obj_h.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_DW.objisempty = true;
  buck_converter_w_feedback_DW.obj_h.isInitialized = 1;
  buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (16U, 0.0, 0.0);
  buck_converter_w_feedback_DW.obj_h.isSetupComplete = true;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  buck_converter_w_feedback_X.Integrator_CSTATE =
    buck_converter_w_feedback_P.Integrator_IC;
}

/* Model terminate function */
void buck_converter_w_feedback_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!buck_converter_w_feedback_DW.obj_l.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((buck_converter_w_feedback_DW.obj_l.isInitialized == 1) &&
        buck_converter_w_feedback_DW.obj_l.isSetupComplete) {
      buck_converter_w_feedback_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(26U);
      MW_AnalogIn_Close
        (buck_converter_w_feedback_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!buck_converter_w_feedback_DW.obj.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!buck_converter_w_feedback_DW.obj_h.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((buck_converter_w_feedback_DW.obj_h.isInitialized == 1) &&
        buck_converter_w_feedback_DW.obj_h.isSetupComplete) {
      buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle
        (buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(16U);
      MW_PWM_Close(buck_converter_w_feedback_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
