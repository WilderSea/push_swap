/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:56:00 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/20 20:17:25 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_transform_array(long int *stack_a, int len, long int *aux)
{
	int	min_pos;
	int	min;
	int	i;
	int	j;

	i = 0;
	min_pos = 0;
	while (i < len)
	{
		min = INT_MAX;
		j = 0;
		while (j < len)
		{
			if ((aux[j] < min && aux[j] != INT_MIN) || \
					(i == 0 && aux[j] == INT_MIN))
			{
				min = aux[j];
				min_pos = j;
			}
			j++;
		}
		aux[min_pos] = INT_MIN;
		stack_a[min_pos] = i;
		i++;
	}
}

long int	ft_long_atoi(const char *str)
{
	int			i;
	long int	sum;
	int			neg;

	i = 0;
	sum = 0;
	neg = 1;
	while (str[i])
	{
		while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || \
					str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
			i++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				neg = -1;
		while (str[i] && ((str[i] >= '0' && str[i] <= '9')))
		{
			sum = (sum * 10) + (str[i] - '0');
			i++;
		}
		return (sum * neg);
	}
	return (0);
}

int	ft_strisdigit(char *argv)
{
	int	i;

	i = 0;
	if ((argv[0] == '-' || argv[0] == '+') && argv[1] == '\0')
		return (0);
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;
	int	result;

	n = 0;
	result = 0;
	while (s1[n] || s2[n])
	{
		if (s1[n] != s2[n])
		{
			result = s1[n] - s2[n];
			return (result);
		}
		result = 0;
		n++;
	}
	return (result);
}
