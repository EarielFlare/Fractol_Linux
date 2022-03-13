/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:11:07 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:38:26 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	render_func(void *strct)
{
	t_vars	*vars;

	vars = (t_vars *)strct;
	calc_fractol_1(&vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	if (vars->img.is_help)
	{
		draw_help_1(vars);
		draw_help_2(vars);
	}
	return (0);
}

int	choose_fractol(t_vars *vars, char *str)
{
	if (!ft_strncmp("Julia", str, ft_strlen(str)))
		vars->img.proc = iter_julia;
	else if (!ft_strncmp("Matka", str, ft_strlen(str)))
		vars->img.proc = iter_matka;
	else if (!ft_strncmp("Valera", str, ft_strlen(str)))
		vars->img.proc = iter_valera;
	else if (!ft_strncmp("Islands", str, ft_strlen(str)))
		vars->img.proc = iter_islands;
	else if (!ft_strncmp("Web", str, ft_strlen(str)))
		vars->img.proc = iter_web;
	else if (!ft_strncmp("Mandelbrot", str, ft_strlen(str)))
		vars->img.proc = iter_mandelbrot;
	else if (!ft_strncmp("Lotos", str, ft_strlen(str)))
		vars->img.proc = iter_lotos;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1 || !choose_fractol(&vars, argv[argc - 1]))
		print_prompt();
	else
	{
		vars.mlx = mlx_init();
		init_fractol(&vars);
		init_image(&vars);
		render_func(&vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
