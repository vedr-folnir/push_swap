/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:54:05 by hlasota           #+#    #+#             */
/*   Updated: 2023/08/08 11:14:26 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_liste *liste)
{
	int			x;
	t_element	*actuel;

	actuel = liste->premier->suivant;
	x = actuel->nombre;
	actuel->nombre = actuel->suivant->nombre;
	actuel->suivant->nombre = x;
}

void	pa(t_liste *liste_a, t_liste *liste_b)
{
	t_element	*actuel_b;

	actuel_b = liste_b->premier->suivant;
	insertion(liste_a, actuel_b->nombre);
	suppression(liste_b);
}

void	ra(t_liste *liste)
{
	int			x;
	t_element	*actuel;

	actuel = liste->premier->suivant;
	x = actuel->nombre;
	while (actuel->suivant != NULL)
	{
		actuel->nombre = actuel->suivant->nombre;
		actuel = actuel->suivant;
	}
	actuel->nombre = x;
}

void	rra(t_liste *liste)
{
	int			x;
	int			y;
	t_element	*actuel;

	actuel = liste->premier->suivant;
	x = actuel->nombre;
	while (actuel->suivant != NULL)
	{
		actuel = actuel->suivant;
		y = actuel->nombre;
		actuel->nombre = x;
		x = y;
	}
	liste->premier->suivant->nombre = x;
}
