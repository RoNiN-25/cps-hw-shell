#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "motor_cmd.h"

void init_motors() {
  pinMode(L_MOTOR_PWM_PIN, OUTPUT);
  pinMode(L_MOTOR_DIR_PIN, OUTPUT);
  pinMode(L_MOTOR_SLEEP_PIN, OUTPUT);
  
  pinMode(R_MOTOR_PWM_PIN, OUTPUT);
  pinMode(L_MOTOR_DIR_PIN, OUTPUT);
  pinMode(R_MOTOR_SLEEP_PIN, OUTPUT);
}

void set_motor_speed(char **cmd_strings, char* return_data) {
  char* motor = *(cmd_strings+1); // motor L or R
  char* percentage = *(cmd_strings+2); // speed percent
  int p = atoi(percentage);
  int pwm = (int) (p*255);
  if(strcmp(motor, "L")) {
    // set left motor speed
    if (pwm == 0) {
      analogWrite(L_MOTOR_PWM_PIN, 0);
      digitalWrite(L_MOTOR_DIR_PIN, HIGH);
      digitalWrite(L_MOTOR_SLEEP_PIN, LOW);  // give complement sleep to turn off motors
    } else if(pwm > 0 && pwm <= 255)  {
      analogWrite(L_MOTOR_PWM_PIN, pwm);
      digitalWrite(L_MOTOR_DIR_PIN, HIGH);
      digitalWrite(L_MOTOR_SLEEP_PIN, HIGH);
    } else {
      strcpy(return_data, "Invalid speed percentage\nPercentage must be between 0 and 100");
      return;
    }
  } else if(strcmp(motor, "R")) {
    // set right motor speed
    if (pwm == 0) {
      analogWrite(R_MOTOR_PWM_PIN, 0);
      digitalWrite(R_MOTOR_DIR_PIN, HIGH);
      digitalWrite(R_MOTOR_SLEEP_PIN, LOW);  // give complement sleep to turn off motors
    } else if(pwm > 0 && pwm <= 255)  {
      analogWrite(R_MOTOR_PWM_PIN, pwm);
      digitalWrite(R_MOTOR_DIR_PIN, HIGH);
      digitalWrite(R_MOTOR_SLEEP_PIN, HIGH);
    } else {
      strcpy(return_data, "Invalid speed percentage\nPercentage must be between 0 and 100");
      return;
    }
  } else {
    strcpy(return_data, "Invalid motor choice\n Motor choice Must be L or R");
    return;
  }
  strcpy(return_data, "OK");
}


void show_help_motor(char **cmd_strings, char* return_data) {
  const char* help_text = "motor [choice] [percent] \t - Sets the speed of the motor. choice is L or R. percent is between 0 to 100";
  strcpy(return_data, help_text);
}
