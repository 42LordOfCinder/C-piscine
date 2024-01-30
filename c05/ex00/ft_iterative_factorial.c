/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:02 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/19 20:47:53 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;

	if (nb == 0)
		return (1);
	if (nb > 0)
	{
		sum = 1;
		while (nb > 0)
		{
			sum *= nb;
			nb--;
		}
		return (sum);
	}
	return (0);
}
