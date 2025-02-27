/*
 * buck_converter_w_feedback_alternative.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter_w_feedback_alternative".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed Feb 26 19:36:49 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buck_converter_w_feedback_alternative.h"
#include "rtwtypes.h"
#include "buck_converter_w_feedback_alternative_private.h"
#include <string.h>
#include <math.h>

/* Block signals (default storage) */
B_buck_converter_w_feedback_a_T buck_converter_w_feedback_alt_B;

/* Block states (default storage) */
DW_buck_converter_w_feedback__T buck_converter_w_feedback_al_DW;

/* Real-time model */
static RT_MODEL_buck_converter_w_fee_T buck_converter_w_feedback_al_M_;
RT_MODEL_buck_converter_w_fee_T *const buck_converter_w_feedback_al_M =
  &buck_converter_w_feedback_al_M_;

/*
 * System initialize for action system:
 *    '<S1>/If Action Subsystem1'
 *    '<S1>/If Action Subsystem'
 */
void buck_co_IfActionSubsystem1_Init(B_IfActionSubsystem1_buck_con_T *localB,
  P_IfActionSubsystem1_buck_con_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
   *  Outport: '<S4>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem1'
 *    '<S1>/If Action Subsystem'
 */
void buck_convert_IfActionSubsystem1(real_T rtu_In1,
  B_IfActionSubsystem1_buck_con_T *localB)
{
  /* SignalConversion generated from: '<S4>/In1' */
  localB->In1 = rtu_In1;
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
void buck_converter_w_feedback_alternative_step(void)
{
  real_T u0;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (buck_converter_w_feedback_al_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<S1>/Constant'
   */
  u0 = rt_roundd_snf(buck_converter_w_feedback_alt_P.Constant_Value_p);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(25, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* Gain: '<S1>/conversion to duty cycle' incorporates:
   *  Constant: '<Root>/what we want as output'
   */
  buck_converter_w_feedback_alt_B.conversiontodutycycle =
    buck_converter_w_feedback_alt_P.conversiontodutycycle_Gain *
    buck_converter_w_feedback_alt_P.whatwewantasoutput_Value;

  /* MATLABSystem: '<Root>/Analog Input' */
  buck_converter_w_feedback_al_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(28U);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (buck_converter_w_feedback_al_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &buck_converter_w_feedback_alt_B.AnalogInput, MW_ANALOGIN_UINT16);

  /* Gain: '<S1>/Multiply' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Product: '<S1>/Divide'
   */
  buck_converter_w_feedback_alt_B.Multiply = (real_T)
    buck_converter_w_feedback_alt_B.AnalogInput /
    buck_converter_w_feedback_alt_P.Constant3_Value *
    buck_converter_w_feedback_alt_P.Multiply_Gain;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   */
  if (buck_converter_w_feedback_alt_B.conversiontodutycycle >
      buck_converter_w_feedback_alt_B.Multiply) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    buck_convert_IfActionSubsystem1
      (buck_converter_w_feedback_alt_P.Constant2_Value +
       buck_converter_w_feedback_alt_B.Multiply,
       &buck_converter_w_feedback_alt_B.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
  } else if (buck_converter_w_feedback_alt_B.Multiply >
             buck_converter_w_feedback_alt_B.conversiontodutycycle) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    buck_convert_IfActionSubsystem1(buck_converter_w_feedback_alt_B.Multiply -
      buck_converter_w_feedback_alt_P.Constant1_Value,
      &buck_converter_w_feedback_alt_B.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  }

  /* End of If: '<S1>/If' */

  /* Sum: '<S1>/Sum2' */
  buck_converter_w_feedback_alt_B.Sum2 =
    buck_converter_w_feedback_alt_B.conversiontodutycycle -
    buck_converter_w_feedback_alt_B.Multiply;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   */
  if (buck_converter_w_feedback_alt_B.Sum2 <
      buck_converter_w_feedback_alt_P.Constant_Value) {
    /* Switch: '<S1>/Switch' */
    buck_converter_w_feedback_alt_B.Switch =
      buck_converter_w_feedback_alt_B.IfActionSubsystem.In1;
  } else {
    /* Switch: '<S1>/Switch' */
    buck_converter_w_feedback_alt_B.Switch =
      buck_converter_w_feedback_alt_B.IfActionSubsystem1.In1;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<Root>/PWM' */
  buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(16U);

  /* Gain: '<Root>/duty cycle to digital out' */
  u0 = buck_converter_w_feedback_alt_P.dutycycletodigitalout_Gain *
    buck_converter_w_feedback_alt_B.Switch;

  /* Start for MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle
    (buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++buck_converter_w_feedback_al_M->Timing.clockTick0)) {
    ++buck_converter_w_feedback_al_M->Timing.clockTickH0;
  }

  buck_converter_w_feedback_al_M->Timing.taskTime0 =
    buck_converter_w_feedback_al_M->Timing.clockTick0 *
    buck_converter_w_feedback_al_M->Timing.stepSize0 +
    buck_converter_w_feedback_al_M->Timing.clockTickH0 *
    buck_converter_w_feedback_al_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void buck_converter_w_feedback_alternative_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)buck_converter_w_feedback_al_M, 0,
                sizeof(RT_MODEL_buck_converter_w_fee_T));
  rtmSetTFinal(buck_converter_w_feedback_al_M, -1);
  buck_converter_w_feedback_al_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  buck_converter_w_feedback_al_M->Sizes.checksums[0] = (2768697319U);
  buck_converter_w_feedback_al_M->Sizes.checksums[1] = (1656497221U);
  buck_converter_w_feedback_al_M->Sizes.checksums[2] = (968314831U);
  buck_converter_w_feedback_al_M->Sizes.checksums[3] = (247273834U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    buck_converter_w_feedback_al_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &buck_converter_w_feedback_al_DW.IfActionSubsystem.IfActionSubsystem1_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &buck_converter_w_feedback_al_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(buck_converter_w_feedback_al_M->extModeInfo,
      &buck_converter_w_feedback_al_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(buck_converter_w_feedback_al_M->extModeInfo,
                        buck_converter_w_feedback_al_M->Sizes.checksums);
    rteiSetTPtr(buck_converter_w_feedback_al_M->extModeInfo, rtmGetTPtr
                (buck_converter_w_feedback_al_M));
  }

  /* block I/O */
  (void) memset(((void *) &buck_converter_w_feedback_alt_B), 0,
                sizeof(B_buck_converter_w_feedback_a_T));

  /* states (dwork) */
  (void) memset((void *)&buck_converter_w_feedback_al_DW, 0,
                sizeof(DW_buck_converter_w_feedback__T));

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  buck_converter_w_feedback_al_DW.obj.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_al_DW.objisempty_p = true;
  buck_converter_w_feedback_al_DW.obj.isInitialized = 1;
  digitalIOSetup(25, 1);
  buck_converter_w_feedback_al_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  buck_converter_w_feedback_al_DW.obj_l.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_al_DW.objisempty_d = true;
  buck_converter_w_feedback_al_DW.obj_l.isInitialized = 1;
  buck_converter_w_feedback_al_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(28U);
  buck_converter_w_feedback_al_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  buck_converter_w_feedback_al_DW.obj_h.matlabCodegenIsDeleted = false;
  buck_converter_w_feedback_al_DW.objisempty = true;
  buck_converter_w_feedback_al_DW.obj_h.isInitialized = 1;
  buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (16U, 0.0, 0.0);
  buck_converter_w_feedback_al_DW.obj_h.isSetupComplete = true;

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem1' */
  buck_co_IfActionSubsystem1_Init
    (&buck_converter_w_feedback_alt_B.IfActionSubsystem1,
     &buck_converter_w_feedback_alt_P.IfActionSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem1' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem' */
  buck_co_IfActionSubsystem1_Init
    (&buck_converter_w_feedback_alt_B.IfActionSubsystem,
     &buck_converter_w_feedback_alt_P.IfActionSubsystem);

  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem' */
}

/* Model terminate function */
void buck_converter_w_feedback_alternative_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!buck_converter_w_feedback_al_DW.obj.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_al_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!buck_converter_w_feedback_al_DW.obj_l.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_al_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((buck_converter_w_feedback_al_DW.obj_l.isInitialized == 1) &&
        buck_converter_w_feedback_al_DW.obj_l.isSetupComplete) {
      buck_converter_w_feedback_al_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(28U);
      MW_AnalogIn_Close
        (buck_converter_w_feedback_al_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!buck_converter_w_feedback_al_DW.obj_h.matlabCodegenIsDeleted) {
    buck_converter_w_feedback_al_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((buck_converter_w_feedback_al_DW.obj_h.isInitialized == 1) &&
        buck_converter_w_feedback_al_DW.obj_h.isSetupComplete) {
      buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle
        (buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(16U);
      MW_PWM_Close
        (buck_converter_w_feedback_al_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
