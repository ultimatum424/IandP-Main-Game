#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
using namespace sf;
struct structImages
{
	Image image;
	String file;
	Texture texture;
	Sprite sprite;
	int pos_x;
	int pos_y;
};
struct Structheroes
{
	struct StructMove
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} move;
	struct StructAction1
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} action1;
	struct StructAction2
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} action2;
	struct StructAction3
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} action3;
	struct StructAction4
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} action4;
	struct StructDamage
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} hit;
	struct StructDie
	{
		float num_frame;
		int pos_x;
		int pos_y;
		int size_x;
		int size_y;
	} die;

	Sprite sprite;
	Sprite batle_sprite;
	Vector2f heroesPosition;
	int hp;
	int max_hp;
	float damage;
	float def;
	int position;
	Sprite icon;
	Sprite batle_icon;
	Sprite image_ability;
};
struct StructGameImage
{
	Sprite map;
	Sprite background;
	Sprite inventory_background;
	Sprite batle_background;
};
struct StructBattleImage
{
	Sprite background;
	Sprite main_background;
	Sprite inventory_background;
	Sprite blackout;
};
struct StructLoad
{
	structImages wizard_load;
	structImages rogue_load;
	structImages cruasder_load;
	structImages mage_load;
	structImages background;
	structImages background2;
	structImages map1;
	structImages background_battle;
	structImages background_fon;
	structImages load_ghost;
	structImages load_skeleton;
	structImages blackout;
	structImages load_alien;
	structImages load_image_ability_cruasder;
	structImages load_image_ability_rogue;
	structImages load_image_ability_wizard;
	structImages load_image_ability_mage;
};
struct StructAllHeroes
{
	Structheroes wizard;
	Structheroes rogue;
	Structheroes cruasder;
	Structheroes mage;
};
struct StructEnemy
{
	RectangleShape sq;
	Sprite sprite;
	int hp;
	float num_frame;
	int pos_x;
	int pos_y;
	int size_x;
	int size_y;
};
struct StructLocalEnemy
{
	StructEnemy enemy[4];
};
struct StructAllEnemy
{
	StructEnemy skeleton;
	StructEnemy ghost;
	StructEnemy alien;
};
struct StructFlaq
{
	bool cheat;
	bool mous_inventory;
	bool r_alt;
	bool key_attack;
	bool key_wizard;
	bool key_rogue;
	bool key_cruasder;
	bool key_mage;
};
struct StructTime
{
	bool flaq_time2;
	float CurrentFrame;
	float time;
	Clock clock;
	Clock clock2;
};
StructFlaq flaq;
StructLoad load;
structImages templar;
StructAllEnemy all_enemy;
structImages items;
StructAllHeroes all_heroes;
StructLocalEnemy local_enemy[5];
StructTime time_game;

StructGameImage game_image;
StructBattleImage battle_image;
struct AttacksRogue
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
struct AttacksWizard
{
	void Attack1(StructEnemy& victim)
	{
		victim.hp -= 7;
	}
	void Attack2(StructAllHeroes& all_heroes)
	{
		all_heroes.wizard.def = all_heroes.wizard.def + 0.15;
		all_heroes.cruasder.def = all_heroes.cruasder.def + 0.15;
		all_heroes.rogue.def = all_heroes.rogue.def + 0.15;
		all_heroes.mage.def = all_heroes.mage.def + 0.15;
	}
	void Attack3(StructAllHeroes& all_heroes)
	{
		all_heroes.cruasder.damage += 0.1;
		all_heroes.rogue.damage += 0.1;
		all_heroes.wizard.damage += 0.1;
		all_heroes.mage.damage += 0.1;
	}
	void Attack4(StructEnemy& victim)
	{
		victim.hp -= 10;
	}
};
struct AttacksMage 
{
	void Attack1(StructAllHeroes& all_heroes)
	{
		all_heroes.cruasder.hp += 6;
	}
	void Attack2(StructAllHeroes& all_heroes)
	{
		all_heroes.rogue.hp += 6;
	}
	void Attack3(StructAllHeroes& all_heroes)
	{
		all_heroes.wizard.hp += 6;
	}
	void Attack4(StructAllHeroes& all_heroes)
	{
		all_heroes.cruasder.hp += 3;
		all_heroes.rogue.hp += 3;
		all_heroes.wizard.hp += 3;
		all_heroes.mage.hp += 3;
	}
};
AttacksRogue attack_rouge;
AttacksCruasder attack_cruasder;
AttacksWizard attack_wizard;
AttacksMage attack_mage;
int jump_step;
const  int NUM_STACK_ENEMY = 4;