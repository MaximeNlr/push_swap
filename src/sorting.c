/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:54:47 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 18:31:22 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_2(t_push_swap *ps)
{   
    if (!is_sorted(ps->stack_a))
        sa(ps);
}

void sort_3(t_push_swap *ps)
{
    int *nb;

    nb = ps->stack_a->data;
    if (!is_sorted(ps->stack_a))
    {
        if (nb[0] > nb[1] && nb[0] > nb[2])
        {
            ra(ps);
            sa(ps);
        }
        if (nb[1] > nb[0] && nb[1] > nb[2])
        {
            sa(ps);
            ra(ps);
            sa(ps);
        }
        if (nb[0] < nb[1] && nb[0] > nb[2])
        {
            sa(ps);
            ra(ps);
        }
        if (nb[0] > nb[1] && nb[0] < nb[2])
            sa(ps);
    }
}

void sort_5(t_push_swap *ps)
{
    if (!is_sorted(ps->stack_a))
    {
        move_smallest(ps);
        move_smallest(ps);
        sort_3(ps);
        pa(ps);
        pa(ps);
    }
}

void sort(t_push_swap *ps)
{
    int half_size;
    int chunk_size;
    int *moved;
    
    moved = init_moved(ps->stack_a->capacity);
    if (!moved)
    {
        write (1, "Erreur lors de l'allocation de memoire de moved\n", 48);
        return;
    }
    half_size = ps->stack_a->size / 2;
    chunk_size = half_size / 2;
    while (ps->stack_a->size > 0)
    {
        move_chunk(ps, chunk_size, moved);
    }
    while (ps->stack_b->size > 0)
    {
        find_push_max(ps);
    }
    free(moved);
}
