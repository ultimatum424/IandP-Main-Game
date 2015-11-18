#include <SFML/Graphics.hpp>
#include "map.h"
using namespace sf;

sf::View view;
float x_view = 500;
float y_view = 300;
//объ€вили sfml объект "вид", который и €вл€етс€ камерой#pragma once

void ViewMove(float& time, Vector2f& f) //функци€ дл€ считывани€ координат игрока
{ 
	
	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) & ( f.x - 500 >= 0))
	{
		view.move(-0.05*time, 0);
	}
	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) & (f.x + 500 < (length_map * 248)))
	{
		view.move(0.05*time, 0);
	}
	f = view.getCenter();
	/*if ((x > 50) & (y == 85)) 
	{
	if (x > (x_view - 450))
	{
		x_view = (x_view + x);
	}
		//view.setCenter(x + 450  , y + 215 ); 
		view.setCenter(x_view, 300);
		std::cout << x << "---" << x_view << '\n';
		//следим за игроком, передава€ его координаты камере.
	//}*/
}