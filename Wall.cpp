#include "Wall.h"

Wall::Wall(int size, int width, int height)
{
    wallSize = size;
    int maxParts = rand()%(20-10+1)+10;
    
    int direction;
    int x=width/size/2, y=height/size/2;
    
    //First part on center
    parts.push_back(Vector2f(x*size, y*size));
    
    for(int i = 1; i < maxParts; i++)
    {
        //Decide about direction of new part
        direction = (rand()%4)+1;
        
        switch(direction)
        {
            //Up
            case 1:
               y--;
               
               if(y < 1)
                   y=height/size - 2;
            break;
            
            //Down
            case 2:
                y++;
                
                if(y >= height/size - 2)
                    y = 1;
            break;
            
            //Left
            case 3:
                x--;
                
                if(x < 1)
                    x = width/size - 2;
            break;
            
            //Right
            case 4:
                x++;
                
                if(x >= width/size - 2)
                    x = 1;
            break;
        }
        parts.push_back(Vector2f(x*size,y*size));
    }
    
    wall.setSize(Vector2f(size,size));
    wall.setFillColor(Color::Cyan);
}

//Check if given point collide with wall
bool Wall::isCollision(int x, int y)
{
    for(int i = 0; i < parts.size(); i++)
        if(parts[i].x/wallSize == x && parts[i].y/wallSize == y)
            return true;
        
    return false;
}

void Wall::drawWall(sf::RenderWindow& window)
{
    for(int i = 0; i < parts.size(); i++)
    {
        wall.setPosition(parts[i]);
        window.draw(wall);
    }
}
