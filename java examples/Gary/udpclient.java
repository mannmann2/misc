import java.net.*;
import java.io.*;
import java.util.*;
public class udpclient
{
public static void main(String args[])throws Exception
{
try
{
	Scanner sc=new Scanner(System.in);
DatagramSocket clientSocket = new DatagramSocket();
       InetAddress IPAddress = InetAddress.getByName("192.168.173.1");
       byte[] sendData = new byte[1024];
       byte[] receiveData = new byte[1024]; 
//input name	   
System.out.println("PLEASE ENTER YOUR NAME");
String name=sc.nextLine();
//send name	   
sendData =name.getBytes();
DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 5656);
clientSocket.send(sendPacket); 

//input string
System.out.println("PLEASE ENTER THE STRING YOU WANT TO REVERSE");
String st=sc.nextLine();

//send string
sendData =st.getBytes();
DatagramPacket sendPacket1 = new DatagramPacket(sendData, sendData.length, IPAddress,5656);
clientSocket.send(sendPacket1);

//recieve reverse string
DatagramPacket receivePacket= new DatagramPacket(receiveData, receiveData.length);
clientSocket.receive(receivePacket);
String str = new String(receivePacket.getData());

System.out.println("REVERSED STRING RECIEVED FROM SERVER IS--  "+str);
clientSocket.close();
	
}
catch(Exception e)
{
System.out.println(e);		
}

}

}
