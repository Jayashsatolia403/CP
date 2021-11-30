import java.io.*;
import java.util.*;


public class C_Minimum_Extraction {

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
            int result = Integer.MIN_VALUE;
            int count = 0;
            int track = 0;

            Map<Integer, Boolean> map = new HashMap<>();
            List<Integer> list = new ArrayList<>();

            for (int i : arr) {
                if (map.containsKey(i)) map.put(i, true);
                else map.put(i, false);
            }

            for (int i : map.keySet()) {
                list.add(i);
            }


            Collections.sort(list);

            while (count < list.size()) {
                int min = list.get(count)-track;

                if (min < 0 && map.get(list.get(count)+track) == true) {
                    result = Math.max(result, 0);
                } else {
                    result = Math.max(result, min);
                }

                track += min;

                count++;
            }

            System.out.println(result);
        }
    }
}