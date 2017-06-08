/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:48:13 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 15:48:14 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

intmax_t		ft_get_notation_number(char **format, t_base *arg_base,
				va_list *arg_list)
{
	intmax_t	number;

	number = va_arg(*arg_list, intmax_t);
	if (arg_base->j == 1 || arg_base->z == 1 || **format == 'p')
		return (number);
	else if (arg_base->ll == 1)
		return ((unsigned long long int)number);
	else if (arg_base->l == 1 || **format == 'O')
		return ((unsigned long int)number);
	else if (arg_base->h == 1)
		return ((unsigned short int)number);
	else if (arg_base->hh == 1)
		return ((unsigned char)number);
	else
		return ((unsigned int)number);
}

int				number_lenght(char **f, t_base *a_b,
				int p, char *str)
{
	if ((a_b->flag_sharp && !(*str == '0' && *(str + 1) == '\0')) || **f == 'p')
	{
		if (**f == 'o' || **f == 'O')
		{
			if (a_b->precision <= (int)ft_strlen(str) && p)
			{
				ft_putchar('0');
				a_b->wight--;
			}
		}
		else
		{
			if (p == 1)
			{
				if (**f == 'X')
					ft_putstr("0X");
				else
					ft_putstr("0x");
				a_b->wight -= 2;
			}
			return (2);
		}
		return (1);
	}
	return (0);
}

int				notation_type(char **format, t_base *arg_base,
				va_list *arg_list)
{
	int					base;
	unsigned long int	number;
	char				*str;
	int					tmp;

	if (**format == 'p')
		arg_base->flag_sharp = 1;
	base = (**format == 'o' || **format == 'O') ? 8 : 16;
	number = ft_get_notation_number(format, arg_base, arg_list);
	str = change_base(format, number, base);
	if (*str == '0')
		*str = notation_null(arg_base, format);
	if (**format == 'p' && *str == '0')
		*str = pointer_null(arg_base);
	notation_helper(format, arg_base, str);
	if (!arg_base->flag_hyphen)
		notation_hyp(format, arg_base, str);
	base = number_lenght(format, arg_base, 0, str);
	tmp = not_result(ft_strlen(str) + base, arg_base, base);
	free(str);
	return (tmp);
}

unsigned int	notation_hyp(char **format, t_base *arg_base, char *str)
{
	int		i;
	char	chr;

	chr = ' ';
	if (arg_base->flag_zero)
		chr = '0';
	i = 0;
	if (arg_base->wight > (int)ft_strlen(str) && arg_base->flag_zero)
		i = 1;
	ft_putnchr(chr, arg_base->wight - number_lenght(format, arg_base, i, str) -
	((arg_base->precision > (int)ft_strlen(str))
	? (unsigned int)arg_base->precision : (unsigned int)ft_strlen(str)));
	number_lenght(format, arg_base, !i, str);
	ft_putnchr('0', arg_base->precision - (int)ft_strlen(str));
	ft_putstr(str);
	return ((unsigned int)ft_strlen(str));
}

char			*change_base(char **format, unsigned long int num, int base)
{
	char	*str;
	char	*temp;
	int		i;

	str = (char*)malloc(sizeof(char) * 32);
	temp = "0123456789abcdef";
	if (**format == 'X')
		temp = "0123456789ABCDEF";
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (num && base > 1 && base < 17)
	{
		str[i] = temp[num % base];
		num /= base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
