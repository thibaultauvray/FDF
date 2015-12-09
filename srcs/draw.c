/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 14:51:31 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/16 13:46:30 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	set_p(int x, int y, int z, t_env *e)
{
	t_point	p;
	t_point	p2;

	p2.x = x;
	p2.y = y;
	p2.z = z;
	p.x = get_x(x, y, e->len);
	p.y = get_y(p2, e->z, e->len, e->marg);
	p.z = z;
	return (p);
}

void			draw_tab2(t_env *e, int x, int y)
{
	int	z;
	int	z1;

	z1 = e->tab[y][x];
	if (e->tab[y + 1])
	{
		if (x <= e->tab[y + 1][0])
		{
			z = e->tab[y + 1][x];
			draw_line(set_p(x + e->x, y, z1, e),
					set_p(x + e->x, y + 1, z, e), e);
		}
	}
	if (x < e->tab[y][0])
	{
		z = e->tab[y][x + 1];
		draw_line(set_p(x + e->x, y, z1, e),
				set_p(x + e->x + 1, y, z, e), e);
	}
}

void			draw_tab3(t_env *e)
{
	int	y;
	int x;

	y = 0;
	x = 1;
	while (e->tab[y])
	{
		while (x <= e->tab[y][0])
		{
			draw_tab2(e, x, y);
			x++;
		}
		y++;
		x = 1;
	}
}

void			draw_tab(t_env *e)
{
	draw_tab3(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
