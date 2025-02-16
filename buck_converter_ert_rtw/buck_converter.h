/*
 * buck_converter.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter".
 *
 * Model version              : 1.0
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun Feb 16 13:39:35 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef buck_converter_h_
#define buck_converter_h_
#ifndef buck_converter_COMMON_INCLUDES_
#define buck_converter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* buck_converter_COMMON_INCLUDES_ */

#include "buck_converter_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_int_m_T obj_h;/* '<Root>/PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_d;              /* '<Root>/Analog Input' */
} DW_buck_converter_T;

/* Parameters (default storage) */
struct P_buck_converter_T_ {
  real32_T DutyCycle_Value;            /* Computed Parameter: DutyCycle_Value
                                        * Referenced by: '<Root>/Duty Cycle'
                                        */
  real32_T maxinputreference_Gain; /* Computed Parameter: maxinputreference_Gain
                                    * Referenced by: '<Root>/max input reference'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_buck_converter_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_buck_converter_T buck_converter_P;

/* Block states (default storage) */
extern DW_buck_converter_T buck_converter_DW;

/* Model entry point functions */
extern void buck_converter_initialize(void);
extern void buck_converter_step(void);
extern void buck_converter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_buck_converter_T *const buck_converter_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'buck_converter'
 * '<S1>'   : 'buck_converter/Subsystem'
 */
#endif                                 /* buck_converter_h_ */
