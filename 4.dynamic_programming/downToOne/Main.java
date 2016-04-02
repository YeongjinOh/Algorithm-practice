import java.util.Scanner;
import java.math.BigInteger;

class operation {

	BigInteger[] num;
	int length;

	public operation(int N) {
		this.num = new BigInteger[N+1];
		this.length = N;
	}

	public boolean first_check(int i) {
		return (i%3==0) && (i>=3);
	}

	public BigInteger first_op(int i) {
		//System.out.println(i);
		return	num[(int)(i/3)];
	}

	public boolean second_check(int i) {
		return (i%2==0) && (i>=2);
	}

	public BigInteger second_op(int i) {
		return num[(int)(i/2)];
	}

	public BigInteger third_op(int i) {
		return num[i-1];
	}

	public BigInteger ithNum(int i) {
		BigInteger res = third_op(i);
		if (first_check(i))
			res = res.min(first_op(i));
		if (second_check(i))
			res = res.min(second_op(i));

		return res.add(new BigInteger("1"));
	}

	public void execute() {
		num[1] = new BigInteger("0");
		for(int i=2; i<=length; i++)
			num[i] = ithNum(i);

		System.out.println(num[length]);

	}

}

public class Main {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		
		operation op = new operation(N);
		op.execute();
	}
}
