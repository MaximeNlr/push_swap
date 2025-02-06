/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:24:21 by mneller           #+#    #+#             */
/*   Updated: 2025/02/03 10:52:16 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Cette fonction rempli le stack si il ne possede que des chiffres ou des nombres
// il doit aussi split la chaine pour verifier si les nombres sont précédé d'un '-'
void free_split(char **tokens)
{
    size_t i; 
    i = 0;
    if (!tokens)
        return;
    while (tokens[i]) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

void process_arg(t_push_swap *ps, char *arg)
{
    char **strs;
    size_t i;
    long num;

    i = 0;
    strs = ft_split(arg, ' ');
    while (strs[i])
    {
        if (!is_valid(strs[i]))
        {
            write(2, "Error\n", 6);
            free_split(strs);
            exit(EXIT_FAILURE);
        }
        num = ft_atoi(strs[i]);
        if (num < INT_MIN || num > INT_MAX || is_duplicate(ps, (int)num))
        {
            write(2, "Error\n", 6);
            free_split(strs);
            exit(EXIT_FAILURE);
        }
        ps->stack_a->data[ps->stack_a->size] = (int)num;
        ps->stack_a->size++;
        i++;
    }
}
void fill_stack_a(t_push_swap *ps, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        process_arg(ps, argv[i]);
        i++;
    }
}
