import java.io.*;
import java.util.*;


public class A_Linear_Keyboard {

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
            String keywords = f.next();
            String keys = f.next();
            int result = 0;

            HashMap<Character, Integer> keywordsMap = new HashMap<Character, Integer>();

            for (int i = 0; i < keywords.length(); i++) {
                keywordsMap.put(keywords.charAt(i), i+1);
            }

            for (int i=0; i < keys.length()-1; i++) {
                result += Math.abs(
                    keywordsMap.get(keys.charAt(i)) - keywordsMap.get(keys.charAt(i+1))
                );
            }

            System.out.println(result);
        }
    }
}