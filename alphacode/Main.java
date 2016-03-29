import java.util.Scanner;

class alphacode {

	public String str;

	public alphacode(String str)
	{
		this.str = str;
	}

	public int length() {
		return str.length();
	}

	public int get(int idx) {
		return str.charAt(idx)-'0';
	}
};


public class Main{
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		alphacode a = new alphacode(in.next());

		int l = a.length();
	
		System.out.println(a.get(0) + "length :" + l);

	}
}
