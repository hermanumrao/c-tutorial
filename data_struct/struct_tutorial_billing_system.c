#include <stdio.h>

//simplified billing system
// maintain details in an array of structures.

struct date
{	int month;
	int day;
	int year;
};

struct account 
{	char name[20];
	char street[30];
	char city[10];
	int acc_no;
	char acc_type;	// 3 types 'O':payment> 10% of prev outstanding balance   
			// 'D':Delinquent if there is outstanding balnce but payment=0    
			// 'c':current otherwise
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
} customer[10];

void readinput(int i);  		//funct declaration
void writeoutput(int i);

int main()
{	int n;
	
	printf("CUSTOMER BILLING SYSTEM \n\n");
	printf("How many customers\t:");
	scanf("%d",&n);

	for (int i=0;i<n;i++)
	{	readinput(i);

		//determine account status
		if (customer[i].payment >0)
			customer->acc_type=((customer[i].payment< 0.1*customer[i].oldbalance) ? 'O' :'C');
		else customer->acc_type=(customer[i].oldbalance>0) ? 'D' :'C';

		// adjust current balance
		customer[i].newbalance = customer[i].oldbalance-customer[i].payment;
	}
	for (int i=0; i<n;i++)
		writeoutput(i);
	return 0;
}



void readinput(int i)
{	printf("\n Customer number : %d",i+1);
	printf("\nName\t:");
	scanf("%s", customer[i].name);
	printf("\nstreet\t:");    
        scanf("%s", customer[i].street);
	printf("\ncity\t:");    
        scanf("%s", customer[i].city);
	printf("\nAccount Number\t:");    
        scanf("%d", &customer[i].acc_no);
	printf("\npreveeous balance\t:");    
        scanf("%f", &customer[i].oldbalance);
	printf("\nCurrent Payment\t:");    
        scanf("%f", &customer[i].payment);
	printf("\nDate of Payment\t:");    
        scanf("%d %d %d", &customer[i].lastpayment.day,
			&customer[i].lastpayment.month,
			&customer[i].lastpayment.year);
	return;
}

void writeoutput(int i)
{	printf("\nName: %s",customer[i].name);
	printf("\tAccount number: %d\n",customer[i].acc_no);
	printf("street : %s\n",customer[i].street); 
	printf("city : %s\n",customer[i].city);
	printf("old balance : %7.2f\n",customer[i].oldbalance);
	printf("current payment : %7.2f\n",customer[i].payment);
	printf("new balance : %7.2f\n",customer[i].newbalance);
	printf("account status :- ");

	switch (customer[i].acc_type)
	{	case 'C':
			printf("CURRENT \n");
			break;
		case 'D':
                        printf("DELINQUENT \n");
                        break;
		case 'O':
                        printf("OVERDUE \n");
                        break;
		default:
			printf("ERROR\n");
	}
	return;
}

