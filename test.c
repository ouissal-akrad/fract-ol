#include<mlx.h>
#include "mlx.h"
#include<math.h>
void	draw_circle(void *mlx, void *win, int x, int y, int r)
{
	int	d;
	int	cur_x;
	int	cur_y;

	d = 3 - (2 * r);
	cur_x = 0;
	cur_y = r;
	while (cur_x <= cur_y)
	{
		mlx_pixel_put(mlx, win, x + cur_x, y + cur_y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x + cur_y, y + cur_x, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x - cur_x, y + cur_y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x - cur_y, y + cur_x, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x + cur_x, y - cur_y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x + cur_y, y - cur_x, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x - cur_x, y - cur_y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, x - cur_y, y - cur_x, 0xFFFFFF);
		if (d < 0)
			d = d + (4 * cur_x) + 6;
		else
		{
			d = d + 4 * (cur_x - cur_y) + 10;
			cur_y--;
		}
		cur_x++;
	}
}
int main()
{
	void *mlx_pnt;
	void *win_mlx;
	// int x = 0;
	// int y = 20;
	mlx_pnt = mlx_init();
	win_mlx = mlx_new_window(mlx_pnt,1200 ,720 ,"Fract-ol");
	// while (x <= 1200)
	// {
	// 	mlx_pixel_put(mlx_pnt, win_mlx, x, y ,0xFFFFFF);
	// 	x++;
	// }
	draw_circle(mlx_pnt,win_mlx, 500,500,120);
	mlx_loop(mlx_pnt);
}
