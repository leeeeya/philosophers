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

#include "philo_bonus.h"

void	*watching(void *data)
{
	t_philo		*p;

	p = (t_philo *)data;
	while (1)
	{
		if (p->num_of_eat
			&& get_time() - p->last_time_eating > p->t->time_to_die)
			break ;
		error_handler(usleep(10), "usleep");
	}
	p->t->philo_is_dead = 1;
	if (p->t->num_of_eating != p->num_of_eat)
		print_dead_message(p);
	sem_post(p->t->death);
	exit(EXIT_SUCCESS);
}

void	actions(t_philo *p)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, watching, (void *) p);
	while (!p->t->philo_is_dead && p->num_of_eat != p->t->num_of_eating)
	{
		dinning(p);
		sleeping(p);
		thinking(p);
	}
	error_handler(pthread_join(watcher, NULL), "pthread_join");
	exit(0);
}

void	end_of_actions(t_philo *p, pid_t	*philo)
{
	int	i;
	int	status;

	i = -1;
	while (++i < p->t->num_of_philo)
	{
		kill(philo[i], SIGKILL);
		errno_checker();
	}
	waitpid(0, &status, 0);
	errno_checker();
	free(philo);
	free(p);
}

void	create_processes(t_philo *p)
{
	pid_t	*philo;
	int		i;

	i = 0;
	philo = (pid_t *)ft_calloc(p->t->num_of_philo + 1, sizeof(pid_t));
	while (i < p->t->num_of_philo)
	{
		philo[i] = fork();
		if (philo[i] == -1)
		{
			printf("Error: fork\n");
			exit(1);
		}
		else if (philo[i] == 0)
			actions(&p[i]);
		i++;
	}
	sem_wait(p->t->death);
	end_of_actions(p, philo);
}
