/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:49:31 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 18:42:40 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data *p_img, int x, int y, t_color color)
{
	int	i;

	i = (x * p_img->bits_per_pixel / 8)
		+ (y * p_img->line_length);
	p_img->addr[i] = color.channel[3];
	p_img->addr[++i] = color.channel[2];
	p_img->addr[++i] = color.channel[1];
	p_img->addr[++i] = color.channel[0];
}

int	close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}
