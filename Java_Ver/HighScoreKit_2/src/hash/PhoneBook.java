package hash;

import java.util.HashMap;
import java.util.Map;

public class PhoneBook {

    public boolean solution(String[] phone_book) {
        boolean answer = true;

        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < phone_book.length; i++) {
            map.put(phone_book[i], i);
        }

        for (String phoneNumber : phone_book) {
            for (int i = 0; i < phoneNumber.length(); i++) {
                if (map.containsKey(phoneNumber.substring(0, i))) {
                    return false;
                }
            }
        }

        return answer;
    }

    public static void main(String[] args) {

        PhoneBook phoneBook = new PhoneBook();

        String[] phoneBook1 = {"119", "97674223", "1195524421"};
        String[] phoneBook2 = {"123","456","789"};
        String[] phoneBook3 = {"12","123","1235","567","88"};

        System.out.println(phoneBook.solution(phoneBook1));
        System.out.println(phoneBook.solution(phoneBook2));
        System.out.println(phoneBook.solution(phoneBook3));
    }
}
