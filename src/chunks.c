/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:58:10 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 18:39:42 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void move_chunk(t_push_swap *ps, int chunk_size, int *moved)
{
    int i;

    i = 0;
    while (i < chunk_size)
    {
        if (find_smallest_chunk(ps, moved) == -1)
            break;
        move_smallest_chunk(ps, moved);
        i++;
    }
}

int already_moved(int *moved, int moved_index, int value)
{
    int i;
    
    i = 0;
    while (i < moved_index)
    {
        if (moved[i] == value)
            return (1);
        i++;
    }
    return (0);
}

void mark_as_moved(int *moved, t_push_swap *ps, int value)
{
    if (already_moved(moved, ps->moved_index, value))
        return;
    moved[ps->moved_index] = value;
    ps->moved_index++;     
}

