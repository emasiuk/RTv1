#ifndef _RTV_H
# define _RTV_H
# define RAD (0.0175433)
# define W 800
# define H 800
# define min(a,b) (((a) < (b)) ? (a) : (b))
# define max(a,b) (((a) < (b)) ? (b) : (a))

# include "mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>


typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;


typedef struct	s_col
{
	int r;
	int g;
	int b;
}				t_col;


typedef struct	s_light
{
	t_vec pos;
}				t_light;


typedef struct	s_sphere
{
	t_col color;
	t_vec pos;
	double radius;
}				t_sphere;


typedef	struct	s_plane
{
	t_col color;
	t_vec pos;
	t_vec norm;
}				t_plane;


typedef struct	s_ray
{
	t_vec start;
	t_vec dir;
}				t_ray;


typedef struct  s_rtv
{
	double r;
	double g;
	double b;
    void *mlx;
    void *win;
    void *image;
}               t_rtv;

typedef struct	s_read
{
	t_vec campos;
	t_vec camdir;
	t_light *light;
	int l;
	int s;
	int p;
	t_sphere *sphere;
	t_plane *plane;
}				t_read;



t_read		read_scene(t_read *read, char *filename);
int keyboard(int key);
int		press_x();
int hook(t_rtv *rtv);
void	init(t_rtv *rtv);



#endif
