#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,numOfAns=0,count=0;

typedef struct Queen{
	int x;
	int y;
} queen;
queen queens[16],answers[1000][16];

void init(){
	for(int i=0;i!=n;i++){
		queens[i].x=i;
		queens[i].y=n+1;
	}
}

bool checkRow(int index,int position){
	bool isRepeated=false;
	
	for(int i=index-1;i>=0;i--)
		if(queens[i].y==position){
			isRepeated=true;
			break;
		}
	return isRepeated;
}

void printAns(){
	for(int i=0;i!=numOfAns;i++){
		printf("第%d次\n",i+1);
		for(int j=0;j!=n;j++){
			for(int k=0;k!=n;k++){
				if(k==answers[i][j].y)
					printf("Q");
				else
					printf("X");
			}
			puts("");
		}
		puts("");
	}
}

void saveAns(){
	for(int i=0;i!=n;i++){
		answers[numOfAns][i].x=queens[i].x;
		answers[numOfAns][i].y=queens[i].y;
	}
	numOfAns++;
}

void checkAns(){
	bool isRight=true;
	count++;
	system("cls");
	printf("第%d次 已發現%d個答案\n",count,numOfAns);
	
	for(int i=0;i!=n && isRight;i++){
		for(int x=queens[i].x+1,y=queens[i].y+1;x!=n && y!=n; x++,y++)
		
			if(y==queens[x].y){
				isRight=false;
				break;
			}
	}
	for(int i=0;i!=n && isRight;i++){
		for(int x=queens[i].x-1,y=queens[i].y-1;x!=-1 && y!=-1; x--,y--)
		
			if(y==queens[x].y){
				isRight=false;
				break;
			}
	}
	for(int i=0;i!=n && isRight;i++){
		for(int x=queens[i].x+1,y=queens[i].y-1;x!=n && y!=-1; x++,y--)
		
			if(y==queens[x].y){
				isRight=false;
				break;
			}
	}
	for(int i=0;i!=n && isRight;i++){
		for(int x=queens[i].x-1,y=queens[i].y+1;x!=-1 && y!=n; x--,y++)
		
			if(y==queens[x].y){
				isRight=false;
				break;
			}
	}

	if(isRight)
		saveAns();
}

void getPosition(int index){
	int num=0;
	for(int i=0;num!=n-index;i++){
		if(!checkRow(index,i)){
			queens[index].y=i;
			if(index==n-1)
				checkAns();
			else
				getPosition(index+1);
			num++;
		}
	}
}

void main(){
	scanf("%d",&n);
	init();
	getPosition(0);
	printAns();
	system("pause");
} 
