/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <mlavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:22:28 by aboutale          #+#    #+#             */
/*   Updated: 2025/11/18 20:34:07 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*whitespace(char *line)
{
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	return (line);
}

int	parse_rgb(char *s)
{
	int	value;
	int	i;

	s = whitespace(s);
	if (!*s)
		return (-1);
	i = 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		return (-1);
	value = ft_atoi(s);
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

int	check_texture(t_data *data, char *path, char *line)
{
	int	len;
	int	fd;

	len = ft_strlen(path);
	if ((len < 4) || (ft_strcmp(path + len - 4, ".png") != 0))
	{
		if (line)
			free(line);
		put_error_and_exit(data, "Error\nFormat must be .png\n");
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		if (line)
			free(line);
		put_error_and_exit(data, "Error\nCannot open texture\n");
	}
	else
		close(fd);
	return (1);
}

static void	check_valid_tex_param(t_data *game, char *line, char *path)
{
	free(path);
	free_l(game, "Error\nInvalid texture format\n", line);
}

int	parse_texture(t_data *game, char *line)
{
	char	*path;
	char	*newline;

	path = ft_strdup(whitespace(line + 2));
	if (!line || !line[2] || line[2] != ' ')
		check_valid_tex_param(game, line, path);
	if (!(path[0] == '.' && path[1] == '/'))
	{
		free(path);
		free_l(game, "Error\nTexture path must start with ./\n", line);
	}
	if (!path)
		return (0);
	newline = ft_strchr(path, '\n');
	if (newline)
		*newline = '\0';
	if (!ft_strncmp(line, "NO", 2))
		game->param.no_path = path;
	else if (!ft_strncmp(line, "SO", 2))
		game->param.so_path = path;
	else if (!ft_strncmp(line, "WE", 2))
		game->param.we_path = path;
	else if (!ft_strncmp(line, "EA", 2))
		game->param.ea_path = path;
	return (check_texture(game, path, line));
}
