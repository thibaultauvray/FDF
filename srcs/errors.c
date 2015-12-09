/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 11:59:06 by tauvray           #+#    #+#             */
/*   Updated: 2015/01/31 20:31:50 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error_nofile(void)
{
	ft_putendl("usage : ./fdf file1");
}

void		ft_errors_valid(char *str)
{
	int	i;

	i = open(str, O_RDONLY, 1);
	if (i < 0)
	{
		ft_putstr(str);
		ft_putendl(": No such file or directory");
		close(i);
		exit(0);
	}
	close(i);
}

void		ft_free(char ***tab)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
		{
			free(tab[y][x]);
			x++;
		}
		x = 0;
		free(tab[y]);
		y++;
	}
	free(tab);
}

t_env		initiz_env_e(t_env e)
{
	e.len = 20;
	e.marg = 10;
	e.x = 0;
	e.c = 0;
	e.y = 0;
	e.z = -0.5;
	e.tab = NULL;
	return (e);
}
