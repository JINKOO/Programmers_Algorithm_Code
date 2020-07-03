/*
  #. [ �ٸ��� ������ Ʈ�� ]
  #. ���� ����
     Ʈ�� ���� �밡 ���� ���������� �� ���� �ٸ��� ������ ������ �ǳʷ� �մϴ�. 
     ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� �˾Ƴ��� �մϴ�. 
     Ʈ���� 1�ʿ� 1��ŭ �����̸�, �ٸ� ���̴� bridge_length�̰� �ٸ��� ���� weight���� �ߵ��ϴ�.
     �� Ʈ���� �ٸ��� ������ ������ ���� ���, �� Ʈ���� ���Դ� ������� �ʽ��ϴ�.

     
     ���� ���, ���̰� 2�̰� 10kg ���Ը� �ߵ�� �ٸ��� �ֽ��ϴ�. 
     ���԰� [7, 4, 5, 6]kg�� Ʈ���� ������� �ִ� �ð� �ȿ� �ٸ��� �ǳʷ��� ������ ���� �ǳʾ� �մϴ�.
       
     ��� �ð�	�ٸ��� ���� Ʈ��	    �ٸ��� �ǳʴ� Ʈ��	      ��� Ʈ��
           0	             []	                   []	     [7,4,5,6]
         1~2	             []	                  [7]	       [4,5,6]
           3	            [7]	                  [4]	         [5,6]
           4	            [7]	                [4,5]	           [6]
           5	          [7,4]	                  [5]	           [6]
         6~7	        [7,4,5]	                  [6]	            []
           8	      [7,4,5,6]	                   []	            []

     ����, ��� Ʈ���� �ٸ��� �������� �ּ� 8�ʰ� �ɸ��ϴ�.
     
     solution �Լ��� �Ű������� �ٸ� ���� bridge_length, �ٸ��� �ߵ� �� �ִ� ���� weight, Ʈ���� ���� truck_weights�� �־����ϴ�. �̶� ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

  #. ���� ����
     - bridge_length�� 1 �̻� 10,000 �����Դϴ�.
     - weight�� 1 �̻� 10,000 �����Դϴ�.
     - truck_weights�� ���̴� 1 �̻� 10,000 �����Դϴ�.
     - ��� Ʈ���� ���Դ� 1 �̻� weight �����Դϴ�.
 
  #. ����� ��
     bridge_length	     weight	                   truck_weights	   return
                 2	         10	                       [7,4,5,6]	        8
               100	        100	                            [10]	      101
               100	        100	 [10,10,10,10,10,10,10,10,10,10]	      110
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    //
    queue<int> q;
    int current_weight = 0;
    for (int i = 0; i < truck_weights.size(); i++)
    {
        int truck = truck_weights[i];

        if (current_weight + truck <= weight)
        {
            current_weight += truck;
            q.push(truck);
        }

        else
        {

        }
    }
    //
    return answer;
}

int main()
{

    cout << solution(2, 10, { 7,4,5,6 }) << "\n";
    cout << solution(100, 100, { 10 }) << "\n";
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << "\n";

    return 0;
}