/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:00:54 by lixu              #+#    #+#             */
/*   Updated: 2022/05/23 13:40:23 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*uintptr_t
"an unsigned integer type with the property 
that any valid pointer to void can be converted to this type, 
then converted back to pointer to void, 
and the result will compare equal to the original pointer"*/

void	ft_put_ptr(uintptr_t ptr)
{
	if (ptr <= 9)
		ft_putchar_fd(ptr + 48, 1);
	else if (ptr >= 10 && ptr <= 15)
		ft_putchar_fd(87 + ptr, 1);
	else
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
}

int	ft_count_ptr(uintptr_t nbr)
{
	int	count_nbr;

	count_nbr = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		count_nbr++;
	}
	return (count_nbr);
}

int	ft_p_ptr(unsigned long long ptr)
{
	int	count_ptr;

	count_ptr = write(1, "0x", 2);
	if (ptr == 0)
		count_ptr += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		count_ptr += ft_count_ptr(ptr);
	}
	return (count_ptr);
}
/*
int	main(void)
{
	unsigned long long	ptr;

	ptr = 7000;
	printf("\nreturn value:%i", ft_p_ptr(ptr));
}
*/