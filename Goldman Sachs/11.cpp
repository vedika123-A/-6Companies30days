 int *findTwoElement(int *arr, int n) {
        // code here
         int xor_all = 0, rt_set;
        for(int i=0; i<n; i++) xor_all ^= (arr[i])^(i+1);
        
        rt_set = xor_all & (-xor_all);
        
        // cout << (-xor_all) << " " << rt_set << endl;
        
        int a = 0, b = 0, i;
        
        for(int i=0; i<n; i++){
            if(arr[i] & rt_set) a = a^arr[i];
            else b = b^arr[i];
            
            if((i+1) & rt_set) a = a ^ (i+1);
            else b = b ^ (i+1);
        }
        
        for( i=0; i<n; i++)
        {
            if(arr[i] == a) break;
            
            // if(arr[i] == b) return *{a, b};
        }
    
        if(i<n){    
       int *ans = new int(2) ;
       ans[0] = a;
       ans[1] = b;
            return ans;
        }
        else {
            int *ans = new int(2) ;
            ans[0] = b;
            ans[1] = a;
            return ans;
        }
     }
};
