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

#include "philo_bonus.h"

t_philo	*create_philos(t_table *t)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = (t_philo *)ft_calloc(t->num_of_philo + 1, sizeof(t_philo));
	while (i < t->num_of_philo)
	{
		p[i].t = t;
		p[i].num_of_eat = 0;
		p[i].id = i + 1;
		p[i].last_time_eating = 0;
		i++;
	}
	return (p);
}

void	init_sem(t_table *t)
{
	sem_unlink("print");
	errno_checker();
	sem_unlink("death");
	errno_checker();
	sem_unlink("forks");
	errno_checker();
	t->print = sem_open("print", O_CREAT, 0644, 1);
	check_sem_error(t->print);
	t->death = sem_open("death", O_CREAT, 0644, 0);
	check_sem_error(t->death);
	t->forks = sem_open("forks", O_CREAT, 0644, t->num_of_philo);
	check_sem_error(t->forks);
}

void	create_table(char **args, t_table *t)
{
	t->num_of_philo = ft_atoi(args[1]);
	if (!t->num_of_philo)
		error_handler(ERROR, "invalid arguments");
	t->time_to_die = ft_atoi(args[2]);
	t->time_to_eat = ft_atoi(args[3]);
	t->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		t->num_of_eating = ft_atoi(args[5]);
	else
		t->num_of_eating = -1;
	t->philo_is_dead = 0;
	t->start = get_time();
	init_sem(t);
}
