/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:52 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:46 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(t_table *t)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = (t_philo *)ft_calloc(t->num_of_philo + 1, sizeof(t_philo));
	if (!p && free_t(t, 1))
		return (NULL);
	while (i != t->num_of_philo)
	{
		p[i].t = t;
		p[i].num_of_eat = 0;
		p[i].id = i + 1;
		p[i].last_time_eating = 0;
		p[i].right_fork = &t->forks[i];
		if (i == t->num_of_philo - 1)
			p[i].left_fork = p[0].right_fork;
		else
			p[i].left_fork = &t->forks[i + 1];
		i++;
	}
	return (p);
}

int	mutex_init(t_table *t)
{
	int	i;

	i = 0;
	t->forks = (pthread_mutex_t *)ft_calloc(t->num_of_philo + 1,
			sizeof(pthread_mutex_t));
	if (!t->forks)
		return (-1);
	while (i != t->num_of_philo)
	{
		if (free_t(t, pthread_mutex_init(&t->forks[i], NULL)))
			return (-1);
		i++;
	}
	if (free_t(t, pthread_mutex_init(&t->print, NULL)))
		return (-1);
	if (free_t(t, pthread_mutex_init(&t->death, NULL)))
		return (-1);
	return (0);
}

int	fifth_arg(char **args, t_table *t)
{
	if (args[5])
	{
		t->num_of_eating = ft_atoi(args[5]);
		if (t->num_of_eating < 0)
			return (-1);
	}
	else
		t->num_of_eating = (-1);
	return (0);
}

int	create_table(char **args, t_table *t)
{
	t->num_of_philo = ft_atoi(args[1]);
	if (t->num_of_philo <= 0)
		return (-1);
	t->time_to_die = ft_atoi(args[2]);
	if (t->time_to_die < 0)
		return (-1);
	t->time_to_eat = ft_atoi(args[3]);
	if (t->time_to_eat < 0)
		return (-1);
	t->time_to_sleep = ft_atoi(args[4]);
	if (t->time_to_sleep < 0)
		return (-1);
	t->philo_is_dead = 0;
	t->start = get_time();
	if (t->start < 0)
		return (-1);
	if (fifth_arg(args, t) < 0)
		return (-1);
	if (mutex_init(t) < 0)
		return (-1);
	return (0);
}
