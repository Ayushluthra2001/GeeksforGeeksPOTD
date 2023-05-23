Node* solve( int pre[] , int preMirror[] , int l1 , int r1 , int l2 , int r2 )
    {
        if( l1 > r1 or l2 > r2 ) return NULL ;
        
        Node* root = new Node(pre[l1]) ;
        
        int nr1 = INT_MAX ;
        
        if( l2 + 1 <= r2 )
        {
            for( int  j = l1 ; j <= r1 ; j++ )
            {
                if( pre[j] == preMirror[l2+1] )
                {
                    nr1 = j ;
                    break ;
                }
            }
        }
        
        int nr2 = INT_MAX ;
        
        if( l1 + 1 <= r1 )
        {
            for( int  j = l2 ; j <= r2 ; j++ )
            {
                if( preMirror[j] == pre[l1+1] )
                {
                    nr2 = j ;
                    break ;
                }
            }
        }
        
        if( nr1 != INT_MAX && nr2 != INT_MAX )
        {
            root->left  = solve( pre , preMirror , l1 + 1 , nr1-1 , nr2 , r2 ) ;
            root->right = solve( pre , preMirror , nr1  , r1 , l2+1 , nr2-1 ) ;
        }
        
        return root ;
        
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        
        return solve( pre , preMirror , 0 , size-1 , 0 , size-1 ) ;
    }
