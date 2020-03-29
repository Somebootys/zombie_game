#include "main.h" 
#include "Zombie.h" 
#include "TextureHolder.h" 
#include <stdlib.h> 
#include <time.h> 
#include<math.h>

Zombie* createHorde(int numZombies, sf::IntRect arena)
{
  Zombie* zombies = new Zombie[numZombies];
  int maxY = arena.height - 20;
  int minY = arena.top +20; 
  int maxX = arena.width +20; 
  int minX = arena.width -20;
  
  for (int i = 0; i < numZombies;i ++ )
  {
    //which side of the arena should the zombies spawn 
    srand((int)std::time(0)*i);
    int side = (rand() % 4 );
    float x, y;
    switch (side)
    {
      case 0: 
         // left 
         x = minX; 
         y = (rand() % maxY) + minY; 
         break; 
 
      case 1: 
         // right 
         x = maxX; 
         y = (rand() % maxY) + minY; 
         break; 
 
      case 2: 
         // top 
         x = (rand() % maxX) + minX; 
         y = minY; 
         break; 
 
      case 3: 
         // bottom 
         x = (rand() % maxX) + minX; 
         y = maxY; 
         break; 
    }
    // zoomer, crawler or boomer
    srand((int)std::time(0)*i*2);
    int type = (rand()%3);
    
    //spawn the new zombies into the array
    zombies[i].spawn(x,y,type,i);
    
  }
  return zombies;
}