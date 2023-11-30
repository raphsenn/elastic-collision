#include "./sandbox.h"

SandBox::SandBox()
    : gravity(0.0, 0.0), slider_gravity_x(50, 70, true),
      slider_gravity_y(300, 70, true), slider_restitution(550, 70, false),
      restart_button(850, 0) {

  // width and height for window
  WIDTH = 1000;
  HEIGHT = 800;

  // width and height for simulation box
  SIMWIDTH = WIDTH - 50; // border right 50 pixel between simwall and window screen
  SIMHEIGHT = HEIGHT - 50; // border at the bottom 50 pixel between simwall and winodw screen

  dt = 1.0 / 60.0; // simulation speed
  restitution = 1.0; // ratio of the relative velocity of seperation after collision

  // load relevant fonts
  if (!font.loadFromFile("fonts/monitorica.ttf"))
    printf("Error loading font\n");

  // declare sliders, to manipulate gravity and restitution
  slider_gravity_x.create(-5, 5, 0.0);
  slider_gravity_y.create(-5.0, 5.0, 0.0);
  slider_restitution.create(1.0, 0.0, 1.0);

  // declare restart button
  restart_button.create("Restart", font);

  numberOfBalls = 40;
  for (size_t ball_i = 0; ball_i < numberOfBalls; ball_i++) {
    double ballRadius = getRandomRadius(); // create ball radius
    double ballMass = M_PI * ballRadius * ballRadius; // mass in kg
    Vector2 ballPosition = getRandomVector(SIMWIDTH, SIMHEIGHT);   // create ball position vector
    Vector2 ballVelocity = getRandomVelocity(); // create ball velocity vector
    sf::Color ballColor = getRandomColor();     // create ball color
    Ball ball(ballRadius, ballMass, ballPosition, ballVelocity, ballColor);  // create ball
    balls.push_back(ball); // add ball to the ball list
  }
  // words to draw on window
  words = {"gravity.x", "gravity.y", "restitution"};
}

void SandBox::draw(sf::RenderWindow &window) {
  // create simulation box lines
  sf::Vertex lines[] = {
      sf::Vertex(sf::Vector2f(50, 100)),  // Line 1 start (top)
      sf::Vertex(sf::Vector2f(950, 100)), // Line 1 end

      sf::Vertex(sf::Vector2f(50, 750)),  // Line 2 start (bottom)
      sf::Vertex(sf::Vector2f(950, 750)), // Line 2 end

      sf::Vertex(sf::Vector2f(50, 100)), // Line 3 start (left)
      sf::Vertex(sf::Vector2f(50, 750)), // Line 3 end

      sf::Vertex(sf::Vector2f(950, 100)),  // Line 4 start (right)
      sf::Vertex(sf::Vector2f(950, 750))}; // Line 4 end

  // draw balls
  for (size_t balli = 0; balli < balls.size(); balli++) {
    Ball ball = balls[balli];
    sf::CircleShape ball_shape(ball.radius);
    ball_shape.setFillColor(ball.color);
    ball_shape.setPosition(ball.position.x - ball.radius, ball.position.y - ball.radius);
    window.draw(ball_shape);
  }
  // draw lines
  window.draw(lines, 8, sf::Lines);

  // draw text
  int word_x = 50;
  int word_y = 0;
  for (size_t wordi = 0; wordi < words.size(); wordi++) {
    sf::Text word;
    word.setFont(font);
    word.setString(words[wordi]);
    word.setCharacterSize(30);
    word.setPosition(word_x, word_y);
    window.draw(word);
    word_x += 250;
  }
}

void SandBox::simulate() {
  for (size_t ball_index = 0; ball_index < balls.size(); ball_index++) {
    balls[ball_index].simulate(gravity, dt);

    for (size_t ball2_index = ball_index + 1; ball2_index < balls.size(); ball2_index++) {
      collisionBallToBall(balls[ball_index], balls[ball2_index], restitution);
    }
    collisionToWall(balls[ball_index]);
  }
}

