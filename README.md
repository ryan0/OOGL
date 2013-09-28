OOGL
====
OOGL is a simple and easy to use C++ library for 2d graphics. It consists of classes which wrap
opengl calls in simple methods hiding implementaton from the user. OOGL also asists in loading textures 
and 2d models. OOGL does not have any functionality for creating windows or an opengl context so the
user must create a window themselves or use a library such as GLFW, SDL, SFML, etc.

Example
=======

#include <oogl.h>
#include <iostream>

int main()
{
    ... //create window
    
    if(!ooglInit()) 
    {   
        std::cout<<"error setting up oogl";
        return 1;
    }
    
    oogl::Texture tex("fileLocation");
    oogl::Model model(oogl::Vec2(), 1);
    oogl::Entity entity(model, tex, NORMAL);
    
    while(program is running)
    {
        oogl::Entity::drawAll();
        
        ...
        //swap windows buffers, poll events, etc.
    }
    
    ooglEnd();
}


Resouces
========
OOGL uses GLEW and SOIL
