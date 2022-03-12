/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:20:44 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/06 16:54:38 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_prompt(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl("You can specify from 1 to 7 names of fractals");
	ft_putendl("List of available fractals:");
	ft_putendl(" ⚬➡️	Julia");
	ft_putendl(" ⚬➡️	Mandelbrot");
	ft_putendl(" ⚬➡️	Matka");
	ft_putendl(" ⚬➡️	Valera");
	ft_putendl(" ⚬➡️	Islands");
	ft_putendl(" ⚬➡️	Web");
	ft_putendl(" ⚬➡️	Lotos");
}

void	draw_help_1(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 115, 40, 0x0000FFCC,
		"Controls");
	mlx_string_put(vars->mlx, vars->win, 40, 65, 0x0000FFCC,
		"Zoom           - Scroll");
	mlx_string_put(vars->mlx, vars->win, 40, 90, 0x0000FFCC,
		"Move           - Arrows");
	mlx_string_put(vars->mlx, vars->win, 40, 115, 0x0000FFCC,
		"Mouse Lock     - Space");
	mlx_string_put(vars->mlx, vars->win, 40, 140, 0x0000FFCC,
		"Iterations     - + / -");
	mlx_string_put(vars->mlx, vars->win, 40, 165, 0x0000FFCC,
		"Contrast       - Q / E");
	mlx_string_put(vars->mlx, vars->win, 40, 190, 0x0000FFCC,
		"Brightness     - A / D");
	mlx_string_put(vars->mlx, vars->win, 40, 215, 0x0000FFCC,
		"Color Shift    - C");
	mlx_string_put(vars->mlx, vars->win, 40, 240, 0x0000FFCC,
		"Close Help     - H");
}

void	draw_help_2(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 80, 460, 0x0000FFCC,
		"Fractal Reset");
	mlx_string_put(vars->mlx, vars->win, 40, 485, 0x0000FFCC,
		"Islands reset       - I");
	mlx_string_put(vars->mlx, vars->win, 40, 510, 0x0000FFCC,
		"Mandelbrot reset    - M");
	mlx_string_put(vars->mlx, vars->win, 40, 535, 0x0000FFCC,
		"Lotos reset         - L");
	mlx_string_put(vars->mlx, vars->win, 40, 560, 0x0000FFCC,
		"Web reset           - W");
}
