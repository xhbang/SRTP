1. 概述

float和double类型的主要设计目的是为了科学计算和工程计算。它们执行二进制浮点运算，这是为了在广域数值范围上提供较为精确的快速近似计算而精心设计的。然而，它们没有提供完全精确的结果，所以不应该被用于要求精确结果的场合。float和double类型对于货币计算尤为不合适，因为要让一个float或者double精确地表示0.1(或者10的任何负数次方值)是不可能的，比如System.out.println(2.0-1.1)将会打印0.899999999999999,而不是你所希望的0.9，这种舍入错误产生的原因是浮点数实际上是用二进制系统实现的，而分数1/10在二进制系统中没有精确的表示，其道理就如同在十进制系统中无法精确表示1/3一样；再比如0.5在二进制系统中有精确表示，而0.55在二进制系统中没有精确表示。

许多数都是无法在有限的n内完全精确的表示出来的，我们只能利用更大的n值来更精确的表示这个数，但更大的n也只是更加逼近精确值而无法得到精确值。例如

   1. public static void main(String[] args) {
   2.     System.out.println("100.5 - 100                 = " + (100.5 - 100));
   3.     System.out.println("100.5F - 100F               = " + (100.5F - 100F));
   4.     System.out.println("100.55 - 100.00             = " + (100.55 - 100.00));
   5.     System.out.println("100.55F - 100.00F           = " + (100.55F - 100.00F));
   6.     System.out.println("new Double(100.55 - 100.00) = " + new Double(100.55 - 100.00));
   7.     System.out.println("new Float(100.55 - 100.00)  = " + new Float(100.55 - 100.00));
   8.     System.out.println("(double)(100.55 - 100.00)   = " + (double)(100.55 - 100.00));
   9.     System.out.println("(float)(100.55 - 100.00)    = " + (float)(100.55 - 100.00));
  10.     
  11.     System.out.println("2.0 - 1.1               = " + (2.0 - 1.1));
  12.     System.out.println("2.0F - 1.1F             = " + (2.0F - 1.1F));
  13.     System.out.println("new Double(2.0 - 1.1)   = " + new Double(2.0 - 1.1));
  14.     System.out.println("new Float(2.0 - 1.1)    = " + new Float(2.0 - 1.1));
  15.     System.out.println("(double)(2.0 - 1.1)     = " + (double)(2.0 - 1.1));
  16.     System.out.println("(float)(2.0 - 1.1)      = " + (float)(2.0 - 1.1));
  17.
  18.     System.out.println("1.0 - 0.9               = " + (1.0 - 0.9));
  19.     System.out.println("1.0F - 0.9F             = " + (1.0F - 0.9F));
  20.     System.out.println("new Double(1.0 - 0.9)   = " + new Double(1.0 - 0.9));
  21.     System.out.println("new Float(1.0 - 0.9)    = " + new Float(1.0 - 0.9));
  22.     System.out.println("(double)(1.0 - 0.9)     = " + (double)(1.0 - 0.9));
  23.     System.out.println("(float)(1.0 - 0.9)      = " + (float)(1.0 - 0.9));
  24.     /*
  25.      * 输出结果：
  26.      * 100.5 - 100                 = 0.5
  27.      * 100.5F - 100F               = 0.5
  28.      * 100.55 - 100.00             = 0.5499999999999972
  29.      * 100.55F - 100.00F           = 0.55000305
  30.      * new Double(100.55 - 100.00) = 0.5499999999999972
  31.      * new Float(100.55 - 100.00)  = 0.55 (将一个Double转换为Float自然会有精度丢失, 所以舍入为0.55)
  32.      * (double)(100.55 - 100.00)   = 0.5499999999999972
  33.      * (float)(100.55 - 100.00)    = 0.55 (将一个double转换为float自然会有精度丢失, 所以舍入为0.55)
  34.      * 
  35.      * 2.0 - 1.1                = 0.8999999999999999
  36.      * 2.0F - 1.1F              = 0.9 (这里用Float可以得到正确值, 我不知道原因, 你去问cpu吧. 只要记住这是一个巧合就可以了)
  37.      * new Double(2.0 - 1.1)    = 0.8999999999999999
  38.      * new Float(2.0 - 1.1)     = 0.9 (将一个Double转换为Float自然会有精度丢失, 所以舍入为0.9)
  39.      * (double)(2.0 - 1.1)      = 0.8999999999999999
  40.      * (float)(2.0 - 1.1)       = 0.9 (将一个double转换为float自然会有精度丢失, 所以舍入为0.9)
  41.      * 
  42.      * 1.0 - 0.9                = 0.09999999999999998
  43.      * 1.0F - 0.9F              = 0.100000024
  44.      * new Double(1.0 - 0.9)    = 0.09999999999999998
  45.      * new Float(1.0 - 0.9)     = 0.1 (将一个Double转换为Float自然会有精度丢失, 所以舍入为0.1)
  46.      * (double)(1.0 - 0.9)      = 0.09999999999999998
  47.      * (float)(1.0 - 0.9)       = 0.1 (将一个double转换为float自然会有精度丢失, 所以舍入为0.1)
  48.      * */
  49. }

