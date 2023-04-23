/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:02:52 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/21 20:03:10 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

/*
* content	:	The number/value of the node.
* index		:	The index of the node.
* pos		:	The position of the node.
* future_pos	:	The future position in stack_a, where the element 
*			from stack_b should be in stack_a.
* cost_b	:	The cost of getting the element to the top of the stack_b.
* cost_a	:	The cost of getting the element to the right position in stack_a.
* next		:	The pointer to the next node.
*/

typedef struct s_stack
{
	int				content;
	int				index;
	int				pos;
	int				future_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

t_stack		*ft_lstlast_a(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*ft_lstnew_a(int value);
void		ft_lstadd_back_a(t_stack **stack, t_stack *new);
int		ft_lstsize_a(t_stack *lst);

void		ft_error(char *msg);
void		ft_free(t_stack **str);
char		**ft_free_array(char **s);
int		ft_min(t_stack *stack);
int		ft_max(t_stack *stack);
int		stack_sorted(t_stack *stack);

void		checking_arg(int argc, char **argv);

void		fill_stack(t_data *data, int argc, char **argv);
void		indexing(t_stack *stack);
void		sort_3(t_stack **stack);
void		sorting(t_data *data, int stack_size);
void		sorting_a(t_stack **stack_a);
void		find_future_position(t_stack **stack_a, t_stack **stack_b);
void		assign_position(t_stack **stack);
void		calculate_cost(t_stack **stack_a, t_stack **stack_b);
void		apply_move(t_stack **stack_a, t_stack **stack_b);
void		do_rotations(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		printStacksData(t_stack *stack_a, t_stack *stack_b);
void		printStacks(t_stack *stack_a, t_stack *stack_b);

#endif
