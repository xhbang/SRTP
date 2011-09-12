package com;

import java.sql.*;
import java.text.DateFormat;

public class User extends ExecuteDB
{
	//�������Ա����
	private long UserID;
	private String UserName;
	private String UserPassword; 
	private String Email;  
	private String Sex;      
	private String NickName;     
	private String CreateTime; 
	private String Role;
	private String strSql;
    
    //���캯�����Գ�Ա�������г�ʼ����ֵ
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
  
	//������û�����users���ݱ������һ���¼�¼
	public boolean add()
	{
	    
		this.strSql="insert into users ";
		this.strSql=this.strSql + "(UserName,UserPassword,Email,Sex,NickName,CreateTime) ";        
		this.strSql=this.strSql + "values('" + this.UserName + "','" + this.UserPassword + "','" + this.Email + "','" + this.Sex + "','" + this.NickName + "','" + this.CreateTime + "')";
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
   
	//�޸�UserID��Ӧ���û�����Ϣ
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

	//�޸�UserID��Ӧ���û�������
 	public boolean modify_UserPassword()
 	{
		this.strSql="update users set ";
		this.strSql=this.strSql + "UserPassword=" + "'" + this.UserPassword + "'";
		this.strSql=this.strSql + " where UserID='" + this.UserID + "'";
		boolean isUpdatekey = super.exeSql(this.strSql);

		return isUpdatekey;
	}
  
 	//���UserID��Ӧ���û�����Ϣ������Щ��Ϣ��ֵ����Ӧ�������
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

	//��֤�û����������Ƿ���ȷ
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
   
   	//�ж��û����Ƿ����
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

	//�������Ա����UserName��ֵ
 	public void setUserName(String UserName)
	{
		this.UserName = UserName;	
	}
   
	//��ȡ���Ա����UserName��ֵ  
	public String getUserName()
	{
		return this.UserName;	
	}

	//�������Ա����UserPassword��ֵ  
 	public void setUserPassword(String UserPassword)
	{
		this.UserPassword = UserPassword;	
	}
   
	//��ȡ���Ա����UserPassword��ֵ  
	public String getUserPassword()
	{
		return this.UserPassword;	
	}

	//�������Ա����Email��ֵ 
	public void setEmail(String Email)
	{
		this.Email = Email;	
	}

	//��ȡ���Ա����Email��ֵ  
	public String getEmail()
	{
		return this.Email;	
	}

	//�������Ա����Sex��ֵ  
 	public void setSex(String Sex)
	{
		this.Sex = Sex;	
	}
   
	//��ȡ���Ա����Sex��ֵ  
	public String getSex()
	{
		return this.Sex;	
	}

	//�������Ա����NickName��ֵ  
 	public void setNickName(String NickName)
	{
		this.NickName = NickName;	
	}
   
	//��ȡ���Ա����NickName��ֵ  
	public String getNickName()
	{
		return this.NickName;	
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
	
	//�������Ա����Role��ֵ 
 	public void setRole(String Role)
	{
		this.Role = Role;	
	}   

	//��ȡ���Ա����Role��ֵ  
	public String getRole()
	{
		return this.Role;	
	}  
}

