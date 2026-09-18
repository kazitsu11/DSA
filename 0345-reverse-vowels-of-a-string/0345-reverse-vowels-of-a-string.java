class Solution {
    public String reverseVowels(String s) {
        Set<Character> st = Set.of('a', 'e', 'i', 'o', 'u');

        char[] arr = s.toCharArray();

        int left = 0;
        int right = arr.length - 1;

        while(left < right) {

            while(left < right &&
                  !st.contains(Character.toLowerCase(arr[left]))) {
                left++;
            }

            while(left < right &&
                  !st.contains(Character.toLowerCase(arr[right]))) {
                right--;
            }

            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }

        return new String(arr);
    }
}