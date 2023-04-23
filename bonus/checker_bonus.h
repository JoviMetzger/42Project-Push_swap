/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 21:18:33 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/23 19:27:54 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		content;
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
int		stack_sorted(t_stack *stack);

void		checking_arg(int argc, char **argv);
void		fill_stack(t_data *data, int argc, char **argv);

#endif
