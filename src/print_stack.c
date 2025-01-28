/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:10:32 by mneller           #+#    #+#             */
/*   Updated: 2025/01/24 14:51:43 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_putnbr_fd(int n, int fd)
{
    char c;

    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd);
    c = n % 10 + '0';
    write(fd, &c, 1);
}

void print_stack_a(t_push_swap *ps)
{
    int i;

    if (ps->stack_a->size == 0)
    {
        write(1, "A est vide\n", 11);
        return;
    }
    i = 0;
    while (i < ps->stack_a->size)
    {
        ft_putnbr_fd(ps->stack_a->data[i], 1);
        write(1 , " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

void print_stack_b(t_push_swap *ps)
{
    int i;

    if (ps->stack_b->size == 0)
    {
        write(1, "B est vide\n", 11);
        return;
    }
    i = 0;
    while (i < ps->stack_b->size)
    {
        ft_putnbr_fd(ps->stack_b->data[i], 1);
        write(1 , " ", 1);
        i++;
    }
    write(1, "\n", 1);
}