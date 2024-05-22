#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <bitset>
#include <map>
#include <sstream>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

bool bcmp(int& a, int& b) {
	return a > b;
}

int main() {
	//1920
	ios::sync_with_stdio(false);
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
	}

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


