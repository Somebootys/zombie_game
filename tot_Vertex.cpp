#include<SFML/Graphics.hpp>
// Create a vertex array 
sf::VertexArray background; 
// What primitive type are we using 
background.setPrimitiveType(Quads); 
// Set the size of the vertex array 
background.resize(10 * 10 * 4); 


// Position each vertex in the current quad
background[0].position=sf::Vector2f(0,0);
background[1].position=sf::Vector2f(49,0);
background[2].position=sf::Vector2f(49,49);
background[3].position=sf::Vector2f(0,49);  

// Set the texture coordinate of each vertex
background[0].texCoords = sf::Vector2f(0,0)  ;
background[1].texCoords = sf::Vector2f(49,0);
background[2].texCoords = sf::Vector2f(49,49);
background[3].texCoords = sf::Vector2f(0,49) ;

// set the texture coordinates of each vertex
background[0].texCoords = sf::Vector2f(0,50);
background[1].texCoords = sf::Vector2f(49,50);
background[2].texCoords = sf::Vector2f(49,99);
background[3].texCoords = sf::Vector2f(0,99);

// Load the texture for our background vertex array 
sf::Texture textureBackground;
textureBackground.loadFromFile("graphics/background_sheet.png")

//Draw teh texturebackground 
window.draw(background, &textureBackground);