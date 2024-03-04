class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int score=0;
        int j=tokens.size()-1;
        if(tokens.size()==0){
            return 0;
        }
        if(tokens.size()==1){
            if(power>=tokens[0]){
                return 1;
            }
        }
        while(i<j){
        if(power<tokens[i]&& score<1){
                break;
         }
          if(tokens[i]<=power){
              power=power-tokens[i];
              i++;
              score++;
        }else if(tokens[i]>power && score>=1){
            power=power+tokens[j];
            score--;
            j--;
        }
    }
    if(i==j){
        if(power-tokens[j]>=0){
            score++;
        }
    }
    
    return score;
    }
};