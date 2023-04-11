/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_list.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmetzger <jmetzger@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 22:28:19 by jmetzger      #+#    #+#                 */
/*   Updated: 2023/04/03 13:03:09 by jmetzger      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 
int	ft_lstsize_a(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//
t_stack	*ft_lstlast_a(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

//
void	ft_lstadd_back_a(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_lstlast_a(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

//
t_stack	*ft_lstnew_a(int value)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}
