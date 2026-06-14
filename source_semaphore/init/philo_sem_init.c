/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:04:00 by fox               #+#    #+#             */
/*   Updated: 2025/10/20 12:43:55 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_sem.h"

static void	sem_test(t_monitor philo)
{
	int	kill;

	kill = 0;
	if (philo->scenario->meal_target && philo->sem_total_meals == SEM_FAILED)
		kill = 1;
	else if (philo->sem_print == SEM_FAILED)
		kill = 1;
	else if (philo->sem_forks == SEM_FAILED)
		kill = 1;
	else if (philo->sem_tbl_seat == SEM_FAILED)
		kill = 1;
	if (kill)
		philo_sem_kill(philo, EXIT_FAILURE, "sem_open failed. Exit...");
}

static void	sem_create(t_monitor philo)
{
	t_scenario	scene;

	semaphores_unlink();
	scene = philo->scenario;
	if (scene->meal_target)
		philo->sem_total_meals = sem_open(SEM_TOTAL_MEALS, O_CREAT, 0644, 0);
	philo->sem_print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	philo->sem_tbl_seat = \
		sem_open(SEM_TBL_SEATS, O_CREAT, 0644, scene->philosophers - 1);
	philo->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0644, scene->philosophers);
	sem_test(philo);
}

t_monitor	philo_sem_init(char **argv)
{
	t_monitor	new;
	char		*errmsg;

	new = philo_init(argv, philo_sem_kill);
	if (new)
	{
		if (new->scenario->philosophers == 1)
		{
			errmsg = "Set at least 2 philosophers! Exiting...\n";
			philo_sem_kill(new, EXIT_FAILURE, errmsg);
		}
		new->pid_tbl = ft_calloc(new->scenario->philosophers, sizeof(pid_t));
		if (!new->pid_tbl)
		{
			errmsg = "Fatal error while initializing pid table. Exiting...\n";
			philo_sem_kill(new, EXIT_FAILURE, errmsg);
		}
		sem_create(new);
	}
	return (new);
}
