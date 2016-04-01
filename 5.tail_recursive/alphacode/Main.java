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

	public boolean checkLast (int idx) {
		return idx == (str.length()-1);
	}

	public boolean checkTwoDigits (int idx) {
		if (checkLast(idx)) {
			return false;
		} else if (get(idx) == 1) {
				return true;
		} else if (get(idx) == 2) {
				return (get(idx+1) <= 6);
		} else
			return false;
	}

	public boolean checkOneDigit (int idx) {
		return (get(idx) != 0);
	}

	// a is the number of cases that this idx is involved
	// and b is the number of cases that this idx is NOT involved
	public double numberofCases (int idx, double a, double b) {
		double mod = 1000000;
		if (checkLast(idx)) {
			if(checkOneDigit(idx))
				return (a+b)%mod;
			else
				return a%mod;
		}	else {
			if (!checkOneDigit(idx))
				return numberofCases (idx+1, 0, a)%mod;
			else if (checkTwoDigits(idx)) {
				return numberofCases (idx+1, b, a+b)%mod;
			}
			else {
				return numberofCases (idx+1, 0, a+b)%mod;


			}
		}
	}
};


public class Main{
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		alphacode a = new alphacode(in.next());
		
		System.out.print((int)(a.numberofCases(0, 0, 1)));
	

	}
}
