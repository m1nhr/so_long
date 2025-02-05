/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:19:33 by rmarecar          #+#    #+#             */
/*   Updated: 2023/01/11 13:03:05 by rmarecar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.img_width * x, data->img.img_height * y);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				print_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == '0')
				print_img(data, data->img.img_floor, x, y);
			x++;
		}
		y++;
	}
}

void	render_elements(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
				print_img(data, data->img.img_player, x, y);
			if (data->map[y][x] == 'E')
				print_img(data, data->img.img_exit, x, y);
			if (data->map[y][x] == 'C')
				print_img(data, data->img.img_item, x, y);
			x++;
		}
		y++;
	}
}

void	set_img(t_data *data)
{
	data->step_count = 0;
	data->img.img_height = 60;
	data->img.img_width = 60;
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./img/w.xpm",
			&(data->img.img_height), &(data->img.img_width));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, "./img/f.xpm",
			&(data->img.img_height), &(data->img.img_width));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/p.xpm",
			&(data->img.img_height), &(data->img.img_width));
	data->img.img_item = mlx_xpm_file_to_image(data->mlx_ptr, "./img/i.xpm",
			&(data->img.img_height), &(data->img.img_width));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, "./img/e.xpm",
			&(data->img.img_height), &(data->img.img_width));
}
