class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>vc(26,0);
        for(int i=0;i<sentence.size();i++){
            vc[sentence[i]-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(vc[i]==0){
                return 0;
            }
        }
        return 1;
    }
};