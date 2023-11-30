#ifndef VECTOR2_H
#define VECTOR2_H
#include <cstdio>
#include <cmath>

class Vector2 {
  
  private:
  

  public:
    Vector2(double init_x, double init_y); // constructor
    double x; // x komponent of Vector2
    double y;  // y komponent of Vector2
    Vector2 addVectors(Vector2 v, Vector2 w); // adds two vectors
    Vector2 subVectors(Vector2 v, Vector2 w); // subtracts two vectors
    Vector2 add(Vector2 v, double s); // adds factor times vector komponent to the vector
    Vector2 sub(Vector2 v, double s); // subs factor times vector komponent to the vector
    void scaleVector(double lambda); // scale vector by factor lambda
    double dot(Vector2 v); // dotproduct between two vectors
    double length(); // returns euklidian length of the vector
    bool operator==(Vector2 w); // check if two vectors are the same
    Vector2 scalarMultVector(Vector2 v, double lambda); 
};
#endif // VECTOR2_H
