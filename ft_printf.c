/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:24:20 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/30 20:54:54 by oiahidal         ###   ########.fr       */
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

// #include <stdio.h>
// int main()
// {
// 	int rlen1, rlen2;
	// char	*ptr = "Hola";
	// rlen1 = ft_printf("Hello char, %c\n", 'A');
	// rlen2 = printf("Hello char, %c\n", 'A');
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello string, %s\n", "world");
	// rlen2 = printf("Hello string, %s\n", "world");
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello hex, %x\n", 25555555);
	// rlen2 = printf("Hello hex, %x\n", 25555555);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello ptr, %p\n", ptr);
	// rlen2 = printf("Hello ptr, %p\n", ptr);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello HEX, %X\n", 255);
	// rlen2 = printf("Hello HEX, %X\n", 255);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello dig, %d\n", 777);
	// rlen2 = printf("Hello dig, %d\n", 777);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello int, %i\n", 777);
	// rlen2 = printf("Hello int, %i\n", 777);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello uns, %u\n",0);
	// rlen2 = printf("Hello uns, %u\n", 0);
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
	// rlen1 = ft_printf("Hello percent, %%\n");
	// rlen2 = printf("Hello percent, %%\n");
	// printf("ft_printf returned: %d\n", rlen1);
	// printf("printf returned: %d\n", rlen2);
// 	return 0;
// }
