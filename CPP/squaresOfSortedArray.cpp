vector<int> sortedSquares(vector<int> &nums)
{

    int n = nums.size();
    int first_pos = n;
    int behind_pos = n - 1;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {   
        //check for the first positive 
        if (nums[i] >= 0)
        {
            first_pos = i;  // make the current index as first positive and index behind it as first negative behind the positive.
            behind_pos = i - 1;
            break;
        }
    }

    //perform by taking boundary from 0 to firstpos ----> behind_pos 

    // And firstpos to n ----> first_pos

    //steps are combining both two pointer and merge two sorted Array Approach 

    while (behind_pos >= 0 && first_pos < n)
    {
        int negsquare = nums[behind_pos] * nums[behind_pos];
        int possquare = nums[first_pos] * nums[first_pos];
        if (negsquare <= possquare)
        {
            ans.push_back(negsquare);
            behind_pos--;
        }
        else
        {
            ans.push_back(possquare);
            first_pos++;
        }
    }
    while (behind_pos >= 0)
    {
        int negsquare = nums[behind_pos] * nums[behind_pos];
        ans.push_back(negsquare);
        behind_pos--;
    }
    while (first_pos < n)
    {
        int possquare = nums[first_pos] * nums[first_pos];
        ans.push_back(possquare);
        first_pos++;
    }
    return ans;
}
