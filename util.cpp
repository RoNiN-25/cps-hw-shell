#include <string.h>
#include "util.h"
#include "commands.h"

void get_cmd_strings(char* cmd, char** cmd_strings) {
  char *token = strtok(cmd, " ");
  cmd_strings[0] = token;
  int i = 1;
  while (token != NULL) {
    token = strtok(NULL, " ");
    cmd_strings[i] = token;
    i++;
  } 
}
