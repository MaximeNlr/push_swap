/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:00:46 by mneller           #+#    #+#             */
/*   Updated: 2025/01/24 11:24:55 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_duplicate(t_push_swap *ps, int num)
{
    int i;

    i = 0;
    while (i < ps->stack_a->size)
    {
        if (ps->stack_a->data[i] == num)
            return (1);
        i++;
    }
    return (0);
}
int is_valid(char *str)
{
   size_t i;
   i = 0;
    if (!str || str[i] == '\0')
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!ft_isdigit(str[i]))
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_sorted(t_stack *stack)
{
    int i;

    if (stack->size == 0)
        return (0);
    i = 0;
    while (i < stack->size -1)
    {
        if (stack->data[i] > stack->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}