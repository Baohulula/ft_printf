/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:08:40 by lixu              #+#    #+#             */
/*   Updated: 2022/06/01 19:03:46 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int ui, const char format)
{
	if (ui <= 9)
		ft_putchar_fd(ui + 48, 1);
	else if (ui >= 10 && ui <= 15)
	{
		if (format == 'x')
			ft_putchar_fd(87 + ui, 1);
		if (format == 'X')
			ft_putchar_fd(55 + ui, 1);
	}
	else
	{
		ft_p_hex(ui / 16, format);
		ft_p_hex(ui % 16, format);
	}
}

int	ft_count_hex(unsigned int ui)
{
	int	count_char;

	count_char = 0;
	while (ui != 0)
	{
		ui = ui / 16;
		count_char++;
	}
	return (count_char);
}

int	ft_p_hex(unsigned int ui, const char format)
{
	if (ui == 0)
		return (write (1, "0", 1));
	ft_put_hex(ui, format);
	return (ft_count_hex(ui));
}
/*
int	main(void)
{
	printf("\nreturn value:%d", ft_p_hex(987654, 'x'));
}
*/
