
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	//0 빈칸 1집 2치킨집
	
	static int ans = Integer.MAX_VALUE;
	static int N, M;
	static int[][] map;
	static List<int[]> chicken;
	static void dfs(int idx, int cnt, List<int[]> arr) {
		if(arr.size() == M){
			int sum = 0;
			for(int[] v : arr) {
				//System.out.println(Arrays.toString(v));
			}
			for(int i =0 ;i<N;i++) {
				for(int j =0;j<N;j++) {
					if(map[i][j] == 1) {
						int part = 99999999;
						for(int k = 0;k<arr.size();k++) {
							part = Math.min(part, Math.abs(i-arr.get(k)[0]) + Math.abs(j-arr.get(k)[1]));
						}
						//System.out.println(part);
						sum+= part;
					}
				}
			}
			
			ans = Math.min(ans, sum);
			return ;
		}
		
		for(int i = idx+1;i<chicken.size();i++) {
			arr.add(chicken.get(i));
			dfs(i,cnt+1,arr);
			arr.remove(arr.size()-1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		 map = new int[N][N];
		List<int[]> house = new ArrayList<>();
		chicken = new ArrayList<>();
		for(int i =0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j =0;j<N;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1) {
					int[] pair = new int[2];
					pair[0] = i;
					pair[1] = j;
					house.add(pair);
				}else if(map[i][j] == 2) {
					int[] pair = new int[2];
					pair[0] = i;
					pair[1] = j;
					chicken.add(pair);
				}
			}
		}
		
		for(int i = 0;i+M <= chicken.size();i++) {
			List<int[]> tmp = new ArrayList<>();
			tmp.add(chicken.get(i));
			dfs(i, 1,tmp);
		}
		
		sb.append(ans);
		System.out.println(sb);
	}

}
