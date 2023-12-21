#pragma once
#include "Entity.h"
#include "Snake.h"


class StaticEntity : public Entity {
    protected:
        int x, y, width, height, health;
        ofImage image;


    
    public:
        StaticEntity(int x, int y, int width, int height, ofImage image){
            this->x = x;
            this->y = y;
            this->width = width;
            this->height = height;
            this->image = image;
        }
        // ~StaticEntity();

        void update();
        void draw();

        bool collides(Snake *snake);


        int getX() { return x; }
        int getY() { return y; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        void setY(int y) { this->y = y; }
        void setX(int x) { this->x = x; }

        ofRectangle getBounds(){
            return ofRectangle(this->x, this->y, this->width, this->height);
        }


};