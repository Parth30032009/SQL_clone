#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "./include/REPL.h"
#include "./include/compiler.h"

int main(int argc, char* agrv[])
{
    InputBuffer *input_buffer = new_input_buffer();

    while(true)
    {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer[0] == '.')
        {
            switch(do_meta_command(input_buffer))
            {
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command %s\n", input_buffer->buffer);
                    continue;
            }
        }

        Statement statement;
        switch(prepare_statement(input_buffer, &statement))
        {
            case (PREPARE_SUCCESS):
                break;
            case(PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keybord on the start of %s.\n", input_buffer->buffer);
                continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
}