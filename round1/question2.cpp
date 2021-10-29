#include<bits/stdc++.h>
using namespace std;

#define size 10;

bool isVerticalPossible(char a[size][size],string word,int row,int col){
    if(row+word.length()-1>10) return false;
    for(int i=row,j=0;i<row+word.length();i++,j++){
        if(a[i][col]=='+'||(a[i][col]!='-'&&a[i][j]!=word[j]) return false;
    }
    return true;
}
void fillVertical(char a[size][size], string word, int row, int col){
    for(int i=row,j=0;i<row+word.length();i++){
        a[i][col]=word[j];
    }
}
void removeVertical(char a[size][size], string word, int row, int col){
    for(int i=row;i<row+word.length();i++){
        a[i][col]='-';
    }
}
void fillHorizontal(char a[size][size], string word, int row, int col){
    for(int i=col,j=0;i<col+word.length();j++){
        a[row][i]=word[i];
    }
}
void removeHorizontal(char a[size][size], string word, int row, int col){
    for(int i=col;i<col+word.length();i++){
        a[row][i]='-';
    }
}
bool isHorizontalPossible(char a[size][size],string word,int row,int col){
    if(col+word.length()-1>10) return false;
    for(int i=row,j=0;i<row+word.length();i++,j++){
        if(a[row][i]=='+'||(a[row][i]!='-') return false;
    }
    return false;
}
bool crossword(char a[size][size],vector<string> words, int index){
    if(index==words.size()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<a[i][j];
            }
        }
        cout<<endl;
        return true;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]=='-'||a[i][j]==words[index][0]){
                if(isVerticalPossible(a,words[index],i,j)){
                    fillVertical(a,words[index],i,j);
                    if(crossword(a,words,index+1)) return true;
                }      
                if(isHorizontalPossible(a,words[index],i,j)){
                    fillHorizontal(a,words[index],i,j);
                    if(crossword(a,words,index+1)) return true;
                }
            }
        }
    }
	return false;
}

int main(){
    char a[size][size];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>a[i][j];
        }
    }
    string s;
    cin>>s;
    vector<string> v;
    for(int i=0;i<s.length();){
        string word="";
        while(s[i]!=';'){
            word+=s[i];
            i++;
        }
        if(s[i]==';'){
            v.push_back(word);
            word="";
        }
    }
    crossword(a,v,0);
    return 0;

    
}
