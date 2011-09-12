package com;

import java.sql.*;
import java.text.DateFormat;

public class Email extends ExecuteDB
{ 
	//�������Ա����
	private long EmailID;
	private String Subject;
	private String Content;
	private String Sender;
	private String Receiver;
	private String CreateTime;
	private int Tag;
	private String strSql;   
	
    //���캯�����Գ�Ա�������г�ʼ����ֵ	
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

	//��email���ݱ������һ���¼�¼
	public boolean add()
	{
		this.strSql="insert into email";
		this.strSql=this.strSql + " (Subject,Content,Sender,Receiver,CreateTime,Tag) ";
		this.strSql=this.strSql + "values('" + this.Subject + "','" + this.Content + "','" + this.Sender + "','" + this.Receiver + "','" + this.CreateTime + "','" + this.Tag + "')";   
		
		boolean isAdd = super.exeSql(this.strSql);
		return isAdd;	
	}
	
	//ɾ������ĳ�������е��ʼ�
	public boolean delete(String sEmailID)
	{
		this.strSql="delete from email";
		this.strSql=this.strSql + "  where EmailID in ("+sEmailID+")";
		
		boolean isDelete = super.exeSql(this.strSql);      
		return isDelete;	
	}

  	//��ȡ�ʼ���ϸ��Ϣ������Щ��Ϣ��ֵ����Ӧ�������
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

	//���Receiver��Ӧ�Ľ����ʼ���Ϣ������һ��ResultSet���Ͷ���
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
	
	//�������Ա����tag��ֵ
	public boolean update_tag()
	{
		this.strSql="update email set ";
		this.strSql=this.strSql + " Tag=" + "'" + 1 + "'";
		this.strSql=this.strSql + " where EmailID='" + this.EmailID + "'";
		boolean updateTag = super.exeSql(strSql);		
		return updateTag;
	}
  
   	//�������Ա����EmailID��ֵ 
	public void setEmailID(long EmailID)
	{
		this.EmailID = EmailID;	
	}

	//��ȡ���Ա����EmailID��ֵ  
	public long getEmailID()
	{
		return this.EmailID;	
	}

	//�������Ա����Subject��ֵ  
 	public void setSubject(String Subject)
	{
		this.Subject = Subject;	
	}
   
	//��ȡ���Ա����Subject��ֵ  
	public String getSubject()
	{
		return this.Subject;	
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
 
 	//�������Ա����Sender��ֵ 
 	public void setSender(String Sender)
	{
		this.Sender = Sender;	
	}   

	//��ȡ���Ա����Sender��ֵ  
	public String getSender()
	{
		return this.Sender;	
	}  

	//�������Ա����Receiver��ֵ  
 	public void setReceiver(String Receiver)
	{
		this.Receiver = Receiver;	
	}
   
	//��ȡ���Ա����Receiver��ֵ  
	public String getReceiver()
	{
		return this.Receiver;	
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
 
 	//�������Ա����Tag��ֵ 
 	public void setTag(int Tag)
	{
		this.Tag = Tag;	
	}   

	//��ȡ���Ա����Tag��ֵ  
	public int getTag()
	{
		return this.Tag;	
	} 

}
