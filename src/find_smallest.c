/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:18:39 by mneller           #+#    #+#             */
/*   Updated: 2025/02/07 13:05:38 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int find_smallest(t_push_swap *ps)
{
    int smallest;
    int smallest_index;
    int i;

    if (ps->stack_a->size == 0)
        return (-1);
    
    smallest = INT_MAX;
    smallest_index = -1;
    
    i = 0;
    while (i < ps->stack_a->size)
    {
        if (ps->stack_a->data[i] < smallest)
        {
            smallest = ps->stack_a->data[i];
            smallest_index = i;
        }
        i++;
    }
    return (smallest_index);
}

int find_smallest_chunk(t_push_swap *ps, int *moved)
{
    int smallest;
    int smallest_index;
    int i;
    int current;

    if (ps->stack_a->size == 0)
        return (-1);
    
    smallest = INT_MAX;
    smallest_index = -1;
    
    i = 0;
    while (i < ps->stack_a->size)
    {
        current = ps->stack_a->data[i];
        if (!already_moved(moved, ps->moved_index, current) && current < smallest)
        {
            smallest = current;
            smallest_index = i;
        }
        i++;
    }
    return (smallest_index);
}

int *init_moved(size_t size)
{
    int *moved;

    moved = (int *)ft_calloc(size, sizeof(int));
    if (!moved)
        {
            write(1, "Error: calloc failed\n", 21);
            return (NULL);
        }
    return (moved);
}
