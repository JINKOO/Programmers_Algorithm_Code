package toss;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main02 {

	private int n;
	private String[] address;

	public String solution() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();

		StringBuilder sb = new StringBuilder();

		this.n = Integer.valueOf(input);
		this.address = new String[n];

		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			address[i] = line;
		}

		StringTokenizer stk = new StringTokenizer(address[0], ".");
		while (stk.hasMoreTokens()) {
			String str = stk.nextToken();
			boolean flag = false;
			for (int j = 1; j < address.length; j++) {
				if (address[j].contains(str))
					flag = true;
			}
			
			if(flag)
				sb.append(str + ".");

		}

		return sb.toString();

	}

	public static void main(String[] args) throws IOException {

		Main02 m = new Main02();
		System.out.println(m.solution());
	}
}
