//#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Struct.h"
#include "View.h"
//#include "map.h" //подключили код с картой

using namespace sf;
Vector2i inventory[quantity_subject];

void loadImage(struct structImages& s, String F)
{
	s.image.loadFromFile(F);
	s.texture.loadFromImage(s.image);
	s.sprite.setTexture(s.texture);
}
void InitHeroes(StructLoad& load, StructAllHeroes& all_heroes)
{
	// Загрузка ахимика
	loadImage(load.wizard_load, "../images/wizard/wizard.png");
	all_heroes.wizard.sprite = load.wizard_load.sprite;
	all_heroes.wizard.sprite.setTextureRect(IntRect(19, 6, 40, 80));
	all_heroes.wizard.sprite.setPosition(70, 85);
	all_heroes.wizard.icon = all_heroes.wizard.sprite;
	all_heroes.wizard.batle_sprite = all_heroes.wizard.sprite;
	all_heroes.wizard.icon.setTextureRect(IntRect(494, 747, 58, 64));
	all_heroes.wizard.batle_icon = all_heroes.wizard.sprite;
	all_heroes.wizard.batle_icon.setTextureRect(IntRect(494, 747, 58, 64));
	// Загрузка вора
	loadImage(load.rogue_load, "../images/rogue/rogue.png");
	all_heroes.rogue.sprite = load.rogue_load.sprite;
	all_heroes.rogue.sprite.setTextureRect(IntRect(0, 155, 58, 85));
	all_heroes.rogue.sprite.setPosition(120, 85);
	all_heroes.rogue.icon = all_heroes.rogue.sprite;
	all_heroes.rogue.batle_sprite = all_heroes.rogue.sprite;
	all_heroes.rogue.icon.setTextureRect(IntRect(617, 644, 58, 64));
	all_heroes.rogue.batle_icon = all_heroes.rogue.sprite;
	all_heroes.rogue.batle_icon.setTextureRect(IntRect(617, 644, 58, 64));
	// Загрузка рыцаря
	loadImage(load.cruasder_load, "../images/crusader/crusader.png");
	all_heroes.cruasder.sprite = load.cruasder_load.sprite;
	all_heroes.cruasder.sprite.setTextureRect(IntRect(12, 526, 80, 90));
	all_heroes.cruasder.sprite.setPosition(180, 85);
	all_heroes.cruasder.icon = all_heroes.cruasder.sprite;
	all_heroes.cruasder.batle_sprite = all_heroes.cruasder.sprite;
	all_heroes.cruasder.icon.setTextureRect(IntRect(883, 181, 58, 64));
	all_heroes.cruasder.batle_icon = all_heroes.cruasder.sprite;
	all_heroes.cruasder.batle_icon.setTextureRect(IntRect(883, 181, 58, 64));
	// Загрузка священика
	loadImage(load.mage_load, "../images/mage/Arch Mage.png");
	all_heroes.mage.sprite = load.mage_load.sprite;
	all_heroes.mage.sprite.setTextureRect(IntRect(0, 154, 72, 104));
	all_heroes.mage.sprite.setPosition(10, 80);
	all_heroes.mage.icon = all_heroes.mage.sprite;
	all_heroes.mage.batle_sprite = all_heroes.mage.sprite;
	all_heroes.mage.icon.setTextureRect(IntRect(890, 442, 58, 64));
	all_heroes.mage.batle_icon = all_heroes.mage.sprite;
	all_heroes.mage.batle_icon.setTextureRect(IntRect(890, 442, 58, 64));

	all_heroes.cruasder.hp = 37;
	all_heroes.cruasder.max_hp = 60;
	all_heroes.cruasder.damage = 1.65;
	all_heroes.cruasder.def = 1.13;

	all_heroes.rogue.hp = 25;
	all_heroes.rogue.max_hp = 25;
	all_heroes.rogue.damage = 2;
	all_heroes.rogue.def = 0.5;

	all_heroes.wizard.hp = 30;
	all_heroes.wizard.max_hp = 30;
	all_heroes.wizard.damage = 1.65;
	all_heroes.wizard.def = 1.13;

	all_heroes.mage.hp = 35;
	all_heroes.mage.max_hp = 35;
	all_heroes.mage.damage = 1.65;
	all_heroes.mage.def = 1.13;
}
void InitAnimation(StructAllHeroes& all_heroes)
{
	all_heroes.wizard.move.num_frame = 5;
	all_heroes.wizard.move.pos_x = 0;
	all_heroes.wizard.move.pos_y = 118;
	all_heroes.wizard.move.size_x = 40;
	all_heroes.wizard.move.size_y = 80;

	all_heroes.rogue.move.num_frame = 10;
	all_heroes.rogue.move.pos_x = 0;
	all_heroes.rogue.move.pos_y = 155;
	all_heroes.rogue.move.size_x = 58;
	all_heroes.rogue.move.size_y = 85;

	all_heroes.cruasder.move.num_frame = 6;
	all_heroes.cruasder.move.pos_x = 12;
	all_heroes.cruasder.move.pos_y = 526;
	all_heroes.cruasder.move.size_x = 80;
	all_heroes.cruasder.move.size_y = 90;

	all_heroes.mage.move.num_frame = 9;
	all_heroes.mage.move.pos_x = 0;
	all_heroes.mage.move.pos_y = 154;
	all_heroes.mage.move.size_x = 72;
	all_heroes.mage.move.size_y = 104;
}
void InintExplonationImage(StructLoad& load, StructExplonationImage& explonation_image)
{
	// Загрузка карты
	loadImage(load.map1, "../images/fon/level2.png");
	explonation_image.map = load.map1.sprite;
	//Загрузка фона
	loadImage(load.background, "../images/Инвентарь/фон инвентаря.png");
	explonation_image.background = load.background.sprite;
	explonation_image.background.setPosition(0, 250);
	loadImage(load.background2, "../images/Инвентарь/back.png");
	explonation_image.background2 = load.background2.sprite;
	explonation_image.background2.setPosition(0, 208);
}
void InintBattleImage(StructBattleImage& battle_image)
{

}
void MoveHeroes(Structheroes& hero, float& time, float& CurrentFrame, int key)
{
	std::cout << CurrentFrame << "\n";
	CurrentFrame += 0.0005*time;
	if (CurrentFrame > hero.move.num_frame)  CurrentFrame -= hero.move.num_frame; 
	hero.sprite.setTextureRect(IntRect(hero.move.pos_x + (hero.move.size_x * (int(CurrentFrame))), hero.move.pos_y, hero.move.size_x, hero.move.size_y));
	if (key == -1)  (hero.sprite.move(-0.05*time, 0)); 
	if (key == 1)  (hero.sprite.move(0.05*time, 0)); 
	hero.heroesPosition = hero.sprite.getPosition();
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

	if ((TileMap[int(heroesPosition.x / 248)] == 'c') || (TileMap[int(heroesPosition.x / 248 + 100)] == 'c') || (TileMap[int(heroesPosition.x / 248 - 50)] == 'c'))
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
void HpInfo(struct Structheroes& hero, Vector2f f, int num, RenderWindow& window)
{
	Font font;
	font.loadFromFile("D:/Универ/ИИП и игра/Besgt Gama Ever MB/Breitkpf.pfb");
	Text Hp("", font, 25);
	Hp.setColor(Color::White);
	std::ostringstream player_max_HP;
	std::ostringstream playerHP;
	std::ostringstream player_damage;
	std::ostringstream player_armor;
	player_damage << hero.damage;
	player_armor << hero.def;
	player_max_HP << hero.max_hp;
	playerHP << hero.hp;
	Hp.setString("HP: " + playerHP.str() + "/ " + player_max_HP.str() + "	" + "% damage: " + player_damage.str() + "	" + "% armor: " + player_armor.str());
	Hp.setPosition(f.x + 100, f.y - 50 + (num * 70));
	//hero.icon.setTextureRect(IntRect(494, 747, 58, 64));
	hero.icon.setPosition(f.x + 40, f.y - 50 + (num * 70));
	window.draw(hero.icon);
	window.draw(Hp);
	

}
void DrawMap(RenderWindow& window, Sprite& map)  // отрисовка карты
{
	int i;
	for (i = 0; i < length_map; i++)
	{
		if (TileMap[i] == '0') {
			map.setTextureRect((IntRect(0, 0, 248, 208)));
		}
		if (TileMap[i] == 'c') {

			map.setTextureRect((IntRect(248, 0, 248, 208)));
		}
		if (TileMap[i] == 'o') {

			map.setTextureRect((IntRect(496, 0, 248, 208)));
		}
		if (TileMap[i] == 'e') {

			map.setTextureRect((IntRect(744, 0, 248, 208)));
		}
		map.setPosition(i * 248, 0);
		window.draw(map);
	}
}
void DrawInventory(structImages& items, Vector2f f, RenderWindow& window)
{
	int k = 0;
	for (int i = 0; i < quantity_subject; i++) // отрисовка инвентаря
	{
		//std::cout << "-----" << inventory[i].x << "\n";
		if (inventory[i].x != 0)
		{
			k++;
			//int j = inventory[i];
			items.sprite.setTextureRect((IntRect((inventory[i].x - 1) * 50, 0, 50, 50)));
			items.sprite.setPosition(((f.x - 500) + (k * 50)), f.y - 40);

			window.draw(items.sprite);
		}
	}
}
void ExplorationMod(RenderWindow& window, StructAllHeroes& all_heroes, float& time, float& CurrentFrame, Vector2f& f)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			openChest(all_heroes.rogue.sprite, explonation_image.map, items.sprite, inventory);
			window.draw(explonation_image.map);
		}
		if (Keyboard::isKeyPressed(Keyboard::Q)) { window.clear(); system("pause"); }

		if (event.type == sf::Event::Closed)
			window.close();
	}


	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) & (all_heroes.mage.heroesPosition.x >= 10))
	{
		CurrentFrame += 0.005*time;
		MoveHeroes(all_heroes.wizard, time, CurrentFrame, -1);
		MoveHeroes(all_heroes.rogue, time, CurrentFrame, -1);
		MoveHeroes(all_heroes.cruasder, time, CurrentFrame, -1);
		MoveHeroes(all_heroes.mage, time, CurrentFrame, -1);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) & (all_heroes.cruasder.heroesPosition.x <= (length_map * 228)))
	{
		CurrentFrame += 0.005*time;
		MoveHeroes(all_heroes.wizard, time, CurrentFrame, 1);
		MoveHeroes(all_heroes.rogue, time, CurrentFrame, 1);
		MoveHeroes(all_heroes.cruasder, time, CurrentFrame, 1);
		MoveHeroes(all_heroes.mage, time, CurrentFrame, 1);
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



	window.setView(view);
	ViewMove(time, f);
	explonation_image.background.setPosition(f.x - 500, f.y - 92);
	explonation_image.background2.setPosition(f.x - 500, f.y - 95);
	templar.sprite.setPosition(f.x - 250, f.y);
	window.draw(explonation_image.background2);
	window.draw(explonation_image.background);


	//getPlayerCoordinateForView(wizard.heroesPosition.x, wizard.heroesPosition.y);
	//std::cout << wizard.heroesPosition.x << "-----" << wizard.heroesPosition.y << "\n";

	DrawMap(window, explonation_image.map);
	DrawInventory(items, f, window);
	HpInfo(all_heroes.cruasder, f, 1, window);
	HpInfo(all_heroes.rogue, f, 2, window);
	HpInfo(all_heroes.wizard, f, 3, window);
	HpInfo(all_heroes.mage, f, 4, window);

	//window.draw(templar.sprite);
	//window.draw(ghost.sprite);
	//window.draw(skeleton_sprite);
	//wizard.sprite.setScale(2.0f, 2.0f);
	window.draw(all_heroes.wizard.sprite);
	window.draw(all_heroes.rogue.sprite);
	window.draw(all_heroes.cruasder.sprite);
	window.draw(all_heroes.mage.sprite);
	//window.draw(items.sprite);
}
void BattleMod(RenderWindow& window, StructAllHeroes& all_heroes, float& time, float& CurrentFrame, Vector2f& f)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	const int window_x = 1000;
	const int window_y = 600;

	int i;
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
	
	//Загрузка инвентаря
	loadImage(items, "../images/Инвентарь/Предеметы.png");
	InitHeroes(load, all_heroes);
	InitAnimation(all_heroes);
	InintExplonationImage(load, explonation_image);
	Vector2f f;
	float CurrentFrame = 0;
	Clock clock;
	int stage_game = 0;
	stage_game = 1;
	for (int i = 0; i < quantity_subject; i++)
	{
		inventory[i].x = 0;
		inventory[i].y = 0;
	}
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 1000; //скорость игры
		sf::Event event;
		if (stage_game == 1) ExplorationMod(window, all_heroes, time, CurrentFrame, f);
		if (stage_game == 2) BattleMod(window, all_heroes, time, CurrentFrame, f);
		//sf::Event event;
		
		window.display();
	}

	return 0;
}
