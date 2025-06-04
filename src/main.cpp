#include <iostream>
#include "game.hpp"



int main(int argc, char* argv[]) {
  Game app(800,600, "Dodge Multiplayer");
  app.start();
  return 0;
}
