/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:16:05 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 20:19:43 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	iter_matka(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = (oldre * oldre)
			- fractol->c_koef.re * (oldim * oldim) + fractol->c_koef.re;
		fractol->new.im
			= fabs(fractol->c_koef.im * oldre * oldim) + fractol->c_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

int	iter_valera(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = oldre * oldre
			- oldim * oldim + oldim * fractol->c_koef.re;
		fractol->new.im = (3 * oldre * oldim) + oldre * fractol->c_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

int	iter_islands(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = oldre * oldre * oldre
			- oldim * oldim + fractol->i_koef.re;
		fractol->new.im = 2 * oldre * oldim + fractol->i_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

int	iter_web(t_koefs *fractol, int max_iter)
{
	int		iter;
	double	oldre;
	double	oldim;

	iter = 0;
	while (iter < max_iter)
	{
		oldre = fractol->new.re;
		oldim = fractol->new.im;
		fractol->new.re = oldre - oldim * oldim + fractol->w_koef.re;
		fractol->new.im = 2 * oldre * oldim + fractol->w_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

int	iter_lotos(t_koefs *fractol, int max_iter)
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
		fractol->new.re = fractol->l_koef.re * fabs(oldre)
			- oldim * oldim + fractol->c_koef.re;
		fractol->new.im
			= fractol->l_koef.im * (oldre * oldim) + fractol->c_koef.im;
		if ((fractol->new.re * fractol->new.re
				+ fractol->new.im * fractol->new.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}
