/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:56:12 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:56:15 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;
typedef unsigned char	t_byte;

typedef struct s_table
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eating;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	long int		start;
	int				philo_is_dead;
	pthread_mutex_t	death;
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				num_of_eat;
	long int		last_time_eating;
	t_table			*t;
}	t_philo;

int			ft_atoi(const char *s);
t_philo		*create_philos(t_table *t);
int			create_table(char **args, t_table *t);
int			ft_usleep(long int ms);
long int	get_time(void);
int			create_threads(t_philo *p);
int			if_one(t_philo *p);
int			if_odd(t_philo *p);
int			if_even(t_philo *p);
int			dinning(t_philo *p);
int			sleeping(t_philo *p);
int			thinking(t_philo *p);
int			print_message(t_philo *p, char *msg);
int			print_dead_message(t_philo *p);
int			free_t(t_table *t, int ret);
void		*ft_calloc(size_t num, size_t size);
#endif //PHILO_H
