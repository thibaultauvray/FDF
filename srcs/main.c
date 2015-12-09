/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:47:22 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/16 13:46:44 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->edit = mlx_get_data_addr(e->img, &(e->bpx), &(e->szl), &(e->endiant));
	draw_tab(e);
	return (0);
}

void				ft_gest_lib(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "fdf");
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}

void				ft_gnl(char *str)
{
	t_env	e;
	int		max;
	int		i;
	int		q;
	char	*line;

	q = 0;
	e = initiz_env_e(e);
	max = ft_nline(str) - 1;
	if (!(e.tab = (int **)malloc(sizeof(int *) * (max + 1))))
		ft_errors("Can't malloc 'tab'");
	e.tab[max] = '\0';
	i = open(str, O_RDONLY, 1);
	while (get_next_line(i, &line) == 1)
	{
		e.tab[q] = ft_put_int(line);
		q++;
		free(line);
		line = NULL;
	}
	ft_gest_lib(e);
}

int					main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_error_nofile();
		return (0);
	}
	ft_errors_valid(av[1]);
	ft_gnl(av[1]);
	return (0);
}
