 /**************************************************************************** 
  * Copyright (C) 2008 Wurzer Roland                                         * 
  *                                                                          * 
  * Consnake is free software: you can redistribute it and/or modify         * 
  * it under the terms of the GNU General Public License as published by     * 
  * the Free Software Foundation, either version 3 of the License.           * 
  *                                                                          * 
  * Consnake is distributed in the hope that it will be useful,              * 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of           * 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            * 
  * GNU General Public License for more details.                             * 
  *                                                                          * 
  * You should have received a copy of the GNU General Public License        * 
  * along with Consnake.  If not, see <http: www.gnu.org="" licenses="">.        * 
  * *************************************************************************/  
   
 #include "consnake.h"  
   
 Snake::Snake(int size)  
 {  
     grow = FALSE;  
     shrink = FALSE;  
     snake_unit = NULL;  
       
     for(int x=size;x>0;x--)  
     {  
         SnakeUnit *temp = new SnakeUnit;  
         temp->x = x;  
         temp->y = 1;  
         temp->next = snake_unit;  
         temp->direction = SNAKE_RIGHT;  
         snake_unit = temp;  
     }  
 }  
   
 Snake::~Snake(void)  
 {  
     while(snake_unit)  
     {  
         SnakeUnit *temp = snake_unit->next;  
         delete snake_unit;  
         snake_unit = temp;  
     }  
 }  
   
 SnakeUnit* Snake::GetSnakeUnit(void)  
 {  
     return snake_unit;  
 }  
   
 int Snake::Tick(void)  
 {  
     SnakeUnit *new_snake_unit = NULL;  
       
     if(shrink && grow)  
     {  
         shrink = 0;  
         grow = 0;  
     }  
     if(shrink && snake_unit->next)  
     {  
         shrink = 0;  
         SnakeUnit *temp = snake_unit->next;  
         delete snake_unit;  
         snake_unit = temp;  
     }  
     if(grow)  
     {  
         grow = 0;  
         new_snake_unit = new SnakeUnit;  
         new_snake_unit->direction = snake_unit->direction;  
         new_snake_unit->x = snake_unit->x;  
         new_snake_unit->y = snake_unit->y;  
     }  
       
     //alle in die entsprechende richtung verschieben und direction neu bestimmen  
     for(SnakeUnit *temp = snake_unit;temp;temp = temp->next)  
     {  
         switch(temp->direction)  
         {  
         case SNAKE_UP:  
             temp->y--;  
             break;  
         case SNAKE_DOWN:  
             temp->y++;  
             break;  
         case SNAKE_LEFT:  
             temp->x--;  
             break;  
         case SNAKE_RIGHT:  
             temp->x++;  
             break;  
         }  
         if(temp->next)  
             temp->direction = temp->next->direction;  
     }  
       
     if(new_snake_unit)  
     {  
         new_snake_unit->next = snake_unit;  
         snake_unit = new_snake_unit;  
     }  
     return 0;  
 }  
   
 int Snake::Grow(void)  
 {  
     grow = 1;  
     return 0;  
 }  
   
 int Snake::Shrink(void)  
 {  
     shrink = 1;  
     return 0;  
 }  
   
 int Snake::Direction(SnakeDirection newDirection)  
 {  
     SnakeUnit *temp = snake_unit;  
     while(temp->next)  
         temp=temp->next;  
     switch(newDirection)  
     {  
     case SNAKE_RIGHT:  
         if(temp->direction != SNAKE_LEFT)  
             temp->direction = newDirection;  
         break;  
     case SNAKE_LEFT:  
         if(temp->direction != SNAKE_RIGHT)  
             temp->direction = newDirection;  
         break;  
     case SNAKE_UP:  
         if(temp->direction != SNAKE_DOWN)  
             temp->direction = newDirection;  
         break;  
     case SNAKE_DOWN:  
         if(temp->direction != SNAKE_UP)  
             temp->direction = newDirection;  
         break;  
     }  
     return 0;  
 }  
   
 int Snake::GetHeadPosition(int &x, int &y)  
 {  
     SnakeUnit *temp = snake_unit;  
     while(temp->next)  
         temp = temp->next;  
     x = temp->x;  
     y = temp->y;  
 }  