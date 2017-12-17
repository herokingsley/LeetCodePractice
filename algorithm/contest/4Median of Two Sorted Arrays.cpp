#include <iostream>
#include <vector>
using namespace std;

    int min(int a, int b){
        return a < b ? a: b;
    }
    int max(int a, int b){
        return a > b ? a: b;
    }
    int minelement(int indexa, int indexb, vector<int>& nums1 , vector<int>& nums2){
        if(indexa == nums1.size()){
            return nums2[indexb];
        }
        if(indexb == nums2.size()){
            return nums1[indexa];
        }
        return min(nums1[indexa], nums2[indexb]);
    }
    
    int maxelement(int indexa, int indexb, vector<int>& nums1 , vector<int>& nums2){
        if(indexa == nums1.size()){
            return nums2[indexb];
        }
        if(indexb == nums2.size()){
            return nums1[indexa];
        }
        return max(nums1[indexa], nums2[indexb]);
    }
    
int next(int temp, int tl, int tr){
	if(tl +1 == tr ){
		if(temp == tl){
			return tr;
		}else{
			return tl;
		}
	}
	return (tl + tr) /2;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int l = l1 + l2;
        int mid = l / 2;
        int temp, temp2 = 0;
        if(l1 < l2){
            nums1.swap(nums2);
            l1 = nums1.size();
            l2 = nums2.size();
        }
        if(l2 == 0){
            if(l1 % 2 == 0){
                return (double) (nums1[l1 / 2] + nums1[l1 / 2 - 1]) /2;
            }else{
                return (double) nums1[l1 / 2];
            }
        }
        int tl = 0, tr = l1 - 1;
        temp = (tl + tr) / 2;
        int c = 0;
        while(true){
        	c ++;
        	if(c > 100)break;
        	temp2 = mid - temp;
        	cout<<tl<<" "<<tr<<" "<<temp<<" "<<temp2<<endl;
            if(temp > mid){ 
                tr = temp;
                //temp = (tl + tr) / 2;
                temp = next(temp, tl, tr);
                continue;
            }
            if(temp2 > l2){
                tl = temp;
                //temp = (tl + tr) /2;
                temp = next(temp, tl, tr);
                continue;
            }
            if(temp2 == 0){
                if(nums1[temp - 1] <= nums2[0]){
                    break;
                }else{
                    tr = temp;
                    //temp = (tl + tr) / 2;
                    temp = next(temp, tl, tr);
                    continue;
                }
            }else if(temp2 == l2){
                if(nums2[temp2 - 1] <= nums1[temp]){
                    break;
                }else{
                    tl = temp;
                    //temp = (tl + tr) / 2;
                    temp = next(temp, tl, tr);
                    continue;
                }
            }else{
                if(nums1[temp - 1] <= nums2[temp2] && nums2[temp2 - 1] <= nums1[temp]){
                    break;
                }else if(nums1[temp - 1] > nums2[temp2]){
                    tr = temp;
                    //temp = (tl + tr) / 2;
                    temp = next(temp, tl, tr);
                    continue;
                }else{
                    tl = temp;
                    //temp = (tl + tr) / 2;
                    temp = next(temp, tl, tr);
                    continue;
                }
            }
            
        }
        cout<<temp<<" "<<temp2<<endl;
        if( l % 2 == 0){
            int s;
            if(temp2 == 0){
                s = nums1[temp - 1] + minelement(temp, 0, nums1, nums2);
            }else if(temp2 == l2){
                s = maxelement(temp - 1, l2 - 1, nums1, nums2) + nums1[temp];
            }else{
                s = maxelement(temp - 1, temp2 - 1, nums1, nums2) + minelement(temp, temp2, nums1, nums2);
            }
            return (double)s / 2;
        }else{
            if(temp2 == 0){
                return (double) minelement(temp,0, nums1, nums2);
            }else if(temp2 == l2){
                return (double) nums1[temp];
            }else{
                return (double) minelement(temp, temp2, nums1, nums2);
            }
        }
    }


int main(){
	
	vector<int> num1;
	vector<int> num2;
	num1.push_back(2);
	num2.push_back(1);
	num2.push_back(3);
	num2.push_back(4);
	double r = findMedianSortedArrays(num1, num2);
	cout<<"result: "<<r<<endl;	
	
}
