#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	//----------------------------INITIALIZE-------------------
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800,600), "RPG GAME",Style::Default, settings);

	//----------------------------LOAD-------------------------


	//----------------------------SKELETON-------------------------
	Texture skeletonTexture;
	Sprite skeletonSprite;

	if (skeletonTexture.loadFromFile("assets/skeleton/textures/spritesheet.png"))
	{
		cout << "Player Images Loaded!" << endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setPosition(Vector2f(400,100));

		//int
		//Width, Height, X,Y

		int XIndex = 8;
		int YIndex = 3;
		skeletonSprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		skeletonSprite.scale(Vector2f(1, 1));
	}
	else
	{
		cout << "Skeleton Image failed to loaded!" << endl;
	}
	//----------------------------SKELETON-------------------------


	//----------------------------PLAYER-------------------------

	Texture playerTexture;
	Sprite playerSprite;

	if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png"))
	{
		cout << "Player Images Loaded!" << endl;
		playerSprite.setTexture(playerTexture);

		//int
		//Width, Height, X,Y

		int XIndex = 8;
		int YIndex = 3;
		playerSprite.setTextureRect(IntRect(XIndex*64, YIndex*64,64,64));
		playerSprite.scale(Vector2f(1, 1));
	}
	else
	{
		cout << "Player Image failed to loaded!" << endl;
	}

	//----------------------------PLAYER-------------------------
	// 
	//----------------------------LOAD-------------------------
	

	CircleShape shape(50.0f,7);
	shape.setFillColor(Color::Red);
	shape.setPosition(Vector2f(100,100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(Color::Cyan);

	RectangleShape rectangle(Vector2f(100, 100));
	rectangle.setPosition(Vector2f(100, 100));
	rectangle.setFillColor(Color::Blue);
	rectangle.setOrigin(Vector2f(-90, 90));
	rectangle.setRotation(45);

	//----------------------------INITIALIZE-------------------
	while (window.isOpen())
	{
	
	//------------------------------UPDATE------------------------------
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			Vector2f position = playerSprite.getPosition();
			playerSprite.setPosition(position + Vector2f(0.2, 0));
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			Vector2f position = playerSprite.getPosition();
			playerSprite.setPosition(position + Vector2f(-0.2, 0));
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			Vector2f position = playerSprite.getPosition();
			playerSprite.setPosition(position + Vector2f(0, 0.2));
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			Vector2f position = playerSprite.getPosition();
			playerSprite.setPosition(position + Vector2f(0, -0.2));
		}
		
	//-------------------------------DRAW------------------------------------
		window.clear(Color::Black);
		window.draw(playerSprite);
		window.draw(skeletonSprite);
		window.display();

	

	//-------------------------------DRAW------------------------------------		
	}
}

