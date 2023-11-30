#ifndef SANDBOX_H
#define SANDBOX_H
#include <vector>
#include <cstdio>
#include <cmath>
#include "./SFML/Graphics.hpp"
#include "./ball.h"
#include "./random.h"
#include "./slider.h"
#include "./button.h"

class SandBox {
  private:
    // application
    int WIDTH; // width of window
    int HEIGHT; // height of window
    int SIMWIDTH; // width for simulation box
    int SIMHEIGHT; // height for simulation box
    sf::Font font; // font for text
    std::vector<std::string> words; // array of words to plot in window
   
    // simulation 
    std::vector<Ball> balls; // list (array) of all balls
    Vector2 gravity; // gravity vector
    double restitution; // 0 < restitiution <= 1
    double dt; // simulation speed
    size_t numberOfBalls; // number of balls

    // user interface
    Slider slider_gravity_x; // manipulate gravity x vector
    Slider slider_gravity_y; // manipulate gravity y vector
    Slider slider_restitution; // manipulate restitution
    Button restart_button; // clickable text to restart the simulation

  public:
    SandBox(); // Constructor
    void simulate(); // simulates balls
    void collisionToWall(Ball& ball); // physics logic for ball to wall collision
    void collisionBallToBall(Ball& ball_1, Ball& ball_2, double restitution); // physics logic for ball to ball collision
    void run(); // main window loop, standard sfml
    void update(sf::RenderWindow& window); // update method
    void draw(sf::RenderWindow& window); // draw method
    void user_input(sf::RenderWindow& window); // checks user input, sliders, and buttons
    void reset(); // restarts the simulation
};
#endif // SANDBOX_H