2. 为什么浮点数会丢失精度(浮点数没办法用十进制来精确表示)

(1)十进制与二进制转换

要归咎于CPU表示浮点数的方法：2.4的二进制表示并非就是精确的2.4，而是最为接近2.3999999999999999；原因在于浮点数由两部分组成：指数和尾数，浮点数的值实际上是由cpu的某个数学公式计算得到的，所以您所遇到的精度损失会在任何操作系统和编程环境中遇到。

(2)类型失配

您可能混合了浮点数和双精度浮点数类型。请确定您在进行数学运算的时候所有的数据类型全部相同。注意：float类型的变量只有7位的精度，而double类型的变量有15位的精度。

3. 解决方法

(1)java.lang.Math中的public static int round(float a)和public static long round(double a)不能解决问题； java.lang.Object --> java.text.Format --> java.text.NumberFormat --> java.text.DecimalFormat 也不能解决问题
(2)使用BigDecimal、int或long(将小数转换为整数再进行计算，例如：将以美元为单位的货币计算改为以美分为单位的货币计算)。java.lang.Object --> java.lang.Number -- Direct Known Subclasses: BigDecimal, Byte, Double, Float, Integer, Long, Short

BigDecimal常用构造方法：

public BigDecimal(double val) --> Translates a double into a BigDecimal which is the exact decimal representation of the double's binary floating-point value.

public BigDecimal(String val) --> Translates the string representation of a BigDecimal into a BigDecimal

通常情况下，上面的那一个使用起来要方便一些。我们可能想都不想就用上了，会有什么问题呢？等到出了问题的时候，才发现上面哪个够造方法的详细说明中有这么一段。

The results of this constructor can be somewhat unpredictable. One might assume that writing new BigDecimal(0.1) in Java creates a BigDecimal which is exactly equal to 0.1 (an unscaled value of 1, with a scale of 1), but it is actually equal to 0.1000000000000000055511151231257827021181583404541015625. This is because 0.1 cannot be represented exactly as a double (or, for that matter, as a binary fraction of any finite length). Thus, the value that is being passed in to the constructor is not exactly equal to 0.1, appearances notwithstanding.

The String constructor, on the other hand, is perfectly predictable: writing new BigDecimal("0.1") creates a BigDecimal which is exactly equal to 0.1, as one would expect. Therefore, it is generally recommended that the String constructor be used in preference to this one.

When a double must be used as a source for a BigDecimal, note that this constructor provides an exact conversion; it does not give the same result as converting the double to a String using the Double.toString(double) method and then using the BigDecimal(String) constructor. To get that result, use the static valueOf(double) method.

原来我们如果需要精确计算，非要用String来够造BigDecimal不可！在《Effective Java》一书中的例子也是用String来够造BigDecimal的，但是书上却没有强调这一点，这也许是一个小小的失误吧。

