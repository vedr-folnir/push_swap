/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:21:39 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/19 14:14:59 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include "push_swap.h"

static void	lettre(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	reduc(const char *str, int i, long int result)
{
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > 2147483647)
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	long int	result;

	i = 0;
	j = 1;
	result = 0;
	lettre(str);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			j = j * -1;
		}
		i++;
	}
	result = reduc(str, i, result);
	return (result * j);
}
