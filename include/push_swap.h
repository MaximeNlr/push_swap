/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:50:08 by mneller           #+#    #+#             */
/*   Updated: 2025/01/28 15:45:18 by mneller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
    int *data;
    int size;
    int capacity;
} t_stack;

typedef struct s_push_swap
{
    t_stack *stack_a;
    t_stack *stack_b;
} t_push_swap;

// Remplissage des stacks
void fill_stack_a(t_push_swap *ps, int argc, char **argv);
void process_arg(t_push_swap *ps, char *arg);
void free_split(char **tokens);

// Affichage du stack
void print_stack_a(t_push_swap *ps);
void print_stack_b(t_push_swap *ps);
void ft_putnbr_fd(int n, int fd);

// Toutes les oprations sa, sb etc..
void sa(t_push_swap *ps); // Intervertit les 2 premiers
void sb(t_push_swap *ps);
void ra(t_push_swap *ps); // Le premier devient le dernier
void rb(t_push_swap *ps);
void rra(t_push_swap *ps); // Le dernier devient le premier.
void pb(t_push_swap *ps); // Le premier element de b devient le premier de a.
void pa(t_push_swap *ps); // Le premier element de a devient le premier de b.

// tri des stacks
void sort_2(t_push_swap *ps);
void sort_3(t_push_swap *ps);
void sort_5(t_push_swap *ps);
void move_smallest(t_push_swap *ps);

// Verification de la confromité du stack
int is_duplicate(t_push_swap *ps, int num); // Check si 2 chiffres sont similaire
int is_valid(char *str); // Check si la chaine contient des chiffres apres le signe '-'
int is_sorted(t_stack *stack); // Check si le stack est trié

// Utils lié a la validation du stack
int ft_isdigit(int c);
size_t ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int ft_atoi(char *str);

// Fonction split
size_t count_token(char *str, char del);
int	safe_malloc(char **tokens, int pos, size_t buffer);
int fill_token(char **tokens, char *str, char del);
char **ft_split(char *str, char del);

// Malloc des stacks
t_stack *init_stack(int capacity);
t_push_swap *init_push_swap(int argc);

// Liberation de memoire
void free_stack(t_stack *stack);
void free_push_swap(t_push_swap *ps);

// Fonction main
int main(int argc, char **argv);

#endif