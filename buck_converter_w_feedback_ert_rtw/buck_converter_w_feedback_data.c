/*
 * buck_converter_w_feedback_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "buck_converter_w_feedback".
 *
 * Model version              : 1.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Mar  7 16:17:32 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "buck_converter_w_feedback.h"

/* Block parameters (default storage) */
P_buck_converter_w_feedback_T buck_converter_w_feedback_P = {
  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Integrator'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Switch'
   */
  1.0,

  /* Expression: 255
   * Referenced by: '<Root>/duty cycle to digital out'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Switch'
   */
  1.0,

  /* Computed Parameter: Vref_Value
   * Referenced by: '<Root>/Vref'
   */
  5.0F,

  /* Computed Parameter: Switch1_Threshold_a
   * Referenced by: '<S1>/Switch1'
   */
  0.0F,

  /* Computed Parameter: Vtimeconstant_Gain
   * Referenced by: '<S1>/V time constant'
   */
  0.5F,

  /* Computed Parameter: VoutDtoA_Gain
   * Referenced by: '<Root>/Vout D to A'
   */
  63579U
};
