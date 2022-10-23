#include <string.h>
#include "commands.h"
#include "util.h"
#include "led_cmd.h"

// Maximum number of arguments
int MAX_ARG = 10;

// Add the command structs to this array
struct command array_of_cmd[] = {
  {.name="color", .function=set_led_color},
};


void run_command(char **cmd_strings, char* return_data) {
  int number_of_commands = sizeof(array_of_cmd)/sizeof(array_of_cmd[0]);
  for (int i = 0; i < number_of_commands; i++) {
    if(!strcmp(*cmd_strings, array_of_cmd[i].name)) {
      array_of_cmd[0].function(cmd_strings, return_data);
    } else {
      // Display error message
      // Display help?
    }
  }
}

void process_command(char* cmd, char* cmd_output) {
  char* cmd_strings[MAX_ARG];
  get_cmd_strings(cmd, cmd_strings);
  run_command(cmd_strings, cmd_output);
}
