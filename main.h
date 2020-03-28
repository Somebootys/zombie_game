#pragma once
#include<SFML/Graphics.hpp>
int createBackground(sf::VertexArray& rVA, sf::IntRect arena);
Zombie* createHorde(int numZombies, sf::IntRect arena);