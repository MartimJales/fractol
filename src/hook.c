/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:36:18 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 17:00:25 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	key_hook(int keycode, t_var *vars)
{
	if (keycode == ESC_KEY || keycode == CROSS)
		exit_program(vars);
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

int	mouse_hook(int keycode)
{
	if (keycode == SCROLL_UP)
		zoom_in(vars());
	else if (keycode == SCROLL_DOWN)
		zoom_out(vars());
	else if (keycode == LEFT_CLICK)
		new_fractol();
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
