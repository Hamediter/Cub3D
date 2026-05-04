/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <mlavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:44:04 by mlavry            #+#    #+#             */
/*   Updated: 2025/11/18 20:47:00 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	handle_param_line_bonus(t_data *game, char *line)
{
	char	*trimmed;

	trimmed = whitespace(line);
	if (!check_duplicate(game, trimmed, line))
		return (0);
	if (ft_strncmp(trimmed, "F ", 2) == 0 || ft_strncmp(trimmed, "C ", 2) == 0)
	{
		if (!parse_colour(game, trimmed))
			return (0);
	}
	else if (!ft_strncmp(trimmed, "NO", 2) || !ft_strncmp(trimmed, "SO", 2)
		|| !ft_strncmp(trimmed, "WE", 2) || !ft_strncmp(trimmed, "EA", 2))
	{
		if (!parse_texture(game, trimmed))
			return (0);
	}
	else if (is_map_line_bonus(trimmed))
	{
		if (!all_param_ok(&game->param))
			free_l(game, "Error\nMissing parameters\n", line);
	}
	else
		free_l(game, "Error\nInvalid parameter\n", line);
	return (1);
}

int	check_param_bonus(t_data *game, char *file)
{
	char	*line;
	int		status;

	game->map_fd = open(file, O_RDONLY);
	if (game->map_fd < 0)
		put_error_and_exit(game, "Error\nCannot open file\n");
	line = skip_empty_lines(game->map_fd);
	while (line)
	{
		status = handle_param_line_bonus(game, line);
		free(line);
		if (status == 0)
			return (get_next_line(-1), (void)close(game->map_fd), 0);
		if (status == 2)
			break ;
		line = skip_empty_lines(game->map_fd);
	}
	close(game->map_fd);
	return (1);
}
