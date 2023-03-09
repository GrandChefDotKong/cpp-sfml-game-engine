#include <SFML/Graphics.hpp>
#include "Character.hpp"

int main() {

  sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML works!");
  window.setFramerateLimit(60);
  sf::Texture texture;
  texture.loadFromFile("link.png");

  Character link;
  link.setTexture(texture);
  link.setPosition(500, 300);
  link.scale(sf::Vector2f(5, 5));
  
  Animation animation_1 = Animation(texture);
  animation_1.setIsLoop(true);
  animation_1.setInterval(sf::milliseconds(100));
  animation_1.addFrames(10, sf::IntRect(15, 76, 20, 32), 32, 0);

  Animation animation_2 = Animation(texture);
  animation_2.setIsLoop(true);
  animation_2.setInterval(sf::milliseconds(100));
  animation_2.addFrames(10, sf::IntRect(348, 76, 23, 32), 32, 0);

  Animation animation_3 = Animation(texture);
  animation_3.setIsLoop(true);
  animation_3.setInterval(sf::milliseconds(100));
  animation_3.addFrames(10, sf::IntRect(683, 76, 20, 32), 32, 0);
  
  Animation animation_4 = Animation(texture);
  animation_4.setIsLoop(true);
  animation_4.setInterval(sf::milliseconds(100));
  animation_4.addFrames(10, sf::IntRect(348+23, 76, -23, 32), 32, 0);

  link.addAnimation("down", animation_1);
  link.addAnimation("left", animation_2);
  link.addAnimation("up", animation_3);
  link.addAnimation("right", animation_4);

  link.setCurrentAnimation("left");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }  
    }

    link.update();

    window.clear(sf::Color::White);
    window.draw(link);
    window.display();
  
  }

  return 0;
}
