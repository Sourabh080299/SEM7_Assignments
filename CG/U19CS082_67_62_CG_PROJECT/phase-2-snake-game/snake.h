#include <graphics.h>

enum DIR {LEFT , UP , RIGHT , DOWN};       


struct POS
{
       int x,y;
       POS()
       {
            x = -50;
            y = 0;
       }
};

////// SNAKE CLASS //////
class snakeBody
{
private:
        POS arr[31];            
        int direction;         
        int length;             
public :
        snakeBody()
        {
              arr[0].x = 30;        
              arr[0].y = 30;        
              length = 2;           
              direction = RIGHT;    
        }
        void drawSnake();
        void appendSnake();         
        void changeDirTo(int);
        int update();
        int getPosx();             
        int getPosy();              
        int getlength();            

};

void snakeBody::drawSnake()         
{
     for(int i=0; i<length ; i++)
     {
          setcolor(BLUE);
          rectangle(arr[i].x , arr[i].y , arr[i].x+30 , arr[i].y+30);
          if(i==0)                                      
                  setfillstyle(SOLID_FILL , GREEN);
          else                                          
                  setfillstyle(SOLID_FILL , LIGHTGREEN);
          floodfill(arr[i].x+15 , arr[i].y+15 , BLUE);
     }
}

void snakeBody::appendSnake()
{
     if(length < 30)                            
        length++;
}

void snakeBody::changeDirTo(int newdir)
{
     if(newdir == LEFT || newdir == RIGHT)
     {
            if(direction == UP || direction == DOWN)
                         direction = newdir;
     }
     else if(newdir == UP || newdir == DOWN)
     {
            if(direction == LEFT || direction == RIGHT)
                         direction = newdir;
     }
}

int snakeBody::update()                                                     
{                                                                           
     for(int i=1 ; i<length ; ++i)                                          
     {                                                                      
             if(arr[0].x == arr[i].x && arr[0].y == arr[i].y)               // HENCE [1] GETS THE POSITION OF [0]
             {                                                              // [2] GETS THE POSITION OF [1] AND SO ON...
                         return 0;                                          // AND LASTLY HEAD([0]) IS GIVEN LATEST VALUES
             }
     }
     for(int i=length ; i>=0 ; --i)
     {
             if(i==0)
             {
                     arr[1].x = arr[0].x;
                     arr[1].y = arr[0].y;
             }
             else
             {
                     arr[i].x = arr[i-1].x;
                     arr[i].y = arr[i-1].y;
             }
     }
     if(direction == LEFT)
     {
                  arr[0].x -= 30;
                  if(arr[0].x == 0)
                  {
                              arr[0].x = 450;
                  }
     }
     else if(direction == RIGHT)
     {
                  arr[0].x += 30;
                  if(arr[0].x == 480)
                  {
                              arr[0].x = 30;
                  }
     }
     else if(direction == UP)
     {
                  arr[0].y -= 30;
                  if(arr[0].y == 0)
                  {
                              arr[0].y = 450;
                  }
     }
     else if(direction == DOWN)
     {
                  arr[0].y += 30;
                  if(arr[0].y == 480)
                  {
                              arr[0].y = 30;
                  }
     }
     return 1;
}

int snakeBody::getPosx()
{
    return arr[0].x;
}

int snakeBody::getPosy()
{
    return arr[0].y;
}

int snakeBody::getlength()
{
    return length;
}