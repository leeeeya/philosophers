/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:34:14 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/06 17:34:17 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	errno_checker(void)
{
	if (errno)
	{
		printf("%s\n", strerror(errno));
		exit(errno);
	}
}

void	error_handler(int value, char *msg)
{
	if (value != 0)
	{
		printf("Error: %s\n", msg);
		exit(1);
	}
}

void	check_sem_error(sem_t *sem)
{
	if (sem == SEM_FAILED)
	{
		printf("Error: sem_open\n");
		exit(1);
	}
}
