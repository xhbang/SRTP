package com;

import java.sql.*;
import java.text.DateFormat;

public class User extends ExecuteDB
{
	//定义类成员变量
	private long UserID;
	private String UserName;
	private String UserPassword; 
	private String Email;  
	private String Sex;      
	private String NickName;     
	private String CreateTime; 
	private String Role;
	private String strSql;
    
    //构造函数，对成员变量进行初始化赋值
	public User()
	{  
		super(); 
		this.UserID=0;
		this.UserName="";
		this.UserPassword="";        
		this.Sex="";
		this.NickName="";
		this.Email="";  
		this.Role = "0";
		java.util.Date NowTime = new java.util.Date();
		DateFormat df=DateFormat.getDateInstance();
		this.CreateTime =df.format(NowTime);                    
		this.strSql="";
	}   
  
	//添加新用户，往users数据表中添加一条新记录
	public boolean add()
	{
	    
		this.strSql="insert into users ";
		this.strSql=this.strSql + "(UserName,UserPassword,Email,Sex,NickName,CreateTime) ";        
		this.strSql=this.strSql + "values('" + this.UserName + "','" + this.UserPassword + "','" + this.Email + "','" + this.Sex + "','" + this.NickName + "','" + this.CreateTime + "')";
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
   
	//修改UserID对应的用户的信息
	public boolean modify_info()
	{
		this.strSql="update users set";
		this.strSql=this.strSql + " Email=" + "'" + this.Email + "',";
		this.strSql=this.strSql + " Sex=" + "'" + this.Sex + "',";
		this.strSql=this.strSql + " NickName=" + "'" + this.NickName + "',";		
		this.strSql=this.strSql + " CreateTime=" + "'" + this.CreateTime + "'";
		this.strSql=this.strSql + " where UserID='" + this.UserID + "'";
		boolean isUpdate = super.exeSql(this.strSql);
		
		return isUpdate;
	}

	//修改UserID对应的用户的密码
 	public boolean modify_UserPassword()
 	{
		this.strSql="update users set ";
		this.strSql=this.strSql + "UserPassword=" + "'" + this.UserPassword + "'";
		this.strSql=this.strSql + " where UserID='" + this.UserID + "'";
		boolean isUpdatekey = super.exeSql(this.strSql);

		return isUpdatekey;
	}
  
 	//获得UserID对应的用户的信息，将这些信息赋值给相应的类变量
	public boolean init()
	{
		this.strSql="select * from `users` where UserID=";
		this.strSql=this.strSql + "'" + this.UserID + "'";        

		try
		{
			ResultSet rs = super.exeQuery(this.strSql);
			if (rs.next())
			{
				this.UserID=rs.getLong("UserID");
				this.UserName=rs.getString("UserName");
				this.UserPassword=rs.getString("UserPassword");
				this.Sex=rs.getString("Sex");
				this.NickName=rs.getString("NickName");
				this.Email=rs.getString("Email"); 
				this.CreateTime=rs.getString("CreateTime");			    
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

	//验证用户名和密码是否正确
	public boolean valid()
	{
		this.strSql="select UserID,UserName,Role from `users` ";
		this.strSql=this.strSql + " where UserName='" + this.UserName + "'";
		this.strSql=this.strSql + "  and UserPassword='"+ this.UserPassword + "'";         
		System.out.println(this.strSql);            

		try
		{
			ResultSet rs = super.exeQuery(this.strSql); 
			if (rs.next())
			{
				this.UserID=rs.getLong("UserID");
				this.UserName=rs.getString("UserName");
				this.Role = rs.getString("Role");
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
   
   	//判断用户名是否存在
	public boolean exist()
	{
		this.strSql="select * from `users` ";
		this.strSql=this.strSql + " where UserName='" + this.UserName + "'";  

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

	//设置类成员变量UserName的值
 	public void setUserName(String UserName)
	{
		this.UserName = UserName;	
	}
   
	//获取类成员变量UserName的值  
	public String getUserName()
	{
		return this.UserName;	
	}

	//设置类成员变量UserPassword的值  
 	public void setUserPassword(String UserPassword)
	{
		this.UserPassword = UserPassword;	
	}
   
	//获取类成员变量UserPassword的值  
	public String getUserPassword()
	{
		return this.UserPassword;	
	}

	//设置类成员变量Email的值 
	public void setEmail(String Email)
	{
		this.Email = Email;	
	}

	//获取类成员变量Email的值  
	public String getEmail()
	{
		return this.Email;	
	}

	//设置类成员变量Sex的值  
 	public void setSex(String Sex)
	{
		this.Sex = Sex;	
	}
   
	//获取类成员变量Sex的值  
	public String getSex()
	{
		return this.Sex;	
	}

	//设置类成员变量NickName的值  
 	public void setNickName(String NickName)
	{
		this.NickName = NickName;	
	}
   
	//获取类成员变量NickName的值  
	public String getNickName()
	{
		return this.NickName;	
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
	
	//设置类成员变量Role的值 
 	public void setRole(String Role)
	{
		this.Role = Role;	
	}   

	//获取类成员变量Role的值  
	public String getRole()
	{
		return this.Role;	
	}  
}

