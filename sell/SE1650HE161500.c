#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
typedef struct product {
	char id[7];
	char name[100];
	int  price;
	int quantity;
} pro ;
int n=0;
pro a[100];
typedef struct order {
	char orderId[15];
	char cName[50];
	char cPhone[12];
	char shipAdd[200];
	int oState;
	int total;
	int discount;
	pro PRO[100];
} order ;
int m=0;
order b[100];
char function_choice() {
	char choice;
	system("cls");
	printf("Order Management System\n");
	printf("=======================\n");
	printf("\na) Add new product\n");
	printf("\nb) Update a product\n");
	printf("\nc) Delete a product\n");
	printf("\nd) Print a product\n");
	printf("\ne) List all products in alphabetical order from 'A' to 'Z'\n ");
	printf("\nf) Sort and display all products in ascending order of price \n");
	printf("\ng) Save infor product \n");
	printf("\nh) Read infor product \n");
	printf("\ni) Add new order\n ");
	printf("\nk) Show the detail of an order given its Id\n");
	printf("\nl) Save infor order \n ");
	printf("\nm) Read infor order \n");
	printf("\nn) List all orders in a given month \n");
	printf("\no) Calculate number of products sold in month, group by each product \n");
	printf("\np) Find top 5 best-selling products in a specific period \n ");
	printf("\nq) Quit\n");
	printf("\n---\n");
	printf("Enter a letter (a, b, ..) to select the corresponding function: ");
	fflush(stdin);
	choice = getchar();
	system("cls");

	return choice;
}
void  add(int *n) {
	do {
		printf("\n enter n item: ");
		scanf("%d", n);
	} while(n <= 0);
}
void addPro(pro *pro1) {
	int flag=1;
	printf("\nEnter id product\n");
	while(flag!=0) {
		scanf("%s", &pro1 ->id);
		getchar();
		int i;
		for(i=0; i<3; i++) {
			if(pro1 ->id[i]<'A'||pro1 ->id[i]>'Z'||strlen(pro1 ->id)!=6) {
				flag=1;
				printf("Try again!\n");
				break;
			} else flag=0;

		}
		int h;
		for(h=3;h<7;h++){
			if(pro1->id[i]<'0'||pro1->id[i]>'9'){
			flag=1;
			printf("Try again!!");
			break;
			}else {
			flag=0;
		}
		}
	}
	printf("enter name product\n");
	int flag2=1;

	while(flag2!=0) {
		scanf("%s", &pro1 ->name);
		getchar();
		int i;
		for(i=0; i<strlen(pro1->name); i++) {
			if(pro1->name[i]<'A'||pro1 ->name[i]>'z' ) {
				flag2=1;
				printf("Try again!\n");
				break;
			} else flag2=0;
		}

	}

	printf("enter price product\n");
	scanf("%d",&pro1 ->price);
	getchar();
}
void addOrder (order *order1 ) {
	int flag=1;
	printf("\nEnter id order\n");
	while(flag!=0) {
		scanf("%s", &order1->orderId);
		getchar();
		int i;
		for(i=0; i<14; i++) {
			if(order1 ->orderId[i]>'9'||order1 ->orderId[i]<'0'||strlen(order1->orderId)!=14) {
				flag=1;
				printf("Try again!\n");
				break;
			} else {
				flag=0;
			}
		}
	}

	printf("enter customer name  \n");
	int flag2=1;
	while(flag2!=0) {
		scanf("%s", &order1 ->cName);

		getchar();
		int i;
		for(i=0; i<strlen(order1 ->cName); i++) {
			if(order1 ->cName [i]<'A'||order1 ->cName [i]>'z' ) {
				flag2=1;
				printf("Try again!\n");
				break;
			} else flag2=0;
		}

	}
	printf("enter customer phone\n");

	int flag3=1;
	do {
		scanf("%s",&order1->cPhone);

		int i;
		for(i=0; i<strlen(order1->cPhone); i++) {
			if(!isdigit(order1->cPhone[i])) {
				flag3=1;
			} else {
				flag=0;
			}
		}
	} while(strlen(order1->cPhone)!=10&&strlen(order1->cPhone)!=11||flag!=0);
	printf("enter shipping  ADD\n");
	scanf("%s", &order1 ->shipAdd);

	getchar();
	printf("enter order state\n");
	do {
		scanf("%d", &order1->oState);
	} while(order1->oState!=0&&order1->oState!=1);
	getchar();
	printf("enter discount order \n");
	scanf("%d", &order1 ->discount);
//	tinh tien
	printf("enter n product \n");
	int i=0;
	scanf("%d",&order1->PRO[i].quantity);

	printf("enter id product \n");

	scanf("%s",&order1->PRO[i].id );


	i++;
	getchar();
	int j;
	for(j=0; j<n; j++) {
		if(strcmp(order1->PRO[j].id,a[j].id)==0) {
			order1->total=( a[j].price*order1->PRO[j].quantity)-order1->discount;
		}
	}
}
void add_order(order o[], int m) {
	printf("Add a new order:\n");
	printf("==================\n\n");
	printf("\n____________________________________\n");
	int i;
	for( i= 0; i<m; ++i) {
		printf("  enter   order  %d:", i+1);
		addOrder(&o[i]);
	}
	printf("\n____________________________________\n");

}
void printOrder(order Order) {
	printf("\n idOrder:		    %20s\n", Order.orderId );
	printf("\n name customer:\t           %20s\n", Order.cName );
	printf("\n cPhone :	  	    %20s\n", Order.cPhone);
	printf("\n shipAdd:		    %20s\n", Order.shipAdd );
	printf("\n oState: 		    %20d\n", Order.oState);
	printf("\n discount :	            %20d\n", Order.discount);
	printf("\n total : 		    %20d\n", Order.total );
}
void printNorder(order o[], int m) {
	printf("\n____________________________________\n");
	int i;
	for( i= 0; i < m; ++i) {
		printf("\n infor of order  %d:", i+1);
		printOrder(o[i]);
	}
	printf("\n____________________________________\n");
}
void add_product(pro a[], int n ) {
	printf("Add a new product:\n");
	printf("==================\n\n");
	printf("\n____________________________________\n");
	int i;
	for( i= 0; i<n; ++i) {
		printf("  enter   product %d:", i+1);
		addPro(&a[i]);
	}
	printf("\n____________________________________\n");


}
void update_product(pro a[], int n) {
	printf("Update a product:\n");
	printf("=================\n\n");
	char upid[7];
	printf("   enter id  product to update:" );
	scanf("%s",&upid);

	int i;
	for( i= 0; i<n; ++i) {
		if(strcmp(upid, a[i].id)==0) {
			printf("  update price:" );
			int pr;
			scanf("%d",&pr);
			a[i].price=pr;
			break;
		}
	}
}
void delete_product(pro a[], int *n) {
	printf("Delete a product:\n");
	printf("=================\n\n");
	char upid[7];
	printf("   enter id  product to delete:" );
	scanf("%s",&upid);

	int i;
	for(i = 0; i<*n; ++i) {
		if(strcmp(upid, a[i].id)==0) {
			int j;
			for(j=i; j<*n; j++) {
				strcpy(a[j].id ,  a[j+1].id );
				strcpy(a[j].name ,  a[j+1].name );
				a[j].price=a[j+1].price;

			}

			(*n)--;
			break;
		}

	}
}
void print(pro Pro) {
	printf("\n id:   % 20s\n", Pro.id );
	printf("\n name: % 20s\n", Pro.name );
	printf("\n price:% 20d\n", Pro.price);

}
void printN(pro a[], int n) {
	printf("\n____________________________________\n");
	int i;
	for( i= 0; i < n; ++i) {
		printf("\n infor product  %d:", i+1);
		print(a[i]);
	}
	printf("\n____________________________________\n");
}
void sortProName(pro a[], int n) {
	printf("\n____________________________________\n");
	printf("  List all products in alphabetical order from 'A' to 'Z'\n ");
	pro tmp;
	char a1[100];
	char a2[100];
	int i;
	for(i = 0; i < n-1; i++) {
		strcpy(a1, a[i].name);
		int j;
		for( j= i+1; j < n; j++) {
			strcpy(a2, a[j].name);
			if( strcmp(a1,a2) > 0) {

				strcpy( tmp.name , a[i].name);
				strcpy(  tmp.id  , a[i].id );
				tmp.price=a[i].price;

				strcpy(  a[i].name, a[j].name);
				strcpy(   a[i].id , a[j].id);
				a[i].price=a[j].price;

				strcpy( a[j].name, tmp.name  );
				strcpy(  a[j].id,tmp.id    );
				a[j].price= tmp.price;

			}
		}
	}

	printf("\n____________________________________\n");
}
void sortProPrice(pro a[],int  n) {
	printf("\n____________________________________\n");
	printf("  Sort and display all products in ascending order of price  ");
	pro tmp;
	int i;
	for( i= 0; i < n-1; i++) {
		int j;
		for( j= i+1; j < n; j++) {
			if( a[i].price>a[j].price) {

				strcpy( tmp.name , a[i].name);
				strcpy(  tmp.id  , a[i].id );
				tmp.price=a[i].price;

				strcpy(  a[i].name, a[j].name);
				strcpy(   a[i].id , a[j].id);
				a[i].price=a[j].price;

				strcpy( a[j].name, tmp.name  );
				strcpy(  a[j].id,tmp.id    );
				a[j].price= tmp.price;

			}
		}
	}

	printf("\n____________________________________\n");
}
void sortPro(pro a[], int n) {
	printf("\n____________________________________\n");
	pro tmp;
	char a1[100];
	char a2[100];
	int i;
	for( i= 0; i < n-1; i++) {
		strcpy(a1, a[i].name);
		int j;
		for( j= i+1; j < n; j++) {
			strcpy(a2, a[j].name);
			if(strcmp(a1, a2) > 0) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	printf("\n____________________________________\n");
}
void writeFilePRO(pro prd[], int n) {

	printf("\n  Save infor product \n");

	FILE* fOut = fopen("product.txt", "a+");
	int i;
	for(i = 0; i < n; i++) {

		fprintf(fOut, "%-20s   %-20s   %-20d \n",
		        prd[i].id,prd[i].name,prd[i].price );
		printf("\n");
	}
	fclose(fOut);

}
void readFilePRO(pro  prd[]  ,int *n) {

	printf("\n        Read infor product \n\n");

	FILE *fp;
	printf("id                     name                   price   \n\n");
	fp=fopen("product.txt","r");
	if(fp!=NULL) {
		int i=0;

		do {
			fscanf(fp, "%20s   %20s   %20d  \n",
			       prd[*n].id, prd[*n].name ,&prd[*n].price );

			printf("%-20s   %-20s   %-20d  \n\n", prd[*n].id, prd[*n].name ,prd[*n].price);
			(*n)++;

		} while(!feof(fp));



		fclose(fp);
	}
}
void writeFileOrder(order b[], int m) {
	printf("\n  Save infor order \n ");

	FILE* fOut = fopen("order.txt", "a+");
	int i;
	for(i = 0; i < m; i++) {

		fprintf(fOut, "%-20s   \n%-20s    \n%-20s   \n%-20s   \n%-20d    \n%-20d    \n%-20d    \n%-20d   \n%-20s   \n\n\n",
		        b[i].orderId,b[i].cName,
		        b[i].cPhone, b[i].shipAdd,b[i].oState, b[i].discount,
		        b[i].total,b[i].PRO[i].quantity,b[i].PRO[i].id  );
		printf("\n");
	}
	fclose(fOut);

}
void readFileOrder(order  b[]  ,int *m) {

	printf("\n  Read infor order \n");

	FILE *fp;
	fp=fopen("order.txt","r");
	if(fp!=NULL) {
		do {
			fscanf(fp, "%20s   \n%20s   \n%20s  \n%20s   \n%20d   \n%20d   \n%20d    \n%20d   \n%20s\n\n",
			       b[*m].orderId,b[*m].cName,
			       b[*m].cPhone, b[*m].shipAdd,&b[*m].oState,& b[*m].discount,
			       & b[*m].total,&b[*m].PRO[*m].quantity,b[*m].PRO[*m].id);

			printf("orderId:    % s\ncName:      % s\ncPhone:     % s\nshipAdd:    % s\noState:    % d\ndiscount:  % d\ntotal:     % d\nquantity:  % d\nidproduct:  % s\t \n\n",
			       b[*m].orderId,b[*m].cName,
			       b[*m].cPhone, b[*m].shipAdd, b[*m].oState, b[*m].discount,
			       b[*m].total,b[*m].PRO[*m].quantity,b[*m].PRO[*m].id);
			;

			(*m)++;
		} while(!feof(fp));

		fclose(fp);

	}
}
void List_order_in_month( order b[], int m) {

	printf("\n  List all orders in a given month \n");

	char c[2];
	printf("enter month \n");
	char month[2];
	do {
		scanf("%s",&month);

	} while(strlen(month)!=2);

	int j;
	for( j= 0; j < m; j++) {
		strncpy(c,b[j].orderId + 2 , 2);
		if(strcmp(month,c))  {
			printOrder(b[j]);
		}


	}

}
void caculateNum(order b[], int m  ) {
	 
	 
	printf("\n  Calculate number of products sold in month, group by each product \n");
	char c[2];
	printf("enter month \n");
	char month[2];
	do {
		scanf("%s",&month);

	} while(strlen(month)!=2);
	char idneed[15];
	printf("Product                   Quantity \n\n" );
	int j	;
	for(j = 0; j < m; j++) {
		strncpy(c,b[j].orderId + 2 , 2);
		if(strcmp(month,c)==0)  {
			int count =0;
			count=b[j].PRO[j].quantity;
			strcpy(idneed,b[j].PRO[j].id);
			int i;
			for( i=j+1; i < m ; i++) {
				if(strcmp(idneed, b[i].PRO[i].id)==0) {
					count+=b[i].PRO[i].quantity;
					b[i].PRO[i].quantity=0;
					strcpy(b[i].PRO[i].id,"");
				}

			}
			if(count!=0) {

				printf("%s        %20d\n\n",idneed,count);
			}

		}



	}
}
typedef struct top5pro {
	int qnt;
	char idtop5[7];
} t5;
t5 t[100];
void top5(order b[], int m, t5 t[]) {
	
	char c[2];
	printf("enter month \n");
	char month[2];
	do {
		scanf("%s",&month);

	} while(strlen(month)!=2);
	char idneed[15];
	int k=0;
	int j;
	for( j= 0; j < m; j++) {
		strncpy(c,b[j].orderId + 2 , 2);
		if(strcmp(month,c)==0)  {
			int count =0;
			count=b[j].PRO[j].quantity;
			strcpy(idneed,b[j].PRO[j].id);
			int i;
			for( i=j+1; i < m ; i++) {
				if(strcmp(idneed, b[i].PRO[i].id)==0) {
					count+=b[i].PRO[i].quantity;
					b[i].PRO[i].quantity=0;
					strcpy(b[i].PRO[i].id,"");
				}

			}
			if(count!=0) {
				strcpy(t[k].idtop5 ,idneed);
				t[k].qnt =count;
				k++;
			}

		}

	}
	int i;
	for(i=0; i<k-1; i++) {
		int j;
		for(j=i+1; j<k; j++) {
			if(t[i].qnt<t[j].qnt) {
				int temp =t[i].qnt;
				t[i].qnt=t[j].qnt;
				t[j].qnt=temp;
				char tempid[7];
				strcpy(tempid ,t[i].idtop5);
				strcpy( t[i].idtop5,t[j].idtop5);
				strcpy( t[j].idtop5,tempid);
			}
		}
	}
	printf("Top 5 best selling in month\n");
	printf("Product                   Quantity \n\n" );
	int h;
	for(h=0; h<5; h++) {
		printf("%s        %20d\n\n",t[h].idtop5,t[h].qnt );
	}
}

int main() {
	char choice;
	do {
		choice = function_choice();

		switch (choice) {
			case 'a':
				add(&n);
				add_product(a,n);

				break;
			case 'i':
				add (&m);
				add_order(b,m);
				break;
			case 'k':
				printNorder(b,m);
				break;
			case 'b':
				update_product(a,n);
				break;
			case 'c':
				delete_product(a,&n);
				break;
			case 'h':
				readFilePRO(a,&n);
				break;
			case 'd':
				printN(a,n);
				break;
			case 'e':
				printN(a,n);
				sortProName(a,n);
				break;
			case 'n':
				List_order_in_month( b, m);
				break;
			case 'g':
				writeFilePRO(a,n);
				break;
			case 'p':
				top5(b,m,t);
				break;
			case 'm':
				readFileOrder(b,&m);
				break;
			case 'l':
				writeFileOrder(b,m);
				break;
			case 'o':
				caculateNum(b,m);
				break;
			case 'f':
				sortProPrice(a,n);
				printN(a,n);
		}

		if (choice != 'q') {
			printf("\n\n---\n");
			printf("Press any key to back to main menu.");
			getch();
		}
	} while (choice != 'q');



	return 0;
}




