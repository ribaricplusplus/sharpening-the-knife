package a1278;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);
        String password;
        String passwordHash;
        int testCases = inputScanner.nextInt();
        inputScanner.nextLine();
        for (int i = 0; i < testCases; i++) {
            password = inputScanner.nextLine();
            passwordHash = inputScanner.nextLine();
            System.out.println(solution(password, passwordHash));
        }
    }

    private static String solution(String password, String passwordHash) {
        int lastIndex = passwordHash.length() - password.length();
        if (lastIndex < 0) {
            return "NO";
        }
        for (int i = 0; i <= lastIndex; i++) {
            if (isPermutation(password, passwordHash.substring(i, i + password.length()))) {
                return "YES";
            }
        }
        return "NO";
    }

    private static boolean isPermutation(String password, String substring) {
        Map<Character, Integer> frequenciesPassword = new HashMap<>();
        Map<Character, Integer> frequenciesSubstring = new HashMap<>();
        for (int i = 0; i < password.length(); i++) {
            if (frequenciesPassword.containsKey(password.charAt(i))) {
                int currentFrequency = frequenciesPassword.get(password.charAt(i));
                ++currentFrequency;
                frequenciesPassword.put(password.charAt(i), currentFrequency);
            } else {
                frequenciesPassword.put(password.charAt(i), 1);
            }
            if (frequenciesSubstring.containsKey(substring.charAt(i))) {
                int currentFrequency = frequenciesSubstring.get(substring.charAt(i));
                ++currentFrequency;
                frequenciesSubstring.put(substring.charAt(i), currentFrequency);
            } else {
                frequenciesSubstring.put(substring.charAt(i), 1);
            }
        }
        return frequenciesPassword.equals(frequenciesSubstring);
    }
}
