#include "push_swap.h"

void    initStack(t_list **stack, int argc, char **argv)
{
    t_list  *new;
    char    **args;
    int     i;

    i = 1;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
        args = argv;
    while (args[i])
    {
        new = ft_listnew(ft_atoi(args[i]));
        ft_listadd_back(stack, new);
        i++;
    }
    index_stack(stack);
    if (argc == 2)
        ft_free(args);
}

int is_sorted (t_list **stack)
{
    t_list *head;

    head = *stack;
    while (head && head ->next)
    {
        if(head-> value > head ->next ->value)
            return(0);
        head = head ->next;
    }
    return(1);
}

void    free_stack(t_list **stack)
{
    t_list *head;
    t_list *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}

void    simple_sort(t_list **stack_a, t_list **stack_b)
{
    int size;

    if (is_sorted(stack_a) == 1 || ft_listsize(*stack_a) == 0
            || ft_listsize(*stack_a) == 1)
            return ;
    size = ft_listsize(*stack_a);
    if(size == 2)
        sa(stack_a);
    if (size == 3)
        sort_3(stack_a);
    if (size == 4)
        sort_4(stack_a, stack_b);
    if (size == 5)
        sort_5(stack_a, stack_b);
}

void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    if (ft_listsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}