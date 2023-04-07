/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:36:46 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 14:34:04 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}
