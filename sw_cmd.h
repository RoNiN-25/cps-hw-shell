#ifndef SW_CMD_H_
#define SW_CMD_H_

#define SW1 31
#define SW2 17

extern void get_sw_state(char **cmd_strings, char* return_data);
extern void show_help(char **cmd_strings, char* return_data);


#endif // SW_CMD_H_
