/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:02:04 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/16 13:36:34 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_nline(char *str)
{
	int		i;
	int		cpt;
	char	*line;

	cpt = 0;
	i = open(str, O_RDONLY, 1);
	while (get_next_line(i, &line) == 1)
	{
		free(line);
		cpt++;
	}
	if (line)
		cpt++;
	return (cpt);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		*ft_put_int(char *str)
{
	char	**chartab;
	int		*tab;
	int		i;
	int		j;

	chartab = ft_strsplit(str, ' ');
	i = ft_tablen(chartab);
	tab = (int*)malloc((i + 1) * (sizeof(*tab)));
	tab[0] = i;
	j = 0;
	while (++j <= i)
		tab[j] = ft_atoi(chartab[j - 1]);
	return (tab);
}
