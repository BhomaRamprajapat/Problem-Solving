    vector<int> subarraySum(int arr[], int n, long long s)
    {
     long long sum=0;
     int start=0;
     
     for(int i=0;i<n;i++)
     {
      sum+=arr[i];
      
      if(sum>s)
       while(sum>s && start<=i)
        sum-=arr[start++];
        
      if(sum==s && start<=i)
      {
       return {start+1,i+1};
      }
     }
     return {-1};
    }