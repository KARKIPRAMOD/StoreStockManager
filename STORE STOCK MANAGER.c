#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define xc 75

void name();   // for product details
void display();
void display1();
void pass(char);
void Admin();
void staff();
void display_product();
void total_product();
void search();
void new_product();
void purchase();
void edit_product();
void delete_product();
void zero_product();
void highest_product();
void sales_report();
void make_sale();
void display_sale();
void edit_sale();
void delete_sale();
void total_sold_product();
void highest_lowest_sale();
void order_list();
void display_orderlist();
void edit_orderlist();
void delete_orderlist();
void total_order_list();
void edit_order_list();
void monthly_report();
void yearly_report();
void profit_loss();

void Employee();                       //For  Employee management 
void add_employee();         
void display_employee();
void search_employee();
void edit_employee();
void delete_employee();
void total_employee();
 
typedef struct info
{
	char product_id[10];
	char product_name[20];
	int quantity;
	char product_category[15];
	char purchased_date[15];
	char manufacture_name[15];
	char manufacture_contact[20];
	char shipping_company[15];
	char contact_no[20];
	char mfg_date[15];
	char exp_date[15];
	float cost_price;
	float sales_price;
	char sold_product_id[15];
	float discount;
	int sold_quantity;
	int old_sold_quantity;
	int total_sold_quantity;
	int s_day,s_month,s_year;
	char sales_type[15];
	char order_product_id[15];
	char order_product_name[15];
	char order_product_category[10];
	int order_max_limit;
	int order_product_quantity;
	char order_manufacture_name[15];
	char order_manufacture_contact[20];
	char order_shipping_company[15];
	char order_contact_no[20];
	char status[10];
	float total,totalsoldam,totalcostam,spentam,gainedam;
	int sn;
	int max;
	 
}info;

typedef struct employee                 //For  Employee management 
{
	char emp_id[10];
	char emp_name[20];
	char emp_post[15];
	char emp_address[20];
	char emp_contact[20];
	float emp_salary;
	char emp_remarks[100];
}employee;

void gotoxy(int x, int y)
{ 
  COORD pos = {x, y}; 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
        k=i;
}

void main ()                                                                // main function
{
	getch();
	int option,i;
    system("cls");
    name();
	printf("\n");
	gotoxy(xc,14);
	printf("press\n");
	gotoxy(xc,15);
	printf("1 for Manager\n");
	gotoxy(xc,16);
	printf("2 for Staff\n");
	gotoxy(xc,17);
	printf("Manager or staff:");
	scanf("%d",&option);
	system("cls");
	name();
	switch(option)
	{
		case 1:
		Admin();
        break;
        
        case 2:
        staff();
        break;
        
        default:
        gotoxy(xc,15);
        printf("Invalid Input! Please Choose the correct option\a");
        
	}
	sleep (3);
	system("cls");
	main();
}

void name()
{
	int i,j;
	char cur_time[128];
	
	HANDLE  hConsole;
    int k=3,l=14,m=15;
	gotoxy (70+21,7);
	printf("*-----STORE STOCK MANAGER-----*");	
       time_t      t;
       struct tm*  ptm;
       t = time(NULL);
       ptm = localtime(&t);
       strftime(cur_time, 128, "%d-%b-%Y  %H:%M", ptm);
       gotoxy(97+21,12);
	   printf("%s\n", cur_time);
    
	//Top border line...
    gotoxy(50+21,5); 
    for(j=0; j<69; j++)
    printf("%c", 223);
  
    //middle border line...
    gotoxy(50+21,10); 
    for(j=0; j<69; j++)
    printf("%c", 223);
 
    //Bottom border line... 
    gotoxy(50+20,41);
    for(j=0; j<=69; j++)
    printf("%c", 223);
	
	
   //Left and Right border line...
   for(j=0; j<36; j++)
   {
     gotoxy(50+20,5+j);
     printf("%c",219);
  
     gotoxy(119+20,5+j);
     printf("%c",219);
   }
}

void name1()
{
	int i,j;
	char cur_time[128];
	gotoxy (70+21,8);
	printf("*-----STORE STOCK MANAGER-----*");	
	
	//Top border line...
    gotoxy(40,5); 
    for(j=0; j<69+69; j++)
    printf("%c", 223);
  
    //middle border line...
    gotoxy(40,10); 
    for(j=0; j<69+69; j++)
    printf("%c", 223);
 
    //Bottom border line... 
    gotoxy(40,41);
    for(j=0; j<=69+69; j++)
    printf("%c", 223);
    
    for(i=10;i<41;i++)
    {
    	gotoxy(40+69,i);
        printf("%c",219);
    	
	}
    
   //Left and Right border line...
   for(j=0; j<36; j++)
   {
     gotoxy(40,5+j);
     printf("%c",219);
  
     gotoxy(40+69+69,5+j);
     printf("%c",219);
   }
}
void display()                                                                // display function for Admin menu
{
	//system("cls");
	name();
	gotoxy(xc,14);
	printf("press ");
	gotoxy(xc,15);
    printf("1.) Display all existing products ");
    gotoxy(xc,16);
    printf("2.) Add new product details ");
    gotoxy(xc,17);
    printf("3.) Search Product Details ");
    gotoxy(xc,18);
    printf("4.) Edit a existing product ");
    gotoxy(xc,19);
    printf("5.) Make a purchase ");
    gotoxy(xc,20);
    printf("6.) Sales Report ");
    gotoxy(xc,21);
    printf("7.) Order List ");
    gotoxy(xc,22);
    printf("8.) Delete a Product ");
    gotoxy(xc,23);
    printf("9.) Display all product with zero quantity ");
    gotoxy(xc,24);
    printf("10.) Total Number of product ");
    gotoxy(xc,25);
	printf("11.) Employee Management ");
    gotoxy(xc,26);
	printf("12.) TO Go Back TO LOGIN PAGE ");
    gotoxy(xc,27);
    printf("0.) Exit SSM ");
}

void display1()                                                                // display function for Staff menu
{
	//system("cls");
	name();
	gotoxy(xc,14);
	printf("press ");
	gotoxy(xc,16);
    printf("1.) Display all existing products ");
    gotoxy(xc,17);
    printf("2.) Add new product details ");
    gotoxy(xc,18);
    printf("3.) Search a Product Detail ");
    gotoxy(xc,19);
    printf("4.) Make a purchase ");
    gotoxy(xc,20);
    printf("5.) Sales Report ");
    gotoxy(xc,21);
    printf("6.) Order List ");
    gotoxy(xc,22);
    printf("7.) Total Number of product ");
    gotoxy(xc,23);
    printf("8.) Display all product with zero quantity ");
    gotoxy(xc,24);
	printf("9.) TO Go Back TO LOGIN PAGE !!");
    gotoxy(xc,25);
    printf("0.) Exit SSM ");
}
void Admin()                                                                // Admin menu
{
	int len=50,cpos=0,comp,p,i;
	int option;
	char password[len +1],ch,pass[50];
	strcpy(pass,"pass123");
    name();
    gotoxy(xc,14);
	printf("Enter your password:\n");
	gotoxy(xc,15);
    while(1)
	{
        ch=getch();
        if(ch==13)
		{	 break;    /* if user hits enters button */}
		else if(ch==8)
		{
			if(cpos > 0)
			{
		    	cpos--;   //backspace
		    	password[cpos]= '\0';
		    	printf("\b \b");
	    	}
		}
		else if(ch== 9 ||ch== 32)
		{	continue;  /*space and tab*/ }
		else 
		{    if(cpos < len)
			{
			  password[cpos]=ch;
			  cpos++;
			  printf("*");
			}
	        else
	        break;
		}
    }
    password[cpos]='\0';
	comp=strcmp(password,pass);
	if(comp==0)
	{
		{system("cls");
	    name();
	    gotoxy(80,20);
		printf("Password Match!LOADING");
		gotoxy(103,20);
        for(i=0;i<=10;i++)
        {
            fordelay(100000000);
            printf(".");
        }}
	do{
	system("cls");
	name();
    display();
    gotoxy(xc,28);
    printf("Press the option:");
    scanf("%d",&option);
    switch (option)
    {
        case 0:
    	exit(0);
    	break; 
    	    
        case 1:
    	display_product();
    	break;
    	    
    	case 2:
    	new_product();
    	break;
    	    
    	case 3:
    	search();
    	break;
    	    
    	case 4:
    	edit_product();   	
    	break;
    	    
    	case 5:
    	purchase();
    	break;
    	    
    	case 6:
    	sales_report();
    	break;
    	    	
    	case 7:
    	order_list();
    	break;
    	    
    	case 8:
    	delete_product();
    	break;
    	    
    	case 9:
    	zero_product();
       	break;
       	    
    	case 10:
    	total_product();
    	break;	    
    	    
    	case 11:
    	Employee();
    	break;
    	    
    	case 12:
    	main();
    	break;
    	   
    	default :
		printf("\a");
	    }
    } while(option!=0);
    }
	else
    {
       system("cls");
       name();
       gotoxy(98,18);
       printf("\aInvalid password!");
       gotoxy(96,19);
       printf("Enter Correct Password ");
       getch();
       system("cls");
    }
	Admin();   
} 
   
void staff()                                                                //Staff menu
{
	int len=50,cpos=0,comp,p,option,i;
	char password[len +1],ch,pass[50];
	strcpy(pass,"staff123");
    name();
    gotoxy(xc,14);
	printf("Enter your password:\n");
	gotoxy(xc,15);
    while(1)
	{
        ch=getch();
        if(ch==13)
		{	 break;    /* if user hits enters button */}
		else if(ch==8)
		{
			if(cpos > 0)
			{
		    	cpos--;   //backspace
		    	password[cpos]= '\0';
		    	printf("\b \b");
	    	}
		}
		else if(ch== 9 ||ch== 32)
		{	continue;  /*space and tab*/ }
		else 
		{    if(cpos < len)
			{
			  password[cpos]=ch;
			  cpos++;
			  printf("*");
			}
	        else
	        break;
		}
    }
    password[cpos]='\0';
    //printf("%s and %s",pass,password);
	//comp=strcmp(password1,pass1);
	if(strcmp(password,pass)==0)
	{
		{system("cls");
	    name();
	    gotoxy(80,20);
		printf("Password Match!LOADING");
		gotoxy(103,20);
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }}
     do{
     	system("cls");
	    name();
		display1();
        int option;
        gotoxy(xc,26);
        printf("Press the option:");
        scanf("%d",&option);
        switch (option)
         {
            case 0:
            exit(0);
            break;
            
         	case 1:
    	    display_product();
    	    break;
    	    
    	    case 2:
    	    new_product();
    	    break;
    	    
    	    case 3:
    	    search();
    	    break;
    	    
    	    case 4:
    	    purchase();
    	    break;
    	    
    	    case 5:
    	    sales_report();
    	    break;
    	    
    	    case 6:
    	    order_list();
    	    break;
    	    
    	    case 7:
    	    total_product();
    	    break;
    	    
    	    case 8:
    	    zero_product();
    	    break;
    	    
    	    case 9:
    	    main();
    	    break;
    	    
    	    default :
    	    printf("\a"); 
		 }
      }while(option!=0); 
	}
	else
    {
      system("cls");
	  name();
	  gotoxy(98,18);
      printf("\aInvalid password!");
      gotoxy(96,19);
      printf("Enter Correct Password "); 
      getch();
      system("cls");
      staff();
    }    
}

void display_product()                                                 // display function to display products
{
	system("cls");
	info e1;
	FILE *fp;
	int j,sn=0,c=20,a=19,b=18;
	fp= fopen("inventory.dat", "rb");
	// Top Border
	gotoxy(12,13);
	for(j=0; j<100+95; j++)
    printf("%c", 205);
    // Top Border
    gotoxy(12,16);
	for(j=0; j<100+95; j++)
    printf("%c", 205);
    // Top left corner
    gotoxy(12,13);
	printf("%c",201);
	// Top Left corner 
    gotoxy(77+130,13);
	printf("%c",187);
	gotoxy(15,15);
	printf("SN. | \t  ID. \t | \t NAME \t\t | \t CATEGORY \t | \t QUANTITY \t | \t MFG DATE \t | \t EXP DATE \t | \t PURCHASED DATE \t | \t SALES PRICE \t ");
	while(fread(&e1, sizeof(info),1,fp))
	{
	    sn++;
	    // left Border
	    for(j=14;j<=c;j++)
	    {
		    gotoxy(77+130,j);
		    printf("%c",186);
	    }
	    //Right Border
	    for(j=14;j<=c;j++)
	    {
		    gotoxy(12,j);
		    printf("%c",186);
	    }
       	   
	    gotoxy(15,a);
		printf("%d .",sn);
		gotoxy(25,a);
		printf("%s",strupr(e1.product_id));
		gotoxy(40,a);
		printf("%s",strupr(e1.product_name));
		gotoxy(65,a);
		printf("%s",strupr(e1.product_category));
		gotoxy(90,a);
		printf("%d",e1.quantity);
		gotoxy(100+15,a);
		printf("%s",strupr(e1.mfg_date));
		gotoxy(60+80,a);
		printf("%s",strupr(e1.exp_date));
		gotoxy(65+100,a);
		printf("%s",strupr(e1.purchased_date));
		gotoxy(65+130,a);
		printf("%f",e1.sales_price);
		gotoxy(13,c);
	    for(j=0; j<100+94; j++)
        printf("%c", 95);
		a+=2;
		c+=2;
		//b=a;
		// Bottom left corner
        gotoxy(12,c-2);
	    printf("%c",200);
	    // Bottom Left corner 
        gotoxy(77+130,c-2);
	    printf("%c",188);
	    gotoxy(13,c-2);
	    for(j=0; j<100+94; j++)
        printf("%c", 205);    
	}
	if (fp==NULL)
	{
		gotoxy(15,10);
		printf("NO ITEMS TO SHOW");
	}
    
    
	fclose(fp);
	getch();
		
}
void  new_product()                                                                //  function for adding new product in the inventory
{
	system("Cls");
	name();
	info *e,e1,e0;
	FILE *fp,*fp1;
	char ids[10];
	int i,n,j;
	//fp=fopen("inventory.dat","ab+");            //opening a file named inventory.dat
	//fp1=fopen("inventory.dat","rb");
	gotoxy(xc,14);
	fflush(stdin);
	printf("How many products you want to  add:  ");
	scanf("%d",&n);
	e= (info*)calloc(n,sizeof(info));
	
	for(i=0;i<n;i++)
	{
	  l1:
	  fp=fopen("inventory.dat","ab+");            //opening a file named inventory.dat
	  fp1=fopen("inventory.dat","rb");
	  system("cls");
	  name();
	  fflush(stdin);
	  gotoxy(xc,14);
	  printf("DETAILS FOR PRODUCT %d:",i+1);
	  gotoxy(xc,16);
	  printf("Enter product ID:  ");
	  gets(ids);
	  while(fread(&e0, sizeof(info),1,fp1))
	  {	
	    if(strcmp(e0.product_id,ids)==0)                      
	    {
	    	gotoxy(xc+5,18);
	    	printf("ID %s is alreday taken",ids);
	    	gotoxy(xc+5,19);
	    	printf("Choose another ID");
	    	gotoxy(xc,20);
	    	printf("Press Any Key To Continue");
	    	getch();
	    	fclose(fp);
	    	fclose(fp1);
	    	goto l1;
	    }
	  }
	  strcpy(e[i].product_id,ids);
	  gotoxy(xc,18);
	  printf("Enter Product Name :  ");
	  gets(e[i].product_name);
	  fflush(stdin);
	  gotoxy(xc,20);
	  printf("Enter Product Category:  ");
	  gets(e[i].product_category);
	  gotoxy(xc,22);
	  printf("Enter Manufacture Name:  ");
	  gets(e[i].manufacture_name);
	  gotoxy(xc,24);
	  printf("Enter Manufacture contact Number:  ");
	  gets(e[i].manufacture_contact);
	  gotoxy(xc,26);
	  printf("Enter Shipping Company :  ");
	  gets(e[i].shipping_company);
	  gotoxy(xc,28);
	  printf("Enter Contact Detail:  ");
	  gets(e[i].contact_no);
	  gotoxy(xc,30);
	  printf("Enter Max Limit: ");
	  scanf("%d",&e[i].max);
	
	  fwrite(&e[i],sizeof(info),1,fp);
	  fclose(fp);
      fclose(fp1);
	  
    }
    system("cls");
    name();
    gotoxy(60+21,17);
    printf("NEW PRODUCT DETAILS ADDED SUCESSFULLY ");
    getch();
}

