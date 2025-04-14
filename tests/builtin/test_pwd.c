/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayano <dayano@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:07:28 by dayano            #+#    #+#             */
/*   Updated: 2025/04/14 16:11:42 by dayano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	printf("=====check function=====");
	printf("argc = %d\n", argc);
	i = 0;
	while (argv[i])
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	printf("========================\n");
	if (builtin_pwd(argc, argv))
		printf("error\n");
	return (0);
}
