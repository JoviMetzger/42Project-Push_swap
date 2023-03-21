/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:02:52 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/09 12:19:45 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int content;
	int	index;
	struct s_stack	*next;
} t_list;

typedef struct s_data
{
	t_list *stack_a;
	t_list *stack_b;
	
    int len;
    int limit;   
} t_data;

t_list	*ft_lstnew(void *content);
void	ft_error(char *msg);
void	ft_free(char **str);
void	ft_checking_arg(int argc, char **arg);

#endif
