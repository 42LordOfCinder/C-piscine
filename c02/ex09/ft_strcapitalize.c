/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmassoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:34:55 by gmassoni          #+#    #+#             */
/*   Updated: 2023/07/17 18:39:02 by gmassoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha_low_or_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= '0' && c <= '9')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_alpha_low_or_up(str[i]) == 2
			&& !ft_char_is_alpha_low_or_up(str[i - 1]))
			str[i] -= 32;
		else if (ft_char_is_alpha_low_or_up(str[i]) == 1
			&& ft_char_is_alpha_low_or_up(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
