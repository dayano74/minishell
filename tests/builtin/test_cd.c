/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:33:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/14 12:34:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	path[PATH_MAX];

	printf("cd %s\n", argv[1]);
	getcwd(path, PATH_MAX);
	printf("before:path=%s\n", path);
	builtin_cd(argc, argv);
	getcwd(path, PATH_MAX);
	printf("after :path=%s\n", path);
	return (0);
}
