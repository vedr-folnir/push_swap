/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:11:27 by hlasota           #+#    #+#             */
/*   Updated: 2023/06/22 13:15:28 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_liste *liste)
{
	t_element	*actuel;

	actuel = liste->premier->suivant;
	while (actuel->suivant != NULL)
	{
		if ((actuel->nombre) >= (actuel->suivant->nombre))
		{
			return (0);
		}
		actuel = actuel->suivant;
	}
	return (1);
}

void	doublon(t_liste *liste, int n)
{
	t_element	*actuel;

	actuel = liste->premier->suivant;
	while (actuel->suivant != NULL)
	{
		if ((actuel->nombre) == n)
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		actuel = actuel->suivant;
	}
}

void	mid_decal(int taille, int exp, t_liste	*liste, t_liste *temp)
{
	int			i;
	t_element	*actuel;

	actuel = liste->premier->suivant;
	i = 0;
	while (i < taille)
	{
		if (is_sorted(liste))
		{
			break ;
		}
		if ((actuel->nombre >> exp & 1) == 1)
		{
			pa(temp, liste);
			write(1, "pb\n", 3);
			actuel = liste->premier->suivant;
		}
		else
		{
			ra(liste);
			write(1, "ra\n", 3);
		}
		i++;
	}
}

void	decal(t_liste *liste, t_liste *temp)
{
	int			taille;
	int			max;
	int			exp;

	max = ch_max(liste);
	exp = 0;
	taille = lst_size(liste);
	while (max >> exp > 0)
	{
		mid_decal(taille, exp, liste, temp);
		while (lst_size(temp) != 0)
		{
			pa(liste, temp);
			write(1, "pa\n", 3);
		}
		exp += 1;
	}
}

void	verif(int argc, char const *argv[], t_liste *liste, int i)
{
	char	**arg;

	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		i = 0;
		while (arg[i])
		{
			insertion(liste, ft_atoi(arg[i]));
			doublon(liste, ft_atoi(arg[i]));
			i++;
		}
	}
	else
	{
		while (i < argc)
		{
			insertion(liste, ft_atoi(argv[i]));
			doublon(liste, ft_atoi(argv[i]));
			i++;
		}
	}
}
