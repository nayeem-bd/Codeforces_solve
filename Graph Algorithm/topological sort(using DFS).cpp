//Complexity: O(V+E)

For DAG :

  #define M 55
  vector<int> ans, depends[M];
  int taken[M];

  // depends[i] contains all the items that item i is depending on
  // when taken[i] = 1, that means it's already taken

  void take( int p ) {
      if( !taken[ p ] ) {
          // i am taking all the items that i should take before p
          for(int i=0; i<depends[p].size(); i++)
              take( depends[p][i] );
          ans.push_back( p ); // now i can take it   
          taken[p] = 1;
      }
  }

  int main() {
      // input routine
      // .....

      for(int i=0; i<n; i++) take( i );
      for(int i=0; i<n; i++) printf("%d\n", ans[i] );

      return 0;
  }

if contain cycle:


#define M 55
int visited[M], cycle = 0;
vector<int> edge[M];

void visit( int p ) {
    if( visited[p] == 2 || cycle ) return;
    // we won't process anything if we already have found a cycle
    if( visited[p] == 1 ) {
        cycle = 1; // found cycle
        return;
    }
   
    visited[p] = 1;
    for(int i=0; i<edge[p].size(); i++) visit( edge[p][i] );
    visited[p] = 2;
}

