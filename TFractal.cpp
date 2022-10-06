#include <iostream>
#include "Triangle.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

int main (int argc, char* argv[]) {
  char* string1 = argv[1];
  char* string2 = argv[2];
  double L; //side length of base triangle
  int N; //depth of recursion
  string::size_type sz, sz2;
  L = stod(string1, &sz);
  N = stoi(string2, &sz2);
  
  sf::RenderWindow window(sf::VideoMode(600, 600), "Sierpinski Triangles");

  window.setFramerateLimit(60);

  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();
    fTree(window, L, N, 0, 300-L/2, 300-L/2);
  }
  return 0;
}
