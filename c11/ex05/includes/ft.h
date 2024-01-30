/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <gauthier.massoni@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:45:56 by gmassoni          #+#    #+#             */
/*   Updated: 2023/08/03 13:42:44 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <unistd.h>

void	ft_do_op(char *v1, char *op, char *v2);

int		ft_atoi(char *str);

void	ft_putnbr(int nb);

int		ft_sum(int n1, int n2);
int		ft_sub(int n1, int n2);
int		ft_mult(int n1, int n2);
int		ft_div(int n1, int n2);
int		ft_mod(int n1, int n2);
#endif
