#include <arduino.h>
#include <stdlib.h>
#include <string.h>
#include "photo_sensor_cmd.h"

// array containing the 8 pins connected to the photo sensor
// they are PB_0, PB_1, PE_4, PE_5, PB_4, PA_5, PA_6, PA_7
int photo_sensor_pins[] = {3, 4, 5, 6, 7, 8, 9, 10};

void init_photo_sensor() {
  pinMode(IR_LED_PIN, OUTPUT);
}

void read_photo_sensor(char **cmd_strings, char* return_data) {
  unsigned int photo_sensor_value = 0;
  digitalWrite(IR_LED_PIN, HIGH);
  for(int i = 0; i < 8; i++)
    pinMode(photo_sensor_pins[i], OUTPUT);
    
  for(int i = 0; i < 8; i++)
    digitalWrite(photo_sensor_pins[i], HIGH);

  delayMicroseconds(10);
  
  for(int i = 0; i < 8; i++)
    pinMode(photo_sensor_pins[i], INPUT);

  delayMicroseconds(1000);
  
  for(int i = 0; i < 8; i++) {
    int sensor_val = digitalRead(photo_sensor_pins[i]);
    photo_sensor_value = photo_sensor_value << 1 | sensor_val;
  }

  digitalWrite(IR_LED_PIN, LOW);
//  char buffer[8];   // buffer to store the string version of the read sensor data
  itoa(photo_sensor_value, return_data, 2);   // convert the read 8-bit sensor data into a string and return it
//  strcpy(return_data, buffer);
}

void show_help_photo_sensor(char **cmd_strings, char* return_data) {
  const char* help_text = "ref \t - Read the photo sensor data below the RSLK kit";
  strcpy(return_data, help_text);
}
