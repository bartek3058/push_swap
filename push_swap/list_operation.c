#include "push_swap.h"

void    ft_listadd_front(t_list **stack, t_list *new)
{
    new -> next = *stack;
    *stack = new;
}

t_list *ft_listlast(t_list *head)
{
    t_list *temp;

    temp = head;
    while (temp -> next)
    {
        temp = temp -> next;
        if (temp -> next == NULL)
            return (temp);
    }
    return (temp);
}

void    ft_listadd_back (t_list **stack, t_list *new)
{
    t_list *n;

    if (*stack)
    {
        n = ft_listlast(*stack);
        n -> next = new;
        new -> next = NULL;
    }
    else
    {
        *stack = new;
        (*stack) -> next = NULL;
    }
}

t_list  *ft_listnew(int value)
{
    t_list *new;

    new = (t_list *) malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new -> value = value;
    new -> index = -1;
    new -> next = NULL;
    return (new);
}

int ft_listsize(t_list *head)
{
    size_t  i;
    t_list  *temp;

    temp = head;
    i = 0;
    while (temp)
    {
        temp = temp ->next;
        i++;
    }
    return (i);
}