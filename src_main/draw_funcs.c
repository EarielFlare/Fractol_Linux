/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:10:30 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/13 22:00:24 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	steps_calc(t_data *p_img)
{
	p_img->x_step = (p_img->ru_corner.re - p_img->ld_corner.re) / WIDTH;
	p_img->y_step = (p_img->ru_corner.im - p_img->ld_corner.im) / HEIGHT;
}

void	win_rescale(t_data *p_img)
{
	p_img->ld_corner.re = p_img->ld_corner.re
		+ (((1 - p_img->zoom) * p_img->mouse_x) * p_img->x_step);
	p_img->ld_corner.im = p_img->ld_corner.im
		+ (((1 - p_img->zoom) * (p_img->mouse_y)) * p_img->y_step);
	p_img->ru_corner.re = p_img->ru_corner.re
		- (((1 - p_img->zoom) * (WIDTH - 1 - p_img->mouse_x)) * p_img->x_step);
	p_img->ru_corner.im = p_img->ru_corner.im
		- (((1 - p_img->zoom) * (HEIGHT - 1 - p_img->mouse_y)) * p_img->y_step);
	steps_calc(p_img);
}

void	calc_fractol_1(t_data *p_img)
{
	int		x;
	int		y;
	t_color	color_left;

	y = 1;
	while (y < HEIGHT)
	{
		x = 1;
		while (x < WIDTH)
		{
			p_img->fractol.new.re = p_img->ld_corner.re + (p_img->x_step * (x));
			p_img->fractol.new.im = p_img->ld_corner.im + (p_img->y_step * (y));
			p_img->point.iter = p_img->proc(&p_img->fractol, p_img->max_iter);
			p_img->point.color = get_color(p_img);
			put_pixel(p_img, x, y, p_img->point.color);
			color_left = get_color_left(p_img);
			p_img->point.color_last = p_img->point.color;
			put_pixel(p_img, x - 1, y, color_left);
			put_pixel(p_img, x, y - 1, p_img->point.color);
			put_pixel(p_img, x - 1, y - 1, color_left);
			x += 2;
		}
		y += 2;
	}
}

int	iter_julia(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = oldre * oldre - oldim * oldim + fractol->c_koef.re;
		fractol->new.im = 2 * oldre * oldim + fractol->c_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

int	iter_mandelbrot(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	fractol->c_koef.re = fractol->new.re;
	fractol->c_koef.im = fractol->new.im;
	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = fractol->m_koef.re * oldre * oldre
			- oldim * oldim + fractol->c_koef.re;
		fractol->new.im = fractol->m_koef.im * oldre * oldim
			+ fractol->c_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}
