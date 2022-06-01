#include <stdio.h>
#include <stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	int ch,e;
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	while(1)
	{
		printf("\n1.APPEND\n2.DISPLAY(F)\n3.DISPLAY(R)\n4.DELETE(HEAD)\n5.DELETE(TAIL)\n6.TRAVERSE\n7.EXIT\n");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Data: ");
				scanf("%d",&e);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=e;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=e;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			case 2:
			{
				pos=head;
				while (pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				}
				break;
			}
			case 3:
			{
				pos=tail;
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->prev;
				}
				break;
			}
			case 4:
			{
				struct node *temp=head;
				head=head->next;
				temp->next=NULL;
				head->prev=NULL;
				free(temp);
				break;
			}
			case 5:
			{
				struct node *temp=tail;
				tail=tail->prev;
				temp->prev=NULL;
				tail->next=NULL;
				free(temp);
				break;
			}
			case 6:
			{
				int num,flag=0,count=-1;
				printf("\nEnter Element to Search for: ");
				scanf("%d", &num);
				pos=head;
				while(pos!=NULL)
				{
					count++;
					if(pos->data==num)
					{
						printf("\nElement is present at position %d\n",count);
						flag=1;
					}
					pos=pos->next;
				}
				if(flag==0)
				{
					printf("\nElement not found\n");
				}
				break;
			}
			case 7:
			{
				printf("\nEXITING\n");
				exit(0);
			}
		}
	}
}
	

