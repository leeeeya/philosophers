/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:12 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:47 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinning(t_philo *p)
{
	if (p->t->num_of_philo == 1)
		if_one(p);
	else if (p->id % 2)
		if_odd(p);
	else
		if_even(p);
	return (0);
}

int	sleeping(t_philo *p)
{
	if (p->num_of_eat && !p->t->philo_is_dead
		&& p->num_of_eat != p->t->num_of_eating)
	{
		if (print_message(p, "is sleeping") != 0)
			return (-1);
		if (ft_usleep(p->t->time_to_eat) != 0)
			return (-1);
	}
	return (0);
}

int	thinking(t_philo *p)
{
	if (p->num_of_eat && !p->t->philo_is_dead
		&& p->num_of_eat != p->t->num_of_eating)
		if (print_message(p, "is thinking") != 0)
			return (-1);
	return (0);
}
