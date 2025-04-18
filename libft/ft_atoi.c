/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfleuret <cfleuret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:24:45 by cfleuret          #+#    #+#             */
/*   Updated: 2025/01/16 14:08:10 by cfleuret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *str)
{
	int	i;
	int	f;
	int	c;

	i = 0;
	f = 0;
	c = 1;
	if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		return (0);
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			c = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		f = f * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (f * c);
}
/*int main (void)
{
	char s[] = "    2147-483647";
	printf("%d\n",ft_atoi(s));
	printf("%d\n",atoi(s));
	return (0);
}*/
