#include "buck_converter_w_feedback.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  buck_converter_w_feedback_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.001;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  MW_Arduino_Init();
  rtmSetErrorStatus(buck_converter_w_feedback_M, 0);
  buck_converter_w_feedback_initialize();
  noInterrupts();
  configureArduinoARM_M0plus_RP2040_Alarm();
  runModel =
    rtmGetErrorStatus(buck_converter_w_feedback_M) == (NULL)&&
    !rtmGetStopRequested(buck_converter_w_feedback_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(buck_converter_w_feedback_M) == (NULL)&&
                      !rtmGetStopRequested(buck_converter_w_feedback_M));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  buck_converter_w_feedback_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