void SandBox::collisionToWall(Ball &ball) {
  // Check collision with top wall
  if (ball.position.x < ball.radius + 50) {
    ball.position.x = ball.radius + 50;
    ball.velocity.x = -ball.velocity.x;
  }
  // Check collision with bottom wall
  if (ball.position.x > SIMWIDTH - 1 * ball.radius) {
    ball.position.x = SIMWIDTH - 1 * ball.radius;
    ball.velocity.x = -ball.velocity.x;
  }
  // Ceck collision with left wall
  if (ball.position.y <  ball.radius + 100) {
    ball.position.y = ball.radius + 100;
    ball.velocity.y = -ball.velocity.y;
  }
  // Check collision with right wall
  if (ball.position.y > SIMHEIGHT - 1 * ball.radius) {
    ball.position.y = SIMHEIGHT - 1 * ball.radius;
    ball.velocity.y = -ball.velocity.y;
  }
}

void SandBox::collisionBallToBall(Ball &ball_1, Ball &ball_2, double restitution) {
  Vector2 direction(0.0, 0.0);
  direction.subVectors(ball_2.position, ball_1.position); // new direction after collision
  double direction_length = direction.length(); // length of direction

  if (direction_length == 0.0 || direction_length > ball_1.radius + ball_2.radius) {
    return; // no collision
  }
  
  direction.scaleVector(1.0 / direction_length); // normalize direction vector
  
  double corr = (ball_1.radius + ball_2.radius - direction_length) / 2.0;
  ball_1.position.add(direction, -corr);
  ball_2.position.add(direction, corr);

  double v1 = ball_1.velocity.dot(direction);
  double v2 = ball_2.velocity.dot(direction);

  double m1 = ball_1.mass;
  double m2 = ball_2.mass;

  double newV1 = (m1 * v1 + m2 * v2 - m2 * (v1 - v2) * restitution) / (m1 + m2);
  double newV2 = (m1 * v1 + m2 * v2 - m1 * (v2 - v1) * restitution) / (m1 + m2);

  ball_1.velocity.add(direction, newV1 - v1);
  ball_2.velocity.add(direction, newV2 - v2);
}

void SandBox::update(sf::RenderWindow &window) {
  window.clear();
  simulate();
  draw(window);
  slider_gravity_x.draw(window);
  slider_gravity_y.draw(window);
  slider_restitution.draw(window);
  restart_button.draw(window);
  user_input(window);
  window.display();
}

void SandBox::user_input(sf::RenderWindow &window) {
  gravity.x = slider_gravity_x.getSliderValue();
  gravity.y = slider_gravity_y.getSliderValue();
  restitution = slider_restitution.getSliderValue();
  if (restart_button.checkClick(window) == true) {
    reset();
  }
}

void SandBox::run() {
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Elastic collision - physics simulation");
  // standard sfml window loop 
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    update(window);
  }
}

void SandBox::reset() {
  // reset sliders, gravity and restitution 
  slider_gravity_x.reset();
  slider_gravity_y.reset();
  slider_restitution.reset();
  gravity = Vector2(0.0, 0.0);
  restitution = 1.0;

  // delete every ball in balls
  balls.clear();
  numberOfBalls = 40;
  
  // create new balls
  for (size_t ball_i = 0; ball_i < numberOfBalls; ball_i++) {
    double ballRadius = getRandomRadius(); // create ball radius
    Vector2 ballPosition = getRandomVector(SIMWIDTH, SIMHEIGHT);   // create ball position vector
    Vector2 ballVelocity = getRandomVelocity(); // create ball velocity vector
    sf::Color ballColor = getRandomColor();     // create ball color
    Ball ball(ballRadius, 1.0, ballPosition, ballVelocity, ballColor);  // create ball
    balls.push_back(ball); // add ball to balls vector
  }
}
