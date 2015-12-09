/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:52:26 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 14:01:33 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_hook3(int keycode, t_env *e)
{
	if (keycode == 119)
	{
		e->z = e->z - 0.1;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 115 && e->z < -0.3)
	{
		e->z = e->z + 0.1;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 65364)
	{
		e->marg = e->marg + 20;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	return (0);
}

int				key_hook2(int keycode, t_env *e)
{
	if (keycode == 65363)
	{
		e->x = e->x + 10;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 65362)
	{
		e->marg = e->marg - 20;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 65361)
	{
		e->x = e->x - 10;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	key_hook3(keycode, e);
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 65451)
	{
		e->len = e->len + 1;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 65453 && e->len > 1)
	{
		e->len = e->len - 1;
		mlx_destroy_image(e->mlx, e->img);
		expose_hook(e);
	}
	if (keycode == 65307)
	{
		exit(0);
	}
	key_hook2(keycode, e);
	return (0);
}
