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
   
 Toplist::Toplist(char *file)  
 {  
     memset(filename,0,100);  
     tlu = NULL;  
       
     if(file)  
         if(strlen(file))  
         {  
             strcpy(filename,file);  
             int fd = open(filename,O_RDONLY);  
             if(fd >= 0)  
             {  
                 while(1)  
                 {  
                     int ret;  
                     ToplistUnit *temp = new ToplistUnit;  
                     ret = read(fd,temp->name,100);  
                     if(ret<100)  
                     {  
                         delete temp;  
                         break;  
                     }  
                     read(fd,&temp->points,sizeof(int));  
                     if(!tlu)  
                         tlu = temp;  
                     else  
                     {  
                         ToplistUnit *last = tlu;  
                         while(last->next)  
                             last=last->next;  
                         last->next = temp;  
                     }  
                 }  
                 close(fd);  
             }  
         }  
     return;  
 }  
   
 Toplist::~Toplist(void)  
 {  
     while(tlu)  
     {  
         ToplistUnit *temp = tlu->next;  
         delete tlu;  
         tlu = temp;  
     }  
 }  
   
 int Toplist::Save(void)  
 {  
     unlink(filename);  
     int fd = open(filename,O_WRONLY|O_CREAT,00644);  
     if(fd < 0)  
         return -1;  
     for(ToplistUnit *temp = tlu;temp;temp=temp->next)  
     {  
         write(fd,temp->name,100);  
         write(fd,&temp->points,sizeof(int));  
     }  
     close(fd);  
     return 0;  
 }  
   
 int Toplist::Insert(char *name, int points)  
 {  
     ToplistUnit *temp = new ToplistUnit;  
     strncpy(temp->name,name,100);  
     temp->points = points;  
     temp->next = NULL;  
       
     if(!tlu)  
     {  
         tlu = temp;  
         return 0;  
     }  
       
     if(tlu->points < temp->points)  
     {  
         temp->next = tlu;  
         tlu = temp;  
         return 0;  
     }  
       
     for(ToplistUnit *act = tlu;act->next;act=act->next)  
     {  
         if(act->next->points < temp->points)  
         {  
             temp->next = act->next;  
             act->next = temp;  
             return 0;  
         }  
     }  
       
     ToplistUnit *last = tlu;  
     while(last->next)  
         last = last->next;  
     last->next = temp;  
       
     return 0;  
 }  
   
   
 int Toplist::Update(char *name, int points)  
 {  
     Insert(name,points);  
       
     ToplistUnit *last = tlu;  
     if(last)  
     {  
         int anz = 0;  
         while(last->next)  
         {  
             anz++;  
             if(anz >= 10)  
                 if(last->next)  
                 {  
                     delete last->next;  
                     last->next = NULL;  
                     break;  
                 }  
             last = last->next;  
         }  
               
     }  
           
     Save();  
     return 0;  
 }  
   
 ToplistUnit* Toplist::GetToplistUnit(void)  
 {  
     return tlu;  
 }  
   