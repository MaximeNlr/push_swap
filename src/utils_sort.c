/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:18:39 by mneller           #+#    #+#             */
/*   Updated: 2025/02/06 17:06:31 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// Cette fonction deplace le plus petit element a stack_b
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
        print_moved(moved, ps->stack_a->size);
        printf("Valeur a trouver [%d]\n", smallest_value);
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
    
    printf("Taille de a après pb [%d]\n", ps->stack_a->size);
    printf("Après pb:\n");
    printf("stack_a\n");
    print_stack_a(ps);
    printf("stack_b\n");
    print_stack_b(ps);
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
