#include <stdlib.h>
#include "util.h"
#include "commands.h"
#include "led_cmd.h"
#include "sw_cmd.h"
#include "blink_cmd.h"
#include "motor_cmd.h"
#include "photo_sensor_cmd.h"

char cmd[80];
char resp[120];
int pos = 0;
const char version[] = "2.0";

void setup() {
  // put your setup code here, to run once:
  init_pins();
  init_motors();
  init_timer();
  init_photo_sensor();
  Serial.begin(115200);
  Serial.println("Initializing shell...");
  Serial.print("Version:"); 
  Serial.println(version);
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
