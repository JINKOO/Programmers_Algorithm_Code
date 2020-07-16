/*
  #. [ ���α׷��ӽ�_�Ҽ� ����� Level 2 ]
  
  #. ���� ����
     �־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�. 
     ���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, nums�� �ִ� ���ڵ� �� ���� �ٸ� 3���� ��� ������ ��, 
     �Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

  #. ���ѻ���
     - nums�� ����ִ� ������ ������ 3�� �̻� 50�� �����Դϴ�.
     - nums�� �� ���Ҵ� 1 �̻� 1,000 ������ �ڿ����̸�, �ߺ��� ���ڰ� ������� �ʽ��ϴ�.
     
  #. ����� ��
            nums	result
       [1,2,3,4]	     1
     [1,2,7,6,4]	     4

  #. ����� �� ����
 
     - ����� �� #1
       [1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.

     - ����� �� #2
       [1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.
       [1,4,6]�� �̿��ؼ� 11�� ���� �� �ֽ��ϴ�.
       [2,4,7]�� �̿��ؼ� 13�� ���� �� �ֽ��ϴ�.
       [4,6,7]�� �̿��ؼ� 17�� ���� �� �ֽ��ϴ�.
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> v;

bool is_prime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(vector<int>& nums, int index, int sum, int count)
{
    if (index >= nums.size())
        return;

    sum += nums[index];

    for (int i = index; i < nums.size(); i++)
    {
        if (count == 2)
        {
            v.push_back(sum);
            return;
        }
        else
            dfs(nums, i + 1, sum, count + 1);
    }
}

int solution(vector<int> nums) 
{
    int answer = 0;
    //

    for (int i = 0; i < nums.size() - 2; i++)
        dfs(nums, i, 0, 0);

    for (int i : v)
    {
        //cout << i << " ";
        if (is_prime(i))
            answer++;
    }
    //
    return answer;
}

int main()
{

    cout << solution({ 1,2,3,4 }) << "\n";
    v.clear();
    cout << solution({ 1,2,7,6,4 }) << "\n";

    return 0;
}