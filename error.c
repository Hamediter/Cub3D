/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavry <mlavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:46:45 by mlavry            #+#    #+#             */
/*   Updated: 2025/11/25 00:32:10 by mlavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_l(t_data *data, char *str, char *line)
{
	if (line)
		free(line);
	put_error_and_exit(data, str);
}

static void	free_texture(t_data *data)
{
	if (data->param.no_path)
	{
		free(data->param.no_path);
		data->param.no_path = NULL;
	}
	if (data->param.so_path)
	{
		free(data->param.so_path);
		data->param.so_path = NULL;
	}
	if (data->param.ea_path)
	{
		free(data->param.ea_path);
		data->param.ea_path = NULL;
	}
	if (data->param.we_path)
	{
		free(data->param.we_path);
		data->param.we_path = NULL;
	}
}

void	free_mlx(t_data *data)
{
	if (data->textures.east)
		mlx_delete_texture(data->textures.east);
	if (data->textures.west)
		mlx_delete_texture(data->textures.west);
	if (data->textures.north)
		mlx_delete_texture(data->textures.north);
	if (data->textures.south)
		mlx_delete_texture(data->textures.south);
	if (data->textures.door)
		mlx_delete_texture(data->textures.door);
	if (data->weapon.tex)
		mlx_delete_texture(data->weapon.tex);
	if (data->window.img)
		mlx_delete_image(data->mlx, data->window.img);
	if (data->minimap.img)
		mlx_delete_image(data->mlx, data->minimap.img);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

void	free_all(t_data *data)
{
	if (data->map)
		free_tab(data->map);
	if (data->map_fd >= 0)
	{
		get_next_line(-1);
		close(data->map_fd);
		data->map_fd = -1;
	}
	free_texture(data);
	if (data)
		free(data);
}

void	put_error_and_exit(t_data *data, char *str)
{
	ft_putstr_fd(str, 1);
	free_all(data);
	exit (1);
}
