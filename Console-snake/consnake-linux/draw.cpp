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
   
 WINDOW *gameWindow = NULL;  
 WINDOW *statusWindow = NULL;  
 WINDOW *toplistWindow = NULL;  
   
 int draw_init(void)  
 {  
     initscr();  
     gameWindow = newwin(GAMEWINDOW_HEIGHT,GAMEWINDOW_WIDTH,0,0);  
     statusWindow = newwin(STATUSWINDOW_HEIGHT,GAMEWINDOW_HEIGHT,0,GAMEWINDOW_WIDTH+1);  
     toplistWindow = newwin(TOPLIST_HEIGHT,TOPLIST_WIDTH,0,0);  
     return 0;  
 }  
   
 int draw_deinit(void)  
 {  
     if(gameWindow) delwin(gameWindow);  
     if(statusWindow) delwin(statusWindow);  
     if(toplistWindow) delwin(toplistWindow);  
     gameWindow = NULL;  
     statusWindow = NULL;  
     toplistWindow = NULL;  
     endwin();  
     return 0;  
 }  
   
 int draw_start_window(Game *g)  
 {  
     clear();  
     printw("\  
 Consnake (C) 2008 Wurzer Roland\n\  
 This program comes with ABSOLUTELY NO WARRANTY.\n\n\  
 Dein Name: ");  
     refresh();  
     scanw("%s",g->name);  
     if(strlen(g->name)==0)  
     {  
         strcpy(g->name,"Anonym");  
     }  
     clear();  
     refresh();  
 }  
   
 int draw_game_window(Game *g)  
 {  
     wclear(gameWindow);  
     wborder(gameWindow,'|','|','-','-','+','+','+','+');  
       
     mvwaddch(gameWindow,g->snack.y,g->snack.x,'O');  
       
     for(SnakeUnit *temp = g->snake->GetSnakeUnit();temp;temp=temp->next)  
         mvwaddch(gameWindow,temp->y,temp->x,'*');  
       
     mvwaddch(gameWindow,0,0,'+');  
     wrefresh(gameWindow);  
 }  
   
 int draw_status_window(Game *g)  
 {  
     wclear(statusWindow);  
     wborder(statusWindow,'|','|','-','-','+','+','+','+');  
     mvwprintw(statusWindow,1,7,"Status");  
     mvwprintw(statusWindow,3,1,"Name: %s",g->name);  
     mvwprintw(statusWindow,4,1,"Punkte: %d",g->points);  
     mvwprintw(statusWindow,5,1,"Speed: %d",SNAKE_STARTDELAY - g->delay);  
       
     char *snack_type[] = {  
             "Snack: Punkte",  
             "Snack: schneller",  
             "Snack: langsamer",  
             "Snack: wachsen",  
             "Snack: schrumpfen",  
     };  
           
     mvwprintw(statusWindow,6,1,"%s",snack_type[g->snack.type]);  
       
     int sx,sy;  
     mvwaddch(statusWindow,0,0,'+');  
     wrefresh(statusWindow);  
 }  
   
 int draw_toplist_window(Game *g)  
 {  
     wclear(toplistWindow);  
     wborder(toplistWindow,'|','|','-','-','+','+','+','+');  
     mvwprintw(toplistWindow,1,22,"Top 10");  
       
     int y = 2;  
     ToplistUnit *tlu = g->toplist->GetToplistUnit();  
     while(tlu)  
     {  
         y++;  
         char cache[200];  
         sprintf(cache,"%d. %s (%d Punkte)",y-2,tlu->name,tlu->points);  
         mvwprintw(toplistWindow,y,TOPLIST_WIDTH/2-strlen(cache)/2,cache);  
         tlu=tlu->next;  
     }  
       
     wrefresh(toplistWindow);  
 }  
   