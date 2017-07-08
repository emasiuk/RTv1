#include "rtv.h"

void		read_plane(char **temp, t_read *read)
{
	read->plane[read->p].pos.x = atof(temp[1]);
	read->plane[read->p].pos.y = atof(temp[2]);
	read->plane[read->p].pos.z = atof(temp[3]);

	read->plane[read->p].norm.x = atof(temp[4]);
	read->plane[read->p].norm.y = atof(temp[5]);
	read->plane[read->p].norm.z = atof(temp[6]);

	read->plane[read->p].color.r = ft_atoi(temp[7]);
	read->plane[read->p].color.g = ft_atoi(temp[8]);
	read->plane[read->p].color.b = ft_atoi(temp[9]);
	// printf("pos  x = %f  y = %f  z = %f\n", read->plane[read->p].pos.x, read->plane[read->p].pos.y, read->plane[read->p].pos.z);
	// printf("norm   x = %f  y = %f  z = %f\n", read->plane[read->p].norm.x, read->plane[read->p].norm.y, read->plane[read->p].norm.z);
	// printf("color   r = %d  g = %d  b = %d\n", read->plane[read->p].color.r, read->plane[read->p].color.g, read->plane[read->p].color.b);

	read->p++;

}


void		read_sphere(char **temp, t_read *read)
{
	read->sphere[read->s].pos.x = atof(temp[1]);
	read->sphere[read->s].pos.y = atof(temp[2]);
	read->sphere[read->s].pos.z = atof(temp[3]);

	read->sphere[read->s].radius = atof(temp[4]);

	read->sphere[read->s].color.r = ft_atoi(temp[5]);
	read->sphere[read->s].color.g = ft_atoi(temp[6]);
	read->sphere[read->s].color.b = ft_atoi(temp[7]);
	read->s += 1;
}



void		read_light(char **temp, t_read *read)
{
	read->light[read->l].pos.x = atof(temp[1]);
	read->light[read->l].pos.y = atof(temp[2]);
	read->light[read->l].pos.z = atof(temp[3]);
	read->l += 1;
}



void		read_cam(char **temp, t_read *read)
{
	read->campos.x = atof(temp[1]);
	read->campos.y = atof(temp[2]);
	read->campos.z = atof(temp[3]);

	read->camdir.x = atof(temp[4]);
	read->camdir.y = atof(temp[5]);
	read->camdir.z = atof(temp[6]);
}


void		calculate(t_read *read, char *filename)
{
	char *str;
	int fd = open(filename, O_RDONLY);
	char **temp;
	read->l = 0;
	read->s = 0;
	read->p = 0;
	int i = -1;
	while (get_next_line(fd, &str) == 1)
	{
		temp = ft_strsplit(str, ' ');
		if (ft_strcmp(temp[0], "light") == 0)
			read->l++;
		if (ft_strcmp(temp[0], "sphere") == 0)
			read->s++;
		// if (temp[0] == 'cone')
		// 	read_cone();
		// if (temp[0] == 'cylin')
		// 	read_cylin();
		if (ft_strcmp(temp[0], "plane") == 0)
			read->p++;
		free(str);
		while (temp[++i] != NULL)
			free(temp[i]);
		free(temp);
		i = -1;
	}
	close(fd);
}

t_read		read_scene(t_read *read, char *filename)
{
	calculate(read, filename);
	read->sphere = (t_sphere *)malloc(sizeof(t_sphere) * read->s);
	read->light = (t_light *)malloc(sizeof(t_light) * read->l);
	read->plane = (t_plane *)malloc(sizeof(t_plane) * read->p);
	char *str;
	int fd = open(filename, O_RDONLY);
	char **temp;
	read->s = 0;
	read->l = 0;
	read->p = 0;

	int i = -1;
	while (get_next_line(fd, &str) == 1)
	{
		temp = ft_strsplit(str, ' ');
		if (ft_strcmp(temp[0], "camera") == 0)
			read_cam(temp, read);
		if (ft_strcmp(temp[0], "light") == 0)
			read_light(temp, read);
		if (ft_strcmp(temp[0], "sphere") == 0)
			read_sphere(temp, read);
		// if (temp[0] == 'cone')
		// 	read_cone();
		// if (temp[0] == 'cylin')
		// 	read_cylin();
		if (ft_strcmp(temp[0], "plane") == 0)
			read_plane(temp, read);
		i = -1;
		free(temp);
		free(str);
	}
	return (*read);
}
