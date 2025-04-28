/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:07:44 by ttsubo            #+#    #+#             */
/*   Updated: 2025/04/27 15:55:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Takes one character out of the buffer and sets it in cp.
 * 
 * @param [out] fd_buf	: fd_buf
 * @param [out] cp		: char pointer.
 * @retval PUTC_OK		: Successfully retrieved the char.
 * @retval PUTC_ERR		: Error while retrieving char.
 * @retval PUTC_EOF		: EOF was reached.
 * @note	<pre> fd_buf != NULL
 */
static int	_ft_getc(t_buf *fd_buf, unsigned char *cp)
{
	if (fd_buf->buf_len == 0)
	{
		fd_buf->buf_len = read(fd_buf->fd, fd_buf->buf, BUFFER_SIZE);
		if (fd_buf->buf_len < 0)
			return (GETC_ERR);
		if (fd_buf->buf_len == 0)
			return (GETC_EOF);
		fd_buf->bufp = fd_buf->buf;
	}
	*cp = (unsigned char)*fd_buf->bufp++;
	fd_buf->buf_len--;
	if (*cp == '\n')
		return (GETC_LF);
	else
		return (GETC_OTHER);
}

/**
 * @brief  Add c to t_string->str
 * 
 * @param line 
 * @param c 
 * @param sts 
 * @return int 
 */
static int	_ft_putc(t_string *line, char c, t_getc_sts sts)
{
	char	*tmp;

	if (sts == GETC_EOF)
		return (PUTC_OK);
	if (sts == GETC_ERR)
		return (PUTC_ERR);
	if (line->len + 1 >= line->capa)
	{
		line->capa = (line->len + 1) * 2;
		tmp = gnl_calloc(line->capa, 1);
		if (!tmp)
			return (PUTC_ERR);
		gnl_strncpy(tmp, line->str, line->len);
		free(line->str);
		line->str = tmp;
	}
	line->str[line->len] = c;
	line->len++;
	return (PUTC_OK);
}

/**
 * @brief Initialize t_buf. (but only if not yet created).
 * 
 * @param s_buf 
 * @param fd 
 * @return t_buf* 
 */
static t_buf	*_gnl_buf_init(t_buf **s_buf, int fd)
{
	if (!s_buf)
		return (NULL);
	if (!*s_buf)
	{
		*s_buf = gnl_calloc(sizeof(t_buf), 1);
		if (!*s_buf)
			return (NULL);
		(*s_buf)->buf = gnl_calloc(BUFFER_SIZE, 1);
		if (!(*s_buf)->buf)
		{
			free(*s_buf);
			*s_buf = NULL;
			return (NULL);
		}
		(*s_buf)->buf_len = 0;
		(*s_buf)->bufp = (*s_buf)->buf;
		(*s_buf)->fd = fd;
	}
	return (*s_buf);
}

/**
 * @brief free s_buf.
 *
 * @param [out]	s_buf
 */
static void	_gnl_buf_free(t_buf **s_buf)
{
	if (!s_buf)
		return ;
	if (*s_buf)
	{
		if ((*s_buf)->buf)
		{
			free((*s_buf)->buf);
			(*s_buf)->buf = NULL;
		}
		free(*s_buf);
		*s_buf = NULL;
	}
}

/**
 * @brief Get string from fd to newline
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd)
{
	static t_buf	*buf[MAX_FD];
	t_string		newline;
	unsigned char	uc;
	t_sts			status;

	if (fd < 0 || MAX_FD <= fd)
		return (NULL);
	if (!_gnl_buf_init(&buf[fd], fd))
		return (NULL);
	newline = (t_string){.str = NULL, .len = 0, .capa = 0};
	while (1)
	{
		status.getc_sts = _ft_getc(buf[fd], &uc);
		status.putc_sts = _ft_putc(&newline, uc, status.getc_sts);
		if (set_sts(&status)->gnl_sts != GNL_READ)
			break ;
	}
	if (status.gnl_sts == GNL_LF || status.gnl_sts == GNL_EOF)
		_ft_putc(&newline, '\0', status.getc_sts);
	if (status.gnl_sts == GNL_EOF || status.gnl_sts == GNL_ERR)
		_gnl_buf_free(&buf[fd]);
	if (status.gnl_sts == GNL_ERR)
		return (gnl_line_free(&newline));
	return (newline.str);
}
