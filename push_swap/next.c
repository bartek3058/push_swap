#include "push_swap.h"

t_list  *get_next_min(t_list **stack)
{
    t_list  *head;
    t_list  *min;
    int     minint;

    min = NULL;
    minint = 0;
    head = *stack;
    if(head)
    {
        while(head)
        {
            if ((head -> index == -1) && (minint == 0 || head -> value < min -> value))
            {
                min = head;
                minint = 1;
            }
            head = head -> next;
        }
    }
    return (min);
}

void    index_stack(t_list **stack)
{
    t_list *head;
    int     index;

    index = 0;
    head = get_next_min (stack);
    while(head)
    {
        head -> index = index++;
        head = get_next_min(stack);
    }
}

int get_min_index (t_list **stack, int val)
{
    t_list  *head;
    int     min;

    head = *stack;
    min = head -> index;
    while (head -> next)
    {
        head = head -> next;
        if ((head -> index < min) && head -> index != val)
            min = head -> index;
    }
    return (min);
}

void    sort_3 (t_list **stack_a)
{
    t_list  *head;
    int         min;
    int         next_min;
    
    head = *stack_a;
    min = get_min_index(stack_a, -1);
    next_min = get_min_index(stack_a, min);
    if (is_sorted(stack_a))
        return ;
    if (head -> index == min && head -> next -> index != next_min)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (head -> index == next_min)
    {
        if (head -> next -> index == min)
            sa (stack_a);
        else
            rra (stack_a);
    }
    else
    {
        if (head -> next -> index == min)
            ra(stack_a);
        else
        {
            sa(stack_a);
            rra(stack_a);
        }
    }
}

void    sort_4 (t_list **stack_a, t_list **stack_b)
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
        rra(stack_a);
    if (is_sorted(stack_a))
        return ;
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}