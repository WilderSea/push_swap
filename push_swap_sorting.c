/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:02:29 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/22 17:48:05 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_data *datos)
{
	int	i;

	i = 0;
	ft_sa(datos);
}

void	ft_sort_three(t_data *datos)
{
	int	i;

	i = 0;
	if ((datos->stack_a[i] > datos->stack_a[i + 1]) && (datos->stack_a[i] < \
				datos->stack_a[i + 2]))
		ft_sa(datos);
	else if ((datos->stack_a[i] > datos->stack_a[i + 1]) && \
			(datos->stack_a[i + 1] > datos->stack_a[i + 2]))
	{
		ft_sa(datos);
		ft_rra(datos);
	}
	else if ((datos->stack_a[i] > datos->stack_a[i + 1]) && \
			(datos->stack_a[i] > datos->stack_a[i + 2]))
		ft_ra(datos);
	else if ((datos->stack_a[i] < datos->stack_a[i + 1]) && \
			(datos->stack_a[i] < datos->stack_a[i + 2]) && \
			(datos->stack_a[i + 1] > datos->stack_a[i + 2]))
	{
		ft_sa(datos);
		ft_ra(datos);
	}
	else if ((datos->stack_a[i] < datos->stack_a[i + 1]) && \
			(datos->stack_a[i] > datos->stack_a[i + 2]))
		ft_rra(datos);
}

void	ft_sort_five(t_data *datos)
{
	int	smallest;
	int	smallest_index;

	datos->size_b = 0;
	while (datos->max_size > 3)
	{
		smallest_index = ft_find_index_smallest(datos, &smallest);
		while (datos->stack_a[0] != smallest)
			ft_up_or_down(datos, smallest_index);
		ft_push_b(datos);
	}
	ft_sort_three(datos);
	while (datos->size_b > 0)
		ft_push_a(datos);
}

int	num_bits(int num)
{
	if (num < 2)
		return (1);
	return (num_bits(num / 2) + 1);
}

void	ft_radix_sort(t_data *datos)
{
	int	i;
	int	bit;
	int	max_bites;

	bit = 0;
	max_bites = num_bits(datos->max_size);
	while (bit < max_bites)
	{
		i = 0;
		while (i < (datos->max_size + datos->size_b))
		{
			if (((datos->stack_a[0] >> bit) & 1) == 0)
				ft_push_b(datos);
			else
				ft_ra(datos);
			i++;
		}
		while (datos->size_b > 0)
			ft_push_a(datos);
		bit++;
	}	
}
