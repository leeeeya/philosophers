/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:54:12 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:50 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define SUCCESS 0
#define ERROR 1

int	free_t(t_table *t, int ret)
{
	int	i;

	i = 0;
	if (ret != 0)
	{
		while (i != t->num_of_philo)
		{
			pthread_mutex_destroy(&t->forks[i]);
			i++;
		}
		if (t->forks)
			free(t->forks);
		pthread_mutex_destroy(&t->death);
		pthread_mutex_destroy(&t->print);
		return (ERROR);
	}
	return (SUCCESS);
}

int	print_message(t_philo *p, char *msg)
{
	if (!p->t->philo_is_dead)
	{
		pthread_mutex_lock(&(p->t->print));
		printf("%ld  philo %d %s\n", get_time() - p->t->start, p->id, msg);
		pthread_mutex_unlock(&(p->t->print));
	}
	return (0);
}

int	print_dead_message(t_philo *p)
{
	pthread_mutex_lock(&(p->t->print));
	printf("%ld  philo %d is dead\n", get_time() - p->t->start, p->id);
	pthread_mutex_unlock(&(p->t->print));
	return (0);
}
