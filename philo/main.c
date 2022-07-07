/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstefany <cstefany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:56 by cstefany          #+#    #+#             */
/*   Updated: 2022/07/04 14:54:44 by cstefany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(char **argv)
{
	t_table	t;
	t_philo	*p;

	if (create_table(argv, &t) < 0)
	{
		printf("Error: create_table\n");
		return (-1);
	}
	p = create_philos(&t);
	if (!p)
	{
		printf("Error: create_philos\n");
		return (-1);
	}
	if (create_threads(p) < 0)
	{
		printf("Error: create_threads\n");
		return (-1);
	}
	printf("\n%s\n", "end of simulation");
	free(p);
	free_t(&t, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (start(argv) == 0)
			return (0);
	}
	printf("Error: Invalid number of arguments\n");
	return (-1);
}
