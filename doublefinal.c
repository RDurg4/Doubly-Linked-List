#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL,*temp=NULL;

	int ch,e,c=0,find,i;
	while(1)
	{
		printf("\n1:INSERT(FRONT)\n2:INSERT(END)\n3:DELETE(HEAD)\n4:DELETE(TAIL)\n5:DISPLAY(F)\n6.DISPLAY(B)\n7:EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 2:
			{
				printf("Enter data: ");
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
					temp=(struct node*)malloc(sizeof(struct node));
					temp->prev=NULL;
					temp->data=e;
					temp->next=head;
					head=temp;
					head->next->prev=head;
				}
				break;
			}


			case 1:
			{
				printf("Enter data: ");
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

			case 3:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}

				if(head->next==NULL)
				{
					head=NULL;
					break;
				}

				struct node *del=head;
				head=head->next;
				del->next=NULL;
				head->prev=NULL;
				free(del);
				break;
			}
			case 4:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}

				if(head->next==NULL)
				{
					head=NULL;
					break;
				}

				struct node *del=tail;
				tail=tail->prev;
				del->prev=NULL;
				tail->next=NULL;
				free(del);
				break;
			}

			case 5:
			{
				pos=head;
				if(pos==NULL)
				{
					printf("No Elements");
				}
				else
				{
					printf("\nElements are: ");
					while(pos!=NULL)
					{
						printf("%d ",pos->data);
						pos=pos->next;
					}
				}
				printf("\n");
				break;
			}

			case 6:
			{
				pos=tail;
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("%d ",pos->data);
					pos=pos->prev;
				}
				printf("\n");
				break;
			}

			case 7:
			{
				printf("EXITING\n");
				exit(0);
			}

		
		}
	}
}


