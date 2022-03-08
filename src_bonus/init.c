/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:48:42 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:38:07 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_image(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx,
			vars->win_width, vars->win_height);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel, &vars->img.line_length,
			&vars->img.endian);
}

void	init_fractol(t_vars *vars)
{
	set_defaults(vars);
	vars->win = mlx_new_window(vars->mlx,
			vars->win_width, vars->win_height, "FRACTOL");
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
	mlx_hook(vars->win, 4, 1L<<2, mouse_hook, vars);
	mlx_hook(vars->win, 6, 1L<<6, mouse_move, vars);
	mlx_hook(vars->win, 17, 0L, close_win, vars);
}

void	set_defaults(t_vars *vars)
{
	vars->win_width = WIDTH;
	vars->win_height = HEIGHT;
	vars->img.max_iter = 50;
	vars->img.zoom = 1.0;
	vars->img.move_speed = 4;
	vars->img.pq1 = 120;
	vars->img.pq2 = 80;
	vars->img.clr_shift = 2;
	vars->img.is_fixed = true;
	vars->img.is_help = false;
	vars->img.ru_corner.re = 2.0;
	vars->img.ld_corner.re = -2.0;
	vars->img.ru_corner.im = (HEIGHT * (vars->img.ru_corner.re
				- vars->img.ld_corner.re) / WIDTH) / 2;
	vars->img.ld_corner.im = -vars->img.ru_corner.im;
	steps_calc(&vars->img);
	win_rescale(&vars->img);
	vars->img.fractol.c_koef = init_complex(-0.4, 0.6);
	vars->img.fractol.i_koef = init_complex(0.28, 0.80);
	vars->img.fractol.w_koef = init_complex(0.24, 0.24);
	vars->img.fractol.m_koef = init_complex(1.0, 2.0);
	vars->img.fractol.l_koef = init_complex(2.05, 2.0);
}
