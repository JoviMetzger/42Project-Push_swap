/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:02:52 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 16:18:03 by jmetzger      ########   odam.nl         */
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
} t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

t_stack *ft_lstnew_a(int value);
t_stack *ft_lstlast_a(t_stack *lst);
int		ft_lstsize_a(t_stack *lst);
void	ft_lstadd_back_a(t_stack **lst, t_stack *new);

void	ft_error(char *msg);
void	ft_free(char **str);//
int		ft_max(t_stack *stack);
int		ft_min(t_stack *stack);
int		find_index(t_stack *a, int nbr);
int		future_index_in_a(t_stack *stack, int current_nbr);
int		future_index_in_b(t_stack *stack, int current_nbr);

void	checking_arg(int argc, char **argv);
void	fill_stackA(t_data *data, int argc, char **argv);

int		stack_sorted(t_stack *stack);
void	sorting(t_data *data);
void	sorting_stack_A(t_data *data);
void	sorting_stack_B(t_data *data);
void	last_stackA_sort(t_data *data);

int 	case_one_a(t_data *data, t_stack *current_nbr);
int 	case_two_a(t_data *data, t_stack *current_nbr);
int 	case_three_a(t_data *data, t_stack *current_nbr);
int 	case_four_a(t_data *data, t_stack *current_nbr);
int 	case_one_b(t_data *data, t_stack *current_nbr);
int 	case_three_b(t_data *data, t_stack *current_nbr);
int 	case_two_b(t_data *data, t_stack *current_nbr);
int 	case_four_b(t_data *data, t_stack *current_nbr);

int 	apply_case_one(t_data *data, int current, int c);
int 	apply_case_two(t_data *data, int current, int c);
int 	apply_case_three(t_data *data, int current, int c);
int 	apply_case_four(t_data *data, int current, int c);

void 	ft_printStacks(t_stack *s); //rm
void 	printStack(t_stack *s); //rm
void 	printStacks(t_stack *a, t_stack *b); //rm

#endif
