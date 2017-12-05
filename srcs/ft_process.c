/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherriau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:37:34 by aherriau          #+#    #+#             */
/*   Updated: 2017/12/05 13:27:16 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_cl_1(t_env *e)
{
	e->cl.fd = open("./srcs/fractal.cl", O_RDONLY);
	if (e->cl.fd == -1)
		exit(ft_error("Error\n"));
	e->cl.source_size = read(e->cl.fd, e->cl.buff, BUF_SIZE);
	e->cl.source_str = ft_strdup((char *)(e->cl.buff));
	close(e->cl.fd);
	e->cl.platform_id = NULL;
	e->cl.device_id = NULL;
	e->cl.ret = clGetPlatformIDs(1, &(e->cl.platform_id),
			&(e->cl.ret_num_platforms));
	e->cl.ret = clGetDeviceIDs(e->cl.platform_id, CL_DEVICE_TYPE_GPU, 1,
			&(e->cl.device_id), &(e->cl.ret_num_devices));
	e->cl.context = clCreateContext(NULL, 1, &(e->cl.device_id), NULL, NULL,
			&(e->cl.ret));
	e->cl.command_queue = clCreateCommandQueue(e->cl.context, e->cl.device_id,
			0, &(e->cl.ret));
	e->cl.input_mem_obj = clCreateBuffer(e->cl.context, CL_MEM_READ_ONLY,
			e->cl.list_size * sizeof(int), NULL, &(e->cl.ret));
	e->cl.output_mem_obj = clCreateBuffer(e->cl.context, CL_MEM_WRITE_ONLY,
			e->cl.list_size * sizeof(int), NULL, &(e->cl.ret));
	e->cl.ret = clEnqueueWriteBuffer(e->cl.command_queue, e->cl.input_mem_obj,
			CL_TRUE, 0, e->cl.list_size * sizeof(int), e->cl.input, 0, NULL,
			NULL);
}

void	ft_cl_2(t_env *e)
{
	e->cl.program = clCreateProgramWithSource(e->cl.context, 1,
			(const char **)&(e->cl.source_str),
			(const size_t *)&(e->cl.source_size), &(e->cl.ret));
	e->cl.ret = clBuildProgram(e->cl.program, 1, &(e->cl.device_id), NULL, NULL,
			NULL);
	e->cl.kernel = NULL;
	if (e->name == MANDEL)
		e->cl.kernel = clCreateKernel(e->cl.program, "mandelbrot",
				&(e->cl.ret));
	else if (e->name == JULIA)
		e->cl.kernel = clCreateKernel(e->cl.program, "julia", &(e->cl.ret));
	else if (e->name == SHIP)
		e->cl.kernel = clCreateKernel(e->cl.program, "burning_ship",
				&(e->cl.ret));
	else if (e->name == PREY)
		e->cl.kernel = clCreateKernel(e->cl.program, "bird_of_prey",
				&(e->cl.ret));
	else if (e->name == MAND5)
		e->cl.kernel = clCreateKernel(e->cl.program, "mandelbrot5",
				&(e->cl.ret));
	else if (e->name == INV)
		e->cl.kernel = clCreateKernel(e->cl.program, "inverse", &(e->cl.ret));
	else
		exit(ft_error("Error\n"));
}

void	ft_cl_3(t_env *e)
{
	e->cl.ret = clSetKernelArg(e->cl.kernel, 0, sizeof(cl_mem),
			(void *)&(e->cl.input_mem_obj));
	e->cl.ret = clSetKernelArg(e->cl.kernel, 1, sizeof(cl_mem),
			(void *)&(e->cl.output_mem_obj));
	e->cl.ret = clSetKernelArg(e->cl.kernel, 2, sizeof(t_fractal),
			(void *)&(e->fractal));
	e->cl.global_item_size = e->cl.list_size;
	e->cl.local_item_size = 240;
	e->cl.ret = clEnqueueNDRangeKernel(e->cl.command_queue, e->cl.kernel, 1,
			NULL, &(e->cl.global_item_size), &(e->cl.local_item_size), 0, NULL,
			NULL);
	e->cl.ret = clEnqueueReadBuffer(e->cl.command_queue, e->cl.output_mem_obj,
			CL_TRUE, 0, e->cl.list_size * sizeof(int), e->image.data, 0, NULL,
			NULL);
	e->cl.ret = clFlush(e->cl.command_queue);
	e->cl.ret = clFinish(e->cl.command_queue);
	e->cl.ret = clReleaseKernel(e->cl.kernel);
	e->cl.ret = clReleaseProgram(e->cl.program);
	e->cl.ret = clReleaseMemObject(e->cl.input_mem_obj);
	e->cl.ret = clReleaseMemObject(e->cl.output_mem_obj);
	e->cl.ret = clReleaseCommandQueue(e->cl.command_queue);
	e->cl.ret = clReleaseContext(e->cl.context);
	free(e->cl.source_str);
	free(e->cl.input);
}

void	ft_process_mlx(t_env *e)
{
	int		i;

	mlx_clear_window(e->mlx, e->win);
	e->image = ft_new_image(e, 1080, 1080);
	if (e->image.img == NULL)
		exit(ft_error("Error\n"));
	e->cl.input = (int *)malloc(sizeof(int) * e->cl.list_size);
	i = 0;
	while (i < e->cl.list_size)
	{
		e->cl.input[i] = i;
		i++;
	}
	ft_cl_1(e);
	ft_cl_2(e);
	ft_cl_3(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
	mlx_destroy_image(e->mlx, e->image.img);
	if (e->fractal.info == 1)
		ft_iter_speed_info(e);
}
