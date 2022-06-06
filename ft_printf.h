/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:09:49 by lixu              #+#    #+#             */
/*   Updated: 2022/05/23 13:41:26 by lixu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
int		ft_p_char(int c);
int		ft_p_str(char *str);
int		ft_p_ptr(unsigned long long ptr);
int		ft_p_nbr(int i);
int		ft_p_ui(unsigned int ui);
int		ft_p_hex(unsigned int ui, const char format);
int		ft_p_pct(void);
int		ft_printf(const char *str, ...);

#endif
