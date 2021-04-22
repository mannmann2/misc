import java.net.*;
import java.io.*;
import java.util.*;
public class tcpserver
{
public static void main(String args[])throws Exception
{
try
{

int i=2;
while(i==2)
{
System.out.println();
System.out.println();
System.out.println("     WELCOME TO STRING REVERSAL TCP - SERVER SIDE -BY ARSH ,MANUJ ,CHINMAY ");
System.out.println();
System.out.println();

ServerSocket ss=new ServerSocket(5656); 
Socket s=ss.accept();
Scanner sc=new Scanner(s.getInputStream());
PrintStream p=new PrintStream(s.getOutputStream());
String name=sc.nextLine();

System.out.println(name+" WANTS TO USE THE SERVICE  ");
String st=sc.nextLine();

System.out.println("STRING RECIEVED IS  ---"+st);

String rev=reverse(st);//reverse the string//
 

p.println(rev);
System.out.println("REVERSED STRING SENT TO ---"+name);

ss.close();

System.out.println("                     ________________________________________________");
 
}

}

catch(Exception e)
{
System.out.println(e);
}

}

public static String reverse(String s)
{	
	String rev=new StringBuffer(s).reverse().toString(); 
	return rev;
}
}
