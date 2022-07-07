/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:01 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:48 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_fork(t_philo *p)
{
	if (!p->t->philo_is_dead)
	{
		if (pthread_mutex_lock(p->left_fork) != 0)
			return (-1);
		if (print_message(p, "has taken a left fork") != 0)
			return (-1);
	}
	return (0);
}

int	take_right_fork(t_philo *p)
{
	if (!p->t->philo_is_dead)
	{
		if (pthread_mutex_lock(p->right_fork) != 0)
			return (-1);
		if (print_message(p, "has taken a right fork") != 0)
			return (-1);
	}
	return (0);
}

int	if_one(t_philo *p)
{
	static int	taken = 0;

	if (!taken)
	{
		taken++;
		if (take_left_fork(p) != 0)
			return (-1);
		p->last_time_eating = get_time();
		if (p->last_time_eating < 0)
			return (-1);
		if (pthread_mutex_unlock(p->left_fork) != 0)
			return (-1);
	}
	return (0);
}

int	if_odd(t_philo *p)
{
	if (take_left_fork(p) < 0)
		return (-1);
	if (take_right_fork(p) < 0)
		return (-1);
	p->last_time_eating = get_time();
	if (p->last_time_eating < 0)
		return (-1);
	p->num_of_eat++;
	if (print_message(p, "is eating") < 0)
		return (-1);
	if (ft_usleep(p->t->time_to_eat) < 0)
		return (-1);
	if (pthread_mutex_unlock(p->right_fork) != 0)
		return (-1);
	if (pthread_mutex_unlock(p->left_fork) != 0)
		return (-1);
	return (0);
}

int	if_even(t_philo *p)
{
//	if (usleep(1) < 0)
//		return (-1);
	if (take_right_fork(p) < 0)
		return (-1);
	if (take_left_fork(p) < 0)
		return (-1);
	p->last_time_eating = get_time();
	if (p->last_time_eating < 0)
		return (-1);
	p->num_of_eat++;
	if (print_message(p, "is eating") < 0)
		return (-1);
	if (ft_usleep(p->t->time_to_eat) < 0)
		return (-1);
	if (pthread_mutex_unlock(p->left_fork) != 0)
		return (-1);
	if (pthread_mutex_unlock(p->right_fork) != 0)
		return (-1);
	return (0);
}
