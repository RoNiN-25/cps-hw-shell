#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "sw_cmd.h"

void get_sw_state(char **cmd_strings, char* return_data) {
  char* number = *(cmd_strings+1);
  int n = atoi(number);
  switch(n) {
    case 1: {
      int state = digitalRead(SW1);
      state == 1 ? strcpy(return_data, "ON"): strcpy(return_data, "OFF");
    }
      break;
    case 2: {
      int state = digitalRead(SW2);
      state == 1 ? strcpy(return_data, "ON"): strcpy(return_data, "OFF");
    }
      break;
    default: {
      strcpy(return_data, "Invalid input\n Input Must be either 1 or 2");
      return;
    }
      break;
  }
  strcat(return_data, "\nOK");
}

extern void show_help(char **cmd_strings, char* return_data) {
  const char* help_text = "color [n] \t - set LED color to n. n can be between 0 and 7";
  strcpy(return_data, help_text);
}
