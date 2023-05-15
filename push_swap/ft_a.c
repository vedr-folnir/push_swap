/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:54:05 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/15 17:08:50 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(Liste *liste)
{
	int		x;
	Element	*actuel;

	actuel = liste->premier->suivant;
	x = actuel->nombre;
	actuel->nombre = actuel->suivant->nombre;
	actuel->suivant->nombre = x;
}

/*void	pa(Liste *liste_a, Liste *liste_b)
{
	int		x;
	Element	*actuel_a;
	Element	*actuel_b;

	actuel_a = liste_a->premier->suivant;
	actuel_b = liste_b->premier->suivant;
	x = actuel_b->nombre;
	actuel_b->nombre = actuel_a->nombre;
	actuel_a->nombre = x;
}*/

void	pa(Liste *liste_a, Liste *liste_b)
{
	Element	*actuel_b;

	actuel_b = liste_b->premier->suivant;
	insertion(liste_a, actuel_b->nombre);
	suppression(liste_b);
}

void	ra(Liste *liste)
{
	int		x;
	Element	*actuel;

	actuel = liste->premier->suivant;
	x = actuel->nombre;
	while (actuel->suivant != NULL)
	{
		actuel->nombre = actuel->suivant->nombre;
		actuel = actuel->suivant;
	}
	actuel->nombre = x;
}

void	rra(Liste *liste)
{
	int		x;
	int		y;
	Element	*actuel;

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
