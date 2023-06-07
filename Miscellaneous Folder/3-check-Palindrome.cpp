
// https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633


bool checkPalindrome(string s)
{
    // Convert all upper case alphabets to lower case
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }
    
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        // if the element at start pointer of the string is neither an alphabet or an integer move the start pointer rightwards

        if (!(s[start] >= 'a' && s[start] <= 'z') && !(s[start] >= '0' && s[start] <= '9'))
        {
            start++;
        }
        // if the element at end pointer of the string is neither an alphabet or an integer move the end pointer leftwards

        else if (!(s[end] >= 'a' && s[end] <= 'z') && !(s[end] >= '0' && s[end] <= '9'))
            end--;

        // if the elements at start and end pointers are not same then return false

        else if (s[start] != s[end])
            return false;

        // if the elements at start and end pointers are same then increment the start pointer and decrement the end pointer

        else
        {
            start++;
            end--;
        }
    }
    return true;
}
