import java.net.*;
import java.io.*;
public class SimpleCient {
	public static void main(String[] args) 
	{
		try
		{
			Socket socket=new Socket("127.0.0.1",8080);
			PrintWriter out=new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			out.println("hello java");//��������������Դ��������������
			out.flush();//�ƺ������������������ܼ�⵽out
			BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String s=in.readLine();//��ȡ�������˴�����������
			System.out.println(s);//����������������you too
			out.close();
			in.close();
			socket.close();
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
