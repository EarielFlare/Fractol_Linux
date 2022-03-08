/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:48:48 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:36:58 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_win(vars);
	else if (keycode == 61 || keycode == 65451)
		vars->img.max_iter = vars->img.max_iter + 2;
	else if (keycode == 45 || keycode == 65453)
		vars->img.max_iter = vars->img.max_iter - 2;
	else if (keycode == 32)
		vars->img.is_fixed = !vars->img.is_fixed;
	else if (keycode == 1755 || keycode == 105)
		vars->img.fractol.i_koef = init_complex(0.28, 0.80);
	else if (keycode == 1752 || keycode == 109)
		vars->img.fractol.m_koef = init_complex(1.0, 2.0);
	else if (keycode == 1732 || keycode == 108)
		vars->img.fractol.l_koef = init_complex(2.05, 2.0);
	else if (keycode == 1731 || keycode == 119)
		vars->img.fractol.w_koef = init_complex(0.24, 0.24);
	else if (keycode == 1746 || keycode == 104)
		vars->img.is_help = !vars->img.is_help;
	kbrd_color_check(vars, keycode);
	kbrd_move_check_ud(vars, keycode);
	kbrd_move_check_lr(vars, keycode);
	render_func(vars);
	return (0);
}

void	kbrd_move_check_ud(t_vars *vars, int keycode)
{
	if (keycode == 65362)
	{
		vars->img.ld_corner.im = vars->img.ld_corner.im
			- vars->img.move_speed * vars->img.x_step;
		vars->img.ru_corner.im = vars->img.ru_corner.im
			- vars->img.move_speed * vars->img.x_step;
	}
	else if (keycode == 65364)
	{
		vars->img.ld_corner.im = vars->img.ld_corner.im
			+ vars->img.move_speed * vars->img.x_step;
		vars->img.ru_corner.im = vars->img.ru_corner.im
			+ vars->img.move_speed * vars->img.x_step;
	}
}

void	kbrd_move_check_lr(t_vars *vars, int keycode)
{
	if (keycode == 65361)
	{
		vars->img.ld_corner.re = vars->img.ld_corner.re
			- vars->img.move_speed * vars->img.x_step;
		vars->img.ru_corner.re = vars->img.ru_corner.re
			- vars->img.move_speed * vars->img.x_step;
	}
	else if (keycode == 65363)
	{
		vars->img.ld_corner.re = vars->img.ld_corner.re
			+ vars->img.move_speed * vars->img.x_step;
		vars->img.ru_corner.re = vars->img.ru_corner.re
			+ vars->img.move_speed * vars->img.x_step;
	}
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (!vars->img.is_fixed)
	{
		vars->img.fractol.c_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.c_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.i_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.i_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.m_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.m_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.l_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.l_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.w_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.w_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		render_func(vars);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	vars->img.mouse_x = x;
	vars->img.mouse_y = y;
	vars->img.zoom = 0.9;
	if (keycode == 4)
		win_rescale(&vars->img);
	else if (keycode == 5)
	{
		vars->img.zoom = 1 / vars->img.zoom;
		win_rescale(&vars->img);
	}
	render_func(vars);
	return (0);
}
