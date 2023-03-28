/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:23:27 by mjales            #+#    #+#             */
/*   Updated: 2023/03/28 18:14:46 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/fractol.h"

int	zoom_in(t_var *vars)
{
	int	off_set_y;

	vars->img_ptr->w *= 1.1;
	vars->img_ptr->h *= 1.1;
	off_set_y = -(HEIGHT - vars->img_ptr->h) / 2;
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	if (ft_strncmp(vars->fractol, "MANDELBROT", 10) == 0)
		image_mandelbrot(*vars->img_ptr, 0, off_set_y);
	else if (ft_strncmp(vars->fractol, "JULIA", 5) == 0)
		image_julia(*vars->img_ptr, 0, 0);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}

int	zoom_out(t_var *vars)
{
	int	off_set_y;

	vars->img_ptr->w *= 0.9;
	vars->img_ptr->h *= 0.9;
	vars->img_ptr->w += 1;
	vars->img_ptr->h += 1;
	off_set_y = -(HEIGHT - vars->img_ptr->h) / 2;
	mlx_clear_window(vars->win->mlx_ptr, vars->win->win_ptr);
	if (ft_strncmp(vars->fractol, "MANDELBROT", 10) == 0)
		image_mandelbrot(*vars->img_ptr, 0, off_set_y);
	else if (ft_strncmp(vars->fractol, "JULIA", 5) == 0)
		image_julia(*vars->img_ptr, 0, 0);
	mlx_put_image_to_window(vars->win->mlx_ptr, vars->win->win_ptr, \
	vars->img_ptr->img_ptr, 0, 0);
}
