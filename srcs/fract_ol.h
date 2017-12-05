/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:22:53 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 14:50:57 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <fcntl.h>
# include <OpenCL/opencl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "./../minilibx/mlx.h"
# include "./../libft/libft.h"

# define BUF_SIZE		10000
# define MANDEL			1
# define JULIA			2
# define SHIP			3
# define PREY			4
# define MAND5			5
# define INV			6

typedef struct			s_cl
{
	int					list_size;
	int					*input;
	int					fd;
	char				buff[BUF_SIZE];
	char				*source_str;
	size_t				source_size;
	cl_platform_id		platform_id;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	cl_int				ret;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				input_mem_obj;
	cl_mem				output_mem_obj;
	cl_program			program;
	cl_kernel			kernel;
	size_t				global_item_size;
	size_t				local_item_size;
}						t_cl;

typedef struct			s_fractal
{
	int					color;
	int					origin_max_iter;
	int					max_iter;
	int					info;
	int					move;
	int					x;
	int					y;
	double				origin_c_x;
	double				origin_c_y;
	double				c_x;
	double				c_y;
	double				origin_min_x[4];
	double				origin_max_x[4];
	double				origin_min_y[4];
	double				origin_max_y[4];
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	double				speed;
}						t_fractal;

typedef struct			s_image
{
	void				*img;
	int					*data;
	int					bpp;
	int					sl;
	int					endian;
	int					height;
	int					width;
}						t_image;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	int					name;
	t_image				image;
	t_fractal			fractal;
	t_cl				cl;
}						t_env;

int						ft_error(char *msg);
int						ft_usage(void);
int						ft_man(void);

void					ft_mandel(t_fractal *fractal);
void					ft_julia(t_fractal *fractal);
void					ft_ship(t_fractal *fractal);
void					ft_prey(t_fractal *fractal);
void					ft_mand5(t_fractal *fractal);
void					ft_inv(t_fractal *fractal);

int						ft_keypress_hook(int keycode, t_env *e);
int						ft_button_press_hook(int btn, int x, int y, t_env *e);
int						ft_motion_notify_hook(int x, int y, t_env *e);

void					ft_button_1(t_env *e, int x, int y);
void					ft_button_2(t_env *e, int x, int y);
void					ft_button_4(t_env *e);
void					ft_button_5(t_env *e);

void					ft_keypress_tool(int keycode, t_env *e);
void					ft_keypress_tool_2(int keycode, t_env *e);
void					ft_keypress_tool_3(int keycode, t_env *e);
void					ft_keypress_tool_4(int keycode, t_env *e);
void					ft_keypress_tool_5(int keycode, t_env *e);
void					ft_keypress_tool_6(int keycode, t_env *e);
void					ft_keypress_tool_7(int keycode, t_env *e);
void					ft_keypress_tool_8(int keycode, t_env *e);
void					ft_keypress_tool_9(int keycode, t_env *e);

void					ft_iter_info(t_env *e);
void					ft_speed_info(t_env *e);
void					ft_iter_speed_info(t_env *e);
void					ft_spot(t_env *e, int spot);

t_image					ft_new_image(t_env *e, int width, int height);
int						ft_init_mlx(t_env *e, char *filename, int w, int h);
void					ft_process_mlx(t_env *e);

#endif
