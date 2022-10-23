#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "blink_cmd.h"
#include "util.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

int red_led_state = LOW;

void blink_led(char **cmd_strings, char* return_data) {
  char* number = *(cmd_strings+1);
  int n = atoi(number);
  if (n > 0 && n <= 20) {
    start_timer(n*TICKS_1MS);
    strcpy(return_data, "OK");
  }
  else if (n == 0) {
    stop_timer();
    strcpy(return_data, "OK");
  }
  else
    strcpy(return_data, "Invalid Input\nn has to be between 0 to 20 only");
}

void start_timer(unsigned int delay_value) {
  stop_timer();
  // Load a timer value
  TimerLoadSet(TIMER4_BASE, TIMER_A, delay_value);
  // Enable the timer
  TimerEnable(TIMER4_BASE, TIMER_A);
}

void stop_timer() {
  // disable the timer
  TimerDisable(TIMER4_BASE, TIMER_A);
  digitalWrite(RED_LED, LOW);
}

void init_timer() {
  // Enable timer peripheral
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);  
  // Configure timer to generate peridic interrupts
  TimerConfigure(TIMER4_BASE, TIMER_CFG_PERIODIC);
  // Register an interrupt with the timer
  TimerIntRegister(TIMER4_BASE, TIMER_A, &timerIntHandler);
  // Enable interrupts for the timer
  TimerIntEnable(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
}

void timerIntHandler() {
  TimerIntClear(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
  digitalWrite(RED_LED, red_led_state);
  red_led_state = !red_led_state;
}

void show_help_blink(char **cmd_strings, char* return_data) {
  const char* help_text = "blink [n] \t - Blinks the red LED every n*0.1s. n can be between 0 to 20";
  strcpy(return_data, help_text);
}
