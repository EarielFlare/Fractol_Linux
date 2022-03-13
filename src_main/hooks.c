/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:48:48 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:06:10 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (keycode == 1752 || keycode == 109)
		vars->img.fractol.m_koef = init_complex(1.0, 2.0);
	else if (keycode == 1746 || keycode == 104)
		vars->img.is_help = !vars->img.is_help;
	kbrd_color_check(vars, keycode);
	render_func(vars);
	return (0);
}

void	kbrd_color_check(t_vars *vars, int keycode)
{
	if (vars->img.pq2 + vars->img.pq1 < 255 && vars->img.pq2 < 121)
	{
		if (keycode == 1749 || keycode == 101)
			vars->img.pq2 = vars->img.pq2 + 1;
		if (keycode == 1751 || keycode == 100)
			vars->img.pq1 = vars->img.pq1 + 1;
		if (vars->img.pq2 > vars->img.pq1)
			vars->img.pq1 = vars->img.pq2;
	}
	if ((keycode == 1738 || keycode == 113) && vars->img.pq2 > 10)
		vars->img.pq2 = vars->img.pq2 - 1;
	if ((keycode == 1734 || keycode == 97) && vars->img.pq1 > 10)
		vars->img.pq1 = vars->img.pq1 - 1;
	if (vars->img.pq1 < vars->img.pq2)
		vars->img.pq2 = vars->img.pq1;
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (!vars->img.is_fixed)
	{
		vars->img.fractol.c_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.c_koef.im
			= -(vars->img.ld_corner.im + (vars->img.y_step * (y)));
		vars->img.fractol.m_koef.re
			= vars->img.ld_corner.re + (vars->img.x_step * (x));
		vars->img.fractol.m_koef.im
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
