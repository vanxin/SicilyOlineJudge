#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int caseNum;
    cin>>caseNum;
    int i = 1; 
    while(i <= caseNum)
    {
        int playerNum;
        cin>>playerNum;
        queue<int>* players = new queue<int>[playerNum];
        int* count = new int[playerNum];
        //初始化计数器 
        for(int player = 0; player < playerNum; player++)
        {
            count[player] = 0;
        }
        int* lastCard = new int[playerNum];
        for(int cardNum = 0; cardNum < 52; cardNum++)
        {
            int card;
            cin>>card;
            players[0].push(card);
        }
        //开始计数
        int times = 0;
        int discard = 0;
        while(times <= 10000)
        {
            for(int player = 0; player < playerNum; player++)
            {
                if(players[player].empty())
                    continue;
                count[player]++;
                if(count[player] == 14)
                    count[player] = 1;
                int tempCard = players[player].front();
                players[player].pop();
                if(players[player].empty())
                    lastCard[player] = tempCard;
                if(tempCard == count[player])
                {
                    if(player + 1 == playerNum)
                    {
                        discard++;
                    }
                    else
                    {
                        players[player+1].push(tempCard);
                    }
                }
                else
                {
                    players[player].push(tempCard);
                }
            }
            if(discard == 52)
                break;
            times++;
        }
        cout<<"Case "<<i<<": ";
        if(discard == 52)
        {   
            for(int player = 0; player < playerNum-1; player++)
            {
                cout<<lastCard[player]<<" ";
            }
            cout<<lastCard[playerNum-1]<<endl;
        }
        else
        {
            cout<<"unwinnable"<<endl;
        }
        discard = 0;
        i++;
    }
    return 0;
} 
