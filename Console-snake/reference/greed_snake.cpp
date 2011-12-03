# #define min(a, b)  (((a) < (b)) ? (a) : (b))   
# #define max(a, b)  (((a) > (b)) ? (a) : (b))    
# #define Pi 3.1415927   
#    
# #include <assert.h>   
#    
# # include <stdio.h>   
# # include <stdlib.h>   
# # include <string.h>   
# # include <math.h>   
# #include<iostream.h>   
#    
#    
# // ����������ɢ���ݵ�����ݽṹ    
# struct SnakeLink   
# {   
#     int x;               // ���Ƶ�ˮƽ���������   
#     int y;               // ���Ƶ���ֱ���������   
#     double curv;         // ����   
#     double bIndex;       // �ڲ�������ϵ�� �����Ƶ�Ϊ�ǵ�ʱȡֵ0����ʼֵΪ1   
# };   
#    
# /****************************************************************  
# ��ȡͼ���ļ��е�����  
# ���������  
# int Height��          ͼ��ߣ�������  
# int Width��           ͼ���������  
# int ColorBit��        ���ص�λ����ֻ��Ϊ8��24  
# FILE * fp��           �ļ����  
# ���������  
# unsigned char * Data�������ͼ�����ݣ����ڻҶ�ͼ���СΪWxH�ֽڣ�  
#                       ��ɫ����ΪWxHx3�ֽ�  
# ****************************************************************/   
# void ImageDataRead( unsigned char * Data, int Height, int Width,    
#                    int ColorBit, FILE * fp )   
# {   
#     int x,y;   
#     unsigned char indata;   
#        
#     if ( ColorBit == 8 )   /* ��8λ�Ҷ�ͼ��Ĵ��� */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 fread( &indata, sizeof(unsigned char), 1, fp );   
#                 Data[ y*Width+x ] = indata;   
#             }   
#     }   
#     else                  /* ��24λ���ɫͼ��Ĵ��� */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 fread( &indata, sizeof(unsigned char), 1, fp );   
#                 Data[ (y*Width+x)*3 ] = indata; // read in B   
#                 fread( &indata, sizeof(unsigned char), 1, fp );   
#                 Data[ (y*Width+x)*3+1 ] = indata; // read in G   
#                 fread( &indata, sizeof(unsigned char), 1, fp );   
#                 Data[ (y*Width+x)*3+2 ] = indata; // read in R                 
#             }   
#     }   
#     return;   
# }   
#    
# /****************************************************************  
# ����ͼ�����ݵ��ļ���  
# ���������  
# int Height��          ͼ��ߣ�������  
# int Width��           ͼ���������  
# int ColorBit��        ���ص�λ����ֻ��Ϊ8��24  
# FILE * fp��           �ļ����  
# unsigned char * Data�������ͼ�����ݣ����ڻҶ�ͼ���СΪWxH�ֽڣ�  
#                       ��ɫ����ΪWxHx3�ֽ�  
# ���������  
#                       ��  
# ****************************************************************/   
# void ImageDataWrite( unsigned char * Data, int Height, int Width,   
#                     int ColorBit, FILE * fp )   
# {   
#     int x,y;   
#     unsigned char outdata;   
#        
#     if ( ColorBit == 8 )    /* ��8λ�Ҷ�ͼ��Ĵ��� */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 outdata = Data[ y*Width+x ];   
#                 fwrite( ( unsigned char * ) &outdata, sizeof( unsigned char ), 1, fp );   
#             }   
#     }   
#     else                    /* ��24λ���ɫͼ��Ĵ��� */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 outdata = Data[ (y*Width+x)*3 ]; // output B   
#                 fwrite( ( unsigned char * ) &outdata, sizeof( unsigned char ), 1, fp );   
#                 outdata = Data[ (y*Width+x)*3+1 ]; // output G   
#                 fwrite( ( unsigned char * ) &outdata, sizeof( unsigned char ), 1, fp );   
#                 outdata = Data[ (y*Width+x)*3+2 ]; // output R   
#                 fwrite( ( unsigned char * ) &outdata, sizeof( unsigned char ), 1, fp );   
#             }   
#     }   
#     return;   
# }   
#    
# /**********************************************************************  
#    ��ͼ���һ���������ڵ��˲���˹�˲�   
#    data:    ��Ҫ���о��������              
#    topx:    �����˲������϶���x���������  
#    topy:    �����˲������϶���x���������  
#    bottomx: �����˲������¶���x���������  
#    bottomy: �����˲������¶���x���������  
#    imgWidth��imgHeight: ͼ��ĸ߶ȡ����  
#    kernel: ��˹��������ķ���      
#    ��˹�������: (exp(-x*x/2/kernel/kernel)/(sqrt(2*3.1515926)/kernel  
# /***********************************************************************/   
#    
# void GaoSiSmooth(unsigned char *data, int topx, int topy, int bottomx,    
#                  int bottomy, int imgWidth, int imgHeight,  double kernel)   
#    
# {   // ��Ҫ�˲���������������   
#     int leftx=topx-(bottomx-topx)/2;      
#     int lefty=topy-(bottomy-topy)/2;   
#     int rightx=bottomx+(bottomx-topx)/2;   
#     int righty=bottomy+(bottomy-topy)/2;   
#     leftx=max(leftx, 10);             //��˹�˲���Χ ���϶���   
#     lefty=max(lefty,10);   
#     rightx=min(rightx, imgWidth-10);  //��˹�˲���Χ ���¶���   
#     righty=min(righty, imgHeight-10);   
#        
#     int y,x,i;             // ѭ�����Ʊ���   
#     int nWindowSize=0;     // ��˹�˲��������鳤��   
#     int nHalfLen=0;        // ���ڳ��ȵ�1/2     
#     double* pdKernel ;     // һά��˹�����˲���   
#     double  dDotMul=0 ;   // ��˹ϵ����ͼ�����ݵĵ��      
#     double  dDis=0  ;      // �����ĳһ�㵽���ĵ�ľ���   
#     double  dValue=0;      // �м����   
#     double  dSum =0 ;      // �м����   
#     double  PI= 3.1415926;   
#        
#     // ���鳤�ȣ����ݸ����۵�֪ʶ��ѡȡ[-3*kernel, 3*kernel]���ڵ�����         
#     nWindowSize = 1 + 2*((int)ceil(3*kernel));   
#     nHalfLen = (nWindowSize)/2;  // ����   
#     double* ImgTemp;   
#     ImgTemp=new double[imgWidth*imgHeight]; //��ʱ����   
#     assert(ImgTemp!=NULL);   
#     pdKernel = new double[nWindowSize] ;  // �����ڴ�       
#     assert(pdKernel);   
#           
#     for(i=0; i<nwindowsize; i++)="" �����˹ϵ��="" {="" ddis="(i-nHalfLen)*1.0" dvalue="exp(-0.5*dDis*dDis/(kernel*kernel))/(sqrt(2*PI)*kernel);" pdkernel[i]="dValue" ;="" dsum="" +="dValue;" }="" for(i="0;" i=""><nwindowsize; i++)="" {="" pdkernel[i]="" }="" ��һ��="" for(y="lefty;" y=""><righty; y++)="" y��������˲�="" {="" for(x="leftx;" x=""><rightx; x++)="" {="" ddotmul="0;" for(i="(-nHalfLen);" i=""><=nHalfLen; i++)   
#             {      
#                  dDotMul+=data[y*imgWidth+i+x] * pdKernel[nHalfLen+i]; //�����Ǳ߽����   
#                   
#                  /* //���Ǳ߽����  
#                 if( (i+x) < 0 ) //���ڶԳ�����  
#                 { dDotMul+=data[y*width + abs(i+x)-1] * pdKernel[nHalfLen+i]; }               
#                 if( (i+x) >= 0  && (i+x) < width )  
#                 {dDotMul+=data[y*width+i+x] * pdKernel[nHalfLen+i]; }                 
#                 if( (i+x) >=width )  
#                 { dDotMul+=data[y*width + 2*width-1-(i+x)] * pdKernel[nHalfLen+i]; }  
#                 */   
#             }   
#             ImgTemp[y*imgWidth+x] = dDotMul;   
#         }   
#     }   
#        
#     // x��������˲�   
#     for(y=lefty; y<righty; y++)="" y��������˲�="" {="" for(x="leftx;" x=""><rightx; x++)="" {="" ddotmul="0;" for(i="(-nHalfLen);" i=""><=nHalfLen; i++)   
#             {      
#                 dDotMul += ImgTemp[(y+i)*imgWidth+x] * pdKernel[nHalfLen+i]; //�����Ǳ߽����   
#                 
#                 /* //���Ǳ߽����  
#                if( (i+y) < 0)  //���ڶԳ�����  
#                { dDotMul += ImgTemp[(abs(y+i)-1)*width +x ]* pdKernel[nHalfLen+i]; }                  
#               if( (i+y) >= 0  && (i+y) < height )  
#               { dDotMul += ImgTemp[(y+i)*width+x] * pdKernel[nHalfLen+i]; }               
#               if( (i+y) >=height )  
#               { dDotMul += ImgTemp[(2*height-1-i-y)*width+x] * pdKernel[nHalfLen+i];}  
#              */    
#             }      
#                
#             data[y*imgWidth+x] =(unsigned char)dDotMul;   
#         }   
#     }   
#        
#     delete []pdKernel;  pdKernel = NULL ;   
#     delete[]ImgTemp;    ImgTemp=NULL;   
# }   
#    
#    
# /*****************************************  
#   ������ʼ���ݽṹ  
#   realNumber:ʵ�ʷ������ɢ�����  
#   x1: ��ʼ�������������϶���ˮƽ��������  
#   y1: ��ʼ�������������϶��㴹ֱ��������  
#   x2: ��ʼ�������������¶���ˮƽ��������  
#   y2: ��ʼ�������������¶��㴹ֱ��������  
#   number: ����������ɢ���Ƶ�ĸ���  
#   imgWidth: ͼ��Ŀ��  
#   imgHeight: ͼ��ĸ߶�  
# ******************************************/   
# void SnakeInital(SnakeLink snake[], int &realNumber, int number,   
#                  int imgWidth, int imgHeight, unsigned char *imagedata, int radius)   
# {   
#     
#    
# double step=2*Pi/number;   
# realNumber=number;   
#       
#    for( int i=0; i<number; i++="" )="" ȷ����ʼֵ="" snake[i].x="0;" snake[i].y="0;" snake[i].bindex="1.0;" snake[i].curv="0;" xcenter="int(imgWidth/2);" ycenter="int(imgHeight/2);" for(int="" k="0;k<number;k++)" snake[k].x="int(xCenter+radius*cos(k*step));" snake[k].y="int(yCenter-radius*sin(k*step));" snake[number].x="snake[0].x;" ѭ���洢�������±����="" snake[number].y="snake[0].y;" }="" ***********************************="" ����ƽ������="" snake:="" ����������ɢ���ݵ�����ݽṹ����="" realnumber:="" ʵ�ʷ������ɢ�����="" ************************************="" snakeavgedistance(snakelink="" snake[],="" realnumber)="" {="" double="" dist="0;" for(="" int="" i="1;"><realnumber+1; i++="" )="" temp="0;" snake[i].x-snake[i-1].x="" temp+="(" )*(="" snake[i].y-snake[i-1].y="" );="" dist+="sqrt(temp);" dist="" return="" dist;="" }="" ******************************************************="" ��������="" snake:="" ����������ɢ���ݵ�����ݽṹ����="" realnumber:="" ʵ�ʷ������ɢ�����="" *******************************************************="" void="" snakecurvature(="" snakelink="" snake[],="" realnumber)="" {="" tempx0="0," tempx1="0," tempy0="0," tempy1="0;" double="" tempa="0," tempb="0," tempc="0," tempd="0" ;="" for(="" int="" i="1;"><realnumber+1; i++="" tempx0="snake[i+1].x-snake[i].x;" tempx1="snake[i].x-snake[i-1].x;" tempy0="snake[i+1].y-snake[i].y;" tempy1="snake[i].y-snake[i-1].y;" tempa="tempx1/sqrt(" tempb="tempx0/sqrt(" tempc="tempy1/sqrt(" tempx1*tempx1+tempy1*tempy1="" tempd="tempy0/sqrt(" tempx0*tempx0+tempy0*tempy0="" );="" snake[i].curv="(tempa-tempb)*(tempa-tempb)+(tempc-tempd)*(tempc-tempd);" snake[0].curv="snake[realNumber].curv" snake[realnumber+1].curv="snake[1].curv" }="" ***************************************************************************="" �ڲ�����1="" engeryone:="" 8����ĸ�����ڲ�����1������������="" snake:="" ����������ɢ���ݵ�="" realnumber:��ɢ���ݵ�ĸ���="" index:="" ��ǰ��ɢ���ݵ���±�="" ******************************************************************************="" void="" snakeenergyone(double="" engeryone[],="" snakelink="" snake[],int="" realnumber,int="" index="" )="" {="" ����ƽ������="" avgdist="0" double="" tmp1="0" ;="" for(="" int="" i="1;"><realnumber+1; i++="" {="" tmp1="(" snake[i].x-snake[i-1].x="" tmp1+="(" )*(="" snake[i].y-snake[i-1].y="" )="" avgdist+="sqrt(tmp1)" }="" avgdist="" ;="" ����������ľ���="" const="" len="9;" 3*3���������ڴ�С="" double="" distone[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ )   
#     {   
#         for( int n=-1; n<=1; n++ )   
#         {   
#             double temp=0;   
#             int tmpx1=snake[index].x+m;   
#             int tmpy1=snake[index].y+n;                
#                
#             temp=(tmpx1-snake[index-1].x) * (tmpx1-snake[index-1].x);   
#             temp+=(tmpy1-snake[index-1].y) * (tmpy1-snake[index-1].y);              
#             distOne[k++]=fabs( avgDist-sqrt(temp) );               
#         }   
#     }   
#        
#     //�����Сֵ   
#     double maxValue=distOne[0];    
#     double minValue=distOne[0];   
#     for(i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><distone[i] )="" {="" maxvalue="distOne[i];" }="" if(="" minvalue="">distOne[i] )   
#         {   minValue=distOne[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" )="" ��һ��="" engeryone[i]="(distOne[i]-minValue)/(maxValue-minValue);" }="" ***************************************************************************="" �ڲ�����2="" engerytwo:="" 8����ĸ�����ڲ�����2���������ʴ���������ߵĶ��׵���="" snake:="" ����������ɢ���ݵ�="" index:="" ��ǰ��ɢ���ݵ���±�="" ******************************************************************************="" void="" snakeenergytwo(double="" engerytwo[],="" snakelink="" snake[],="" index)="" {="" const="" len="9;" 3*3���������ڴ�С="" double="" curv[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ )   
#     {   
#         for( int n=-1; n<=1; n++ )   
#         {   
#             int tmpx=snake[index].x+m;   
#             int tmpy=snake[index].y+n;             
#             int tempx0=tmpx-snake[index-1].x;   
#             int tempy0=tmpy-snake[index-1].y;   
#             int tempx1=snake[index+1].x-tmpx;   
#             int tempy1=snake[index+1].y-tmpy;   
#             double tempCurv= tempx0*tempx1 + tempy0*tempy1;     
#             tempCurv/=sqrt(tempx1*tempx1+tempy1*tempy1);   
#             tempCurv/=sqrt(tempx0*tempx0+tempy0*tempy0);   
#             curv[k++]=1-tempCurv;   
#         }   
#     }   
#        
#     //�����Сֵ   
#     double maxValue=curv[0];       
#     double minValue=curv[0];   
#     for(int i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><curv[i] )="" {="" maxvalue="curv[i];" }="" if(="" minvalue="">curv[i] )   
#         {   minValue=curv[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" )="" ��һ��="" engerytwo[i]="(curv[i]-minValue)/(maxValue-minValue);" }="" ***************************************************************************="" �ݶ�����3="" engerythree:="" 8����ĸ�����ݶ�����="" snake:="" ����������ɢ���ݵ�="" index:="" ��ǰ��ɢ���ݵ���±�="" *imgdata:="" �ҶȻ����ͼ������="" imgwidth:="" ͼ��Ŀ��="" imgheight:="" ͼ��ĸ߶�="" ******************************************************************************="" void="" snakeenergythree(double="" energythree[],="" snakelink="" snake[],="" index,="" unsigned="" char="" *imgdata,="" imgwidth,="" imgheight)="" {="" const="" len="9;" 3*3���������ڴ�С="" double="" grad[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ ) //�����ݶ�   
#     {   
#         for( int n=-1; n<=1; n++ )   
#         {   
#            
#             int tmpx1=snake[index].x+m;   
#             int tmpy1=snake[index].y+n;                            
#             //���Ĳ��   
#             double gradx1=( imgData[ tmpy1*imgWidth+tmpx1+1 ]-imgData[ tmpy1*imgWidth+tmpx1-1] )/2;   
#             double grady1=( imgData[ (tmpy1+1)*imgWidth+tmpx1 ]-imgData[(tmpy1-1)*imgWidth+tmpx1] )/2;             
#             //grad[k++]=sqrt(gradx1*gradx1+grady1*grady1);   
#             grad[k++]=(gradx1*gradx1+grady1*grady1);   
#         }   
#     }   
#        
#     double max1=grad[0];   
#     double min1=grad[0];   
#     for( int i=1; i<len; i++="" )="" {="" if(max1=""><grad[i]) {="" max1="grad[i];" }="" if(min1="">grad[i])   
#         { min1=grad[i]; }   
#     }   
#        
#     if ( (max1-min1)<5 )   
#     { min1=max1-5;}   
#        
#     for(  i=0; i<len; i++="" )="" ��һ��="" �Ǹ���="" energythree[i]="(min1-grad[i])/(max1-min1);" }="" ***************************************************************************="" �ݶ�����4="" engeryfour:="" �Ľ���="" ��������="" ��Ϊsnake���㵽���ĵľ���="" snake:="" ����������ɢ���ݵ�="" index:="" ��ǰ��ɢ���ݵ���±�="" realnumber����ǰsnake�����Ŀ="" ******************************************************************************="" void="" snakeenergyfour(double="" engeryfour[],="" snakelink="" snake[],="" index,="" realnumber)="" {="" const="" len="9;" 3*3���������ڴ�С="" double="" bal[len];="" k="0;" centx,centy;="" *centx="0;" *centy="0;" tempx="0," tempy="0;" for(="" int="" i="0;"><realnumber; i++="" )="" {="" tempx+="snake[i].x;" tempy+="snake[i].y;" }="" centx="(int)(tempx/realnumber);" centy="(int)(tempy/realnumber);" for(="" int="" m="-1;"><=1; m++ )   
#     {   
#         for( int n=-1; n<=1; n++ )   
#         {   
#                
#             int tmpxx=snake[index].x+m;   
#             int tmpyy=snake[index].y+n;    
#             bal[k++]=sqrt((tmpxx-centx)*(tmpxx-centx)+(tmpyy-centy)*(tmpyy-centy));   
#         }   
#     }   
#       
#     //�����Сֵ   
#     double maxValue=bal[0];    
#     double minValue=bal[0];   
#     for( i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><bal[i] )="" {="" maxvalue="bal[i];" }="" if(="" minvalue="">bal[i] )   
#         {   minValue=bal[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" ��һ��="" engeryfour[i]="(bal[i]-minValue)/(maxValue-minValue);" }="" ******************************************************="" ��ɢ���ݵ�ĸ�����̬����="" snake:="" ����������ɢ���ݵ�="" realnumber:="" ��ɢ���ݵ�ĸ���="" setnumber:="" Ԥ���趨�ĸ���="" *******************************************************="" void="" snakedistadjust(snakelink="" snake[],="" &realnumber,="" setnumber="" )="" {="" avgdist="0" tmp1="0" ;="" double="" *distence="new" double[realnumber+1];="" ��¼ƽ������="" assert(distence!="NULL);" distence[0]="0;" for(="" int="" i="1;"><realnumber+1; i++="" {="" tmp1="(" snake[i].x-snake[i-1].x="" tmp1+="(" )*(="" snake[i].y-snake[i-1].y="" )="" distence[i]="sqrt(tmp1)" avgdist+="distence[i]" }="" avgdist="" ;="" double="" *curv="new" double[realnumber+1];="" ��¼ƽ������="" assert(curv!="NULL);" curv[0]="0;" for(="" i="1;"><realnumber+1; i++="" )="" {="" tempx0="snake[i].x-snake[i-1].x;" tempy0="snake[i].y-snake[i-1].y;" tempx1="snake[i+1].x-snake[i].x;" tempy1="snake[i+1].y-snake[i].y;" double="" +="" tempy0*tempy1;="" tempcurv="tempx0*tempx1" curv[i]="tempCurv;" }="" int="" number="realNumber;" for(="" i="number;">=1; i-- ) //���ʹ�С��ȥ�������   
#     {   
#            
#         if( curv[i]<-0.80  && realNumber>0 )   
#         {   
#             for( int j=i; j<=realNumber; j++ )   
#             {   
#                 snake[j].x= snake[j+1].x;   
#                 snake[j].y= snake[j+1].y;   
#             }   
#                
#             realNumber--;   
#         }          
#     }   
#     snake[0].x = snake[realNumber].x; // ע��ѭ������ͷβ��������   
#     snake[0].y = snake[realNumber].y;   
#     snake[realNumber+1].x = snake[1].x; // ע��ѭ������ͷβ��������   
#     snake[realNumber+1].y = snake[1].y;        
#        
#     int index=0;   
#      number=realNumber;        
#     for(  i=1; i<number+1; i++="" )="" {="" index++;="" if(="" distence[i]="">avgDist*3 && realNumber<setnumber-1 )="" {="" for(int="" j="realNumber+2;j">=index+2;   j-- )   
#             {   
#                 snake[j].x= snake[j-1].x;   
#                 snake[j].y= snake[j-1].y;   
#             }   
#                
#             snake[i+1].x= ( snake[i+1].x + snake[i].x )>>1 ;   
#             snake[i+1].y= ( snake[i+1].y + snake[i].y )>>1 ;                 
#             snake[0].x = snake[realNumber+1].x; // ע��ѭ������ͷβ��������   
#             snake[0].y = snake[realNumber+1].y;   
#             snake[realNumber+2].x = snake[1].x; // ע��ѭ������ͷβ��������   
#             snake[realNumber+2].y = snake[1].y;   
#             index++;   
#             realNumber++;   
#                
#         }   
#     }   
#     //����������ľ���   
#        
#     delete []distence; distence=NULL;   
#     delete []curv; curv=0;   
# }   
#    
# /***************************************************************  
# �������������㷨  ��ɢ���ݵ�ĸ�����̬����  
#  snake:      ����������ɢ���ݵ�  
#  realNumber: ��ɢ���ݵ�ĸ���  
#  SetNumber:  Ԥ���趨�ĸ���  
#  index:      ��ǰ��ɢ���ݵ���±�  
#  imgData:    ͼ������  
#  imgWidth:   ͼ��Ŀ��  
#  imgHeight:  ͼ��ĸ߶�  
#  CountNum:   ��������  
#  lamda:      �������������������ͣ���1������������������1��  
# ****************************************************************/   
# void SnakeMotionAlgorithm(SnakeLink snake[], int &realNumber,    
#                              int SetNumber, unsigned char *imgData,   
#                                int imgWidth, int imgHeight, int countNum,float lamda )   
# {   
#     double aInd=2.5; // =1.0 �������Ե��� ��ActiveSnakeOne.h    
#     double bbInd=4.0;   
#     double cInd=2.9;    
#     double dInd; // =1.6   
#    
#     if(lamda==1)   
#         dInd=4.8;   
#     else dInd=2.5;   
#        
#    
#     for( int k=0;  k<countnum; k++="" )="" ������������Ĵ���="" {="" for(="" int="" i="1;"><realnumber+1; i++="" )="" ע��ѭ������ͷβ��������="" {="" minengery="1000000000.0;" Ĭ���趨һ���޴�ֵ="" energyone[9];="" �ڲ�����1="" energytwo[9];="" �ڲ�����2="" energythree[9];="" double="" energyfour[9];="" �ⲿ����="" snakeenergyone(energyone,="" realnumber,="" �����ڲ�����1="" snakeenergytwo(energytwo,="" i);="" �����ڲ�����2="" snakeenergythree(energythree,="" i,="" imgdata,="" imgwidth,="" imgheight);="" �����ⲿ����="" snakeenergyfour(energyfour,="" snake,="" i,realnumber);="" kk="0;" pointx="snake[i].x;" pointy="snake[i].y;" for(="" int="" m="-1;"><=1; m++ ) //3*3����   
#             {   
#                 for( int n=-1; n<=1; n++ )   
#                 {   
#                     int tmpx1=pointx+m;   
#                     int tmpy1=pointy+n;                                                            
#                     tmpx1=max(tmpx1,10);        //ȷ�������߽緶Χ�����   
#                     tmpx1=min(imgWidth-10,tmpx1);   
#                     tmpy1=max(tmpy1,10);   
#                     tmpy1=min(imgHeight-10,tmpy1);   
#                        
#                     double temp=aInd*energyOne[kk] + bbInd*energyTwo[kk]    
#                                 + cInd*energyThree[kk]+lamda*dInd*energyFour[kk];//+snake[i].bIndex*energyFour[kk];   
#                     kk++;   
#                        
#                     if( temp<minengery )="" �ƶ���������С�ĵ�="" {="" minengery="temp;" snake[i].x="tmpx1;" snake[i].y="tmpy1;" }="" for(="" int="" i="1;"><realnumber+1; i++="" )="" snake[0].x="snake[realNumber].x;" ע��ѭ������ͷβ��������="" snake[0].y="snake[realNumber].y;" snake[realnumber+1].x="snake[1].x;" snake[realnumber+1].y="snake[1].y;" ����ƽ�����������ĸ���="" snakedistadjust(snake,="" realnumber,setnumber="" );="" }="" for(="" int="" k="0;"><countnum; k++="" ʹ�÷���˵��="" ���������="" number:="" ʹ��˵���ţ�����δ�ã�="" number="" snake������������1ʹ�÷�����\n="" grayimagefilename="" edgeimagefilename="" snake:="" ������������1��\n="" grayimagefilename:="" ����Ҷ�ͼ���ļ�����.dat��\n="" edgeimagefilename:="" �����Եͼ���ļ�����.dat��\n="" printf(="" \n="" ������="" ��ѡ������="" heart1.dat="" hh.dat="" 20="" 132="" 29(��������)="" 152="" 50="" 102="" 30="" 25���������ͣ�="" ****************************************************************="" void="" main(="" argc,="" argv[]="" f_gray,*f_edge;="" ָ���ļ���ָ��="" *params;="" ָ������ļ���ָ��="" file_gray[="" ],="" file_edge[="" 256="" ];="" �ļ���="" note[256];="" *="" graydata,*graydata8;="" �ļ��е�����="" int="" height,width,radius,controlnum,count,realnumber,topx,topy,bottomx,bottomy,x,y;="" float="" lamda="1;" snakelink="" *snake;="" argc="" !="3" )="" usage(="" 1="" exit(="" -1="" �����������ͣ�%sΪ�ַ�����%dΪ������ʮ�������ͣ�%f��С����ʽ�������˫��������="" argv[1],="" file_gray="" sscanf(="" argv[2],="" file_edge="" params="fopen" r="" if="" (params)="" {="" &height);="" &width);="" %f="" &lamda);="" &radius);="" &controlnum);="" %d="" &count);="" fscanf="" (params,="" %s="" ,="" &note);="" fclose="" (params);="" }="" else="" printf="" parameter="" file="" snakecircle.txt="" does="" not="" exist.\n="" snake="" snakelink[controlnum+2];="" ����������ɢ���Ƶ�����="" assert(snake!="NULL);" graydata="new" height*width*3];="" graydata8="new" unsigned="" char="" [="" height*width];="" file_gray,="" rb="" graydata,="" 24,="" imagedataread(="" graydata8,="" height,="" width,="" 8,="" fclose(="" f_gray="fopen(" );="" for="" (="" y="0;">< height; y++ )   
#             for ( x = 0; x < width; x++ )   
#             {   
#            
#                
#                 graydata8[ y*width+x ] =GrayData[ (y*width+x)*3 ] ; // read in B   
#             }   
#    
# int xcenter=int(width/2);   
# int ycenter=int(height/2);   
#        
# topx=xcenter-radius*2;   
# topy=ycenter-radius*2;   
# bottomx=xcenter+radius*2;   
# bottomy=ycenter+radius*2;   
#    
# GaoSiSmooth( graydata8, topx, topy, bottomx, bottomy, width, height, 0.6 );   
#         // ��ʼ�����Ƶ�����    
# SnakeInital(snake, realnumber, controlnum, width, height, graydata8, radius);   
#    
#    
# // ̰���㷨����      
# SnakeMotionAlgorithm(snake, realnumber, controlnum*2, graydata8,   
#                                 width, height,  count,lamda );   
# for(int i=0;i<realnumber;i++) {="" graydata[(width*snake[i].y+snake[i].x)*3]="255;" graydata[(width*(snake[i].y+1)+snake[i].x)*3]="255;" graydata[(width*snake[i].y+snake[i].x+1)*3]="255;" graydata[(width*(snake[i].y-1)+snake[i].x)*3]="255;" graydata[(width*snake[i].y+snake[i].x-1)*3]="255;" graydata[(width*snake[i].y+snake[i].x)*3+1]="0;" graydata[(width*(snake[i].y+1)+snake[i].x)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x+1)*3+1]="0;" graydata[(width*(snake[i].y-1)+snake[i].x)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x-1)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x)*3+2]="0;//���" graydata[(width*(snake[i].y+1)+snake[i].x)*3+2]="0;" graydata[(width*snake[i].y+snake[i].x+1)*3+2]="0;" graydata[(width*(snake[i].y-1)+snake[i].x)*3+2]="0;" graydata[(width*snake[i].y+snake[i].x-1)*3+2]="0;" graydata8[width*snake[i].y+snake[i].x]="255;" graydata8[width*int(0.5*(snake[i+1].y+snake[i].y))+int(0.5*(snake[i+1].x+snake[i].x))]="255;" *="" file_edge,="" wb="" graydata,="" width,24,="" imagedatawrite(="" graydata8,="" height,="" width,8,="" fclose(="" f_edge="fopen(" );="" graydata;="" graydata8;="" delete="" snake;="" }=""></realnumber;i++)></countnum;></realnumber+1;></minengery></realnumber+1;></countnum;></setnumber-1></number+1;></realnumber+1;></realnumber+1;></len;></bal[i]></len;></realnumber;></len;></grad[i])></len;></len;></curv[i]></len;></len;></distone[i]></len;></realnumber+1;></realnumber+1;></realnumber+1;></number;></rightx;></righty;></rightx;></righty;></nwindowsize;></nwindowsize;></iostream.h></math.h></string.h></stdlib.h></stdio.h></assert.h>  