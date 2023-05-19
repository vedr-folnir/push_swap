/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:28:45 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/19 16:09:47 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
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

void	afficher_liste(t_liste *liste)
{
	t_element	*actuel;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	actuel = liste->premier->suivant;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
	// faut changer les print en ajoutant ft_printf
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

int	main(int argc, char const *argv[])
{
	t_liste	*liste_b;
	t_liste	*liste_a;
	int		i;
	char	**arg;

	liste_b = initialisation();
	liste_a = initialisation();
	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		i = 0;
		while (arg[i])
		{
			insertion(liste_b, ft_atoi(arg[i]));
			doublon(liste_b, ft_atoi(arg[i]));
			i++;
		}
	}
	else
	{
		while (i < argc)
		{
			insertion(liste_b, ft_atoi(argv[i]));
			doublon(liste_b, ft_atoi(argv[i]));
			i++;
		}
	}
	afficher_liste(liste_b);
	liste_a = copier_vide(liste_b);
	simple(liste_b, liste_a);
	afficher_liste(liste_a);
	//printf("%d\n", 15&9);
	return (0);
}
