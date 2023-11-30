#ifndef BUTTON_H
#define BUTTON_H
#include <cstdio>
#include "./SFML/Graphics.hpp"

class Button{
  private:
    sf::RectangleShape button; 
    sf::Text text; // text button
    sf::Color color; // button color
    sf::Font font; // button font 

    int xCord; // x Position button
    int yCord; // y positoin button
 
  public: 
    Button(int x, int y); // Constructor
    void create(std::string, sf::Font& font); // creates a button
    bool checkClick(sf::RenderWindow& window); // check button activity
    void draw(sf::RenderWindow& window); // draw method
};
#endif // BUTTON_H
