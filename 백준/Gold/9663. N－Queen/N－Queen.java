import java.util.*;

class Main {
    static int T;
    static int N, ans = 0;

    static int[][] map;
    static boolean[][] v;
    static int[] dy= {-1,-1,-1}, dx = {-1,0,1};
    
    static boolean oob(int y, int x) {
    	return y < 0 || x < 0 || y>= N || x>=N;
    }
    
        static void dfs(int y, int x, int cnt) {
        if (cnt == 0) { // 모든 퀸을 배치한 경우
            ans++;
            return;
        }

        if (y >= N) { // 더 이상 행이 없는 경우 종료
            return;
        }

        for (int i = x; i < N; i++) { // 현재 열부터 시작
            boolean isOk = true;

            for (int d = 0; d < 3; d++) { // 대각선 및 수직 방향 확인
                int ny = y + dy[d];
                int nx = i + dx[d];
                while (!oob(ny, nx)) {
                    if (v[ny][nx]) {
                        isOk = false;
                        break;
                    }
                    ny += dy[d];
                    nx += dx[d];
                }
                if (!isOk) break;
            }

            if (isOk) {
                v[y][i] = true; // 퀸을 배치
                dfs(y + 1, 0, cnt - 1); // 다음 행으로 이동
                v[y][i] = false; // 배치 취소 (백트래킹)
            }
        }
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();




            N = sc.nextInt();
            
            map = new int[N][N];
            v = new boolean[N][N];
            
            dfs(0,0,N);
            sb.append(String.format("%d", ans));
            ans = 0;
   
        
        System.out.println(sb.toString());
        sc.close();  // 스캐너를 닫아 자원 해제
    }
}
