#include "./ball.h"

// Constructor
Ball::Ball(double rad, double m, Vector2 pos, Vector2 vel, sf::Color col)
    : radius(rad), mass(m), position(pos), velocity(vel), color(col) {}

void Ball::simulate(Vector2 gravity, double dt) {
  velocity.add(gravity, dt);
  position.add(velocity, dt);
}
