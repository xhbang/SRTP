package com;

import java.sql.*;
import java.text.DateFormat;

public class Article extends ExecuteDB
{
	//�������Ա����
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
   
    //���캯�����Գ�Ա�������г�ʼ����ֵ
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
   
	//��������£���articles���ݱ������һ���¼�¼
	public boolean add()
	{	
		this.strSql="insert into articles ";
		this.strSql=this.strSql + "(";
		this.strSql=this.strSql + "Title,Content,UserID,BoardID,FatherID,ReadCount,ReCount,PicUrl,PicName,CreateTime)";		
		this.strSql=this.strSql + "values('" + this.Title + "','" + this.Content + "','" + this.UserID + "','" + this.BoardID + "','" + this.FatherID + "','" + this.ReadCount + "','" + this.ReCount + "','" + this.PicUrl + "','" + this.PicName + "','" + this.CreateTime + "')";		
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
  
  	//ɾ��ArticleID��Ӧ�����µ���Ϣ
	public boolean delete()
	{
		this.strSql="delete from `articles` where ArticleID='";
		this.strSql=this.strSql + this.ArticleID + "'";
		boolean isDelete = super.exeSql(this.strSql);
        
		return isDelete;
	}

	//��֤ArticleID��UserID�Ƿ�ƥ��  
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
	
	
   
  	//��ȡArticleID��Ӧ�����µ���Ϣ������Щ��Ϣ��ֵ����Ӧ�������
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

	//���FatherID��ͬ��һ�����µ���Ϣ������һ��ResultSet���Ͷ���
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

  	//���BoardID��Ӧ��������������������������Ϣ������һ��ResultSet���Ͷ���
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
	
	//���BoardID��Ӧ������������������������
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
	
	
	//����articles���ݱ���ArticleID����Ӧ��ReadCount��ֵ
	public boolean modify_ReadCount()
	{
		this.strSql="update articles set";
		this.strSql=this.strSql + " ReadCount = '"+this.ReadCount+"'";	
		this.strSql=this.strSql + " where ArticleID='" + this.ArticleID + "'";
		boolean isModify = super.exeSql(this.strSql);
		
		return isModify;
	}
	
	//����articles���ݱ���ArticleID����Ӧ��ReCount��ֵ
	public boolean modify_ReCount()
	{
		this.strSql="update articles set";
		this.strSql=this.strSql + " ReCount = '"+this.ReCount+"'";	
		this.strSql=this.strSql + " where ArticleID='" + this.ArticleID + "'";
		boolean isModify = super.exeSql(this.strSql);
		
		return isModify;
	}


  	//�������Ա����ArticleID��ֵ
	public void setArticleID(long ArticleID)
	{
		this.ArticleID = ArticleID;	
	}
   
	//��ȡ���Ա����ArticleID��ֵ  
	public long getArticleID()
	{
		return this.ArticleID;	
	}

	//�������Ա����Title��ֵ
 	public void setTitle(String Title)
	{
		this.Title = Title;	
	}
   
	//��ȡ���Ա����Title��ֵ  
	public String getTitle()
	{
		return this.Title;	
	}

	//�������Ա����Content��ֵ  
 	public void setContent(String Content)
	{
		this.Content = Content;	
	}
   
	//��ȡ���Ա����Content��ֵ  
	public String getContent()
	{
		return this.Content;	
	}

	//�������Ա����UserID��ֵ 
	public void setUserID(long UserID)
	{
		this.UserID = UserID;	
	}

	//��ȡ���Ա����UserID��ֵ  
	public long getUserID()
	{
		return this.UserID;	
	}

	//�������Ա����BoardID��ֵ  
 	public void setBoardID(long BoardID)
	{
		this.BoardID = BoardID;	
	}
   
	//��ȡ���Ա����BoardID��ֵ  
	public long getBoardID()
	{
		return this.BoardID;	
	}

	//�������Ա����FatherID��ֵ  
 	public void setFatherID(long FatherID)
	{
		this.FatherID = FatherID;	
	}
   
	//��ȡ���Ա����FatherID��ֵ  
	public long getFatherID()
	{
		return this.FatherID;	
	}

 	//�������Ա����CreateTime��ֵ 
 	public void setCreateTime(String CreateTime)
	{
		this.CreateTime = CreateTime;	
	}   

	//��ȡ���Ա����CreateTime��ֵ  
	public String getCreateTime()
	{
		return this.CreateTime;	
	}  

	//�������Ա����ReadCount��ֵ 
	public void setReadCount(int ReadCount)
	{
		this.ReadCount = ReadCount;	
	}

	//��ȡ���Ա����ReadCount��ֵ  
	public int getReadCount()
	{
		return this.ReadCount;	
	}

	//�������Ա����ReCount��ֵ  
 	public void setReCount(int ReCount)
	{
		this.ReCount = ReCount;	
	}
   
	//��ȡ���Ա����ReCount��ֵ  
	public int getReCount()
	{
		return this.ReCount;	
	}
 
 	//�������Ա����PicUrl��ֵ 
 	public void setPicUrl(String PicUrl)
	{
		this.PicUrl = PicUrl;	
	}   

	//��ȡ���Ա����PicUrl��ֵ  
	public String getPicUrl()
	{
		return this.PicUrl;	
	}  
	
	//�������Ա����PicName��ֵ 
 	public void setPicName(String PicName)
	{
		this.PicName = PicName;	
	}   

	//��ȡ���Ա����PicName��ֵ  
	public String getPicName()
	{
		return this.PicName;	
	}  	
}

