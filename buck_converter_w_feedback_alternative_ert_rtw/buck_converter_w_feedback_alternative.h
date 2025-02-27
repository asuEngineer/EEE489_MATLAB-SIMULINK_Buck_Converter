/*
 * buck_converter_w_feedback_alternative.h
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

#ifndef buck_converter_w_feedback_alternative_h_
#define buck_converter_w_feedback_alternative_h_
#ifndef buck_converter_w_feedback_alternative_COMMON_INCLUDES_
#define buck_converter_w_feedback_alternative_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif              /* buck_converter_w_feedback_alternative_COMMON_INCLUDES_ */

#include "buck_converter_w_feedback_alternative_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define buck_converter_w_feedback_alternative_M (buck_converter_w_feedback_al_M)

/* Block signals for system '<S1>/If Action Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S4>/In1' */
} B_IfActionSubsystem1_buck_con_T;

/* Block states (default storage) for system '<S1>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S1>/If Action Subsystem1' */
} DW_IfActionSubsystem1_buck_co_T;

/* Block signals (default storage) */
typedef struct {
  real_T conversiontodutycycle;        /* '<S1>/conversion to duty cycle' */
  real_T Multiply;                     /* '<S1>/Multiply' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T Switch;                       /* '<S1>/Switch' */
  uint16_T AnalogInput;                /* '<Root>/Analog Input' */
  B_IfActionSubsystem1_buck_con_T IfActionSubsystem;/* '<S1>/If Action Subsystem' */
  B_IfActionSubsystem1_buck_con_T IfActionSubsystem1;/* '<S1>/If Action Subsystem1' */
} B_buck_converter_w_feedback_a_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input' */
  codertarget_arduinobase_int_o_T obj_h;/* '<Root>/PWM' */
  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_p;              /* '<Root>/Digital Output' */
  boolean_T objisempty_d;              /* '<Root>/Analog Input' */
  DW_IfActionSubsystem1_buck_co_T IfActionSubsystem;/* '<S1>/If Action Subsystem' */
  DW_IfActionSubsystem1_buck_co_T IfActionSubsystem1;/* '<S1>/If Action Subsystem1' */
} DW_buck_converter_w_feedback__T;

/* Parameters for system: '<S1>/If Action Subsystem1' */
struct P_IfActionSubsystem1_buck_con_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_buck_converter_w_feedback_a_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T whatwewantasoutput_Value;     /* Expression: 5
                                        * Referenced by: '<Root>/what we want as output'
                                        */
  real_T conversiontodutycycle_Gain;   /* Expression: .072
                                        * Referenced by: '<S1>/conversion to duty cycle'
                                        */
  real_T Constant3_Value;              /* Expression: 4095
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Multiply_Gain;                /* Expression: .303
                                        * Referenced by: '<S1>/Multiply'
                                        */
  real_T Constant2_Value;              /* Expression: 0.02
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0.02
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T dutycycletodigitalout_Gain;   /* Expression: 255
                                        * Referenced by: '<Root>/duty cycle to digital out'
                                        */
  P_IfActionSubsystem1_buck_con_T IfActionSubsystem;/* '<S1>/If Action Subsystem' */
  P_IfActionSubsystem1_buck_con_T IfActionSubsystem1;/* '<S1>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_buck_converter_w_feed_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_buck_converter_w_feedback_a_T buck_converter_w_feedback_alt_P;

/* Block signals (default storage) */
extern B_buck_converter_w_feedback_a_T buck_converter_w_feedback_alt_B;

/* Block states (default storage) */
extern DW_buck_converter_w_feedback__T buck_converter_w_feedback_al_DW;

/* Model entry point functions */
extern void buck_converter_w_feedback_alternative_initialize(void);
extern void buck_converter_w_feedback_alternative_step(void);
extern void buck_converter_w_feedback_alternative_terminate(void);

/* Real-time Model object */
extern RT_MODEL_buck_converter_w_fee_T *const buck_converter_w_feedback_al_M;
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
 * '<Root>' : 'buck_converter_w_feedback_alternative'
 * '<S1>'   : 'buck_converter_w_feedback_alternative/C'
 * '<S2>'   : 'buck_converter_w_feedback_alternative/C/Compare To Zero'
 * '<S3>'   : 'buck_converter_w_feedback_alternative/C/If Action Subsystem'
 * '<S4>'   : 'buck_converter_w_feedback_alternative/C/If Action Subsystem1'
 */
#endif                            /* buck_converter_w_feedback_alternative_h_ */
