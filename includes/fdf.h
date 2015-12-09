/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauvray <tauvray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:47:46 by tauvray           #+#    #+#             */
/*   Updated: 2015/02/14 14:05:06 by tauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define CTE 0.82
# define TWIDTH 3
# define MLX_BIG_ENDIAN 1
# define THEIGHT 4

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	int				**tab;
	int				len;
	void			*img;
	char			*edit;
	int				marg;
	int				szl;
	int				bpx;
	int				endiant;
	int				x;
	int				y;
	int				c;
	double			z;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_bres
{
	int				w;
	int				h;
	int				dx1;
	int				dy1;
	int				dx2;
	int				dy2;
	int				longest;
	int				shortest;
	int				numerator;
	int				i;
}					t_bres;

typedef unsigned int	t_uint32;

void				ft_error_nofile();
void				ft_errors_valid(char *str);
void				draw_tab(t_env *e);
void				draw_line(t_point p, t_point p2, t_env *e);
void				ft_free(char ***tab);
int					ft_max_width(t_env e);
int					ft_max_height(t_env e);
int					key_hook(int keycode, t_env *e);
int					key_hook2(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				pxl_to_img(t_env *e, int x, int y, t_uint32 color);
t_env				initiz_env_e(t_env e);
int					get_y(t_point p, double haut, int len, int marg);
int					get_x(int x, int y, int len);
int					*ft_put_int(char *str);
int					ft_tablen(char **tab);
int					ft_nline(char *str);
#endif
