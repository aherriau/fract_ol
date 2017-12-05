typedef struct	s_fractal
{
	int			color;
	int			origin_max_iter;
	int			max_iter;
	int			info;
	int			move;
	int			x;
	int			y;
	double		origin_c_x;
	double		origin_c_y;
	double		c_x;
	double		c_y;
	double		origin_min_x[4];
	double		origin_max_x[4];
	double		origin_min_y[4];
	double		origin_max_y[4];
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		speed;
}				t_fractal;

static void		get_color(int red, int green, int blue, int *color)
{
	*color = 0;
	*color += red << 16;
	*color += green << 8;
	*color += blue;
}

static void		color_1(int k, int max_iter, double norm, int *color)
{
	if (k == max_iter)
    	*color = 0;
	else
	{
		double	mu = k + 1 - log(log(sqrt(norm))) / log(2.0);
		double	muPrime = mu / max_iter * 255;
		int		red = fmin(10 * muPrime, 255);
		int		green = fmin(muPrime, 255);
		int		blue = fmax(255 - 15 * muPrime, 0);
		get_color(red, green, blue, color);
	}
}

static void		color_2(int k, int *color)
{
	int j = k % 16;
	int mapping[16];
	get_color(66, 30, 15, color);
	mapping[0] = *color;
	get_color(25, 7, 26, color);
	mapping[1] = *color;
	get_color(9, 1, 47, color);
	mapping[2] = *color;
	get_color(4, 4, 73, color);
	mapping[3] = *color;
	get_color(0, 7, 100, color);
	mapping[4] = *color;
	get_color(12, 44, 138, color);
	mapping[5] = *color;
	get_color(24, 82, 177, color);
	mapping[6] = *color;
	get_color(57, 125, 209, color);
	mapping[7] = *color;
	get_color(134, 181, 229, color);
	mapping[8] = *color;
	get_color(211, 236, 248, color);
	mapping[9] = *color;
	get_color(241, 233, 191, color);
	mapping[10] = *color;
	get_color(248, 201, 95, color);
	mapping[11] = *color;
	get_color(255, 170, 0, color);
	mapping[12] = *color;
	get_color(204, 128, 0, color);
	mapping[13] = *color;
	get_color(153, 87, 0, color);
	mapping[14] = *color;
	get_color(106, 52, 3, color);
	mapping[15] = *color;
	*color = mapping[j];
}

static void		color_3(int k, int max_iter, int *color)
{
	double	mu = sin(0.01 * k + 1) * 127 + 128;
	int		red = mu * 25;
	mu = sin(0.01 * k + 1) * 127 + 128;
	int		green = mu * 127;
	mu = sin(0.01 * k + 1) * 127 + 128;
	int		blue = mu * 128;
	get_color(red, green, blue, color);
}

__kernel void	mandelbrot(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = zx + f.c_x;
	double	cy = zy + f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * x_temp * zy + cy;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}

__kernel void	julia(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = f.c_x;
	double	cy = f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * x_temp * zy + cy;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}

__kernel void	burning_ship(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = zx + f.c_x;
	double	cy = zy + f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * fabs(x_temp * zy) + cy;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}

__kernel void	bird_of_prey(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = zx + f.c_x;
	double	cy = zy + f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		zx = (zx * zx - (zy * zy * 3)) * fabs(zx) + cx;
		zy = ((x_temp * x_temp * 3) - (zy * zy)) * fabs(zy) + cy;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}

__kernel void	mandelbrot5(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = zx + f.c_x;
	double	cy = zy + f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		zx = zx * zx * zx * zx * zx - 10 * zx * zx * zx * zy * zy + 5 * zx * zy * zy * zy * zy + cx;
		zy = 5 * x_temp * x_temp * x_temp * x_temp * zy - 10 * x_temp * x_temp * zy * zy * zy + zy * zy * zy * zy * zy + cy;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}

__kernel void	inverse(__global const int *input, __global int *output, t_fractal f)
{
    int		i = get_global_id(0);
	int		x = input[i] % 1080;
	int		y = input[i] / 1080;
	double	zx = f.min_x + (f.max_x - f.min_x) / 1080 * x;
	double	zy = f.min_y + (f.max_y - f.min_y) / 1080 * y;
	double	cx = f.c_x;
	double	cy = f.c_y;
	double	norm = zx * zx + zy * zy;
	int		k = 0;
	while ((norm < 4) && (k < f.max_iter))
	{
		double	x_temp = zx;
		double	div = (zx * zx - zy * zy + cx) * (zx * zx - zy * zy + cx) +
			(2 * zx * zy + cy) * (2 * zx * zy + cy);
		zx = (zx * zx - zy * zy + cx) / div;
		zy = (2 * x_temp * zy + cy) / div;
		norm = zx * zx + zy * zy;
		k++;
	}
	int color;
	if (f.color == 1)
		color_1(k, f.max_iter, norm, &color);
	if (f.color == 2)
		color_2(k, &color);
	if (f.color == 3)
		color_3(k, f.max_iter, &color);
	output[i] = color;
}
