#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define int long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
typedef long long LL;
const int N = 3e5 + 100;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
int t, n, m;
int root[N];
int road[N];//ͬһ����ͨ·��
int cnt[N];//ͬһ��������
int ans;
void init() {//��ʼ��
	for (int i = 0; i <= n; i++) {
		root[i] = i;//��ʼ���Լ�Ϊ��
		road[i] = 0;//��ʼûͨ·
		cnt[i] = 1;//��ʼֻ���Լ�һ����
	}
	return;
}
int find(int x) { return x == root[x] ? x : root[x] = find(root[x]); }//·��ѹ��
void merge(int x, int y) {
	int dx = find(x);
	int dy = find(y);
	if (dx != dy) {//��ͬ��
		cnt[dx] += cnt[dy];//������������
		road[dx] += road[dy];//����ͨ·������
        //���������Ӳ���֮��
		root[dy] = dx;
		road[dx] ++;//����ʱ���ӵ�һ��ͨ·
	}
	else {//ͬ����ֻ��ͨ·������
		road[dx] ++;
	}
	return;
}
void solve() {
	init();
	int x, y;
	while (m--) {//�ӱ߲���
		cin >> x >> y;
		if (y < x) swap(x, y);//������Ĭ��ǰ��Ⱥ������Ŵ󣬲�֪����merge��û��Ӱ��
		merge(x, y);
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (root[i] == i) {
			int t = road[i] - cnt[i];
			if (t >= 0) ans += t;//�������Ϊ�������
		}
	}
	return;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		solve();
		cout << "Case #" << i << ": " << ans << endl;//���
	}
    system("pause");
	return 0;
}