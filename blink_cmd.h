#ifndef BLINK_CMD_H_
#define BLINK_CMD_H_

#define TICKS_1MS 8000000 // 1ms at 80 MHz

extern void blink_led(char **cmd_strings, char* return_data);
extern void show_help_blink(char **cmd_strings, char* return_data);
extern void init_timer();

extern void start_timer(unsigned int delay_value);
extern void stop_timer();

extern void timerIntHandler();

extern int red_led_state;


#endif // BLINK_CMD_H_
