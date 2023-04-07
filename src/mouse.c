/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:41 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 17:23:33 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

double	convert_range(double old_value, int max_value)
{
	return (((old_value + old_value) / max_value) - 1.0f);
}

void	new_fractol(void)
{
	int		mouse_x;
	int		mouse_y;
	double	real;
	double	imag;

	mlx_mouse_get_pos(vars()->win->mlx_ptr, vars()->win->win_ptr, \
	&mouse_x, &mouse_y);
	vars()->off_set_x = 0;
	vars()->off_set_y = 0;
	vars()->zoom_x = 0;
	vars()->zoom_y = 0;
	vars()->img_ptr->h = HEIGHT;
	vars()->img_ptr->w = WIDTH;
	real = convert_range(mouse_x, WIDTH);
	imag = convert_range(mouse_y, HEIGHT);
	vars()->real = real;
	vars()->imag = imag;
	put_image();
}
