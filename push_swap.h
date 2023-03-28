/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:31:24 by msintas-          #+#    #+#             */
/*   Updated: 2023/01/22 20:08:34 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	long int	*stack_a;
	long int	*stack_b;
	int			size_a;
	int			size_b;
	int			max_size;
}	t_data;

int			ft_strcmp(char *s1, char *s2);
int			ft_strisdigit(char *argv);
long int	ft_long_atoi(const char *str);
char		**ft_check_digit(int argc, char **argv, int num_args);
char		**ft_check_duplicated(char **digits_array);
void		ft_number_converter(char **digits_array, t_data *datos);
void		ft_check_maxmin(long int *aux, int size);
int			ft_find_index_smallest(t_data *datos, int *smallest);
int			ft_stack_is_sorted(t_data *datos);
void		ft_sort_two(t_data *datos);
void		ft_sort_three(t_data *datos);
void		ft_sort_five(t_data *datos);
void		ft_sa(t_data *datos);
void		ft_rra(t_data *datos);
void		ft_ra(t_data *datos);
void		ft_push_b(t_data *datos);
void		ft_push_a(t_data *datos);
long int	*ft_up_or_down(t_data *datos, int index);
void		ft_radix_sort(t_data *datos);
void		ft_transform_array(long int *stack_a, int len, long int *aux);
void		ft_free_split(char **split);
void		check_leaks(void);
int			size_array(char **digits_array);
void		ft_free_all(int argc, t_data *datos, char **valid, char **splited);

#endif
