import java.util.*;
import java.io.*;
 
class Solution {
    static List<List<Integer>> m = new ArrayList<>();
 
    static void leftRotate(int idx) {
        int top = m.get(idx-1).get(0);
        m.get(idx-1).remove(0);
        m.get(idx-1).add(top);
    }
 
    static void rightRotate(int idx) {
        int top = m.get(idx-1).get(7);
        m.get(idx-1).remove(7);
        m.get(idx-1).add(0, top);
    }
 
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
 
        // init
        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++) {
            int ans = 0;
            m.clear(); // 매 테스트 케이스마다 초기화
 
            int K = Integer.parseInt(br.readLine());
            for(int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());
                List<Integer> tmp = new ArrayList<>();
                for(int j = 0; j < 8; j++) {
                    tmp.add(Integer.parseInt(st.nextToken()));
                }
                m.add(tmp);
            }
 
            // rotate
            for(int i = 0; i < K; i++) {
                int[] dir_arr = new int[5];
                st = new StringTokenizer(br.readLine());
                int gear = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());
 
                dir_arr[gear] = dir;
 
                Queue<Integer> q = new LinkedList<>();
                boolean[] visited = new boolean[5];
                q.offer(gear);
                int[] dx = {-1, 1};
                visited[gear] = true;
                while(!q.isEmpty()) {
                    int g = q.poll();
                    for(int d = 0; d < 2; d++) {
                        int ng = g + dx[d];
                        if(ng < 1 || ng > 4) continue;
                        if(visited[ng]) continue;
                        if(d == 0) {
                            if(m.get(ng-1).get(2) != m.get(g-1).get(6)) {
                                dir_arr[ng] = -dir_arr[g];
                            }
                        } else {
                            if(m.get(ng-1).get(6) != m.get(g-1).get(2)) {
                                dir_arr[ng] = -dir_arr[g];
                            }
                        }
                        visited[ng] = true;
                        q.offer(ng);
                    }
                }
 
                for(int c = 1; c < 5; c++) {
                    if(dir_arr[c] == 1) {
                        rightRotate(c);
                    } else if(dir_arr[c] == -1) {
                        leftRotate(c);
                    }
                }
            }
 
            // 결과 계산
            for(int i = 1; i < 5; i++) {
                if(m.get(i-1).get(0) == 1) {
                    ans += Math.pow(2, i-1);
                }
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.print(sb.toString());
    }
}