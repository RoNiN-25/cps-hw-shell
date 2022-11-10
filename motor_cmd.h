#ifndef MOTOR_CMD_H_
#define MOTOR_CMD_H_

#define L_MOTOR_SLEEP_PIN 38    // PB_3
#define L_MOTOR_DIR_PIN 37      // PC_4
#define L_MOTOR_PWM_PIN 36      // PC_5
#define R_MOTOR_SLEEP_PIN 35    // PC_6
#define R_MOTOR_DIR_PIN 34      // PC_7
#define R_MOTOR_PWM_PIN 33      // PD_6


extern void set_motor_speed(char **cmd_strings, char* return_data);
extern void show_help_motor(char **cmd_strings, char* return_data);
extern void init_motors();

#endif // MOTOR_CMD_H_
