/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:49:27 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/22 20:09:18 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_maxmin(long int *aux, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((aux[i] > INT_MAX) || (aux[i] < INT_MIN))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

void	ft_number_converter(char **digits_array, t_data *datos)
{
	int			i;
	long int	*aux;

	i = 0;
	while (digits_array[i])
	{
		i++;
		datos->max_size++;
	}
	aux = NULL;
	datos->stack_a = malloc(sizeof(long int) * (datos->max_size));
	aux = malloc(sizeof(long int) * (datos->max_size));
	i = 0;
	while (digits_array[i] && i <= (datos->max_size))
	{
		aux[i] = ft_long_atoi(digits_array[i]);
		i++;
	}
	ft_check_maxmin(aux, datos->max_size);
	ft_transform_array(datos->stack_a, datos->max_size, aux);
	free(aux);
}

char	**ft_check_duplicated(char **digits_array)
{
	int	i;
	int	j;
	int	arr_len;

	i = 0;
	arr_len = size_array(digits_array);
	while (i <= arr_len)
	{
		j = i + 1;
		while (j <= arr_len && digits_array[j])
		{
			if (ft_atoi(digits_array[i]) == ft_atoi(digits_array[j]))
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (digits_array);
}

char	**ft_check_digit(int argc, char **argv, int num_args)
{
	int		i;
	char	**result;

	result = ft_calloc(sizeof(char **), num_args + 1);
	i = 0;
	(void)argc;
	while (argv[i])
	{
		if (ft_strisdigit(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		else
			result[i] = argv[i];
		i++;
	}
	return (result);
}
