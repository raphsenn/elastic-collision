#ifndef SLIDER_H
#define SLIDER_H
#include "./SFML/Graphics.hpp"
#include <cstdio>
#include <cmath>
#include <vector>

class Slider {
  private:
    sf::RectangleShape slider;
    sf::RectangleShape axis;
    sf::Font font;
    sf::Text text;
    int minValue;
    int maxValue;
    int xCord;
    int yCord;
    int axisWidth;
    int axisHeight;
    int sliderWidth;
    int sliderHeight;
    int slider_start_value;
    float sliderValue;
    float slider_start; 
  
   public:
    Slider(int x, int y, bool middle);
    sf::Text returnText(int x, int y, std::string z, int fontSize);
    void create(int min, int max, int start_value);
    void logic(sf::RenderWindow &window);
    float getSliderValue();
    void setSliderValue(float newValue);
    void setSliderPercentValue(float newPercentValue);
    void draw(sf::RenderWindow & window);
    void reset();
};
#endif //SLIDER_H
