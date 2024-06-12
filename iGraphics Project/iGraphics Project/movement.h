
#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

#define screenHeight 522
#define screenWidth 840
#define upperbackgroundspeed 5
#define Zombie1Number 3
#define Zombie2Number 2
#define Zombie3Number 1
#define BulletNumber 100

//#include "Variable.h"
#include"iGraphics.h"

void zom1run()
{
	for (int i = 0; i<Zombie1Number; i++)
	{
		if (Zr1[i].zrShow == true)
		{
			iShowImage(Zr1[i].zrX, Zr1[i].zrY, 65, 90, z1run[Zr1[i].zrIndex]);
		}
	}
}

void zom2run()
{
	for (int i = 0; i<Zombie2Number; i++)
	{
		if (Zr2[i].zrShow = true)
		{
			iShowImage(Zr2[i].zrX, Zr2[i].zrY, 82, 116, z2run[Zr2[i].zrIndex]);
		}
	}
}
void zom3run()
{
	for (int i = 0; i<Zombie3Number; i++)
	{
		if (Zr3[i].zrShow = true)
		{
			iShowImage(Zr3[i].zrX, Zr3[i].zrY, 82, 116, z3run[Zr3[i].zrIndex]);
		}
	}
}





#endif