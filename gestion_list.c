/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:09:16 by hlasota           #+#    #+#             */
/*   Updated: 2023/06/22 13:21:45 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_liste	*initialisation(void)
{
	t_liste		*liste;
	t_element	*element;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
	if (liste == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;
	return (liste);
}

void	insertion(t_liste *liste, int nvNombre)
{
	t_element	*nouveau;
	t_element	*actuel;

	nouveau = malloc(sizeof(*nouveau));
	actuel = liste->premier;
	if (liste == NULL || nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	}
	nouveau->nombre = nvNombre;
	while (actuel->suivant != NULL)
		actuel = actuel->suivant;
	actuel->suivant = nouveau;
}

void	suppression(t_liste *liste)
{
	t_element	*a_supprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	if (liste->premier != NULL)
	{
		a_supprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(a_supprimer);
	}
}

int	lst_size(t_liste *liste)
{
	int			x;
	t_element	*actuel;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	actuel = liste->premier;
	x = 0;
	while (actuel->suivant != NULL)
	{
		x++;
		actuel = actuel->suivant;
	}
	return (x);
}
