
#include <stdio.h>
#include <string.h>
#include <string.h>

int dp[10][3];//dp[i][j]��i�������ֵ�λ����j����״��
//dp[i][0],��ʾ�����ڲ���������
//dp[i][1],��ʾ�����ڲ��������֣������λΪ2
//dp[i][2],��ʾ���ڲ���������
void Init()
{
    memset(dp,0,sizeof(dp));
    int i;
    dp[0][0] = 1;
    for(i = 1; i<=6; i++)//�����Ϊ6
    {
        dp[i][0] = dp[i-1][0]*9-dp[i-1][1];//���λ���ϲ���4��9�����ֵ�״��������Ϊ���6������Ҫ��ȥǰһ�ֿ�ͷΪ2�����
        dp[i][1] = dp[i-1][0];//��ͷֻ����2
        dp[i][2] = dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];//�Ѿ����е�ǰ���ʲô�������ԣ������Ƿ�һ��4����������2ǰ���6
    }
}

int solve(int n)
{
    int i,len = 0,tem = n,ans,flag,a[10];
    while(n)//��ÿһλ��ַ�������
    {
        a[++len] = n%10;
        n/=10;
    }
    a[len+1] = ans = 0;
    flag = 0;
    for(i=len; i>=1; i--)
    {
        ans+=dp[i-1][2]*a[i];
        if(flag)//����Ѿ��ǲ������ˣ����⴦��
            ans+=dp[i-1][0]*a[i];
        if(!flag && a[i]>4)//��λ����4�������з�4�����
            ans+=dp[i-1][0];
        if(!flag && a[i+1]==6 && a[i]>2)//��һλΪ6����λ����2
            ans+=dp[i][1];
        if(!flag && a[i]>6)//��λ����6�����ܵ�62״��
            ans+=dp[i-1][1];
        if(a[i]==4 || (a[i+1]==6&&a[i]==2))//���Ϊ������
            flag = 1;
    }
    return tem-ans;
}

int main()
{
    int l,r;
    Init();
    while(~scanf("%d%d",&l,&r),l+r)
    {
		printf("%d ~ %d = ", l, r);

        printf("%d\n",solve(r+1)-solve(l));
        //��Ϊsolve�����в�û�п���n�ǲ��ǲ����������������r+1ֻ����1~r����lֻ����1~l-1,���������������ȷ��
    }

    return 0;
}
