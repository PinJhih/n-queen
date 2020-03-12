#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,count=0;

typedef struct Queen{
	int x;
	int y;
} queen;
queen queens[100];

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
	count++;
	printf("²Ä%d­Ó\n",count);
	for(int i=0;i!=n;i++){
		for(int j=0;j!=n;j++)
			if(j==queens[i].y)
				printf("Q");
			else
				printf("X");
		puts("");
	}
}

void checkAns(){
	bool isRight=true;
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
		printAns();
}

void getPosition(int index){
	for(int i=0;i!=n;i++){
		if(!checkRow(index,i)){
			queens[index].y=i;
			if(index==n-1)
				checkAns();
			else
				getPosition(index+1);
		}
	}
}


void main(){
	scanf("%d",&n);
	init();
	getPosition(0);
	system("pause");
} 
