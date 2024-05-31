/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:24:20 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/31 20:39:36 by oiahidal         ###   ########.fr       */
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

/* #include <stdio.h>
int main(void)
{
	int n = 42;
	unsigned int un = -42;
	char c = 'U';
	char *s = "UP2U";
	char *ptr = "Hola";

	int rlen1, rlen2 = 0;

	// Test 1: Mix
	rlen1 = ft_printf("Mix %c %s %d %i %u %x %X %p %%\n", c, s, n, n, un, n, n, s);
	rlen2 = printf("Mix %c %s %d %i %u %x %X %p %%\n", c, s, n, n, un, n, n, s);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 2: Char
	rlen1 = ft_printf("Hola char, %c\n", 'A');
	rlen2 = printf("Hola char, %c\n", 'A');
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 3: String
	rlen1 = ft_printf("Hola string, %s\n", "mundo");
	rlen2 = printf("Hola string, %s\n", "mundo");
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 4: Hex minusculas
	rlen1 = ft_printf("Hola hex, %x\n", 25555555);
	rlen2 = printf("Hola hex, %x\n", 25555555);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 5: Puntero
	rlen1 = ft_printf("Hola ptr, %p\n", ptr);
	rlen2 = printf("Hola ptr, %p\n", ptr);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 6: Hex mayusculas
	rlen1 = ft_printf("Hola HEX, %X\n", 255);
	rlen2 = printf("Hola HEX, %X\n", 255);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 7: Decimal
	rlen1 = ft_printf("Hola dec, %d\n", 777);
	rlen2 = printf("Hola dec, %d\n", 777);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 8: Int
	rlen1 = ft_printf("Hola int, %i\n", 777);
	rlen2 = printf("Hola int, %i\n", 777);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 9: Unsigned int
	rlen1 = ft_printf("Hola uns, %u\n", -0);
	rlen2 = printf("Hola uns, %u\n", -0);
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);
	printf("\n\n");

	// Test 10: Porcentaje
	rlen1 = ft_printf("Hola porcentaje, %%\n");
	rlen2 = printf("Hola porcentaje, %%\n");
	printf("ft_printf devolvió: %d\n", rlen1);
	printf("printf devolvió: %d\n", rlen2);

return 0;
} */
