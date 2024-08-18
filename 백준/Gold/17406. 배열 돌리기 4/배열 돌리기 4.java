import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M, K, ans= Integer.MAX_VALUE;
	static int[][] map;
	static List<int[]> rotateArr;
	static int[] dy = {0,1,0,-1};
	static int[] dx = {1,0,-1,0};
	static boolean[] v;
	
	static void rotate(int r, int c, int s) {
		r -= 1;
		c -=1;
		for(int cnt = 1;cnt<=s;cnt++) {
			int i = r-cnt;
			int j = c-cnt;
			int last = map[i][j];
			int dir = 0;
			int count = 0;
			while(dir<4) {
				//System.out.println(i + " " + j);
				i += dy[dir];
				j += dx[dir];
				int tmp = map[i][j];
				map[i][j] = last;
				last = tmp;
				if(++count >= 2*cnt) {dir = (dir + 1) ;count = 0;}
			}
		}
		
//		for(int i =0;i<N;i++) {
//			for(int j =0;j<M;j++) {
//				System.out.print(map[i][j] + " ");
//			}
//			System.out.println();
//		}
	}
	
	static void reset(int[][] copy) {
		for(int i =0;i<N;i++) {
			for(int j =0;j<M;j++) {
				map[i][j] = copy[i][j];
			}
		}
	}
	
	static void dfs(int idx, int cnt) {
		if(cnt == K) {
			int val = Integer.MAX_VALUE;
			
			for(int i = 0;i<N;i++) {
				int part = 0;
				for(int j =0;j<M;j++) {
					part+=map[i][j];
				}
				val = Math.min(val, part);
			}
			ans = Math.min(val, ans);
			
			return;
		}
		
		int[][] copy = new int[N][M];
		
		for(int i = 0;i<N;i++) {
			for(int j =0;j<M;j++) {
				copy[i][j] = map[i][j];
			}
		}
		
		for(int i =0 ;i<rotateArr.size();i++) {
			if(v[i])continue;
			v[i] = true;
			rotate(rotateArr.get(i)[0], rotateArr.get(i)[1], rotateArr.get(i)[2]);
			dfs(i, cnt+1);
			reset(copy);
			v[i] = false;
		}
	}
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		rotateArr = new ArrayList<>();
		
		map = new int[N][M];
		
		for(int i =0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0;j<M;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0;i<K;i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			
			rotateArr.add(new int[] {r,c,s});
		}
		
		v = new boolean[rotateArr.size()];
//		
//		for(int i = 0;i<N;i++) {
//			for(int j =0;j<M;j++) {
//				System.out.print(map[i][j] + " ");
//			}
//			System.out.println();
//		}
		dfs(0,0);
		
		System.out.println(String.format("%d", ans));
	}

}
