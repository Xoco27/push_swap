/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:24:45 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/30 12:43:01 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	f;
	int		s;

	i = 0;
	f = 0;
	s = 1;
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (f * s);
}
/*int main (void)
{
	char s[] = "    2147-483647";
	printf("%d\n",ft_atoi(s));
	printf("%d\n",atoi(s));
	return (0);
}*/
