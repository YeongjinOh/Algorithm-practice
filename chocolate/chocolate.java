import java.util.Scanner;
import java.util.List;

class choco {
	public	int T;
	public	double N;

	public	choco(int T, double N) {
		this.T = T;
		this.N = N;
	}

	public	double getR(int queryT)
	{
		int deltaT = queryT - T;
		if (deltaT < 0)
			return 0;
		else
			return 8*N - deltaT/12;
	}
};


class coffee {
	public int T;
	public double N;

	public coffee(int T, double N) {
		this.T = T;
		this.N = N;
	}

	public double getR(int queryT)
	{
		int deltaT = queryT - T;
		if (deltaT < 0)
			return 0;
		else
			return 8*N - deltaT/12;
	}
};


public class chocolate {
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			switch (in.next()) {
				case "Query" :
					System.out.println("Query = " + in.nextInt());
					break;

				case "Chocolate" :
					System.out.println("Chocolate = " + in.nextInt() + ", " + in.nextDouble());
					break;

				case "Coffee" :
					System.out.println("Coffee = " + in.nextInt() + ", " + in.nextDouble());
					break;
				default :
					System.out.println("Wrong Input!");
					break;
				}
		}
	
	
	}
}
