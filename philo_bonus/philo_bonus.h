/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:37:49 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/06 17:37:51 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define ERROR 1

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>

typedef struct timeval	t_time;
typedef unsigned char	t_byte;

typedef struct s_table
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_eating;
	long int	start;
	int			philo_is_dead;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*death;
}	t_table;

typedef struct s_philo
{
	int			id;
	int			num_of_eat;
	long int	last_time_eating;
	t_table		*t;
}	t_philo;

int			ft_atoi(const char *s);
t_philo		*create_philos(t_table *t);
void		create_table(char **args, t_table *t);
void		ft_usleep(long int ms);
long int	get_time(void);
void		create_processes(t_philo *p);
void		dinning(t_philo *p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);
void		print_message(t_philo *p, char *msg);
void		print_dead_message(t_philo *p);
void		*ft_calloc(size_t num, size_t size);
void		error_handler(int value, char *msg);
void		errno_checker(void);
void		check_sem_error(sem_t *sem);
#endif //PHILO_BONUS_H
