/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:50:43 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/30 12:53:35 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*copier_vide(t_liste *liste)
{
	int		j;
	t_liste	*l_v;

	j = lst_size(liste);
	l_v = initialisation();
	while (j > 0)
	{
		insertion(l_v, 0);
		j--;
	}
	return (l_v);
}

void	changer_val(t_liste *liste, int where, int val)
{
	t_element	*actuel;

	actuel = liste->premier->suivant;
	while (where > 0)
	{
		where--;
		actuel = actuel->suivant;
	}
	actuel->nombre = val;
}

int	ch_min(t_liste *liste, t_liste *change, int a_min, int val)
{
	int			min;
	t_element	*actuel;
	int			i;
	int			i_min;

	actuel = liste->premier->suivant;
	min = 2147483647;
	i = 1;
	i_min = 0;
	while (actuel != NULL)
	{
		if (actuel->nombre < min && actuel->nombre > a_min)
		{
			min = actuel->nombre;
			i_min = i;
		}
		i++;
		actuel = actuel->suivant;
	}
	changer_val(change, i_min -1, val);
	return (min);
}

int	ch_max(t_liste *liste)
{
	t_element	*actuel;
	int			max;

	actuel = liste->premier->suivant;
	max = actuel->nombre;
	while (actuel != NULL)
	{
		if (actuel->nombre > max)
			max = actuel->nombre;
		actuel = actuel->suivant;
	}
	return (max);
}

void	simple(t_liste *liste, t_liste *change)
{
	int	max;
	int	min;
	int	i;

	max = lst_size(liste);
	min = ch_min(liste, change, -2147483648, 1);
	i = 2;
	while (i != max + 1)
	{
		min = ch_min(liste, change, min, i);
		i++;
	}
}