void total_product()   // press 9                                                              // To display total products in the inventory 
{
	system("Cls");
	name();
	gotoxy(xc,14);
	info i1;
	FILE *fp;
	fp=fopen("inventory.dat","rb");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof (info);
	printf("Total number of products= %d",n);
	fclose(fp);
	getch();
}

void search()    // staff ma press 5                                                                  //  function for searching  product in the inventory                              
{
	system("cls");
	name();
	char ids[10];
	info e1;
	FILE *fp;
	int a=18,c=19,found=0,j;
	fp= fopen("inventory.dat","rb");
	fflush(stdin);
	gotoxy(xc,13);
	printf("Enter the ID or Name to search the product: ");
	gets(ids);
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    if(strcmp(ids,e1.product_id)==0||strcmp(ids,e1.product_name)==0)
	    {
	    	found=1;
	    	system("cls");
	    	gotoxy(50,11);
	    	printf("Product Found");
	    	//Top Border
	    	gotoxy(50,13);
	    	for(j=0; j<100; j++)
        	printf("%c", 205);
        	// Right Border
	    	for(j=14;j<=28;j++)
	    	{
		    	gotoxy(150,j);
		    	printf("%c",186);
	    	}
	
	    	gotoxy(60,15); 
	    	printf(" ID                     %s",strupr(e1.product_id));
	    	gotoxy(110,15);
	    	printf(" Name                %s",strupr(e1.product_name));
	
	    	gotoxy(50,16);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
	    	gotoxy(60,17);
	    	printf(" Category               %s",strupr(e1.product_category));
	    	gotoxy(110,17);
	    	printf(" Quantity            %d",e1.quantity);
	
	    	gotoxy(50,18);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
        	gotoxy(60,19);
	    	printf(" Maanufacture Date      %s",strupr(e1.mfg_date));
	    	gotoxy(110,19);
	    	printf(" Expiry Date         %s",strupr(e1.exp_date));
	
	    	gotoxy(50,20);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
        	gotoxy(60,21);
	    	printf(" Cost Price             %.2f",e1.cost_price);
	    	gotoxy(110,21);
	    	printf(" Sales Price         %.2f",e1.sales_price);
	
	    	gotoxy(50,22);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
	    	gotoxy(60,23);
	    	printf(" Manufacture Name       %s",strupr(e1.manufacture_name));
	    	gotoxy(110,23);
	    	printf(" Contact No.         %s",strupr(e1.manufacture_contact));
	
	    	gotoxy(50,24);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
	    	gotoxy(60,25);
	    	printf(" Shipping Copamy        %s",strupr(e1.shipping_company));
	    	gotoxy(110,25);
	    	printf(" Contact No.         % s",strupr(e1.contact_no));
	
	    	gotoxy(50,26);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
        	gotoxy(60,27);
	    	printf(" Purchased Date         %s",strupr(e1.purchased_date));
	    	gotoxy(110,27);
    		printf(" Max Purchase Limit  %d",e1.max);
	
	    	gotoxy(50,28);
	    	for(j=0; j<100; j++)
        	printf("%c", 95);
	    	a+=2;
	    	c+=2;
	
	    	//Mid Border
	    	for(j=14;j<=28;j++)
	    	{
		    	gotoxy(100,j);
		    	printf("%c",186);
	    	}
	    	//Left Border
	    	for(j=14;j<=28;j++)
	    	{
		    	gotoxy(50,j);
		    	printf("%c",186);
	    	}
        	// Top left corner
        	gotoxy(50,13);
	    	printf("%c",201);
	    	// Top mid 
        	gotoxy(100,13);
	    	printf("%c",203);
	    	// Top Right corner 
        	gotoxy(150,13);
	    	printf("%c",187);
	    	// Bottom left corner
        	gotoxy(50,28);
	    	printf("%c",200);
	    	// Bottom Right corner 
        	gotoxy(150,28);
	    	printf("%c",188);
	    	//Bottom line
	    	gotoxy(51,28);
	    	for(j=0; j<99; j++)
        	printf("%c", 205);
        	// Top mid 
        	gotoxy(100,28);
	    	printf("%c",202);
        }
    }
	
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(72+21,20);
		printf("Product not found!!\a");
		gotoxy(65+21,21);
		printf("Press Any Key to Go Back To Menu ");
		//sleep(2);
	}
	fclose(fp);
	getch();
	
}
void delete_product()   //press 6                                                          //  function for deleting  product from the inventory
{
	system("Cls");
	name();
	info i1;
	FILE *fp,*fp1;
	char ids[10],ch;
	int found=0;
	fflush(stdin);
	gotoxy(xc,14);
	printf("Enter the ID or Name to Delete the product: ");
	gets(ids);
	fp=fopen("inventory.dat","rb");
	fp1=fopen("temp.dat","wb");	
	gotoxy(xc,15);
	while(fread(&i1, sizeof(info),1,fp))
	{	
	    if(strcmp(ids,i1.product_id)==0||strcmp(ids,i1.product_name)==0)                //searching id or name to match the product id or name
	    {
	    	found=1;
	    }
	    else
	    fwrite(&i1,sizeof(info),1,fp1);                            // copyng previous data to temporary file leaving the if  product matched   
	}
	fclose(fp);
	fclose(fp1);
	
	if(found==1)                                                  //if found copyng previous data to original file 
	{
		fp1=fopen("temp.dat","rb");
		fp=fopen("inventory.dat","wb+");
		
	    while(fread(&i1, sizeof(info),1,fp1))
	    fwrite(&i1,sizeof(info),1,fp);
	    
	    fclose(fp1);
	    fclose(fp);
	    system("cls");
	    name();
	    gotoxy(65+21,18);
	    printf("PRODUCT DETAIL SUCESSFULLY DELETED"); 
	    gotoxy(xc,21);
	    printf("Do You Want To Delete Another Product (Y/N): ");
	    scanf("%c",&ch);
	    if(ch=='y'||ch=='Y')
	    delete_product();
	}
	if(!found)                                                   //if ID not found  returning to main menu 
	{
		system("cls");
	    name();
	    gotoxy(72+21,20);
		printf("Product not found!!\a");
		gotoxy(65+21,21);
		printf("Press Any Key to Go Back To Menu ");
		remove("temp.dat");	
		getch();	
	}
	remove("temp.dat");
}

void purchase()      //press 4                                                          //  function for making a purchase
{
	system("cls");
	name();
	info e1,*e;
	FILE *fp,*fp1;
	char ids[10],ch;
	int i,n,j, count=0,found=0,quantity;
	fp=fopen("inventory.dat","rb");
	fp1=fopen("temp1.dat","wb");
	gotoxy(xc,15);
	fflush(stdin);
    printf("Enter the ID or Name For Purchase : ");
	gets(ids);
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    count ++;
	    e = (info*)calloc(count,sizeof(info));
	    if(strcmp(ids,e1.product_id)==0||strcmp(ids,e1.product_name)==0)                       //searching id or name to match the product id or name
	    {
	    	found =1;
	    	l1:
	    	system("cls");
			name();
			gotoxy(xc,16);
			printf("Max Purchase Limit %d",e1.max);
	        gotoxy(xc,18);
            printf("Enter quantity:  ");
            scanf("%d",&quantity);
           if(quantity<=e1.max)
           {
           	if(e1.max!=0)
           	{
           	fflush(stdin);
            gotoxy(xc,20);
            printf("Enter Purchased Date:  ");
            gets(e[count-1].purchased_date);
            gotoxy(xc,22);
            printf("Enter Manufacture Date:  ");
            gets(e[count-1].mfg_date);
            gotoxy(xc,24);
            printf("Enter Expiry Date:  ");
            gets(e[count-1].exp_date);
            gotoxy(xc,26);
            fflush(stdin);
            printf("Enter Cost Price:  ");
            scanf("%f",&e[count-1].cost_price);
            gotoxy(xc,28);
            fflush(stdin);
            printf("Enter sales Price:  ");
            scanf("%f",&e[count-1].sales_price);
            
            e[count-1].quantity=e1.quantity+quantity;
            strcpy(e[count-1].product_id,e1.product_id);                              //Writing previous data in file along with purchase details
			strcpy(e[count-1].product_name,e1.product_name);
			strcpy(e[count-1].product_category,e1.product_category); 
			strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			strcpy(e[count-1].shipping_company,e1.shipping_company);
			strcpy(e[count-1].contact_no,e1.contact_no);
			e[count-1].max=e1.max;
			
			e[count-1].totalcostam+=(e[count-1].cost_price)*e[count-1].quantity;	
		   }
		   else
		   {
		   	   gotoxy(xc,20);
		       printf(" Max Purchase Limit is Zero Edit Max Limit To make Purchase");
		       getch();
		   }
		   }
		   else
		   {
		   	gotoxy(xc+15,20);
		   	printf("\a Max Limit Exceeded");
		   	gotoxy(xc+10,21);
		   	printf("Cannot Purchase More Than %d ",e1.max);
		   	getch();			 
		    goto l1;
		   }
		fwrite(&e[count-1],sizeof (info),1,fp1);
		}
        
        else
        {
        	strcpy(e[count-1].product_id,e1.product_id);                             //Writing previous data in file if product not found without purchase details
			strcpy(e[count-1].product_name,e1.product_name);
			strcpy(e[count-1].product_category,e1.product_category); 
			strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			strcpy(e[count-1].shipping_company,e1.shipping_company);
			strcpy(e[count-1].contact_no,e1.contact_no);
			e[count-1].cost_price=e1.cost_price; 
			e[count-1].sales_price=e1.sales_price;
			strcpy(e[count-1].purchased_date,e1.purchased_date); 
			e[count-1].quantity=e1.quantity;
			strcpy(e[count-1].mfg_date,e1.mfg_date); 
			strcpy(e[count-1].exp_date,e1.exp_date);
			e[count-1].max=e1.max;
			e[count-1].totalcostam=(e1.cost_price)*e1.quantity+e[count-1].totalcostam;	
			  
			fwrite(&e[count-1],sizeof (info),1,fp1);
		}
	e[count-1].spentam+=(e[count-1].quantity)*e[count-1].cost_price;
   }
   fclose(fp);
   fclose(fp1);
   if(found)
	{
		system("cls");
		name();
		gotoxy(xc+20,18);
		printf("Purchase Successfull ");
		remove("inventory.dat");
		rename("temp1.dat","inventory.dat");    

		fflush(stdin);
    	gotoxy(xc,25);
		printf("Purchase Another Product (Y/N): ");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y')
		purchase();    
	}
	
	else
	{
		system("cls");
		name();
		gotoxy(xc+18,18);
		printf("Product not found !");
		gotoxy(xc+5,19);
		printf("Please Try again with valid ID. Press any key to continue.");
		remove("temp1.dat");
		getch();
	}	
}
 
 
void edit_product()   //press 3                                                             //  function for editing  product detail in the inventory
{
	system("cls");
	name();
	char ids[10],ch,ids1[10];
	info e1,*e,e0;
	FILE *fp,*fp1,*fp2;
	int choice,a=70+65,found=0,count=0;
	fp=fopen("inventory.dat","rb");
	fp1=fopen("temp3.dat","wb");
	fp2=fopen("inventory.dat","rb");
	fflush(stdin);
	gotoxy(xc,13);
	printf("Enter the ID or Name to Edit the product: ");
	gets(ids);
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    count ++;
	    e = (info*)calloc(count,sizeof(info));
	    if(strcmp(ids,e1.product_id)==0||strcmp(ids,e1.product_name)==0)                       //if id or name matches edit menu opens 
	    {
	    	found=1;
	    	system("cls");
			name1();
			gotoxy(70+65,14);
			printf("OLD DETAILS:  ");
			gotoxy(a,16);
	        printf("Product ID.          %s",strupr(e1.product_id));
	        gotoxy(a,17);
	        printf("Product Name         %s",strupr(e1.product_name));
	        gotoxy(a,18);
	        printf("Product Category     %s",strupr(e1.product_category));
	        gotoxy(a,19);
	        printf("Quantity             %d",e1.quantity);
	        gotoxy(a,20);
	        printf("Manufacture Date     %s",strupr(e1.mfg_date));
	        gotoxy(a,21);
	        printf("Expiry Date          %s",strupr(e1.exp_date));
	        gotoxy(a,22);
	        printf("Manufacture Name     %s",strupr(e1.manufacture_name));
	        gotoxy(a,23);
	        printf("Contact No.          %s",strupr(e1.manufacture_contact));
	        gotoxy(a,24);
	        printf("Shipping Company     %s",strupr(e1.shipping_company));
	        gotoxy(a,25); 
	        printf("Contact No:          %s",strupr(e1.contact_no));
	        gotoxy(a,26); 
	        printf("Cost Price           %f",e1.cost_price);
	        gotoxy(a,27); 
	        printf("Sales Price          %f",e1.sales_price);
	        gotoxy(a,28);
		    printf("Purchase Limit       %d",e1.max);
	    	gotoxy(45,15);
	    	printf("Press ");
	    	gotoxy(45,16);
	    	printf("0.) To Go Back To Main Menu !! ");
	    	gotoxy(45,17);
	    	printf("1.) Update product ID ");
	    	gotoxy(45,18);
        	printf("2.) Update Name of the product ");
        	gotoxy(45,19);
        	printf("3.) Update Quantity  ");
        	gotoxy(45,20);
        	printf("4.) Update Cost Price and sales price ");
        	gotoxy(45,21);
        	printf("5.) Update Product Category ");
        	gotoxy(45,22);
			printf("6.) Update Manufacture Date And Expiry Date ");
        	gotoxy(45,23);
			printf("7.) Update Purchased Date ");
        	gotoxy(45,24);
			printf("8.) Update MAnufacturer Name and contact  ");
        	gotoxy(45,25);
        	printf("9.) Update  Shipping Company Name and Contact ");
        	gotoxy(45,26);
        	printf("10.) All of the above ");
        	gotoxy(45,27);
        	printf("11. Update Purchase Max Limit ");
	    	gotoxy(45,29);
            printf("Enter your choice: ");
            fflush(stdin);
            scanf("%d", &choice);
            l1:
	        
            system("cls");
			name1();
			gotoxy(70+65,14);
			printf("OLD DETAILS:  ");
            gotoxy(a,16);
	        printf("Product ID.          %s",strupr(e1.product_id));
	        gotoxy(a,17);
	        printf("Product Name         %s",strupr(e1.product_name));
	        gotoxy(a,18);
	        printf("Product Category     %s",strupr(e1.product_category));
	        gotoxy(a,19);
	        printf("Quantity             %d",e1.quantity);
	        gotoxy(a,20);
	        printf("Manufacture Date     %s",strupr(e1.mfg_date));
	        gotoxy(a,21);
	        printf("Expiry Date          %s",strupr(e1.exp_date));
	        gotoxy(a,22);
	        printf("Manufacture Name     %s",strupr(e1.manufacture_name));
	        gotoxy(a,23);
	        printf("Contact No.          %s",strupr(e1.manufacture_contact));
	        gotoxy(a,24);
	        printf("Shipping Company     %s",strupr(e1.shipping_company));
	        gotoxy(a,25); 
	        printf("Contact No:          %s",strupr(e1.contact_no));
	        gotoxy(a,26); 
	        printf("Cost Price           %f",e1.cost_price);
	        gotoxy(a,27); 
	        printf("Sales Price          %f",e1.sales_price);
	        gotoxy(a,28);
		    printf("Purchase Limit       %d",e1.max);
            switch(choice)
            {
            	case 0:
            	strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
			    strcpy(e[count-1].product_name,e1.product_name);
		    	strcpy(e[count-1].product_category,e1.product_category); 
		    	strcpy(e[count-1].manufacture_name,e1.manufacture_name);
		    	strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
		    	strcpy(e[count-1].shipping_company,e1.shipping_company);
		    	strcpy(e[count-1].contact_no,e1.contact_no);
		    	e[count-1].cost_price=e1.cost_price; 
		    	e[count-1].sales_price=e1.sales_price;
	    		strcpy(e[count-1].purchased_date,e1.purchased_date); 
		    	e[count-1].quantity=e1.quantity;
		    	strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date);
		    	e[count-1].max=e1.max; 
		    	e[count-1].totalcostam=(e[count-1].cost_price)*e[count-1].quantity+e[count-1].totalcostam;	
            	break;
            	
    	        case 1 :                 
               	fflush(stdin);
                gotoxy(45,15);
    	        printf("Enter New ID:  ");
    	        gets(ids1);
	            while(fread(&e0, sizeof(info),1,fp2))
	            {	
	                if(strcmp(e0.product_id,ids1)==0)                      
	                {
	                	//system("cls");
	    	            gotoxy(xc+5,18);
	    	            printf("ID %s is alreday taken",ids1);
	    	            gotoxy(xc+5,19);
	                	printf("Choose another ID");
	                	gotoxy(xc,20);
	    	            printf("Press Any Key To Continue");
	    	            getch();
	    	            goto l1;         
	                }
	            }
    	        strcpy(e[count-1].product_id,ids1);
			    strcpy(e[count-1].product_name,e1.product_name);                            //Writing previous data in file 
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date);   
		    	e[count-1].max=e1.max;
				e[count-1].totalcostam==e1.totalcostam;	
    	        break;
    	
    	        case 2 :    	        
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New Name:  ");
    	        gets(e[count-1].product_name);
    			strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date);  
		    	e[count-1].max=e1.max;
				e[count-1].totalcostam==e1.totalcostam;		 
    	        break;
    	
    	        case 3 :
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New quantity:  ");
    	        scanf("%d",&e[count-1].quantity);
    	        strcpy(e[count-1].product_id,e1.product_id);
				strcpy(e[count-1].product_name,e1.product_name);                            //Writing previous data in file
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date);
				e[count-1].max=e1.max; 
				e[count-1].totalcostam=(e1.cost_price)*e[count-1].quantity+e[count-1].totalcostam;	 
    	        break;
    	
    	        case 4:    	        
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New cost price:  ");
    	        scanf("%f",&e[count-1].cost_price);
    	        gotoxy(45,17);
    	        printf("Enter New Sales price:  ");
    	        scanf("%f",&e[count-1].sales_price);
    	        
    	        strcpy(e[count-1].product_id,e1.product_id);                          //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date); 
		    	e[count-1].max=e1.max; 
		        e[count-1].totalcostam=(e[count-1].cost_price)*e1.quantity+e[count-1].totalcostam;	 
    	        break;
    	        
    	        case 5:    	        
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New Product Category : ");
    	        gets(e[count-1].product_category);
    	        
    	        strcpy(e[count-1].product_id,e1.product_id);                          //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
		    	strcpy(e[count-1].exp_date,e1.exp_date); 
		    	e[count-1].max=e1.max; 
		    	e[count-1].totalcostam==e1.totalcostam;	
		    	break;
    	
    	        case 6:
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New manufacture Date:  ");
    	        gets(e[count-1].mfg_date);
    	        gotoxy(45,17);
    	        printf("Enter New Expiry Date:  ");
    	        gets(e[count-1].exp_date);
    	        
    	        strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    e[count-1].max=e1.max; 
			    e[count-1].totalcostam==e1.totalcostam;	
    	        break;
    	
    	        case 7 :
    	        gotoxy(45,15);
    	        fflush(stdin);
    	        printf("Enter New Purchased Date:  ");
    	        gets(e[count-1].purchased_date);
    	        
    	        strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date);
			    strcpy(e[count-1].exp_date,e1.exp_date);
			    e[count-1].max=e1.max; 
			    e[count-1].totalcostam==e1.totalcostam;		
    	        break;
    	        
    	        case 8:
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New manufacture Name:  ");
    	        gets(e[count-1].manufacture_name);
    	        gotoxy(45,17);
    	        printf("Enter New Contact no. :  ");
    	        gets(e[count-1].manufacture_contact);
    	        
    	        strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    strcpy(e[count-1].mfg_date,e1.mfg_date);
			    strcpy(e[count-1].exp_date,e1.exp_date);
			    e[count-1].quantity=e1.quantity;
			    e[count-1].max=e1.max; 
			    e[count-1].totalcostam==e1.totalcostam;		
    	        break;
    	        
    	        case 9:
    	        fflush(stdin);
    	        gotoxy(45,15);
    	        printf("Enter New Shipping company Name :  ");
    	        gets(e[count-1].shipping_company);
    	        gotoxy(45,17);
    	        printf("Enter New Contact No. :  ");
    	        gets(e[count-1].contact_no);
    	        strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
    	        strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category); 
			    strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact);
				strcpy(e[count-1].mfg_date,e1.mfg_date);
			    strcpy(e[count-1].exp_date,e1.exp_date); 
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
			    strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    e[count-1].max=e1.max; 
			    e[count-1].totalcostam==e1.totalcostam;		
    	        break;
    	
    	        case 10:
    	        fflush(stdin);
    	        gotoxy(45,13);
    	        printf("Enter New ID:  ");
    	        gets(ids1);
    	        //fp2=fopen("inventory.dat","rb");
	            while(fread(&e0, sizeof(info),1,fp2))
	            {	
	                if(strcmp(e0.product_id,ids1)==0)                      
	                {
	    	            gotoxy(xc+5,18);
	    	            printf("ID %s is alreday taken",ids1);
	    	            gotoxy(xc+5,19);
	                	printf("Choose another ID");
	                	gotoxy(xc,20);
	    	            printf("Press Any Key To Continue");
	    	            getch();
	    	            goto l1;     
	                }
	            }
	            strcpy(e[count-1].product_id,ids1);
    	        gotoxy(45,15);
    	        printf("Enter new Name:  ");
                fflush(stdin);
    	        gets(e[count-1].product_name);
    	        gotoxy(45,17);
    	        printf("Enter New quantity:  ");
    	        scanf("%d",&e[count-1].quantity);
    	        gotoxy(45,19);
    	        fflush(stdin);
    	        printf("Enter New cost price:  ");
    	        scanf("%f",&e[count-1].cost_price);
    	        gotoxy(45,21);
    	        printf("Enter New Sales price:  ");
    	        scanf("%f",&e[count-1].sales_price);
    	        fflush(stdin);
    	        gotoxy(45,23);
    	        printf("Enter New Product Category : ");
    	        gets(e[count-1].product_category);
    	        gotoxy(45,25);
    	        printf("Enter New manufacture Date:  ");
    	        gets(e[count-1].mfg_date);
    	        gotoxy(45,27);
    	        fflush(stdin);
    	        printf("Enter New Expiry Date:  ");
    	        gets(e[count-1].exp_date);
    	        gotoxy(45,29);
    	        fflush(stdin);
    	        printf("Enter New Purchased Date:  ");
    	        gets(e[count-1].purchased_date);
    	        gotoxy(45,31);
    	        printf("Enter New manufacture Name:  ");
    	        gets(e[count-1].manufacture_name);
    	        gotoxy(45,33);
    	        printf("Enter New Contact no. :  ");
    	        gets(e[count-1].manufacture_contact);
    	        gotoxy(45,35);
    	        printf("Enter New Shipping company Name :  ");
    	        gets(e[count-1].shipping_company);
    	        gotoxy(45,37);
    	        printf("Enter New Contact No. :  ");
    	        gets(e[count-1].contact_no);
    	        gotoxy(45,39);
    	        printf("Enter New Purchase Limit : ");
    	        scanf("%d",&e[count-1].max);
    	        break;
    	        
    	        case 11:
    	        gotoxy(45,15);
    	        printf("Enter New Purchase Limit : ");
    	        scanf("%d",&e[count-1].max);
    	        strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
		    	strcpy(e[count-1].product_name,e1.product_name);
		    	strcpy(e[count-1].product_category,e1.product_category); 
		    	strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			    strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			    strcpy(e[count-1].shipping_company,e1.shipping_company);
			    strcpy(e[count-1].contact_no,e1.contact_no);
			    e[count-1].cost_price=e1.cost_price; 
			    e[count-1].sales_price=e1.sales_price;
		    	strcpy(e[count-1].purchased_date,e1.purchased_date); 
			    e[count-1].quantity=e1.quantity;
			    strcpy(e[count-1].mfg_date,e1.mfg_date); 
			    strcpy(e[count-1].exp_date,e1.exp_date);
			    e[count-1].totalcostam==e1.totalcostam;	
			    break;
    	
    	        default:
    	        printf("Please choose correct option!");	        
	        } 
	        fwrite(&e[count-1],sizeof (info),1,fp1);  
	    } 
		
		else
		{
			strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
			strcpy(e[count-1].product_name,e1.product_name);
			strcpy(e[count-1].product_category,e1.product_category); 
			strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			strcpy(e[count-1].shipping_company,e1.shipping_company);
			strcpy(e[count-1].contact_no,e1.contact_no);
			e[count-1].cost_price=e1.cost_price; 
			e[count-1].sales_price=e1.sales_price;
			strcpy(e[count-1].purchased_date,e1.purchased_date); 
			e[count-1].quantity=e1.quantity;
			strcpy(e[count-1].mfg_date,e1.mfg_date); 
			strcpy(e[count-1].exp_date,e1.exp_date);
			e[count-1].max=e1.max; 
			e[count-1].totalcostam==e1.totalcostam;	
			 
			fwrite(&e[count-1],sizeof (info),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	if(found)                                                                //if found removing previous original file and renaming temp file  original  
	{
		system("cls");
		name();
		gotoxy(72+15,20);
		printf("Successfully Updated the Detail !");
		gotoxy(72+18,21);
		printf(" Press any key to continue.");
		remove("inventory.dat");
		rename("temp3.dat","inventory.dat");	   
	}
	
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(72+21,20);
		printf("Product not found!!\a");
		gotoxy(65+21,21);
		printf("Press Any Key to Go Back To Menu ");
		remove("temp3.dat");
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);	
	remove("temp3.dat");
	getch();
}

