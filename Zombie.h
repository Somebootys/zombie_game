#pragma once
#include<SFML/Graphics.hpp>


class Zombie
{
private:
// setting the speed of the different zombies 
const float ZOOMER_SPEED = 80 ;
const float CRAWLER_SPEED = 20 ;
const float BOOMER_SPEED = 30 ;


// Zombie health
const float ZOOMER_HEALTH = 1 ;
const float CRAWLER_HEALTH = 3 ;
const float BOOMER_HEALTH = 5 ;
// Make each zombie vary its speed slightly 
const int MAX_VARRIANCE = 30; 
const int OFFSET = 101 - MAX_VARRIANCE;

//zombie's position 
sf::Vector2f m_Postion;

//Zombie sprite 
sf::Sprite m_Sprite;

//Zombie movement speed and health   
float m_Speed;
float m_Health;


//Zombies dead/alive 
bool m_Alive;
//Zombie hit or not
bool hit();

// determine if zombie is dead or alive 
bool isAlive();

//spawn new Zombiies
void spawn(float startX, float startY, int type, int seed);

//return the hitbox
sf::FloatRect getPosition();

//get copy of sprite to draw 
sf::Sprite getSprite();

//Update the zombie each frame 
void update(float elapsedTime, sf::Vector2f playerLocation);

};


}