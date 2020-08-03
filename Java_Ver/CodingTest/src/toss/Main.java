package toss;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	char[] hex = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	public String convertHex(int x) {

		StringBuilder sb = new StringBuilder();

		if(x == -1)
			return "#00";
		if(x == 100)
			return "#FF";
		
		while (x != 0) {
			sb.append(String.valueOf(hex[x % 16]));
			x /= 16;
		}
		return "#" + sb.reverse().toString();
	}

	public static void main(String[] args) throws IOException {
		
		Main m = new Main();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		StringTokenizer stk = new StringTokenizer(input, ",");

		String rgbCode = stk.nextToken();
		rgbCode = rgbCode.substring(1, rgbCode.length());
		int alpha = Integer.valueOf(stk.nextToken());

		int x = (alpha * 256) / 100 - 1;
		String alphaHex = m.convertHex(x);

		String answer = alphaHex + rgbCode;
		System.out.println(answer);
	}
}
