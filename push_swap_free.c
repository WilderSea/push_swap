/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:36:14 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/22 19:56:22 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(int argc, t_data *datos, char **valid, char **splited)
{
	free(datos->stack_a);
	free(datos->stack_b);
	if (argc == 2)
		ft_free_split(splited);
	free(valid);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

void	check_leaks(void)
{
	system("leaks -q push_swap");
}

int	size_array(char **digits_array)
{
	int	i;
	int	arr_len;

	i = 0;
	arr_len = 0;
	while (digits_array[i])
	{
		arr_len++;
		i++;
	}
	return (arr_len);
}
