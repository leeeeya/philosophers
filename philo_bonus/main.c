/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:34:50 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/06 17:34:53 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start(char **argv)
{
	t_table	t;
	t_philo	*p;

	create_table(argv, &t);
	p = create_philos(&t);
	create_processes(p);
	printf("\n%s\n", "end of simulation");
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		error_handler(ERROR, "Invalid number of arguments");
	start(argv);
	return (0);
}
