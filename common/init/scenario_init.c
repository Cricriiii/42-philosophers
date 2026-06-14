/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:21:24 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 12:16:02 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	scenario_init(t_monitor philo, char **argv, \
									void (*kill)(t_monitor, int, char *))
{
	t_scenario	ptr;

	philo->scenario = ft_calloc(1, sizeof(struct s_scenario));
	if (philo->scenario)
	{
		ptr = philo->scenario;
		ptr->philosophers = atoi(argv[1]);
		ptr->time_to_die = atoi(argv[2]) * 1000;
		ptr->time_to_eat = atoi(argv[3]) * 1000;
		ptr->time_to_sleep = atoi(argv[4]) * 1000;
		if (argv[5])
			ptr->meal_target = atoi(argv[5]);
	}
	else
		kill(philo, EXIT_FAILURE, "Error at init. Exit now...\n");
}
