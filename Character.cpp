#include "Character.hpp"

Character::Character() : m_speedX(0), m_speedY(0), m_direction(LEFT) {

}

Character::Character(sf::Texture& texture) : m_speedX(0), m_speedY(0), m_direction(LEFT) {
  sf::Sprite::setTexture(texture);
}

void Character::move() {
  sf::Vector2f position = sf::Sprite::getPosition();
  position.x += m_speedX;
  position.y += m_speedY;

  sf::Sprite::setPosition(position);
}

void Character::update() {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    AnimatedSprite::setCurrentAnimation("down");

    m_speedY = SPEED;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    AnimatedSprite::setCurrentAnimation("up");

    m_speedY = -SPEED;
  } else {
    m_speedY = 0;
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    AnimatedSprite::setCurrentAnimation("left");
    m_speedX = -SPEED;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    AnimatedSprite::setCurrentAnimation("right");
    m_speedX = SPEED;
  } else {
    m_speedX = 0;
  }
  

  this->move();

  AnimatedSprite::update();

}