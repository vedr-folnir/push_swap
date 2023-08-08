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

typedef struct s_element	t_element;
struct s_element
{
	int			nombre;
	t_element	*suivant;
};
typedef struct s_liste		t_liste;
struct s_liste
{
	t_element	*premier;
};

t_liste	*initialisation(void);
void	insertion(t_liste *liste, int nvNombre);
void	suppression(t_liste *liste);
void	afficherListe(t_liste *liste);
void	sa(t_liste *liste);
void	pa(t_liste *listeA, t_liste *listeB);
void	pb(t_liste *liste_a, t_liste *liste_b);
int		lst_size(t_liste *liste);
void	ra(t_liste *liste);
void	rra(t_liste *liste);
char	**ft_piece_2(char **dst, int *lw, const char *str, char c);
char	**ft_split(const char *str, char c);
int		ft_atoi(const char *str);
int		is_sorted(t_liste *liste);
void	doublon(t_liste *liste, int n);
t_liste	*copier_vide(t_liste *liste);
void	changer_val(t_liste *liste, int where, int val);
int		ch_min(t_liste *liste, t_liste *change, int a_min, int val);
int		ch_max(t_liste *liste);
void	simple(t_liste *liste, t_liste *change);
void	mid_decal(int taille, int exp, t_liste	*liste, t_liste *temp);
void	decal(t_liste *liste, t_liste *temp);
void	verif(int argc, char const *argv[], t_liste *liste, int i);

#endif
