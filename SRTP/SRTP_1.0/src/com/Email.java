package com;

import java.sql.*;
import java.text.DateFormat;

public class Email extends ExecuteDB
{ 
	//定义类成员变量
	private long EmailID;
	private String Subject;
	private String Content;
	private String Sender;
	private String Receiver;
	private String CreateTime;
	private int Tag;
	private String strSql;   
	
    //构造函数，对成员变量进行初始化赋值	
	public Email()
	{
		super(); 
		this.EmailID=0;
		this.Subject="";
		this.Content="";
		this.Sender="";
		this.Receiver="";
		this.Tag=0;
		java.util.Date NowTime = new java.util.Date();
		DateFormat df=DateFormat.getDateInstance();
		this.CreateTime =df.format(NowTime);
		this.strSql=""; 
	}

	//在email数据表中添加一条新记录
	public boolean add()
	{
		this.strSql="insert into email";
		this.strSql=this.strSql + " (Subject,Content,Sender,Receiver,CreateTime,Tag) ";
		this.strSql=this.strSql + "values('" + this.Subject + "','" + this.Content + "','" + this.Sender + "','" + this.Receiver + "','" + this.CreateTime + "','" + this.Tag + "')";   
		
		boolean isAdd = super.exeSql(this.strSql);
		return isAdd;	
	}
	
	//删除属于某个集合中的邮件
	public boolean delete(String sEmailID)
	{
		this.strSql="delete from email";
		this.strSql=this.strSql + "  where EmailID in ("+sEmailID+")";
		
		boolean isDelete = super.exeSql(this.strSql);      
		return isDelete;	
	}

  	//获取邮件详细信息，将这些信息赋值给相应的类变量
	public boolean  init()
	{
		this.strSql="select * from email";
		this.strSql=this.strSql + " where EmailID='" + this.EmailID + "'";

		try
		{
			ResultSet rs = super.exeQuery(this.strSql);
			if (rs.next())
			{
				this.EmailID=rs.getLong("EmailID");
				this.Subject=rs.getString("Subject");
				this.Content=rs.getString("Content");
				this.Sender=rs.getString("Sender");
				this.Receiver=rs.getString("Receiver");
				this.CreateTime=rs.getString("CreateTime"); 
				this.Tag=rs.getInt("Tag");
				return true;
			}
			else
			{               
				return false;
			}	
		}
		catch(Exception e)
		{			
			System.out.println(e.toString());            
			return false;
		}
	}

	//获得Receiver对应的接收邮件信息，返回一个ResultSet类型对象
	public ResultSet rec_list()
	{
		this.strSql="select * from email where Receiver=";
		this.strSql=this.strSql + "'" + this.Receiver + "' order by CreateTime desc";
		try
		{
			ResultSet rs = super.exeQuery(this.strSql);
			if(rs == null)
			{
				System.out.println("test"); 			
			}               
                                  
			return rs;          
		}
		catch(Exception e)
		{			
			System.out.println(e.toString()); 
			return null;
		}
	}
	
	//更改类成员变量tag的值
	public boolean update_tag()
	{
		this.strSql="update email set ";
		this.strSql=this.strSql + " Tag=" + "'" + 1 + "'";
		this.strSql=this.strSql + " where EmailID='" + this.EmailID + "'";
		boolean updateTag = super.exeSql(strSql);		
		return updateTag;
	}
  
   	//设置类成员变量EmailID的值 
	public void setEmailID(long EmailID)
	{
		this.EmailID = EmailID;	
	}

	//获取类成员变量EmailID的值  
	public long getEmailID()
	{
		return this.EmailID;	
	}

	//设置类成员变量Subject的值  
 	public void setSubject(String Subject)
	{
		this.Subject = Subject;	
	}
   
	//获取类成员变量Subject的值  
	public String getSubject()
	{
		return this.Subject;	
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
 
 	//设置类成员变量Sender的值 
 	public void setSender(String Sender)
	{
		this.Sender = Sender;	
	}   

	//获取类成员变量Sender的值  
	public String getSender()
	{
		return this.Sender;	
	}  

	//设置类成员变量Receiver的值  
 	public void setReceiver(String Receiver)
	{
		this.Receiver = Receiver;	
	}
   
	//获取类成员变量Receiver的值  
	public String getReceiver()
	{
		return this.Receiver;	
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
 
 	//设置类成员变量Tag的值 
 	public void setTag(int Tag)
	{
		this.Tag = Tag;	
	}   

	//获取类成员变量Tag的值  
	public int getTag()
	{
		return this.Tag;	
	} 

}
