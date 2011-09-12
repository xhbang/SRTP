package com;

import java.sql.*;
import java.text.DateFormat;

public class Article extends ExecuteDB
{
	//定义类成员变量
	private long ArticleID;
	private String Title;
	private String Content; 
	private long UserID;  
	private long BoardID;   
	private long FatherID; 
	private int ReadCount; 
	private int ReCount;    
	private String PicUrl;
	private String PicName;
	private String CreateTime;   
	private String strSql;
   
    //构造函数，对成员变量进行初始化赋值
	public Article()
	{       
		this.ArticleID=0;
		this.Title="";
		this.Content="";        
		this.BoardID=0;
		this.ReCount=0;
		this.ReadCount=0;       
		this.PicUrl="";
		this.PicName="";
		this.FatherID=0;
		this.UserID=0;                      
		java.util.Date NowTime = new java.util.Date();
		DateFormat df=DateFormat.getDateInstance();
		this.CreateTime =df.format(NowTime);                    
		this.strSql="";
	}
   
	//添加新文章，往articles数据表中添加一条新记录
	public boolean add()
	{	
		this.strSql="insert into articles ";
		this.strSql=this.strSql + "(";
		this.strSql=this.strSql + "Title,Content,UserID,BoardID,FatherID,ReadCount,ReCount,PicUrl,PicName,CreateTime)";		
		this.strSql=this.strSql + "values('" + this.Title + "','" + this.Content + "','" + this.UserID + "','" + this.BoardID + "','" + this.FatherID + "','" + this.ReadCount + "','" + this.ReCount + "','" + this.PicUrl + "','" + this.PicName + "','" + this.CreateTime + "')";		
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
  
  	//删除ArticleID对应的文章的信息
	public boolean delete()
	{
		this.strSql="delete from `articles` where ArticleID='";
		this.strSql=this.strSql + this.ArticleID + "'";
		boolean isDelete = super.exeSql(this.strSql);
        
		return isDelete;
	}

	//验证ArticleID和UserID是否匹配  
	public boolean valid()
	{
		this.strSql="select ArticleID from `articles` ";
		this.strSql=this.strSql + " where ArticleID='" + this.ArticleID + "'";
		this.strSql=this.strSql + "  and UserID='"+ this.UserID + "'";         
		System.out.println(this.strSql);            

		try
		{
			ResultSet rs = super.exeQuery(this.strSql); 
			if (rs.next())
			{
				return true;
			}
			else
			{                
				return false;
			}
		}
		catch(Exception ex)
		{            
			return false;
		}       
	}
	
	
   
  	//获取ArticleID对应的文章的信息，将这些信息赋值给相应的类变量
	public boolean  init()
	{
    	this.strSql="select * from `articles` where ArticleID=";
        this.strSql=this.strSql + "'" + this.ArticleID + "'";        
        try
		{
   			ResultSet rs = super.exeQuery(this.strSql);
			if (rs.next())
			{
                ArticleID=rs.getLong("ArticleID");
                Title=rs.getString("Title");
                Content=rs.getString("Content");
                BoardID=rs.getLong("BoardID");
                FatherID=rs.getLong("FatherID");
                ReadCount=rs.getInt("ReadCount");
                UserID=rs.getLong("UserID"); 
                ReCount=rs.getInt("ReCount");
                PicUrl=rs.getString("PicUrl");
                PicName=rs.getString("PicName");
                CreateTime=rs.getString("CreateTime");
                return true;
			}
			else
			{
				return false;
			}
		}
		catch(Exception ex)
		{
			return false;
		}        
	}

	//获得FatherID相同的一组文章的信息，返回一个ResultSet类型对象
	public ResultSet show_son_articles()
	{	
		this.strSql="select * from `articles`";
        this.strSql=this.strSql + " where FatherID = '" + this.FatherID + "'";        
		ResultSet rs = null;              
		try
		{
			rs = super.exeQuery(this.strSql); 
		}
		catch(Exception e)
		{
			System.out.println(e.toString()); 
		}
		return rs;	    
	}

  	//获得BoardID对应的讨论区的所有主贴的文章信息，返回一个ResultSet类型对象
	public ResultSet show_board_articles()
	{	
		this.strSql="select ArticleID,Title,UserID,ReadCount,ReCount,CreateTime from `articles`";
        this.strSql=this.strSql + " where BoardID = '" + this.BoardID + "'";        
        this.strSql=this.strSql + " and FatherID = '0' order by CreateTime desc";
		ResultSet rs = null;              
		try
		{
			rs = super.exeQuery(this.strSql); 
		}
		catch(Exception e)
		{
			System.out.println(e.toString()); 
		}
		return rs;	    
	}
	
	//获得BoardID对应的讨论区的所有主贴的数量
	public int articles_count()
	{	
		this.strSql="select ArticleID,Title,UserID,ReadCount,ReCount,CreateTime from `articles`";
        this.strSql=this.strSql + " where BoardID = '" + this.BoardID + "'";        
        this.strSql=this.strSql + " and FatherID = '0'";
        ResultSet rs = null; 
		try
		{
			rs = super.exeQuery(this.strSql);
			rs.last();
			return rs.getRow();	
		}
		catch(Exception e)
		{
			System.out.println(e.toString()); 
			return 0;
		}  
	}
	
	
	//更改articles数据表中ArticleID所对应的ReadCount的值
	public boolean modify_ReadCount()
	{
		this.strSql="update articles set";
		this.strSql=this.strSql + " ReadCount = '"+this.ReadCount+"'";	
		this.strSql=this.strSql + " where ArticleID='" + this.ArticleID + "'";
		boolean isModify = super.exeSql(this.strSql);
		
		return isModify;
	}
	
	//更改articles数据表中ArticleID所对应的ReCount的值
	public boolean modify_ReCount()
	{
		this.strSql="update articles set";
		this.strSql=this.strSql + " ReCount = '"+this.ReCount+"'";	
		this.strSql=this.strSql + " where ArticleID='" + this.ArticleID + "'";
		boolean isModify = super.exeSql(this.strSql);
		
		return isModify;
	}


  	//设置类成员变量ArticleID的值
	public void setArticleID(long ArticleID)
	{
		this.ArticleID = ArticleID;	
	}
   
	//获取类成员变量ArticleID的值  
	public long getArticleID()
	{
		return this.ArticleID;	
	}

	//设置类成员变量Title的值
 	public void setTitle(String Title)
	{
		this.Title = Title;	
	}
   
	//获取类成员变量Title的值  
	public String getTitle()
	{
		return this.Title;	
	}

	//设置类成员变量Content的值  
 	public void setContent(String Content)
	{
		this.Content = Content;	
	}
   
	//获取类成员变量Content的值  
	public String getContent()
	{
		return this.Content;	
	}

	//设置类成员变量UserID的值 
	public void setUserID(long UserID)
	{
		this.UserID = UserID;	
	}

	//获取类成员变量UserID的值  
	public long getUserID()
	{
		return this.UserID;	
	}

	//设置类成员变量BoardID的值  
 	public void setBoardID(long BoardID)
	{
		this.BoardID = BoardID;	
	}
   
	//获取类成员变量BoardID的值  
	public long getBoardID()
	{
		return this.BoardID;	
	}

	//设置类成员变量FatherID的值  
 	public void setFatherID(long FatherID)
	{
		this.FatherID = FatherID;	
	}
   
	//获取类成员变量FatherID的值  
	public long getFatherID()
	{
		return this.FatherID;	
	}

 	//设置类成员变量CreateTime的值 
 	public void setCreateTime(String CreateTime)
	{
		this.CreateTime = CreateTime;	
	}   

	//获取类成员变量CreateTime的值  
	public String getCreateTime()
	{
		return this.CreateTime;	
	}  

	//设置类成员变量ReadCount的值 
	public void setReadCount(int ReadCount)
	{
		this.ReadCount = ReadCount;	
	}

	//获取类成员变量ReadCount的值  
	public int getReadCount()
	{
		return this.ReadCount;	
	}

	//设置类成员变量ReCount的值  
 	public void setReCount(int ReCount)
	{
		this.ReCount = ReCount;	
	}
   
	//获取类成员变量ReCount的值  
	public int getReCount()
	{
		return this.ReCount;	
	}
 
 	//设置类成员变量PicUrl的值 
 	public void setPicUrl(String PicUrl)
	{
		this.PicUrl = PicUrl;	
	}   

	//获取类成员变量PicUrl的值  
	public String getPicUrl()
	{
		return this.PicUrl;	
	}  
	
	//设置类成员变量PicName的值 
 	public void setPicName(String PicName)
	{
		this.PicName = PicName;	
	}   

	//获取类成员变量PicName的值  
	public String getPicName()
	{
		return this.PicName;	
	}  	
}

