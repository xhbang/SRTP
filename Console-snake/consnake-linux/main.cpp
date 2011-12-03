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
   
 int main(int argc, char *argv[])  
 {  
     draw_init();  
     srand(time(NULL));  
     Game *g = game_new();  
     draw_start_window(g);  
     while(1)  
     {  
         game_main_loop(g);  
           
         printw("Nochmal spielen? (j/N)");  
         refresh();  
         if(getchar() != 'j')  
             break;  
           
         game_reset(g);      //  
     }  
     delete g;  
     draw_deinit();  
     return 0;  
 }  