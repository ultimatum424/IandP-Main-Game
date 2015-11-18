#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "View.h"
//#include "map.h" //подключили код с картой

using namespace sf;

typedef struct structImages
{
	Image image;
	String file;
	Texture texture;
	Sprite sprite;
	int pos_x;
	int pos_y;
};
typedef struct heroes
{
	Sprite sprite;
	Vector2f heroesPosition;
	int hp;
	float damage;
	float def;
	int position;
};
void moveWizard(struct heroes& wizard, float& time, float& CurrentFrame, int key)
{
	CurrentFrame += 0.0005*time;
	if (CurrentFrame > 5) { CurrentFrame -= 5; }
	wizard.sprite.setTextureRect(IntRect(40 *(int(CurrentFrame)), 118, 40, 80));
	if (key == -1) { (wizard.sprite.move(-0.05*time, 0)); }
	if (key == 1) { (wizard.sprite.move(0.05*time, 0)); }
	wizard.heroesPosition = wizard.sprite.getPosition();

	
}
void moveRogue(struct heroes& rogue, float& time, float& CurrentFrame, int key)
{
	CurrentFrame += 0.005*time;
	if (CurrentFrame > 10) { CurrentFrame -= 10; }
	rogue.sprite.setTextureRect(IntRect(0 + (90 * (int(CurrentFrame))), 155, 90, 85));
	if (key == -1) { rogue.sprite.move(-0.05*time, 0); }
	if (key == 1) { rogue.sprite.move(0.05*time, 0); }
	rogue.heroesPosition = rogue.sprite.getPosition();

}
void loadImage(struct structImages& s, String F)
{
	s.image.loadFromFile(F);
	s.texture.loadFromImage(s.image);
	s.sprite.setTexture(s.texture);
}
void loadSubject(struct subject& s)
{
	keytab[1].Name;
}
/*int move_templar(int status, int time, Sprite templar_sprite)
{
	int CurrentFrame;
	if (((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) && (status == 0))
	{
		CurrentFrame += 0.005*time;
		templar_sprite.move(-0.1*time, 0);
	}
}*/

void openChest(Sprite s, Sprite map)
{
	int i;
	Vector2f heroesPosition = s.getPosition();

	if (TileMap[int(heroesPosition.x / 248)] == 'c')
	{
		map.setTextureRect((IntRect(0, 0, 248, 208)));
		int i = (int(heroesPosition.x / 248));
		TileMap[i] = 'o';
		i = Chest[(int(heroesPosition.x / 248))];
		map.setPosition((i * 248), 0);
		std::cout << keytab[i].Name << "-" << keytab[i].Effect << "-" << "\n";
		//open(int(heroesPosition.x / 248));

	}
}



