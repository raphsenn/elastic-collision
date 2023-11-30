#ifndef RANDOM_H
#define RANDOM_H
#include <tuple>
#include <vector>
#include <random>
#include "./SFML/Graphics.hpp"
#include "./vector2.h"

sf::Color getRandomColor(); // returns a random sfml sf::Color, you can add more colors if you like.
Vector2 getRandomVector(double maxX, double maxY); // returns a random Vector2 between given pixels
Vector2 getRandomVelocity(); // returns a random Vector2 (x, y) with 0 < x < 1, and y  < 1, and y 
double getRandomRadius(); // reutrn a random radius
#endif // RANDOM_H
