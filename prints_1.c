/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:25:04 by oiahidal          #+#    #+#             */
/*   Updated: 2024/06/01 17:03:17 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	int	ret;

	if (!s)
		return (write(1, "(null)", 6));
	ret = ft_strlen(s);
	write(1, s, ft_strlen(s));
	return (ret);
}

int	print_number(int n)
{
	char	*str;
	int		ret;

	str = ft_itoa(n);
	ret = ft_strlen(str);
	write(1, str, ret);
	free (str);
	return (ret);
}

int	print_hex(unsigned long n, char id)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret = print_hex(n / 16, id);
	if ((id == 'x') || (id == 'p'))
		ret += print_char("0123456789abcdef"[n % 16]);
	if (id == 'X')
		ret += print_char("0123456789ABCDEF"[n % 16]);
	return (ret);
}
