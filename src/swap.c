/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:21:21 by mneller           #+#    #+#             */
/*   Updated: 2025/01/24 16:20:31 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sa(t_push_swap *ps)
{
    int i;
    int tmp;

    i = 0;
    
    while (ps->stack_a->data[i])
        i++;
    tmp = ps->stack_a->data[0];
    ps->stack_a->data[0] = ps->stack_a->data[1];
    ps->stack_a->data[1] = tmp;
}

void sb(t_push_swap *ps)
{
    int i;
    int tmp;

    i = 0;
    while (ps->stack_b->data[i])
        i++;
    tmp = ps->stack_b->data[0];
    ps->stack_b->data[0] = ps->stack_b->data[1];
    ps->stack_b->data[1] = tmp;
}
