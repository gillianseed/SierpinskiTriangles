//header file
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

class Triangle : public sf::Drawable {
public:
  Triangle(double sideLength);
  void setPosition(double posx, double posy);
  void setRadius(double length);
  double getRadius();
  void setFillColor(double a, double b, double c);
  /**double getLength();
  double getCenterX();
  double getCenterY();**/
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  double length;
  double radius;
  //sf::CircleShape triangle(double l, double s); //maybe define in constructor
  sf::CircleShape triangle;
  sf::Texture texture;
};

void fTree(sf::RenderWindow& window, double len, int depth, int i, double x, double y);

#endif