使用BigDecimal加法运算步骤：(1)将两个浮点数转为String，然后构造成BigDecimal；(2)在其中一个上调用add() 方法，传入另一个作为参数，然后把运算的结果(BigDecimal)再转换为浮点数。这样比较繁琐，我们可以自己写一个工具类Arith来简化操作：

   1. package edu.hust.test;
   2.
   3. import java.math.BigDecimal;
   4. /**
   5.  * 由于Java的简单类型不能够精确的对浮点数进行运算，这个工具类提供精确的浮点数运算，包括加减乘除和四舍五入。
   6.  * 所以提供以下静态方法：
   7.  * public static double add(double v1,double v2)
   8.  * public static double sub(double v1,double v2)
   9.  * public static double mul(double v1,double v2)
  10.  * public static double div(double v1,double v2)
  11.  * public static double div(double v1,double v2,int scale)
  12.  * public static double round(double v,int scale)
  13.  * 
  14.  */
  15. public class Arith {
  16.     //默认除法运算精度
  17.     private static final int DEF_DIV_SCALE = 10;
  18.     //这个类不能实例化
  19.     private Arith(){}
  20.
  21.     /**
  22.      * 提供精确的加法运算。
  23.      * @param v1 被加数
  24.      * @param v2 加数
  25.      * @return 两个参数的和
  26.      */
  27.     public static double add(double v1,double v2){
  28.         BigDecimal b1 = new BigDecimal(Double.toString(v1));
  29.         BigDecimal b2 = new BigDecimal(Double.toString(v2));
  30.         return b1.add(b2).doubleValue();
  31.     }
  32.     /**
  33.      * 提供精确的减法运算。
  34.      * @param v1 被减数
  35.      * @param v2 减数
  36.      * @return 两个参数的差
  37.      */
  38.     public static double sub(double v1,double v2){
  39.         BigDecimal b1 = new BigDecimal(Double.toString(v1));
  40.         BigDecimal b2 = new BigDecimal(Double.toString(v2));
  41.         return b1.subtract(b2).doubleValue();
  42.     } 
  43.     /**
  44.      * 提供精确的乘法运算。
  45.      * @param v1 被乘数
  46.      * @param v2 乘数
  47.      * @return 两个参数的积
  48.      */
  49.     public static double mul(double v1,double v2){
  50.         BigDecimal b1 = new BigDecimal(Double.toString(v1));
  51.         BigDecimal b2 = new BigDecimal(Double.toString(v2));
  52.         return b1.multiply(b2).doubleValue();
  53.     }
  54.
  55.     /**
  56.      * 提供（相对）精确的除法运算，当发生除不尽的情况时，精确到小数点以后10位，以后的数字四舍五入。
  57.      * @param v1 被除数
  58.      * @param v2 除数
  59.      * @return 两个参数的商
  60.      */
  61.     public static double div(double v1,double v2){
  62.         return div(v1,v2,DEF_DIV_SCALE);
  63.     }
  64.
  65.     /**
  66.      * 提供（相对）精确的除法运算。当发生除不尽的情况时，由scale参数指定精度，以后的数字四舍五入。
  67.      * @param v1 被除数
  68.      * @param v2 除数
  69.      * @param scale 表示表示需要精确到小数点以后几位。
  70.      * @return 两个参数的商
  71.      */
  72.     public static double div(double v1,double v2,int scale){
  73.         if(scale<0){
  74.             throw new IllegalArgumentException("The scale must be a positive integer or zero");
  75.         }
  76.         BigDecimal b1 = new BigDecimal(Double.toString(v1));
  77.         BigDecimal b2 = new BigDecimal(Double.toString(v2));
  78.         return b1.divide(b2,scale,BigDecimal.ROUND_HALF_UP).doubleValue();
  79.     }
  80.
  81.     /**
  82.      * 提供精确的小数位四舍五入处理。
  83.      * @param v 需要四舍五入的数字
  84.      * @param scale 小数点后保留几位
  85.      * @return 四舍五入后的结果
  86.      */
  87.     public static double round(double v,int scale){
  88.         if(scale<0){
  89.             throw new IllegalArgumentException("The scale must be a positive integer or zero");
  90.         }
  91.         BigDecimal b = new BigDecimal(Double.toString(v));
  92.         BigDecimal one = new BigDecimal("1");
  93.         return b.divide(one,scale,BigDecimal.ROUND_HALF_UP).doubleValue();
  94.     }
  95. }

使用BigDecimal缺点：要创建对象并占用内存；其floatValue()方法有时会精度丢失而造成计算错误(所以一般小数计算尽量使用double)。

最后补充一点：也正因为此，浮点数不能用于循环判断，否则容易造成死循环。

