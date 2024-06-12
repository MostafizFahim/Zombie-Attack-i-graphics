#include "iGraphics.h"
#include <iostream>
#include "Variable.h"

#define screenHeight 522
#define screenWidth 840
#define upperbackgroundspeed 8
#define Zombie1Number 3
#define Zombie2Number 2
#define Zombie3Number 1
#define BulletNumber 50
using namespace std;



void HealthShow()
{
	if (health == 6)
		iShowImage(110, 470, 200, 20, healthbar[5]);
	if (health == 5)
		iShowImage(110, 470, 200, 20, healthbar[4]);
	if (health == 4)
		iShowImage(110, 470, 200, 20, healthbar[3]);
	if (health == 3)
		iShowImage(110, 470, 200, 20, healthbar[2]);
	if (health == 2)
		iShowImage(110, 470, 200, 20, healthbar[1]);
	if (health == 1)
		iShowImage(110, 470, 200, 20, healthbar[0]);

	if (abishow == true)
	{
		iShowImage(780, 470, 30, 30, abi);
	}
}

void Bulletmovement()
{
	for (int i = 0; i<BulletNumber; i++)
	{
		if (Bullet[i].bShow == true)
		{
			iShowImage(Bullet[i].bX, Bullet[i].bY, Bullet[i].bdx, Bullet[i].bdy, guli);
		}
	}
}

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





void charmovement()
{
	
	if (front)
	{
		iShowImage(RunX, RunY, 80,110,runimage[RunIndex]);
	}
	else if (health < 1)
	{
		iShowImage(RunX, RunY, 80, 110, dieimage[dieIndex]);
		
	}
}

void backgroundmovement()
{
	for (int i = 0; i<13; i++)
	{
		iShowImage(upperbackground[i].x, upperbackground[i].y, 72, 522, upperbackgroundimage[i]);
	}
}

void scoreview()
{
	iSetColor(255, 0, 0);
	sprintf(skor, "%d", score);
	iText(50, 470, skor, GLUT_BITMAP_TIMES_ROMAN_24);
	
	iSetColor(0, 0, 0);
}

void finalscoreshow()
{
	iSetColor(255, 0, 0);

	iShowImage(0, 0, screenWidth, screenHeight, gamo);

	iText(260, 60, skor, GLUT_BITMAP_TIMES_ROMAN_24);
	iShowImage(37, 430, 130, 60, buttons3);

}

void rankScore(){

	FILE *a = fopen("x.txt", "w+");



	for (int i = 0; i<5; i++) {

		fscanf(a, "%d", &winner[i].score);

	}

	

	char z[1000];

	for (int i = 0; i<5; i++) {

		for (int j = i + 1; j < 5; j++)
		{

			if (winner[i].score < winner[j].score) {

				int temp = winner[i].score;

				winner[i].score = winner[j].score;

				winner[j].score = temp;

			}

		}

	}
	fclose(a);

	FILE *n = fopen("HighScore.txt", "w+");





	for (int i = 0; i < 5 - 1; i++) {


		fprintf(n, "%ld\n", winner[i].score);

	}

	fclose(n);

}

void read()
{
	//reading scores from the text file
	FILE *fp = fopen("score.txt", "r");
	for (int i = 0; i<5; i++)
	{

		fscanf(fp, "%d\n", &sc);

		winner[i].score = sc;
		////putiing score in structure type array
	}
	for (int i = 0; i<5; i++)
	{

		winner[i].score = score;
	}
	
	
	
	
int temp;

	//bubble sorting the score in higher order
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<5; j++)
		{
			if (winner[j].score <winner[j + 1].score)
			{
				temp = winner[j].score;
				winner[j].score = winner[j + 1].score;
				winner[j + 1].score = temp;
			}
		}
	}
	fclose(fp);
}


