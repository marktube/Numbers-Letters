#include<iostream>

using namespace std;

int Mi[5] = { 0 }, target = 0, Max_n = 0;

void DFS(int nums[], int len);

bool Cmp_exist(int a);

int main(){
  int testcases = 0;
  cin >> testcases;
  while (testcases--)
    {
      Max_n = -99999999;
      for (int i = 0; i < 5; i++)
	cin >> Mi[i];
      cin >> target;
      for (int i = 0; i < 5; i++)
        {
	  if (Cmp_exist(Mi[i]))
            {
	      if (Mi[i]>Max_n)
                {
		  Max_n = Mi[i];
                }
            }
        }
      DFS(Mi, 5);
      cout << Max_n<<endl;
    }
  return 0;
}

//每次取2个数进行运算，将运算完的结果和剩下的数组成新的数组，再继续进行相同的操作，注意减法与除法的顺序
//以及除以0和是否可整除的问题

void DFS(int nums[], int len){
  if (len <= 1)
    {
      if (Cmp_exist(nums[0])){
	if (Max_n < nums[0])
	  {
	    Max_n = nums[0];
	  }
      }
    }
  else
    {
      bool found = false;
      for (int i = 0; i < len; i++)
        {
	  if (!found)
            {
	      for (int j = i + 1; j < len; j++){
		if (!found)
		  {
		    int res[5] = { 0 }, upside = 4;
		    res[0] = nums[i] + nums[j];
		    res[1] = nums[i] - nums[j];
		    res[2] = nums[j] - nums[i];
		    res[3] = nums[i] * nums[j];
		    if ((nums[j] != 0) && (nums[i] % nums[j] == 0)){
		      res[4] = nums[i] / nums[j];
		      upside = 5;
		    }
		    if ((nums[i] != 0) && (nums[j] % nums[i] == 0)){
		      res[4] = nums[j] / nums[i];
		      upside = 5;
		    }
		    for (int k = 0; k < upside; k++)
		      {
			if (Cmp_exist(res[k])){
			  if (Max_n < res[k])
			    {
			      Max_n = res[k];
			      if (res[k] == target)
				{
				  found = true;
				  break;
				}
			    }
			}
			int tmp[5] = { nums[0], nums[1], nums[2], nums[3], nums[4] };
			tmp[j] = tmp[len - 1];
			tmp[i] = res[k];
			DFS(tmp, len - 1);
		      }
		  }
		else
		  break;
	      }
            }
	  else
	    break;
        }
    }
}

bool Cmp_exist(int a){
  if (a > target)
    return false;
  return true;
}                                 
