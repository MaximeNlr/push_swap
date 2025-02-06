/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:14 by mneller           #+#    #+#             */
/*   Updated: 2025/02/05 21:43:20 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *init_stack(int capacity)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->data = malloc(sizeof(int) * capacity);
    if (!stack->data)
    {
        free(stack);
        return (NULL);
    }
    stack->size = 0;
    stack->capacity = capacity;
    return (stack);
}

t_push_swap *init_push_swap(int argc)
{
    t_push_swap *ps;
    int capacity;

    capacity = argc -1;
    ps = malloc(sizeof(t_push_swap));
    if (!ps)
        return (NULL);
    ps->moved_index = 0;
    ps->stack_a = init_stack(capacity);
    if (!ps->stack_a)
    {
        free(ps);
        return (NULL);
    }
    ps->stack_b = init_stack(capacity);
    if (!ps->stack_b)
    {
        free(ps->stack_a);
        free(ps);
        return (NULL);
    }
    return (ps);
}

void free_stack(t_stack *stack)
{
    free(stack->data);
    free(stack);
}

void free_push_swap(t_push_swap *ps)
{
    free_stack(ps->stack_a);
    free_stack(ps->stack_b);
    free(ps);
}