void showable()
{
	iSetColor(255, 0, 0);
	for (int i = 0; i < 5; i++)
	{
		sprintf(nameShow, "%d", winner[i].score);
		iText(500, 350, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	


	/*sprintf(nameShow, "%d", winner[1].score);
	iText(500, 310, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



	sprintf(nameShow, "%d", winner[2].score);
	iText(500, 270, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);


	sprintf(nameShow, "%d", winner[3].score);
	iText(500, 230, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);



	sprintf(nameShow, "%d", winner[4].score);
	iText(500, 190, nameShow, GLUT_BITMAP_TIMES_ROMAN_24);

	*/




}

void menuscreen()
{
	if (gameState == -1)
	{
		//homemenu
		iShowImage(0, 0, screenWidth, screenHeight, menus[0]);
		for (int i = 0; i <= 5; i++)
		{
			iShowImage(bCordinate[i].x, bCordinate[i].y, screenWidth / 3.36, screenHeight / 14, buttons1[i]);
		}

	}

	else if (gameState == 0)
	{//play

		gameon = true;


	}

	else if (gameState == 1)
	{//story
		iShowImage(0, 0, screenWidth, screenHeight, menus[2]);
		iShowImage(screenWidth / 22.6, screenHeight / 1.213, screenWidth / 3.36, screenHeight / 14, buttons3);
	}
	else if (gameState == 2)
	{
		//highscore
		iShowImage(0, 0, screenWidth, screenHeight, menus[3]);
		iShowImage(screenWidth / 22.6, screenHeight / 1.213, screenWidth / 3.36, screenHeight / 14, buttons3);
		showable();
		//rankScore();
	}
	else if (gameState == 3)
	{//ins
		iShowImage(0, 0, screenWidth, screenHeight, menus[4]);
		iShowImage(screenWidth / 22.6, screenHeight / 1.213, screenWidth / 3.36, screenHeight / 14, buttons3);
	}
	else if (gameState == 4)
	{//credits
		iShowImage(0, 0, screenWidth, screenHeight, menus[5]);
		iShowImage(screenWidth / 22.6, screenHeight / 1.213, screenWidth / 3.36, screenHeight / 14, buttons3);
	}
	else if (gameState == 5)
	{
		exit(0);
	}
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();



	menuscreen();
	if (gameState == 0)
	{
		backgroundmovement();
		HealthShow();
		charmovement();
		zom1run();
		zom2run();
		zom3run();
		Bulletmovement();
		scoreview();
		
		
	}

	if (gameState == 29)
	{
		
		
		finalscoreshow();
		read();
		

	}



}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iPassiveMouse(int mx, int my)
{
	//x=mx-150;
	//y=my-20;
}
void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	//x=mx-150;
	//y=my-20;
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i<6; i++)
		{
			if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + screenWidth / 3.36 && my >= bCordinate[i].y && my <= bCordinate[i].y + screenHeight / 14)
			{
				gameState = i;
				if (i == 0)
				{
					PlaySound("m4.wav", NULL, SND_ASYNC);
					//PlaySound("m3.wav", NULL, SND_ASYNC);
					health = 6;
					score = 0;
					ability = 0;
					scoreincrement = true;
					abishow = false;
					zombieFF = 0;
					
				}
				else
					PlaySound("m2.wav", NULL, SND_ASYNC);
			}
			if (gameState == 1 && mx >= screenWidth / 22.70 && mx <= screenWidth / 22.70 + screenWidth / 3.36  && my >= screenHeight / 1.213 && my <= screenHeight / 1.213 + screenHeight / 14)
			{
				gameState = -1;
				PlaySound("m2.wav", NULL, SND_ASYNC);
			}

			if (gameState == 2 && mx >= screenWidth / 22.70 && mx <= screenWidth / 22.70 + screenWidth / 3.36  && my >= screenHeight / 1.213 && my <= screenHeight / 1.213 + screenHeight / 14)
			{
				gameState = -1;
				PlaySound("m2.wav", NULL, SND_ASYNC);
			}
			if (gameState == 3 && mx >= screenWidth / 22.70 && mx <= screenWidth / 22.70 + screenWidth / 3.36  && my >= screenHeight / 1.213 && my <= screenHeight / 1.213 + screenHeight / 14)
			{
				gameState = -1;
				PlaySound("m2.wav", NULL, SND_ASYNC);
			}
			if (gameState == 4 && mx >= screenWidth / 22.70 && mx <= screenWidth / 22.70 + screenWidth / 3.36  && my >= screenHeight / 1.213 && my <= screenHeight / 1.213 + screenHeight / 14)
			{
				gameState = -1;
				PlaySound("m2.wav", NULL, SND_ASYNC);
			}
			if (gameState == 29 && mx >= screenWidth / 22.70 && mx <= screenWidth / 22.70 + screenWidth / 3.36  && my >= screenHeight / 1.213 && my <= screenHeight / 1.213 + screenHeight / 14)
			{
				gameState = -1;
				health = 300000;
				ability = 0;
				score = 0;
				PlaySound("m2.wav", NULL, SND_ASYNC);
			}
		}

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	
	if (key == ' ')
	{
		
		
		if (shootwait >= 10)
		{
			shootcount++;
			if (shootcount == 20)
			{
				shootcount = 0;
				iDelayMS(10);
				
			}

			shooting = true;
			
			shootwait = 0;
			Bullet[bulletIndex].bX = RunX + 60;
			Bullet[bulletIndex].bY = 107;
			bulletIndex++;

			if (bulletIndex >= BulletNumber)
				bulletIndex = 0;
		}
	}

	else if (key == 'h')
	{
		if (ability >= 40)
		{
			health = 6;
			abishow = false;
			ability = 0;
			//PlaySound("ability.wav", NULL, SND_ASYNC);
		}
	}

	else if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("m.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	/*if (key == GLUT_KEY_RIGHT)
	{
	x+=10;
	}
	if (key == GLUT_KEY_LEFT)
	*/

}


