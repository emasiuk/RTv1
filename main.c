#include "rtv.h"


void	ft_image_pixel_put(t_rtv *rtv, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*image;
	unsigned int	tmp;

	image = mlx_get_data_addr(rtv->image, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(rtv->mlx, rgb));
	if (x > 0 && x < W && y > 0 && y < H)
		memcpy((void *)(image + y * W * (bpp / 8)) + x * (bpp / 8),
		(void *)&tmp, 4);
}




t_vec vectorSub(t_vec *v1, t_vec *v2){
	t_vec result;
	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float vectorDot(t_vec *v1, t_vec *v2){
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}


t_vec		ft_normalize(t_vec *n)
{
	float m;
	t_vec res;

	m = sqrtf(vectorDot(n, n));
	res.x = n->x / m;
	res.y = n->y / m;
	res.z = n->z / m;
	return (res);
}



// int intersection(t_ray *r, t_sphere *s, float *t)
// {
// 	float A = vectorDot(&r->dir, &r->dir);
// 	t_vec dist = vectorSub(&r->start, &s->pos);
// 	float B = 2 * vectorDot(&r->dir, &dist);
// 	float C = vectorDot(&dist, &dist) - (s->radius * s->radius);
// 	float discr = B * B - 4 * A * C;
// 	if (discr < 0)
// 		return (0);
// 	else
// 	{
// 		discr = sqrt(discr);
// 		float t0 = -B - discr;
// 		float t1 = -B + discr;
// 		*t = min(t0, t1);
// 		return (discr);
// 	}
// }
// не рабочая интерсекция для сферы

int createRGB(int r, int g, int b)
{
   return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

// void	sphere(t_rtv *rtv, t_read *read)
// {
// 	t_ray r;
// 	int x;
// 	int y;
// 	int k;
// 	float t;
//
// 	r.dir.z = read->camdir.z;
//
// 	r.start.z = read->campos.z;
// 	r.start.x = read->campos.x;
// 	r.start.y = read->campos.y;
// 	y = -1;
// 	while (++y <= H)
// 	{
// 		float winy = 2. * (double)y / (double)H - 1.;
// 		r.dir.y = (read->camdir.y + 1.0 * winy) * 2 / tan(70 * RAD);
// 		x = -1;
// 		while (++x <= W)
// 		{
// 			float winx = 2. * (double)x / (double)W - 1.;
// 			r.dir.x = (read->camdir.x + 1.0 * winx) * 2 / tan(70 * RAD);
//
// 			k = -1;
// 			while (++k <= read->s)
// 			{
// 				t = -1;
// 				// float discr = intersection(&r, &read->sphere[k]);
// 				float A = vectorDot(&r.dir, &r.dir);
// 				t_vec dist = vectorSub(&r.start, &read->sphere[k].pos);
// 				float B = 2 * vectorDot(&r.dir, &dist);
// 				float C = vectorDot(&dist, &dist) - (read->sphere[k].radius * read->sphere[k].radius);
// 				float discr = B * B - 4 * A * C;
// 				if (discr >= 0)
// 				{
// 					discr = sqrt(discr);
// 					float t0 = (-B - discr) / 2 * A;
// 					float t1 = (-B + discr) / 2 * A;
// 					t = min(t0, t1);
//
// 					t_vec refl;
//
// 					refl.x = r.start.x + r.dir.x * t;
// 					refl.y = r.start.y + r.dir.y * t;
// 					refl.z = r.start.z + r.dir.z * t;
//
// 					t_vec norm;
//
// 					norm.x = (refl.x - read->sphere[k].pos.x) / read->sphere[k].radius;
// 					norm.y = (refl.y - read->sphere[k].pos.y) / read->sphere[k].radius;
// 					norm.z = (refl.z - read->sphere[k].pos.z) / read->sphere[k].radius;
//
// 					t_vec b = ft_normalize(&norm);
//
// 					int j = -1;
// 					rtv->r = 0;
// 					rtv->g = 0;
// 					rtv->b = 0;
// 					while (++j < read->l)
// 					{
//
// 						int red;
// 						int green;
// 						int blue;
//
// 						t_vec light;
//
// 						light.x = (read->light[j].pos.x - refl.x);
// 						light.y = (read->light[j].pos.y - refl.y);
// 						light.z = (read->light[j].pos.z - refl.z);
//
// 						t_vec a = ft_normalize(&light);
//
// 						double dt = vectorDot(&a, &b);
//
// 						red = read->sphere[k].color.r * dt;
// 						green = read->sphere[k].color.g * dt;
// 						blue = read->sphere[k].color.b * dt;
//
// 						if (red < 0)
// 							red = 0;
// 						if (blue < 0)
// 							blue = 0;
// 						if (green < 0)
// 							green = 0;
//
// 						// rtv->r = sqrt(pow(read->sphere[k].color.r * dt, 2) + pow(rtv->r, 2));
// 						// rtv->g = sqrt(pow(read->sphere[k].color.g * dt, 2) + pow(rtv->g, 2));
// 						// rtv->b = sqrt(pow(read->sphere[k].color.b * dt, 2) + pow(rtv->b, 2));
//
//
//
// 						rtv->r = sqrt(pow(red, 2) + pow(rtv->r, 2));
// 						rtv->g = sqrt(pow(green, 2) + pow(rtv->g, 2));
// 						rtv->b = sqrt(pow(blue, 2) + pow(rtv->b, 2));
//
//
// 						// rtv->r = read->sphere[k].color.r * dt;
// 						// rtv->g = read->sphere[k].color.g * dt;
// 						// rtv->b = read->sphere[k].color.b * dt;
//
//
// 						if (rtv->r > 255)
// 							rtv->r = 255;
// 						else if (rtv->r < 0)
// 							rtv->r = 0;
//
// 						if (rtv->g > 255)
// 							rtv->g = 255;
// 						else if (rtv->g < 0)
// 							rtv->g = 0;
//
// 						if (rtv->b > 255)
// 							rtv->b = 255;
// 						else if (rtv->b < 0)
// 							rtv->b = 0;
// 					}
// 					ft_image_pixel_put(rtv, x, y, createRGB(rtv->r,
// 						rtv->g, rtv->b));
// 				}
// 			}
// 		}
// 	}
// }



void		plane(t_rtv *rtv, t_read *read)
{
	t_ray r;
	int x;
	int y;
	float t;
	int k;

	r.dir.z = read->camdir.z;

	r.start.z = read->campos.z;
	r.start.x = read->campos.x;
	r.start.y = read->campos.y;
	y = -1;
	while (++y <= H)
	{
		float winy = 2. * (double)y / (double)H - 1;
		r.dir.y = (read->camdir.y + 1.0 * winy) / tan(65 * RAD);
		x = -1;
		while (++x <= W)
		{
			float winx = 2. * (double)x / (double)W - 1.;
			r.dir.x = (read->camdir.x + 1.0 * winx) / tan(65 * RAD);

			k = -1;
			while (++k < read->p)
			{
				t_vec one;

				one.x = 1;
				one.y = 1;
				one.z = 1;

				t = -1;
				float inter = vectorDot(&r.dir, &read->plane[k].norm);
				if (inter > 0)
				{

					t_vec unknow;

					unknow.x = read->plane[k].pos.x - r.dir.x * inter;
					unknow.y = read->plane[k].pos.y - r.dir.y * inter;
					unknow.z = read->plane[k].pos.z - r.dir.z * inter;

					t = (vectorDot(&unknow, &read->plane[k].norm)) / inter;

					if (t > 0)
					{

						t_vec refl;

						refl.x = r.start.x + r.dir.x * t;
						refl.y = r.start.y + r.dir.y * t;
						refl.z = r.start.z + r.dir.z * t;

						t_vec norm;

						norm.x = (refl.x - read->plane[k].pos.x);
						norm.y = (refl.y - read->plane[k].pos.y);
						norm.z = (refl.z - read->plane[k].pos.z);

						t_vec b = ft_normalize(&norm);

						int j = -1;
						rtv->r = 0;
						rtv->g = 0;
						rtv->b = 0;
						while (++j < read->l)
						{
							//
							// int red;
							// int green;
							// int blue;

							t_vec light;

							light.x = (read->light[j].pos.x - refl.x);
							light.y = (read->light[j].pos.y - refl.y);
							light.z = (read->light[j].pos.z - refl.z);

							t_vec a = ft_normalize(&light);

							double dt = vectorDot(&a, &b);

							printf("%f\n", dt);

							// red = read->plane[k].color.r * dt;
							// green = read->plane[k].color.g * dt;
							// blue = read->plane[k].color.b * dt;
							//
							// if (red < 0)
							// 	red = 0;
							// if (blue < 0)
							// 	blue = 0;
							// if (green < 0)
							// 	green = 0;

							// rtv->r = sqrt(pow(read->sphere[k].color.r * dt, 2) + pow(rtv->r, 2));
							// rtv->g = sqrt(pow(read->sphere[k].color.g * dt, 2) + pow(rtv->g, 2));
							// rtv->b = sqrt(pow(read->sphere[k].color.b * dt, 2) + pow(rtv->b, 2));
							//


							// rtv->r = sqrt(pow(red, 2) + pow(rtv->r, 2));
							// rtv->g = sqrt(pow(green, 2) + pow(rtv->g, 2));
							// rtv->b = sqrt(pow(blue, 2) + pow(rtv->b, 2));


							rtv->r = read->sphere[k].color.r * dt;
							rtv->g = read->sphere[k].color.g * dt;
							rtv->b = read->sphere[k].color.b * dt;


							if (rtv->r > 255)
							rtv->r = 255;
							else if (rtv->r < 0)
							rtv->r = 0;

							if (rtv->g > 255)
							rtv->g = 255;
							else if (rtv->g < 0)
							rtv->g = 0;

							if (rtv->b > 255)
							rtv->b = 255;
							else if (rtv->b < 0)
							rtv->b = 0;

						}
					}
					ft_image_pixel_put(rtv, x, y, createRGB(rtv->r,
						rtv->g, rtv->b));

				}
			}

		}
	}
}




int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_rtv *rtv;
		t_read *read;

		read = (t_read *)malloc(sizeof(t_read));
		rtv = (t_rtv *)malloc(sizeof(t_rtv));
		read_scene(read, argv[1]);
		init(rtv);
		// sphere(rtv, read);
		plane(rtv, read);
		mlx_loop_hook(rtv->mlx, hook, rtv);
		mlx_loop(rtv->mlx);
	}
	return (0);
}
