/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:38:05 by lixu              #+#    #+#             */
/*   Updated: 2022/05/23 13:38:32 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_ui(unsigned int ui)
{
	int	count_ui;

	count_ui = 0;
	while (ui != 0)
	{
		ui = ui / 10;
		count_ui++;
	}
	return (count_ui);
}

char	*ft_uitoa(unsigned int ui)
{
	char	*str;
	int		count_ui;

	count_ui = ft_count_ui(ui);
	str = malloc(sizeof(char) * (count_ui + 1));
	if (!ui)
		return (0);
	str[count_ui] = 0;
	while (ui != 0)
	{
		str[count_ui - 1] = ui % 10 + 48;
		ui = ui / 10;
		count_ui--;
	}
	return (str);
}

int	ft_p_ui(unsigned int ui)
{
	char	*str;
	int		count_char;

	count_char = 0;
	if (ui == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
	{
		str = ft_uitoa(ui);
		count_char += ft_p_str(str);
		free(str);
	}
	return (count_char);
}
