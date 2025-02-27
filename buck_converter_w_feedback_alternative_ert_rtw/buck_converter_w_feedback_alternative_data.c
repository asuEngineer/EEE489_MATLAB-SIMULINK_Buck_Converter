/*
 * buck_converter_w_feedback_alternative_data.c
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

/* Block parameters (default storage) */
P_buck_converter_w_feedback_a_T buck_converter_w_feedback_alt_P = {
  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/what we want as output'
   */
  5.0,

  /* Expression: .072
   * Referenced by: '<S1>/conversion to duty cycle'
   */
  0.072,

  /* Expression: 4095
   * Referenced by: '<S1>/Constant3'
   */
  4095.0,

  /* Expression: .303
   * Referenced by: '<S1>/Multiply'
   */
  0.303,

  /* Expression: 0.02
   * Referenced by: '<S1>/Constant2'
   */
  0.02,

  /* Expression: 0.02
   * Referenced by: '<S1>/Constant1'
   */
  0.02,

  /* Expression: 255
   * Referenced by: '<Root>/duty cycle to digital out'
   */
  255.0,

  /* Start of '<S1>/If Action Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S3>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S1>/If Action Subsystem' */

  /* Start of '<S1>/If Action Subsystem1' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S4>/Out1'
     */
    0.0
  }
  /* End of '<S1>/If Action Subsystem1' */
};
