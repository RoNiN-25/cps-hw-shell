#ifndef UTIL_H_
#define UTIL_H_

#define RED_LED 30
#define BLUE_LED 40
#define GREEN_LED 39
#define SW1 31
#define SW2 17

extern void get_cmd_strings(char* cmd,  char** cmd_strings);
extern void disp_help(char **cmd_strings, char* return_data);
extern void set_led_color(int n);

extern int MAX_ARG;

#endif // UTIL_H_
