/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:09:40 by lixu              #+#    #+#             */
/*   Updated: 2022/06/01 18:45:14 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	char_count;

	char_count = 0;
	if (format == 'c')
		char_count += ft_p_char(va_arg(args, int));
	else if (format == 's')
		char_count += ft_p_str(va_arg(args, char *));
	else if (format == 'p')
		char_count += ft_p_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		char_count += ft_p_nbr(va_arg(args, int));
	else if (format == 'u')
		char_count += ft_p_ui(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		char_count += ft_p_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		char_count += ft_p_pct();
	return (char_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			char_count += ft_format(args, str[i + 1]);
			i++;
		}
		else
			char_count += ft_p_char(str[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}

//int	main(void)
//{
	//printf("return value: %i\n", ft_printf("c: %c\n", 'c'));
	//printf("return value: %i\n", ft_printf("s: %s\n", "string"));
	//printf("return value: %i\n", ft_printf("ptr: %p\n", 7000));
	//printf("return value: %i\n", ft_printf("u: %u\n", 100 ));
	//printf("return value: %i\n", ft_printf("d/i: %d\n", -2147483648));
	//printf("return value: %i\n", ft_printf("x: %x\n", 7000));
	//printf("return value: %i\n", ft_printf("X: %X\n", 7000));
	//printf("return value: %i\n", ft_printf("pct: %%\n", '%'));
//}
