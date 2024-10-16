//brute force..khud..


//o(n^2)..
//o(n)..

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            int product=1;
            for(int j=0;j<n;j++){

                if(i!=j){

                    product *= nums[j];
                }
            }

            ans.push_back(product);

        }

        return ans;
        
    }
};

//optimal
//PREFIIX..SUFFIX...


//5,3,4,9  ..ANS= [78,180,135,60]...

//PREFIX..[5,15,60,540]
//SUFFIX..[540,108,36,9]...


//FOR 5...ANS=3 ka suffix obvio..=108..
//for 3..prefix of 5* suffix of 4..= 5*36=180
//for 4...prefix of 3 , suffix of 9... 15*9=135..
//for 9..pefix of 4* 1=4(lastelemnt)(ase hi shuru wle me tha)..

//HAR ELEMENT PE USSE PEECHE WLE KA PREFIX * USKE AAGE WALA KA SUFFIX...


//o(n)..
//o(n)...



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


       int n=nums.size();

       vector<int>prefix(n,1);
       vector<int>suffix(n,1);

       prefix[0]=nums[0];
       suffix[n-1]=nums[n-1];


    //fill prefix..

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] * nums[i];
    }

    //fill suffix..

    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] * nums[i];
    }

    //ab result..
    //phle or last element ka result to phle septa...phleka=suffix of 1..aur last ka..suffix[n-2]..

    vector<int>result(n);

    result[0]= suffix[1];
    result[n-1]=prefix[n-2];

    for(int i=1;i<=n-2;i++){

        result[i] = prefix[i-1] * suffix[i+1];
    }

    return result;

        
    }
};

