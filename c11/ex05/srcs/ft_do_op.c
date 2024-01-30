/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:48:07 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/03 13:46:02 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_test_0(char op, int nb)
{
	if (nb == 0)
	{
		if (op == '/')
		{
			write(2, "Stop : division by zero\n", 24);
			return (0);
		}
		if (op == '%')
		{
			write(2, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	return (1);
}

void	ft_do_op(char *v1, char *op, char *v2)
{
	int		n1;
	int		n2;
	char	*oplist;
	int		(*opfunc[5])(int a, int b);
	int		i;

	opfunc[0] = &ft_sum;
	opfunc[1] = &ft_sub;
	opfunc[2] = &ft_mult;
	opfunc[3] = &ft_div;
	opfunc[4] = &ft_mod;
	n1 = ft_atoi(v1);
	n2 = ft_atoi(v2);
	oplist = "+-*/%";
	i = -1;
	while (++i < 6)
		if (op[0] == oplist[i])
			break ;
	if (i < 5)
	{
		if (ft_test_0(oplist[i], n2))
			ft_putnbr((*opfunc[i])(n1, n2));
	}
	else
		ft_putnbr(0);
}
