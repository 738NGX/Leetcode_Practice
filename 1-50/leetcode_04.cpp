#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int>& v)
    {
        int size=v.size();
        if(size<=1) return;
        vector<int> v1=vector<int>(v.begin(),v.begin()+size/2);
        vector<int> v2=vector<int>(v.begin()+size/2,v.end());
        mergeSort(v1);
        mergeSort(v2);
        merge(v,v1,v2);
    }

    void merge(vector<int>& v,vector<int>& v1,vector<int>& v2)
    {
        vector<int> index={0,0};
        for(int i=0;i<v.size();i++)
        {
            if(index[0]==v1.size())
            {
                v[i]=v2[index[1]];
                index[1]++;
                continue;
            }
            else if(index[1]==v2.size())
            {
                v[i]=v1[index[0]];
                index[0]++;
                continue;
            }
            if(v1[index[0]]<v2[index[1]])
            {
                v[i]=v1[index[0]];
                index[0]++;
            }
            else
            {
                v[i]=v2[index[1]];
                index[1]++;
            }
        }
        return;
    }
    
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) 
    {
        int length=nums1.size()+nums2.size();
        vector<int> merged(length,0);
        mergeSort(nums1);
        mergeSort(nums2);
        merge(merged,nums1,nums2);
        if(length%2)
            return merged[length/2];
        else    
            return (merged[length/2-1]+merged[length/2])/2.0;
    }
};