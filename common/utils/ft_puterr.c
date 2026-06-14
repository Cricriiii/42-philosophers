/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fox <fox@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:13:13 by cgajean           #+#    #+#             */
/*   Updated: 2025/10/13 10:46:06 by fox              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_puterr(char *errmsg)
{
	size_t	len;

	if (!errmsg)
		return (0);
	len = ft_strlen(errmsg);
	write(STDERR_FILENO, errmsg, len);
	return (len);
}
