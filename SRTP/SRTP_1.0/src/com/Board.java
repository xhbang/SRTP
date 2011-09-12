package com;

import java.sql.*;

public class Board extends ExecuteDB
{
	//定义类成员变量
	private long BoardID;
	private String BoardName;
	private String strSql;
    
    //构造函数，对成员变量进行初始化赋值
	public Board()
	{       
		this.BoardID=0;
		this.BoardName="";
		this.strSql="";
	}   
  
	//添加新讨论区，往boards数据表中添加一条新记录
	public boolean add()
	{
	    
		this.strSql="insert into boards ";
		this.strSql=this.strSql + "(BoardName) ";        
		this.strSql=this.strSql + "values('" + this.BoardName + "')";
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
   
	//修改BoardID对应的讨论区的信息
	public boolean modify()
	{
		this.strSql="update boards set";
		this.strSql=this.strSql + " BoardName=" + "'" + this.BoardName + "'";	
		this.strSql=this.strSql + " where BoardID='" + this.BoardID + "'";
		boolean isUpdate = super.exeSql(this.strSql);
		
		return isUpdate;
	}
	
	//删除属于某个集合中的讨论区信息
	public boolean delete(String sBoardID)
	{
		this.strSql="delete from boards";
		this.strSql=this.strSql + "  where BoardID in ("+sBoardID+")";
		
		boolean isDelete = super.exeSql(this.strSql);      
		return isDelete;	
	}

	
   
 	//获得BoardID对应的讨论区的信息，将这些信息赋值给相应的类变量
	public boolean init()
	{
		this.strSql="select * from `boards` where BoardID=";
		this.strSql=this.strSql + "'" + this.BoardID + "'";        
		try
		{
			ResultSet rs = super.exeQuery(this.strSql);
			if (rs.next())
			{
				this.BoardID=rs.getLong("BoardID");
				this.BoardName=rs.getString("BoardName");
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

 	//判断讨论区名是否存在
	public boolean exist()
	{
		this.strSql="select * from `boards` ";
		this.strSql=this.strSql + " where BoardName='" + this.BoardName + "'";	
		System.out.println(strSql);  
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
		catch(Exception e)
		{		    
			System.out.println(e.toString());  
			return false;
		}
	
	}
 
	//获得所有讨论区信息，返回一个ResultSet对象
	public ResultSet show_all()
	{
		this.strSql="select * from `boards` order by BoardName asc";
		ResultSet rs = null;              
		try
		{
			rs = super.exeQuery(this.strSql); 
		}
		catch(Exception ex)
		{
			System.out.println(ex.toString()); 
		}
		return rs;	    
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

	//设置类成员变量BoardName的值
 	public void setBoardName(String BoardName)
	{
		this.BoardName = BoardName;	
	}
   
	//获取类成员变量BoardName的值  
	public String getBoardName()
	{
		return this.BoardName;	
	}
}

