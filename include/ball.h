#ifndef BALL_H
#define BALL_H
#include "./vector2.h"
#include "./SFML/Graphics.hpp"
#include "./random.h"

class Ball {
  private:
    // no private methods or attributes

  public:
    Ball(double rad, double m, Vector2 pos, Vector2 vel, sf::Color col); // Constructor
    double radius; // radius of ball
    double mass; // mass of ball
    Vector2 position; // 2d vector for current position
    Vector2 velocity; // 2d vector for current velocity and direction
    sf::Color color; // color of ball
    void simulate(Vector2 gravity, double dt); // simulate ball movement
};
#endif // BALL_H
