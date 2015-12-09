/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 12:17:23 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 12:28:23 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uint32		swap_endian(t_uint32 in)
{
	t_uint32	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

t_uint32		true_color(void *mlx, int endian, int rgb)
{
	t_uint32	color;

	color = mlx_get_color_value(mlx, rgb);
	if (endian == MLX_BIG_ENDIAN)
		color = swap_endian(color);
	return (color);
}

void			pxl_to_img(t_env *e, int x, int y, t_uint32 color)
{
	int		pxi;

	pxi = (x * e->szl) + (y * (e->bpx / 8));
	ft_memcpy(e->edit + pxi, &color, e->bpx / 8);
}
