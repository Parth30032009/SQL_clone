#include "./error.h"

Error Err_Meta_Command_Unrecognized = {
    .err_name = "Meta Command Unrecognized",
    .err_message = "Unrecognized command. %s\n" // String to be formatted with the input buffer
};

Error Err_Prepare_Unrecognized_Statement = {
    .err_name = "Prepare Unrecognized Statement",
    .err_message = "Unrecognized keyword on the start of %s\n" // String to be formatted with the input buffer
};

Error Err_Prepare_Syntax_Error = {
    .err_name = "Prepare Syntax Error",
    .err_message = "Syntax error. Could not parse statement %s\n" // String to be formatted with the input buffer
};

Error Err_Execute_Table_Full = {
    .err_name = "Execute Table Full",
    .err_message = "Error: Table full\n"
};

Error Err_Execute_Unrecognized_Statement = {
    .err_name = "Execute Unrecognized Statement",
    .err_message = "Error: Unrecognized statement\n"
};