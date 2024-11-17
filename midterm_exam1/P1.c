#include <stdio.h>
int countArriveTime(int hh, int mm, int time){
    int ans;
    ans = hh * 60 + mm + time;
    return ans;
}
int main(){
    int current_h, current_m;
    scanf("%d:%d", &current_h, &current_m);
    int n;
    scanf("%d", &n);
    int a[30][5];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d:%d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        a[i][4] = countArriveTime(a[i][1], a[i][2], a[i][3]);
    }
    int ans = 0, quickest = 1800;
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d %d %d\n",a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
        if (a[i][1] >= current_h && a[i][2] >= current_m){
            if (quickest > a[i][4]){
                ans = a[i][0];
                quickest = a[i][4];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d:%d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
    }
    printf("%d", ans);
}