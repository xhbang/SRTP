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
   
 Game *game_new(void)  
 {  
     Game *g = new Game;  
     char home[512];  
     passwd *pwd;  
       
     memset(home,0,512);  
     pwd = getpwuid(getuid());  
     strcpy(home,pwd->pw_dir);  
     if(home[strlen(home)-1]!='/') strcat(home,"/");  
     strcat(home,".consnake");  
       
       
     g->toplist = new Toplist(home);  
     g->snake = new Snake(SNAKE_STARTSIZE);  
     memset(g->name,0,100);  
     g->delay = SNAKE_STARTDELAY;  
     g->points = 0;  
     return g;  
 }  
   
 int game_end(Game *g)  
 {  
     delete g->toplist;  
     delete g->snake;  
     delete g;  
 }  
   
 int game_reset(Game *g)  
 {  
     delete g->snake;  
     g->snake = new Snake(SNAKE_STARTSIZE);  
     g->delay = SNAKE_STARTDELAY;  
     g->points = 0;  
     return 0;  
 }  
   
 int game_main_loop(Game *g)  
 {  
     game_new_snack(g);  
     clear();  
     refresh();  
     draw_status_window(g);  
     fcntl(1,F_SETFL,fcntl(1,F_GETFL)|O_NONBLOCK);  
     while(!game_check_gameover(g))  
     {  
         char key = getchar();  
         switch(key)  
         {  
         case 'w':  
             g->snake->Direction(SNAKE_UP);  
             break;  
         case 's':  
             g->snake->Direction(SNAKE_DOWN);  
             break;  
         case 'a':  
             g->snake->Direction(SNAKE_LEFT);  
             break;  
         case 'd':  
             g->snake->Direction(SNAKE_RIGHT);  
             break;  
         }  
               
         g->snake->Tick();  
         game_check_snack_eaten(g);  
         draw_game_window(g);  
         usleep(g->delay*1000);  
     }  
     fcntl(1,F_SETFL,fcntl(1,F_GETFL)&(~O_NONBLOCK));  
     getchar();  
     clear();  
     refresh();  
     g->toplist->Update(g->name,g->points);  
     draw_toplist_window(g);  
     getchar();  
     clear();  
     refresh();  
 }  
   
 int game_check_gameover(Game *g)  
 {  
     int hx, hy;  
     g->snake->GetHeadPosition(hx,hy);  
     for(SnakeUnit *temp = g->snake->GetSnakeUnit();temp->next;temp = temp->next)  
         if((temp->x == hx)&&(temp->y == hy))  
             return 1;  
       
     if((hx < 1)||(hy < 1))  
             return 1;  
       
     if((hx >= (GAMEWINDOW_WIDTH-1))||(hy >= (GAMEWINDOW_HEIGHT-1)))  
         return 1;  
       
     return 0;  
 }  
   
 int game_new_snack(Game *g)  
 {  
     int sx,sy;  
     bool isOK = 0;  
     while(!isOK)  
     {  
         sx = (int)((rand()/(RAND_MAX*1.0)) * (GAMEWINDOW_WIDTH - 3));  
         sy = (int)((rand()/(RAND_MAX*1.0)) * (GAMEWINDOW_HEIGHT - 3));  
         sx++;  
         sy++;  
         isOK = 1;  
         for(SnakeUnit *temp = g->snake->GetSnakeUnit();temp;temp=temp->next)  
         {  
             if((temp->x == sx) && (temp->y == sy))  
                 isOK = 0;  
         }  
     }  
     g->snack.x = sx;  
     g->snack.y = sy;  
       
     int rnd = (int)((rand()/(RAND_MAX*1.0)) * 10);  
     switch(rnd)  
     {  
     case 0:  
     case 5:  
         g->snack.type = SNACK_GROW;      //grow  
         break;  
     case 1:  
     case 6:  
         if(g->delay > 100)  
             g->snack.type = SNACK_FASTER;        //faster  
         else  
             g->snack.type = SNACK_GROW;      //wachsen  
         break;  
     default:  
         g->snack.type = SNACK_POINTS;        //points  
         break;  
     }  
     draw_status_window(g);  
     return 0;  
 }  
   
 int game_check_snack_eaten(Game *g)  
 {  
     int sx, sy;  
     g->snake->GetHeadPosition(sx,sy);  
     if((g->snack.x == sx)&&(g->snack.y == sy))  
     {  
         switch(g->snack.type)  
         {  
         case SNACK_POINTS:  
             g->points++;  
             break;  
         case SNACK_FASTER:  
             g->delay-=20;  
             break;  
         case SNACK_SLOWER:  
             g->delay+= 20;  
             break;  
         case SNACK_GROW:  
             g->snake->Grow();  
             break;  
         case SNACK_SHRINK:  
             g->snake->Shrink();  
             break;  
         }  
         game_new_snack(g);  
     }  
 }  