/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:57:08 by mneller           #+#    #+#             */
/*   Updated: 2025/01/28 13:04:52 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pb(t_push_swap *ps)
{
    int i;

    i = 0;
    if (ps->stack_a->size == 0)
        return;
    i = ps->stack_b->size;
    while (i > 0)
    {
        ps->stack_b->data[i] = ps->stack_b->data[i - 1];
        i--;
    }
    ps->stack_b->data[0] = ps->stack_a->data[0];
    ps->stack_b->size++;
    i = 0;
    while (i < ps->stack_a->size -1)
    {
        ps->stack_a->data[i] = ps->stack_a->data[i + 1];
        i++;
    }
    ps->stack_a->size--;
}

void pa(t_push_swap *ps)
{
   int i;

    i = 0;
    if (ps->stack_b->size == 0)
        return;
    i = ps->stack_a->size;
    while (i > 0)
    {
        ps->stack_a->data[i] = ps->stack_a->data[i - 1];
        i--;
    }
    ps->stack_a->data[0] = ps->stack_b->data[0];
    ps->stack_a->size++;
    i = 0;
    while (i < ps->stack_b->size -1)
    {
        ps->stack_b->data[i] = ps->stack_b->data[i + 1];
        i++;
    }
    ps->stack_b->size--;
}