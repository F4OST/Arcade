/*
** SFMLMenuController.cpp for cpp_arcade in /home/lopez_i/cpp_arcade/SFMLMenuController.cpp
**
** Made by Loïc Lopez
** Login   <loic.lopez@epitech.eu>
**
** Started on  jeu. avr. 06 13:30:29 2017 Loïc Lopez
** Last update Sun Apr  9 16:11:16 2017 Matthias Prost
*/

#include "SFMLViewController.hpp"


void	SFMLViewController::drawMenu(size_t &currentGame,
					 std::vector<std::string> const &games,
					 bool &exit, size_t &currentLibrary,
					 ChangeCommandType &action, std::string &playerName)
{
  sf::Font     	font;
  sf::Event 	event;
  std::vector<sf::Text> menu;
  bool		isSecondPart = false;
  int 		gamePosition;
  int 		selectedItemIndex = 0;
  std::vector<sf::Text> Items;
  const	char 	*ItemStrings[] =
   {
    "Snake",
    "SolarFox",
    "Exit"
   };
  const	char	*texts[] =
   {
    "Move the cursor menu to select a game.",
    "Press enter to choose a game.",
    "In Game :",
    "Key 2 : move to previous graphical library.",
    "Key 3 : move to next graphical library.",
    "Key 4 : move to previous game.",
    "Key 5 : move to next game.",
    "Key 8 : restart the game.",
    "Key 9 : display this menu.",
    "Key Escape : quit the game or menu.",
    "Move character with arrows.",
    "Space to shoot (SolarFox)",
    "\n"
   };
  sf::Text	mainText;
  sf::Text	arrow;
  size_t	index;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Text	player;

	sf::RectangleShape back_text;

	back_text.setSize(sf::Vector2f(500,500));
	back_text.setFillColor(sf::Color(0, 0, 0));
	back_text.setPosition(this->windowsize_x / 2 - 850,
			 320);

  if (!texture.loadFromFile("assets/BorneArcade.png"))
    std::cerr << "ERROR: cannot found BorneArcade in assets/ make sure it exist" << std::endl;
  if (!font.loadFromFile("lib-sources/SFML/Fonts/Roboto-Condensed.ttf"))
    std::cerr << "ERROR: cannot found Roboto-Condensed.ttf in lib-sources/SFML/Fonts/ make sure it exist" << std::endl;
  texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setPosition(sf::Vector2f((this->windowsize_x / 2.0f) * 1.10 - (texture.getSize().x),
				  (this->windowsize_y / 2.0f) * 1.1 - (texture.getSize().y)));
  sprite.scale(sf::Vector2f(1.5f, 1.5f));
  mainText.setFont(font);
  mainText.setString("Game Arcade Menu");
  sf::FloatRect textRect = mainText.getLocalBounds();

  mainText.setOrigin(textRect.width / 2, textRect.height / 2);
  mainText.setPosition((sf::Vector2f((this->windowsize_x / 2.15f), sizeof("Game Arcade Menu"))));
  mainText.setCharacterSize(45);
  mainText.setFillColor(sf::Color::Red);
  arrow.setFont(font);
  arrow.setString("->");
  arrow.setCharacterSize(24);
  arrow.setFillColor(sf::Color::Red);
  arrow.setPosition(((this->windowsize_x) / 2) -
		    (sizeof(ItemStrings[selectedItemIndex]) *
		     sizeof(ItemStrings[selectedItemIndex])) -
		    (sizeof("->") * sizeof("->")) * 3 , (this->windowsize_y / 3) +
							(((selectedItemIndex * sizeof(ItemStrings[selectedItemIndex]))) * 5));
  for (size_t j = 0; j < (sizeof(texts) / sizeof(texts[0])); ++j)
    {
      sf::Text	Text;

      std::string string = texts[j];
      Text.setFont(font);
      Text.setString(string);
      Text.setCharacterSize(24);
      Text.setFillColor(sf::Color::White);
      if (isSecondPart)
	Text.setPosition((this->windowsize_x) / 12, (gamePosition + j * 25) - 20);
      else if (string == "In Game :")
	{
	  isSecondPart = true;
	  gamePosition = (24 * (j * 2)) + (this->windowsize_y / 3);
	  Text.setPosition((this->windowsize_x) / 12, gamePosition);
	}
      else
	Text.setPosition((this->windowsize_x) / 12, 24 * j + (this->windowsize_y / 3));
      menu.push_back(Text);
    }

  for (size_t i = 0; i < (sizeof(ItemStrings) / sizeof(ItemStrings[0])); ++i)
    {
      sf::Text	Text;
      Text.setFont(font);
      Text.setString(ItemStrings[i]);
      Text.setCharacterSize(35);
      Text.setFillColor(sf::Color::White);
      Text.setPosition(((this->windowsize_x) / 2) - (sizeof(ItemStrings[i]) * sizeof(ItemStrings[i])),
		       (this->windowsize_y / 3) + (((i * sizeof(ItemStrings[i]))) * 5));
      Items.push_back(Text);
    }

  this->functionCaller = __FUNCTION__;
  Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
  this->initScreen("Arcade Game Menu", "");
  player.setFont(font);
  player.setString("Player Name: " + playerName);
  player.setPosition((this->windowsize_x) / 12, (24 * menu.size() + 70) + (this->windowsize_y / 3));
  while (this->window.isOpen())
    {
      while (this->window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    {
	      exit = true;
	      this->endScreen();
	      return;
	    }
	  if (event.type == sf::Event::TextEntered)
	    {
	      player.setString("Player Name: " + playerName);
	      if (event.text.unicode == 8 && playerName.size() > 0)
		{
		  playerName.pop_back();
		  player.setString("Player Name: " + playerName);
		}
	      else if (event.text.unicode < 128)
		{
		  playerName += static_cast<char>(event.text.unicode);
		  player.setString("Player Name: " + playerName);
		}
	    }
	  if (event.type == sf::Event::KeyPressed)
	    {
	      if (event.key.code == sf::Keyboard::Escape)
		{
		  exit = true;
		  this->endScreen();
		  return;
		}
	      else if (event.key.code == sf::Keyboard::Up)
		{
		  if (selectedItemIndex - 1 >= 0)
		    {
		      Items[selectedItemIndex].setFillColor(sf::Color::White);
		      selectedItemIndex--;
		      Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
		    }
		}
	      else if (event.key.code == sf::Keyboard::Down)
		{
		  if (selectedItemIndex + 1 < static_cast<int>(Items.size()))
		    {
		      Items[selectedItemIndex].setFillColor(sf::Color::White);
		      selectedItemIndex++;
		      Items[selectedItemIndex].setFillColor(sf::Color::Cyan);
		    }
		}
	      else if (event.key.code == sf::Keyboard::Num2)
		{
		  this->endScreen();
		  action = ChangeCommandType::PREV_LIBRARY;
		  currentLibrary--;
		  return;
		}
	      else if (event.key.code == sf::Keyboard::Num3)
		{
		  this->endScreen();
		  action = ChangeCommandType::NEXT_LIBRARY;
		  currentLibrary++;
		  return;
		}
	      else if (event.key.code == sf::Keyboard::Return)
		{
		  action = ChangeCommandType::PLAY;
		  std::string 	currentText = Items[selectedItemIndex].getString();
		  std::transform(currentText.begin(), currentText.end(),
				 currentText.begin(), ::tolower);
		  if (currentText == "exit")
		    {
		      exit = true;
		      this->endScreen();
		      return;
		    }
		  for (index = 0; index < games.size(); ++index)
		    {
		      if (games.at(index).find(currentText) != std::string::npos)
			{
			  currentGame = index;
			  this->functionCaller = "OTHER";
			  this->endScreen();
			  return;
			}
		    }
		  if (index == games.size())
		    {
		      exit = true;
		      this->functionCaller = "OTHER";
		      this->endScreen();
		      return;
		    }
		}
	    }
	}

      arrow.setPosition(((this->windowsize_x) / 2) -
			(sizeof(ItemStrings[selectedItemIndex]) *
			 sizeof(ItemStrings[selectedItemIndex])) -
			(sizeof("->") * sizeof("->")) * 3 ,
			(this->windowsize_y / 3) +
			(((selectedItemIndex * sizeof(ItemStrings[selectedItemIndex]))) * 5));
      this->window.draw(this->backgroundSprite);
      this->window.draw(back_text);
      this->window.draw(player);
      this->window.draw(sprite);
      this->window.draw(arrow);
      for (size_t i = 0; i < menu.size(); ++i)
	this->window.draw(menu[i]);
      for (size_t j = 0; j < Items.size(); ++j)
	this->window.draw(Items[j]);
      this->window.draw(mainText);
      this->refresh();
    }
}
