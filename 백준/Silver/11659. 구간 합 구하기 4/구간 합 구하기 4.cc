#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <bitset>
#include <map>
#include <sstream>
#include <queue>
#include<string.h>
using namespace std;

typedef long long ll;


//int visited[1001];
//int visited1[1001];
//vector<int> graph[1001];
//int count1 = -1;
//
//
////vector<vector<int>> bat(251, vector<int>(251,0));
//int bat[50][50] = { 0};
//int jVisitied[50][50] = { 0 };
//int dx[4] = { 1,-1,0,0 };
//int dy[4] = { 0,0,1,-1 };
//
//
//
//
//int n, m;
//
//void dfs1012(int y, int x) {
//	for (int i = 0;i < 4;i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
//			continue;
//		}
//		if (bat[ny][nx] && !jVisitied[ny][nx]) {
//			jVisitied[ny][nx] = 1;
//			dfs1012(ny, nx);
//		};
//	}
//}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//11659
	int n, m;
	cin >> n >> m;
	int arr[100001] = { 0 };
	for (int i = 1;i <= n;i++) {
		int num;
		cin >> num;
		arr[i] += arr[i-1] + num;
	}
	for (int i = 0;i < m;i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << arr[n2] - arr[n1 - 1] << "\n";
	}

	
	//10816
	//int n, m;
	//cin >> n;
	//map<int, int> map;
	//for (int i = 0;i < n;i++) {
	//	int num1;
	//	cin >> num1;
	//	if (map.find(num1) != map.end())
	//		++map[num1];
	//	else
	//		map.insert({ num1, 1 });
	//}

	//cin >> m;
	//for (int i = 0;i < m;i++) {
	//	int num2;
	//	cin >> num2;
	//	//if (map.find(num2) != map.end())
	//		cout << map[num2] << " ";
	////	else
	//	//	cout << 0 << " ";
	//}
	
	//2164
	/*int n;
	cin >> n;
	queue<int> q;
	for (int i = 1;i <= n;i++) {
		q.push(i);
	}
	while (1) {
		if(q.size() == 1) break;
		q.pop();
		if (q.size() != 1) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		else break;
	}
	cout << q.front();*/
	//1912
	/*int n;
	cin >> n;
	int dp[100001] = { 0 };
	vector<int> arr;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	dp[0] = arr[0];
	int result = dp[0];
	for (int i = 1;i < n;i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	cout << result;*/

	//1012
	//int t;
	////int n, m, v;//row col total
	//cin >> t;
	//int v;
	//for (int i = 0;i < t;i++) {
	//	cin >> m >> n >> v;

	//	memset(bat, 0, sizeof(bat));
	//	memset(jVisitied, 0, sizeof(jVisitied));
	//	int count = 0;
	//	for (int j = 0;j < v;j++) {
	//		int num1, num2;
	//		cin >> num1 >> num2;
	//		bat[num2][num1] = 1;
	//	}
	//	for (int a = 0;a < n;a++) {
	//			for (int b = 0;b < m;b++) {
	//				if (bat[a][b] && !jVisitied[a][b]) {
	//					count++;
	//					jVisitied[a][b] = 1;
	//					dfs1012(a, b);
	//			}
	//		}
	//	}
	//	
	//	cout << count << endl;
	//	
	//}

	
	

	/*int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
		sort(graph[num1].begin(), graph[num1].end());
		sort(graph[num2].begin(), graph[num2].end());
	}
	
	dfs(1);
	cout << count1;*/

	//1260
	/*int n, m, v;
	cin >> n >> m>>v;
	int size = n;
	
	
	for (int i = 0; i < m; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
		sort(graph[num1].begin(), graph[num1].end());
		sort(graph[num2].begin(), graph[num2].end());
	}
	dfs(v);
	cout << "\n";
	bfs(v);*/

	
	//1904
	//int n;
	//cin >> n;
	//ll dp[1000001];
	//dp[1] = 1;
	//dp[2] = 2;
	//for (ll i = 3;i < 1000001;i++) {
	//	dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	//	//cout << i << " : " << dp[i] << endl;
	//}
	//cout << dp[n];
	//11727
	//int n;
	//cin >> n;
	//ll dp[1001];
	//ll count = 1;
	//dp[1] = 1;
	//dp[2] = 3;
	//dp[3] = 5;
	//dp[4] = 11;
	//for (int i = 5;i < 1001;i++) {
	//	dp[i] = (dp[i - 1] + 2*dp[i - 2])%10007;
	//	//cout << dp[i] << endl;
	//}
	//cout << dp[n] ;
	
	//11726
	//int n;
	//cin >> n;
	//ll dp[1001];
	//ll count = 1;
	//dp[1] = 1;
	//dp[2] = 2;
	//for (int i = 3;i < 1001;i++) {
	//	dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	//	//cout << dp[i] << endl;
	//}
	//cout << dp[n] ;
	

	
	
	//5525
	//ll n;
	//cin >> n;
	//string cmp ="";
	//for (ll i = 0;i <= n;i++) {
	//	cmp += "I";
	//	if (i < n) {
	//		cmp+= "O";
	//	}
	//}
	////cout << cmp << endl;
	//ll size;
	//cin >> size;
	//string str ="";
	//for (ll i = 0;i < size;i++) {
	//	char s;
	//	cin >> s;
	//	str += s;
	//}
	//ll count = 0;
	//while(1){
	//	//cout << str.size() << " " << cmp.size() << endl;
	//	if (str.size() < cmp.size() ||str.find(cmp) == string::npos ) break;
	//	//cout << str << endl;
	//	if (str.find(cmp) != string::npos) {
	//		//cout << str.find(cmp) << endl;
	//		count++;
	//		str = str.substr(str.find(cmp)+2, str.size());
	//	}
	//}
	/*int ans = 0;
	for (int i = 0;i < str.size();i++) {
		int c = 0;
		if(str[i] == 'I')
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				c++;
				i += 2;
				if (c == n) {
					c--;
					ans++;
				}
			}
	}
	cout << ans;
	*/
	//string p=find(str.begin(), str.end(), cmp);

	//9461
	/*int t;
	cin >> t;
	long long int dp[101];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	for (int j = 5;j < 101;j++) {
		dp[j] = dp[j - 1] + dp[j - 5];
	}
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		cout << dp[num-1] << "\n";
	}*/

	//2579
	/*int t;
	cin >> t;
	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4;i <= 10;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i-3];
	}
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}*/
	
	//1463
	
	/*int count;
	int n;
	cin >> n;
	int* dp = new int[n] {0, };
	dp[1] = 0;
	for (int i = 2;i <= n;i++) {
		if (i % 3 ==0&& i % 2==0) dp[i] = min(min(dp[i / 3], dp[i - 1]), dp[i / 2]) + 1;
		else if (i % 3 == 0) dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0) dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else dp[i] = dp[i - 1] + 1;
	}
	cout << dp[n];*/
	//9184
	//int dp[51][51][51];
	//int a, b, c;
	/*while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
		
	}*/
	

	//24416
	/*int n;
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << fibCount << " " << fibonacciCount;*/

	//9375
	/*int t;
	cin >> t;
	map<string, int> clothes;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		for (int j = 0;j < num;j++) {
			string a, b;
			cin >> a >> b;
			if (clothes.find(b) != clothes.end()) {
				clothes.at(b)++;
			}
			else {
				clothes.insert({ b,1 });
			}
		}
		int ans = 1;
		for (auto i : clothes) {
			ans *= (i.second + 1);
		}
		cout << ans - 1 << endl;
		clothes.clear();
	}*/
	
	////1107
	//int goal;
	//cin >> goal;
	//int cur = 100;
	//int count = 0;
	//int lesCount;
	//vector<int> v{ 0,1,2,3,4,5,6,7,8,9 };
	//vector<int> no;
	//int n;
	//cin >> n;
	//for (int i = 0;i < n;i++) {
	//	int num;
	//	cin >> num;
	//	//v.erase(find(v.begin(), v.end(), num));
	//	no.push_back(num);
	//}
	//bool noCount = false;
	//lesCount = abs(goal-100);
	//for (int i = 0;i <= 1000000;i++) {
	//	
	//	string push;
	//	push = to_string(i);
	//	int dupPush = i;
	//	for (int j = 0;j < push.size();j++) {
	//		for (int k = 0;k < no.size();k++) {
	//			if (push[j]-48 == no[k]) {
	//				noCount = true;
	//				break;
	//			}
	//		}
	//	}
	//	if (!noCount) {
	//			count += abs(goal - i)+to_string(i).length();
	//		lesCount = min(lesCount, count);
	//	}
	//	
	//	
	//		
	//		count = 0;
	//		noCount = false;
	//		// << "here";
	//}
	//cout << lesCount;

	//string str;
	//cin >> str;
	//string num;
	//int ans = 0;
	//int sum = 0;
	//bool isM= false;
	//for (int i = 0;i < str.size();i++) {
	//	
	//	if (str[i] != '+' && str[i] != '-') {
	//		num += str[i];
	//	}
	//	else if (str[i] == '-' && !isM) {
	//		isM = true;
	//		ans += stoi(num);
	//		num = "";
	//	}
	//	else if (str[i] == '-' && isM) {
	//		ans -= stoi(num);
	//		num = "";
	//	}
	//	else if (isM && str[i] == '+') {
	//		ans -= stoi(num);
	//		num = "";
	//	}
	//	else if (!isM && str[i] == '+') {
	//		ans += stoi(num);
	//		num = "";
	//	}

	//	if (i == str.size() - 1 && isM) {
	//		ans -= stoi(num);
	//	}
	//	else if(i == str.size() - 1 && (!isM)) {
	//		ans += stoi(num);
	//	}
	//}

	//cout << ans;
	//1764
	/*int n, m;
	cin >> n >> m;
	vector<string> hear;
	vector<string> see;
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		hear.push_back(str);
	}
	for (int i = 0;i < m;i++) {
		string str;
		cin >> str;
		see.push_back(str);
	}
	sort(hear.begin(), hear.end());
	sort(see.begin(), see.end());
	vector<string>buff(hear.size() + see.size());
	auto iter = set_intersection(hear.begin(), hear.end(), see.begin(), see.end(), buff.begin());
	buff.erase(iter, buff.end());

	cout << buff.size() << "\n";
	for (int i = 0;i < buff.size();i++) {
		cout << buff[i] << "\n";
	}*/

	//1920
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> arr;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int num;
		cin >> num;
		int start = 0;
		int end = arr.size() - 1;
		int mid;
		int ans = 0;
		while (end - start >= 0) {
			mid = (start + end) / 2;
			if (arr[mid] == num) {
				ans = 1;
				break;
			}
			else if (arr[mid] > num) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		cout << ans << "\n";
	}*/

	//13305
	/*int t;
	cin >> t;
	vector<long long int> road;
	vector<long long int> val;
	long long int sum = 0;
	long long int min = 1000000000;
	for (int i = 0;i < t-1;i++) {
		int num;
		cin >> num;
		road.push_back(num);
	}
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		val.push_back(num);
	}
	for (int i = 0;i < t - 1;i++) {
		if (min > val[i]) min = val[i];
		sum += min * road[i];
	}
	cout << sum;*/
	//1026
	/*int t;
	cin >> t;
	vector<int> a;
	vector<int> b;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), bcmp);
	int sum = 0;
	for (int i = 0;i < t;i++) {
		sum += a[i] * b[i];
	}
	cout << sum;*/
	//11399
	/*int t;
	cin >> t;
	vector<pair<int, int>> person;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		person.push_back({ i + 1,num });
	}
	sort(person.begin(), person.end(), cmp);
	int sum = 0;
	int part = 0;
	for (int i = 0;i < person.size();i++) {
		for (int j = 0;j <= i;j++) {
			part += person[j].second;
		}
		sum += part;
		part = 0;
	}
	cout << sum;*/
	
	//1931
	/*int t;
	cin >> t;
	vector<pair<int, int>> room;
	vector<pair<int, int>> ans;
	for (int i = 0;i < t;i++) {
		int num1, num2;
		cin >> num1 >> num2;
		room.push_back({ num1,num2 });
	}
	sort(room.begin(), room.end(), cmp);
	ans.push_back(room[0]);
	for (int i = 1;i < room.size();i++) {
		if (ans[ans.size() - 1].second <= room[i].first) ans.push_back(room[i]);
	}
	cout << ans.size();*/
	
	//1259
	/*string str;
	while (1) {
		cin >> str;
		string ans= "yes";
		if (str == "0") return 0;
		if (str.size() % 2 != 0) {
			for (int i = 0;i < str.size()/2;i++) {
				if (str[i] != str[str.size() - 1 - i]) {
					ans = "no";
					break;
				}
			}
			cout << ans << endl;
		}
		else if (str.size() % 2 == 0) {
			for (int i = 0;i <= (str.size() / 2) - 1;i++) {
				if (str[i] != str[str.size() - 1 - i]) {
					ans = "no";
					break;
				}
			}
			cout << ans << endl;
		}
	}*/
	
	//2798
	/*int n, m;
	cin >> n >> m;
	int num;
	int *arr = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> num;
		arr[i] = num;
	}
	int sum;
	int high= 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			for (int k = j + 1;k < n;k++) {
				sum = (arr[i] + arr[j] + arr[k]);
				if (m >= sum&&(high-m) < (sum-m)) high = sum;
				sum = 0;
			}
		}
	}
	cout << high;*/

	//2675
	/*int T;
	string str;
	cin >> T;
	for (int i = 0;i < T;i++) {
		int n;
		cin >> n;
		cin >> str;
		for (int j = 0;j < str.size();j++) {
			for (int k = 0;k < n;k++) {
				cout << str[j];
			}
		}
		cout << "\n";
	}*/

	////1152
	//int count = 0;
	//string a;
	//getline(cin, a);
	//istringstream ss(a);
	//string buff;
	//while (getline(ss, buff, ' ')) {
	//	if(buff !="") count++;
	//}
	//cout << count;

	//17219
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> pwd;
	for (int i = 0;i < n;i++) {
		string a, b;
		cin >> a >> b;
		pwd.insert({ a,b });
	}
	for (int i = 0;i < m;i++) {
		string c;
		cin >> c;
		if (pwd.find(c) != pwd.end()) {
			cout << pwd.find(c)->second << "\n";
		}
	}*/

	
	//1620
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	//int n, t;
	//cin >> n >> t;
	//string pok;
	//string q;
	////string a = "11Aa";
	////int b = stoi(a);
	//map<string, string>m;
	//vector<string> pokArr;
	//for (int i = 0;i < n;i++) {
	//	cin >> pok;
	//	pokArr.push_back(pok);
	//	m.insert({pok,to_string(i + 1)});
	//}
	//cout << endl;
	/*for (int i = 0;i < t;i++) {
		cin >> q;
		if (atoi(q.c_str())) {
			cout << pokArr[atoi(q.c_str()) - 1] << '\n';
		}
		else {
			cout << m[q] << '\n';
		*/
	//}

	////10815
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	//int N, M;
	//cin >> N;
	//vector<int> v;
	//vector<int> numV;
	//vector<int> resV;
	//while (N--) {
	//	int num;
	//	cin >> num;
	//	v.push_back(num);
	//}
	//sort(v.begin(), v.end());
	//cin >> M;
	//resV.assign(M, 0);
	//while (M--) {
	//	int num;
	//	cin >> num;
	//	numV.push_back(num);
	//}
	///*for (int i = 0;i < numV.size();i++) {
	//	cout << binSearch(v, v.size(), numV[i]) << " ";
	//}*/
	//
	//for (int i = 0;i < numV.size();i++) {
	//	int right = v.size() - 1;
	//	int left = 0;
	//	while (left <= right) {
	//		int mid = (right + left) / 2;
	//		if (v[mid] == numV[i]) {
	//			resV[i]=1;
	//			break;
	//		}
	//		else if (v[mid] > numV[i]) {
	//			right = mid - 1;
	//		}
	//		else {
	//			left = mid + 1;
	//		}
	//	}
	//	//resV.push_back(0);
	//}
	//for (int i = 0;i < resV.size();i++) {
	//	cout << resV[i] << " ";
	//}

	//2839
	/*vector<int> na;
	for (int i = 0;i < 10;i++) {
		int num;
		cin >> num;
		na.push_back(num % 42);
	}
	sort(na.begin(), na.end());
	na.erase(unique(na.begin(), na.end()), na.end());
	cout << na.size();*/


	////11723
	//int M, num, BIT =0;
	//string input;

	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//cin >> M;
	//while (M--)
	//{
	//	input.clear();
	//	cin >> input;
	//	if (input == "add")
	//	{
	//		cin >> num;
	//		BIT |= (1 << num);
	//	}
	//	else if (input == "remove")
	//	{
	//		cin >> num;
	//		BIT &= ~(1 << num);
	//	}
	//	else if (input == "check")
	//	{
	//		cin >> num;
	//		if (BIT & (1 << num))    cout << 1 << '\n';
	//		else    cout << 0 << '\n';
	//	}
	//	else if (input == "toggle")
	//	{
	//		cin >> num;
	//		BIT ^= (1 << num);
	//	}
	//	else if (input == "all")
	//	{
	//		BIT = (1 << 21) - 1;
	//	}
	//	else if (input == "empty")
	//	{
	//		BIT = 0;
	//	}
	//	//cout << bitset<32>(BIT) << endl;
	//}
	//return 0;

	////1676
	//int n;
	//cin >> n;
	//int index;
	//index = n / 5 + n/ 25 + n/ 125;
	//cout << index;
	

	////2292
	//int n, sum=1 ;
	//int index = 0;
	//int flag = 0;
	//cin >> n;
	//if (n == 1) {
	//	cout << 1 << endl;
	//	return 0;
	//}
	//while (1) {
	//	sum += 6 * index;
	//	if (n <= sum) { 
	//		cout << index+1;
	//		return 0;
	//	}
	//	else {
	//		index++;
	//	}
	//	
	//}

	////10845
	//int t;
	//int qSize = 0;
	//int front = 0;
	//int back = -1;
	//int queue[10000];
	//for (int i = 0;i < 10000;i++) {
	//	queue[i] = -1;
	//}
	//cin >> t;
	//for (int i = 0; i < t;i++) {
	//	string cmd;
	//	cin >> cmd;
	//	if (cmd == "push") {
	//		int num;
	//		cin >> num;
	//		queue[back+1] = num;
	//		qSize++;
	//		back++;
	//	}
	//	else if (cmd == "pop") {
	//		if (qSize != 0) {
	//			cout << queue[front] << endl;
	//			queue[front] = -1;
	//			front++;
	//			qSize--;
	//			if (qSize == 0) {
	//				front = 0;
	//				back = -1;
	//			}
	//		}
	//		else {
	//			cout << -1 << endl;
	//		}
	//	}
	//	else if (cmd == "size") {
	//		cout << qSize << endl;
	//	}
	//	else if (cmd == "empty") {
	//		if (qSize != 0) {
	//			cout << 0 << endl;
	//		}
	//		else {
	//			cout << 1 << endl;
	//		}
	//	}
	//	else if (cmd == "front") {
	//		
	//		if (qSize == 0) {
	//			cout << -1 << endl;
	//		}
	//		else {
	//			cout << queue[front] << endl;
	//		}
	//	}
	//	else if (cmd == "back") {
	//		
	//		if (qSize == 0) {
	//			cout << -1 << endl;
	//		}
	//		else {
	//			cout << queue[back] << endl;
	//		}
	//	}
	//	
	//	
	//}
	
	//2231
	//int n;
	//cin >> n;
	//int count = 0;
	//int sum=0;
	//string abc ;
	//for(int i = 1;i<=n;i++){
	//	abc = to_string(i);
	//	sum += i;
	//	//cout << sum;
	//	for (int i = 0;i < abc.length();i++) {
	//		sum += abc[i]-48;
	//		//cout << abc[i];
	//	}
	//	if (sum == n) {
	//		cout << i;
	//		return 0;
	//	}
	//	sum = 0;
	//}
	//cout << 0;

	//10250
	/*int h, w, n, T;
	cin >> T;
	for (int i = 0; i < T;i++) {
		cin >> h >> w >> n;
		if(n%h != 0)
			cout << (n % h) * 100 + (n / h) + 1 << endl;
		else if(n%h == 0)
			cout << (h) * 100 + n/h << endl;
	}
	return 0;*/
	//4153
	/*int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}
		if (a* a + b * b == c * c || b*b + c*c == a*a || a*a + c*c == b*b) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}*/

	//1085
	//int x, y, w, h;
	//int a[4];
	//cin >> a[0] >> a[1] >> a[2] >> a[3];
	////h-y, y, w-x, x비교
	//a[2] = a[2] - a[0];
	//a[3] = a[3] - a[1];
	//int shortTime = 0x7f7f7f7f;
	//for (int i = 0;i < 4;i++) {
	//	if (shortTime > a[i]) {
	//		shortTime = a[i];
	//	}
	//}
	//cout << shortTime;

	//18111
	//int col, row, block;
	//int time = 0;
	//int highNumber;
	//cin >> col >> row >> block;
	//vector<vector<int>> v;
	//v.assign(col, vector<int>(row, 0));
	//for (int i = 0;i < col;i++) {
	//	for (int j = 0;j < row;j++) {
	//		int a;
	//		cin >> a;
	//		v[i][j] = a;
	//	}
	//}
	//int add = 0;
	//int remove = 0;
	//int shortTime=0x7f7f7f7f;
	//for (int h = 0;h <= 256;h++) {
	//	for (int i = 0;i < col;i++) {
	//		for (int j = 0;j < row;j++) {
	//			if (v[i][j] - h > 0) {//지워야할
	//				remove+=(v[i][j]-h);
	//			}
	//			else if (v[i][j] - h < 0) {//채워야할
	//				add+=(h-v[i][j]);
	//			}
	//		}
	//	}
	//	if (remove + block >= add) {
	//		time = remove*2 + add ;
	//		if (shortTime >= time) {
	//			shortTime = time;
	//			highNumber = h;
	//		}
	//	}
	//	remove = 0;
	//	add = 0;
	//}

	//cout << shortTime << " " << highNumber;
}


