#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	cout << "카드 모양은 고려하지않으나 중복카드는 4장까지 존재" << endl;


	int Card[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
	string CardShape[13] = {"1","2","3","4","5","6","7","8","9","10","j","Q","K"};
	int Player[3] = { 0, };
	int Computer[3] = { 0, };
	int TotalPlayer = 0;
	int TotalComputer = 0;
	int Result = 0;
	int CardIndex = 0;
	int Deck[52];

	for (int i = 0; i < 52; i++) 
	{
		Deck[i] = i % 13; 
	}

	srand(time(0));

	for (int i = 0; i < 52; i++) 
	{
		int dest = rand() % 52;
		swap(Deck[i], Deck[dest]); 
	}



	cout << "플레이어 카드" << endl;
	for (int i = 0; i < 3; i++)
	{
		int cardIdx = Deck[CardIndex++];
		cout << CardShape[cardIdx] << endl;
		Player[i] = Card[cardIdx];
	}
	cout << "상대 카드" << endl;
	for (int i = 0; i < 3; i++)
	{
		int cardIdx = Deck[CardIndex++]; 
		cout << CardShape[cardIdx] << endl;
		Computer[i] = Card[cardIdx];
	}

	cout << "플레이어 카드합" << endl;

	for (int i = 0; i < 3; i++)
	{
		TotalPlayer = TotalPlayer + Player[i];
	}

	cout << TotalPlayer << endl;

	cout << "상대 카드합" << endl;

	for (int i = 0; i < 3; i++)
	{
		TotalComputer = TotalComputer + Computer[i];
	}

	cout << TotalComputer << endl;


	
	if (TotalComputer==TotalPlayer)//일반적인 결과값
	{
		cout << "두 플레이어의 카드합이 같습니다." << endl;
		Result = 2;
	}
	else if (TotalPlayer > TotalComputer)
	{
		cout << "플레이어의 카드합이 더 큽니다." << endl;
		Result = 0;
	}
	else 
	{
		cout << "상대의 카드합이 더 큽니다." << endl;
		Result = 1;
	}


	//21이 넘었을 경우
	if (TotalComputer > 21 && TotalPlayer > 21)
	{
		cout << "그러나 두 플레이어 모두 카드합이 21을 넘었습니다." << endl;
		Result = 2;
	}
	else if (TotalPlayer > 21)
	{
		cout << "그러나 플레이어 카드합이 21을 넘었습니다." << endl;
		Result = 1;
	}
	else if (TotalComputer > 21)
	{
		cout << "그러나 상대 카드합이 21을 넘었습니다." << endl;
		Result = 0;
	}

	//결과 출력

	if (Result==0)
	{
		cout << "플레이어가 이겼습니다." << endl;
	}
	else if (Result == 1)
	{
		cout << "상대가 이겼습니다." << endl;
	}
	else
	{
		cout << "무승부입니다." << endl;
	}

}