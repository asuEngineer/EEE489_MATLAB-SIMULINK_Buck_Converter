/*
 * buck_converter.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter".
 *
 * Model version              : 1.2
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Feb 21 13:32:16 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buck_converter.h"
#include "rtwtypes.h"
#include <string.h>

/* Block states (default storage) */
DW_buck_converter_T buck_converter_DW;

/* Real-time model */
static RT_MODEL_buck_converter_T buck_converter_M_;
RT_MODEL_buck_converter_T *const buck_converter_M = &buck_converter_M_;

/* Model step function */
void buck_converter_step(void)
{
  real_T u0;
  uint16_T rtb_AnalogInput;

  /* MATLABSystem: '<Root>/PWM' */
  buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);

  /* Start for MATLABSystem: '<Root>/PWM' incorporates:
   *  Constant: '<Root>/Duty Cycle'
   *  Gain: '<Root>/max input reference'
   */
  u0 = buck_converter_P.maxinputreference_Gain *
    buck_converter_P.DutyCycle_Value;
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle(buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<Root>/Analog Input' */
  buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(26U);
  MW_AnalogInSingle_ReadResult
    (buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_AnalogInput, MW_ANALOGIN_UINT16);
}

/* Model initialize function */
void buck_converter_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(buck_converter_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&buck_converter_DW, 0,
                sizeof(DW_buck_converter_T));

  /* Start for MATLABSystem: '<Root>/PWM' */
  buck_converter_DW.obj_h.matlabCodegenIsDeleted = false;
  buck_converter_DW.objisempty = true;
  buck_converter_DW.obj_h.isInitialized = 1;
  buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
  buck_converter_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  buck_converter_DW.obj.matlabCodegenIsDeleted = false;
  buck_converter_DW.objisempty_d = true;
  buck_converter_DW.obj.isInitialized = 1;
  buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(26U);
  buck_converter_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void buck_converter_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!buck_converter_DW.obj_h.matlabCodegenIsDeleted) {
    buck_converter_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((buck_converter_DW.obj_h.isInitialized == 1) &&
        buck_converter_DW.obj_h.isSetupComplete) {
      buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_SetDutyCycle(buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(16U);
      MW_PWM_Close(buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!buck_converter_DW.obj.matlabCodegenIsDeleted) {
    buck_converter_DW.obj.matlabCodegenIsDeleted = true;
    if ((buck_converter_DW.obj.isInitialized == 1) &&
        buck_converter_DW.obj.isSetupComplete) {
      buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(26U);
      MW_AnalogIn_Close
        (buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}
