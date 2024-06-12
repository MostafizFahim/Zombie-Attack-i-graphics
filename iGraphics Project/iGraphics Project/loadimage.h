#ifndef LOADIMAGE_H_INCLUDED
#define LOADIMAGE_H_INCLUDED

#define SCREEN_WIDTH 1490
#define SCREEN_HEIGHT 749
#define UPPER_BACKGROUND_SPEED 5
#define JUMP_LIMIT 100
#define Zombie1Number 7
#define Zombie2Number 5
#define Zombie3Number 3
#define BULLET_NUMBER 1000

#include "Variables.h"
#include "iGraphics.h"
#include "stb_image.h"



/* Home menu image load*/
void menuBackground()
{
	menu[0] = iLoadImage("mainMenu\\menuBackground.png");
	menu[1] = iLoadImage("mainMenu\\sPage.png");
	menu[2] = iLoadImage("mainMenu\\storyPage.png");
	menu[3] = iLoadImage("mainMenu\\scorePage.png");
	menu[4] = iLoadImage("mainMenu\\ins.png");
	menu[5] = iLoadImage("mainMenu\\credit.png");

	buttons[0] = iLoadImage("buttons\\play.png");
	buttons[1] = iLoadImage("buttons\\story.png");
	buttons[2] = iLoadImage("buttons\\highScore.png");
	buttons[3] = iLoadImage("buttons\\instruction.png");
	buttons[4] = iLoadImage("buttons\\credit.png");
	buttons[5] = iLoadImage("buttons\\ex.png");

	button2 = iLoadImage("buttons\\back.png");
}




/*char stand*/
void charStand()
{
	standimage = iLoadImage("CharStand\\CharStand_01.png");
}
/*char stand*/
void charJumpimage()
{
	jumpimage = iLoadImage("CharStand\\CharStand_01.png");
}

/*char run*/

void charRunimageload()
{
	charRunimage[0] = iLoadImage("CharRun\\CharRun_01.png");
	charRunimage[1] = iLoadImage("CharRun\\CharRun_02.png");
	charRunimage[2] = iLoadImage("CharRun\\CharRun_03.png");
	charRunimage[3] = iLoadImage("CharRun\\CharRun_04.png");
	charRunimage[4] = iLoadImage("CharRun\\CharRun_05.png");
	charRunimage[5] = iLoadImage("CharRun\\CharRun_06.png");
}
void charRunBackimageload()
{
	charRunbackimage[0] = iLoadImage("CharRunB\\CharRunB_01.png");
	charRunbackimage[1] = iLoadImage("CharRunB\\CharRunB_02.png");
	charRunbackimage[2] = iLoadImage("CharRunB\\CharRunB_03.png");
	charRunbackimage[3] = iLoadImage("CharRunB\\CharRunB_04.png");
	charRunbackimage[4] = iLoadImage("CharRunB\\CharRunB_05.png");
	charRunbackimage[5] = iLoadImage("CharRunB\\CharRunB_06.png");
}
/*Zombie image load*/
void zombie1image()
{
	z1run[0] = iLoadImage("Run Z1\\Run4.png");
	z1run[1] = iLoadImage("Run Z1\\Run5.png");
	z1run[2] = iLoadImage("Run Z1\\Run6.png");
	z1run[3] = iLoadImage("Run Z1\\Run7.png");
	z1run[4] = iLoadImage("Run Z1\\Run8.png");
	z1run[5] = iLoadImage("Run Z1\\Run9.png");
	z1run[6] = iLoadImage("Run Z1\\Run10.png");
}
/*Zombie image load*/
void zombie2image()
{
	z2run[0] = iLoadImage("Run Z2\\Run4.png");
	z2run[1] = iLoadImage("Run Z2\\Run5.png");
	z2run[2] = iLoadImage("Run Z2\\Run6.png");
	z2run[3] = iLoadImage("Run Z2\\Run7.png");
	z2run[4] = iLoadImage("Run Z2\\Run8.png");
	z2run[5] = iLoadImage("Run Z2\\Run9.png");
	z2run[6] = iLoadImage("Run Z2\\Run10.png");
}
/*Zombie image load*/

void zombie3image()
{
	z3run[0] = iLoadImage("Run Z3\\Run4.png");
	z3run[1] = iLoadImage("Run Z3\\Run5.png");
	z3run[2] = iLoadImage("Run Z3\\Run6.png");
	z3run[3] = iLoadImage("Run Z3\\Run7.png");
	z3run[4] = iLoadImage("Run Z3\\Run8.png");
	z3run[5] = iLoadImage("Run Z3\\Run9.png");
	z3run[6] = iLoadImage("Run Z3\\Run10.png");
}

/*Shoot*/
void bulletImage()
{
	bImage = iLoadImage("CharShoot\\guli.png");
}
/*Shoot image*/
void shootImage()
{
	shootimage[0] = iLoadImage("CharShoot\\CharShoot_01.png");
	shootimage[1] = iLoadImage("CharShoot\\CharShoot_02.png");
	shootimage[2] = iLoadImage("CharShoot\\CharShoot_03.png");
	shootimage[3] = iLoadImage("CharShoot\\CharShoot_04.png");
}





#endif