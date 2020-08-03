package toss;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Stack;

public class Main03 {

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		
		DecimalFormat formatter = new DecimalFormat("###,###");
		int n = Integer.valueOf(input);
		
		String[] unit = {"원", "만 ", "억 ", "조 "};
		
		ArrayList<String> result = new ArrayList<>();
		
		for (int i = 0; i < n; i++) {
			String num = br.readLine();
			if (num.length() > 3 && num.charAt(num.length() - 4) == ',') {
				num = num.replace(",", "");
			}
			
			Stack<Character> s = new Stack<>();
			for(int j = 0; j < num.length(); j++) {
				s.push(num.charAt(j));
			}
			
			String[] temp;
			if(num.length() % 4 != 0)
			   temp = new String[num.length() / 4 + 1];
			else
				temp = new String[num.length() / 4];
			
			StringBuilder sb = new StringBuilder();
			int count = 0;
			int t = 0;
			while(!s.isEmpty()) {
				count++;
				sb.append(s.pop());
				if(count == 4 || s.isEmpty()) {
					temp[t++] = sb.reverse().toString();
					sb = new StringBuilder();
					count = 0;
				}
			}
			
			ArrayList<String> list = new ArrayList<>();
			String answer = "";
			sb = new StringBuilder();
			int u = 0;
			for(int j = 0; j < temp.length; j++) {
				int unitNum = Integer.valueOf(temp[j]);
				if(unitNum == 0) {
					u++;
				}
				else
					list.add(formatter.format(unitNum) + unit[u++]);
			}
			for(int j = list.size() - 1; j >= 0; j--) {
				answer += list.get(j);
			}
			result.add(answer);
		}
		
		for(String s : result)
			System.out.println(s);
	}
}
