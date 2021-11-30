import java.io.*;
import java.util.*;


public class B_Odd_Grasshopper {

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
                while (!st.hasMoreTokens())
                        try {
                                st=new StringTokenizer(br.readLine());
                        } catch (IOException e) {
                                e.printStackTrace();
                        }
                return st.nextToken();
        }

        int nextInt() {
                return Integer.parseInt(next());
        }
        int[] readArray(int n) {
                int[] a=new int[n];
                for (int i=0; i<n; i++) a[i]=nextInt();
                return a;
        }
        long nextLong() {
                return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastScanner f = new FastScanner();

        int T = f.nextInt();

        while (T-- > 0) {
            long x = f.nextLong();
            long n = f.nextLong();

            long n2 = n / 4 * 4;


            while (n2 < n) {
                if (x%2 == 0) {
                    x -= n2+1;
                } else {
                    x += n2+1;
                }

                n2++;
            }

            System.out.println(x);
        }
    }
}