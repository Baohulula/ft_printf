/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:45:35 by lixu              #+#    #+#             */
/*   Updated: 2022/05/23 13:48:20 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	ft_p_str(char *str)
{
	int	char_count;

	char_count = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[char_count])
		write (1, &str[char_count++], 1);
	return (char_count);
}
/*
int	main(void)
{
	printf("\nreturn value:%i", ft_p_str(NULL));
}
*/
