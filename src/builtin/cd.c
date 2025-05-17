/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:12:37 by ttsubo            #+#    #+#             */
/*   Updated: 2025/05/17 13:36:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	_cd_common(t_minish *minish, char *path)
{
	char	*pwd;
	char	*newpwd;

	pwd = get_env_value(minish->env, "PWD");
	if (chdir(path) < 0)
		return (perror(path), 1);
	newpwd = getcwd(NULL, 0);
	if (!newpwd)
		return (perror("getcwd"), 1);
	set_env_value(minish->env, "OLDPWD", pwd);
	set_env_value(minish->env, "PWD", newpwd);
	free_str(&newpwd);
	return (0);
}

static int	_cd_home(t_minish *minish)
{
	char	*home;

	home = get_env_value(minish->env, "HOME");
	if (!home)
		return (error_mes("bash: cd", "HOME not set"), EXIT_FAILURE);
	return (_cd_common(minish, home));
}

static int	_cd_oldpwd(t_minish *minish)
{
	char	*oldpwd;
	int		status;

	oldpwd = get_env_value(minish->env, "OLDPWD");
	if (!oldpwd)
		return (error_mes("bash: cd", "OLDPWD not set"), EXIT_FAILURE);
	status = _cd_common(minish, oldpwd);
	if (status == 0)
		return (printf("%s\n", oldpwd), status);
	else
		return (status);
}

static int	_cd_normal(char *path, t_minish *minish)
{
	return (_cd_common(minish, path));
}

int	builtin_cd(int argc, char *argv[], t_minish *minish)
{
	if (argc == 1)
		return (_cd_home(minish));
	else if (argc == 2 && ft_strcmp("-", argv[1]) == 0)
		return (_cd_oldpwd(minish));
	else if (argc == 2)
		return (_cd_normal(argv[1], minish));
	else
		return (error_mes(argv[0], "too many arguments"), EXIT_FAILURE);
}
