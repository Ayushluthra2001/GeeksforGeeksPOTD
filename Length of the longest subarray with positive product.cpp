int maxLength(vector<int> &arr,int n){

           //code here

           int poslen=0 , neglen=0 ;

           int ans = 0;

           for(int i=0;i<n;i++){

               if(arr[i]==0) {

                   poslen=0 ;

                   neglen=0 ;

               }

              else if(arr[i]>0){

                   poslen++ ;

                   if(neglen>0) neglen++ ;

                   ans = max(ans, poslen) ;

               }

               else{

                   swap(poslen , neglen) ;

                   neglen++ ;

                   if(poslen>0) poslen++ ;

                   ans = max(ans, poslen) ;

               }

           }

           return ans ;

        }
