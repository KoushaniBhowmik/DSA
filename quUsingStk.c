//Implement a Queue using stack

#include<stdio.h>
#include<stdlib.h>

#define size 100

int top1=-1,top2=-1,max;
int stk1[size],stk2[size];

void push(){
	if(top2==max-1){
		printf("overflow condition\n");
	}
	else{
		top1++;
		printf("Enter the element to be inserted:");
		scanf("%d",&stk1[top1]);
	}
}
void pop(){
    int ans=-1;
	if(top2==-1){
		if(top1==-1){
			printf("Queue is Empty!!\n");
			return;
		}
		else{
			while(top1>=0){
				int x=stk1[top1];
				top1--,top2++;
				stk2[top2]=x;
			}
			ans=stk2[top2];
			top2--;
		}
	}
	else{
		ans=stk2[top2];
		top2--;
	}
	printf("The pop element is: %d\n",ans);
}
void display(){
	if(top2==-1 && top1==-1){
		printf("Queue is Empty!!\n");
	}
	if(top2!=-1){
		for(int i=top2;i>=0;i--){
			printf("%d\t",stk2[i]);
		}
	}
	if(top1!=-1){
		for(int i=0;i<=top1;i++){
			printf("%d\t",stk1[i]);
		}
	}
}
void peek(){
	int res=-1;
	if(top2==-1){
		if(top1==-1){
			printf("Queue is Empty!!");
			return;
		}
		else{
			while(top1>=0){
				int y=stk1[top1];
				top1--,top2++;
				stk2[top2]=y;
			}
			res=stk2[top2];
		}
	}
	else{
		res=stk2[top2];
	}
	printf("The top element is: %d",res);
}
void sizeQu(){
	if(top2==-1 && top1==-1){
		printf("Queue is Empty!!\n");
	}
	else{
		int totalSize=(top1+1)+(top2+1);
	    printf("The size of the queue is: %d\n",totalSize);
	}
}

int main(){
	int choice;
 	printf("Enter the max element:");
    scanf("%d",&max);
 	while(1){
 	    printf("\n\nEnter 1.push, 2.pop, 3.display, 4.peek, 5.sizeOfQueue, 6.exit\n");
 	    printf("Enter your choice:");
 	    scanf("%d",&choice);
 	    switch(choice){
 		    case 1: push();
 		    break;
 		    case 2: pop();
 		    break;
 		    case 3 : display();
 		    break;
 		    case 4: peek();
		    break;
		    case 5: sizeQu();
		    break;
		    case 6: exit(0);
		    break;
 		    default: printf("wrong choice\n");
        }
    }
}