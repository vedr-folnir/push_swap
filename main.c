/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:28:45 by hlasota           #+#    #+#             */
/*   Updated: 2023/08/08 11:25:08 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_liste	*liste_b;
	t_liste	*liste_simple;
	t_liste	*temp;
	int		i;

	liste_b = initialisation();
	liste_simple = initialisation();
	temp = initialisation();
	i = 1;
	verif(argc, argv, liste_b, i);
	liste_simple = copier_vide(liste_b);
	simple(liste_b, liste_simple);
	
	t_element	*actuel;	

	actuel = temp->premier->suivant;
	while (actuel!= NULL)
	{
		printf("%d->h", actuel->nombre);
		actuel=actuel->suivant;
	}
	
	decal(liste_simple, temp);
/*
	t_element	*actuel;

	actuel = liste_simple->premier->suivant;
	printf("\n");
	while (actuel != NULL)
	{
		printf("%d->", actuel->nombre);
		actuel=actuel->suivant;
	}*/
	return (0);
}
