// You are given a string containing characters  and  only. Your task is to change it into a string such 
// that there are no matching adjacent characters. 
// To do this, you are allowed to delete zero or more characters in the string.
// Your task is to find the minimum number of required deletions.
// For example, given the string , remove an  at positions  and  to make  in  deletions.

// Function Description
// Complete the alternatingCharacters function in the editor below. It must return an integer representing 
// the minimum number of deletions to make the alternating string.
// alternatingCharacters has the following parameter(s):
// s: a string

// Input Format
// The first line contains an integer , the number of queries.
// The next  lines each contain a string .

// Constraints
// Each string  will consist only of characters  and 

// Output Format
// For each query, print the minimum number of deletions required on a new line.

// Sample Input
// 5
// AAAA
// BBBBB
// ABABABAB
// BABABA
// AAABBB

// Sample Output
// 3
// 4
// 0
// 0
// 4

// Explanation
// The characters marked red are the ones that 
//can be deleted so that the string doesn't have matching consecutive characters.
#include<iostream>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    char preChar = s[0];
    int count = 0;

	for (std::string::size_type i = 1; i < s.size(); i++) {
		 if(s[i] == preChar)
         {
             count++;
         }
         preChar = s[i];
	}
    return count;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        cout << result << "\n";
    }

   // cout.close();

    return 0;
}