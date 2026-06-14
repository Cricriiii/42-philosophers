/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_at_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgajean <cgajean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:27:25 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/20 11:43:27 by cgajean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_usage(void)
{
	ft_puterr("Usage: "
		"number_of_philosophers "
		"time_to_die time_to_eat "
		"time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n");
}

static void	exit_philo(char *cmp_str, char *errmsg, \
										void (*kill)(t_monitor, int, char *))
{
	free(cmp_str);
	kill(NULL, 1, errmsg);
}

static void	check_arg_range(char *argv, int philo, \
										void (*kill)(t_monitor, int, char *))
{
	char	*cmp_str;
	int		value;

	cmp_str = ft_itoa(ft_atoi(argv));
	if (!cmp_str)
		kill(NULL, 1, "Memory error. Exit now...\n");
	if (ft_strcmp(argv, cmp_str) == 0)
	{
		value = ft_atoi(argv);
		if (value == 0)
			exit_philo(cmp_str, "All values must be greater than 0!\n", kill);
		if (philo == 1 && value > 200)
			exit_philo(cmp_str, "Wrong philo range (1-200).\n", kill);
		else if (value > 99999999)
			exit_philo(cmp_str, "Wrong time range (1-99999999).\n", kill);
		else
			free(cmp_str);
	}
	else
		exit_philo(cmp_str, "Wrong time range (1-99999999).\n", kill);
}

static void	input_compliance(char **argv, \
										void (*kill)(t_monitor, int, char *))
{
	char	*current;
	int		philo;

	philo = 1;
	while (*argv)
	{
		current = *argv;
		while (*current)
		{
			if (!ft_isdigit(*current))
			{
				print_usage();
				exit(EXIT_FAILURE);
			}
			current++;
		}
		check_arg_range(*argv, philo--, kill);
		argv++;
	}
}

void	exit_at_input(int argc, char **argv, \
										void (*kill)(t_monitor, int, char *))
{
	if (argc < 5 || argc > 6)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	input_compliance(argv, kill);
}
