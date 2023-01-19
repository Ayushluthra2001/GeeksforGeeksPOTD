class Solution{
    public:
    int findMoves(int a, int b, int c, int d){
        int moves=0;
        while(a>c || b>d){
            if(a>c) moves++; a/=2;
            if(b>d) moves++; b/=2;
        }
        return moves;
    }
    int carpetBox(int a, int b, int c, int d){
        return min(findMoves(a,b,c,d), findMoves(b,a,c,d));
    }
};
