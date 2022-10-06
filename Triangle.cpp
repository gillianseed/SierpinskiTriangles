//class defintion
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Triangle.hpp"
#include <cmath>

using namespace std;

Triangle::Triangle(double sideLength) {
  length = sideLength;
  triangle.setRadius(sideLength);
  triangle.setPointCount(3);
}

void Triangle::setPosition(double x, double y) {
  triangle.setPosition(x, y);
}

void Triangle::setRadius(double l) {
  radius = (sqrt(l*l-(l*l)/4))/2;
}

double Triangle::getRadius() {
  return radius;
}

void Triangle::setFillColor(double a, double b, double c) {
  triangle.setFillColor(sf::Color((int)a, (int)b, (int) c));
}

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(triangle);
}

void fTree(sf::RenderWindow& window, double len, int depth, int i, double centerX, double centerY) { //function call must set i = 0 and centerX to middle and centerY to 0
  if (i == depth) return;
  //
  // create a Triangle object and set side length
  //Triangle& tri(len);

  
  /**if (i == 0) {
    Triangle tri(len); //may be wrong
     tri.setPosition(centerX, centerY);
     window.draw(tri);
     }**/
  //else {
    Triangle *tri = new Triangle(len);
    tri->setRadius(len);
    //tri->setPosition(centerX - tri->getRadius(), centerY - tri->getRadius());
    tri->setPosition(centerX - len/2, centerY - len/2);
    tri->setFillColor(centerX/2, centerX/2, centerY/2);
    window.draw(*tri);
    window.display();
    double rad = tri->getRadius();
    //}
    //delete tri;
  //tri.setPosition(centerX-length/2, centerY-length/2);
  //tri.setPosition(centerX, centerY); //this is the correct one
  //tri->setPosition(centerX, centerY);
  //window.draw(tri);
  if (depth > 1) {
    i++;
    fTree(window, len/2, depth, i, centerX - len, centerY + len/2); //this is where error occurs
    //maybe set back to original length
    fTree(window, len/2, depth, i, centerX + len/2 + len/8, centerY - len);
    fTree(window, len/2, depth, i, centerX + len+len/8, centerY + len+len/8);
    //maybe set back to original length
    //fTree(window, len/2, depth, i++, centerX+len/2, centerY-len/2);
  }
  // draw triangle and
  // 
  //recursively call fTree(length/2, depth, i++); or until there are 3^depth-1 triangles drawn
  }
