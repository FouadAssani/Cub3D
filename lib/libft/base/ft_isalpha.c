/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:48:22 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:20 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int first_test;
	int second_test;

	if ((c >= 97) && (c <= 122))
		first_test = 1;
	else
		first_test = 0;
	if ((c >= 65) && (c <= 90))
		second_test = 1;
	else
		second_test = 0;
	if ((first_test == 1) || (second_test == 1))
		return (1);
	else
		return (0);
}
