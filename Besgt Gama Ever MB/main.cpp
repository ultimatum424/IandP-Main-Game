#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "View.h"
//#include "map.h" //подключили код с картой

using namespace sf;
Vector2i inventory[quantity_subject];
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
	int max_hp;
	float damage;
	float def;
	int position;
	Sprite icon;
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
	CurrentFrame += 0.0015*time;
	if (CurrentFrame > 10) { CurrentFrame -= 10; }
	rogue.sprite.setTextureRect(IntRect(0 + (90 * (int(CurrentFrame))), 155, 90, 85));
	if (key == -1) { rogue.sprite.move(-0.05*time, 0); }
	if (key == 1) { rogue.sprite.move(0.05*time, 0); }
	rogue.heroesPosition = rogue.sprite.getPosition();

}
void moveCrusader(struct heroes& crusader, float& time, float& CurrentFrame, int key)
{
	CurrentFrame += 0.0015*time;
	if (CurrentFrame > 6) { CurrentFrame -= 6; }
	crusader.sprite.setTextureRect(IntRect(12 + (80 * (int(CurrentFrame))), 526, 80, 90));
	if (key == -1) { crusader.sprite.move(-0.05*time, 0); }
	if (key == 1) { crusader.sprite.move(0.05*time, 0); }
	crusader.heroesPosition = crusader.sprite.getPosition();
}
void moveMage(struct heroes& mage, float& time, float& CurrentFrame, int key)
{
	CurrentFrame += 0.0015*time;
	if (CurrentFrame > 9) { CurrentFrame -= 9; }
	mage.sprite.setTextureRect(IntRect(0 + (72 * (int(CurrentFrame))), 154, 72, 104));
	if (key == -1) { mage.sprite.move(-0.05*time, 0); }
	if (key == 1) { mage.sprite.move(0.05*time, 0); }
	mage.heroesPosition = mage.sprite.getPosition();
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

void openChest(Sprite s, Sprite map, Sprite& items, Vector2i inventory[quantity_subject])
{
	int i;
	Vector2f heroesPosition = s.getPosition();

	if (TileMap[int(heroesPosition.x / 248)] == 'c')
	{
		map.setTextureRect((IntRect(0, 0, 248, 208)));
		int pos = (int(heroesPosition.x / 248));
		TileMap[pos] = 'o';
		int i = Chest[pos].key;
		//map.setPosition((i * 248), 0);
		std::cout << keytab[i].Name << "-" << keytab[i].Effect << "-" << "\n";
		if (i != 0) 
		{ 
			int k = 0;
			bool p = 0;
			while ((p == 0) && (k < quantity_subject))
			{
				//std::cout << inventory[k].x << "\n";
				if (inventory[k].x == i) { inventory[k].y = inventory[k].y + Chest[i].quantity; p = 1; }
				if ((inventory[k].x == 0)) { inventory[k].x = i; inventory[k].y = Chest[i].quantity; p = 1;  }
				std::cout << inventory[k].x << "--" << inventory[k].y << "--" << p << "\n";
				k++;
				
			}
		}
		
		//open(int(heroesPosition.x / 248));

	}
}

void HpInfo(struct heroes& hero, Vector2f f, int num, RenderWindow& window)
{
	Font font;
	font.loadFromFile("D:/Универ/ИИП и игра/Besgt Gama Ever MB/Breitkpf.pfb");
	Text Hp("", font, 25);
	Hp.setColor(Color::Red);
	hero.hp = 17;
	hero.max_hp = 20;
	hero.damage = 0.75;
	hero.def = 1.13;
	std::ostringstream player_max_HP;
	std::ostringstream playerHP;
	std::ostringstream player_damage;
	std::ostringstream player_armor;
	player_damage << hero.damage;
	player_armor << hero.def;
	player_max_HP << hero.hp;
	playerHP << hero.hp;
	Hp.setString("HP: " + player_max_HP.str() + "/ " + playerHP.str() + "	" + "% damage: " + player_damage.str() + "	" + "% armor: " + player_armor.str());
	Hp.setPosition(f.x + 100, f.y - 50 + (num * 50));
	//hero.icon.setTextureRect(IntRect(494, 747, 58, 64));
	hero.icon.setPosition(f.x + 100, f.y - 50 + (num * 50));
	window.draw(hero.icon);
	window.draw(Hp);
	

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
	struct structImages items;
	struct structImages background;
	struct structImages background2;
	struct structImages cruasder_load;
	struct structImages mage_load;

	struct heroes wizard;
	struct heroes rogue;
	struct heroes ghost;
	struct subject sub;
	struct heroes cruasder;
	struct heroes mage;


	
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
	//Загрузка фона
	loadImage(background, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/Инвентарь/фон инвентаря.png");
	background.sprite.setPosition(0, 250);
	loadImage(background2, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/Инвентарь/back.png");
	background2.sprite.setPosition(0, 208);
	//Загрузка инвентаря
	loadImage(items, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/Инвентарь/Предеметы.png");
	// Загрузка волшебника
	loadImage(wizard_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/wizard/wizard.png");
	wizard.sprite = wizard_load.sprite;
	wizard.sprite.setTextureRect(IntRect(19, 6, 40, 80));
	wizard.sprite.setPosition(70, 85);
	wizard.icon = mage_load.sprite;
	wizard.icon.setTextureRect(IntRect(494, 747, 58, 64));
	// Загрузка вора
	loadImage(rogue_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/rogue/rogue.png");
	rogue.sprite = rogue_load.sprite;
	rogue.sprite.setTextureRect(IntRect(0, 155, 90, 85));
	rogue.sprite.setPosition(120, 85);
	rogue.icon = mage_load.sprite;
	rogue.icon.setTextureRect(IntRect(617, 644, 58, 64));
	// Загрузка рыцаря
	loadImage(cruasder_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/crusader/crusader.png");
	cruasder.sprite = cruasder_load.sprite;
	cruasder.sprite.setTextureRect(IntRect(12, 526, 80, 90));
	cruasder.sprite.setPosition(180, 85);
	cruasder.icon = mage_load.sprite;
	cruasder.icon.setTextureRect(IntRect(883, 181, 58, 64));
	// Загрузка священика
	loadImage(mage_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/mage/Arch Mage.png");
	mage.sprite = mage_load.sprite;
	mage.sprite.setTextureRect(IntRect(0, 154, 72, 104));
	mage.sprite.setPosition(10, 80);
	mage.icon = mage_load.sprite;
	mage.icon.setTextureRect(IntRect(890, 442, 58, 64));


	

	

	Vector2f f;
	float CurrentFrame = 0;
	Clock clock;
	for (int i = 0; i < quantity_subject; i++)
	{
		inventory[i].x = 0;
		inventory[i].y = 0;
	}
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
				openChest(rogue.sprite, map1.sprite, items.sprite, inventory);
				window.draw(map1.sprite);
			}
			if (Keyboard::isKeyPressed(Keyboard::Q)){ system("pause"); }
			
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) & (wizard.heroesPosition.x >= 10))
		{
			CurrentFrame += 0.005*time;
			moveWizard(wizard, time, CurrentFrame, -1);
			moveRogue(rogue, time, CurrentFrame, -1);
			moveCrusader(cruasder, time, CurrentFrame, -1);
			moveMage(mage, time, CurrentFrame, -1);
			
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) & (wizard.heroesPosition.x <= (length_map * 208)))
		{
			CurrentFrame += 0.005*time;
			moveWizard(wizard, time, CurrentFrame, 1);
			moveRogue(rogue, time, CurrentFrame,  1);
			moveCrusader(cruasder, time, CurrentFrame, 1);
			moveMage(mage, time, CurrentFrame, 1);
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
		background2.sprite.setPosition(f.x - 500, f.y - 92);
		background.sprite.setPosition(f.x - 500, f.y - 50);
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
		int k = 0;
		for (int i = 0; i < quantity_subject; i++)
		{
			//std::cout << "-----" << inventory[i].x << "\n";
			if (inventory[i].x != 0)
			{
				k++;
				//int j = inventory[i];
				items.sprite.setTextureRect((IntRect((inventory[i].x - 1)* 50, 0, 50, 50)));
				items.sprite.setPosition(((f.x - 450) + (k * 50)), f.y - 45);
				window.draw(items.sprite);
			}
		}
		HpInfo(wizard, f, 1, window);
		HpInfo(rogue, f, 2, window);
		window.draw(wizard.icon);
		//window.draw(background2.sprite);
		//window.draw(background.sprite);
		//window.draw(templar.sprite);
		//window.draw(ghost.sprite);
		//window.draw(skeleton_sprite);
		//wizard.sprite.setScale(2.0f, 2.0f);
		window.draw(wizard.sprite);
		window.draw(rogue.sprite);
		window.draw(cruasder.sprite);
		window.draw(mage.sprite);
		//window.draw(items.sprite);
		window.display();
	}

	return 0;
}