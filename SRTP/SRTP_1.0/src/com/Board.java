package com;

import java.sql.*;

public class Board extends ExecuteDB
{
	//�������Ա����
	private long BoardID;
	private String BoardName;
	private String strSql;
    
    //���캯�����Գ�Ա�������г�ʼ����ֵ
	public Board()
	{       
		this.BoardID=0;
		this.BoardName="";
		this.strSql="";
	}   
  
	//���������������boards���ݱ������һ���¼�¼
	public boolean add()
	{
	    
		this.strSql="insert into boards ";
		this.strSql=this.strSql + "(BoardName) ";        
		this.strSql=this.strSql + "values('" + this.BoardName + "')";
		boolean isAdd = super.exeSql(this.strSql);
		
		return isAdd;
	}
   
	//�޸�BoardID��Ӧ������������Ϣ
	public boolean modify()
	{
		this.strSql="update boards set";
		this.strSql=this.strSql + " BoardName=" + "'" + this.BoardName + "'";	
		this.strSql=this.strSql + " where BoardID='" + this.BoardID + "'";
		boolean isUpdate = super.exeSql(this.strSql);
		
		return isUpdate;
	}
	
	//ɾ������ĳ�������е���������Ϣ
	public boolean delete(String sBoardID)
	{
		this.strSql="delete from boards";
		this.strSql=this.strSql + "  where BoardID in ("+sBoardID+")";
		
		boolean isDelete = super.exeSql(this.strSql);      
		return isDelete;	
	}

	
   
 	//���BoardID��Ӧ������������Ϣ������Щ��Ϣ��ֵ����Ӧ�������
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

 	//�ж����������Ƿ����
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
 
	//���������������Ϣ������һ��ResultSet����
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

	//�������Ա����BoardName��ֵ
 	public void setBoardName(String BoardName)
	{
		this.BoardName = BoardName;	
	}
   
	//��ȡ���Ա����BoardName��ֵ  
	public String getBoardName()
	{
		return this.BoardName;	
	}
}

