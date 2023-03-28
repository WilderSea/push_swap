/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:44:29 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/20 20:52:47 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data *datos)
{
	int	aux;

	aux = datos->stack_a[0];
	datos->stack_a[0] = datos->stack_a[1];
	datos->stack_a[1] = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_ra(t_data *datos)
{
	int	i;
	int	aux;

	i = 0;
	aux = datos->stack_a[0];
	while (i < datos->max_size - 1)
	{
		datos->stack_a[i] = datos->stack_a[i + 1];
		i++;
	}
	datos->stack_a[datos->max_size - 1] = aux;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_data *datos)
{
	int	i;
	int	aux;

	i = datos->max_size;
	aux = datos->stack_a[datos->max_size - 1];
	while (i > 0)
	{
		datos->stack_a[i] = datos->stack_a[i - 1];
		i--;
	}
	datos->stack_a[0] = aux;
	ft_putstr_fd("rra\n", 1);
}
