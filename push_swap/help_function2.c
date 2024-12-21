#include "push_swap.h"

int rr(t_list **stack_a, t_list **stack_b)
{
    if((ft_listsize(*stack_a) < 2) || (ft_listsize(*stack_b) < 2))
        return (-1);
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
    return (0);
}

int reverseRotate(t_list **stack)
{
    t_list  *head;
    t_list  *tail;

    if (ft_listsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_listlast(*stack);
    while(head)
    {
        if (head -> next -> next == NULL)
        {
            head -> next = NULL;
            break ;
        }
        head = head -> next;
    }
    tail -> next = *stack;
    *stack = tail;
    return(0);
}

int rra(t_list **stack_a)
{
    if (reverseRotate(stack_a) == -1)
        return (-1);
    ft_putstr_fd("rra\n", 1);
    return (0);
}

int rrb(t_list **stack_b)
{
    if (reverseRotate(stack_b) == -1)
        return (-1);
    ft_putstr_fd("rrb\n", 1);
    return (0);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
    if((ft_listsize(*stack_a) < 2) || (ft_listsize(*stack_b) < 2))
        return (-1);
    reverseRotate(stack_a);
    reverseRotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
    return (0);
}

