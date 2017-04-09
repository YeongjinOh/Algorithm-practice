import java.util.Scanner;

public class Main {
    public static void main (String[] args) {

        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int l = in.nextInt(), r = in.nextInt();

        int[] before = new int[N], after = new int[N];
        for (int i=0; i<N; i++)
            before[i] = in.nextInt();
        for (int i=0; i<N; i++)
            after[i] = in.nextInt();
        boolean res = true;
        for (int i=0; i<l-1; i++)
            if (before[i] != after[i]) res = false;
        for (int i=r; i<N; i++)
            if (before[i] != after[i]) res = false;
        int[] cnt = new int[N];
        for (int i=l-1; i<r; i++) {
            cnt[before[i]-1]++;
            cnt[after[i]-1]--;
        }
        for (int i=0; i<N; i++)
            if (cnt[i] != 0) res = false;

        if (res)
            System.out.println("TRUTH");
        else
            System.out.println("LIE");
    }
}
