#include "./vector2.h"

Vector2::Vector2(double init_x, double init_y) : x(init_x), y(init_y) {}

Vector2 Vector2::add(Vector2 v, double s) {
  x += v.x * s;
  y += v.y * s;
  return Vector2(x, y);
}

Vector2 Vector2::sub(Vector2 v, double s) {
  x -= v.x * s;
  y -= v.y * s;
  return Vector2(x, y);
}

Vector2 Vector2::addVectors(Vector2 v, Vector2 w) {
  x = v.x + w.x;
  y = v.y + w.y; 
  return Vector2(x, y);
}

Vector2 Vector2::subVectors(Vector2 v, Vector2 w) {
  x = v.x - w.x;
  y = v.y - w.y;
  return Vector2(x, y);
}

Vector2 Vector2::scalarMultVector(Vector2 v, double lambda) {
  return Vector2(lambda * v.x, lambda * v.y);
}

void Vector2::scaleVector(double lambda) {
  x *= lambda;
  y *= lambda;
}

double Vector2::length() { return sqrt(x * x + y * y); }

double Vector2::dot(Vector2 v) { return x * v.x + y * v.y; }

bool Vector2::operator==(Vector2 w) {
  double x_eq = std::abs(x - w.x);
  double y_eq = std::abs(y - w.y);
  if (x_eq < 1e-6 && y_eq < 1e-6) {
    return true;
  } else {
    return false;
  }
}
