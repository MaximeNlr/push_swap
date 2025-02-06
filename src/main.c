/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:54:53 by mneller           #+#    #+#             */
/*   Updated: 2025/02/04 22:13:24 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_push_swap *ps;


    if (argc < 2)
    {
        return (EXIT_FAILURE);
    }
    ps = init_push_swap(argc);
    if (!ps)
    {
        return (EXIT_FAILURE);
    }
    
    fill_stack_a(ps, argc, argv);
    printf("Stack_a avant le tri\n");
    print_stack_a(ps);
   
    if (is_sorted(ps->stack_a))
    {
        printf("a est trié\n");
        print_stack_a(ps);
        free_push_swap(ps);
        return (EXIT_SUCCESS);
    }
    if (ps->stack_a->size == 2)
    {
        sort_2(ps);
    }
    if (ps->stack_a->size == 3)
    {
        sort_3(ps);
    }
    if (ps->stack_a->size == 5)
    {
        sort_5(ps);
    }
    if (ps->stack_a->size > 5)
    {
        sort(ps);
    }
    if (is_sorted(ps->stack_a))
    {
        printf("a est trié\n");
        print_stack_a(ps);
        free_push_swap(ps);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
    free_push_swap(ps);
}