#include <stdlib.h>
#include "util.h"
#include "commands.h"
#include "led_cmd.h"
#include "sw_cmd.h"
#include "blink_cmd.h"

char cmd[80];
char resp[80];
int pos = 0;
const char version[] = "1.0";

void init_pins() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  init_timer();
}
void setup() {
  // put your setup code here, to run once:
  init_pins();
  Serial.begin(115200);
  Serial.println("Initializing shell...");
  Serial.print("Version:"); 
  Serial.println("1.0");
  Serial.print(">");
}

void loop() {
  // put your main code here, to run repeatedly: 
  while(Serial.available() > 0) {
    char ch = Serial.read();
    if(ch != '\n' && ch != '\r' && pos < 78) {
      cmd[pos] = ch;
      pos += 1;
    } else {
      cmd[pos] = '\0';
      pos = 0;
      process_command(cmd, resp);
      Serial.println(resp);
      Serial.print(">");
      strcpy(resp, "");
    }
  }
}
