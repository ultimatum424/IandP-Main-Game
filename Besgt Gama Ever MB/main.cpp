#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


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

void loadImage(struct structImages& s, String F)
{
	s.image.loadFromFile(F);
	s.texture.loadFromImage(s.image);
	s.sprite.setTexture(s.texture);
}





int main()
{
	setlocale(LC_CTYPE, "rus");
	const int window_x = 1000;
	const int window_y = 600;

	int i;
	struct structImages map1;
	struct structImages ghost_load;
	struct structImages templar;
	struct structImages wizard_load;
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Game");
	
	

	
	Image skeleton;
	skeleton.loadFromFile("D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/CadashSheet3.png");
	skeleton.createMaskFromColor(Color(255, 0, 255));
	Texture skeleton_texture;
	skeleton_texture.loadFromImage(skeleton);
	Sprite skeleton_sprite;
	skeleton_sprite.setTexture(skeleton_texture);
	skeleton_sprite.setTextureRect(IntRect(161, 162, 52, 64));
	skeleton_sprite.setPosition(485, 85);

	loadImage(map1, "D: / Универ / ИИП и игра / Besgt Gama Ever MB / images /11289_1260477187.png");
	map1.sprite.setPosition(0, 0);
	// Загружаем призрака
	loadImage(ghost_load, "D:/Универ/ИИП и игра/примеры/PC Computer - Shovel Knight - The Big Creep.png");
	ghost_load.sprite.setTextureRect(IntRect(0, 155, 90, 85));
	ghost_load.sprite.setPosition(400, 85);
	// Загрузка волшебника
	loadImage(wizard_load, "D:/Универ/ИИП и игра/Besgt Gama Ever MB/images/wizard/wizard.png");
	wizard_load.sprite = wizard_load.sprite;
	wizard_load.sprite.setTextureRect(IntRect(19, 6, 40, 80));
	wizard_load.sprite.setPosition(50, 85);


	

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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		
		

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			ghost_load .sprite.setTextureRect(IntRect(65 + (65 * int(CurrentFrame)), 62, -65, 58));
			ghost_load.sprite.move(-0.1, 0);
	}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
		{
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 4) { CurrentFrame -= 4; }
			ghost_load.sprite.setTextureRect(IntRect(65+(65 * int(CurrentFrame)), 62, -65, 58));
			ghost_load.sprite.move(0.1, 0);
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
		}
		
		window.clear();
		map1.sprite.setPosition(0, 0);
		window.draw(map1.sprite);
		window.draw(ghost_load.sprite);
		window.draw(skeleton_sprite);
		window.display();
	}

	return 0;
}