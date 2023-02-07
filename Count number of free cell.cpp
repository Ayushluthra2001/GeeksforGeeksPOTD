vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){

      //Code Here

      

      unordered_map< int , int >row , col ;

      vector<long long int>ans ;

      

      for( int i = 0 ; i < k ; i++ )

      {

          row[arr[i][0]]++ ;

          col[arr[i][1]]++ ;

          

          int r = row.size() , c = col.size() ;

          long long int t = n*n - ( r*n + c*n - r*c ) ;

          ans.push_back(t) ;

      }

      

      return ans ;

  }