void SetAll()
{
	int sum = 0;
	for (int i = 0; i<13; i++)
	{
		upperbackground[i].y = 0;
		upperbackground[i].x = sum;
		sum += 70;
	}
}

void backgroundslices()
{
	upperbackgroundimage[0] = iLoadImage("bgs\\Background_01.png");
	upperbackgroundimage[1] = iLoadImage("bgs\\Background_02.png");
	upperbackgroundimage[2] = iLoadImage("bgs\\Background_03.png");
	upperbackgroundimage[3] = iLoadImage("bgs\\Background_04.png");
	upperbackgroundimage[4] = iLoadImage("bgs\\Background_05.png");
	upperbackgroundimage[5] = iLoadImage("bgs\\Background_06.png");
	upperbackgroundimage[6] = iLoadImage("bgs\\Background_07.png");
	upperbackgroundimage[7] = iLoadImage("bgs\\Background_08.png");
	upperbackgroundimage[8] = iLoadImage("bgs\\Background_09.png");
	upperbackgroundimage[9] = iLoadImage("bgs\\Background_10.png");
	upperbackgroundimage[10] = iLoadImage("bgs\\Background_11.png");
	upperbackgroundimage[11] = iLoadImage("bgs\\Background_12.png");
	upperbackgroundimage[12] = iLoadImage("bgs\\Background_13.png");

}

void RUN()
{
	runimage[0] = iLoadImage("CharRun\\CharRun_01.png");
	runimage[1] = iLoadImage("CharRun\\CharRun_02.png");
	runimage[2] = iLoadImage("CharRun\\CharRun_03.png");
	runimage[3] = iLoadImage("CharRun\\CharRun_04.png");
	runimage[4] = iLoadImage("CharRun\\CharRun_05.png");
	runimage[5] = iLoadImage("CharRun\\CharRun_06.png");
}
void DIE()
{
	dieimage[0] = iLoadImage("CharDie\\CharDie_01.png");
	dieimage[1] = iLoadImage("CharDie\\CharDie_02.png");
	dieimage[2] = iLoadImage("CharDie\\CharDie_03.png");
	dieimage[3] = iLoadImage("CharDie\\CharDie_04.png");
	dieimage[4] = iLoadImage("CharDie\\CharDie_05.png");
	dieimage[5] = iLoadImage("CharDie\\CharDie_06.png");
	dieimage[6] = iLoadImage("CharDie\\CharDie_07.png");
	dieimage[7] = iLoadImage("CharDie\\CharDie_08.png");
	dieimage[8] = iLoadImage("CharDie\\CharDie_09.png");
}



void STAND()
{
	standimage = iLoadImage("CharStand\\CharStand_01.png");
}

void GULI()
{
	guli = iLoadImage("CharShoot\\guli.png");
}

void SHOOT()
{
	shootimage[0] = iLoadImage("CharShoot\\CharShoot_01.png");
	shootimage[1] = iLoadImage("CharShoot\\CharShoot_02.png");
	shootimage[2] = iLoadImage("CharShoot\\CharShoot_03.png");
	shootimage[3] = iLoadImage("CharShoot\\CharShoot_04.png");
}

void Z1Run()
{
	z1run[0] = iLoadImage("Run Z1\\Run4.png");
	z1run[1] = iLoadImage("Run Z1\\Run5.png");
	z1run[2] = iLoadImage("Run Z1\\Run6.png");
	z1run[3] = iLoadImage("Run Z1\\Run7.png");
	z1run[4] = iLoadImage("Run Z1\\Run8.png");
	z1run[5] = iLoadImage("Run Z1\\Run9.png");
	z1run[6] = iLoadImage("Run Z1\\Run10.png");
}

