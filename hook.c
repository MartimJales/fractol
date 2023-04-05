/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:36:18 by mjales            #+#    #+#             */
/*   Updated: 2023/03/28 20:38:10 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/fractol.h"

void	move_up(t_var *vars)
{
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	vars->off_set_y -= 40;
	image_julia(*vars->img_ptr, vars->off_set_x + vars->zoom_x, \
	vars->off_set_y + vars->zoom_y);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}

void	move_down(t_var *vars)
{
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	vars->off_set_y += 40;
	image_julia(*vars->img_ptr, vars->off_set_x + vars->zoom_x, \
	vars->off_set_y + vars->zoom_y);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}

void	move_left(t_var *vars)
{
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	vars->off_set_x -= 40;
	image_julia(*vars->img_ptr, vars->off_set_x + vars->zoom_x, \
	vars->off_set_y + vars->zoom_y);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}

void	move_right(t_var *vars)
{
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	vars->off_set_x += 40;
	image_julia(*vars->img_ptr, vars->off_set_x + vars->zoom_x, \
	vars->off_set_y + vars->zoom_y);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}

int	key_hook(int keycode, t_var *vars)
{
	printf("%d\n", keycode);
	if (keycode == ESC_KEY || keycode == CROSS)
	{
		if (vars)
			exit_program(vars);
	}
	else if (keycode == KEY_UP)
		move_up(vars);
	else if (keycode == KEY_DOWN)
		move_down(vars);
	else if (keycode == KEY_LEFT)
		move_left(vars);
	else if (keycode == KEY_RIGHT)
		move_right(vars);
	return (0);
}

int	mouse_hook(int keycode, t_var *v)
{
	(void) v;

	if (keycode == SCROLL_UP)
		zoom_in(vars());
	else if (keycode == SCROLL_DOWN)
		zoom_out(vars());
	return (0);
}

int	exit_program(t_var *vars)
{
	mlx_destroy_image(vars->win->mlx_ptr, vars->img_ptr->img_ptr);
	mlx_destroy_window(vars->win->mlx_ptr, vars->win->win_ptr);
	mlx_destroy_display(vars->win->mlx_ptr);
	free(vars->win->mlx_ptr);
	exit(0);
}
