// leetcode.com/problems/permutation-in-string/description/

        // 2 string derkhi btana h ki badi string ka koi permutation choti string ke barabar h ya ni..

        // brute force....
        // intutitive logical..
        // choti string s1 ki freq vector me freq store krli har character ki...

        // fir loop lgaya bdi string me n2-n1 size ka...
        // s2.substr(i,n1)... i se leke n1 size ki substring nikalte gye..
        // fir ek aur freq vector bnaya usme us substring ki freq store krte rhe...agar freq vector equal hai..to return
        // true...warna bahar ake return false...

        // o(n2-n1+1* n1)==o(n2*n1)
        // o(1)..

        // optimal ...sliding window 2 pointer..
        // similar way me choti string ki freq vectr me store krlia..
        // l,r do pointr aur ek freq vector bdi string ka bnaya.... r<n2 window chlayi.
        // freq++ kri r pe jo char pda..freq2[s2[r]-'a']++....
        // fir outof bounds ki condition dali... fir condition match ki condition dali return true warna false...


class Solution{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2)
        {
            return false;
        }

        vector<int> freqS1(26, 0);

        for (char c : s1)
        {
            freqS1[c - 'a']++;
        }

        for (int i = 0; i <= n2 - n1; i++)
        {

            string substring = s2.substr(i, n1); // Extract substring of length n1

            vector<int> freqSub(26, 0);

            for (char c : substring)
            {
                freqSub[c - 'a']++;
            }

            if (freqS1 == freqSub)
            {
                return true;
            }
        }

        return false;
    }
};



//OPTIMAL..2 POINTER SLIDING WINDOW..
// o(n1+n2)..
// o(1)...o(26)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2)
        {
            return false;
        }

        vector<int> freq_s1(26, 0); 
        vector<int> freq_s2(26, 0);

        for (char c : s1)
        {
            freq_s1[c - 'a']++;
        }

        int l = 0;
        int r = 0;

        while (r < n2)
        {

            freq_s2[s2[r] - 'a']++;

            while (r - l + 1 > n1)
            {

                freq_s2[s2[l] - 'a']--;

                l++;
            }

            if (r - l + 1 == n1 && freq_s2 == freq_s1)
            {
                return true;
            }

            r++;
        }

        return false;
    }
};