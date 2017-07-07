#include "rtv.h"

int keyboard(int key)
{
    (key == 53) ? exit(228) : 228;
    return (0);
}

int		press_x()
{
	exit(10);
	return (0);
}

int hook(t_rtv *rtv)
{
    mlx_key_hook(rtv->win, keyboard, rtv);
	mlx_hook(rtv->win, 17, 0L, press_x, rtv);
	mlx_put_image_to_window(rtv->mlx, rtv->win, rtv->image, 0, 0);
    return (0);
}