void Z2Run()
{
	z2run[0] = iLoadImage("Run Z2\\Run4.png");
	z2run[1] = iLoadImage("Run Z2\\Run5.png");
	z2run[2] = iLoadImage("Run Z2\\Run6.png");
	z2run[3] = iLoadImage("Run Z2\\Run7.png");
	z2run[4] = iLoadImage("Run Z2\\Run8.png");
	z2run[5] = iLoadImage("Run Z2\\Run9.png");
	z2run[6] = iLoadImage("Run Z2\\Run10.png");
}

void Z3Run()
{
	z3run[0] = iLoadImage("Run Z3\\Run4.png");
	z3run[1] = iLoadImage("Run Z3\\Run5.png");
	z3run[2] = iLoadImage("Run Z3\\Run6.png");
	z3run[3] = iLoadImage("Run Z3\\Run7.png");
	z3run[4] = iLoadImage("Run Z3\\Run8.png");
	z3run[5] = iLoadImage("Run Z3\\Run9.png");
	z3run[6] = iLoadImage("Run Z3\\Run10.png");
}

void HEALTH()
{
	healthbar[0] = iLoadImage("health\\healthbar_01.png");
	healthbar[1] = iLoadImage("health\\healthbar_02.png");
	healthbar[2] = iLoadImage("health\\healthbar_03.png");
	healthbar[3] = iLoadImage("health\\healthbar_04.png");
	healthbar[4] = iLoadImage("health\\healthbar_05.png");
	healthbar[5] = iLoadImage("health\\healthbar_06.png");
	abi = iLoadImage("health\\regen.png");
	gamo = iLoadImage("menu2\\gameover.png");
}

void menubg()
{
	menus[0] = iLoadImage("mainMenu//menuBackground.png");
	menus[1] = iLoadImage("mainMenu//sPage.png");
	menus[2] = iLoadImage("mainMenu//storyPage.png");
	menus[3] = iLoadImage("mainMenu//scorePage.png");
	menus[4] = iLoadImage("mainMenu//ins.png");
	menus[5] = iLoadImage("mainMenu//credit.png");

	buttons1[0] = iLoadImage("buttons\\play.png");
	buttons1[1] = iLoadImage("buttons\\story.png");
	buttons1[2] = iLoadImage("buttons\\highScore.png");
	buttons1[3] = iLoadImage("buttons\\instruction.png");
	buttons1[4] = iLoadImage("buttons\\credit.png");
	buttons1[5] = iLoadImage("buttons\\ex.png");
	

	buttons3 = iLoadImage("buttons\\back.png");
}


void change()
{
	for (int i = 0; i<13; i++)
	{
		upperbackground[i].x -= upperbackgroundspeed;
		if (upperbackground[i].x <= -70)
			upperbackground[i].x = screenWidth;
	}
}

void zombie()
{
	
	for (int i = 0; i<Zombie1Number; i++)
	{

		Zr1[i].zrX -= 20;
		
		if (zombieFF >= 150)
		{
			Zr1[i].zrX -= 10;
		}
		if (Zr1[i].zrX <= 0)
			Zr1[i].zrX = screenWidth + rand() % 840;
		Zr1[i].zrIndex++;
		if (Zr1[i].zrIndex >= 7)
			Zr1[i].zrIndex = 0;

		if ((RunX + 60) > Zr1[i].zrX)
		{
			health--;
			
			Zr1[i].zrX = screenWidth + rand() % 840;
		}

	}

	

	for (int i = 0; i<Zombie2Number; i++)
	{

		Zr2[i].zrX -= 10;
		if (zombieFF >= 300)
		{
			Zr2[i].zrX -= 5;
		}
		if (Zr2[i].zrX <= 0)
			Zr2[i].zrX = screenWidth + rand() % 30;
		Zr2[i].zrIndex++;
		if (Zr2[i].zrIndex >= 7)
			Zr2[i].zrIndex = 0;

		if ((RunX + 60) > Zr2[i].zrX) 
		{
			health -= 2;
			Zr2[i].zrX = screenWidth + rand() % 30;
		}

	}

	for (int i = 0; i<Zombie3Number; i++)
	{

		Zr3[i].zrX -= 25;
		if (zombieFF >= 200)
		{
			Zr3[i].zrX -= 10;
		}
		if (Zr3[i].zrX <= 0)
			Zr3[i].zrX = screenWidth + (rand() % 30)*100;
		Zr3[i].zrIndex++;
		if (Zr3[i].zrIndex >= 7)
			Zr3[i].zrIndex = 0;

		if ((RunX + 60) > Zr3[i].zrX)
		{
			health -= 3;
			Zr3[i].zrX = screenWidth + (rand() % 30) * 100;
		}

	}

	if (health<1)
	{
		gameState = 29;
		scoreincrement = false;

	}

}

