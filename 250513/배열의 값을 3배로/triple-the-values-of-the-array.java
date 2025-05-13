import java.util.*;

public class Main {
    static final int MAX_N = 3;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<List<Integer>> arr = new ArrayList<>();

        for (int i = 0; i < MAX_N; i++) {
            List<Integer> ar = new ArrayList<>();
            for (int j = 0; j < MAX_N; j++) {
                ar.add(sc.nextInt() * 3);
            }
            arr.add(ar);
        }

        for (List<Integer> ar : arr) {
            for (int i : ar) {
                System.out.print(i);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}