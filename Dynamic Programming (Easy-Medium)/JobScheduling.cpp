class Solution 
{
   public:
   //Function to find the maximum profit and the number of jobs done.
   static bool mycmp(Job a,Job b){
       return a.profit>b.profit;
   }
   vector<int> JobScheduling(Job arr[], int n) 
   { 
       // your code here
       vector<int>v(2,0);
       vector<int>mp(101,0);
       sort(arr,arr+n,mycmp);
       for(int i =0;i<n;i++){
           for(int j=arr[i].dead;j>0;j--){
               if(mp[j] == 0){
                   mp[j]=arr[i].id;
                   v[0]++;
                   v[1] += arr[i].profit;
                   break;
               }
           }
       }
       return v;
       
   } 
};
