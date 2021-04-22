import java.io.*;
import java.net.*;
import java.util.*;

public class tcpclient
{
public static void main(String args[])throws Exception

{

try
{
Socket s=new Socket("192.168.173.1",5656);
Scanner sc=new Scanner(System.in);
Scanner sc1=new Scanner(s.getInputStream());
PrintStream p=new PrintStream(s.getOutputStream());


System.out.println("PLEASE ENTER YOUR NAME");
String name=sc.nextLine();
p.println(name);

System.out.println("PLEASE ENTER THE STRING YOU WANT TO REVERSE");
String st=sc.nextLine();

p.println(st);
String str=sc1.nextLine();


System.out.println("REVERSED STRING RECIEVED FROM SERVER IS--  "+str);
s.close();

}
catch(Exception e)
{
System.out.println(e);
}

}

}
