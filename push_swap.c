/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:30:40 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/23 20:22:55 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(t_data *datos)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = ft_stack_is_sorted(datos);
	datos->stack_b = ft_calloc(sizeof(long int), datos->max_size);
	if (sorted)
		return (1);
	if (datos->max_size == 2)
		ft_sort_two(datos);
	else if (datos->max_size == 3)
		ft_sort_three(datos);
	else if (datos->max_size <= 5)
		ft_sort_five(datos);
	else
		ft_radix_sort(datos);
	return (0);
}

char	**ft_split_args(char **argv, int *num_args)
{
	char	**def_args;

	def_args = ft_split(argv[1], ' ');
	*num_args = 0;
	while (def_args[*num_args])
		(*num_args)++;
	return (def_args);
}

int	main(int argc, char **argv)
{
	t_data	datos;
	char	**valid_array;
	char	**splited_args;
	int		num_args;

	atexit(check_leaks);
	if (argc == 1)
		exit(1);
	else if (argc == 2)
		splited_args = ft_split_args(argv, &num_args);
	else
	{
		splited_args = &argv[1];
		num_args = argc;
	}
	valid_array = ft_check_digit(argc, splited_args, num_args);
	valid_array = ft_check_duplicated(valid_array);
	datos.max_size = 0;
	ft_number_converter(valid_array, &datos);
	ft_push_swap(&datos);
	ft_free_all(argc, &datos, valid_array, splited_args);
	return (0);
}
