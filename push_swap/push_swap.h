/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pus_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlasota <hlasota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:26:04 by cspreafi          #+#    #+#             */
/*   Updated: 2023/05/11 14:08:21 by hlasota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};



Liste 	*initialisation();
void	insertion(Liste *liste, int nvNombre);
void	suppression(Liste *liste);
void	afficherListe(Liste *liste);
void	sa(Liste *liste);
void	pa(Liste *listeA, Liste *listeB);
int	lst_size(Liste *liste);
void	ra(Liste *liste);
void	rra(Liste *liste);
char	**ft_piece_2(char **dst, int *lw, const char *str, char c);
char	**ft_split(const char *str, char c);
int	ft_atoi(const char *str);
int	is_sorted(Liste *liste);
void	doublon(Liste *liste, int n);
#endif
