#include "StaticEntity.h"



void StaticEntity::update(){
    
}

void StaticEntity::draw(){
    image.draw(x,y,width,height);
}



bool StaticEntity::collides(Snake* snake){
    if (snake->getBounds().intersects(this->getBounds())){
        return true;
    } else {
        return false;
    }
    
}

//(snake->getHead()[0]*this->getWidth()) == (this->getX()) && (snake->getHead()[1]*this->getHeight()) == (this->getY())


