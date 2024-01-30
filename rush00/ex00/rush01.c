/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmikola <jmikola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:17:19 by jmikola           #+#    #+#             */
/*   Updated: 2023/07/16 09:46:44 by jmikola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	somme;

	somme = 0;
	i = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			return (somme * sign);
		somme = somme * 10 + str[i] - '0';
		i++;
	}
	return (somme * sign);
}

void	ft_rush01(int x, int y)
{
	int	col;
	int	ligne;

	col = 0;
	ligne = 0;
	while (col <= x - 1 && ligne <= y - 1)
	{
		if ((col == 0 && ligne == 0) || (col == x - 1 && ligne == y - 1))
			ft_putchar('/');
		else if ((col == 0 && ligne == y - 1) || (col == x - 1 && ligne == 0))
			ft_putchar('\\');
		else if ((col == 0 || col == x - 1) || (ligne == 0 || ligne == y - 1))
			ft_putchar('*');
		else
			ft_putchar(' ');
		if (ligne == y - 1)
		{
			col++;
			ligne = -1;
			ft_putchar('\n');
		}
		ligne++;
	}
}
