#include "Button.h"

class TitleScreen
{

	sf::Vector2u size;
	sf::RectangleShape bgImage;
	sf::Texture bgTexture;
	sf::Texture btn1Texture;
	float x1;
	float y2;

	sf::Font titleFont;

public:
	Button btn1;
	sf::RenderWindow titleScreen;
	TitleScreen()
	{
		titleScreen.create(sf::VideoMode(1280, 720), "Catan: Red Edition");
		size = titleScreen.getSize();
		bgImage.setSize(sf::Vector2f(size.x, size.y));
		bgTexture.loadFromFile("src\\backGround.jpg");
		bgImage.setTexture(&bgTexture);
		titleFont.loadFromFile("src\\RobotoSlab-VariableFont_wght.ttf");
		btn1Texture.loadFromFile("src\\Start_Button.png");
		btn1 = Button({ 400, 175 }, btn1Texture);
		btn1.setPosition(sf::Vector2f(size.x / 2, size.y / 2.5));
	}

	void drawTitle()
	{
		titleScreen.draw(bgImage);
		btn1.drawTo(titleScreen);
	}
};