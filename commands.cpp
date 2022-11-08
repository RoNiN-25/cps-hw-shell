#include <arduino.h>
#include <string.h>
#include "commands.h"
#include "util.h"
#include "led_cmd.h"
#include "sw_cmd.h"
#include "blink_cmd.h"
#include "motor_cmd.h"
#include "photo_sensor_cmd.h"

// Maximum number of arguments
int MAX_ARG = 10;

// Add the command structs to this array
struct command array_of_cmd[] = {
  {.name="color", .function=change_led_color  , .help_fn=show_help_color        },
  {.name="sw"   , .function=get_sw_state      , .help_fn=show_help_sw           },
  {.name="blink", .function=blink_led         , .help_fn=show_help_blink        },
  {.name="motor", .function=set_motor_speed   , .help_fn=show_help_motor        },
  {.name="ref"  , .function=read_photo_sensor , .help_fn=show_help_photo_sensor },
};


void run_command(char **cmd_strings, char* return_data) {
  bool command_run = false;  // flag to check if a command has been run
  int number_of_commands = sizeof(array_of_cmd)/sizeof(array_of_cmd[0]);
  for (int i = 0; i < number_of_commands; i++) {
    if(!strcmp(*cmd_strings, array_of_cmd[i].name)) {
      array_of_cmd[i].function(cmd_strings, return_data);
      command_run = true;
      break;
    }
  }
  
  // If help command, display help strings
  if(!strcmp(*cmd_strings, "help")) {
    for (int i = 0; i < number_of_commands; i++) {
      array_of_cmd[i].help_fn(cmd_strings, return_data);
      Serial.println(return_data);
      command_run = true;
    }
    // Empty return data as help has already been displayed
    strcpy(return_data, "");
  }

  // if none of the commands are run show error message
  if(!command_run) {
    strcpy(return_data, "Unknown command\nUse command - \'help\' to see list of commands supported");
  }
}

void process_command(char* cmd, char* cmd_output) {
  char* cmd_strings[MAX_ARG];
  get_cmd_strings(cmd, cmd_strings);
  run_command(cmd_strings, cmd_output);
}
