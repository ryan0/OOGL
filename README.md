OOGL
====
OOGL is a simple and easy to use C++ library for 2d graphics. It consists of wrapper classes that
implement all necessary opengl calls hiding implementaton from the user. OOGL also loads textures 
with assistance from the SOIL library. OOGL does not have functionality for creating windows 
or an opengl context so the user must create a window, either themselves themselves or useing
a library such as GLFW, SDL, SFML, etc.

Example
=======
```
#include <oogl.hpp>

int main()
{
    ... //create window
    
    if(!gl::ooglInit()) 
    {   
        std::cout<<"error setting up oogl";
        return 1;
    }
    
    gl::Texture tex("file.png");
    gl::Entity entity(gl::Rectangle(), tex);
    
    while(program is running)
    {
        gl::clear();
		entity.draw();
        
        ...
        //display what was rendered/swap window buffers
    }
    
    gl::ooglTerminate();
}
```

Resouces
========
OOGL uses the libraries GLEW and SOIL
