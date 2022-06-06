/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:37:24 by lixu              #+#    #+#             */
/*   Updated: 2022/05/23 13:38:23 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	nbr;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		str[len--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}

int	ft_p_nbr(int i)
{
	int		char_count;
	char	*str;

	str = ft_itoa(i);
	char_count = ft_p_str(str);
	free(str);
	return (char_count);
}
/*
int	main(void)
{
	int	i;

	i = 1000;
	printf("\nreturn value:%i", ft_p_nbr(i));
}
*/
