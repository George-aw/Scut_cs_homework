import java.net.*;
import java.io.*;
public class SimpleServer {
	public static void main(String[] args) 
	{
		try
		{
			ServerSocket server=new ServerSocket(8080);
			System.out.println("��������������");
			Socket socket=server.accept();
			InetAddress clientAddress=socket.getInetAddress();
			System.out.println("Client connected"+"from\n"+clientAddress+"\n");
			BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String s=in.readLine();//��ȡ�ͻ�����Ϣ
			System.out.println(s);//�����ȡ����hello server
			Thread.sleep(3000);
			PrintWriter out=new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
			out.println("Nice work");//������������ǻᴫ���ͻ���
			out.close();//�ر�out,�������������
			in.close();//�ر�in
			server.close();//�ر�socketserver,���ټ���
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
}