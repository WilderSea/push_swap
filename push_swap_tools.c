/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:32:03 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/21 12:23:44 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_up_or_down(t_data *datos, int index)
{
	int	middle;

	middle = datos->max_size / 2;
	if (((datos->max_size - 1) - index) < (index - 0))
		ft_rra(datos);
	else
		ft_ra(datos);
	return (datos->stack_a);
}

int	ft_find_index_smallest(t_data *datos, int *smallest)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	(*smallest) = datos->stack_a[0];
	while (i < datos->max_size)
	{
		if ((*smallest) > datos->stack_a[i])
		{
			(*smallest) = datos->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_stack_is_sorted(t_data *datos)
{
	int	i;
	int	asc;
	int	desc;

	i = 0;
	asc = 1;
	desc = 1;
	while ((asc == 1 || desc == 1) && i < datos->max_size - 1)
	{
		if (datos->stack_a[i] < datos->stack_a[i + 1])
			desc = 0;
		else if (datos->stack_a[i] > datos->stack_a[i + 1])
			asc = 0;
		i++;
	}
	if (asc == 1)
		return (1);
	else if (desc == 1)
		return (0);
	else
		return (0);
	return (2);
}
