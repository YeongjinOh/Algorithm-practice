import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int sum=1;

		while(N-->0){
			sum += in.nextInt()-1 ;
		}
		
		System.out.println(sum);
	}
}
