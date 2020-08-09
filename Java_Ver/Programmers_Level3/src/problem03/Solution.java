/*
 *  #. [ 프로그래머스_베스트앨범 Level 3 ]
 *  
 *  #. 문제 설명
 *     스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
 *     노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
 *     
 *     - 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
 *     - 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
 *     - 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
 *     
 *     노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 
 *     베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.
 *     
 *  #. 제한사항
 *     - genres[i]는 고유번호가 i인 노래의 장르입니다.
 *     - plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
 *     - genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
 *     - 장르 종류는 100개 미만입니다.
 *     - 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
 *     - 모든 장르는 재생된 횟수가 다릅니다.
 *  
 *  #. 입출력 예
 *                                    genres	                     plays	      return
 *     [classic, pop, classic, classic, pop]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
 *     
 *  #. 입출력 예 설명
 *     classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.
 *     고유 번호 3: 800회 재생
 *     고유 번호 0: 500회 재생
 *     고유 번호 2: 150회 재생
 *     
 *     pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.
 *     고유 번호 4: 2,500회 재생
 *     고유 번호 1: 600회 재생
 *     
 *     따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.
 */

/**
 *  #. 나의 풀이법
 *     - 처음 풀었을 때, 졸린 상태에서 풀어서 집중이 되지 않았다.
 *     - 차근차근 생각하고 내 논리대로 풀어보니 정답이었다.
 *     
 *     1. 우선 장르별로 총 재생 횟수 더한다. HashMap<String(장르), Integer(재생 수)> genreMap 
 *     2. genreMap을 value기준 내림 차순 정렬 (-> 이 부분이 살짝 어려웠음)
 *        value기준 정렬한것은 List가 된다.
 *     3. Iterator를 사용하여 정렬한 List를 순회하면서
 *        해당 장르이면, 임시 List에 삽입하고 이 tempList의 사이즈가 2이상이면, plays기준 내림차순 정렬 후,
 *        result List에 차례대로 2개 삽입한다.
 *        사이즈가 1이면, 1개만 삽입.
 *     4. 이 후result List -> answer로 대입
 * 
 * 
 */
package problem03;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

class Music {
	
	int index;
	String genre;
	int plays;
	
	Music(int index, String genre, int plays) {
		this.index = index;
		this.genre = genre;
		this.plays = plays;
	}
}

public class Solution {

	public int[] solution(String[] genres, int[] plays) {
		int[] answer = {};
		//
		
		//1. 장르별 총 재생 횟수 위한 hashMap -> 이후, value기준 내림차순 정렬
		HashMap<String, Integer> genreMap = new HashMap<>();
		//1.1. 각 노래 정보가 따로 있어서 묶어줄 list
		ArrayList<Music> musicList = new ArrayList<>();
		//1.2. answer에 대입하기 직전, 재생 수 가장 많은 장르안에서 재생 수 가장 많은 고유index 저장하는 list
		ArrayList<Music> bestAlbum = new ArrayList<>();
		
		//2. genreMap, musicList 초기화
		for(int i = 0; i < genres.length; i++) {
			
			if(genreMap.containsKey(genres[i]))
				genreMap.put(genres[i], genreMap.get(genres[i]) + plays[i]);
			else
				genreMap.put(genres[i], plays[i]);
			
			musicList.add(new Music(i, genres[i], plays[i]));
		}
		
		//3. genreMap에서 keySet변환 후, plays기준 정렬 
		List<String> keySetList = new ArrayList<>(genreMap.keySet());
		Collections.sort(keySetList, new Comparator<String>() {
			@Override
			public int compare(String key1, String key2) {
				return genreMap.get(key2).compareTo(genreMap.get(key1));
			}
		});
		
		//4. musicList에서 keyGenre와 같은 장르 찾고 list에 삽입 후, plays기준 내림차순 정렬  
		//   즉, plays가 가장 많은 장르에서 그 장르에 속한 Music을 찾는 과정이다.
		Iterator<String> iter = keySetList.iterator();
		while(iter.hasNext()) {
			String keyGenre = iter.next();
			//System.out.println(keyGenre);
			ArrayList<Music> tempList = new ArrayList<>();
			for(int i = 0; i < musicList.size(); i++) {
				if(keyGenre.equals(musicList.get(i).genre)) 
					tempList.add(musicList.get(i));
			}
			//여기까지 한번 돌면, 가장 재생 수가 많았던 장르의 노래들을 tempList에 삽입된다.
			//이후 tempList에서 plays순 기준 내림차순 정렬해야 한다.
			
			if(tempList.size() >= 2) {
				Collections.sort(tempList, new Comparator<Music>() {
					@Override
					public int compare(Music m1, Music m2) {
						return Integer.valueOf(m2.plays).compareTo(Integer.valueOf(m1.plays));
					}
				});
				//2곡만 담음
				bestAlbum.add(tempList.get(0));
				bestAlbum.add(tempList.get(1));
			}
			
			//장르에 속한 곡이 1개라면
			else if(tempList.size() == 1) 
				bestAlbum.add(tempList.get(0));
		}
		
		answer = new int[bestAlbum.size()];
		for(int i = 0; i < answer.length; i++)
			answer[i] = bestAlbum.get(i).index;
		
		//
		return answer;
	}

	public void printResult(int[] answer) {
		for(int i : answer)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {

		Solution s = new Solution();

		String[] genres = { "classic", "pop", "classic", "classic", "pop", "ROCK"};
		int[] plays = { 500, 600, 150, 800, 2500, 10000};

		s.printResult(s.solution(genres, plays));
	}
}
