#include "./button.h"

Button::Button(int x, int y) {
  xCord = x;
  yCord = y;
}

void Button::create(std::string txt, sf::Font &font) {
  sf::Color col(255, 255, 255);

  text.setString(txt);
  text.setFont(font);
  text.setCharacterSize(30);
  text.setFillColor(col);
  text.setPosition(xCord, yCord);

  button.setFillColor(col);
  // button.setSize(sf::Vector2f(200, 100));
  button.setPosition(xCord, yCord);
}

bool Button::checkClick(sf::RenderWindow &window) {
  if (text.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) &&
      sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    
  while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    }

    return true;
  }
  return false;
}

void Button::draw(sf::RenderWindow &window) {
  window.draw(button);
  window.draw(text);
}
