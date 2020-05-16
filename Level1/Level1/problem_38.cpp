/*
  #. [ ��Ʈ ���� - 2018 Kakao Blind Recruitment ]

  #. īī���� ���Ӻ��� �Ϲݱ� �ű� ���񽺷� ��Ʈ ������ ����ϱ�� �ߴ�. 
     ��Ʈ ������ ��Ʈ�ǿ� ��Ʈ�� �� ���� ���� �� ������ �հ�� �Ƿ��� �ܷ�� ��������, ��ΰ� ������ ��� �� �ִ�.
     �� �Ի��� ������ �ڵ� �Ƿ��� �����޾� ������ �ٽ� �κ��� ���� ��� ������ �ð� �Ǿ���. 
     ��Ʈ ������ ���� ��� ������ �Ʒ��� ����.

     1. ��Ʈ ������ �� 3���� ��ȸ�� �����ȴ�.
     2. �� ��ȸ���� ���� �� �ִ� ������ 0������ 10�������̴�.
     3. ������ �Բ� Single(S), Double(D), Triple(T) ������ �����ϰ� 
     4. �� ���� ��÷ �� �������� 1����, 2����, 3���� (����1 , ����2 , ����3 )���� ���ȴ�.
     5. �ɼ����� ��Ÿ��(*) , ������(#)�� �����ϸ� ��Ÿ��(*) ��÷ �� �ش� ������ �ٷ� ���� ���� ������ �� 2��� �����. 
        ������(#) ��÷ �� �ش� ������ ���̳ʽ��ȴ�.
     
     6. ��Ÿ��(*)�� ù ��° ��ȸ������ ���� �� �ִ�. 
        �� ��� ù ��° ��Ÿ��(*)�� ������ 2�谡 �ȴ�. (���� 4�� ����)
     7. ��Ÿ��(*)�� ȿ���� �ٸ� ��Ÿ��(*)�� ȿ���� ��ø�� �� �ִ�. 
        �� ��� ��ø�� ��Ÿ��(*) ������ 4�谡 �ȴ�. (���� 4�� ����)
     8. ��Ÿ��(*)�� ȿ���� ������(#)�� ȿ���� ��ø�� �� �ִ�. 
        �� ��� ��ø�� ������(#)�� ������ -2�谡 �ȴ�. (���� 5�� ����)
     
     9. Single(S), Double(D), Triple(T)�� �������� �ϳ��� �����Ѵ�.
     10. ��Ÿ��(*), ������(#)�� �������� �� �� �ϳ��� ������ �� ������, �������� ���� ���� �ִ�.
     
     0~10�� ������ ���� S, D, T, *, #�� ������ ���ڿ��� �Էµ� �� �������� ��ȯ�ϴ� �Լ��� �ۼ��϶�.

  #. �Է� ����
     ���� | ���ʽ� | [�ɼ�]���� �̷���� ���ڿ� 3��Ʈ.
     ��) 1S2D*3T

     ������ 0���� 10 ������ �����̴�.
     ���ʽ��� S, D, T �� �ϳ��̴�.
     �ɼ��� *�̳� # �� �ϳ��̸�, ���� ���� �ִ�.
  
  #. ��� ����
     3���� ��ȸ���� ���� ���� �հ迡 �ش��ϴ� �������� ����Ѵ�.
     ��) 37

  #. ����� ����
     ����	    dartResult	     answer	        ����
       1	       1S2D*3T	        37	        11 * 2 + 22 * 2 + 33
       2	      1D2S#10S	         9	        12 + 21 * (-1) + 101
       3	        1D2S0T	         3	        12 + 21 + 03
       4	      1S*2T*3S	        23	        11 * 2 * 2 + 23 * 2 + 31
       5	      1D#2S*3S	         5	        12 * (-1) * 2 + 21 * 2 + 31
       6	       1T2D3D#	        -4	        13 + 22 + 32 * (-1)
       7	       1D2S3T*	        59	        12 + 21 * 2 + 33 * 2
*/

#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    //
    cout << dartResult << "\n";
    vector<int> numeric;
    vector<char> bonus;
    vector<char> option;
  
    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= 'A' && dartResult[i] <= 'Z')
        {
            bonus.push_back(dartResult[i]);
            if (dartResult[i + 1] == '*')
                option.push_back('*');
            else if (dartResult[i + 1] == '#')
                option.push_back('#');
            else
                option.push_back(' ');
        }
        else if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (dartResult[i + 1] == '0')
            {
                numeric.push_back(10);
                i++;
            }
            else
                numeric.push_back(dartResult[i] - '0');
        }
    }

    int digit = 0;
    vector<int> sub_score;

    for (int i = 0; i < 3; i++)
    {
        digit = numeric[i];
        
        if (bonus[i] == 'S')
            digit = digit * 1;
        else if (bonus[i] == 'D')
            digit = digit * digit;
        else if (bonus[i] == 'T')
            digit = digit * digit * digit;
        
    
        if (option[i] == '*')
        {
            sub_score.push_back(digit * 2);
            if (i >= 1)
                sub_score[i-1] *= 2;
        }
        else if (option[i] == '#')
            sub_score.push_back(digit * -1);
        else if (option[i] == ' ')
            sub_score.push_back(digit);
    }

    for (int i = 0; i < sub_score.size(); i++)
    {
        //cout << sub_score[i] << " ";
        answer += sub_score[i];
    }
    cout << "\n";
    //
    return answer;
}

void printResult(int answer)
{
    cout <<"answer :: " << answer << "\n";
}

int main()
{

    printResult(solution("1S2D*3T"));
    printResult(solution("1D2S#10S"));
    printResult(solution("1D2S0T"));
    printResult(solution("1S*2T*3S"));
    printResult(solution("1D#2S*3S"));
    printResult(solution("1T2D3D#"));
    printResult(solution("1D2S3T*"));
    printResult(solution("1D#10S*2S*"));
    

    return 0;
}