void zero_product()                //press 11                                                                //  function for displaying Zero Quantity items
{
	
	system("cls");
	char ids[10];
	info e1;
	FILE *fp;
	int a=17,c=18,found=0,j;
	fp= fopen("inventory.dat","rb");
	// Top Border
	gotoxy(8,13);
	for(j=0; j<100+99; j++)
    printf("%c", 205);
    // Top Border
    gotoxy(8,16);
	for(j=0; j<100+99; j++)
    printf("%c", 205);
    // Top left corner
    gotoxy(8,13);
	printf("%c",201);
	// Top Left corner 
    gotoxy(77+130,13);
	printf("%c",187);
	gotoxy(15,15);
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    if(e1.quantity<10)
	    {
		    // left Border
	        for(j=14;j<=c;j++)
	        {
		        gotoxy(77+130,j);
		        printf("%c",186);
	        }
	        //Right Border
	        for(j=14;j<=c;j++)
	        {
		       gotoxy(8,j);
		       printf("%c",186);
	        }
	    	found=1;
	    	printf("\a");	
	    	gotoxy(10,14);
	        printf("ID.\t|\t NAME\t|\t CATEGORY\t|\t QUANTITY\t|\t MANUFACTURER \t|\t CONTACT NO: \t|\t SHIPPING COMPANY \t|\t CONTACT NO: \t|\t COST PRICE \t");
		    gotoxy(10,a);
		    printf("%s",strupr(e1.product_id));
		    gotoxy(25,a);
		    printf("%s",strupr(e1.product_name));
		    gotoxy(40,a);
		    printf("%s",strupr(e1.product_category));
		    gotoxy(65,a);
		    printf("%d",e1.quantity);
		    gotoxy(55+35,a);
		    printf("%s",strupr(e1.manufacture_name));
		    gotoxy(55+60,a);
		    printf("%s",strupr(e1.manufacture_contact));
		    gotoxy(55+55+30,a);
		    printf("%s",strupr(e1.shipping_company));
		    gotoxy(55+55+60,a);
		    printf("%s",strupr(e1.contact_no));
		    gotoxy(55+55+84,a);
		    printf("%f",e1.cost_price);
		
			a+=2;
			c+=2;
			gotoxy(9,c-2);
			for(j=0; j<100+98; j++)
    		printf("%c", 205);
		}
		    // Bottom left corner
    		gotoxy(8,c-2);
			printf("%c",200);
			// Bottom Left corner 
    		gotoxy(77+130,c-2);
			printf("%c",188);
			gotoxy(9,c-2);
			for(j=0; j<100+98; j++)
    		printf("%c", 205);
		if(!found)
		printf("NO Products ");
	}	
	fclose(fp);
	getch();
}

void total_sold()
{
	system("cls");
	info e,e1,i1;
	FILE *fp,*fp1;
	int i,n,max=0,min=0,ch,a=17,found=0,count=0;
	char ids[15];
    fp=fopen("Sales Report.dat","ab+");
    while(fread(&i1, sizeof(info),1,fp))
    {
    	printf("%s  ",i1.sold_product_id);
    	printf("%d",i1.total_sold_quantity);
    	printf("\n");
    }
    
    fclose(fp);
    getch();
}

void sales_report()        //press 12                                                               //  function for sales report 
{
	int opt;
	do{	
	system("cls");
	name();
	gotoxy(xc,14);
	printf("Press \n");
	gotoxy(xc,15);
	printf("1.) To make a sale \n");
	gotoxy(xc,16);
	printf("2.) To view Sales Report \n");
	gotoxy(xc,17);
	printf("3.) To edit the Report \n");
	gotoxy(xc,18);
	printf("4.) To find Profit or loss \n");
	gotoxy(xc,19);
	printf("5.) To Delete an Sale Report \n");
	gotoxy(xc,21);
	printf("Choose your option:  ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
		make_sale();
		break;
    
        case 2:
        display_sale();
	    break;
	    
	    case 3:
	    edit_sale();
	    break;
	    
	    case 4:
	    profit_loss();
	    break;
	    
	    case 5:
	    delete_sale();
	    break;
    
    }
	}while(opt!=0); 	
}



