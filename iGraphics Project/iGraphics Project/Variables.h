#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


#define SCREEN_WIDTH 1240
#define SCREEN_HEIGHT 720
#define UPPER_BACKGROUND_SPEED 5
#define JUMP_LIMIT 100
#define Zombie1Number 3
#define Zombie2Number 2
#define Zombie3Number 1
#define BULLET_NUMBER 100


int x = 0, y = 0, r = 255, g = 255, b = 255;
int speed;










/*Button cordinate*/
struct buttonCordinate
{
	int x;
	int y;
}bCordinate[6];
/* for background move*/
struct upperbackground
{
	int x;
	int y;

}ubackground[15];




/*menu page image*/
int menu[6];
/*buttons*/
int buttons[6];
int button2;
/*game state*/
int gameState = -1;
/*play*/
bool gameon = false;
/*moving background variable*/
int upperbackgroundimage[13];

/*For character*/
int standimage;
int charRunimage[6];
int charRunbackimage[6];

/*Run*/
int charCordinateX = 10;
int charCordinateY = 20;
int charRunIndex = 0;
int charRunBackIndex = 0;
bool standPosition = true;
int standcounter = 0;
bool front = true;
bool standing = false;

/*JUMP*/
int jumpimage;
bool jump = false;
bool jumpup = false;
int charCordinateJump = 0;





/*For zombie image*/
int z1run[7];
int z2run[7];
int z3run[7];
/*Zombie run*/
struct zombierun
{
	int zrX;
	int zrY;
	int zrIndex;
	int standCounter;
	bool zrShow;

};
zombierun Zr1[Zombie1Number];
zombierun Zr2[Zombie2Number];
zombierun Zr3[Zombie2Number];

/*bullet*/
struct bullet
{
	int bX;
	int bY;
	int bdx;
	int bdy;
	bool bShow;

	bullet()
	{
		bX = 10000;
		bY = 10000;
		bdx = 9;
		bdy = 3;
		bShow = true;

	}
};

bullet Bullet[BULLET_NUMBER];
int bImage;
int shootimage[4];
int bulletIndex = 0;


int shootcount = 0;
int shootwait = 20;

bool shooting = false;




/*other*/

int here;
int sc;
boolean musicOn = false;





int bcIndex = 0;
int health = 300006;
int ability = 0;
bool abishow = false;
int score = 0;

int finalscore;
char finalskor[10 + sizeof(char)];
char nameShow[10 + sizeof(char)];
char skor[10 + sizeof(char)];
bool scoreincrement = true;
int hsindex = 5;

struct Player {

	int score;
};

Player winner[10];





int guli;
int abi;
int gamo;

int healthbar[6];
int buttons1[6];
int buttons2[6];
int menus[6];
int buttons3;
int ShootIndex = 0;


//int standcount = 0;

bool stand = true, fw = true, bw = false, shootBullet = false, maincJump = false, maincUp = true, maincDown = false, dead = false;


#endif