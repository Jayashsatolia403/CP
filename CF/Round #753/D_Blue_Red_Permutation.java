import java.io.*;
import java.util.*;



public class D_Blue_Red_Permutation {

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
            int n = f.nextInt();
            int[] arr = f.readArray(n);
            String colors = f.next();

            ArrayList<Integer> blues = new ArrayList<>();
            ArrayList<Integer> reds = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                if (colors.charAt(i) == 'B') {
                    blues.add(arr[i]);
                } else {
                    reds.add(arr[i]);
                }
            }

            Collections.sort(blues);
            Collections.sort(reds);
            Collections.reverse(reds); 

            Boolean ok = true;


            for (int i = 0; i < blues.size(); i++) {
                if (blues.get(i) < i+1) ok = false; 
            }

            for (int i = 0; i < reds.size(); i++) {
                if (reds.get(i) > n-i) ok = false;
            }

            if (ok) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}