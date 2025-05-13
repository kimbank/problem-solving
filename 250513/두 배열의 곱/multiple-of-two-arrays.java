import java.util.*;

class Main {
    static final int MAX_N = 3;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        List<List<Integer>> arr = new ArrayList<>();

        for (int i = 0; i < MAX_N; i++) {
            List<Integer> ar = new ArrayList<>();
            for (int j = 0; j < MAX_N; j++) {
                ar.add(sc.nextInt());
            }
            arr.add(ar);
        }

        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                int cur = arr.get(i).get(j);
                arr.get(i).set(j, cur * sc.nextInt());
            }
        }

        for (List<Integer> o : arr) {
            for (int i : o) {
                System.out.printf("%d ", i);
            }
            System.out.println();
        }
    }
}