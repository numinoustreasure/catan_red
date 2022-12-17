#include "Button.h"

class TitleScreen
{

	sf::Vector2u size;
	sf::RectangleShape bgImage;
	sf::Texture bgTexture;
	sf::Texture btn1Texture;
	sf::Texture btn2Texture;
	sf::Texture btn3Texture;
	float x1;
	float y2;

	sf::Font titleFont;

public:
	Button btn1, btn2, btn3;

	sf::RenderWindow titleScreen;
	TitleScreen()
	{
		titleScreen.create(sf::VideoMode(1280, 720), "Catan: Red Edition");
		size = titleScreen.getSize();
		bgImage.setSize(sf::Vector2f(size.x, size.y));
		bgTexture.loadFromFile("src\\backGround.jpg");
		bgImage.setTexture(&bgTexture);
		titleFont.loadFromFile("src\\RobotoSlab-VariableFont_wght.ttf");

		//btn1
		btn1Texture.loadFromFile("src\\Play_Button.png");
		btn1 = Button({ 185, 85 }, btn1Texture);
		btn1.setPosition(sf::Vector2f(size.x / 2, size.y / 2.5));

		//btn2
		btn2Texture.loadFromFile("src\\Settings_Button.png");
		btn2 = Button({ 185, 85 }, btn2Texture);
		btn2.setPosition(sf::Vector2f(size.x / 2, size.y / 1.7));

		//btn3
		btn3Texture.loadFromFile("src\\Exit_Button.png");
		btn3 = Button({ 185, 85 }, btn3Texture);
		btn3.setPosition(sf::Vector2f(size.x / 2, size.y / 1.3));
	}

	void drawTitle()
	{
		titleScreen.draw(bgImage);
		btn1.drawTo(titleScreen);
		btn2.drawTo(titleScreen);
		btn3.drawTo(titleScreen);
	}
};
