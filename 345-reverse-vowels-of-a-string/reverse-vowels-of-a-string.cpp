class Solution {
public:
       bool isvowel(char c){
             c = tolower(c);
             return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
        }
    string reverseVowels(string s) {
        //first need to chech is this vowel or not then do operation
        int i=0, j=s.size()-1;
        while(i<j){
            if(isvowel(s[i])&&isvowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(!isvowel(s[i]))i++;
            else if(!isvowel(s[j]))j--;
        }
        return s;
    }
};