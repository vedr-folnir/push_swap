/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:28:45 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/15 17:11:00 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"

Liste	*initialisation(void)
{
	Liste	*liste;
	Element	*element;

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

void	insertion(Liste *liste, int nvNombre)
{
	Element	*nouveau;
	Element	*actuel;

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

void	suppression(Liste *liste)
{
	Element	*a_supprimer;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	if (liste->premier != NULL)
	{
		a_supprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(a_supprimer);
	}
}

void	afficher_liste(Liste *liste)
{
	Element	*actuel;

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

int	lst_size(Liste *liste)
{
	int		x;
	Element	*actuel;

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

/*Liste	lst_last(Liste *lst)
{
	Element *actuel;

	actuel = lst->premier;
	while (actuel->suivant != NULL)
	{
		if (!actuel->suivant->suivant)
			return (actuel);
		actuel = actuel->suivant;

	}
	return (actuel);
}
*/

int	is_sorted(Liste *liste)
{
	Element	*actuel;

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

void	doublon(Liste *liste, int n)
{
	Element	*actuel;


	actuel = liste->premier->suivant;
	while (actuel->suivant != NULL)
	{
		if ((actuel->nombre) == n)
		{
			write(1,"ERROR\n",6);
			exit(EXIT_FAILURE);
		}
		actuel = actuel->suivant;
	}
}

int	main(int argc, char const *argv[])
{
	Liste	*ListeB;
	Liste	*ListeA;
	int 	i;

	ListeB = initialisation();
	ListeA = initialisation();
	i = 1;
	if (argc == 1)
		return 0;

	if (argc == 2)
	{
		char **arg;
		int	i;

		arg = ft_split(argv[1], ' ');
		i = 0;
		while (arg[i])
		{
			insertion(ListeB, ft_atoi(arg[i]));
			doublon(ListeB, ft_atoi(arg[i]));
			i++;
		}

	}
	else
	{
		while (i < argc)
		{
			insertion(ListeB, ft_atoi(argv[i]));
			doublon(ListeB, ft_atoi(argv[i]));
			i++;
		}
	}
    afficher_liste(ListeB);
    afficher_liste(ListeA);
    
	pa(ListeA, ListeB);
    afficher_liste(ListeB);
    afficher_liste(ListeA);
    
    return 0;
}