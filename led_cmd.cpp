#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "led_cmd.h"
#include "util.h"


void set_led_color(char **cmd_strings, char* return_data) {
  char* number = *(cmd_strings+1);
  int n = atoi(number);
  switch(n) {
    case 0: {
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
      break;
    case 1: {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
      break;
    case 2: {
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
      break;
    case 3: {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
      break;
    case 4: {
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
      break;
    case 5: {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
      break;
    case 6: {
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
    }
      break;
    case 7: {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BLUE_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
    }
      break;
    default: {
      strcpy(return_data, "Invalid input\n Input Must be between 0 to 7");
      return;
    }
      break;
  }
  strcpy(return_data, "OK");
}

extern void show_help_color(char **cmd_strings, char* return_data) {
  const char* help_text = "sw [n] \t - prints the state of the switch SWn. n can be 1 or 2";
  strcpy(return_data, help_text);
}
