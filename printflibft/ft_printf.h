/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 12:44:59 by oposhiva          #+#    #+#             */
/*   Updated: 2017/02/20 12:44:59 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct		s_falg_base
{
	int		flag_hyphen;
	int		flag_plus;
	int		flag_space;
	int		flag_sharp;
	int		flag_zero;
	int		wight;
	int		precision;
	int		p_mod;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		j;
	int		z;

}					t_base;

/*
** ft_printf.c
*/

int					ft_printf(char *format, ...);
int					ft_printf_body(char *format, va_list *arg_list,
					int byte_amount);
int					qualifier_def(char **format, t_base *arg_base,
					va_list *arg_list);
int					zeroing_structure(t_base *arg_base);
int					qualifier_search(char **format);

/*
** qualifier_definition.c
*/

char				*qualifier_flags(char **format, t_base *arg_base);
char				*qualifier_wight(char **format, t_base *arg_base,
					va_list *arg_list, int digit);
char				*qualifier_precision(char **format, t_base *arg_base,
					va_list *arg_list);
char				*qualifier_lenght(char **format, t_base *arg_base);

/*
** type_definition.c
*/

int					qualifier_type_one(char **format, t_base *arg_base,
					va_list *arg_list);

/*
** percent.c
*/

int					percent_sign_type(t_base *arg_base);

/*
**char.c
*/

int					character_type(t_base *arg_base, va_list *arg_list);

/*
** string.c
*/

int					string_type(t_base *arg_base, va_list *arg_list,
					int str_len);

/*
** integer.c
*/

int					integer_type(char **format, t_base *arg_base,
					va_list *arg_list);
int					result(t_base *arg_base, int num_len, int i);
int					prefix(t_base *arg_base, long long int *num, int f);
void				integer_hup(t_base *arg_base, int num_len,
					long long int num);
intmax_t			size_def(char **format, t_base *arg_base,
					va_list *arg_list);

/*
** natation.c
*/

intmax_t			ft_get_notation_number(char **format, t_base *arg_base,
					va_list *arg_list);
int					number_lenght(char **format, t_base *arg_base,
					int f, char *string);
unsigned int		notation_hyp(char **format, t_base *arg_base, char *str);
int					notation_type(char **format, t_base *arg_base,
					va_list *arg_list);
char				*change_base(char **format, unsigned long int num,
					int base);
/*
** unsigned.c
*/

unsigned long int	ft_get_number(char **format, t_base *arg_base,
					va_list *arg_list);
int					unsigned_type(char **format, t_base *arg_base,
					va_list *arg_list);
int					uns_result(int lenght, t_base *arg_base);
int					unsigned_null(t_base *arg_base);
void				unsigned_hyp(t_base *arg_base, int length,
					unsigned long int number);

/*
**binary.c
*/

int					binary_type(t_base *arg_base, va_list *arg_list);
unsigned int		display_notation(unsigned long int number, int base,
					unsigned int *lenght, int f);

/*
** wchar.c
*/

char				*wchar_convert(int i);
int					wcharacter_type(t_base *arg_base, va_list *arg_list);

/*
** wstr.c
*/

int					wstring_type(t_base *arg_base, va_list *arg_list, int i);
int					uni_size(int i);
int					count_length(char **mass);
int					put_n_double(int length, int *mass, int f);
int					put_unicode(char **str, t_base *arg_base,
					int *mass, int i);

/*
** none.c
*/

int					none_type(char **format, t_base *arg_base);

/*
** notation_help.c
*/

void				notation_helper(char **format, t_base *arg_base, char *str);
char				pointer_null(t_base *arg_base);
char				notation_null(t_base *arg_base, char **format);
int					not_result(int num_len, t_base *arg_base, int i);
int					print_null(t_base *a);

#endif
