import java.util.*;
import java.io.*;

public class Main {
	
	static int N, M, ans = Integer.MAX_VALUE;
	static int[][] map;
	static List<int[]> houses;
	static List<int[]> chickens;
	static boolean[] selected;
	
	static void dfs(int idx, int cnt) {
		if(cnt == M) {
			int sum = 0;
			for(int h = 0;h<houses.size();h++) {
				int part = Integer.MAX_VALUE;
				for(int i = 0;i<chickens.size();i++) {
					if(selected[i]) {
						//System.out.print(i + " ");
						part= Math.min(Math.abs(chickens.get(i)[0] - houses.get(h)[0]) + Math.abs(chickens.get(i)[1] - houses.get(h)[1]),part); 
					}
				}				
				sum += part;
				//System.out.println();
			}
			ans = Math.min(ans, sum);
			return ;
		}
		
		for(int i = idx;i<chickens.size();i++) {
			
			if(selected[i]) continue;
			selected[i] = true;
			dfs(i, cnt+1);
			selected[i] = false;
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
		
		map = new int[N][N];
		houses = new ArrayList<>();
		chickens = new ArrayList<>();
		
		
		for(int i =0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0;j<N;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) houses.add(new int[] {i,j});
				else if(map[i][j] == 2) chickens.add(new int[] {i,j});
			}
		}
		
		selected = new boolean[chickens.size()];
		dfs(0,0);
		
		System.out.println(String.format("%d", ans));
	}

}
