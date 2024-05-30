/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oiahidal <oiahidal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:09:40 by oiahidal          #+#    #+#             */
/*   Updated: 2024/05/30 17:04:52 by oiahidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
int		print_char(char c);
int		print_string(char *s);
int		print_number(int n);
int		print_hex(unsigned long n, char id);
int		print_unnumber(unsigned int n);
int		print_pointer(size_t n, char id);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_unitoa(unsigned int n);
#endif