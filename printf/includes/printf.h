/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:50:33 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/16 13:19:25 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdio.h>
# include <stdarg.h>
# include "../Libft/libft.h"

typedef struct	s_flags
{
	int		converter;
	int		zero;
	int		minus;
	int		precision;
	int		width;
	int		wildcard;
	int		track;
	int		bytes;
	int		percent;
	char	*index;
}				t_flags;

int				ft_printf(char *format, ...);
int				ft_flags_check(char *format, t_flags *general, va_list args);
void			ft_flags_display(va_list args, t_flags *general);

void			conv_per(va_list args, t_flags *general);
void			conv_c(va_list args, t_flags *general);
void			conv_s(va_list args, t_flags *general);
void			conv_p(va_list args, t_flags *general);
void			conv_d(va_list args, t_flags *general);

void			conv_i(va_list args, t_flags *general);
void			conv_u(va_list args, t_flags *general);
void			conv_x(va_list args, t_flags *general);
void			conv_bigx(va_list args, t_flags *general);

void			ft_printchar(char c, t_flags *general);
void			ft_printstr(char *str, t_flags *general);
void			ft_printnbr(long int n, t_flags *general);
void			ft_printunbr(unsigned int n, t_flags *general);
void			ft_printwidth_s(t_flags *general, char *s);

int				nb_size(long int n);
void			ft_printwidth_diu(t_flags *general, int n);
void			ft_printwidth_pxbigx(t_flags *general, char *str);
void			ft_printpxbigx(char *str, t_flags *general);
char			*ft_capitalize(char *str);

int				x_calculator(t_flags *general, int n);
int				z_calculator(t_flags *general, char *str);
void			print_prefix_p(t_flags *general);
void			initialise_struct(t_flags *general);

#endif
