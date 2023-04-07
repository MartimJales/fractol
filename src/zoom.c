/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:23:27 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 16:59:25 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	put_image(void)
{
	mlx_clear_window(vars()->win->mlx_ptr, vars()->win->win_ptr);
	if (ft_strncmp(vars()->fractol, "MANDELBROT", 10) == 0)
		image_mandelbrot(*vars()->img_ptr, \
		vars()->off_set_x + vars()->zoom_x, vars()->off_set_y + vars()->zoom_y);
	else if (ft_strncmp(vars()->fractol, "JULIA", 5) == 0)
		image_julia(*vars()->img_ptr, \
		vars()->off_set_x + vars()->zoom_x, vars()->off_set_y + vars()->zoom_y);
	else
		return (write(1, "FRACTOL NOT FOUND\n", 19));
	mlx_put_image_to_window(vars()->win->mlx_ptr, vars()->win->win_ptr, \
	vars()->img_ptr->img_ptr, 0, 0);
	return (0);
}

void	zoom_in(t_var *vars)
{
	vars->img_ptr->w *= 1.1;
	vars->img_ptr->h *= 1.1;
	vars->zoom_y = -(HEIGHT - vars->img_ptr->h) / 2;
	vars->zoom_x = -(WIDTH - vars->img_ptr->w) / 2;
	vars->off_set_x *= 1.1;
	vars->off_set_y *= 1.1;
	put_image();
}

void	zoom_out(t_var *vars)
{
	vars->img_ptr->w *= 0.9;
	vars->img_ptr->h *= 0.9;
	vars->zoom_y = -(HEIGHT - vars->img_ptr->h) / 2;
	vars->zoom_x = -(WIDTH - vars->img_ptr->w) / 2;
	vars->off_set_x *= 0.9;
	vars->off_set_y *= 0.9;
	put_image();
}
