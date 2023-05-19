/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:28:45 by hlasota           #+#    #+#             */
/*   Updated: 2023/05/19 14:10:28 by hlasota          ###   ########.fr       */
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
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
		actuel = actuel->suivant;
	}
}

Liste	*copier_vide(Liste *liste)
{
	int		j;
	Liste	*l_v;

	j = lst_size(liste);
	l_v = initialisation();
	while (j > 0)
	{
		insertion(l_v, 0);
		j--;
	}
	return (l_v);
}

void changer_val(Liste *liste, int where, int val)
{
	Element	*actuel;

	actuel = liste->premier->suivant;
	while (where > 0)
	{
		where--;
		actuel = actuel->suivant;
	}
	actuel->nombre = val;
}

int	ch_min(Liste *liste, Liste *change, int a_min, int val)
{
	int		min;
	Element	*actuel;
	int		i;
	int		i_min;

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

int ch_max(Liste *liste)
{
	Element	*actuel;
	int	max;

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

void	simple(Liste *liste, Liste *change)
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

int	main(int argc, char const *argv[])
{
	Liste	*liste_b;
	Liste	*liste_a;
	int 	i;

	liste_b = initialisation();
	liste_a = initialisation();
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
    return 0;
}