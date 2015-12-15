#pragma once
#include <SFML\Graphics.hpp>
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
};
struct StructExplonationImage
{
	Sprite map;
	Sprite background;
	Sprite background2;
};
struct StructBattleImage
{
	Sprite main_background;
	Sprite inventory_background;
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
};
struct StructAllHeroes
{
	Structheroes wizard;
	Structheroes rogue;
	Structheroes cruasder;
	Structheroes mage;
};
StructLoad load;
structImages ghost_load;
structImages templar;

structImages items;
StructAllHeroes all_heroes;
Structheroes ghost;


StructExplonationImage explonation_image;
StructBattleImage battle_image;