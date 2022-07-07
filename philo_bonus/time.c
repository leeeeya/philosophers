/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:08 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:49 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	get_time(void)
{
	t_time	n;

	error_handler(gettimeofday(&n, NULL), "gettimeofday");
	return ((long int)(n.tv_sec * 1000 + n.tv_usec / 1000));
}

void	ft_usleep(long int ms)
{
	long int	start_action;
	long int	now;
	long int	s;

	start_action = get_time();
	while (1)
	{
		now = get_time();
		s = now - start_action;
		if (s < (long int)ms)
		{
			error_handler(usleep(10), "usleep");
			continue ;
		}
		break ;
	}
}
