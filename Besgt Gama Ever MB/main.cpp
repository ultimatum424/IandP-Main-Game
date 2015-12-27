//#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Struct.h"
#include "View.h"
//#include "batt.h"
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
	loadImage(load.load_image_ability_wizard, "../images/wizard/icon_wizard.png");
	all_heroes.wizard.image_ability = load.load_image_ability_wizard.sprite;
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
	loadImage(load.load_image_ability_rogue, "../images/rogue/icon_rogue.png");
	all_heroes.rogue.image_ability = load.load_image_ability_rogue.sprite;
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
	loadImage(load.load_image_ability_cruasder, "../images/crusader/icon_crusader.png");
	all_heroes.cruasder.image_ability = load.load_image_ability_cruasder.sprite;
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
	loadImage(load.load_image_ability_mage, "../images/mage/icon_mage.png");
	all_heroes.mage.image_ability = load.load_image_ability_mage.sprite;

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
void InitEnemy(StructLoad& load, StructAllEnemy& all_enemy)
{
	// Загружаем призрака
	loadImage(load.load_ghost, "../images/enemy/PC Computer - Shovel Knight - The Big Creep.png");
	all_enemy.ghost.sprite = load.load_ghost.sprite;
	all_enemy.ghost.sprite.setTextureRect(IntRect(332, 2, 64, 58));
	all_enemy.ghost.hp = 30;
	//enemy.ghost.sprite.setPosition(400, 85);

	loadImage(load.load_skeleton, "../images/enemy/CadashSheet3.png");
	//skeleton.createMaskFromColor(Color(255, 0, 255));
	all_enemy.skeleton.sprite.setTextureRect(IntRect(164, 163, 43, 63));
	all_enemy.skeleton.hp = 50;
	//enemy.skeleton.sprite.setPosition(485, 85);
	loadImage(load.load_alien, "../images/enemy/alien.png");
	all_enemy.alien.sprite = load.load_alien.sprite;
	all_enemy.alien.sprite.setTextureRect(IntRect(150, 5, 42, 61));
	all_enemy.skeleton.hp = 70;
}
void InitLocalEnemy(StructAllEnemy& all_enemy, StructLocalEnemy local_enemy[NUM_STACK_ENEMY])
{
	srand(time(NULL));
	for (int i = 0; i < NUM_STACK_ENEMY; i++)
	{
		for (int j = 1; j < 4; j++)
		{ 
			int secret = rand() % 5;
			//std::cout << i << "---" << secret << "--" << j << "\n";
			if (secret == 0) local_enemy[i].enemy[j] = all_enemy.ghost;
			if (secret == 1) local_enemy[i].enemy[j] = all_enemy.skeleton;
			if (secret == 2) local_enemy[i].enemy[j] = all_enemy.alien;
			if (secret == 3) local_enemy[i].enemy[j] = all_enemy.ghost;
			if (secret == 4) local_enemy[i].enemy[j] = all_enemy.ghost;
		}
	}
}
void InintExplonationImage(StructLoad& load, StructGameImage& game_image)
{
	// Загрузка карты
	loadImage(load.map1, "../images/fon/level2.png");
	game_image.map = load.map1.sprite;
	//Загрузка фона
	loadImage(load.background, "../images/Инвентарь/фон инвентаря.png");
	game_image.inventory_background = load.background.sprite;
	game_image.background.setPosition(0, 250);
	loadImage(load.background2, "../images/Инвентарь/back.png");
	game_image.background = load.background2.sprite;
	game_image.background.setPosition(0, 208);

	loadImage(load.background_battle, "../images/Batle/040-Tower02.jpg");
	game_image.batle_background = load.background_battle.sprite;
}
void InintBattleImage(StructLoad& load, StructBattleImage& battle_image)
{
	loadImage(load.background_battle, "../images/Batle/040-Tower02.jpg");
	battle_image.main_background = load.background_battle.sprite;
	loadImage(load.background_fon, "../images/Batle/town_c22a1.jpg");
	battle_image.background = (load.background_fon.sprite);
	loadImage(load.blackout, "../images/Batle/blackout.png");
	battle_image.blackout = load.blackout.sprite;
}
/*struct AttacksRogue
{
	void Attack1(Structheroes& rogue, StructEnemy& victim)
	{
		victim.hp -= 10;
	}
	void Attack2(Structheroes& rogue)
	{
		rogue.damage = rogue.damage + 0.5;
	}
	void Attack3(StructEnemy& victim, StructEnemy& victim2, StructEnemy& victim3)
	{
		victim.hp = -5;
		victim2.hp = -5;
		victim3.hp = -5;
	}
	void Attack4(Structheroes& rogue, StructEnemy& victim)
	{
		victim.hp -= 20;
		rogue.damage -= 0.2;
	}
};
struct AttacksCruasder
{
	void Attack1(Structheroes& cruasder, StructEnemy& victim)
	{
		victim.hp -= 15;
	}
	void Attack2(Structheroes& cruasder)
	{
		cruasder.def = cruasder.def + 0.5;
	}
	void Attack3(Structheroes& cruasder)
	{
		cruasder.hp += 10;
	}
	void Attack4(Structheroes& cruasder, StructEnemy& victim)
	{
		victim.hp -= 20;
		cruasder.def -= 0.2;
	}
};
AttacksRogue attack_rouge;
AttacksCruasder attack_cruasder;*/

