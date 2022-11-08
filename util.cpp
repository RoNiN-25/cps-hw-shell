#include <arduino.h>
#include <string.h>
#include "util.h"
#include "commands.h"

void init_pins() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void get_cmd_strings(char* cmd, char** cmd_strings) {
  char *token = strtok(cmd, " ");
  cmd_strings[0] = token;
  int i = 1;
  while (token != NULL) {
    token = strtok(NULL, " ");
    cmd_strings[i] = token;
    i++;
  } 
}

void set_led_color(int n) {
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
      digitalWrite(RED_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
  }
}
