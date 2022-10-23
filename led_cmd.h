#ifndef LED_CMD_H_
#define LED_CMD_H_

#define RED_LED 30
#define BLUE_LED 40
#define GREEN_LED 39

extern void set_led_color(char **cmd_strings, char* return_data);
extern void show_help(char **cmd_strings, char* return_data);

#endif // LED_CMD_H_
