/*
 * buck_converter.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Mar  7 11:59:27 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buck_converter.h"
#include "rtwtypes.h"
#include "buck_converter_private.h"
#include <string.h>

/* Block signals (default storage) */
B_buck_converter_T buck_converter_B;

/* Block states (default storage) */
DW_buck_converter_T buck_converter_DW;

/* Real-time model */
static RT_MODEL_buck_converter_T buck_converter_M_;
RT_MODEL_buck_converter_T *const buck_converter_M = &buck_converter_M_;

/* Model step function */
void buck_converter_step(void)
{
  real_T u0;

  /* MATLABSystem: '<Root>/Analog Input' */
  buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(28U);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult
    (buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &buck_converter_B.AnalogInput, MW_ANALOGIN_UINT16);

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

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++buck_converter_M->Timing.clockTick0)) {
    ++buck_converter_M->Timing.clockTickH0;
  }

  buck_converter_M->Timing.taskTime0 = buck_converter_M->Timing.clockTick0 *
    buck_converter_M->Timing.stepSize0 + buck_converter_M->Timing.clockTickH0 *
    buck_converter_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void buck_converter_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)buck_converter_M, 0,
                sizeof(RT_MODEL_buck_converter_T));
  rtmSetTFinal(buck_converter_M, -1);
  buck_converter_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  buck_converter_M->Sizes.checksums[0] = (289302665U);
  buck_converter_M->Sizes.checksums[1] = (1504350322U);
  buck_converter_M->Sizes.checksums[2] = (2108105063U);
  buck_converter_M->Sizes.checksums[3] = (3882135555U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    buck_converter_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(buck_converter_M->extModeInfo,
      &buck_converter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(buck_converter_M->extModeInfo,
                        buck_converter_M->Sizes.checksums);
    rteiSetTPtr(buck_converter_M->extModeInfo, rtmGetTPtr(buck_converter_M));
  }

  /* block I/O */
  (void) memset(((void *) &buck_converter_B), 0,
                sizeof(B_buck_converter_T));

  /* states (dwork) */
  (void) memset((void *)&buck_converter_DW, 0,
                sizeof(DW_buck_converter_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  buck_converter_DW.obj.matlabCodegenIsDeleted = false;
  buck_converter_DW.objisempty_d = true;
  buck_converter_DW.obj.isInitialized = 1;
  buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(28U);
  buck_converter_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  buck_converter_DW.obj_h.matlabCodegenIsDeleted = false;
  buck_converter_DW.objisempty = true;
  buck_converter_DW.obj_h.isInitialized = 1;
  buck_converter_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(16U, 0.0, 0.0);
  buck_converter_DW.obj_h.isSetupComplete = true;
}

/* Model terminate function */
void buck_converter_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!buck_converter_DW.obj.matlabCodegenIsDeleted) {
    buck_converter_DW.obj.matlabCodegenIsDeleted = true;
    if ((buck_converter_DW.obj.isInitialized == 1) &&
        buck_converter_DW.obj.isSetupComplete) {
      buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(28U);
      MW_AnalogIn_Close
        (buck_converter_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

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
}
