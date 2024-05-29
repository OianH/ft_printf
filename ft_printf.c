/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:24:20 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/29 11:35:50 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_id(char id, va_list list)
{
	int	ret;

	ret = 0;
	if (id == 'c')
		ret += print_char(va_arg(list, int));
	else if (id == 's')
		ret = print_string(va_arg(list, char *));
	else if (id == 'p')
		ret += print_pointer(va_arg(list, size_t), id);
	else if (id == 'i' || id == 'd')
		ret = print_number(va_arg(list, int));
	else if (id == 'u')
		ret = print_unnumber(va_arg(list, unsigned int));
	else if (id == 'x')
		ret += print_hex(va_arg(list, unsigned long), id);
	else if (id == 'X')
		ret = print_hex(va_arg(list, unsigned long), id);
	else if (id == '%')
		ret = print_char('%');
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		i;
	int		ret;

	va_start(list, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += check_id(str[++i], list);
			i++;
		}
		else
			ret += print_char(str[i++]);
	}
	va_end(list);
	return (ret);
}
