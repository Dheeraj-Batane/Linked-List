#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *next;	
};
struct Node *start=NULL;	
void insertAtE(int );
void insertAtB(int );
void deleteAtB();
void deleteAtE();
void showAll();
void insertAfter(int);
void insertBefore(int);
void deleteBefore(int);
void deleteAfter(int);
void main()
{
	int ch,x;
	do{
	printf("1.Display Linked List\n");
	printf("2.Insert At Ending\n");
	printf("3.Insert At Beginning\n");
	printf("4.Delete At Beginning\n");
	printf("5.Delete At Ending\n");
	printf("6.Insert After Search\n");
	printf("7.Insert Before Search\n");
	printf("8.Delete Before Search\n");
	printf("9.Delete After Search\n");
	printf("10.Exit\n");
	printf("Enter your choice =");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		showAll();
		break;
		case 2:
		printf("\nEnter data to insert-->");
		scanf("%d",&x);
		insertAtE(x);
		break;
		case 3:
		printf("\nEnter data to insert-->");
		scanf("%d",&x);
		insertAtB(x);
		break;
		case 4:
		deleteAtB();
		break;
		case 5:
		deleteAtE();
		break;
		case 6:
		printf("Enter data to search--");
		scanf("%d",&x);
		insertAfter(x);
		break;
		case 7:
		printf("Enter data to search--");
		scanf("%d",&x);
		insertBefore(x);
		break;
		case 8:
		printf("Enter data to search--");
		scanf("%d",&x);
		deleteBefore(x);
		break;
		case 9:
		printf("Enter data to search--");
		scanf("%d",&x);
		deleteAfter(x);
		break;
		
		
	}
	}while(ch<10);
	
}
void  insertAtE(int x)
{
	struct Node *temp=malloc(sizeof(struct Node));
	if(start==NULL)
	{
		temp->info=x;
		temp->next=NULL;
		start=temp;
		printf("First Node Inserted\n");
		return;
	}
	struct Node *temp1=start;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp->info=x;
	temp->next=NULL;
	temp1->next=temp;
	printf("Node Inserted at Ending\n");
}
void insertAtB(int x)
{
	struct Node *temp=malloc(sizeof(struct Node));
	if(start==NULL)
	{
		insertAtE(x);
		return;
	}
	temp->info=x;
	temp->next=start;
	start=temp;
	printf("Node inserted at Beginning\n");
}
void deleteAtB()
{
	if(start==NULL)
	{
		printf("Deletion Not Possible\n");
		return;
	}
	struct Node *temp=start;
	start=temp->next;
	free(temp);
	printf("1st Node deleted Successfully\n");
	
}
void deleteAtE()
{
	if(start==NULL)
	{
		printf("Deletion Not Possible\n");
		return;
	}
	struct Node *prev=start;
	struct Node *temp=start;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
	printf("Last Node Deleted Successfully\n");
}
void insertAfter(int x)
{
	struct Node *temp=start;
	while(temp->info!=x)
	{
		if(temp==NULL)break;
		temp=temp->next;
	}
	int y;
	printf("Enter value to insert after %d\n",x);
	scanf("%d",&y);
	struct Node *temp1=malloc(sizeof(struct Node));
	temp1->info=y;
	temp1->next=temp->next;
	temp->next=temp1;
	printf("Node inserted\n");	
}
void insertBefore(int x)
{
	struct Node *temp=start;
	struct Node *prev=start;	
	while(temp->info!=x)
	{
		if(temp==NULL)break;
		prev=temp;
		temp=temp->next;
	}
	int y;
	printf("Enter value to insert before %d\n",x);
	scanf("%d",&y);
	struct Node *temp1=malloc(sizeof(struct Node));
	temp1->info=y;
	temp1->next=temp;
	prev->next=temp1;
	printf("Node Inserted\n");
}
void deleteBefore(int x)
{
	if(start==NULL)
	{
		printf("Deletion Not Possible\n");
		return;
	}
	struct Node *temp=start;
	struct Node *prev1=start;
	struct Node *prev2=start;	
	while(temp->info!=x)
	{
		if(temp==NULL)break;
		prev1=prev2;
		prev2=temp;
		temp=temp->next;
	}
	if(prev1==start && prev2==start)
	{
		deleteAtB();
		return;
	}
	prev1->next=temp;
	prev2->next=NULL;
	free(prev2);
	printf("Node deleted Successfully\n");
}
void deleteAfter(int x)
{
	if(start==NULL)
	{
		printf("Deletion Not Possible\n");
		return;
	}
	struct Node *temp=start;
	while(temp->info!=x)
	{
		if(temp==NULL)break;
		temp=temp->next;
	}
	struct Node *temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	printf("Node deleted Successfully\n");
}
void showAll()
{
	struct Node *temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}
	printf("\n");
}
