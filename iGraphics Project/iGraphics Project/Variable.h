

#define screenHeight 522
#define screenWidth 840
#define upperbackgroundspeed 5
#define Zombie1Number 3
#define Zombie2Number 2
#define Zombie3Number 1
#define BulletNumber 100








int r = 255, g = 255, b = 255;
int x = 0, y = 0;

int here;
int sc;
bool musicOn = false;
bool gameon = false;
int shootwait = 30;
int bulletIndex = 0;
int bcIndex = 0;
int health = 100;
int ability = 0;
bool abishow = false;
int score = 0;
//int menu = 0;
int finalscore;
char finalskor[10 + sizeof(char)];
char nameShow[10 + sizeof(char)];
char skor[10 + sizeof(char)];
bool scoreincrement = true;
//int hsindex = 5;
int gameState = -1;
//int wIndex = 5;

double zombieFF = 0;
struct buttonCordinate
{
	int x;
	int y;
};

struct Player {

	int score;
};

Player winner[10];


buttonCordinate bCordinate[6];
//buttonCordinate cCordinate;

int upperbackgroundimage[13];
int runimage[6];

int shootimage[4];
int dieimage[9];

int standimage;
int guli;
int abi;
int gamo;
int z1run[7];
int z2run[7];
int z3run[7];
int healthbar[6];
int buttons1[6];
int buttons2[6];
int menus[6];
int buttons3;


bool front = true;
bool shooting = false;

int shootcount = 0;

struct background
{
	int x;
	int y;

};

struct zombierun
{
	int zrX;
	int zrY;
	int zrIndex;
	bool zrShow;

};

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
		bdx = 11;
		bdy = 3;
		bShow = true;

	}
};

bullet Bullet[BulletNumber];


zombierun Zr1[Zombie1Number];
zombierun Zr2[Zombie2Number];
zombierun Zr3[Zombie3Number];

background upperbackground[13];

int RunX = 70;
int RunY = 38;
int RunIndex = 0;
int ShootIndex = 0;
int dieIndex = 0;