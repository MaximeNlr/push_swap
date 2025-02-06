/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:58:10 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 11:10:52 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void move_chunk(t_push_swap *ps, int chunk_size, int *moved)
{
    int i;

    i = 0;
    while (i < chunk_size)
    {
        if (find_smallest_chunk(ps, moved) == -1) // Plus de valeurs à déplacer
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
    {
        printf("⚠️ Value %d is already in moved, skipping...\n", value);
        return;
    }
    moved[ps->moved_index] = value;
    printf("Moved[%d] = %d\n", ps->moved_index, value);
    ps->moved_index++;     
}
void print_moved(int *moved, int size) 
{
    printf("Tableau moved: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", moved[i]);
    }
    printf("\n");
}
