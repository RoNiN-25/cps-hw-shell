# cps-hw-shell
Hardware Shell implementation on TivaC board

There exists a structure that implements each command. The structure is defined in the `commands.h` file. It consists of the name of the function, a callback function that is to be run when the command is run and a callback function that returns the help text of the command. The help function is called, when the help command is run.

Both the **help callback** and the **functionality callback** take two arguments: `char **cmd_strings, char* return_data`. `cmd_strings` is a pointer to an array of strings that contain the command run and its arguments as each element of the array. `return_data` is a string that contains the response to the command.

To add a new command, just create a `.cpp/.c` and a `.h` file that implements the functionality of the command. Then, include the `.h` file in `commands.cpp` file and add an entry to the `array_of_cmd` with the command structure that defines the function. Also, update the `MAX_ARG` value to the maximum number of arguments that any of the functions can take.