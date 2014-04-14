#include "GameMap.h"


GameMap::GameMap()
{
		tab=new int*[10];
		for(int i=0; i<10; i++)
		{
			tab[i]=new int[26];
		}

		for(int i=0; i<10; i++)
		{
			for(int j=0; j<26; j++)
			{
				tab[i][j]=0;
			}
		}
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<26; j++)
			{
				std::cout<<tab[i][j];
			}
		}
}

void GameMap :: Clear()
{
	for(int i=0; i<10; i++)
		{
			for(int j=0; j<26; j++)
			{
				tab[i][j]=0;
			}
		}
}

void GameMap::AddBlocks(int x1, int y1, int special, int blocktype, int tribe)
{
	if(tribe==1)
		tab[((x1-90)/20)][((y1-140)/20)+5]=1;
	else
		if(special==4)
			tab[((x1-90)/20)][((y1-140)/20)+5]=1;
		else if(blocktype<=20)
		{
			tab[((x1-90)/20)][((y1-140)/20)+5]=2;
		}
		else if(blocktype>20)
		{
			tab[((x1-90)/20)][((y1-140)/20)+5]=11;
		}
}

void GameMap::CheckLine(int& points, bool nowyklocek, int tribe)
{
	int count=0, line[4], l, cc=0;
	for(int i=0; i<4; i++)
	{
		line[i]=0;
	}

	for(int i=0; i<26; i++)
	{
		bool frozenline=false;
		bool clearlines=false;
		for(int j=0; j<10; j++)
		{
			if(tab[j][i]>0 && tab[j][i]<2)
				count+=1;
			else if(tab[j][i]>3)
			{
				frozenline=true;
				if(nowyklocek==true)
				{
					tab[j][i]-=1;
					std::cout<<tab[j][i];
				}
				
			}
			l=i;
		}
		
			for(int j=0; j<10; j++)
			{
				if(frozenline!=true && tab[j][i]==2)
				{
					if(count>5)
						clearlines=true;
					count=10;
					for(int i=0; i<26; i++)
						tab[j][i]=0;
				}	
			}

			if(count==10)
			{
				if(clearlines==true)
					points+=300;
				else
					points+=100;
				line[cc]=l;
				count=0;
				cc+=1;
			}
			else if(frozenline=true)
				count=0;
			else 
			{
				count=0;
			}
	}
	
	for(int k=0; k<4; k++)
	{
		if(line[k]>0)
		{
			for(int i=0; i<10; i++)
			{
				for(int j=line[k]; j>0; j--)
				{
					tab[i][j]=tab[i][j-1];
				}
			}
		}
	}

}

void GameMap::CheckGravity()
{
	bool againcheck=false;
	do{
	againcheck=false;
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i+1<27)
				if(tab[j][i]!=0 && tab[j][i+1]==0)
				{
					tab[j][i+1]=tab[j][i];
					tab[j][i]=0;
					againcheck=true;
				}
		}
		
	}
	}while(againcheck==true);
}


