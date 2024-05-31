/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_2_dpends.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:04:25 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/31 17:15:54 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	print_pointer(size_t n, char id)
{
	int	ret;

	ret = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	ret += print_string("0x");
	ret += print_hex(n, id);
	return (ret);
}

int	print_unnumber(unsigned int n)
{
	char	*str;
	int		ret;

	str = ft_unitoa(n);
	ret = ft_strlen(str);
	write(1, str, ft_strlen(str));
	free (str);
	return (ret);
}

/* ##########Dependencies##########Dependencies##########*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_nlen(n) + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	i = ft_nlen(n);
	result[i--] = '\0';
	while (n)
	{
		if (n % 10 < 0)
			result[i--] = ((n % 10) * -1) + '0';
		else
			result[i--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
