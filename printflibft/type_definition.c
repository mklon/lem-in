/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_definition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:01:01 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/25 15:01:02 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		qualifier_type_one(char **format, t_base *arg_base, va_list *arg_list)
{
	if (**format == '%')
		return (percent_sign_type(arg_base));
	else if (**format == 's')
		return (string_type(arg_base, arg_list, 0));
	else if (**format == 'c')
		return (character_type(arg_base, arg_list));
	else if (**format == 'd' || **format == 'i' || **format == 'D')
		return (integer_type(format, arg_base, arg_list));
	else if (**format == 'o' || **format == 'O' || **format == 'x'
			|| **format == 'X' || **format == 'p')
		return (notation_type(format, arg_base, arg_list));
	else if (**format == 'u' || **format == 'U')
		return (unsigned_type(format, arg_base, arg_list));
	else if (**format == 'b')
		return (binary_type(arg_base, arg_list));
	else if (**format == 'p')
		return (notation_type(format, arg_base, arg_list));
	else if (**format == 'C')
		return (wcharacter_type(arg_base, arg_list));
	else if (**format == 'S')
		return (wstring_type(arg_base, arg_list, 0));
	else
		return (none_type(format, arg_base));
}
