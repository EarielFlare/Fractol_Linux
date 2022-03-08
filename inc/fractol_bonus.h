/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgregory <cgregory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:38:43 by cgregory          #+#    #+#             */
/*   Updated: 2022/03/05 21:29:14 by cgregory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# define WIDTH		800
# define HEIGHT		600

typedef enum s_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_color
{
	unsigned char	channel[4];
}					t_color;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_point
{
	int				iter;
	t_color			color;
	t_color			color_last;
}					t_point;

typedef struct s_koefs
{
	t_complex		new;
	t_complex		c_koef;
	t_complex		i_koef;
	t_complex		w_koef;
	t_complex		m_koef;
	t_complex		l_koef;
}					t_koefs;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				max_iter;
	double			zoom;
	int				mouse_x;
	int				mouse_y;
	double			x_step;
	double			y_step;
	int				move_speed;
	t_complex		ld_corner;
	t_complex		ru_corner;
	t_koefs			fractol;
	t_bool			is_fixed;
	t_bool			is_help;
	t_point			point;
	int				pq1;
	int				pq2;
	int				clr_shift;
	int				(*proc)(t_koefs *p_img, int max_iter);
}					t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	int				x;
	int				y;
	t_data			img;
	int				count;
}					t_vars;

typedef struct s_proc
{
	char			*name;
	int				(*proc)(t_koefs *fractol, int max_iter);
}					t_proc;

int				mouse_move(int x, int y, t_vars *vars);
int				mouse_hook(int keycode, int x, int y, t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_win(t_vars *vars);
int				render_func(void *strct);
void			win_rescale(t_data *p_img);
void			calc_fractol_1(t_data *p_img);
void			set_defaults(t_vars *vars);
void			init_fractol(t_vars *vars);
void			init_image(t_vars *vars);
t_color			get_color(t_data *p_img);
t_color			get_color_left(t_data *p_img);
void			put_pixel(t_data *p_img, int x, int y, t_color color);
t_complex		init_complex(double re, double im);
void			steps_calc(t_data *p_img);
int				iter_julia(t_koefs *fractol, int max_iter);
int				iter_matka(t_koefs *fractol, int max_iter);
int				iter_valera(t_koefs *fractol, int max_iter);
int				iter_islands(t_koefs *fractol, int max_iter);
int				iter_web(t_koefs *fractol, int max_iter);
int				iter_mandelbrot(t_koefs *fractol, int max_iter);
int				iter_lotos(t_koefs *fractol, int max_iter);
void			kbrd_color_check(t_vars *vars, int keycode);
void			kbrd_move_check_ud(t_vars *vars, int keycode);
void			kbrd_move_check_lr(t_vars *vars, int keycode);
int				choose_fractol(t_vars *vars, char *str);
void			print_prompt(void);
void			draw_help_1(t_vars *vars);
void			draw_help_2(t_vars *vars);
#endif
