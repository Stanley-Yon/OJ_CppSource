# include <iostream>
# include <cstdio>
# include <set>

using namespace std ;

int n , m ;
int g[105][105] ;
set < pair< int , int > > heap ;
int dis[4][40005] ;

void dij( int s , int tmp )
{
	while ( heap.size() )
	{
		heap.erase( heap.begin() ) ;
	}
	for ( int i = 1 ; i <= n ; i++ )
		dis[tmp][i] = 1e9 + 5 ;
	dis[tmp][s] = 0 ;
	heap.insert( make_pair( dis[tmp][s] , s ) ) ;
	for ( int i = 1; i <= n ; i++ )
	{
		int x = heap.begin() -> second ;
		int d = heap.begin() -> first ;
		heap.erase( make_pair( d , x ) ) ;
		for ( int j = 1 ; j <= n ; j++ )
		{
			if ( dis[tmp][x] + g[x][j] >= dis[tmp][j] )
				continue ;
			heap.erase( make_pair( dis[tmp][j] , j ) ) ;
			dis[tmp][j] = dis[tmp][x] + g[x][j] ;
			heap.insert( make_pair( dis[tmp][j] , j ) ) ;
		}
	}
	return ;
}

int main()
{
	for ( int i = 1 ; i <= 100 ; i++ )
		for ( int j = 1 ; j <= 100 ; j++ )
			g[i][j] = 1000000000 ;
	scanf("%d%d" , &n , &m) ;
	for ( int i = 1 ; i <= m ; i++ )
	{
		int x , y , z ;
		scanf("%d%d%d" , &x , &y , &z) ;
		g[x][y] = z ;
		g[y][x] = z ;
	}
	dij( 1 , 1 ) ;
	dij( n , 2 ) ;
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		for ( int j = 1; j <= n ; j++ )
		{
			if ( dis[1][i] + g[i][j] + dis[2][j] == dis[1][n] )
			{
				g[i][j] *= 2 ;
				g[j][i] *= 2 ;
				dij( 1 , 3 ) ;
				g[i][j] /= 2 ;
				g[j][i] /= 2 ;
				ans = max( ans , dis[3][n] - dis[1][n] ) ;
			}
		}
	}
	printf("%d\n" , ans) ;
    system("pause");
	return 0 ;
}