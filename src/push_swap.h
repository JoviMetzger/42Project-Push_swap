/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:02:52 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/22 14:23:30 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>  //
# include <string.h>  //
# include "../libft/libft.h"

typedef struct s_stack
{
	int content;
	int	index;
	struct s_stack	*next;
} t_stack;

typedef struct s_data
{
	t_stack *stack_a;
	t_stack *stack_b;
	
    int size;   // current size of the stack /len
    int top;    // index of the top element of the stack / limit
    int *array; // array to store the elements of the stack //
} t_data;

void quickSort(t_data *data);
void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);
void pb(t_data *data);
void pa(t_data *data);
void ra(t_data *data);
void rb(t_data *data);
void rr(t_data *data);
void rra(t_data *data);
void rrb(t_data *data);
void rrr(t_data *data);
int ft_isdigit(int digit);
int ft_strcmp(char *s1, char *s2);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
int ft_putstr(char *str);
int ft_putchar(char c);
t_stack *ft_lstnew_a(int value);
void ft_lstadd_back_a(t_stack **lst, t_stack *new);
int	ft_lstsize_a(t_stack *lst);
t_stack *ft_lstlast_a(t_stack *lst);
void ft_error(char *msg);
void ft_free(char **str);
void ft_checking_arg(int argc, char **argv);
//void printStacks(t_stack *a, t_stack *b);
int isEmpty(t_stack *stack);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);
void ft_printStacks(t_stack *s);
void printStack(t_stack *s); //rm
void printStacks(t_stack *a, t_stack *b);

#endif