int main()
{
	setlocale(LC_CTYPE, "rus");
	const int window_x = 1000;
	const int window_y = 600;

	int i;

	struct structImages ghost_load;
	struct structImages templar;
	struct structImages map1;
	struct structImages wizard_load;
	struct structImages rogue_load;
	struct heroes wizard;
	struct heroes rogue;
	struct heroes ghost;
	struct subject sub;
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Game");
	view.setSize(sf::Vector2f(1000, 600)); 
	view.setCenter(window_x / 2, 300);
	
	

	//Ghost.createMaskFromColor(Color(0, 255, 0));
	Image skeleton;
	skeleton.loadFromFile("D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/CadashSheet3.png");
	skeleton.createMaskFromColor(Color(255, 0, 255));
	Texture skeleton_texture;
	skeleton_texture.loadFromImage(skeleton);
	Sprite skeleton_sprite;
	skeleton_sprite.setTexture(skeleton_texture);
	skeleton_sprite.setTextureRect(IntRect(161, 162, 52, 64));
	skeleton_sprite.setPosition(485, 85);

	
	// Загружаем призрака
	loadImage(ghost_load, "D:/Универ/ИИП и игра/примеры/PC Computer - Shovel Knight - The Big Creep.png");
	ghost.sprite = ghost_load.sprite;
	ghost.sprite.setTextureRect(IntRect(0, 155, 90, 85));
	ghost.sprite.setPosition(400, 85);
	// Загрузка карты
	loadImage(map1, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/fon/level2.png");
	// Загрузка волшебника
	loadImage(wizard_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/wizard/wizard.png");
	wizard.sprite = wizard_load.sprite;
	wizard.sprite.setTextureRect(IntRect(19, 6, 40, 80));
	wizard.sprite.setPosition(50, 85);
	// Загрузка вора
	loadImage(rogue_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/rogue/rogue.png");
	rogue.sprite = rogue_load.sprite;
	rogue.sprite.setTextureRect(IntRect(0, 155, 90, 85));
	rogue.sprite.setPosition(100, 85);
	// Загрузка рыцаря
	loadImage(templar, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/tamler/move_jump_dying_dead_100000901.png");
	templar.sprite.setTextureRect(IntRect(78, 0, -78, 72));
	templar.sprite.setPosition(50, 500);

	

	Vector2f f;
	float CurrentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{
		
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 1000; //скорость игры
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				openChest(wizard.sprite, map1.sprite);
				window.draw(map1.sprite);
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) & (wizard.heroesPosition.x >= 10))
		{
			CurrentFrame += 0.005*time;
			moveWizard(wizard, time, CurrentFrame, -1);
			moveRogue(rogue, time, CurrentFrame, -1);
			
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) & (wizard.heroesPosition.x <= (length_map * 208)))
		{
			CurrentFrame += 0.005*time;
			moveWizard(wizard, time, CurrentFrame, 1);
			moveRogue(rogue, time, CurrentFrame,  1);
		}
		

		/*if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			ghost.sprite.setTextureRect(IntRect(65+(65 * int(CurrentFrame)), 62, -65, 58));
			ghost.sprite.move(-0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			ghost.sprite.setTextureRect(IntRect(65+(65 * int(CurrentFrame)), 62, -65, 58));
			ghost.sprite.move(0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			skeleton_sprite.setTextureRect(IntRect(161+(52 * int(CurrentFrame)), 162, 52, 64));
			skeleton_sprite.move(-0.1, 0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			skeleton_sprite.setTextureRect(IntRect(161+(52 * int(CurrentFrame)), 162, 52, 64));
			skeleton_sprite.move(0.1, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::F))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 2) { CurrentFrame -= 2; }
			skeleton_sprite.setTextureRect(IntRect(155 + (78 * int(CurrentFrame)), 229, 78, 64));
		}*/
		
		window.clear(sf::Color::White);
		
	    window.setView(view);
		ViewMove(time, f);
		templar.sprite.setPosition(f.x - 250, f.y);
		//getPlayerCoordinateForView(wizard.heroesPosition.x, wizard.heroesPosition.y);
		//std::cout << wizard.heroesPosition.x << "-----" << wizard.heroesPosition.y << "\n";
		
		for (i = 0; i < length_map; i++)
		{
			if (TileMap[i] == '0') {
				map1.sprite.setTextureRect((IntRect(0, 0, 248, 208))); }
			if (TileMap[i] == 'c') {

				map1.sprite.setTextureRect((IntRect(248, 0, 248, 208))); }
			if (TileMap[i] == 'o') {

				map1.sprite.setTextureRect((IntRect(496, 0, 248, 208)));
			}
			if (TileMap[i] == 'e') {

				map1.sprite.setTextureRect((IntRect(744, 0, 248, 208)));
			}
			map1.sprite.setPosition(i * 248, 0);
			
			
			window.draw(map1.sprite);
		}
		
		//window.draw(templar.sprite);
		//window.draw(ghost.sprite);
		//window.draw(skeleton_sprite);
		//wizard.sprite.setScale(2.0f, 2.0f);
		window.draw(wizard.sprite);
		window.draw(rogue.sprite);
		window.display();
	}

	return 0;
}