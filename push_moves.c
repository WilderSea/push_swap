/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:37:55 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/20 20:47:13 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_data *datos)
{
	int	i;

	i = datos->max_size;
	if (datos->size_b < 1)
		return ;
	while (i > 0)
	{
		datos->stack_a[i] = datos->stack_a[i - 1];
		i--;
	}
	datos->stack_a[0] = datos->stack_b[0];
	while (i < datos->size_b)
	{
		datos->stack_b[i] = datos->stack_b[i + 1];
		i++;
	}
	datos->max_size++;
	datos->size_b--;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_data *datos)
{
	int	i;

	i = datos->size_b;
	if (datos->max_size < 1)
		return ;
	while (i > 0)
	{
		datos->stack_b[i] = datos->stack_b[i - 1];
		i--;
	}
	datos->stack_b[0] = datos->stack_a[0];
	while (i < datos->max_size)
	{
		datos->stack_a[i] = datos->stack_a[i + 1];
		i++;
	}
	datos->size_b++;
	datos->max_size--;
	write(1, "pb\n", 3);
}