void MoveHeroes(Structheroes& hero, float& time, float& CurrentFrame, int key)
{
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
void СheckEnemies(Sprite hero, Sprite map, int& stage_game)
{
	Vector2f heroesPosition = hero.getPosition();
	//std::cout << heroesPosition.x << "\n";
	if ((TileMap[int(heroesPosition.x / 248)] == 'a'))
	{
		stage_game = 2;
		//std::cout << stage_game;
	}
}
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
		if (TileMap[i] == 'a')
		{
			map.setTextureRect((IntRect(1240, 0, 248, 208)));
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
void GetInventory(RenderWindow& window, Vector2i inventory[quantity_subject], Vector2f f)
{
	Vector2i ff;
	ff.x = int(f.x);
	ff.y = int(f.y);
	Vector2i localPosition = Mouse::getPosition(window);
	localPosition = localPosition + ff - Vector2i(500, 300);
	if ((((f.x + 40) <= localPosition.x) && (localPosition.x <= (f.x + 40 + 60))) && ((f.y + 15 <= localPosition.y) && (f.y + 595 >= localPosition.y)))
	{
		int i = (localPosition.y - 315) / 70 +  1;
		std::cout << i << "\n";
	}
	
	
}
void SetImageBattle(StructAllHeroes& all_heroes, StructBattleImage& battle_image, Vector2f f)
{
	battle_image.background.setPosition(f.x - 500, f.y - 300);
	battle_image.blackout.setPosition(f.x - 500, f.y - 300);
	battle_image.main_background.setPosition(f.x - 500, f.y - 300);

	all_heroes.cruasder.batle_sprite.setPosition(f.x - 250, f.y - 150);
	all_heroes.rogue.batle_sprite.setPosition(f.x - 320, f.y - 150);
	all_heroes.wizard.batle_sprite.setPosition(f.x - 390, f.y - 150);
	all_heroes.mage.batle_sprite.setPosition(f.x - 460, f.y - 160);

	all_heroes.cruasder.image_ability.setPosition(f.x - 500, f.y);
	all_heroes.rogue.image_ability.setPosition(f.x - 500, f.y);
	all_heroes.wizard.image_ability.setPosition(f.x - 500, f.y);
	all_heroes.mage.image_ability.setPosition(f.x - 500, f.y);
	float zoom = 1.25;
	all_heroes.cruasder.batle_sprite.setScale(zoom, zoom);
	all_heroes.rogue.batle_sprite.setScale(zoom, zoom);
	all_heroes.wizard.batle_sprite.setScale(zoom, zoom);
	all_heroes.mage.batle_sprite.setScale(zoom, zoom);
}
void SetLocalEnemy(StructEnemy enemy[3], Vector2f f)
{
	float zoom = 1.5;
	enemy[1].sprite.setPosition(f.x, f.y - 160);
	enemy[1].sprite.setScale(zoom, zoom);
	enemy[2].sprite.setPosition(f.x + 70, f.y - 160);
	enemy[2].sprite.setScale(zoom, zoom);
	enemy[3].sprite.setPosition(f.x + 140, f.y - 160);
	enemy[3].sprite.setScale(zoom, zoom);
	for (int i = 1; i <= 4; i++)
	{
		int size_sq = enemy[i].hp;
		enemy[i].sq.setSize(Vector2f(2 * size_sq, 15));
		enemy[i].sq.setFillColor(Color::Red);
		enemy[i].sq.setPosition(f.x + 320, (f.y - 200 + (i * 30)));
	}
}

void AttackModeCrusader(AttacksCruasder& attack_cruasder, StructAllHeroes& all_heroes, StructEnemy enemy[4], int& jump_step, StructFlaq& flaq)
{
	if (flaq.key_attack == 1)
	{
		flaq.key_attack = 0;
		attack_cruasder.Attack1(all_heroes.cruasder, enemy[1]);
	}
	if (flaq.key_attack == 2)
	{
		attack_cruasder.Attack2(all_heroes.cruasder);
		flaq.key_attack = 0;
	}
	if (flaq.key_attack == 3) {
		flaq.key_attack = 0;
		attack_cruasder.Attack3(all_heroes.cruasder);
	}
	if (flaq.key_attack == 4)
	{
		attack_cruasder.Attack4(all_heroes.cruasder, enemy[1]);
		flaq.key_attack = 0;
	}
}
void AttackModeRogue(AttacksRogue& attack_rouge, StructAllHeroes& all_heroes, StructEnemy enemy[4], int& jump_step, StructFlaq& flaq)
{
	if (flaq.key_attack == 1)
	{
		flaq.key_attack = 0;
		attack_rouge.Attack1(all_heroes.rogue, enemy[1]);
	}
	if (flaq.key_attack == 2)
	{
		flaq.key_attack = 0;
		attack_rouge.Attack2(all_heroes.rogue);
	}
	if (flaq.key_attack == 3)
	{
		flaq.key_attack = 0;
		attack_rouge.Attack3(enemy[1], enemy[2], enemy[3]);
	}
	if (flaq.key_attack == 4)
	{
		flaq.key_attack = 0;
		attack_rouge.Attack4(all_heroes.rogue, enemy[2]);
	}
}
void AttackModeWizard(AttacksWizard& attack_wizard, StructAllHeroes& all_heroes, StructEnemy enemy[4], int& jump_step, StructFlaq& flaq)
{
	if (flaq.key_attack == 1)
	{
		flaq.key_attack = 0;
		attack_wizard.Attack1(enemy[3]);
	}
	if (flaq.key_attack == 2)
	{
		flaq.key_attack = 0;
		attack_wizard.Attack2(all_heroes);
	}
	if (flaq.key_attack == 3)
	{
		flaq.key_attack = 0;
		attack_wizard.Attack3(all_heroes);
	}
	if (flaq.key_attack == 4)
	{
		flaq.key_attack = 0;
		attack_wizard.Attack4(enemy[2]);
	}
}
void AttackModeMage(AttacksMage& attack_mage, StructAllHeroes& all_heroes, int& jump_step, StructFlaq& flaq)
{
	if (flaq.key_attack == 1)
	{
		flaq.key_attack = 0;
		attack_mage.Attack1(all_heroes);
	}
	if (flaq.key_attack == 2)
	{
		flaq.key_attack = 0;
		attack_mage.Attack2(all_heroes);
	}
	if (flaq.key_attack == 3)
	{
		flaq.key_attack = 0;
		attack_mage.Attack3(all_heroes);
	}
	if (flaq.key_attack == 4)
	{
		flaq.key_attack = 0;
		attack_mage.Attack4(all_heroes);
	}
}
void AttackModeEnemy(StructAllHeroes& all_heroes, StructEnemy enemy[4], int& jump_step)
{

}
void Attack(StructAllHeroes& all_heroes, StructEnemy enemy[4], int& jump_step)
{
	float zoom_heroes = 2.5;
	float zoom_enemy = 3;
	all_heroes.cruasder.batle_sprite.setTextureRect(IntRect(all_heroes.cruasder.action1.pos_x, all_heroes.cruasder.action1.pos_y, all_heroes.cruasder.action1.size_x, all_heroes.cruasder.action1.size_y));
	all_heroes.rogue.batle_sprite.setTextureRect(IntRect(all_heroes.rogue.action1.pos_x, all_heroes.rogue.action1.pos_y, all_heroes.rogue.action1.size_x, all_heroes.rogue.action1.size_y));
	all_heroes.wizard.batle_sprite.setTextureRect(IntRect(all_heroes.wizard.action1.pos_x, all_heroes.wizard.action1.pos_y, all_heroes.wizard.action1.size_x, all_heroes.wizard.action1.size_y));
	all_heroes.mage.batle_sprite.setTextureRect(IntRect(all_heroes.mage.action1.pos_x, all_heroes.mage.action1.pos_y, all_heroes.mage.action1.size_x, all_heroes.mage.action1.size_y));
	all_heroes.cruasder.batle_sprite.setScale(zoom_heroes, zoom_heroes);
	all_heroes.rogue.batle_sprite.setScale(zoom_heroes, zoom_heroes);
	all_heroes.wizard.batle_sprite.setScale(zoom_heroes, zoom_heroes);
	all_heroes.mage.batle_sprite.setScale(zoom_heroes, zoom_heroes);
	for (int i = 1; i <= 4; i++)
	{
		enemy[i].sprite.setTextureRect(IntRect(enemy[i].pos_x, enemy[i].pos_y, enemy[i].size_x, enemy[i].size_y));
		enemy[i].sprite.setScale(zoom_enemy, zoom_enemy);
	}
}
void WindowPolEvent(RenderWindow& window, Event& event, int stage_game, StructFlaq& flaq)
{
	flaq = { 0 };
	//std::cout << flaq.cheat;
	//flaq.cheat = 0;
	//flaq.mous_inventory = 0;
	//flaq.r_alt = 0;
	while (window.pollEvent(event))
	{
		if (stage_game == 1)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space)) flaq.cheat = 1;
			if (Mouse::isButtonPressed(sf::Mouse::Left)) flaq.mous_inventory = 1;
		}
		if (stage_game == 2)
		{
			if ((Keyboard::isKeyPressed(Keyboard::RAlt)) && (jump_step <= 4)) flaq.r_alt = 1;
			if (Keyboard::isKeyPressed(Keyboard::Num1)) flaq.key_attack = 1;
			if (Keyboard::isKeyPressed(Keyboard::Num2)) flaq.key_attack = 2;
			if (Keyboard::isKeyPressed(Keyboard::Num3)) flaq.key_attack = 3;
			if (Keyboard::isKeyPressed(Keyboard::Num4)) flaq.key_attack = 4;
		}
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void DrawBattle(RenderWindow& window, StructAllHeroes& all_heroes, StructEnemy enemy[4], Vector2f f, float timer, int jump_step)
{
	window.draw(battle_image.background);
	window.draw(battle_image.main_background);
	HpInfo(all_heroes.cruasder, f, 1, window);
	HpInfo(all_heroes.rogue, f, 2, window);
	HpInfo(all_heroes.wizard, f, 3, window);
	HpInfo(all_heroes.mage, f, 4, window);
	
	window.draw(all_heroes.cruasder.batle_sprite);
	window.draw(all_heroes.rogue.batle_sprite);
	window.draw(all_heroes.wizard.batle_sprite);
	window.draw(all_heroes.mage.batle_sprite);

	if (jump_step == 1) window.draw(all_heroes.cruasder.image_ability);
	if (jump_step == 2) window.draw(all_heroes.rogue.image_ability);
	if (jump_step == 3) window.draw(all_heroes.wizard.image_ability);
	if (jump_step == 4) window.draw(all_heroes.mage.image_ability);
	for (int i = 1; i <= 4; i++)
	{
		window.draw(enemy[i].sprite);
		window.draw(enemy[i].sq);
	}
	if ((timer <= 5) || (jump_step == 0)) window.draw(battle_image.blackout);
}
void ExplorationMod(RenderWindow& window, StructAllHeroes& all_heroes, StructTime& time_game, Vector2f& f, int& stage_game, Event& event)
{
	WindowPolEvent(window, event, stage_game, flaq);
	if (flaq.cheat == 1)
	{
		openChest(all_heroes.rogue.sprite, game_image.map, items.sprite, inventory);
		window.draw(game_image.map);
	}
	//if (Keyboard::isKeyPressed(Keyboard::Q)) { window.clear(); system("pause"); }
	if (flaq.mous_inventory) GetInventory(window, inventory, f);
	СheckEnemies(all_heroes.rogue.sprite, game_image.map, stage_game);
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) & (all_heroes.mage.heroesPosition.x >= 10))
	{
		time_game.CurrentFrame += 0.005*time_game.time;
		MoveHeroes(all_heroes.wizard, time_game.time, time_game.CurrentFrame, -1);
		MoveHeroes(all_heroes.rogue, time_game.time, time_game.CurrentFrame, -1);
		MoveHeroes(all_heroes.cruasder, time_game.time, time_game.CurrentFrame, -1);
		MoveHeroes(all_heroes.mage, time_game.time, time_game.CurrentFrame, -1);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) & (all_heroes.cruasder.heroesPosition.x <= (length_map * 228)))
	{
		time_game.CurrentFrame += 0.005*time_game.time;
		MoveHeroes(all_heroes.wizard, time_game.time, time_game.CurrentFrame, 1);
		MoveHeroes(all_heroes.rogue, time_game.time, time_game.CurrentFrame, 1);
		MoveHeroes(all_heroes.cruasder, time_game.time, time_game.CurrentFrame, 1);
		MoveHeroes(all_heroes.mage, time_game.time, time_game.CurrentFrame, 1);
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



	//window.setView(view);
	//ViewMove(time, f);
	game_image.inventory_background.setPosition(f.x - 500, f.y - 92);
	game_image.background.setPosition(f.x - 500, f.y - 95);
	templar.sprite.setPosition(f.x - 250, f.y);
	window.draw(game_image.background);
	window.draw(game_image.inventory_background);


	//getPlayerCoordinateForView(wizard.heroesPosition.x, wizard.heroesPosition.y);
	//std::cout << wizard.heroesPosition.x << "-----" << wizard.heroesPosition.y << "\n";

	DrawMap(window, game_image.map);
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

void BattleMod(RenderWindow& window, StructAllHeroes& all_heroes, StructEnemy enemy[4], StructTime& time_game, Vector2f& f, int& jump_step, Event& event, int& stage_game, StructFlaq& flaq)
{
	float timer = time_game.clock2.getElapsedTime().asSeconds();
	//sf::Event event;	
	if (jump_step == 0)  time_game.clock2.restart();
	if ((timer >- 10) && (jump_step == 0)) jump_step++;
	WindowPolEvent(window, event, stage_game, flaq);
	if (jump_step == 1) AttackModeCrusader(attack_cruasder, all_heroes, enemy, jump_step, flaq);
	if (jump_step == 2) AttackModeRogue(attack_rouge, all_heroes, enemy, jump_step, flaq);
	if (jump_step == 3) AttackModeWizard(attack_wizard, all_heroes, enemy, jump_step, flaq);
	if (jump_step == 4) AttackModeMage(attack_mage, all_heroes, jump_step, flaq);
	if (jump_step == 5) AttackModeEnemy(all_heroes, enemy, jump_step);
	if (jump_step == 6) time_game.clock2.restart();
	if ((flaq.r_alt) && (jump_step <= 4)) jump_step++;
	std::cout << timer << "\n";
	SetImageBattle(all_heroes, battle_image, f);
	SetLocalEnemy(enemy, f);
	//if (timer <= 5) Attack(all_heroes, enemy, jump_step);
	DrawBattle(window, all_heroes, enemy, f, timer, jump_step);
	//DrawInventory(items, f, window);
	//window.draw(all_heroes.wizard.batle_sprite);
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
	/*Image skeleton;
	skeleton.loadFromFile("../images/enemy/CadashSheet3.png");
	skeleton.createMaskFromColor(Color(255, 0, 255));
	Texture skeleton_texture;
	skeleton_texture.loadFromImage(skeleton);
	Sprite skeleton_sprite;
	skeleton_sprite.setTexture(skeleton_texture);
	skeleton_sprite.setTextureRect(IntRect(161, 162, 52, 64));
	skeleton_sprite.setPosition(485, 85);*/
	
		
	//Загрузка инвентаря
	loadImage(items, "../images/Инвентарь/Предеметы.png");
	InitHeroes(load, all_heroes);
	InitAnimation(all_heroes);
	InitEnemy(load, all_enemy);
	InitLocalEnemy(all_enemy, local_enemy);
	InintExplonationImage(load, game_image);
	InintBattleImage(load, battle_image);
	Vector2f f;
	time_game.CurrentFrame = 0;
	int stage_game;
	stage_game = 1;
	srand(time(NULL));
	for (int i = 0; i < quantity_subject; i++)
	{
		inventory[i].x = 0;
		inventory[i].y = 0;
	}
	jump_step = 0;
	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		time_game.time = time_game.clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		time_game.clock.restart(); //перезагружает время
		time_game.time = time_game.time / 1000; //скорость игры
		time_game.flaq_time2 = 0;
		sf::Event event;
		window.setView(view);
		ViewMove(time_game.time, f, stage_game);
		if (stage_game == 1) ExplorationMod(window, all_heroes, time_game, f, stage_game, event);
		if (stage_game == 2) BattleMod(window, all_heroes, local_enemy[0].enemy,  time_game, f,jump_step, event, stage_game, flaq);
		/*while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Num9)) stage_game = 1;
			if (Keyboard::isKeyPressed(Keyboard::Num0)) stage_game = 2;
			if (event.type == sf::Event::Closed)
				window.close();
		}*/
		window.display();
	}

	return 0;
}
