#include "rtv.h"

void	init(t_rtv *rtv)
{
	rtv->mlx = mlx_init();
	rtv->win = mlx_new_window(rtv->mlx, W, H, "RTv1");
	rtv->image = mlx_new_image(rtv->mlx, W, H);
}
