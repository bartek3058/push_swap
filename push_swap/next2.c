#include "push_swap.h"

int get_distance (t_list **stack, int index)
{
    t_list  *head;
    int         distance;

    distance = 0;
    head = *stack;
    while (head)
    {
        if (head -> index == index)
            break ;
        distance++;
        head = head -> next;
    }
    return (distance);
}

void    sort_5 (t_list **stack_a, t_list **stack_b)
{
    int distance;

    if (is_sorted(stack_a))
        return ;
    distance = get_distance(stack_a, get_min_index (stack_a, -1));
    if (distance == 1)
        ra (stack_a);
    else if (distance == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (distance == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if (distance == 4)
        rra(stack_a);
    if (is_sorted(stack_a))
        return ;
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
}

int     get_max_bits(t_list **stack)
{
    t_list  *head;
    int         max;
    int         max_bits;

    head = *stack;
    max = head -> index;
    max_bits = 0;
    while (head)
    {
        if (head -> index > max)
            max = head -> index;
        head = head -> next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    radix_sort(t_list **stack_a, t_list **stack_b)
{
    t_list  *head_a;
    int         i;
    int         j;
    int         size;
    int         max_bits;

    i = 0;
    head_a = *stack_a;
    size = ft_listsize(head_a);
    max_bits = get_max_bits(stack_a);
    while (i  < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            head_a = *stack_a;
            if(((head_a -> index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b); 
        }
        while (ft_listsize(*stack_b) != 0)
            pa(stack_a, stack_b);
        i++;
    }
}

void	ft_error()
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}