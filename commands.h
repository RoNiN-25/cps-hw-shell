#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef void (*fn_ptr)(char **cmd_strings, char* return_data);
struct command {
  const char *name;
  fn_ptr function;
};

extern void run_command(char **cmd_strings, char* return_data);
extern void process_command(char* cmd, char* cmd_output);

extern struct command array_of_cmd[];

#endif // COMMANDS_H_
