#include<bits/stdc++.h>
using namespace std;
const char dirs[5]="NESW"; 
const char turns[4]="FLR";
const int dx[4]= {-1,0,1,0};
const int dy[4]= {0,1,0,-1};
inline int sdir(char c) {
	return strchr(dirs,c)-dirs;
}
inline int sturn(char t) {
	return strchr(turns,t)-turns;
}
int bx,by,bdir,ex,ey,nbx,nby;
bool edge[10][10][4][3];
int step[10][10][4];
struct node {
	int x;
	int y;
	int dir;
	node(int x=0,int y=0,int dir=0) {
		this->x=x;
		this->y=y;
		this->dir=dir;
	}
} father[10][10][4];
node walk(const node &n,int turn) {
	int dir=n.dir;
	if(turn==1) dir=(dir+3)%4;
	else if(turn==2) dir=(dir+1)%4;
	return node(n.x+dx[dir],n.y+dy[dir],dir);
}
inline bool isdir(const char &c) {
	return c=='W'||c=='N'||c=='E'||c=='S';
}
inline bool isturn(const char &c) {
	return c=='F'||c=='L'||c=='R';
}
bool read() {
	string s;
	cin>>s;
	if(s=="END") return 0;
	memset(step,-1,sizeof(step));
	memset(edge,0,sizeof(edge));
	cout<<s<<endl<<" ";
	char tdir;
	scanf("%d %d %c %d %d",&bx,&by,&tdir,&ex,&ey);
	bdir=sdir(tdir);
	int tx,ty;
	while(scanf("%d %d",&tx,&ty)==2) {
		string s1;
		getline(cin,s1);
		for(int i=0; i<s1.size(); ++i) {
			if(isdir(s1[i])) {
				register int dir1=sdir(s1[i]);
				while(isturn(s1[++i])) {
					register int turn1=sturn(s1[i]);
					edge[tx][ty][dir1][turn1]=1;
				}
			}
		}
	}
	nbx=bx+dx[bdir];
	nby=by+dy[bdir];
	return 1;
}
void print_ans(node &n) {
	vector<node> v;
	while(step[n.x][n.y][n.dir]) {
		v.push_back(n);
		n=father[n.x][n.y][n.dir];
	}
	v.push_back(node(nbx,nby,bdir));
	v.push_back(node(bx,by,bdir));
	int cnt=1;
	printf(" (%d,%d)",v.back().x,v.back().y);
	v.pop_back();
	while(!v.empty()) {
		++cnt;
		if((cnt=cnt%10)==1) {
			printf("\n  (%d,%d)",v.back().x,v.back().y);
			v.pop_back();
		} else {
			printf(" (%d,%d)",v.back().x,v.back().y);
			v.pop_back();
		}
	}
	return;
}
void solve() {
	queue<node> q;
	node nbegin(nbx,nby,bdir);
	step[nbx][nby][bdir]=0;
	q.push(nbegin);
	while(!q.empty()) {
		node tmp=q.front();
		q.pop();
		if(tmp.x==ex&&tmp.y==ey) {
			print_ans(tmp);
			cout<<endl;
			return;
		}
		for(int i=0; i<3; ++i) {
			if(edge[tmp.x][tmp.y][tmp.dir][i]) {
				node nn=walk(tmp,i);
				if(step[nn.x][nn.y][nn.dir]>-1) continue;
				q.push(nn);
				step[nn.x][nn.y][nn.dir]=step[tmp.x][tmp.y][tmp.dir]+1;
				father[nn.x][nn.y][nn.dir]=tmp;
			}
		}
	}
	cout<<" No Solution Possible"<<endl;
	return;
}
int main() {

	while(read()) solve();
	return 0;
}