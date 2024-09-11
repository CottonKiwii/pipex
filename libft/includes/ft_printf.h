/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:47:33 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/06 14:54:11 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
size_t	ft_strlen(const char *s);
int		ft_print_nbr(int nbr);
int		ft_print_ptr(void *ptr);
int		ft_print_hex(unsigned long hex, int format);
int		ft_print_unsigned(unsigned int nbr);

#endif
