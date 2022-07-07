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

#include "philo_bonus.h"

void	if_one(t_philo *p)
{
	static int	taken = 0;

	if (!taken && !p->t->philo_is_dead)
	{
		taken++;
		sem_wait(p->t->forks);
		print_message(p, "has taken a right fork");
		p->last_time_eating = get_time();
		ft_usleep(p->t->time_to_eat);
		p->num_of_eat++;
	}
}

void	dinning(t_philo *p)
{
	if (p->t->num_of_philo == 1)
		if_one(p);
	else
	{
		sem_wait(p->t->forks);
		print_message(p, "has taken a right fork");
		sem_wait(p->t->forks);
		print_message(p, "has taken a left fork");
	}
	if (p->t->num_of_philo != 1 && !p->t->philo_is_dead
		&& p->num_of_eat != p->t->num_of_eating)
	{
		print_message(p, "is eating");
		p->last_time_eating = get_time();
		ft_usleep(p->t->time_to_eat);
		p->num_of_eat++;
		sem_post(p->t->forks);
		sem_post(p->t->forks);
	}
}

void	sleeping(t_philo *p)
{
	if (p->t->num_of_philo != 1 && p->num_of_eat && !p->t->philo_is_dead
		&& p->num_of_eat != p->t->num_of_eating)
	{
		print_message(p, "is sleeping");
		ft_usleep(p->t->time_to_eat);
	}
}

void	thinking(t_philo *p)
{
	if (p->t->num_of_philo != 1 && p->num_of_eat && !p->t->philo_is_dead
		&& p->num_of_eat != p->t->num_of_eating)
		print_message(p, "is thinking");
}
