import java.util.*;
import java.io.*;

public class Solution {

	static int T, N, maxCores = 0;
	static int minCost = Integer.MAX_VALUE;
	static int[][] map;
	static List<int[]> cores;
	
	static int[] dy = {-1,1,0,0};
	static int[] dx = {0,0,-1,1};
	
	static boolean oob(int y, int x) {
		return y < 0 || x < 0 || y >= N || x >= N;
	}
	
	static boolean canMove(int y, int x, int dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		while(!oob(ny,nx)) {
			if(map[ny][nx] == 1) {
				return false;
			}
			ny += dy[dir];
			nx += dx[dir];
		}
		return true;
	}
	
	static int setMap(int y, int x , int dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		int sum = 0;
		
		while(!oob(ny,nx)) {
			map[ny][nx] = 1;
			sum++;
			ny += dy[dir];
			nx += dx[dir];
		}
		return sum;
	}
	static void resetMap(int y, int x, int dir) {
	    int ny = y + dy[dir];
	    int nx = x + dx[dir];
	    
	    while (!oob(ny, nx)) {
	        map[ny][nx] = 0;
	        ny += dy[dir];
	        nx += dx[dir];
	    }
	}

	static void dfs(int idx, int cnt, int cost) {
		if(idx == cores.size()) {
			if(cnt > maxCores || (cnt == maxCores && cost < minCost)) {
				minCost = cost;
				maxCores = cnt;
			}
			return;
		}
		
		int y = cores.get(idx)[0];
		int x = cores.get(idx)[1];
	
		int[][] copy = new int[N][];
		for(int i = 0;i<N;i++) {
			copy[i] = map[i].clone();
		}
		
		for(int d = 0;d<4;d++) {
			if(canMove(y,x,d)) {
				int currentCost = setMap(y,x,d);
				dfs(idx +1 , cnt + 1, cost + currentCost);
				resetMap(y,x,d);
			}
		}
		
		dfs(idx + 1, cnt, cost);
	}
	
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		T = Integer.parseInt(br.readLine());
		
		for(int tc = 1;tc<=T;tc++) {
			N = Integer.parseInt(br.readLine());
			minCost = Integer.MAX_VALUE;
			maxCores = 0;
			map = new int[N][N];
			cores = new ArrayList<>();
			
			for(int i = 0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j =0;j<N;j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					//가장자리 빼고 코어 담기
					if(map[i][j] == 1 && i!= 0&& j!=0 && i!=N-1 && j!=N-1)
						cores.add(new int[] {i,j});	
				}
			}
			
			dfs(0,0,0);
			
			sb.append(String.format("#%d %d\n", tc, minCost));
		}
		System.out.println(sb);
	}

}
