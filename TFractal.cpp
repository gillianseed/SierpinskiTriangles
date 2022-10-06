//mainc, recusrive function call
#include <iostream>
#include "Triangle.hpp"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

//void fTree(sf::RenderWindow& window, double len, int depth, int i, double x, double y);

int main (int argc, char* argv[]) {
  char* string1 = argv[1];
  char* string2 = argv[2];
  double L; //side length of base triangle
  int N; //depth of recursion
  string::size_type sz, sz2;
  L = stod(string1, &sz);
  N = stoi(string2, &sz2);

  //Triangle trii(50);

  //sf::CircleShape trii(L, 3);
  
  sf::RenderWindow window(sf::VideoMode(600, 600), "Sierpinski Triangles");

  window.setFramerateLimit(60);

  while(window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    window.clear();
    fTree(window, L, N, 0, 300-L/2, 300-L/2);
    //Triangle tri(L); //test
    //tri.setPosition(300, 300);
    //window.draw(tri);
    //window.draw(trii);


    //window.display();
  }
  
  //create window and call fTree(int depth)
  
  return 0;
}

/**void fTree(sf::RenderWindow& window, double len, int depth, int i, double x, double y) {
  if (i == depth) return;

  Triangle tri(len);
  tri.setPosition(centerX, centerY);
  window.draw(tri);
  if (depth > 1) {
    fTree(window, len/2, depth, i++, centerX, centerY-len/2);
    fTree(window, len/2, depth, i++, centerX-len/2, centerY+len/2);
    fTree(window, len/2, depth, i++, centerX+len/2, centerY-len/2);
  }
}
**/
