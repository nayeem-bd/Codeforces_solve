
int lps[1000005];

void lps_cal(string pattern)
{
    lps[0]=0;
    int i,j;
    j=0;
    for(i=1;i<pattern.size();i++){
        if(pattern[j]==pattern[i]){
            lps[i]=j+1;
            j++;
        }
        else{
            while(j!=0){
                j = lps[j-1];
                if(pattern[j]==pattern[i]){
                    lps[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }
}

int kmp(string text,string pattern)
{
    ms(lps,0);
    lps_cal(pattern);
    int i,j,cnt=0;
    j=0;
    for(i=0;i<text.size();i++){
        if(text[i]==pattern[j]){
            j++;
        }
        else{
            while(j!=0){
                j=lps[j-1];
                if(pattern[j]==text[i]){
                    j++;
                    break;
                }
            }
        }
        if(j==pattern.size()){
            cnt++;
            j=lps[j-1];
           // j++;
        }
    }
    return cnt;
}
