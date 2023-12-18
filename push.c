#include "monty.h"

/**
 * my_special_push - add value to the custom stack by ayoub
 * @stack_head: pointer to the head of the custom stack
 * Return: no return value
 */
void my_special_push(custom_stack_t **stack_head, unsigned int line_num)
{
    int value, idx = 0, invalid_flag = 0;

    if (custom_args.argument)
    {
        if (custom_args.argument[0] == '-')
            idx++;
        for (; custom_args.argument[idx] != '\0'; idx++)
        {
            if (custom_args.argument[idx] > '9' || custom_args.argument[idx] < '0')
                invalid_flag = 1;
        }
        if (invalid_flag == 1)
        {
            fprintf(stderr, "Line %d: custom error: push integer only\n", line_num);
            fclose(custom_args.file);
            free(custom_args.content);
            free_custom_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Line %d: custom error: push integer\n", line_num);
        fclose(custom_args.file);
        free(custom_args.content);
        free_custom_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    value = atoi(custom_args.argument);
 if (custom_args.lifo == 0)
custom_add_queue(stack_head, value);
 else
	custom_add_node(stack_head, value);
}
