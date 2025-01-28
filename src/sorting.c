/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:54:47 by mneller           #+#    #+#             */
/*   Updated: 2025/01/28 16:10:46 by mneller          ###   ########.fr       */
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
        print_stack_b(ps);
        print_stack_a(ps);
        sort_3(ps);
        print_stack_a(ps);
        pa(ps);
        print_stack_a(ps);
         pa(ps);
        print_stack_a(ps);
    }
}

void move_smallest(t_push_swap *ps)
{
    int smallest;
    int smallest_index;
    int i;

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
    while (smallest_index > 0)
    {
        ra(ps);
        smallest_index--;
    }
    pb(ps);
}
