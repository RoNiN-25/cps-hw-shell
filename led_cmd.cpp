#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "led_cmd.h"
#include "util.h"

int current_led_color = 0;
void change_led_color(char **cmd_strings, char* return_data) {
  char* number = *(cmd_strings+1);
  int n = atoi(number);
  if (n >= 0 && n <= 7) {
    current_led_color = n;
    set_led_color(current_led_color);
  } else {
    strcpy(return_data, "Invalid input\n Input Must be between 0 to 7");
    return;
  }
  strcpy(return_data, "OK");
}

extern void show_help_color(char **cmd_strings, char* return_data) {
  const char* help_text = "sw [n] \t - prints the state of the switch SWn. n can be 1 or 2";
  strcpy(return_data, help_text);
}
