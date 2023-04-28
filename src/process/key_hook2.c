#include "../../cub3d.h"

void	rotate_hook(float angdegree, t_pro *p)
{
	float	angrad;
	float	olddirx;
	float	oldplanex;

	angrad = angdegree * (M_PI / 180.0);
	// angrad = 3.00;
	// printf("%f\n", angrad);
	olddirx = p->di.x;
	oldplanex = p->spt.plane.x;

	// printf("dix = %f diy = %f\n", p->di.x, p->di.y);
	p->di.x = (p->di.x * cos(angrad)) - (p->di.y * sin(angrad));
	p->di.y = (olddirx * sin(angrad)) + (p->di.y * cos(angrad));
	// printf("dix = %f diy = %f\n", p->di.x, p->di.y);
	// printf("pos = %f pos = %f\n", p->tline.pos.x , p->tline.pos.y);

	p->spt.plane.x = (p->spt.plane.x * cos(angrad)) - (p->spt.plane.y * sin(angrad));
	p->spt.plane.y = (oldplanex * sin(angrad)) + (p->spt.plane.y * cos(angrad));
}

//     //rotate to the right
//     if (keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if (keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
//   }
// }

int	mouse_hook(int button, int x, int y, t_pro *p)
{
	if (button == 4)
		rotate_hook(-5.0, p);
	else if (button == 5)
		rotate_hook(5.0, p);
	// player_move(p);
}
