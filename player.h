#pragma once
#include <SFML/Graphics.hpp> 
#include<math.h>

class Player
{
  private:   
  const float START_SPEED = 200;   
  const float START_HEALTH = 100; 
  
  // Where is the player   
  sf:: Vector2f m_Position;   
 
  sf:: Sprite m_Sprite;   
  
  sf::Texture m_Texture;   

  // What is the screen resolution   
  sf::Vector2f m_Resolution;   

  // What size is the current arena   
  sf::IntRect m_Arena;   

  // How big is each tile of the arena   
  int m_TileSize;   

   
  //Movement 
  bool m_UpPressed;   
  bool m_DownPressed;   
  bool m_LeftPressed;   
  bool m_RightPressed;

  // player stat / variables 
  int m_Health;   
  int m_MaxHealth;    
  sf::Time m_LastHit;   
  float m_Speed;

public:
  Player();
  void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
  void resetPlayerStats();
  
  bool hit(sf::Time timehit);
  sf::Time getLastHitTime();
  
  sf::FloatRect getPosition();
  // Where is the center of the player
  sf::Vector2f getCenter();
  // what way is player facing
  float getRotation();
  
  //copy sprite to main function
  sf::Sprite getSprite();

  //Player movement functions
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  void stopLeft();
  void stopRight();
  void stopUp();
  void stopDown();

  //call this function once every frame
  void update(float elapsedTime, sf::Vector2i(mousePosition));

  //speed, health- bonus
  void upgradeSpeed();
  void upgradeHealth();

  void increaseHealth(int amount);

  int getHealth();

};
