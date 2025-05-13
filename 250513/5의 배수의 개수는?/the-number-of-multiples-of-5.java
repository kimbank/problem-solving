import java.util.*;

class Main {
    static final int MAX_N = 4;
    static int[][] arr = new int[MAX_N][MAX_N];
    static int ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                arr[i][j] = (sc.nextInt());
            }
        }

        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                if (arr[i][j] % 5 == 0) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}