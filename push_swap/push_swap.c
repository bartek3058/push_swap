
#include "push_swap.h"

void    ft_free(char **s)
{
    int i;

    i = 0;
    while (s[i] != 0)
        i++;
    while (i >= 0)
        free(s[i--]);
}

int ft_double (int temp, char *s, int i)
{
    i++;
    while (s[i] != '\0')
    {
        if (ft_atoi(&s[i]) == temp)
            return (0);
        i++;
    }
    return (1);
}

int ft_isnum(char *s)
{
    int i;

    i = 0;
    if (s[0] == '-')
        i++;
    while (s[i] != '\0')
    {
        if (ft_isdigit(s[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

void    ft_check_args(int argc, char **argv)
{
    int i;
    long int    temp;
    char        **args;

    i = 0;
    if (argc == 2)
        args = ft_split (argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        temp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]))
            ft_error();
        else if (ft_double(temp, args[i], i) == 0)
            ft_error();
        else if (temp < -2147483648 || temp > 2147483647)
            ft_error();
        i++;
    }
    if (argc == 2)
        ft_free(args);
}


int main (int argc, char **argv)
{
    t_list  **stack_a;
    t_list  **stack_b;

    if (argc < 2)
        return (-1);
    ft_check_args(argc,argv);
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    initStack(stack_a, argc, argv);
    if (is_sorted(stack_a) == 1)
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}