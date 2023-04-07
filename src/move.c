/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:37:08 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 17:02:30 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	move_up(t_var *vars)
{
	vars->off_set_y -= 40;
	put_image();
}

void	move_down(t_var *vars)
{
	vars->off_set_y += 40;
	put_image();
}

void	move_left(t_var *vars)
{
	vars->off_set_x -= 40;
	put_image();
}

void	move_right(t_var *vars)
{
	vars->off_set_x += 40;
	put_image();
}
