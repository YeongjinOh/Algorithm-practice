import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;

class choco {
	private	int T;
	private	double N;

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
			return (8.0*N - (double)deltaT/12.0);
	}
};


class coffee {
	private int T;
	private double N;

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
			return (2.0*N - ((double)deltaT*deltaT/79.0));
	}
};


class query {
	
	private List<choco>  choco_list;
	private List<coffee>  coffee_list;

	private static double MIN = 1;

	// constructor
	public	query() {
		this.choco_list = new ArrayList<choco>();
		this.coffee_list = new ArrayList<coffee>();
	}

	public double getR(int queryT) {
		double R = 0;
		for (choco cho : choco_list)
		{
			R = R + cho.getR(queryT);
		}
		for (coffee cof : coffee_list)
		{
			R = R + cof.getR(queryT);
		}
		return max(MIN,R);
	}


	public void putChoco(int T, double N)
	{
		choco new_choco = new choco(T, N);
		choco_list.add(new_choco);
	}

	public void putCoffee(int T, double N)
	{
		coffee new_coffee = new coffee(T, N);
		coffee_list.add(new_coffee);
	}

	private double max(double a, double b)
	{
		if (a>b)
			return a;
		else
			return b;
	}
};



public class chocolate {
	public static void main(String[] args) {
		
		int queryT, T;
		double R, N;
		query q = new query();

		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			switch (in.next()) {
				case "Query" :
					queryT = in.nextInt();
					R = q.getR(queryT);
					System.out.println(queryT+" "+(double)Math.round(R*10)/10);
					break;

				case "Chocolate" :
					T = in.nextInt();
					N = in.nextDouble();
					q.putChoco(T, N);
					break;

				case "Coffee" :
					T = in.nextInt();
					N = in.nextDouble();
					q.putCoffee(T, N);					
					break;
				default :
					System.out.println("Wrong Input!");
					break;
				}
		}
	
	
	}
}
