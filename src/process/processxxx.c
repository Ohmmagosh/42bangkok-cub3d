/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/20 13:22:16 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

    // double xbuff = 4;
    // double ybuff = 1;
    float angle = 0;


# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define COLOR 0xFFFFFF

void	my_mlx_pixel_put(t_myimg *mying, int x, int y, int color)
{
	char	*dst;

    printf("\t\tPut color %d, at  x = %d, y = %d\n", color, x, y);
	dst = mying->addr + (y * mying->line_length + x * (mying->bits_per_pixel / 8));
    printf("exit %p\n", dst);
	*(unsigned int*)dst = color;
    printf("exit %p\n", dst);
}

void get_point_on_circle(float x1, float y1, float angle, float *x2, float *y2)
{
    // Convert angle to radians
    angle = angle * M_PI / 180.0;

    // Calculate x and y coordinates
    *x2 = x1 + 10 * cos(angle);
    *y2 = y1 + 10 * sin(angle);
}


void	circle(t_pro *p)
{

    // define circle parameters
    double h = 250;    // center x-coordinate
    double k = 250;    // center y-coordinate
    double r = 5;    // radius

    // draw the circle
    double x = h - r;
    while (r > 0)
    {
        printf("radius = %f\n", r);
        while (x <= h + r)
        {
            //printf("x = %f h + r = %f\n", x, h + r);
            double y = k + sqrt(r * r - (x - h) * (x - h));
            //mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, 0xFF0000);  // white color
            my_mlx_pixel_put(&p->mlx.img, x , y , 0xFF0000);
            y = k - sqrt(r * r - (x - h) * (x - h));
            //mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, 0xFF0000);  // white color
            my_mlx_pixel_put(&p->mlx.img, x , y , 0xFF0000);
            x += 0.01;
        }
        x = h - r;
        r-=2;
    }
    printf("Exit Circle\n");

}

void draw_line(void *mlx_ptr, void *win_ptr, float x1, float y1, float ang, t_mlx *mlx, t_pro *p)
{
    float x2;
    float y2;

    get_point_on_circle(x1, y1, ang, &x2, &y2);
    float dx = fabsf(x2 - x1);
    float dy = fabsf(y2 - y1);
    float sx = (x1 < x2) ? 1 : -1;
    float sy = (y1 < y2) ? 1 : -1;
    float err = dx - dy;
    float x = x1;
    float y = y1;

    int getout = 1;
    p->mlx.img.img = mlx_new_image(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT);
    p->mlx.img.addr = mlx_get_data_addr(p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);
    // circle(p);
    printf("x in %f\n", x);
    while (1)
    {
        printf("KUY!!! Time %d x = %f y = %f\n", getout, x ,y);
        my_mlx_pixel_put(&(p->mlx.img), x, y, 0xFFFFFF);
        printf("Get point\n");

        //mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
        if (x == 0 || x == WIN_WIDTH || y == 0 || y == WIN_HEIGHT) {
            printf("Break x = %f , y = %f\n", x, y);
            break; // reached the edge of the window
        }
        float e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, mlx->img.img, 0, 0);
}

int	key_hooker(int keycode , t_pro *p)
{
	// ft_startpo(&g_mapber);
	// g_count++;

	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 \
		|| keycode == 123 || keycode == 124 || keycode == 125 \
		|| keycode == 126)
    {
        if (keycode == 0)
            angle -= 1;
        else if (keycode == 2)
             angle += 1;
        printf("kod %d %f\n", keycode, angle);
        // mlx_clear_window(p->mlx.mlx, p->mlx.win);
        // p->mlx.win = mlx_new_window(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT, "My Window");
        printf("Here From Hook\n");
        draw_line(p->mlx.mlx, p->mlx.win, 250, 250, angle, &(p->mlx), p);
    }
    return 0;
}


void	process_cube(t_pro *p)
{
    int x1, y1, x2, y2;
    int color;
    double xstart = 250;
    double ystart = 250;
    float m = 1.5;
    // t_myimg myimg;

    // Initialize mlx
    p->mlx.mlx = mlx_init();
    p->mlx.win = mlx_new_window(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT, "My Window");

    // Img
    //p->mlx.img = malloc(sizeof(t_myimg));
    // p->mlx.img.img = mlx_new_image(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT);
    // p->mlx.img.addr = mlx_get_data_addr(p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);



    // Set the coordinates of the two points that define the line
    x1 = 250;
    y1 = 250;
    x2 = 350;
    y2 = 350;


    // Draw the line using mlx

    // munn(x1, y1, m, p);
    draw_line(p->mlx.mlx, p->mlx.win, 250, 250, angle, &p->mlx , p);
    //mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img->img, 0, 0);
    mlx_hook(p->mlx.win, 2, 1L << 0, key_hooker, &p);
    // mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, NULL, 250, 250);

    // Display the window
    mlx_loop(p->mlx.mlx);

    // return (0);
}
