/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:00:17 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 14:00:53 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_x(int x, int y, int len)
{
	return ((x * len) + (1 * (y * len)));
}

int				get_y(t_point p, double haut, int len, int marg)
{
	return (((p.z * (haut * (len / 10.0))) + ((1 / 2.0) * (p.y * len))) + marg);
}
