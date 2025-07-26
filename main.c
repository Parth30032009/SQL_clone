#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "./include/REPL.h"
#include "./include/compiler.h"
#include "./constants/error.h"
#include "./constants/error.c"

int main(int argc, char* agrv[])
{
    Table* table = new_table();
    InputBuffer *input_buffer = new_input_buffer();

    while(true)
    {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer[0] == '.')
        {
            switch(do_meta_command(input_buffer, table))
            {
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf(Err_Meta_Command_Unrecognized.err_message, input_buffer->buffer);
                    continue;
            }
        }

        Statement statement;
        switch(prepare_statement(input_buffer, &statement))
        {
            case (PREPARE_SUCCESS):
                break;
            case(PREPARE_UNRECOGNIZED_STATEMENT):
                printf(Err_Prepare_Unrecognized_Statement.err_message, input_buffer->buffer);
                continue;
            case (PREPARE_SYNTAX_ERROR):
                printf(Err_Prepare_Syntax_Error.err_message, input_buffer->buffer);
                continue;
        }
        switch (execute_statement(&statement, table))
        {
        case (EXECUTE_SUCCESS):
            printf("Executed.\n");
            break;
        case (EXECUTE_TABLE_FULL):
            printf("%s\n", Err_Execute_Table_Full.err_message);
            break;
        default:
            printf("%s\n", Err_Execute_Unrecognized_Statement.err_message);
            break;
        }
    }
}