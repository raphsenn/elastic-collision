#include "./random.h"

sf::Color getRandomColor() {
  std::vector<sf::Color> colors;
  colors.push_back(sf::Color(30, 144, 255)); // babyblue
  colors.push_back(sf::Color(136, 0, 255));  // lila <3

  int randomIndex = rand() % colors.size();

  return colors[randomIndex];
}

Vector2 getRandomVector(double maxX, double maxY) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distribX(50, maxX);
  std::uniform_real_distribution<double> distribY(100, maxY);

  double randomX = distribX(gen);
  double randomY = distribY(gen);
  return Vector2(randomX, randomY);
}

Vector2 getRandomVelocity() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distrib(-3.0, 3.0);

  double randomX = distrib(gen);
  double randomY = distrib(gen);

  return Vector2(randomX, randomY);
}

double getRandomRadius() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0, 4);
  int randomIndex = distrib(gen);
  if (randomIndex <= 0) {
    return 20.0;
  }
    return 30.0;
}
