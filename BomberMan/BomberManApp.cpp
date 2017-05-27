// Includes
#include "BomberManApp.h"

#include "Common.h"
#define BLOCO 1
#define PLAYER 181
#define ZUMBI 3
#define BOMBA 180
#define EXP 10
#define SOM 200

// Namespace
using namespace AGK;

int sprite = 2, state = 0, tecla, id;
float widthBomba = 30, x = 50, y = 100;
bool bomba = false;


// important !!!
CBomberManApp	BomberMan;

// constructor
CBomberManApp::CBomberManApp()
{ 
	// need to connect with windows programm
	ConnectApplication(this);

	// setup device features
	SetupDevice(DEVICE_WIDTH, DEVICE_HEIGHT, FULLSCREEN);

	// setup window name/title
	SetupTitle(TITLE);
}

void criarSprite(int num, float x, float y) {
	agk::CreateSprite(num, BLOCO);
	agk::SetSpriteSize(num, 50, 50);
	agk::SetSpritePosition(num, x, y);
}

void setexplosaoanimation(){
	agk::SetSpritePosition(EXP, agk::GetSpriteX(BOMBA), agk::GetSpriteY(BOMBA));
	agk::SetSpriteAnimation(EXP, 177, 160, 5);
	agk::PlaySprite(EXP, 100);
}

void setzumbianimation(float x, float y)
{
	agk::CreateSprite(sprite, ZUMBI);
	//agk::SetSpriteImage(sprite, ZUMBI);
	agk::SetSpriteSize(sprite, 40, 40);
	agk::SetSpriteAnimation(sprite, 130, 178, 4);
	agk::PlaySprite(sprite, 10);
	agk::SetSpritePosition(sprite, x, y);
	sprite++;
}

int chekarVisible() {
	int num = 8;
	for (int i = 2; i < 10; i++) {
		if (agk::GetSpriteVisible(i) == 0) {
			num--;
		}
	}
	return num;
}

void move(float horizontal, float vertical) {
	//x = x + horizontal;
	//y = y + vertical;

	float a = agk::GetSpriteX(PLAYER), b = agk::GetSpriteY(PLAYER);

	if ((a + horizontal >= 50) && (b + vertical >= 50) && (a + horizontal <= 750) && (b + vertical <= 550)) { // posição minima do sprite no jogo
		//if (!agk::GetSpriteVisible(agk::GetSpriteHit(x + horizontal, y + vertical))) { // se na próxima posição tem algum sprite visivel
			x = x + horizontal;
			y = y + vertical;
		//}
	}

	/*
	for (int i = 11; i < 175; i++) {
		if (agk::GetSpriteVisible(i)) {
			if (agk::GetSpriteCollision(PLAYER, i)) {
				x = x - horizontal;
				y = y - vertical;
			}
		}
	}
	*/
	agk::SetSpritePosition(PLAYER, x, y);
}

/*
void setplayeranimation()
{
	agk::CreateSprite(PLAYER, 2);
	agk::SetSpriteSize(PLAYER, 100, 100);
	agk::SetSpriteAnimation(PLAYER, 115, 158, 8);
	agk::PlaySprite(PLAYER, 100);
	agk::SetSpritePosition(PLAYER, 50, 80);
}*/

void CBomberManApp::Begin(void)
{
	//	setup agk-application
	agk::SetVirtualResolution(DEVICE_WIDTH, DEVICE_HEIGHT);
	agk::SetClearColor(48, 48, 48);
	agk::SetSyncRate(60, 0);
	agk::SetScissor(0, 0, 0, 0);
	agk::SetPrintColor(0, 0, 0);

	agk::LoadImage(BLOCO, "images/bloco.png");
	agk::LoadImage(PLAYER, "images/player2.png");
	agk::LoadImage(ZUMBI, "images/mw9.png");
	agk::LoadImage(BOMBA, "images/bomba.png");
	agk::LoadImage(EXP, "images/explosao.png");
	agk::LoadSound(SOM, "sound/explosao.mp3");

	agk::CreateSprite(PLAYER, PLAYER);
	agk::SetSpriteSize(PLAYER, 40, 50);
	agk::SetSpritePosition(PLAYER, x, y);

	agk::CreateSprite(BOMBA, BOMBA);
	agk::SetSpriteSize(BOMBA, widthBomba, widthBomba);
	agk::SetSpriteVisible(BOMBA, 0);
	
	agk::CreateSprite(EXP, EXP);
	agk::SetSpriteSize(EXP, 100, 100);
	agk::SetSpriteVisible(EXP, 0);

	//setplayeranimation();
	//srand((unsigned int)time(nullptr));
	
	float j = 50, k = 50;
	/* Sprites dos blocos */
	for (int i = 11; i < 175; i++, j += 50) {
		
		if (i == 26 || i == 41 || i == 56 || i == 71 || i == 86 || i == 101 || i == 116 || i == 131 || i == 146 || i == 161) {
			j = 50;
			k += 50;
		}
		if (i != 3 && i != 31 && i != 41 && i != 51 && i != 87 && i != 95 && i != 121 && i != 128 && i != 147 && i != 156) {
			criarSprite(i, j, k);
		}
		
	}
	/*
	agk::SetSpriteVisible(31, 0);
	agk::SetSpriteVisible(51, 0);
	agk::SetSpriteVisible(87, 0);
	agk::SetSpriteVisible(95, 0);
	agk::SetSpriteVisible(121, 0);
	agk::SetSpriteVisible(128, 0);
	agk::SetSpriteVisible(147, 0);
	agk::SetSpriteVisible(156, 0);
	*/
	// espaços vagos
	agk::SetSpriteVisible(26, 0);
	agk::SetSpriteVisible(27, 0);
	agk::SetSpriteVisible(30, 0);
	agk::SetSpriteVisible(38, 0);
	agk::SetSpriteVisible(39, 0);
	agk::SetSpriteVisible(47, 0);
	agk::SetSpriteVisible(48, 0);
	agk::SetSpriteVisible(59, 0);
	agk::SetSpriteVisible(60, 0);
	agk::SetSpriteVisible(76, 0);
	agk::SetSpriteVisible(79, 0);
	agk::SetSpriteVisible(83, 0);
	agk::SetSpriteVisible(84, 0);
	agk::SetSpriteVisible(98, 0);
	agk::SetSpriteVisible(99, 0);
	agk::SetSpriteVisible(91, 0);
	agk::SetSpriteVisible(92, 0);
	agk::SetSpriteVisible(89, 0);
	agk::SetSpriteVisible(104, 0);
	agk::SetSpriteVisible(117, 0);
	agk::SetSpriteVisible(123, 0);
	agk::SetSpriteVisible(134, 0);
	agk::SetSpriteVisible(138, 0);
	agk::SetSpriteVisible(139, 0);
	agk::SetSpriteVisible(150, 0);
	agk::SetSpriteVisible(154, 0);

	/* Animação e posição dos zumbis */
	setzumbianimation(300, 400);
	setzumbianimation(550, 500);
	setzumbianimation(550, 150);
	setzumbianimation(650, 400);
	setzumbianimation(100, 500);
	setzumbianimation(500, 300);
	setzumbianimation(100, 300);
	setzumbianimation(300, 100);

	agk::SetPhysicsDebugOn();
}