void make_sale()                                                                //  function for making a sale 
{
	system("cls");
	name();
	info *e,e0,e1,i1,i2;
	FILE *fp,*fp1,*fp2;
	char ids[15],sale[10];
	float total;
	int a=70+65,sn=0,i,n,found=0,count=0;
	//i1.total_sold_quantity=0;
	gotoxy(xc,14);
	printf("How many product you're selling:  ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		fp=fopen("inventory.dat","ab+");
	    fp1=fopen("Sales Report.dat","ab+");
		if(i>=0)
		system("cls");
		name();
		gotoxy(xc,14);
		printf("For product %d ",i+1);
		fflush(stdin);
		gotoxy(xc,14);
		printf("Enter the ID or Name to make a sale:  ");
	    gets(ids);
	    while(fread(&e1, sizeof(info),1,fp))
	    {	
	        if(strcmp(ids,e1.product_id)==0||strcmp(ids,e1.product_name)==0)
	        {
	            if(e1.quantity>=1)
	            {
	            found=1;
	            sn++;
	            l1:
				system("cls");
	            name1();
	            gotoxy(a,16);
	            printf("Product ID.          %s",strupr(ids));
	            gotoxy(a,17);
	            printf("Product Name         %s",strupr(e1.product_name));
	            gotoxy(a,18);
	            printf("Product Category     %s",strupr(e1.product_category));
	            gotoxy(a,19);
	            printf("Quantity             %d",e1.quantity);
	            gotoxy(a,20);
	            printf("Manufacture Date     %s",strupr(e1.mfg_date));
	            gotoxy(a,21);
	            printf("Expiry Date          %s",strupr(e1.exp_date));
	            gotoxy(a,22); 
	            printf("Cost Price           %.2f",e1.cost_price);
	            gotoxy(a,23); 
	            printf("Sales Price          %.2f",e1.sales_price);
	            gotoxy(45,15);
	            fflush(stdin);
	            printf("Enter Quantity:  ");
	            scanf("%d",&i1.sold_quantity);
	            if(e1.quantity>=i1.sold_quantity)
	            {
	            fflush(stdin);
	            gotoxy(45,17);
	            printf("Enter Sales type: ");
	            gets(sale);
	            if(strcmp(sale,"Retail")==0 ||strcmp(sale,"retail")==0 ||strcmp(sale,"RETAIL")==0 ||strcmp(sale,"R")==0 ||strcmp(sale,"r")==0)
	            strcpy(i1.sales_type,"RETAIL");
	            else
	            strcpy(i1.sales_type,"WHOLESALE");
				fflush(stdin);
	            gotoxy(45,19);
	            printf("Enter discount: ");
	            scanf("%f",&i1.discount);
	            if(i1.discount>0)
	            {
	            	total=i1.sold_quantity*e1.sales_price-(i1.discount/100)*i1.sold_quantity*e1.sales_price; 
				}
				else
				{
					total=i1.sold_quantity*e1.sales_price;
				}
				while(fread(&e0, sizeof(info),1,fp1))
	            {
	            	sn++;	
	                if(strcmp(ids,e0.sold_product_id)==0||strcmp(ids,e0.product_name)==0)
	                {
	                	i1.total_sold_quantity=e0.total_sold_quantity;
	                    i1.total_sold_quantity+=i1.sold_quantity;
					}
	            }
	            fflush(stdin);
	            gotoxy(45,21);
	            printf("Enter Sales Date (DD/MM/YYYY):  ");
	            scanf("%d",&i1.s_day);
	            gotoxy(80,21);
	            printf("/ ");
	            scanf("%d",&i1.s_month);
	            gotoxy(85,21);
	            printf("/ ");
	            scanf("%d",&i1.s_year);	
	            
	            i1.sn=sn;
				i1.total=total;
				i1.totalsoldam+=i1.total;   	
	            strcpy(i1.sold_product_id,e1.product_id);                            //Writing previous data in file
			    strcpy(i1.product_name,e1.product_name);
			    strcpy(i1.product_category,e1.product_category);
					 
	            fwrite(&i1,sizeof (info),1,fp1);
				}
				else
				{
				    gotoxy(45,18);
				    printf("\a Product Out Of Stock");
				    getch();
				    goto l1;
				}
						
				}
				else
				{
					gotoxy(72,20);
					printf("\a No Stock Available !!");
					getch();
				}
			}   	  
	    }
	    fclose(fp);
	    fclose(fp1);
	        
	    if(found)
	    {
	        fp=fopen("inventory.dat","rb");
	        fp1=fopen("temp8.dat","ab+");
	        while(fread(&e1, sizeof(info),1,fp))
	        {
	        	count ++;
	            e = (info*)calloc(count,sizeof(info));
	                
	        if(strcmp(e1.product_id,i1.sold_product_id)==0)
	        {
	            e[count-1].quantity=e1.quantity-i1.sold_quantity;
	            e[count-1].sold_quantity = i1.sold_quantity;
	            //e[count-1].total_sold_quantity=i1.sold_quantity+i1.old_sold_quantity;
			}
	                
	        else
	        {
	            e[count-1].quantity=e1.quantity;
	            e[count-1].sold_quantity=e1.sold_quantity;
			}
			e[count-1].total_sold_quantity=i1.total_sold_quantity;	               strcpy(e[count-1].product_id,e1.product_id);                            //Writing previous data in file
			strcpy(e[count-1].product_name,e1.product_name);
			strcpy(e[count-1].product_category,e1.product_category); 
			strcpy(e[count-1].manufacture_name,e1.manufacture_name);
			strcpy(e[count-1].manufacture_contact,e1.manufacture_contact); 
			strcpy(e[count-1].shipping_company,e1.shipping_company);
			strcpy(e[count-1].contact_no,e1.contact_no);
			e[count-1].cost_price=e1.cost_price; 
			e[count-1].sales_price=e1.sales_price;
			strcpy(e[count-1].purchased_date,e1.purchased_date); 
			strcpy(e[count-1].mfg_date,e1.mfg_date); 
			strcpy(e[count-1].exp_date,e1.exp_date);
			e[count-1].max=e1.max;  
			e[count-1].totalcostam=e1.totalcostam;	
		    		
			fwrite(&e[count-1],sizeof (info),1,fp1); 
		}
		fclose(fp);
		fclose(fp1);
		remove("inventory.dat");
		rename("temp8.dat","inventory.dat");
	    }
	       
	    if(!found)
	    {
	        system("cls");
	        name();
	        gotoxy(75+20,20);
		    printf("Product not found!!\a");
		    gotoxy(75+15,21);
	        printf("Press Any Key to Go Back To Menu ");
	        fclose(fp);
            fclose(fp1);
	        getch();
		}
	fclose(fp);
    fclose(fp1);
    }      
    getch();
}

void monthly_report()
{
	system("cls");
	name();
	info e,e1,i1;
	FILE *fp,*fp1;
	int ms,j,a=18,c=19;
	char mn;
	fp=fopen("Sales Report.dat","rb");
	gotoxy(xc,14);
    printf("Enter the Month To View The Report ");
    scanf("%d",&ms);
    system("cls");
    while(fread(&i1, sizeof(info),1,fp))
    {
    	if(ms==i1.s_month)
    	{
    		switch(ms){
		    case 1:
		    gotoxy(25,12);
			printf(" Monthly Sales report of January");
			break;
			case 2:
			gotoxy(25,12);
			printf(" Monthly Sales report of Febraury");
			break;
			case 3:
			gotoxy(25,12);
			printf(" Monthly Sales report of March");
			break;
			case 4:
			gotoxy(25,12);
			printf(" Monthly Sales report of April");
			break;
			case 5:
			gotoxy(25,12);
			printf(" Monthly Sales report of May");
			break;
			case 6:
			gotoxy(25,12);
			printf(" Monthly Sales report of June");
			break;
			case 7:
			gotoxy(25,12);
			printf(" Monthly Sales report of July");
			break;
			case 8:
			printf(" Monthly Sales report of August");
		    gotoxy(25,12);
			break;
			case 9:
			gotoxy(25,12);
			printf(" Monthly Sales report of September");
			break;
			case 10:
			gotoxy(25,12);
			printf(" Monthly Sales report of October");
			break;
			case 11:
			gotoxy(25,12);
			printf(" Monthly Sales report of November");
			break;
			case 12:
			gotoxy(25,12);
			printf(" Monthly Sales report of December");
			break;}
    	    // Top border
    	    gotoxy(25,14);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top border 
    	    gotoxy(25,16);
     	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top Left corner
    	    gotoxy(25,14);
    	    printf("%c",201);
    	    // Top Right Corner
    	    gotoxy(117+65,14);
    	    printf("%c",187);
    	    
    	    gotoxy(26,15);
            printf("  SALE NO: | \t ID. | \t PRODUCT NAME \t | \t QUANTITY \t | \t SALES TYPE \t | \t DICCOUNT \t | \t SALES DATE  \t | \t Total \t ");
    		// Left border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(25,j);
    	        printf("%c",186);
			}
    	    // Right border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(117+65,j);
    	        printf("%c",186);
			}
    	    gotoxy(28,a);
    	    printf("%d",i1.sn);
            gotoxy(40,a);
            printf("%s",strupr(i1.sold_product_id));
            gotoxy(50,a);
            printf("%s",strupr(i1.product_name));
            gotoxy(75,a);
            printf("%d",i1.sold_quantity);
            gotoxy(55+42,a);
            if(strcmp(i1.sales_type,"Retail")==0 ||strcmp(i1.sales_type,"retail")==0 ||strcmp(i1.sales_type,"RETAIL")==0 ||strcmp(i1.sales_type,"R")==0 ||strcmp(i1.sales_type,"r")==0)
            printf("RETAIL");
            else
            printf("WHOLESALE");
            gotoxy(57+65,a);
            printf("%.2f%%",i1.discount);
            gotoxy(57+55+33,a);
            printf("%d / %d / %d",i1.s_day,i1.s_month,i1.s_year);
            gotoxy(80+55+35,a);
            printf("%.2f",i1.total);
            gotoxy(25,c);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",95);
    	    
			a+=2;
    	    c+=2;   
		}
    }
    // Bottom border 
    gotoxy(25,c-2);
    for(j=0;j<100+57;j++)
    printf("%c",205);
    // Bottom Left corner
    gotoxy(25,c-2);
    printf("%c",200);
    // Bottom Right Corner
    gotoxy(117+65,c-2);
    printf("%c",188);
}

void yearly_report()
{
	
	system("cls");
	name();
	info e,e1,i1;
	FILE *fp,*fp1;
	int ms,j,a=18,c=19;
	char mn;
	fp=fopen("Sales Report.dat","rb");
	gotoxy(xc,14);
    printf("Enter the Year To View The Report ");
    scanf("%d",&ms);
    system("cls");
    while(fread(&i1, sizeof(info),1,fp))
    {
    	if(ms==i1.s_year)
    	{	
    	    gotoxy(25,12);
		    printf(" Year %d ",ms);
    	    // Top border
    	    gotoxy(25,14);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top border 
    	    gotoxy(25,16);
     	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top Left corner
    	    gotoxy(25,14);
    	    printf("%c",201);
    	    // Top Right Corner
    	    gotoxy(117+65,14);
    	    printf("%c",187);
    	    
    	    gotoxy(26,15);
            printf("  SALE NO: | \t ID. | \t PRODUCT NAME \t | \t QUANTITY \t | \t SALES TYPE \t | \t DICCOUNT \t | \t SALES DATE  \t | \t Total \t ");
    		// Left border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(25,j);
    	        printf("%c",186);
			}
    	    // Right border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(117+65,j);
    	        printf("%c",186);
			}
    	    gotoxy(28,a);
    	    printf("%d",i1.sn);
            gotoxy(40,a);
            printf("%s",strupr(i1.sold_product_id));
            gotoxy(50,a);
            printf("%s",strupr(i1.product_name));
            gotoxy(75,a);
            printf("%d",i1.sold_quantity);
            gotoxy(55+42,a);
            if(strcmp(i1.sales_type,"Retail")==0 ||strcmp(i1.sales_type,"retail")==0 ||strcmp(i1.sales_type,"RETAIL")==0 ||strcmp(i1.sales_type,"R")==0 ||strcmp(i1.sales_type,"r")==0)
            printf("RETAIL");
            else
            printf("WHOLESALE");
            gotoxy(57+65,a);
            printf("%.2f%%",i1.discount);
            gotoxy(57+55+33,a);
            printf("%d / %d / %d",i1.s_day,i1.s_month,i1.s_year);
            gotoxy(80+55+35,a);
            printf("%.2f",i1.total);
            gotoxy(25,c);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",95);
    	    
			a+=2;
    	    c+=2;   
		}
    }
    // Bottom border 
    gotoxy(25,c-2);
    for(j=0;j<100+57;j++)
    printf("%c",205);
    // Bottom Left corner
    gotoxy(25,c-2);
    printf("%c",200);
    // Bottom Right Corner
    gotoxy(117+65,c-2);
    printf("%c",188);

    //getch();
    //display_sale();
    fclose(fp);

}

void display_sale()                                                                //  function for displaying sales report
{
	
	info e,e1,i1;
	FILE *fp,*fp1;
	int i,n,max=0,min=0,ch,found=0,count=0;
	
	char ids[15];
	do{
	int j,a=18,c=19;
	system("cls");
	name();
    fp=fopen("Sales Report.dat","rb");
    //e1.sold_quantity=0;	
    gotoxy(xc,14);
    printf("Press:\n");
    gotoxy(xc,15);
    printf("0.) To Go Back To Main Menu !!");
    gotoxy(xc,16);
    printf("1.) To view all Report ");
    gotoxy(xc,17);
    printf("2.) To view Retail sales ");
    gotoxy(xc,18);
    printf("3.) To view Wholesale sales ");
    gotoxy(xc,19);
    printf("4.) Highest Sale ");
    gotoxy(xc,20);
	printf("5.) Lowest Sale ");
	gotoxy(xc,21);
	printf("6.) Unsold Product ");
	gotoxy(xc,22);
	printf("7.) Monthly sale ");
	gotoxy(xc,23);
	printf("8.) Yearly Sale ");
	
	gotoxy(xc,25);
    printf("Choice==> ");
    scanf("%d",&ch); 
    if(ch==1)                                                          //displays all reports
    {
    	system("cls");
    	
        while(fread(&i1, sizeof(info),1,fp))
        {	// Top border
    	    gotoxy(25,14);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top border 
    	    gotoxy(25,16);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",205);
    	    // Top Left corner
    	    gotoxy(25,14);
    	    printf("%c",201);
    	    // Top Right Corner
    	    gotoxy(117+65,14);
    	    printf("%c",187);
     	
    	    gotoxy(26,15);
            printf("  SALE NO: | \t ID. | \t PRODUCT NAME \t | \t QUANTITY \t | \t SALES TYPE \t | \t DICCOUNT \t | \t SALES DATE  \t | \t Total \t ");
            // Left border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(25,j);
    	        printf("%c",186);
			}
    	    // Right border 
    	    for(j=15;j<=c;j++)
        	{
        		gotoxy(117+65,j);
    	        printf("%c",186);
			}
    	    gotoxy(28,a);
    	    printf("%d",i1.sn);
            gotoxy(40,a);
            printf("%s",strupr(i1.sold_product_id));
            gotoxy(50,a);
            printf("%s",strupr(i1.product_name));
            gotoxy(75,a);
            printf("%d",i1.sold_quantity);
            gotoxy(55+42,a);
            if(strcmp(i1.sales_type,"Retail")==0 ||strcmp(i1.sales_type,"retail")==0 ||strcmp(i1.sales_type,"RETAIL")==0 ||strcmp(i1.sales_type,"R")==0 ||strcmp(i1.sales_type,"r")==0)
            printf("RETAIL");
            else
            printf("WHOLESALE");
            gotoxy(57+65,a);
            printf("%.2f%%",i1.discount);
            gotoxy(57+55+33,a);
            printf("%d / %d / %d",i1.s_day,i1.s_month,i1.s_year);
            gotoxy(80+55+35,a);
            printf("%.2f",i1.total);
            gotoxy(25,c);
    	    for(j=0;j<100+57;j++)
    	    printf("%c",95);
            
			a+=2;
			c+=2;
			// Bottom border 
            gotoxy(25,c-2);
            for(j=0;j<100+57;j++)
            printf("%c",205);
            // Bottom Left corner
            gotoxy(25,c-2);
            printf("%c",200);
            // Bottom Right Corner
            gotoxy(117+65,c-2);
            printf("%c",188);
            //getch();	        
    	}
   }
    
   if(ch==2)                                                          //displays report if Sales Type is Retail
    {
    	system("cls");
    	gotoxy(28,12);
    	printf("RETAIL SALE");
    	a=18,c=19;
	    while(fread(&i1, sizeof(info),1,fp))
        {
        	if(strcmp(i1.sales_type,"Retail")==0 ||strcmp(i1.sales_type,"retail")==0 ||strcmp(i1.sales_type,"RETAIL")==0 ||strcmp(i1.sales_type,"R")==0 ||strcmp(i1.sales_type,"r")==0)
        	{
        		// Top border
          	    gotoxy(28,14);
    	        for(j=0;j<110;j++)
            	printf("%c",205);
    	        // Top border 
            	gotoxy(28,16);
    	        for(j=0;j<110;j++)
    	        printf("%c",205);
    	        // Top Left corner
    	        gotoxy(28,14);
    	        printf("%c",201);
    	        // Top Right Corner
    	        gotoxy(110+28,14);
    	        printf("%c",187);
        		 // Left border 
    	        for(j=15;j<=c;j++)
        	    {
        		    gotoxy(28,j);
    	            printf("%c",186);
			    }
    	        // Right border 
    	        for(j=15;j<=c;j++)
        	    {
        		    gotoxy(110+28,j);
    	            printf("%c",186);
			    }
    	    
        		gotoxy(30,15);
                printf("ID. \t|\t PRODUCT NAME t|\t QUANTITY \t|\t DICCOUNT \t|\t SALES DATE  \t");
        		gotoxy(30,a);
                printf("%s",strupr(i1.sold_product_id));
            	gotoxy(45,a);
                printf("%s",strupr(i1.product_name));
            	gotoxy(75,a);
            	printf("%d",i1.sold_quantity);
                gotoxy(55+42,a);
                printf("%f",i1.discount);
            	gotoxy(55+64,a);
                printf("%d / %d / %d",i1.s_day,i1.s_month,i1.s_year);
                gotoxy(30,c);
    	        for(j=0;j<110;j++)
    	        printf("%c",95);
			    a+=2;
				c+=2;			        
            }
    	}
    	// Bottom border 
        gotoxy(29,c-2);
        for(j=0;j<109;j++)
        printf("%c",205);
        // Bottom Left corner
        gotoxy(28,c-2);
        printf("%c",200);
        // Bottom Right Corner
        gotoxy(110+28,c-2);
        printf("%c",188);
        //getch();
   }
   
   if(ch==3)                                                          //displays report if Sales Type is Wholesale
    {
    	system("cls");
    	gotoxy(28,12);
    	printf("WHOLESALE SALE");
    	a=18,c=19;
        while(fread(&i1, sizeof(info),1,fp))
        {
        	if(strcmp(i1.sales_type,"WHOLESALE")==0 ||strcmp(i1.sales_type,"Wholesale")==0 ||strcmp(i1.sales_type,"wholesale")==0 ||strcmp(i1.sales_type,"W")==0 ||strcmp(i1.sales_type,"w")==0)
        	{
        		// Top border
          	    gotoxy(28,14);
    	        for(j=0;j<110;j++)
            	printf("%c",205);
    	        // Top border 
            	gotoxy(28,16);
    	        for(j=0;j<110;j++)
    	        printf("%c",205);
    	        // Top Left corner
    	        gotoxy(28,14);
    	        printf("%c",201);
    	        // Top Right Corner
    	        gotoxy(110+28,14);
    	        printf("%c",187);
        		 // Left border 
    	        for(j=15;j<=c;j++)
        	    {
        		    gotoxy(28,j);
    	            printf("%c",186);
			    }
    	        // Right border 
    	        for(j=15;j<=c;j++)
        	    {
        		    gotoxy(110+28,j);
    	            printf("%c",186);
			    }
			    
        		gotoxy(30,15);
                printf("ID. \t|\t PRODUCT NAME t|\t QUANTITY \t|\t DICCOUNT \t|\t SALES DATE  \t");
        		gotoxy(30,a);
                printf("%s",strupr(i1.sold_product_id));
            	gotoxy(50,a);
                printf("%s",strupr(i1.product_name));
            	gotoxy(75,a);
            	printf("%d",i1.sold_quantity);
                gotoxy(55+42,a);
                printf("%f",i1.discount);
            	gotoxy(55+64,a);
                printf("%d / %d / %d",i1.s_day,i1.s_month,i1.s_year);
                gotoxy(28,c);
    	        for(j=0;j<110;j++)
    	        printf("%c",95);
			    a+=2;
				c+=2;	
				// Bottom border 
                gotoxy(29,c-2);
                for(j=0;j<109;j++)
                printf("%c",205);
                // Bottom Left corner
                gotoxy(28,c-2);
                printf("%c",200);
                // Bottom Right Corner
                gotoxy(110+28,c-2);
                printf("%c",188); 
                //getch();		        
            }
    	}    
    }
    
    fclose(fp);
    fp=fopen("Sales Report.dat","rb");
	while(fread(&e1,sizeof(info),1,fp))
	{
		max=min=e1.sold_quantity;
	}
	fclose(fp);
	
		if(ch==4)                                                                  // displays Highest sold products
		{
			system("cls");
		    fp=fopen("Sales Report.dat","rb");
	        //fp1=fopen("inventory.dat","rb");
	        while(fread(&e1,sizeof(info),1,fp))
	        {
		    if(max<e1.sold_quantity)
		    {
		    	gotoxy(30,15);
                printf("ID. \t|\t PRODUCT NAME \t|\t QUANTITY \t|");
		    	gotoxy(30,a);
                printf("%s",strupr(e1.sold_product_id));
                gotoxy(50,a);
                printf("%s",strupr(e1.product_name));
                gotoxy(75,a);
                printf("%d",e1.sold_quantity);
                gotoxy(xc+42,a);

			    a+=2;
		    }
		  }
	    }
		    
		if(ch==5)                                                                   // displays Least sold products
		{
			system("cls");
			fp=fopen("Sales Report.dat","rb");
			fp1=fopen("inventory.dat","rb");
			while(fread(&e1,sizeof(info),1,fp))
			{
		    if(min>=e1.sold_quantity)
		    {
		    	gotoxy(30,15);
                printf("ID. \t|\t PRODUCT NAME \t|\t QUANTITY \t|");
		    	gotoxy(30,a);
                printf("%s",strupr(e1.sold_product_id));
                gotoxy(50,a);
                printf("%s",strupr(e1.product_name));
                gotoxy(75,a);
                printf("%d",e1.sold_quantity);
                gotoxy(xc+42,a);
			    a+=2;
		    }
		  }
	    }
		
		if(ch==6)                                                                   // displays unsold products
		{
			system("cls");
			fp=fopen("Sales Report.dat","rb");
			fp1=fopen("inventory.dat","rb");
			while(fread(&e1,sizeof(info),1,fp))
			{
			while(fread(&e,sizeof(info),1,fp1))
			{
			    if(e.sold_quantity==0)
			    {    
			        //printf("\a");
				    gotoxy(30,15);
                    printf("ID. \t|\t PRODUCT NAME \t|\t QUANTITY \t|");
		    	    gotoxy(30,a);
                    printf("%s",strupr(e.product_id));
                    gotoxy(50,a);
                    printf("%s",strupr(e.product_name));
                    gotoxy(75,a);
                    if(e.sold_quantity==0)
                    printf("NULL");
                     
                    else
                    printf("%d",e.sold_quantity);

                    a+=2;
		    	}
		      }
		   }
        }
    //getch();
    if(ch==7)
    {
    	monthly_report();
	}
	if(ch==8)
    {
    	yearly_report();
	}
	fclose(fp);
//	fclose(fp1);
	getch();
	}while(ch!=0);
}

