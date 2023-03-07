/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:02:52 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/03/07 13:54:48 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

// typedef struct s_data
// {
// 	int				value;
// 	int				index;
// 	struct s_data	*next;
// } t_swap;

void ft_error(char *msg);
void    ft_free(char **str);
void ft_checking_arg(int argc, char **arg);

#endif
