
#include "zombie.h" 
#include "TextureHolder.h" 
#include <cstdlib> 
#include <ctime> 


void Zombie::spawn(flaot startX, float startY, int type, int seed)
{
switch (type)
  {
    case 0: 
    //Boomer
    m_Sprite = Sprite(TextureHolder::GetTexture(
    "graphics/boomer.png"));
    
    m_Speed = 40;
    m_Health = 5; 
    break; 
    
    case 1: 
    // zoomer
    m_Sprite(TextureHolder::GetTexture(
    "graphics/zoomer.png"))
    m_Speed = 70;
    m_Health =1 ;
    break;
    
    case 2:
    //Crawler
    m_Sprite = Sprite(textureHolder::GetTexture(
    "graphics/crawler"));
    
    m_Speed = 20;
    m_Health = 3; 
    break;
  }
  
  /* modify the speed so each zombie has different movement speed 
  but still within a certain range for the class*/
  //set seed 
  srand((int)time(0)*seed)
  
  float speed_Modifier = (rand()%MAX_VARIANCE) + OFFSET;
  
  speed_Modifier = speed_Modifier/100 ; // Now it is expressed as a fraction
  
  m_Speed *= speed_Modifier;
  
  //ini zombie location 
  
  m_Position.x = startX;
  m_Position.y = startY;
  
  //Set origin of zom pos to its center. 
  m_Sprite.setOrigin(25,25);
  
  //Set zom position 
  m_Sprite.setPosition(m_Position);

}

bool Zombie::isAlive()
{
  return m_Alive;
}

sf::FloatRect Zombie::getPosition()
{
  return m_Sprite.getGlobalBounds();
}

sf::Sprite Zombie::getSprite()
{
  return m_Sprite;
}

