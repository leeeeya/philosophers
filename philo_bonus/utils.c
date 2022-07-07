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

#include "philo_bonus.h"

void	print_message(t_philo *p, char *msg)
{
	sem_wait(p->t->print);
	printf("%ld  philo %d %s\n", get_time() - p->t->start, p->id, msg);
	sem_post(p->t->print);
}

void	print_dead_message(t_philo *p)
{
	sem_wait(p->t->print);
	printf("%ld  philo %d is dead\n", get_time() - p->t->start, p->id);
}
