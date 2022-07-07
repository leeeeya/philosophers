/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:33 by cstefany          #+#    #+#             */
/*   Updated: 2021/10/04 22:27:03 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((t_byte *)str)[i] = (t_byte)0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*buf;

	buf = malloc(size * num);
	errno_checker();
	ft_bzero(buf, num * size);
	return (buf);
}
