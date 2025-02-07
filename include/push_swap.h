/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneller <mneller@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:50:08 by mneller           #+#    #+#             */
/*   Updated: 2025/02/07 10:47:52 by mneller          ###   ########.fr       */
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
    int moved_index;
} t_push_swap;

// Remplissage des stacks
void fill_stack_a(t_push_swap *ps, int argc, char **argv);
void process_arg(t_push_swap *ps, char *arg);

// Affichage du stack
void print_stack_a(t_push_swap *ps);
void print_stack_b(t_push_swap *ps);
void ft_putnbr_fd(int n, int fd);

// Toutes les oprations sa, sb etc..
void sa(t_push_swap *ps); // Intervertit les 2 premiers de stack_a
void sb(t_push_swap *ps); 
void ra(t_push_swap *ps); // le dernier devient le premier
void rb(t_push_swap *ps);
void rra(t_push_swap *ps);  // stack_a le dernier devient le premier
void rrb(t_push_swap *ps);
void pb(t_push_swap *ps); // Le premier element de b devient le premier de a.
void pa(t_push_swap *ps);

// tri des stacks
void sort_2(t_push_swap *ps); 
void sort_3(t_push_swap *ps); 
void sort_5(t_push_swap *ps); 
void sort(t_push_swap *ps);

//chunks utils
void find_push_max(t_push_swap *ps); // Envoie la valeur la plus grance vers stack_a
int get_max_value(t_stack *stack); // Trouve la valeur la plus grande
int find_max_index(t_stack *stack); // Trouve 
void move_smallest_chunk(t_push_swap *ps, int *moved); // Envoie le plus petit vers stack_b
void move_smallest(t_push_swap *ps);
int find_smallest(t_push_swap *ps);// Trouve le plus petit 
int find_smallest_chunk(t_push_swap *ps, int *moved); // Trouve le plus petit dans un chunk donné
void move_chunk(t_push_swap *ps, int chunk_size, int *moved);
int *init_moved(size_t size); // Initialise le pointeur moved
void mark_as_moved(int *moved, t_push_swap *ps, int value); // Designe une valeur comme moved
int already_moved(int *moved, int moved_index, int value); // Verifie si une valeur a déja été manipulé 

// Verification de la confromité du stack
int is_duplicate(t_push_swap *ps, int num); // Check si 2 chiffres sont similaire
int is_valid(char *str); // Check si la chaine contient des chiffres apres le signe '-'
int is_sorted(t_stack *stack); 

// Utils lié a la validation du stack
int ft_isdigit(int c);
size_t ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

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
void free_split(char **tokens);

int main(int argc, char **argv);

#endif