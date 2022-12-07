#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Textbox
{
public:
	Textbox(int size, sf::Color color, bool sel)
	{
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = sel;
	}
	void setFont(sf::Font& font)
	{
		textbox.setFont(font);
	}
	void setPosition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}
	void setLimit(bool ToF)
	{
		hasLimit = ToF;
	}
	void setLimit(bool ToF, int lim)
	{
		hasLimit = ToF;
		limit = lim;
	}
	void setSelected(bool sel)
	{
		isSelected = sel;
		if (!sel)
		{
			std::string t = text.str();
			std::string newT = "";
			for (size_t i = 0; i < t.length() - 1; i++)
			{
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}
	bool textboxSelected()
	{
		return isSelected;
	}
	std::string getText()
	{
		return text.str();
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}

	void typedOn(sf::Event input)
	{
		if (isSelected)
		{
			int charTyped = input.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == 8)
					{
						deleteLastChar();
					}
				}
				else if (charTyped == 27)
				{
					setSelected(false);
				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}

private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	size_t limit;

	void inputLogic(int charTyped)
	{
		if ((charTyped != 8) && (charTyped != 13) && (charTyped != 27))
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == 8)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void deleteLastChar()
	{
		std::string t = text.str();
		std::string newT = "";
		for (size_t i = 0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}
		text.str("");
		text << newT;
	}
};