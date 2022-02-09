int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    VI crane(N);
    cin >> crane;
    sort(ALL(crane));
    int M;
    cin >> M;
    VI box(M);
    cin >> box;
    sort(ALL(box));
    VI startidx(N, M-1);
    vector<bool> travel(M);
    int boxcnt = 0;
    int clockcnt = 0;
    while(!(boxcnt==M || clockcnt==M)){
        clockcnt++;
        for(int i=N-1; i>=0; i--){
            for(int j=startidx[i]; j>=0; j--){
                if((!travel[j]) && box[j]<=crane[i]){
                    travel[j] = true;
                    boxcnt++;
                    startidx[i] = j-1;
                    break;
                }
                if(j==0) startidx[i] = -1;
            }
        }
    }
    //cout << boxcnt << endl << clockcnt << endl << travel <<endl << startidx << endl;
    if(boxcnt!=M) cout << -1;
    else cout << clockcnt;

}