void CBomberManApp::Loop(void){ 
	agk::SetPhysicsDebugOn();
	if (state == 0) {
		float x, y;

		// teclas de movimentação
		if (agk::GetRawKeyState(37)) {
			move(-5, 0);
		}
		else {
			if (agk::GetRawKeyState(38)) {
				move(0, -5);
			}
			else {
				if (agk::GetRawKeyState(39)) {
					move(5, 0);
				}
				else {
					if (agk::GetRawKeyState(40)) {
						move(0, 5);
					}
				}
			}
		}

		tecla = agk::GetRawLastKey();

		if (agk::GetRawKeyState(32)) {
			x = agk::GetSpriteX(PLAYER);
			y = agk::GetSpriteY(PLAYER);
			agk::SetSpriteVisible(BOMBA, 1);
			agk::SetSpritePosition(BOMBA, x, y);
			agk::PlaySound(SOM, 100, 2); // dar play no efeito da bomba
			bomba = true;
		}
		agk::Print(tecla);

		if (bomba) {
			widthBomba += 0.2;
			agk::SetSpriteSize(BOMBA, widthBomba, widthBomba);
			if (widthBomba > 45) {
				agk::StopSound(SOM); // parar o som
				widthBomba = 30;
				bomba = false;
				// explosao dos blocos
				for (int i = 0; i < 2; i++) {
					agk::SetSpriteVisible(agk::GetSpriteHit(agk::GetSpriteX(BOMBA), agk::GetSpriteY(BOMBA)), 0);
					agk::SetSpriteVisible(agk::GetSpriteHit(agk::GetSpriteX(BOMBA) + 50, agk::GetSpriteY(BOMBA)), 0);
					agk::SetSpriteVisible(agk::GetSpriteHit(agk::GetSpriteX(BOMBA), agk::GetSpriteY(BOMBA) + 50), 0);
					agk::SetSpriteVisible(agk::GetSpriteHit(agk::GetSpriteX(BOMBA) - 50, agk::GetSpriteY(BOMBA)), 0);
					agk::SetSpriteVisible(agk::GetSpriteHit(agk::GetSpriteX(BOMBA), agk::GetSpriteY(BOMBA) - 50), 0);
					agk::Sync(); // atualiza a tela
				}
				agk::Sleep(100); // espera de 0.1 seg
				agk::SetSpritePosition(EXP, agk::GetSpriteX(BOMBA) - 20, agk::GetSpriteY(BOMBA) - 20); // posição da explosão na bomba 
				agk::SetSpriteVisible(EXP, 1); // mostra a explosão
				agk::Sync(); // atualiza a tela
				agk::Sleep(100); // espera de 0.1 seg
				agk::SetSpriteVisible(BOMBA, 0); // fazer bomba sumir
				agk::SetSpriteVisible(EXP, 0);
			}
		}
		agk::Print(chekarVisible());

		if (chekarVisible() < 1) {
			state = 2;
		}
		
		if (!agk::GetSpriteVisible(PLAYER)) {
			state = 1;
		}

	}
	else {
		if (state == 1) {
			agk::Print("Perdeu"); // game over
		}
		else {
			agk::Print("Vitória");  // venceu
		}
	}

	// update the screen
	agk::Sync();
}


void CBomberManApp::End(void)
{
}
