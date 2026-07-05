class Solution {
public:
    int n;
    const int MOD=1e9+7;
    // vector<vector<pair<int,int>>> t(n,vector<pair<int,int>>(n,{-1,-1}));

    bool isValid(int i,int j,vector<string>&board,vector<vector<pair<int,int>>>& t){
        if(i>=0 && i<n && j>=0 && j<n && board[i][j]!='X') return true;
        return false;
    }

    int getIntFromChar(char ch){
        return ch!='S'?ch-'0':0;
    }
    pair<int,int>solve(int i,int j,vector<string>& board,vector<vector<pair<int,int>>> &t){
        if(board[i][j]=='E') return {0,1};
        if(board[i][j]=='X') return {0,0};

        if(t[i][j]!=make_pair(-1,-1)) return t[i][j];

        int upScore=0,upPaths=0;
        int leftScore=0,leftPaths=0;
        int diagScore=0,diagPaths=0;

        char ch=board[i][j];

        if(isValid(i-1,j,board,t)){//up
            auto[score,path]=solve(i-1,j,board,t);

            upScore+=score;
            upPaths=path;

            if(upPaths>0){
                upScore+=getIntFromChar(ch);
            }
        }

        if(isValid(i,j-1,board,t)){//left
            auto[score,path]=solve(i,j-1,board,t);


            leftScore+=score;
            leftPaths=path;

            if(leftPaths>0){
                leftScore+=getIntFromChar(ch);
            }
        }

        if(isValid(i-1,j-1,board,t)){//diagonal
            auto[score,path]=solve(i-1,j-1,board,t);

            diagScore+=score;
            diagPaths=path;

            if(diagPaths>0){
                diagScore+=getIntFromChar(ch);
            }
        }

        int bestScore,bestPaths;
        if (upScore == leftScore && leftScore == diagScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } else if (upScore == leftScore) {
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } else if (leftScore == diagScore) {
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } else {
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        t[i][j] = {bestScore, bestPaths % MOD};
        return t[i][j];


    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        //t.assign(n, vector<pair<int, int>>(n, {-1, -1}));
        vector<vector<pair<int,int>>> t(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int>res=solve(n-1,n-1,board,t);

        return {res.first,res.second};
    }
};