void gulikor()
{
	shootwait++;
	for (int i = 0; i<BulletNumber; i++)
	{
		Bullet[i].bX += 50;
	
		if (Bullet[i].bX >= screenWidth)
		{
			Bullet[i].bX = 10000;
			Bullet[i].bY = 10000;
		}

		for (int j = 0; j<Zombie1Number; j++)
		{
			if ((Bullet[i].bX + Bullet[i].bdx> Zr1[j].zrX && Bullet[i].bX < screenWidth))
			{
				Bullet[i].bX = 10000;
				Zr1[j].zrX = screenWidth + rand() % 840;
				if (scoreincrement)
					score += 1;
			}
		}

		for (int j = 0; j<Zombie2Number; j++)
		{
			if ((Bullet[i].bX + Bullet[i].bdx> Zr2[j].zrX && Bullet[i].bX < screenWidth))
			{
				Bullet[i].bX = 1000;
				Zr2[j].zrX = screenWidth + rand() % 840;
				if (scoreincrement)
					score += 3;
			}
		}

		for (int j = 0; j<Zombie3Number; j++)
		{
			if ((Bullet[i].bX + Bullet[i].bdx> Zr3[j].zrX && Bullet[i].bX < screenWidth))
			{
				Bullet[i].bX = 1000;
				Zr3[j].zrX = screenWidth + rand() % 840;
				if (scoreincrement)
					score += 5;
			}
		}
	}
}
//Strated here 

void zombieFaster()
{
	zombieFF++;
}


void setZombie()
{
	for (int i = 0; i < Zombie1Number; i++)
	{
		Zr1[i].zrX = screenWidth + rand() % 840;
		Zr1[i].zrY = 47;
		Zr1[i].zrIndex = 0;
		Zr1[i].zrShow = true;
	}

	for (int i = 0; i<Zombie2Number; i++)
	{
		Zr2[i].zrX = screenWidth + rand() % 840;
		Zr2[i].zrY = 47;
		Zr2[i].zrIndex = 0;
		Zr2[i].zrShow = true;
	}
	for (int i = 0; i<Zombie3Number; i++)
	{
		Zr3[i].zrX = screenWidth + rand() % 840;
		Zr3[i].zrY = 47;
		Zr3[i].zrIndex = 0;
		Zr3[i].zrShow = true;
	}
}

void setButton()
{
	int sum = 30;
	for (int i = 5; i >= 0; i--)
	{
		bCordinate[i].x = 20;
		bCordinate[i].y = sum;
		sum += 70;
	}
}

void ran()
{
	RunIndex++;
	if (RunIndex >= 6)
	RunIndex = 0;

	dieIndex++;
	if (dieIndex >= 9)
		dieIndex = 0;
	
	
}

/*int collision(int LeftX, int LeftWi, int RightX, int RightWi)
{
	if ((LeftX + LeftWi) > RightX  && LeftX < (RightX + RightWi))
		return 1;
	else
		return 0;

}*/

void healthregen()
{
	ability++;
	if (ability>40)
		abishow = true;
	if (scoreincrement)
		score++;

}

/*void overcheck()
{
if(health<=0)
{
iPauseTimer(here);
gameState = 29;
scoreincrement=false;
}
}*/


/*void collisionCheck(){

if((xchar + dxchar>xzom && xchar<xzom+dxzom)&&(ychar + dychar>yzom && ychar<yzom+dyzom))
{
printf("X");
}
}*/

// isettimer(20,collisioncheck);

int main()
{


	SetAll();
	setZombie();
	setButton();
	

	iSetTimer(40, change);
	iSetTimer(90, zombie);
	iSetTimer(900, healthregen);
	iSetTimer(90, ran);
	iSetTimer(60, gulikor);
	iSetTimer(150, zombieFaster);

	iInitialize(screenWidth, screenHeight, "Jombie Attack");
	backgroundslices();

	Z3Run();
	Z1Run();
	Z2Run();
	RUN();
	DIE();
	STAND();
	SHOOT();
	GULI();
	HEALTH();
	menubg();



	iStart();

	return 0;
}