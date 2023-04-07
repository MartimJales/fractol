/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:18:10 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 17:28:27 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 400
# define MAX_ITER 300

# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include"../mlx_linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}	t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_var
{
	t_win	*win;
	t_img	*img_ptr;
	char	*fractol;
	int		off_set_x;
	int		off_set_y;
	int		zoom_y;
	int		zoom_x;
	double		real;
	double		imag;
}	t_var;

t_win	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
int		key_hook(int keycode, t_var *vars);
int		mouse_hook(int keycode);
int		image_mandelbrot(t_img image, int mouse_x, int mouse_y);
int		image_julia(t_img img, int mouse_x, int mouse_y);
int		exit_program(t_var *vars);
void		zoom_in(t_var *vars);
void		zoom_out(t_var *vars);
t_var	*vars(void);
int		gen_trgb(int opacity, int red, int green, int blue);
t_win	new_program(int w, int h, char *str);

int		mandelbrot(void);
int		julia(void);

int		mandelbrot_pix(double real, double imag, int maxIterations);
int		map_color(int intensity, int max);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		put_image(void);


// MOVE
void	move_up(t_var *vars);
void	move_down(t_var *vars);
void	move_left(t_var *vars);
void	move_right(t_var *vars);

// MOUSE
void new_fractol(void);


# define ESC_KEY 65307
# define CROSS -16778144
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

#endif
