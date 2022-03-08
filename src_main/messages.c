/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:20:44 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/06 18:11:58 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_prompt(void)
{
	ft_putendl_fd("Usage: ./fractol <name>", 1);
	ft_putendl_fd("You can specify from 1 to 2 names of fractals", 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd(" ⚬➡️	Julia", 1);
	ft_putendl_fd(" ⚬➡️	Mandelbrot", 1);
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
		"Close Help     - H");
}