void total_sold_product()   // press 9                                                              // To display total Sales Report in the inventory 
{
	system("Cls");
	name();
	gotoxy(xc,14);
	info i1;
	FILE *fp;
	fp=fopen("Sales Report.dat","rb");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof (info);
	printf("Total number of products= %d",n);
	fclose(fp);
	getch();
}

void delete_sale()
{
	info i1;
	FILE *fp,*fp1;
	int found=0,ids;
	fflush(stdin);
	system("Cls");
	name();
	gotoxy(xc,14);
	printf("Enter the Sale No: ");
	scanf("%d",&ids);
	fp=fopen("Sales Report.dat","rb");
	fp1=fopen("temp.dat","wb");	
	gotoxy(xc,15);
	while(fread(&i1, sizeof(info),1,fp))
	{	
	    if(ids==i1.sn)
	    found=1;
	    
	    else
	    fwrite(&i1,sizeof(info),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	
	if(found)
	{
		fp1=fopen("temp.dat","rb");
		fp=fopen("Sales REport.dat","wb+");
		
	    while(fread(&i1, sizeof(info),1,fp1))
	    fwrite(&i1,sizeof(info),1,fp);
	    printf("PRODUCT DETAIL SUCESSFULLY DELETED");
	}
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(72,20);
		printf("Product not found!!\a");
		gotoxy(65,21);
		printf("Press Any Key to Go Back To Menu ");
		
	}
	fclose(fp1);
	fclose(fp);
	remove("temp.dat");
	getch();	
}

void edit_sale()                                                                //  function for editing sales report
{
	system("cls");
	name();
	FILE *fp,*fp1,*fp3;
	info *e,e1,e3;
	int i,n,found=0,count=0,opt,a=70+65,b=55,ids;
	fp=fopen("Sales Report.dat","rb");
	fp1=fopen("temp6.dat","wb");
	fp3=fopen("inventory.dat","rb");
	gotoxy(xc,15);
	printf("Enter the Sale Number :  ");
	scanf("%d",&ids);
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    count++;
	    e = (info*)calloc(count,sizeof(info));
	    if(ids==e1.sn)
	    {	
	        found=1;
	        system("cls");
		    name1();
		    gotoxy(a,14);
		    printf("Old Details ");
		    gotoxy(a,15);
	        printf("Quantity     %d",e1.sold_quantity);
	        gotoxy(a,16);
	        printf("Sales Type   %s",e1.sales_type);
	        gotoxy(a,17);
	        printf("Discount     %.2f",e1.discount);
	        gotoxy(a,18);
	        printf("Sales Date   %d / %d / %d",e1.s_day,e1.s_month,e1.s_year);
	    	gotoxy(b,15);
	    	printf("press \n");
	    	gotoxy(b,16);
	    	printf("1.) To edit Quantity \n");
	    	gotoxy(b,17);
	    	printf("2.) To edit Sales Type  \n");
	    	gotoxy(b,18);
	    	printf("3.) To edit Discount \n");
	    	gotoxy(b,19);
	    	printf("4.) To edit Sales Date \n");
	    	gotoxy(b,20);
	    	printf("5.) To edit Every Details \n");
	    	gotoxy(b,22);
	    	printf("choice ==>");
	    	scanf("%d",&opt);
	    	system("cls");
		    name1();
		    gotoxy(a,15);
	        printf("Quantity     %d",e1.sold_quantity);
	        gotoxy(a,16);
	        printf("Sales Type   %s",e1.sales_type);
	        gotoxy(a,17);
	        printf("Discount     %d",e1.discount);
	        gotoxy(a,18);
	        printf("Sales Date   %d / %d / %d",e1.s_day,e1.s_month,e1.s_year);
	    	switch(opt)
	    	{
	    		case 1:
	    		fflush(stdin);
	    		gotoxy(xc,15);
	    		printf("Enter NEW Quantity: ");
	    		scanf("%d",&e[count-1].sold_quantity);
	    		
	    		strcpy(e[count-1].sold_product_id,e1.sold_product_id);                            //Writing previous data in file
				strcpy(e[count-1].product_name,e1.product_name);
				strcpy(e[count-1].product_category,e1.product_category);
	    		e[count-1].discount=e1.discount;
				strcpy(e[count-1].sales_type,e1.sales_type);
				e[count-1].s_day=e1.s_day;
				e[count-1].s_month=e1.s_month;
				e[count-1].s_year=e1.s_year;
				e[count-1].sn=e1.sn;
				e[count-1].totalsoldam=e1.totalsoldam;
				while(fread(&e3, sizeof(info),1,fp3)){
				if(strcmp(e1.sold_product_id,e3.product_id)==0){
					if(e1.discount>0)
	            {
	            	e[count-1].total=e[count-1].sold_quantity*e3.sales_price-(e1.discount/100)*e[count-1].sold_quantity*e3.sales_price; 
				}
				else
				{
					e[count-1].total=e[count-1].sold_quantity*e3.sales_price;
				}
			    }}
				break;
	    		
	    		case 2:
	    		gotoxy(b,15);
	    		fflush(stdin);
	    		printf("Enter NEW Sales Type: ");
	    		gets(e[count-1].sales_type);
	    		
	    		strcpy(e[count-1].sold_product_id,e1.sold_product_id);                            //Writing previous data in file
				strcpy(e[count-1].product_name,e1.product_name);
				strcpy(e[count-1].product_category,e1.product_category);
	    		e[count-1].sold_quantity=e1.sold_quantity;
	    		e[count-1].discount=e1.discount;
				e[count-1].s_day=e1.s_day;
				e[count-1].s_month=e1.s_month;
				e[count-1].s_year=e1.s_year;
				e[count-1].sn=e1.sn;
				e[count-1].totalsoldam=e1.totalsoldam;   	
	    		break;
	    		
	    		case 3:
                fflush(stdin);
	    		gotoxy(b,15);
	    		printf("Enter NEW Discount: ");
	    		scanf("%f",&e[count-1].discount);
	    		
	    		strcpy(e[count-1].sold_product_id,e1.sold_product_id);                            //Writing previous data in file
				strcpy(e[count-1].product_name,e1.product_name);
				strcpy(e[count-1].product_category,e1.product_category);
	    		e[count-1].sold_quantity=e1.sold_quantity;
				strcpy(e[count-1].sales_type,e1.sales_type);
				e[count-1].s_day=e1.s_day;
				e[count-1].s_month=e1.s_month;
				e[count-1].s_year=e1.s_year;
				e[count-1].sn=e1.sn;
				e[count-1].totalsoldam=e1.totalsoldam;  
				while(fread(&e3, sizeof(info),1,fp3)){
				if(strcmp(e1.sold_product_id,e3.product_id)==0){
					if(e1.discount>0)
	            {
	            	e[count-1].total=e1.sold_quantity*e3.sales_price-(e[count-1].discount/100)*e1.sold_quantity*e3.sales_price; 
				}
				else
				{
					e[count-1].total=e1.sold_quantity*e3.sales_price;
				}
			    }} 
	    		break;
	    		
	    		case 4:
	    		fflush(stdin);
	    		gotoxy(b,15);
	    		fflush(stdin);
	    		printf("Enter NEW Sales Date: ");
	    		scanf("%d",&e[count-1].s_day);
	            gotoxy(70,15);
	            printf("/ ");
	            scanf("%d",&e[count-1].s_month);
	            gotoxy(74,15);
	            printf("/ ");
	            scanf("%d",&e[count-1].s_year);	
	    		strcpy(e[count-1].sold_product_id,e1.sold_product_id);                            //Writing previous data in file
				strcpy(e[count-1].product_name,e1.product_name);
				strcpy(e[count-1].product_category,e1.product_category);
	    		e[count-1].sold_quantity=e1.sold_quantity;
	    		e[count-1].discount=e1.discount;
				strcpy(e[count-1].sales_type,e1.sales_type);
				e[count-1].sn=e1.sn; 
				e[count-1].totalsoldam=e1.totalsoldam;  	    		
				break;	  
				
				case 5:	
				fflush(stdin);
	    		gotoxy(b,15);
	    		printf("Enter NEW Quantity: ");
	    		scanf("%d",&e[count-1].sold_quantity);
	    		gotoxy(b,17);
	    		fflush(stdin);
	    		printf("Enter NEW Sales Type: ");
	    		gets(e[count-1].sales_type);
	    		gotoxy(b,19);
	    		printf("Enter NEW Discount: ");
	    		scanf("%f",&e[count-1].discount);	
				gotoxy(b,21);
				fflush(stdin);
				printf("Enter New Sales Date: ");
	    		scanf("%d",&e[count-1].s_day);
	            gotoxy(b+25,21);
	            printf("/ ");
	            scanf("%d",&e[count-1].s_month);
	            gotoxy(b+29,21);
	            printf("/ ");
	            scanf("%d",&e[count-1].s_year);
				
				
				strcpy(e[count-1].sold_product_id,e1.sold_product_id);
			    strcpy(e[count-1].product_name,e1.product_name);
			    strcpy(e[count-1].product_category,e1.product_category);
			    e[count-1].sn=e1.sn; 
			    e[count-1].totalsoldam=e1.totalsoldam;  
			    while(fread(&e3, sizeof(info),1,fp3)){
				if(strcmp(e1.sold_product_id,e3.product_id)==0){
					if(e1.discount>0)
	            {
	            	e[count-1].total=e[count-1].sold_quantity*e3.sales_price-(e[count-1].discount/100)*e[count-1].sold_quantity*e3.sales_price; 
				}
				else
				{
					e[count-1].total=e[count-1].sold_quantity*e3.sales_price;
				}
			    }}
				break;          
	        }	 
	        fwrite(&e[count-1],sizeof (info),1,fp1);	           
        }   
	    else
	    {
	    	strcpy(e[count-1].sold_product_id,e1.sold_product_id);                            //Writing previous data in file
			strcpy(e[count-1].product_name,e1.product_name);
			strcpy(e[count-1].product_category,e1.product_category);
	    	e[count-1].sold_quantity=e1.sold_quantity;
	    	e[count-1].discount=e1.discount;
			strcpy(e[count-1].sales_type,e1.sales_type);
			e[count-1].s_day=e1.s_day;
			e[count-1].s_month=e1.s_month;
			e[count-1].s_year=e1.s_year;
			e[count-1].sn=e1.sn; 
			e[count-1].totalsoldam=e1.totalsoldam; 
			e[count-1].total=e1.total; 	
			
			fwrite(&e[count-1],sizeof (info),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found==1)
	{
		system("cls");
		name();
		gotoxy(82,20);
		printf("Successfully Updated !");
		gotoxy(80,21);
		printf("Press any key to continue.");
		remove("Sales Report.dat");
		rename("temp6.dat","Sales Report.dat");
	}
	
	if(found==0)
	{
		fclose(fp);
	    fclose(fp1);
		system("cls");
	    name();
	    gotoxy(85,20);
		printf("Product not found!!\a");
		gotoxy(80,21);
		printf("Press Any Key to Go Back To Menu ");
		remove("temp6.dat");
		//sleep(2);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp3);
	getch();
}


void order_list()    //  press 13                                                          //  function for making a order list 
{
	info e1,*e,*i1,e2,e5;
	FILE *fp,*fp1,*fp3,*fp0;
	int ch,n,i,count=0,a=16,b=18;
	char ids[10], opt;
	do
	{
	system("cls");
	name();
	gotoxy(xc,14);
	printf("Press \n");
	gotoxy(xc,15);
	printf("0.) To Go BAck To Main MENU !!\n");
	gotoxy(xc,16);
	printf("1.) To View Order list \n");
	gotoxy(xc,17);
	printf("2.) To make an Order list \n");
	gotoxy(xc,18);
	printf("3.) To make order for New Product \n");
	gotoxy(xc,19);
	printf("4.) To edit Order list \n");
	gotoxy(xc,20);
	printf("5.) Delete an item in Order list \n");
	gotoxy(xc,21);
	printf("6.) Total Order list \n\n");
	gotoxy(xc,22);
	printf("Choice==> ");
	scanf("%d",&ch);
	switch(ch)
	{ 
	    case 1:
	    display_orderlist();                                                     // display order list 
	    break;
	
	    case 2:
	    system("cls");
 	    name();
 	    fp0=fopen("inventory.dat","rb+");
 	    fp=fopen("inventory.dat","rb");
	    fp1=fopen("orderlist.dat","ab+");  
	    while(fread(&e5,sizeof(info),1,fp0))
	    {if(e5.quantity<=5)
	    {
	    	gotoxy(xc,b);
	    	printf("Product Name  %s",e5.product_name);
	    	gotoxy(xc+25,b);
	    	printf("Id   %s",e5.product_id);
	    	printf("\n");
	    	b++;
		}
	    }fclose(fp0);
	    b=18;
	    gotoxy(xc,14);
	    //fflush(stdin);
	    printf("Do You Want These Products To Be In Order List (Y/N) : ");
	    gotoxy(xc,15);
	    fflush(stdin);
        scanf("%c",&opt);
	    if(opt=='Y'||opt=='y')
	    {  // if quantity less than certain quantity then product goes to order list
		while(fread(&e1,sizeof(info),1,fp))
	    {
	    	count++;
	    	e= (info*)calloc(count,sizeof(info)); 
	    	if(e1.quantity<=5)
	    	{
	    		fflush(stdin);
	    		strcpy(e[count-1].order_product_id,e1.product_id);
	    		strcpy(e[count-1].order_product_name,e1.product_name);                                 // Copying previous data in file 
	    	    strcpy(e[count-1].order_product_category,e1.product_category);
	    	    e[count-1].order_max_limit=e1.max;
	    	    strcpy(e[count-1].order_manufacture_name,e1.manufacture_name);
	    	    strcpy(e[count-1].order_manufacture_contact,e1.manufacture_contact);
	    	    strcpy(e[count-1].order_shipping_company,e1.shipping_company);
	    	    strcpy(e[count-1].order_contact_no,e1.contact_no);
	    	    strcpy(e[count-1].status,"Pending");	
				fwrite(&e[count-1],sizeof(info),1,fp1); 
			}	
				
	    }
	    gotoxy(85,16);
	    printf("Product Added Sucessfully ");
	    getch();
	    fclose(fp);
	    fclose(fp1);
		}
		fclose(fp);
	    fclose(fp1);
	    break;
	
	    case 3:
		system("cls"); 
	    name();
		gotoxy(xc,14);   
		fflush(stdin);                                                             // for Adding new product (Not available in store) 
		printf("How many Products You want to Add: ");
		scanf("%d",&n);
		i1= (info*)calloc(n,sizeof(info));
	    for(i=0;i<n;i++)
	    {
	    	l1:
	    	system("cls");
	    	name();
			fflush(stdin);
			fp=fopen("inventory.dat","rb");
	        fp1=fopen("orderlist.dat","ab+");
	        gotoxy(xc,14);  
	    	printf("Enter Product ID: ");
	    	scanf("%c",&opt);
	    	while(fread(&e1, sizeof(info),1,fp))                                     // checking if the product ID Exist or not in the Store
	        {	
	            if(strcmp(e1.product_id,ids)==0)
	            {
	            	gotoxy(xc+5,18);
	        		printf("Product with ID %s alreday Exist",ids);
	        		gotoxy(xc+10,19);
	        		printf("Choose another ID");
	        		gotoxy(xc+5,20);
	        		printf("Press Any Key To Continue");
	        		getch();
	        		goto l1;
	            }
	        }
	        while(fread(&e2, sizeof(info),1,fp1) )                                     // checking if the product ID Exist or not in the Order list 
	        {	
	            if(strcmp(e2.order_product_id,ids)==0  )
	            {
	            	gotoxy(xc+5,18);
	        		printf("Product with ID %s alreday Exist",ids);
	        		gotoxy(xc+10,19);
	        		printf("Choose another ID");
	        		gotoxy(xc+5,20);
	        		printf("Press Any Key To Continue");
	        		getch();
	        		goto l1;
	            }
	        }                   
	        strcpy(i1[i].order_product_id,ids); 
			gotoxy(xc,16);                                         // if ID is not taken 
		    printf("Enter product Name: ");
	    	gets(i1[i].order_product_name);
	    	gotoxy(xc,18);  
	    	printf("Enter Product Category: ");
	    	gets(i1[i].order_product_category);
	    	gotoxy(xc,20);  
	    	printf("Enter Max Purchase Limit : ");
	    	scanf("%d",&i1[i].order_max_limit);
	    	gotoxy(xc,22);  
	    	fflush(stdin);
	    	printf("Enter manufacturer name: ");
	    	gets(i1[i].order_manufacture_name);
	    	gotoxy(xc,24);  
	    	fflush(stdin);
	    	printf("Enter  contact number: ");
	    	gets(i1[i].order_manufacture_contact);
	    	gotoxy(xc,26);  
	    	printf("Enter manufacturer name: ");
	    	gets(i1[i].order_shipping_company);
	    	gotoxy(xc,28);  
	    	printf("Enter  contact number: ");
	    	gets(i1[i].order_contact_no);
	    	gotoxy(xc,30);  
	    	printf("Enter Status: ");
	    	gets(i1[i].status);
			
		    fwrite(&i1[i],sizeof(info),1,fp1);
		    fclose(fp);
	        fclose(fp1);
	    }
	    fclose(fp);
	    fclose(fp1);
	    break;
    
        case 4: 
		edit_order_list();                                                 // To edit Order list  
		break;
	
	    case 5:
		delete_orderlist();                                                // To Delete an product from Order List 
	    break; 
	
	    case 6:
	    total_order_list();                                                // To display total no. of products in Order list 
	    break;
    }
    }while(ch!=0);
}

void total_order_list()               // press 9                                                              // To display total products in the inventory 
{
	system("Cls");
	name();
	gotoxy(xc,14);
	info i1;
	FILE *fp;
	fp=fopen("orderlist.dat","rb");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof (info);
	printf("Total number of products= %d",n);
	fclose(fp);
	getch();
}

void display_orderlist()                                                          // Function to Display Products from Order List 
{
	system("cls");
	FILE *fp;
	info i1;
	int a=17,c=18,j;
	gotoxy(9,11);
	printf("ORDER LIST \n");
	fp=fopen("orderlist.dat","rb");
	while(fread(&i1,sizeof(info),1,fp))
	{
		// Top Border
    	gotoxy(9,13);
	    for(j=0; j<100*2; j++)
       	printf("%c", 205);
        // Top Border
        gotoxy(9,16);
    	for(j=0; j<100*2; j++)
        printf("%c", 205);
       	// Top left corner
        gotoxy(9,13);
	    printf("%c",201);
	    // Top right corner 
        gotoxy(80+128,13);
	    printf("%c",187);
	    // left Border
	    for(j=14;j<=c;j++)
	    {
		    gotoxy(80+128,j);
		    printf("%c",186);
	    }
	    //Right Border
	    for(j=14;j<=c;j++)
	    {
	        gotoxy(9,j);
	        printf("%c",186);
        }
		
	    gotoxy(10,14);
	    printf("ID.\t|\t NAME \t\t|\t CATEGORY\t|\t MAX LIMIT \t|\t MANUFACTURER \t|\t CONTACT NO: \t|\t SHIPPING COMPANY \t|\t CONTACT NO: \t|\t STATUS ");
	    gotoxy(10,a);
		printf("%s",strupr(i1.order_product_id));
		gotoxy(25,a);
		printf("%s",strupr(i1.order_product_name));
		gotoxy(50,a);
		printf("%s",strupr(i1.order_product_category));
		gotoxy(75,a);
		printf("%d",i1.order_max_limit);
		gotoxy(65+35,a);
		printf("%s",strupr(i1.order_manufacture_name));
		gotoxy(65+60,a);
		printf("%s",strupr(i1.order_manufacture_contact));
		gotoxy(65+55+30,a);
		printf("%s",strupr(i1.order_shipping_company));
		gotoxy(65+55+60,a);
		printf("%s",strupr(i1.order_contact_no));
		gotoxy(60+55+84,a);
        printf("%s",strupr(i1.status));
		gotoxy(9,c);
	    for(j=0; j<100*2; j++)
        printf("%c", 95);
				    
		a+=2;
		c+=2;
		// Bottom left corner
        gotoxy(9,c-2);
	    printf("%c",200);
	    // Bottom Right corner 
        gotoxy(80+128,c-2);
	    printf("%c",188);
	    //Bottom Border
	    gotoxy(10,c-2);
	    for(j=0; j<100*2-2; j++)
        printf("%c", 205);
	}
	if(fp==NULL)
	{
		gotoxy(9,13);
		printf("NO PRODUCT TO SHOW");
	}
	
	fclose(fp);
	getch();
}

void delete_orderlist()                                                        // Functiono to Delete Product from Order List 
{
	info i1;
	FILE *fp,*fp1;
	char ids[10],ch;
	int found=0;
	fflush(stdin);
	system("Cls");
	name();
	gotoxy(xc,14);
	printf("Enter the ID or Name to Delete the product: ");
	gets(ids);
	fp=fopen("orderlist.dat","rb");
	fp1=fopen("temp.dat","wb");	
	gotoxy(xc,15);
	while(fread(&i1, sizeof(info),1,fp))
	{	
	    if(strcmp(ids,i1.order_product_id)==0||strcmp(ids,i1.order_product_name)==0)                             // Searching product Id or name to delete
	    {
	    	found=1;
	    }
	    else
	    fwrite(&i1,sizeof(info),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	
	if(found)                                                     
	{
		fp1=fopen("temp.dat","rb");
		fp=fopen("orderlist.dat","wb+");
		
	    while(fread(&i1, sizeof(info),1,fp1))
	    fwrite(&i1,sizeof(info),1,fp);
	    printf("PRODUCT DETAIL SUCESSFULLY DELETED");
	    gotoxy(xc,18);
	    printf("DO you Want to Delete Another Product (Y/N)  ");
	    scanf("%c",&ch);
	    if(ch=='y'||ch=='Y')
	    {
	    	fclose(fp1);
	    	fclose(fp);
	    delete_orderlist();
	   }
	}
	fclose(fp1);
	fclose(fp);
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(72,20);
		printf("Product not found!!\a");
		gotoxy(65,21);
		printf("Press Any Key to Go Back To Menu ");
		
	}
	
	remove("temp.dat");
}

void edit_order_list()
{
	system("cls");
	name();
	FILE *fp,*fp1,*fp2;
	info *e,e1,i1,i2,e2;
	char ch,ids[10],ids1[10];
	int opt,a=70+65,b=45,found=0,count=0,q;
	fp=fopen("orderlist.dat","rb+");
	fp1=fopen("temp3.dat","wb+");
	fp2=fopen("inventory.dat","ab+");
	fflush(stdin);
	gotoxy(75,14);
	printf("Enter the ID or Name to Edit the product: ");
	gets(ids);
	system("cls");
	while(fread(&e1, sizeof(info),1,fp))
	{	
	    count++;
	    e = (info*)calloc(count,sizeof(info));
	    if(strcmp(ids,e1.order_product_id)==0||strcmp(ids,e1.order_product_name)==0)
	    {
			system("cls");
	    	found=1;
	    	name1();
	    	gotoxy(a,14);
	    	printf("OLD DETAILS \n");                                    // Displays Old Detsils to make easy to Edit 
	    	gotoxy(a,16);
			printf("Product ID           %s",strupr(e1.order_product_id));
			gotoxy(a,17);
			printf("Product Name         %s",strupr(e1.order_product_name));
			gotoxy(a,18);
			printf("Product Category     %s",strupr(e1.order_product_category));
			gotoxy(a,19);
			printf("Max Limit            %d",e1.order_max_limit);
			gotoxy(a,20);
			printf("Manufacturer Name    %s",strupr(e1.order_manufacture_name));
			gotoxy(a,21);
			printf("Contact No:          %s",strupr(e1.order_manufacture_contact));
			gotoxy(a,22);
			printf("Shipping Company     %s",strupr(e1.order_shipping_company));
			gotoxy(a,23);
			printf("Contact No:          %s",strupr(e1.order_contact_no));
			gotoxy(a,24);
       		printf("Status               %s",strupr(e1.status));                                               // To display old details to make esaier for editing details
       		gotoxy(b,14);
	    	printf("Press ");
	    	gotoxy(b,15);
	    	printf("0.) To Go Back To Main Menu  !!");
	    	gotoxy(b,16);
	    	printf("1.) To change Status ");
	    	gotoxy(b,17);
	    	printf("2.) To Edit Product ID ");
	    	gotoxy(b,18);
	    	printf("3.) To Edit Product Name ");
	    	gotoxy(b,19);
	    	printf("4.) To Edit Product Category ");
	    	gotoxy(b,20);
	    	printf("5.) To Edit Quantity ");
	    	gotoxy(b,21);
	    	printf("6.) To Edit Manufacture Name and Contact Number ");
	    	gotoxy(b,22);
	    	printf("7.) To Edit Shipping Company and Contact Number ");
	    	gotoxy(b,23);
	    	printf("8.) To Edit Every Detail ");
	    	gotoxy(b,24);
	    	printf("Choice==> ");
	    	scanf("%d",&opt);
	    	gotoxy(a,14);
	    	l1:
	    	system("cls");
			name1();
	    	gotoxy(a,14);
	    	printf("OLD DETAILS \n");                                    // Displays Old Detsils to make easy to Edit 
	    	gotoxy(a,16);
			printf("Product ID           %s",strupr(e1.order_product_id));
			gotoxy(a,17);
			printf("Product Name         %s",strupr(e1.order_product_name));
			gotoxy(a,18);
			printf("Product Category     %s",strupr(e1.order_product_category));
			gotoxy(a,19);
			printf("Max Limit             %d",e1.order_max_limit);
			gotoxy(a,20);
			printf("Manufacturer Name    %s",strupr(e1.order_manufacture_name));
			gotoxy(a,21);
			printf("Contact No:          %s",strupr(e1.order_manufacture_contact));
			gotoxy(a,22);
			printf("Shipping Company     %s",strupr(e1.order_shipping_company));
			gotoxy(a,23);
			printf("Contact No:          %s",strupr(e1.order_contact_no));
			gotoxy(a,24);
       		printf("Status               %s",strupr(e1.status));   
	    	switch(opt)
	    	{
	    		case 0:
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);                                 // Copying previous data in file 
	    	    strcpy(e[count-1].order_product_name,e1.order_product_name);
	    	    strcpy(e[count-1].order_product_category,e1.order_product_category);
	    	    e[count-1].order_product_quantity=e1.order_product_quantity;
	    	    strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    	    strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    	    strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    	    strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    	    strcpy(e[count-1].status,e1.status);
	    	    e[count-1].order_max_limit=e1.order_max_limit;
	  	    	break;
	    		case 1:                                                     // if status is complete product details moves to Inventory without making purchase manually
	    		fflush(stdin);
	    		gotoxy(b,16); 
	    		printf("New Status : ");
	    		gets(e[count-1].status);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);       // Copying previous data in file 
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		
	    		if(strcmp(e[count-1].status,"Complete")==0 ||strcmp(e[count-1].status,"COMPLETE")==0 ||strcmp(e[count-1].status,"complete")==0 ||strcmp(e[count-1].status,"c")==0 ||strcmp(e[count-1].status,"C")==0)
	    		{
	    			
            		gotoxy(b,18);                                            // if status is complete then .. 
            		printf("Enter Quantity :  ");
            		scanf("%d",&q);
            		if(q>e1.order_max_limit){
            		gotoxy(b,20);  
            		printf("Purchase Limit Exceeded ");
            		gotoxy(b,21);
            		printf("Print Any Key To Continue.. ");
            		getch();
            		goto l1;
            		}
            		e[count-1].quantity=q;
            		fflush(stdin);
	    			gotoxy(b,20);                                            // if status is complete then .. 
            		printf("Enter Purchased Date:  ");
            		gets(e[count-1].purchased_date);
            		gotoxy(b,22);
            		printf("Enter Manufacture Date:  ");
            		gets(e[count-1].mfg_date);
            		gotoxy(b,24);
            		printf("Enter Expiry Date:  ");
            		gets(e[count-1].exp_date);
            		gotoxy(b,26);
            		fflush(stdin);
            		printf("Enter Cost Price:  ");
            		scanf("%f",&e[count-1].cost_price);
            		gotoxy(b,28);
            		fflush(stdin);
            		printf("Enter sales Price:  ");
            		scanf("%f",&e[count-1].sales_price);
				
	    			strcpy(e[count-1].product_id,e1.order_product_id);                                // Copying previous data in file 
	    			strcpy(e[count-1].product_name,e1.order_product_name);
	    			strcpy(e[count-1].product_category,e1.order_product_category);
	    			e[count-1].max=e1.order_max_limit;
	    			strcpy(e[count-1].manufacture_name,e1.order_manufacture_name);
	    			strcpy(e[count-1].manufacture_contact,e1.order_manufacture_contact);
	    			strcpy(e[count-1].shipping_company,e1.order_shipping_company);
	    			strcpy(e[count-1].contact_no,e1.order_contact_no);
	    			e[count-1].totalcostam=(e[count-1].cost_price)*e[count-1].quantity+e[count-1].totalcostam;
					fwrite(&e[count-1],sizeof (info),1,fp2);
	    			
			    }
				break;
	    		
	    		case 2:                                                  //  To Edit Id and checks if the New Id is already taken  
	    		fflush(stdin);
	    		gotoxy(b,14);
	    		printf("Enter New  ID: ");
	    		gets(ids1);
	     		while(fread(&i1, sizeof(info),1,fp))
	            {	
	                if(strcmp(ids1,i1.order_product_id)==0)
	            	{
	    	            gotoxy(b+5,18);
	                	printf("ID %s is alreday taken",ids1);
	                	gotoxy(b+5,19);
	    	            printf("Choose another ID");
	    	            gotoxy(b,20);
	                	printf("Press Any Key To Continue");
	    	            getch();
	    	            goto l1;
	                }
				}
				while(fread(&i2, sizeof(info),1,fp2))
	            {	
	                if(strcmp(ids,i2.product_id)==0)
	            	{
	    	            gotoxy(b+5,18);
	                	printf("ID %s is alreday taken",ids1);
	                	gotoxy(b+5,19);
	    	            printf("Choose another ID");
	    	            gotoxy(b,20);
	                	printf("Press Any Key To Continue");
	    	            getch();
	    	            goto l1;
	                }
				}
				strcpy(e[count-1].order_product_id,ids1);                                      // Copying previous data in file 
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 3:                                                                         //To edit name from Order lis
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("Enter New Name : ");
	    		gets(e[count-1].order_product_name);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);                        // Copying previous data in file
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 4:                                                                          // To Edit Product Category
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("Enter New Category : ");
	    		gets(e[count-1].order_product_category);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 5:                                                                          // To Edit Quantity
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("Enter New Max Limit : ");
	    		scanf("%d",&e[count-1].order_max_limit);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);                        // Copying previous data in file 
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 6:
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("Enter New Manufacture Name and contact Number \n");
	    		printf("New Name: ");
	    		gets(e[count-1].order_manufacture_name);
	    		printf("New Contact Name: ");
	    		gets(e[count-1].order_manufacture_contact);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);                       // Copying previous data in file 
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    		strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 7:
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("Enter New Shipping Company and contact Number \n");
	    		printf("New Name: ");
	    		gets(e[count-1].order_shipping_company);
	    		printf("New Contact Name: ");
	    		gets(e[count-1].order_contact_no);
	    		
	    		strcpy(e[count-1].order_product_id,e1.order_product_id);                          // Copying previous data in file 
	    		strcpy(e[count-1].order_product_name,e1.order_product_name);
	    		strcpy(e[count-1].order_product_category,e1.order_product_category);
	    		e[count-1].order_max_limit=e1.order_max_limit;
	    		strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    		strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    		strcpy(e[count-1].status,e1.status);
	    		break;
	    		
	    		case 8:
				gotoxy(b,14);
	    		fflush(stdin);
	    		printf("New Status : ");
	    		gets(e[count-1].status);
	    		gotoxy(b,16);
	    		printf("Enter New  ID: ");
	    		gets(ids1);
	     		while(fread(&i1, sizeof(info),1,fp))
	            {	
	                if(strcmp(ids1,i1.order_product_id)==0)
	            	{
	            		system("cls");
	    	            gotoxy(b+5,18);
	                	printf("ID %s is alreday taken",ids1);
	                	gotoxy(b+5,19);
	    	            printf("Choose another ID");
	    	            gotoxy(b,20);
	                	printf("Press Any Key To Continue");
	    	            getch();
	    	            system("cls");
	    	            goto l1;
	                }
				}
				while(fread(&i2, sizeof(info),1,fp2))
	            {	
	                if(strcmp(ids,i2.product_id)==0)
	            	{
	            		system("cls");
	    	            gotoxy(b+5,18);
	                	printf("ID %s is alreday taken",ids1);
	                	gotoxy(b+5,19);
	    	            printf("Choose another ID");
	    	            gotoxy(b,20);
	                	printf("Press Any Key To Continue");
	    	            getch();
	    	            system("cls");
	    	            goto l1;
	                }
				}
				strcpy(e[count-1].order_product_id,ids1);
				gotoxy(b,18);
	    		printf("Enter New Name : ");
	    		gets(e[count-1].order_product_name);
	    		gotoxy(b,20);
	    		printf("Enter New Category : ");
	    		gets(e[count-1].order_product_category);
	    		gotoxy(b,22);
	    		printf("Enter New Max Limit : ");
	    		scanf("%d",&e[count-1].order_max_limit);
	    		gotoxy(b,24);
	    		fflush(stdin);
	    		printf("Enter New Manufacture Name and contact Number \n");
	    		gotoxy(b,25);
	    		printf("New Name: ");
	    		gets(e[count-1].order_manufacture_name);
	    		gotoxy(b,26);
	    		printf("New Contact Name: ");
	    		gets(e[count-1].order_manufacture_contact);
	    		gotoxy(b,27);
	    		printf("Enter New Shipping Company and contact Number \n");
	    		gotoxy(b,28);
	    		printf("New Name: ");
	    		gets(e[count-1].order_shipping_company);
	    		gotoxy(b,29);
	    		printf("New Contact Name: ");
	    		gets(e[count-1].order_contact_no);
	    		break;
	    		
	    		default:
				gotoxy(b,14);
    	        printf("Please choose correct option!");
			}
		fwrite(&e[count-1],sizeof (info),1,fp1);
	    }
	    else
	    {
	    	strcpy(e[count-1].order_product_id,e1.order_product_id);                                 // Copying previous data in file 
	    	strcpy(e[count-1].order_product_name,e1.order_product_name);
	    	strcpy(e[count-1].order_product_category,e1.order_product_category);
	    	e[count-1].order_product_quantity=e1.order_product_quantity;
	    	strcpy(e[count-1].order_manufacture_name,e1.order_manufacture_name);
	    	strcpy(e[count-1].order_manufacture_contact,e1.order_manufacture_contact);
	    	strcpy(e[count-1].order_shipping_company,e1.order_shipping_company);
	    	strcpy(e[count-1].order_contact_no,e1.order_contact_no);
	    	strcpy(e[count-1].status,e1.status);
	    	e[count-1].order_max_limit=e1.order_max_limit;
	    	
	    	fwrite(&e[count-1],sizeof (info),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	if(found)                                                                       // if found Removing origial file and renaming temp file Original
	{
		system("cls");
		name();
		gotoxy(80,18);
		printf("Successfully Updated !");
		remove("orderlist.dat");
		rename("temp3.dat","orderlist.dat");
	}
		
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(80,20);
		printf("Product not found!!\a");
		gotoxy(75,21);
		printf("Press Any Key to Go Back To Menu ");
		getch();
	    remove("temp3.dat");
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	getch();
}
void profit_loss()
{
	system("cls");
	name();
	FILE *fp,*fp1;
	info *e,e2,e0,e1,i1,i2;
	char ch,ids[10],ids1[10];
	int opt,a=70+65,b=45,found=0,count=0;
	float total=0,totalsoldam=0,profit=0,spent,gain;
	fp=fopen("Sales Report.dat","rb");
	fp1=fopen("inventory.dat","rb");
	gotoxy(78,16);
	printf("Press");
	gotoxy(78,17);
	printf("1.) All ");
	gotoxy(78,18);
	printf("2.) Individual Product ");
	scanf("%d",&ch);
	if(ch==1)
	{
		system("cls");
		name();
		while(fread(&e1, sizeof(info),1,fp1))
		spent+=e1.cost_price*e1.quantity;
		gotoxy(80,14);
		printf("Total Cost Amount :    %f",spent);
		while(fread(&e2, sizeof(info),1,fp))
		gain+=e2.total;
		gotoxy(80,15);
		printf("Total Gained  Amount :    %f",gain);
	}
	if(ch==2)
	{
		system("cls");
	    name();
		fflush(stdin);
	    gotoxy(78,14);
	    printf("Enter the ID or Name to Search the product: ");
	    gets(ids);
	    while(fread(&e1, sizeof(info),1,fp1))
	    {
	    if(strcmp(ids,e1.product_id)==0 || strcmp(ids,e1.product_name)==0)
	    {   
	        while(fread(&e0, sizeof(info),1,fp))
	        {
	        	if(strcmp(ids,e0.sold_product_id)==0 || strcmp(ids,e0.product_name)==0)
	        	{
    	        totalsoldam+=e0.total;
	        gotoxy(78,18);
	        printf("Cost Price Per Item :    %.2f",e1.cost_price);
	        gotoxy(78,19);
	        printf("Sales Price Per Item :   %.2f",e1.sales_price);
	        gotoxy(78,20);
	        printf("Sold Amount per Item     %.2f",(e0.total/e0.sold_quantity));
	        gotoxy(78,23);
	        printf("Profit on Each Item      %.2f",(e0.total/e0.sold_quantity)-e1.cost_price);
	        }
	    }
	    gotoxy(78,18);
	    printf("Cost Price Per Item :   %.2f",e1.cost_price);
	    gotoxy(78,19);
	    printf("Sales Price Per Item :  %.2f",e1.sales_price);
	    gotoxy(78,21);
	    printf("Total Cost Price        %.2f ",e1.totalcostam);
	    gotoxy(78,22);
	    printf("Total  Sales Price      %.2f ",totalsoldam);
	    gotoxy(78,24);
	    printf("Remaining Quantity      %d",e1.quantity);
	    gotoxy(78,25);
		profit=e1.totalcostam-totalsoldam;
		if(profit>=e1.totalcostam)
		printf("Profit                  %.2f",profit);
		
		else
		printf("Loss                    %.2f",profit);  
	    }
        }
    }
	
	getch();
	fclose(fp);
	fclose(fp1);
}

void Employee()                                                                //  function for Employee management 
{
	int opt;
	do{
	system("cls");
	name();
	gotoxy(xc,14);  
	printf("Press \n");
	gotoxy(xc,15);  
	printf("0.) To Go Back To Main Menu ");
	gotoxy(xc,16);  
	printf("1.) To Add New Employee Details ");
	gotoxy(xc,17);  
	printf("2.) To Display Employee Details ");
	gotoxy(xc,18);  
	printf("3.) To Search Employee ");
	gotoxy(xc,19);  
	printf("4.) To Edit Employee Details ");
	gotoxy(xc,20);  
	printf("5.) To Delete Employee Details ");
	gotoxy(xc,21);  
	printf("Press the option:  ");
	scanf("%d",&opt);
	
	switch(opt)
	{
		case 1:
		add_employee();
		break;
		
		case 2:
		display_employee();
		break;
		
		case 3:
		search_employee();
		break;
		
		case 4:
		edit_employee();
		break;
		
		case 5:
		delete_employee();
		break;
		
		case 6:
		total_employee();
		break;
		
		default:
		printf("Press correct option!");
		
	}}while(opt!=0);
	
	
}

void add_employee()                                                                //  function for adding new employee details
{
	system("cls");
	name();
	employee *e,e0;
	FILE *fp,*fp1;;
	int i,n,found=0;
	char ids[10];
	gotoxy(xc,14);  
	printf("How many Details you want to Add: ");
	scanf("%d",&n);
	e= (employee*)calloc(n,sizeof(employee));
	for(i=0;i<n;i++)
	{
		found=1;
		fp=fopen("employee.dat","ab+");
		l1:
		system("cls");
		name();
		gotoxy(xc,14);  
		fflush(stdin);
		printf("Enter emlyoyee ID: ");
		gets(ids);
		fp1=fopen("employee.dat","rb");
		while(fread(&e0,sizeof(employee),1,fp1))
	    {
	    	if(strcmp(ids,e0.emp_id)==0)
	    	{
	    		gotoxy(xc+18,18);
	    	    printf("ID %s already Taken",ids);
	    	    gotoxy(xc+18,19);
	        	printf("choose another ID");
	        	getch();
		    	fclose(fp1);
	        	goto l1;
			}
	    }	
	    strcpy(e[i].emp_id,ids);
		gotoxy(xc,15);  
		fflush(stdin);
		printf("Enter Employee Name: ");
		gets(e[i].emp_name);
		gotoxy(xc,16);  
		printf("Enter Employee Post: ");
		gets(e[i].emp_post);
		gotoxy(xc,17);  
		printf("Enter Emlpoyee Address: ");
		gets(e[i].emp_address);
		gotoxy(xc,18);  
		printf("Enter Employee Contact number: ");
		gets(e[i].emp_contact);
		gotoxy(xc,19);  
		printf("Enter Employee Salary: ");
		scanf("%f",&e[i].emp_salary);
		fflush(stdin);
		gotoxy(xc,20);  
		printf("Remarks: ");
		gets(e[i].emp_remarks);
		
		fwrite(&e[i],sizeof(employee),1,fp);
		fclose(fp);
	    fclose(fp1);
	}
	if(found)
	{
		gotoxy(xc+15,20);
		printf(" Employee Details");
		gotoxy(xc+15,21);
		printf("Sucessfully Added");
	
	}
	

}
void display_employee()                                                                //  function for displaying employee details
{
	system("cls");
	int j;
    employee e1;
    FILE *fp;
    int a=17,c=18,sn=0;
    fp=fopen("employee.dat","rb");
    // Top Border
	gotoxy(22,14);
	for(j=0; j<100+73; j++)
    printf("%c", 205);
    // Top Border
    gotoxy(22,16);
	for(j=0; j<100+73; j++)
    printf("%c", 205);
    // Top left corner
    gotoxy(22,14);
	printf("%c",201);
	// Top right corner 
    gotoxy(170+24,14);
	printf("%c",187);
	gotoxy(25,15); 
	printf("SN.\t | \t EMPLOYEE ID \t | \t EMPLOYEE NAME  \t | \t POST \t | \t SALARY \t | \t CONTACT NO: \t | \t ADDRESS \t | \t REMARKS \t");
	while(fread(&e1,sizeof(employee),1,fp))
	{
		sn++;
	    // left Border
	    for(j=15;j<=c;j++)
	    {
		    gotoxy(170+24,j);
		    printf("%c",186);
	    }
	    //Right Border
	    for(j=15;j<=c;j++)
	    {
		    gotoxy(22,j);
		    printf("%c",186);
	    }
		gotoxy(28,a); 
		printf("%d",sn);
		gotoxy(45,a);
	    printf("%s",e1.emp_id);
		gotoxy(65,a);  
		printf("%s",e1.emp_name);
		gotoxy(95,a);  
		printf("%s",e1.emp_post);
		gotoxy(115,a);  
		printf("%.2f",e1.emp_salary);
		gotoxy(115+25,a);  
		printf("%s",e1.emp_contact);
		gotoxy(115+50,a);  
		printf("%s",e1.emp_address);
		gotoxy(115+74,a);  
		printf("%s",e1.emp_remarks);
		gotoxy(22,c);
	    for(j=0; j<100+73; j++)
        printf("%c", 95);
		a+=2;
		c+=2;
	}
	// Bottom left corner
    gotoxy(22,c-2);
	printf("%c",200);
	// Bottom right corner 
    gotoxy(170+24,c-2);
	printf("%c",188);
	gotoxy(23,c-2);
	for(j=0; j<100+71; j++)
    printf("%c", 205);
	fclose(fp);
	getch();
}
void search_employee()
{
	system("cls");
	name();
	char ids[10];
	employee e1;
	FILE *fp;
	int a=17,found=0,j,sn=0,c=18;
	fp= fopen("employee.dat","rb");
	fflush(stdin);
	gotoxy(xc,15);
	printf("Enter the ID or Name to search Employee Details: ");
	gets(ids);
	system("cls");

	while(fread(&e1, sizeof(employee),1,fp))
	{	sn++;
	    if(strcmp(ids,e1.emp_id)==0||strcmp(ids,e1.emp_id)==0)
	    {
	    	//sn++;
	    	found=1;
	    	// Top Border
	    	gotoxy(22,14);
	    	for(j=0; j<100+73; j++)
        	printf("%c", 205);
        	// Top Border
        	gotoxy(22,16);
	    	for(j=0; j<100+73; j++)
        	printf("%c", 205);
        	// Top left corner
        	gotoxy(22,14);
	    	printf("%c",201);
	    	// Top right corner 
        	gotoxy(170+24,14);
	    	printf("%c",187);
	    	gotoxy(25,15); 
	    	printf("SN.\t | \t EMPLOYEE ID \t | \t EMPLOYEE NAME  \t | \t POST \t | \t SALARY \t | \t CONTACT NO: \t | \t ADDRESS \t | \t REMARKS \t");
	    	// left Border
	    	for(j=15;j<=c;j++)
	    	{
		    	gotoxy(170+24,j);
		    	printf("%c",186);
	    	}
	    	//Right Border
	    	for(j=15;j<=c;j++)
	    	{
		    	gotoxy(22,j);
		    	printf("%c",186);
	    	}
			gotoxy(28,a); 
			printf("%d",sn);
			gotoxy(45,a);
	    	printf("%s",e1.emp_id);
			gotoxy(65,a);  
			printf("%s",e1.emp_name);
			gotoxy(95,a);  
			printf("%s",e1.emp_post);
			gotoxy(115,a);  
			printf("%.2f",e1.emp_salary);
			gotoxy(115+25,a);  
			printf("%s",e1.emp_contact);
			gotoxy(115+50,a);  
			printf("%s",e1.emp_address);
			gotoxy(115+74,a);  
			printf("%s",e1.emp_remarks);
			gotoxy(22,c);
	    	for(j=0; j<100+73; j++)
        	printf("%c", 95);
			a+=2;
			c+=2;
			// Bottom left corner
            gotoxy(22,c-2);
	        printf("%c",200);
        	// Bottom right corner 
            gotoxy(170+24,c-2);
	        printf("%c",188);
	        gotoxy(23,c-2);
	        for(j=0; j<100+71; j++)
            printf("%c", 205);
	    }
    }
    if(!found)
	{
	    //system("cls");
	    name();
	    gotoxy(xc+15,20);
	    printf("Employee Not Found !!");
	    gotoxy(xc+12,21);
	    printf("Enter Correct ID or Name");
	}
    fclose(fp);
    getch();
	
}

void name2()
{
	int i,j;
	char cur_time[128];
	gotoxy (80+21,8);
	printf("*-----STORE STOCK MANAGER-----*");	
	
	//Top border line...
    gotoxy(50,5); 
    for(j=0; j<69+59; j++)
    printf("%c", 223);
  
    //middle border line...
    gotoxy(50,10); 
    for(j=0; j<69+59; j++)
    printf("%c", 223);
 
    //Bottom border line... 
    gotoxy(50,41);
    for(j=0; j<=69+59; j++)
    printf("%c", 223);
    
    for(i=10;i<41;i++)
    {
    	gotoxy(55+59,i);
        printf("%c",219);
    	
	}
    
	
   //Left and Right border line...
   for(j=0; j<36; j++)
   {
     gotoxy(50,5+j);
     printf("%c",219);
  
     gotoxy(50+69+59,5+j);
     printf("%c",219);
   }
}
void edit_employee()
{
	system("cls");
	name();
	char ids[10],ids1[10];
	employee *e,e1,e0;
	FILE *fp,*fp1,*fp2;
	int a=15,found=0,count=0,j,ch;
	fp= fopen("employee.dat","rb");
	fp1=fopen("emp1.dat","wb");
	fflush(stdin);
	gotoxy(xc,15);
	printf("Enter the ID or Name to search Employee Details: ");
	gets(ids);
	while(fread(&e1, sizeof(employee),1,fp))
	{
	    count++;
	    e= (employee*) calloc(count,sizeof(employee));
	    if(strcmp(ids,e1.emp_id)==0||strcmp(ids,e1.emp_name)==0)
	    {
	    	found=1;
	    	system("cls");
	    	name2();
	    	gotoxy(75+65,14);
	    	printf("OLD DETAILS: ");
	    	gotoxy(75+65,16);
	        printf("Employee ID        %s",e1.emp_id);
	        gotoxy(75+65,17);  
	    	printf("Employee Name      %s",e1.emp_name);
	    	gotoxy(75+65,18);  
	        printf("Post               %s",e1.emp_post);
	    	gotoxy(75+65,19);  
		    printf("Salary             %.2f",e1.emp_salary);
	    	gotoxy(75+65,20);  
		    printf("Contact No:        %s",e1.emp_contact);
	    	gotoxy(75+65,21);  
		    printf("Address            %s",e1.emp_address);
		    gotoxy(75+65,22);  
		    printf("Remarks            %s",e1.emp_remarks);
	    	gotoxy(55,13);
	    	printf("Press ");
	    	gotoxy(55,15);
	    	printf("1.) To Edit Employee ID ");
	    	gotoxy(55,16);
	    	printf("2.) To Edit Name ");
	    	gotoxy(55,17);
	    	printf("3.) To Edit Post ");
	    	gotoxy(55,18);
	    	printf("4.) To Edit Adress ");
	    	gotoxy(55,19);
	    	printf("5.) To Edit Contact No: ");
	    	gotoxy(55,20);
	    	printf("6.) To Edit Salary ");
	    	gotoxy(55,21);
	    	printf("7.) To Edit Remarks ");
	    	gotoxy(55,22);
	    	printf("8.) To Edit All Details ");
	    	gotoxy(55,24);
	    	printf("Choice ==> ");
	    	scanf("%d",&ch);
	    	l1:
	    	system("cls");
	    	name2();
	    	gotoxy(75+65,14);
	    	printf("OLD DETAILS: ");
	    	gotoxy(75+65,16);
	        printf("Employee ID        %s",e1.emp_id);
	        gotoxy(75+65,17);  
	    	printf("Employee Name      %s",e1.emp_name);
	    	gotoxy(75+65,18);  
	        printf("Post               %s",e1.emp_post);
	    	gotoxy(75+65,19);  
		    printf("Salary             %.2f",e1.emp_salary);
	    	gotoxy(75+65,20);  
		    printf("Contact No:        %s",e1.emp_contact);
	    	gotoxy(75+65,21);  
		    printf("Address            %s",e1.emp_address);
		    gotoxy(75+65,22);  
		    printf("Remarks            %s",e1.emp_remarks);
	    	switch(ch)
	    	{
	    		case 0:
	    		strcpy(e[count-1].emp_id,e1.emp_id);
			    strcpy(e[count-1].emp_name,e1.emp_name);
		    	strcpy(e[count-1].emp_post,e1.emp_post);
		    	strcpy(e[count-1].emp_address,e1.emp_address);
		    	strcpy(e[count-1].emp_contact,e1.emp_contact);
		    	strcpy(e[count-1].emp_remarks,e1.emp_remarks);
		    	e[count-1].emp_salary=e1.emp_salary;
	    		break;
	    		case 1:
	    	    fflush(stdin);
	    	    gotoxy(55,14);
			    printf("Enter New  ID: ");
			    gets(ids1);
			    fp2=fopen("employee.dat","rb");
		        while(fread(&e0,sizeof(employee),1,fp2))
	            {
	    	        if(strcmp(ids1,e0.emp_id)==0)
	    	        {
	    	    	    gotoxy(xc+18,18);
	    	            printf("ID %s already Taken",ids1);
	    	            gotoxy(xc+18,19);
	    	            printf("choose another ID");
	    	            getch();
			            fclose(fp2);
	    	            goto l1;
				    }
	            }
	            fclose(fp2);
	            strcpy(e[count-1].emp_id,ids1);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_post,e1.emp_post);
			    strcpy(e[count-1].emp_address,e1.emp_address);
			    strcpy(e[count-1].emp_contact,e1.emp_contact);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			    e[count-1].emp_salary=e1.emp_salary;
				break;
				
				case 2:
				gotoxy(55,14);
				fflush(stdin);
			    printf("Enter New  Name: ");
			    gets(e[count-1].emp_name);
			    
				strcpy(e[count-1].emp_id,e1.emp_id);
			    strcpy(e[count-1].emp_post,e1.emp_post);
			    strcpy(e[count-1].emp_address,e1.emp_address);
			    strcpy(e[count-1].emp_contact,e1.emp_contact);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			    e[count-1].emp_salary=e1.emp_salary;	
				break;  
				
				case 3:
				gotoxy(55,14);
	    	    fflush(stdin);
				printf("Enter New Employee Post: ");
			    gets(e[count-1].emp_post);	
					
				strcpy(e[count-1].emp_id,ids1);
				strcpy(e[count-1].emp_id,e1.emp_id);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_address,e1.emp_address);
			    strcpy(e[count-1].emp_contact,e1.emp_contact);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			    e[count-1].emp_salary=e1.emp_salary;
				break;
				
				case 4:
				gotoxy(55,14);
	    	    fflush(stdin);
				printf("Enter New  Address: ");
			    gets(e[count-1].emp_address);
			    
			    strcpy(e[count-1].emp_id,e1.emp_id);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_post,e1.emp_post);
		    	strcpy(e[count-1].emp_contact,e1.emp_contact);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			    e[count-1].emp_salary=e1.emp_salary;
				break;
				
				case 5:
				gotoxy(55,14);
	    	    fflush(stdin);
	        	printf("Enter New Contact number: ");
			    gets(e[count-1].emp_contact);
			    
			    strcpy(e[count-1].emp_id,e1.emp_id);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_post,e1.emp_post);
			    strcpy(e[count-1].emp_address,e1.emp_address);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			    e[count-1].emp_salary=e1.emp_salary;
				break;
				
				case 6:
				gotoxy(55,14);
	    	    fflush(stdin);
				printf("Enter New Salary : ");
			    scanf("%f",&(e[count-1].emp_salary));
			    
			    strcpy(e[count-1].emp_id,e1.emp_id);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_post,e1.emp_post);
			    strcpy(e[count-1].emp_address,e1.emp_address);
			    strcpy(e[count-1].emp_contact,e1.emp_contact);
			    strcpy(e[count-1].emp_remarks,e1.emp_remarks);
				break;
				
				case 7:
				gotoxy(55,14);
	    	    fflush(stdin);
				printf("New Remarks: ");
			    gets(e[count-1].emp_remarks);
			    
			    strcpy(e[count-1].emp_id,e1.emp_id);
		    	strcpy(e[count-1].emp_name,e1.emp_name);
			    strcpy(e[count-1].emp_post,e1.emp_post);
			    strcpy(e[count-1].emp_address,e1.emp_address);
		    	strcpy(e[count-1].emp_contact,e1.emp_contact);
			    e[count-1].emp_salary=e1.emp_salary;
				break;
	    		
			    case 8:
	    	    gotoxy(55,14);
	    	    fflush(stdin);
			    printf("Enter New  ID: ");
			    gets(ids1);
			    fp2=fopen("employee.dat","rb");
		        while(fread(&e0,sizeof(employee),1,fp2))
	            {
	    	        if(strcmp(ids1,e0.emp_id)==0)
	    	        {
	    	    	    gotoxy(xc+18,18);
	    	            printf("ID %s already Taken",ids1);
	    	            gotoxy(xc+18,19);
	    	            printf("choose another ID");
	    	            getch();
			            fclose(fp2);
	    	            goto l1;
				    }
	            }
	            fclose(fp2);
	            strcpy(e[count-1].emp_id,ids1); 
	            gotoxy(55,16);
			    fflush(stdin);
			    printf("Enter New  Name: ");
			    gets(e[count-1].emp_name);
			    gotoxy(55,18);
			    printf("Enter New  Post: ");
			    gets(e[count-1].emp_post);
			    gotoxy(55,20);
			    printf("Enter New  Address: ");
			    gets(e[count-1].emp_address);
			    gotoxy(55,22);
			    printf("Enter New  Contact number: ");
			    gets(e[count-1].emp_contact);
			    gotoxy(55,24);
			    printf("Enter New  Salary: ");
			    scanf("%f",&e[count-1].emp_salary);
			    fflush(stdin);
			    gotoxy(55,26);
			    printf("New Remarks: ");
			    gets(e[count-1].emp_remarks);
			    break;
			    
			    default:
			    name();
			    printf("Choose correct Option !!");
		   }
		   fwrite(&e[count-1],sizeof(employee),1,fp1);  
		}
		
		else
		{
			strcpy(e[count-1].emp_id,e1.emp_id);
			strcpy(e[count-1].emp_name,e1.emp_name);
			strcpy(e[count-1].emp_post,e1.emp_post);
			strcpy(e[count-1].emp_address,e1.emp_address);
			strcpy(e[count-1].emp_contact,e1.emp_contact);
			strcpy(e[count-1].emp_remarks,e1.emp_remarks);
			e[count-1].emp_salary=e1.emp_salary;
			fwrite(&e[count-1],sizeof(employee),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	//fclose(fp2);
	
	if(found)
	{
		remove("employee.dat");
		rename("emp1.dat","employee.dat");
		system("cls");
		name();
		gotoxy(xc+15,22);
		printf("Sucessfully Updated !!");
	}
	
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(xc+20,20);
		printf("Product not found!!\a");
		gotoxy(xc+15,21);
		printf("Press Any Key to Go Back To Menu ");
	}
	getch();
	remove("emp1.dat");
}

