/*
 * buck_converter_w_feedback_alternative_private.h
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

#ifndef buck_converter_w_feedback_alternative_private_h_
#define buck_converter_w_feedback_alternative_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "buck_converter_w_feedback_alternative.h"
#include "buck_converter_w_feedback_alternative_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void buck_co_IfActionSubsystem1_Init(B_IfActionSubsystem1_buck_con_T
  *localB, P_IfActionSubsystem1_buck_con_T *localP);
extern void buck_convert_IfActionSubsystem1(real_T rtu_In1,
  B_IfActionSubsystem1_buck_con_T *localB);

#endif                    /* buck_converter_w_feedback_alternative_private_h_ */
