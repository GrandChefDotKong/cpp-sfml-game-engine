#ifndef ANIMATEDSPRITE_INCLUDE
#define ANIMATIONSPRITE_INCLUDE

  #include <vector>
  #include <map>
  #include <string>
  #include <SFML/Graphics.hpp>
  #include <SFML/System/Time.hpp>
  #include <SFML/System/Clock.hpp>
  #include "Animation.hpp"

class AnimatedSprite: public sf::Sprite {
  public:
    AnimatedSprite();
    AnimatedSprite(const sf::Texture& texture);
    void addAnimation(std::string animationName, 
      Animation& animation
    );

    const std::string getCurrentAnimation();
    void setCurrentAnimation(std::string animationName);
    void update();

  private:
    std::map<std::string, Animation*> m_animations;
    std::string m_currentAnimation; 

};

#endif