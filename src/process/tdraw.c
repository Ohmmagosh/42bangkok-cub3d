#include "../../cub3d.h"
#include <math.h>

void	draw_T(t_pro *p)
{
	t_coord	tedge;
	t_coord	edgeleft;
	t_coord	edgeright;

	tedge = get_point_on_circle(g_xstart, g_ystart, 30, g_angle);
	draw_line(g_xstart, g_ystart, tedge, p);
	printf("tedge x %f y %f\n", tedge.x, tedge.y);
	// edgeleft = malloc(sizeof(t_coord));
	edgeleft = get_point_on_circle(tedge.x, tedge.y, 17, g_angle - 90);
	// printf("edgeleft x %f y %f\n", edgeleft.x, edgeleft.y);
	edgeright = get_point_on_circle(tedge.x, tedge.y, 17, g_angle + 90);
	draw_line(tedge.x, tedge.y, edgeleft, p);
	draw_line(tedge.x, tedge.y, edgeright, p);
}
