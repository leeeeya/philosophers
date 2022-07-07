/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:29 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:51 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watching(void *data)
{
	t_philo		*p;
	long int	tm;

	p = (t_philo *)data;
	while (1)
	{
		tm = get_time();
		if (tm < 0)
			printf("Error: watching\n");
		if (p->num_of_eat == p->t->num_of_eating)
			break ;
		if (!p->t->philo_is_dead && p->last_time_eating
			&& tm - p->last_time_eating > p->t->time_to_die)
		{
			if (pthread_mutex_lock(&p->t->death) != 0)
				printf("Error: pthread_mutex_lock\n");
			p->t->philo_is_dead = 1;
			print_dead_message(p);
			if (pthread_mutex_unlock(&p->t->death) != 0)
				printf("Error: pthread_mutex_unlock\n");
			break ;
		}
		usleep(10);
	}
	return (EXIT_SUCCESS);
}

void	*actions(void *philo)
{
	t_philo		*p;
	pthread_t	watcher;

	p = (t_philo *)philo;
	if (pthread_create(&watcher, NULL, watching, (void *)p) != 0)
		printf("Error: pthread_create(watcher)\n");
	while (p && !p->t->philo_is_dead && p->num_of_eat != p->t->num_of_eating)
	{
		if (dinning(p) != 0)
			printf("Error: eating\n");
		if (sleeping(p) != 0)
			printf("Error: sleeping\n");
		if (thinking(p) != 0)
			printf("Error: thinking\n");
	}
	if (pthread_detach(watcher) != 0)
		printf("Error: pthread_detach(watcher)\n");
	return (EXIT_SUCCESS);
}

int	create_philo_threads(t_philo *p, pthread_t	*philo)
{
	int	i;

	i = -1;
	while (++i != p[0].t->num_of_philo)
	{
		if (free_t(p->t, pthread_create(&philo[i],
					NULL, actions, (void *)&p[i])))
		{
			free(philo);
			return (-1);
		}
	}
	return (0);
}

int	create_threads(t_philo *p)
{
	pthread_t	*philo;
	int			i;

	i = -1;
	philo = (pthread_t *)malloc(sizeof(pthread_t) * p[0].t->num_of_philo + 1);
	if (!philo && free_t(p->t, 1))
		return (-1);
	if (create_philo_threads(p, philo) < 0)
		return (-1);
	while (++i != p[0].t->num_of_philo)
	{
		if (free_t(p->t, pthread_join(philo[i], NULL)))
		{
			free(philo);
			return (-1);
		}
	}
	free(philo);
	return (0);
}
