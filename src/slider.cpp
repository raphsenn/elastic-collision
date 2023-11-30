#include "./slider.h"

Slider::Slider(int x, int y, bool middle) {
  xCord = x;
  yCord = y;
  axisHeight = 10;
  axisWidth = 200;
  sliderWidth = 20;
  sliderHeight = 30;

  if (!font.loadFromFile("fonts/monitorica.ttf"))
    printf("Error loading font\n");

  text.setFont(font);
  text.setFillColor(sf::Color::White);

  axis.setPosition(x, y);
  axis.setOrigin(0, axisHeight / 2);
  axis.setSize(sf::Vector2f(axisWidth, axisHeight));
  axis.setFillColor(sf::Color(63, 63, 63));

  // slider start position
  if (middle) {
    slider_start = axisWidth / 2 + x;
    // slider.setPosition(axisWidth / 2 + x, y);
  } else {
    slider_start = x;
    // slider.setPosition(x, y);
  }

  slider.setPosition(slider_start, y);
  slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
  slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
  slider.setFillColor(sf::Color(192, 192, 192));
}

sf::Text Slider::returnText(int x, int y, std::string z, int fontSize) {
  text.setCharacterSize(fontSize);
  text.setPosition(x, y);
  text.setString(z);
  return text;
}

void Slider::create(int min, int max, int start_val) {
  sliderValue = start_val;
  minValue = min;
  maxValue = max;
  slider_start_value = start_val;
}

void Slider::logic(sf::RenderWindow &window) {
  if (sf::Mouse::getPosition(window).x >= xCord &&
      sf::Mouse::getPosition(window).x <= xCord + axisWidth &&
      sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
      sf::Mouse::getPosition(window).x <= xCord + 200 &&
      sf::Mouse::getPosition(window).y <= yCord + 100) {
    slider.setPosition(sf::Mouse::getPosition(window).x, yCord);
    sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth *
                               (maxValue - minValue)));
  }
}

float Slider::getSliderValue() { return sliderValue; }

void Slider::setSliderValue(float newValue) {
  if (newValue >= minValue && newValue <= maxValue) {
    sliderValue = newValue;
    float diff = maxValue - minValue;
    float diff2 = newValue - minValue;
    float zzz = axisWidth / diff;
    float posX = zzz * diff2;
    posX += xCord;
    slider.setPosition(posX, yCord);
  }
}

void Slider::setSliderPercentValue(float newPercentValue) {
  if (newPercentValue >= 0 && newPercentValue <= 100) {
    sliderValue = newPercentValue / 100 * maxValue;
    slider.setPosition(xCord + (axisWidth * newPercentValue / 100), yCord);
  }
}

void Slider::draw(sf::RenderWindow &window) {
  logic(window);
  window.draw(returnText(xCord - 10, yCord + 5, std::to_string(minValue), 20));
  window.draw(axis);
  window.draw(returnText(xCord + axisWidth - 10, yCord + 5,
                         std::to_string(maxValue), 20));
  window.draw(slider);
  window.draw(returnText(slider.getPosition().x - sliderWidth,
                         slider.getPosition().y - sliderHeight,
                         std::to_string((float)sliderValue), 15));
}

void Slider::reset() {
  sliderValue = slider_start_value;
  slider.setPosition(slider_start, yCord);
}
