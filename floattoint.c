#include <stdio.h>
#include <math.h>

int main()
{
	float	a[2];
	float	b[2];
	float	c[2];
	float	dtonextX;
	float	dtonextY;
	float	sideDistX;
	float	sideDistY;
	// float	deltaDistX;
	// float	deltaDistY;
	
	a[0] = 1.4;
	a[1] = 1.3;
	dtonextX = (int)a[0] + 1 - a[0];
	dtonextY = (int)a[1] + 1 - a[1];
	sideDistX = dtonextX / cos(1);
	sideDistY = dtonextY / cos(1);
	printf("SDX %f, SDY %f\n", sideDistX, sideDistY);
	b[0] = (int)a[0] + 1;
	b[1] = sideDistY * sin(1);
	c[0] = sideDistX * cos(1);
	c[1] = (int)a[1] + 1;

	printf("Bxy %f %f, SDX %f, Cxy %f %f, SDY %f\n", b[0], b[1], sideDistX, c[0], c[1], sideDistY);
}