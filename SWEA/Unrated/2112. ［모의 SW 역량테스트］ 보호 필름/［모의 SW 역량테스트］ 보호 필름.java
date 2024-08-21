import java.io.*;
import java.util.*;

class Solution {
    
    static int T, N, M, K;
    static int[][] map;
    static int ans;
    
    // 열이 조건을 만족하는지 확인하는 함수
    static boolean checkColumn(int col) {
        int last = map[0][col];
        int cnt = 1;
        
        for (int i = 1; i < N; i++) {
            if (map[i][col] == last) {
                cnt++;
            } else {
                last = map[i][col];
                cnt = 1;
            }
            
            if (cnt >= K) {
                return true;
            }
        }
        return false;
    }
    
    // 모든 열이 조건을 만족하는지 확인하는 함수
    static boolean checkAllColumns() {
        for (int i = 0; i < M; i++) {
            if (!checkColumn(i)) {
                return false;
            }
        }
        return true;
    }
    
    // DFS를 이용해 가능한 모든 경우를 탐색하는 함수
    static void dfs(int row, int cnt) {
        if (checkAllColumns()) {
            ans = Math.min(cnt, ans);
            return;
        }
        
        if (row >= N || cnt >= ans) {
            return;
        }
        
        int[] original = map[row].clone();
        
        // 현재 행을 모두 0으로 변경
        Arrays.fill(map[row], 0);
        dfs(row + 1, cnt + 1);
        
        // 현재 행을 모두 1로 변경
        Arrays.fill(map[row], 1);
        dfs(row + 1, cnt + 1);
        
        // 원래 상태로 복원
        map[row] = original;
        
        // 현재 행을 변경하지 않고 다음 행으로
        dfs(row + 1, cnt);
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            map = new int[N][M];
            
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            ans = Integer.MAX_VALUE;
            
            if (checkAllColumns()) {
                ans = 0;
            } else {
                dfs(0, 0);
            }
            
            sb.append(String.format("#%d %d\n", tc, ans));
        }
        System.out.println(sb);
    }
}
