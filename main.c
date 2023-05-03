/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:25:14 by hrobin            #+#    #+#             */
/*   Updated: 2023/05/03 15:37:57 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || ac > 6)
		return (exit_error("error: wrong nb of arguments\n"));
	checkargs(av);
	if (init(&info, ac, av))
		return(clear(&info) && exit_error("error: fatal\n"));
	if (start_thread())
		return(clear(&info) && exit_error("error: fatal\n"));
}
