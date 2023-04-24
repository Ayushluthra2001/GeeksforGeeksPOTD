vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        
        left[0] = INT_MAX;
        st.push(0);
        for(int i=1; i<n; i++)
        {
            if(st.size()==0)
            {
                left[i] = INT_MAX;
            }
            else
            {
                int f = 0;
                while(st.size()>0)
                {
                    if(arr[st.top()]<arr[i])
                    {
                        left[i] = st.top();
                        st.push(i);
                        f=1;
                        break;
                    }
                    st.pop();
                }
                if(f==0) 
                {
                    left[i] = INT_MAX;
                    st.push(i);
                }
            }
        }
        
        right[n-1] = INT_MAX;
        st.push(n-1);
        for(int i=n-1; i>=0; i--)
        {
            if(st.size()==0)
            {
                right[i] = INT_MAX;
            }
            else
            {
                int f = 0;
                while(st.size()>0)
                {
                    if(arr[st.top()]<arr[i])
                    {
                        right[i] = st.top();
                        st.push(i);
                        f=1;
                        break;
                    }
                    st.pop();
                }
                if(f==0) 
                {
                    right[i] = INT_MAX;
                    st.push(i);
                }
            }
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            if(left[i]==INT_MAX && right[i]==INT_MAX) ans[i]=-1;
            else if(left[i]==INT_MAX && right[i]!=INT_MAX) ans[i]=right[i];
            else if(right[i]==INT_MAX && left[i]!=INT_MAX) ans[i]=left[i];
            else
            {
                if(arr[left[i]]==arr[right[i]] && abs(i-left[i]) ==  abs(i-right[i]))//same height and same distance
                {
                   ans[i] = min(left[i], right[i]);
                }
                else if(arr[left[i]]==arr[right[i]])//same height
                {
                    int x=abs(i-left[i]); int y=abs(i-right[i]);
                    if(x<y) ans[i] = left[i];
                    else ans[i]=right[i];
                }
                else if(abs(i-left[i]) ==  abs(i-right[i]))//same dist
                {
                    if(arr[left[i]]<=arr[right[i]]) ans[i]=left[i];
                    else ans[i] = right[i];
                }
                else
                {
                    int x=abs(i-left[i]); int y=abs(i-right[i]);
                    if(x<y) ans[i] = left[i];
                    else ans[i]=right[i];
                }
            }
        }
        return ans;
    }
