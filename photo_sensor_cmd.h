#ifndef PHOTO_SENSOR_CMD_H_
#define PHOTO_SENSOR_CMD_H_

#define IR_LED_PIN 2      // PB_5

extern void read_photo_sensor(char **cmd_strings, char* return_data);
extern void show_help_photo_sensor(char **cmd_strings, char* return_data);
extern void init_photo_sensor();

extern int photo_sensor_pins[];

#endif // PHOTO_SENSOR_CMD_H_
