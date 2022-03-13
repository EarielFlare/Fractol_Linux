/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:54:36 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:37:05 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_color	get_color_left(t_data *p_img)
{
	t_color	color;

	color.channel[0] = 0;
	color.channel[1] = p_img->point.color.channel[1] / 2
		+ p_img->point.color_last.channel[1] / 2;
	color.channel[2] = p_img->point.color.channel[2] / 2
		+ p_img->point.color_last.channel[2] / 2;
	color.channel[3] = p_img->point.color.channel[3] / 2
		+ p_img->point.color_last.channel[3] / 2;
	return (color);
}

t_color	get_color(t_data *p_img)
{
	t_color	color;
	double	t;

	t = (double)p_img->point.iter * 6 / p_img->max_iter;
	color.channel[0] = 0;
	color.channel[(0 + p_img->clr_shift) % 3 + 1]
		= (sinf(t + 2) * p_img->pq2 + p_img->pq1);
	color.channel[(1 + p_img->clr_shift) % 3 + 1]
		= (sinf(t + 4) * p_img->pq2 + p_img->pq1);
	color.channel[(2 + p_img->clr_shift) % 3 + 1]
		= (sinf(t + 0) * p_img->pq2 + p_img->pq1);
	return (color);
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
	if (keycode == 1747 || keycode == 99)
		vars->img.clr_shift = vars->img.clr_shift + 1;
}
