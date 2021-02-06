// smaller first ->priority queue max_heap
    //     3 2 
    //     3 2
    //     5 3
    //     6 5
    //     6 5
    // 3 3 2 1
    // 3 3 2 2
    // 4 3 3 2
    // 5 4 3 3 
    // 5 5 4 3
    // 6 5 5 4
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()<k)
            {
                // cout<<k;
                pq.push(nums[i]);
            }
            else
            {
                if(pq.top()<=nums[i])
                {
                    // cout<<nums[i];
                    // cout<<pq.top()<<" "<<nums[i];
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }