#include "util.h"
#include "commands.h"
#include "led_cmd.h"
#include "sw_cmd.h"

char cmd[80];
char resp[80];
const char version[] = "1.0";

void init_pins() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}
void setup() {
  // put your setup code here, to run once:
  init_pins();
  Serial.begin(9600);
  Serial.println("Initializing shell...");
  Serial.print("Version:"); 
  Serial.println("1.0");
  Serial.print(">");
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(Serial.available() > 0) {
    Serial.readBytesUntil('\n', cmd, 80);
    process_command(cmd, resp);
    Serial.print(resp);
    Serial.print("\n");
    Serial.print(">");
  }
}
