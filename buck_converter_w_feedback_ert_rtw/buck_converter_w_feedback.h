/*
 * buck_converter_w_feedback.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter_w_feedback".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed Feb 26 20:06:48 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef buck_converter_w_feedback_h_
#define buck_converter_w_feedback_h_
#ifndef buck_converter_w_feedback_COMMON_INCLUDES_
#define buck_converter_w_feedback_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                          /* buck_converter_w_feedback_COMMON_INCLUDES_ */

#include "buck_converter_w_feedback_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Switch;                       /* '<S3>/Switch' */
  real_T Integrator1;                  /* '<S1>/Integrator1' */
  real_T Subtract;                     /* '<S1>/Subtract' */
  real_T Switch_n;                     /* '<S2>/Switch' */
  uint32_T digitalintoerr;             /* '<Root>/digital in to err' */
  real32_T Sum;                        /* '<S1>/Sum' */
  real32_T timeconstant;               /* '<S1>/time constant' */
} B_buck_converter_w_feedback_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input' */
  codertarget_arduinobase_int_i_T obj_h;/* '<Root>/PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_p;              /* '<Root>/Digital Output' */
  boolean_T objisempty_d;              /* '<Root>/Analog Input' */
} DW_buck_converter_w_feedback_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
} X_buck_converter_w_feedback_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
} XDot_buck_converter_w_feedbac_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
} XDis_buck_converter_w_feedbac_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_buck_converter_w_feedback_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch1'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S3>/Switch1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Integrator_IC;                /* Expression: 0.5
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T dutycycletodigitalout_Gain;   /* Expression: 255
                                        * Referenced by: '<Root>/duty cycle to digital out'
                                        */
  real_T Integrator1_IC;               /* Expression: 0.5
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 1
                                        * Referenced by: '<S2>/Switch'
                                        */
  real32_T Vref_Value;                 /* Computed Parameter: Vref_Value
                                        * Referenced by: '<Root>/Vref'
                                        */
  real32_T Switch1_Threshold_a;       /* Computed Parameter: Switch1_Threshold_a
                                       * Referenced by: '<S1>/Switch1'
                                       */
  real32_T timeconstant_Gain;          /* Computed Parameter: timeconstant_Gain
                                        * Referenced by: '<S1>/time constant'
                                        */
  uint16_T digitalintoerr_Gain;       /* Computed Parameter: digitalintoerr_Gain
                                       * Referenced by: '<Root>/digital in to err'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_buck_converter_w_feed_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_buck_converter_w_feedback_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_buck_converter_w_feedbac_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[4][2];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_buck_converter_w_feedback_T buck_converter_w_feedback_P;

/* Block signals (default storage) */
extern B_buck_converter_w_feedback_T buck_converter_w_feedback_B;

/* Continuous states (default storage) */
extern X_buck_converter_w_feedback_T buck_converter_w_feedback_X;

/* Disabled states (default storage) */
extern XDis_buck_converter_w_feedbac_T buck_converter_w_feedback_XDis;

/* Block states (default storage) */
extern DW_buck_converter_w_feedback_T buck_converter_w_feedback_DW;

/* Model entry point functions */
extern void buck_converter_w_feedback_initialize(void);
extern void buck_converter_w_feedback_step(void);
extern void buck_converter_w_feedback_terminate(void);

/* Real-time Model object */
extern RT_MODEL_buck_converter_w_fee_T *const buck_converter_w_feedback_M;
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
 * '<Root>' : 'buck_converter_w_feedback'
 * '<S1>'   : 'buck_converter_w_feedback/C'
 * '<S2>'   : 'buck_converter_w_feedback/C/pass 0-1 (in)'
 * '<S3>'   : 'buck_converter_w_feedback/C/pass 0-1 (out)'
 */
#endif                                 /* buck_converter_w_feedback_h_ */
