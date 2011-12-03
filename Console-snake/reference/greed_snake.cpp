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
# // 主动轮廓离散数据点的数据结构    
# struct SnakeLink   
# {   
#     int x;               // 控制点水平方向的坐标   
#     int y;               // 控制点竖直方向的坐标   
#     double curv;         // 曲率   
#     double bIndex;       // 内部能量的系数 当控制点为角点时取值0，初始值为1   
# };   
#    
# /****************************************************************  
# 读取图像文件中的数据  
# 输入参数：  
# int Height：          图像高（行数）  
# int Width：           图像宽（列数）  
# int ColorBit：        像素的位数，只能为8或24  
# FILE * fp：           文件句柄  
# 输出参数：  
# unsigned char * Data：读入的图像数据，对于灰度图像大小为WxH字节；  
#                       彩色数据为WxHx3字节  
# ****************************************************************/   
# void ImageDataRead( unsigned char * Data, int Height, int Width,    
#                    int ColorBit, FILE * fp )   
# {   
#     int x,y;   
#     unsigned char indata;   
#        
#     if ( ColorBit == 8 )   /* 对8位灰度图像的处理 */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 fread( &indata, sizeof(unsigned char), 1, fp );   
#                 Data[ y*Width+x ] = indata;   
#             }   
#     }   
#     else                  /* 对24位真彩色图像的处理 */   
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
# 保存图像数据到文件中  
# 输入参数：  
# int Height：          图像高（行数）  
# int Width：           图像宽（列数）  
# int ColorBit：        像素的位数，只能为8或24  
# FILE * fp：           文件句柄  
# unsigned char * Data：读入的图像数据，对于灰度图像大小为WxH字节；  
#                       彩色数据为WxHx3字节  
# 输出参数：  
#                       无  
# ****************************************************************/   
# void ImageDataWrite( unsigned char * Data, int Height, int Width,   
#                     int ColorBit, FILE * fp )   
# {   
#     int x,y;   
#     unsigned char outdata;   
#        
#     if ( ColorBit == 8 )    /* 对8位灰度图像的处理 */   
#     {   
#         for ( y = 0; y < Height; y++ )   
#             for ( x = 0; x < Width; x++ )   
#             {   
#                 outdata = Data[ y*Width+x ];   
#                 fwrite( ( unsigned char * ) &outdata, sizeof( unsigned char ), 1, fp );   
#             }   
#     }   
#     else                    /* 对24位真彩色图像的处理 */   
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
#    在图像的一个块区域内的滤波高斯滤波   
#    data:    需要进行卷积的数据              
#    topx:    进行滤波的左上顶点x方向的坐标  
#    topy:    进行滤波的左上顶点x方向的坐标  
#    bottomx: 进行滤波的右下顶点x方向的坐标  
#    bottomy: 进行滤波的右下顶点x方向的坐标  
#    imgWidth、imgHeight: 图像的高度、宽度  
#    kernel: 高斯卷积函数的方差      
#    高斯卷积函数: (exp(-x*x/2/kernel/kernel)/(sqrt(2*3.1515926)/kernel  
# /***********************************************************************/   
#    
# void GaoSiSmooth(unsigned char *data, int topx, int topy, int bottomx,    
#                  int bottomy, int imgWidth, int imgHeight,  double kernel)   
#    
# {   // 将要滤波的区域扩大两倍   
#     int leftx=topx-(bottomx-topx)/2;      
#     int lefty=topy-(bottomy-topy)/2;   
#     int rightx=bottomx+(bottomx-topx)/2;   
#     int righty=bottomy+(bottomy-topy)/2;   
#     leftx=max(leftx, 10);             //高斯滤波范围 左上顶点   
#     lefty=max(lefty,10);   
#     rightx=min(rightx, imgWidth-10);  //高斯滤波范围 右下顶点   
#     righty=min(righty, imgHeight-10);   
#        
#     int y,x,i;             // 循环控制变量   
#     int nWindowSize=0;     // 高斯滤波器的数组长度   
#     int nHalfLen=0;        // 窗口长度的1/2     
#     double* pdKernel ;     // 一维高斯数据滤波器   
#     double  dDotMul=0 ;   // 高斯系数与图象数据的点乘      
#     double  dDis=0  ;      // 数组的某一点到中心点的距离   
#     double  dValue=0;      // 中间变量   
#     double  dSum =0 ;      // 中间变量   
#     double  PI= 3.1415926;   
#        
#     // 数组长度，根据概率论的知识，选取[-3*kernel, 3*kernel]以内的数据         
#     nWindowSize = 1 + 2*((int)ceil(3*kernel));   
#     nHalfLen = (nWindowSize)/2;  // 中心   
#     double* ImgTemp;   
#     ImgTemp=new double[imgWidth*imgHeight]; //临时变量   
#     assert(ImgTemp!=NULL);   
#     pdKernel = new double[nWindowSize] ;  // 分配内存       
#     assert(pdKernel);   
#           
#     for(i=0; i<nwindowsize; i++)="" 计算高斯系数="" {="" ddis="(i-nHalfLen)*1.0" dvalue="exp(-0.5*dDis*dDis/(kernel*kernel))/(sqrt(2*PI)*kernel);" pdkernel[i]="dValue" ;="" dsum="" +="dValue;" }="" for(i="0;" i=""><nwindowsize; i++)="" {="" pdkernel[i]="" }="" 归一化="" for(y="lefty;" y=""><righty; y++)="" y方向进行滤波="" {="" for(x="leftx;" x=""><rightx; x++)="" {="" ddotmul="0;" for(i="(-nHalfLen);" i=""><=nHalfLen; i++)   
#             {      
#                  dDotMul+=data[y*imgWidth+i+x] * pdKernel[nHalfLen+i]; //不考虑边界溢出   
#                   
#                  /* //考虑边界溢出  
#                 if( (i+x) < 0 ) //周期对称延拓  
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
#     // x方向进行滤波   
#     for(y=lefty; y<righty; y++)="" y方向进行滤波="" {="" for(x="leftx;" x=""><rightx; x++)="" {="" ddotmul="0;" for(i="(-nHalfLen);" i=""><=nHalfLen; i++)   
#             {      
#                 dDotMul += ImgTemp[(y+i)*imgWidth+x] * pdKernel[nHalfLen+i]; //不考虑边界溢出   
#                 
#                 /* //考虑边界溢出  
#                if( (i+y) < 0)  //周期对称延拓  
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
#   建立初始数据结构  
#   realNumber:实际分配的离散点个数  
#   x1: 初始矩形轮廓的左上顶点水平方向坐标  
#   y1: 初始矩形轮廓的左上顶点垂直方向坐标  
#   x2: 初始矩形轮廓的右下顶点水平方向坐标  
#   y2: 初始矩形轮廓的右下顶点垂直方向坐标  
#   number: 主动轮廓离散控制点的个数  
#   imgWidth: 图像的宽度  
#   imgHeight: 图像的高度  
# ******************************************/   
# void SnakeInital(SnakeLink snake[], int &realNumber, int number,   
#                  int imgWidth, int imgHeight, unsigned char *imagedata, int radius)   
# {   
#     
#    
# double step=2*Pi/number;   
# realNumber=number;   
#       
#    for( int i=0; i<number; i++="" )="" 确定初始值="" snake[i].x="0;" snake[i].y="0;" snake[i].bindex="1.0;" snake[i].curv="0;" xcenter="int(imgWidth/2);" ycenter="int(imgHeight/2);" for(int="" k="0;k<number;k++)" snake[k].x="int(xCenter+radius*cos(k*step));" snake[k].y="int(yCenter-radius*sin(k*step));" snake[number].x="snake[0].x;" 循环存储，方便下标操作="" snake[number].y="snake[0].y;" }="" ***********************************="" 计算平均距离="" snake:="" 主动轮廓离散数据点的数据结构数组="" realnumber:="" 实际分配的离散点个数="" ************************************="" snakeavgedistance(snakelink="" snake[],="" realnumber)="" {="" double="" dist="0;" for(="" int="" i="1;"><realnumber+1; i++="" )="" temp="0;" snake[i].x-snake[i-1].x="" temp+="(" )*(="" snake[i].y-snake[i-1].y="" );="" dist+="sqrt(temp);" dist="" return="" dist;="" }="" ******************************************************="" 计算曲率="" snake:="" 主动轮廓离散数据点的数据结构数组="" realnumber:="" 实际分配的离散点个数="" *******************************************************="" void="" snakecurvature(="" snakelink="" snake[],="" realnumber)="" {="" tempx0="0," tempx1="0," tempy0="0," tempy1="0;" double="" tempa="0," tempb="0," tempc="0," tempd="0" ;="" for(="" int="" i="1;"><realnumber+1; i++="" tempx0="snake[i+1].x-snake[i].x;" tempx1="snake[i].x-snake[i-1].x;" tempy0="snake[i+1].y-snake[i].y;" tempy1="snake[i].y-snake[i-1].y;" tempa="tempx1/sqrt(" tempb="tempx0/sqrt(" tempc="tempy1/sqrt(" tempx1*tempx1+tempy1*tempy1="" tempd="tempy0/sqrt(" tempx0*tempx0+tempy0*tempy0="" );="" snake[i].curv="(tempa-tempb)*(tempa-tempb)+(tempc-tempd)*(tempc-tempd);" snake[0].curv="snake[realNumber].curv" snake[realnumber+1].curv="snake[1].curv" }="" ***************************************************************************="" 内部能量1="" engeryone:="" 8邻域的各点的内部能量1，调整点间距离="" snake:="" 主动轮廓离散数据点="" realnumber:离散数据点的个数="" index:="" 当前离散数据点的下标="" ******************************************************************************="" void="" snakeenergyone(double="" engeryone[],="" snakelink="" snake[],int="" realnumber,int="" index="" )="" {="" 计算平均距离="" avgdist="0" double="" tmp1="0" ;="" for(="" int="" i="1;"><realnumber+1; i++="" {="" tmp1="(" snake[i].x-snake[i-1].x="" tmp1+="(" )*(="" snake[i].y-snake[i-1].y="" )="" avgdist+="sqrt(tmp1)" }="" avgdist="" ;="" 计算搜索点的距离="" const="" len="9;" 3*3的搜索窗口大小="" double="" distone[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ )   
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
#     //求最大、小值   
#     double maxValue=distOne[0];    
#     double minValue=distOne[0];   
#     for(i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><distone[i] )="" {="" maxvalue="distOne[i];" }="" if(="" minvalue="">distOne[i] )   
#         {   minValue=distOne[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" )="" 归一化="" engeryone[i]="(distOne[i]-minValue)/(maxValue-minValue);" }="" ***************************************************************************="" 内部能量2="" engerytwo:="" 8邻域的各点的内部能量2，计算曲率代替参数曲线的二阶导数="" snake:="" 主动轮廓离散数据点="" index:="" 当前离散数据点的下标="" ******************************************************************************="" void="" snakeenergytwo(double="" engerytwo[],="" snakelink="" snake[],="" index)="" {="" const="" len="9;" 3*3的搜索窗口大小="" double="" curv[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ )   
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
#     //求最大、小值   
#     double maxValue=curv[0];       
#     double minValue=curv[0];   
#     for(int i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><curv[i] )="" {="" maxvalue="curv[i];" }="" if(="" minvalue="">curv[i] )   
#         {   minValue=curv[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" )="" 归一化="" engerytwo[i]="(curv[i]-minValue)/(maxValue-minValue);" }="" ***************************************************************************="" 梯度能量3="" engerythree:="" 8邻域的各点的梯度能量="" snake:="" 主动轮廓离散数据点="" index:="" 当前离散数据点的下标="" *imgdata:="" 灰度化后的图像数据="" imgwidth:="" 图像的宽度="" imgheight:="" 图像的高度="" ******************************************************************************="" void="" snakeenergythree(double="" energythree[],="" snakelink="" snake[],="" index,="" unsigned="" char="" *imgdata,="" imgwidth,="" imgheight)="" {="" const="" len="9;" 3*3的搜索窗口大小="" double="" grad[len];="" k="0;" for(="" int="" m="-1;"><=1; m++ ) //计算梯度   
#     {   
#         for( int n=-1; n<=1; n++ )   
#         {   
#            
#             int tmpx1=snake[index].x+m;   
#             int tmpy1=snake[index].y+n;                            
#             //中心差分   
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
#     for(  i=0; i<len; i++="" )="" 归一化="" 是负数="" energythree[i]="(min1-grad[i])/(max1-min1);" }="" ***************************************************************************="" 梯度能量4="" engeryfour:="" 改进的="" 气球能量="" ，为snake各点到中心的距离="" snake:="" 主动轮廓离散数据点="" index:="" 当前离散数据点的下标="" realnumber：当前snake点的数目="" ******************************************************************************="" void="" snakeenergyfour(double="" engeryfour[],="" snakelink="" snake[],="" index,="" realnumber)="" {="" const="" len="9;" 3*3的搜索窗口大小="" double="" bal[len];="" k="0;" centx,centy;="" *centx="0;" *centy="0;" tempx="0," tempy="0;" for(="" int="" i="0;"><realnumber; i++="" )="" {="" tempx+="snake[i].x;" tempy+="snake[i].y;" }="" centx="(int)(tempx/realnumber);" centy="(int)(tempy/realnumber);" for(="" int="" m="-1;"><=1; m++ )   
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
#     //求最大、小值   
#     double maxValue=bal[0];    
#     double minValue=bal[0];   
#     for( i=1; i<len; i++="" )="" {="" if(="" maxvalue=""><bal[i] )="" {="" maxvalue="bal[i];" }="" if(="" minvalue="">bal[i] )   
#         {   minValue=bal[i]; }    
#     }   
#        
#     for( i=0; i<len; i++="" 归一化="" engeryfour[i]="(bal[i]-minValue)/(maxValue-minValue);" }="" ******************************************************="" 离散数据点的个数动态增加="" snake:="" 主动轮廓离散数据点="" realnumber:="" 离散数据点的个数="" setnumber:="" 预先设定的个数="" *******************************************************="" void="" snakedistadjust(snakelink="" snake[],="" &realnumber,="" setnumber="" )="" {="" avgdist="0" tmp1="0" ;="" double="" *distence="new" double[realnumber+1];="" 记录平均距离="" assert(distence!="NULL);" distence[0]="0;" for(="" int="" i="1;"><realnumber+1; i++="" {="" tmp1="(" snake[i].x-snake[i-1].x="" tmp1+="(" )*(="" snake[i].y-snake[i-1].y="" )="" distence[i]="sqrt(tmp1)" avgdist+="distence[i]" }="" avgdist="" ;="" double="" *curv="new" double[realnumber+1];="" 记录平均距离="" assert(curv!="NULL);" curv[0]="0;" for(="" i="1;"><realnumber+1; i++="" )="" {="" tempx0="snake[i].x-snake[i-1].x;" tempy0="snake[i].y-snake[i-1].y;" tempx1="snake[i+1].x-snake[i].x;" tempy1="snake[i+1].y-snake[i].y;" double="" +="" tempy0*tempy1;="" tempcurv="tempx0*tempx1" curv[i]="tempCurv;" }="" int="" number="realNumber;" for(="" i="number;">=1; i-- ) //曲率过小，去掉这个点   
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
#     snake[0].x = snake[realNumber].x; // 注意循环更新头尾两个数据   
#     snake[0].y = snake[realNumber].y;   
#     snake[realNumber+1].x = snake[1].x; // 注意循环更新头尾两个数据   
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
#             snake[0].x = snake[realNumber+1].x; // 注意循环更新头尾两个数据   
#             snake[0].y = snake[realNumber+1].y;   
#             snake[realNumber+2].x = snake[1].x; // 注意循环更新头尾两个数据   
#             snake[realNumber+2].y = snake[1].y;   
#             index++;   
#             realNumber++;   
#                
#         }   
#     }   
#     //计算搜索点的距离   
#        
#     delete []distence; distence=NULL;   
#     delete []curv; curv=0;   
# }   
#    
# /***************************************************************  
# 主动轮廓搜索算法  离散数据点的个数动态增加  
#  snake:      主动轮廓离散数据点  
#  realNumber: 离散数据点的个数  
#  SetNumber:  预先设定的个数  
#  index:      当前离散数据点的下标  
#  imgData:    图像数据  
#  imgWidth:   图像的宽度  
#  imgHeight:  图像的高度  
#  CountNum:   迭代次数  
#  lamda:      控制轮廓线是向外膨胀（－1）还是向内收缩（＋1）  
# ****************************************************************/   
# void SnakeMotionAlgorithm(SnakeLink snake[], int &realNumber,    
#                              int SetNumber, unsigned char *imgData,   
#                                int imgWidth, int imgHeight, int countNum,float lamda )   
# {   
#     double aInd=2.5; // =1.0 参数可以调整 在ActiveSnakeOne.h    
#     double bbInd=4.0;   
#     double cInd=2.9;    
#     double dInd; // =1.6   
#    
#     if(lamda==1)   
#         dInd=4.8;   
#     else dInd=2.5;   
#        
#    
#     for( int k=0;  k<countnum; k++="" )="" 迭代搜索计算的次数="" {="" for(="" int="" i="1;"><realnumber+1; i++="" )="" 注意循环更新头尾两个数据="" {="" minengery="1000000000.0;" 默认设定一个巨大值="" energyone[9];="" 内部能量1="" energytwo[9];="" 内部能量2="" energythree[9];="" double="" energyfour[9];="" 外部能量="" snakeenergyone(energyone,="" realnumber,="" 计算内部能量1="" snakeenergytwo(energytwo,="" i);="" 计算内部能量2="" snakeenergythree(energythree,="" i,="" imgdata,="" imgwidth,="" imgheight);="" 计算外部能量="" snakeenergyfour(energyfour,="" snake,="" i,realnumber);="" kk="0;" pointx="snake[i].x;" pointy="snake[i].y;" for(="" int="" m="-1;"><=1; m++ ) //3*3邻域   
#             {   
#                 for( int n=-1; n<=1; n++ )   
#                 {   
#                     int tmpx1=pointx+m;   
#                     int tmpy1=pointy+n;                                                            
#                     tmpx1=max(tmpx1,10);        //确定轮廓边界范围不溢出   
#                     tmpx1=min(imgWidth-10,tmpx1);   
#                     tmpy1=max(tmpy1,10);   
#                     tmpy1=min(imgHeight-10,tmpy1);   
#                        
#                     double temp=aInd*energyOne[kk] + bbInd*energyTwo[kk]    
#                                 + cInd*energyThree[kk]+lamda*dInd*energyFour[kk];//+snake[i].bIndex*energyFour[kk];   
#                     kk++;   
#                        
#                     if( temp<minengery )="" 移动到能量最小的点="" {="" minengery="temp;" snake[i].x="tmpx1;" snake[i].y="tmpy1;" }="" for(="" int="" i="1;"><realnumber+1; i++="" )="" snake[0].x="snake[realNumber].x;" 注意循环更新头尾两个数据="" snake[0].y="snake[realNumber].y;" snake[realnumber+1].x="snake[1].x;" snake[realnumber+1].y="snake[1].y;" 根据平均距离调整点的个数="" snakedistadjust(snake,="" realnumber,setnumber="" );="" }="" for(="" int="" k="0;"><countnum; k++="" 使用方法说明="" 输入参数：="" number:="" 使用说明号（保留未用）="" number="" snake主动轮廓程序1使用方法：\n="" grayimagefilename="" edgeimagefilename="" snake:="" 主动轮廓程序1名\n="" grayimagefilename:="" 输入灰度图像文件名（.dat）\n="" edgeimagefilename:="" 输出边缘图像文件名（.dat）\n="" printf(="" \n="" 主程序="" 可选参数：="" heart1.dat="" hh.dat="" 20="" 132="" 29(向内收缩)="" 152="" 50="" 102="" 30="" 25（向外膨胀）="" ****************************************************************="" void="" main(="" argc,="" argv[]="" f_gray,*f_edge;="" 指向文件的指针="" *params;="" 指向参数文件的指针="" file_gray[="" ],="" file_edge[="" 256="" ];="" 文件名="" note[256];="" *="" graydata,*graydata8;="" 文件中的数据="" int="" height,width,radius,controlnum,count,realnumber,topx,topy,bottomx,bottomy,x,y;="" float="" lamda="1;" snakelink="" *snake;="" argc="" !="3" )="" usage(="" 1="" exit(="" -1="" 检查变量的类型（%s为字符串，%d为带符号十进制整型，%f以小数形式输出单、双精度数）="" argv[1],="" file_gray="" sscanf(="" argv[2],="" file_edge="" params="fopen" r="" if="" (params)="" {="" &height);="" &width);="" %f="" &lamda);="" &radius);="" &controlnum);="" %d="" &count);="" fscanf="" (params,="" %s="" ,="" &note);="" fclose="" (params);="" }="" else="" printf="" parameter="" file="" snakecircle.txt="" does="" not="" exist.\n="" snake="" snakelink[controlnum+2];="" 主动轮廓离散控制点数组="" assert(snake!="NULL);" graydata="new" height*width*3];="" graydata8="new" unsigned="" char="" [="" height*width];="" file_gray,="" rb="" graydata,="" 24,="" imagedataread(="" graydata8,="" height,="" width,="" 8,="" fclose(="" f_gray="fopen(" );="" for="" (="" y="0;">< height; y++ )   
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
#         // 初始化控制点轮廓    
# SnakeInital(snake, realnumber, controlnum, width, height, graydata8, radius);   
#    
#    
# // 贪心算法搜索      
# SnakeMotionAlgorithm(snake, realnumber, controlnum*2, graydata8,   
#                                 width, height,  count,lamda );   
# for(int i=0;i<realnumber;i++) {="" graydata[(width*snake[i].y+snake[i].x)*3]="255;" graydata[(width*(snake[i].y+1)+snake[i].x)*3]="255;" graydata[(width*snake[i].y+snake[i].x+1)*3]="255;" graydata[(width*(snake[i].y-1)+snake[i].x)*3]="255;" graydata[(width*snake[i].y+snake[i].x-1)*3]="255;" graydata[(width*snake[i].y+snake[i].x)*3+1]="0;" graydata[(width*(snake[i].y+1)+snake[i].x)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x+1)*3+1]="0;" graydata[(width*(snake[i].y-1)+snake[i].x)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x-1)*3+1]="0;" graydata[(width*snake[i].y+snake[i].x)*3+2]="0;//红点" graydata[(width*(snake[i].y+1)+snake[i].x)*3+2]="0;" graydata[(width*snake[i].y+snake[i].x+1)*3+2]="0;" graydata[(width*(snake[i].y-1)+snake[i].x)*3+2]="0;" graydata[(width*snake[i].y+snake[i].x-1)*3+2]="0;" graydata8[width*snake[i].y+snake[i].x]="255;" graydata8[width*int(0.5*(snake[i+1].y+snake[i].y))+int(0.5*(snake[i+1].x+snake[i].x))]="255;" *="" file_edge,="" wb="" graydata,="" width,24,="" imagedatawrite(="" graydata8,="" height,="" width,8,="" fclose(="" f_edge="fopen(" );="" graydata;="" graydata8;="" delete="" snake;="" }=""></realnumber;i++)></countnum;></realnumber+1;></minengery></realnumber+1;></countnum;></setnumber-1></number+1;></realnumber+1;></realnumber+1;></len;></bal[i]></len;></realnumber;></len;></grad[i])></len;></len;></curv[i]></len;></len;></distone[i]></len;></realnumber+1;></realnumber+1;></realnumber+1;></number;></rightx;></righty;></rightx;></righty;></nwindowsize;></nwindowsize;></iostream.h></math.h></string.h></stdlib.h></stdio.h></assert.h>  