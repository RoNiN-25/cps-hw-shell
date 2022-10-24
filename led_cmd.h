#ifndef LED_CMD_H_
#define LED_CMD_H_

extern void change_led_color(char **cmd_strings, char* return_data);
extern void show_help_color(char **cmd_strings, char* return_data);

extern int current_led_color;

#endif // LED_CMD_H_