void delete_employee()
{
	employee i1;
	FILE *fp,*fp1;
	char ids[10];
	int found=0;
	fflush(stdin);
	system("Cls");
	name();
	gotoxy(xc,14);
	printf("Enter the ID or Name to Delete the product: ");
	gets(ids);
	fp=fopen("employee.dat","rb");
	fp1=fopen("emp2.dat","wb");	
	gotoxy(xc,15);
	while(fread(&i1, sizeof(employee),1,fp))
	{	
	    if(strcmp(ids,i1.emp_id)==0||strcmp(ids,i1.emp_name)==0)
	    {
	    	found=1;
	    }
	    else
	    fwrite(&i1,sizeof(employee),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	
	if(found)
	{
		fp1=fopen("emp2.dat","r");
		fp=fopen("employee.dat","wb");
		
	    while(fread(&i1, sizeof(employee),1,fp1))
	    fwrite(&i1,sizeof(employee),1,fp);
	    
	    system("cls");
	    name();
	    gotoxy(xc+15,22);
		printf("EMPLOYEE DETAIL SUCESSFULLY DELETED");
	}
	fclose(fp1);
	fclose(fp);
	if(!found)
	{
		system("cls");
	    name();
	    gotoxy(72,20);
		printf("Employee  not found!!\a");
		gotoxy(65,21);
		printf("Press Any Key to Go Back To Menu ");
		
	}
	remove("emp2.dat");
	getch();
}
void total_employee()
{
	system("Cls");
	name();
	gotoxy(xc,14);
	info i1;
	FILE *fp;
	fp=fopen("employee.dat","rb");
	fseek(fp,0,SEEK_END);
	int n=ftell(fp)/sizeof (info);
	printf("Total number of Employee = %d",n);
	fclose(fp);
	getch();
}
