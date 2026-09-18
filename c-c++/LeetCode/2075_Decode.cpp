// Online C++ compiler to run C++ program online
#include <iostream>
#include<string>
#include<vector>

using namespace std;

    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = (n%rows == 0) ? n/rows : n/rows + 1;

        vector<vector<char>> grid(rows,vector<char>(cols,'$'));
        int k = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j] = encodedText[k++];
            }
        }

        string ans = "";

        for(int i=0;i<cols;i++){
            int r = 0;
            int c = i;
            while(r<rows && c<cols){
                ans.push_back(grid[r][c]);
                r++;
                c++;
            }
        }
        string finalAns = "";
        bool status = true;
        for(int i=ans.size()-1;i>=0;i--){
            if(status && ans[i]==' '){
                continue;
            }
            else{
                status = false;
                finalAns = ans[i] + finalAns;
            }
        }

        return finalAns;

    }


int main() {
    string encodedText = "tdrrwtuyftoitgzck f nab licvkaqucg siapzkhridlinldremeazyclnavatoxhxgfeueswxsrzalwitgle";
    int rows = 3;

    cout<<decodeCiphertext(encodedText,rows);

    return 0;
}