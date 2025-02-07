/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:04:53 by mneller           #+#    #+#             */
/*   Updated: 2025/02/07 13:05:42 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void move_smallest(t_push_swap *ps)
{
    int smallest_index;
    int half_size;

    smallest_index = find_smallest(ps);
    if (smallest_index == -1)
        return;
    half_size = ps->stack_a->size / 2;
    if (smallest_index <= half_size)
    {
        while (smallest_index > 0)
        {
            ra(ps);
            smallest_index--;
        }
    }
    else
    {
        while (smallest_index < ps->stack_a->size)
        {
            rra(ps);
            smallest_index++;
        }
    }
    pb(ps);
}

void move_smallest_chunk(t_push_swap *ps, int *moved)
{
    int smallest_index;
    int smallest_value;
    int half_size;

    smallest_index = find_smallest_chunk(ps, moved);
    if (smallest_index == -1)
        return;
    smallest_value = ps->stack_a->data[smallest_index];
    half_size = ps->stack_a->size / 2;
    if (smallest_index <= half_size)
    {
        while (ps->stack_a->data[0] != smallest_value)
            ra(ps);
    }
    else 
    {
        while (ps->stack_a->data[0] != smallest_value)
            rra(ps);
    }
    pb(ps);
    mark_as_moved(moved, ps, smallest_value);
}