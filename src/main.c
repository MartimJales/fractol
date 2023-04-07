/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjales <mjales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:34:54 by mjales            #+#    #+#             */
/*   Updated: 2023/04/07 15:44:55 by mjales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

t_var	*vars(void)
{
	static t_var	va;

	return (&va);
}

char	*ft_toupper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		n--;
		s1++;
		s2++;
	}
	return (0);
}

void	draw_fractol(char *fractol)
{
	if (ft_strncmp(fractol, "MANDELBROT", 10) == 0)
		mandelbrot();
	else if (ft_strncmp(fractol, "JULIA", 5) == 0)
		julia();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		vars()->fractol = ft_toupper(argv[1]);
		draw_fractol(ft_toupper(argv[1]));
	}
	else
		return (write(1, "Comand ERROR\n", 13));
	return (0);
}
