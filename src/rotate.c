/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:12:31 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 17:05:04 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra(t_push_swap *ps)
{
    int tmp;
    int i;

    if (ps->stack_a->size <= 1)
    {
        return;
    }
    tmp = ps->stack_a->data[0];
    i = 0;
    while (i < ps->stack_a->size - 1)
    {
        ps->stack_a->data[i] = ps->stack_a->data[i + 1];
        i++;
    }
    ps->stack_a->data[ps->stack_a->size - 1] = tmp;
}

void rb(t_push_swap *ps)
{
    int tmp;
    int i;

    if (ps->stack_b->size <= 1)
        {
            return;
        }
   tmp = ps->stack_b->data[0];
    i = 0;
    while (i < ps->stack_b->size - 1)
    {
        ps->stack_b->data[i] = ps->stack_b->data[i + 1];
        i++;
    }
    ps->stack_b->data[ps->stack_b->size -1] = tmp;
}

void rra(t_push_swap *ps)
{
    int tmp;
    int i;

    if (ps->stack_a->size <= 1)
        return;

    i = ps->stack_a->size - 1;
    tmp = ps->stack_a->data[i];

    while (i > 0)
    {
        ps->stack_a->data[i] = ps->stack_a->data[i - 1];
        i--;
    }
    ps->stack_a->data[0] = tmp;
}

void rrb(t_push_swap *ps)
{
    int tmp;
    int i;

    if (ps->stack_b->size <= 1)
        return;

    i = ps->stack_b->size - 1;
    tmp = ps->stack_b->data[i];

    while (i > 0)
    {
        ps->stack_b->data[i] = ps->stack_b->data[i - 1];
        i--;
    }
    ps->stack_b->data[0] = tmp;
}

