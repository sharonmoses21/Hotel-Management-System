// Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996) /*disable string error*/


// Struct to make the variables esay to access.
struct customer
{
    char roomID[5];
    char Name[20];
    char room_type[20];
    char address[20];
    char phone[20];
    char DoB[20];
    char email[10];
    char Ic_or_passport[20];
    char nationality[25];
    char arrival_date[20];
    double number_of_days;
    double room_price;
    double total;
} c;

// Function declaration
void Room_booking();
void Display_customer_Record();
void Search_customer();
void Edit_customer_info();
void menu_list();


//system functions
int main(void)
{
    char roomID[5];
    char MenuOption;
    FILE *FP = fopen("customer.txt", "a"); // creating a file then appending the information to the file.
    fclose(FP);

    do
    {
        printf("   ******************************  |MAIN MENU|  ***************************** \n");
        printf("\n");
        printf("\n");
        printf("1: ******************************  |Room Booking|*****************************\n");
        printf("\n");
        printf("2: ******************************  |Allow Search Booking|*****************************\n");
        printf("\n");
        printf("3: ******************************  |Display Customer Record|*****************************\n");
        printf("\n");
        printf("4: ******************************  |Booking Update|*****************************\n");
        printf("\n");
        printf("0: ******************************  |Exit|*****************************\n");
        printf("\n");
        printf("\nChoose your option: ");
        scanf("%s", &MenuOption);
        switch (MenuOption)
        {
        case '1': //register new customer
            menu_list();
            printf("\n");
            printf("\n");
            Room_booking();
            break;
        case '2': //Search customer
            Search_customer();
            break;
        case '3': //Display customer information
            Display_customer_Record();
            break;
        case '4':
            Edit_customer_info(); //Editing customer information
            break;
        case '0': //exit
            exit(1);
            break;
        default:
            printf("\nWrong input Try again (Click Enter)\n");
            break;
        }

    } while (MenuOption != '0');
    return 0;
}

// menu function.
void menu_list()
{

    // Here is the table menu to show the customer the room available.
    printf("   ******************************  |WELCOME TO OUR MENU LIST|  ***************************** \n");

    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| RoomID    |          Room Type               |      Price Per Day            |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 101       |          Superior                |      RM 180                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 102       |          Deluxe                  |      RM 200                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 103       |          Studio                  |      RM 250                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 104       |    Executive  Suite              |      RM 400                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 105       |      Deluxe suite                |      RM 500                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 201       |          Superior                |      RM 180                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 202       |          Deluxe                  |      RM 200                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 203       |          Studio                  |      RM 250                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 204       |    Executive  Suite              |      RM 400                   |");
    printf("\n|______________________________________________________________________________");
    printf("\n|           |                                  |                               |");
    printf("\n| 205       |      Deluxe suite                |      RM 500                   |");
    printf("\n|______________________________________________________________________________");
}

// Room booking function
void Room_booking()
{
    double total_charge;
    FILE *FP = fopen("customer.txt", "a");
    char roomID[5];
    char option;

    printf("   ******************************  |Customer Details Registration|  **************************** \n");

    // using swtich to make it easy access
    // user can dorectly choose a room, it will update automatically the room price and type.
    printf("1-RoomID = 101\t\t2-RoomID = 102\n3-RoomID = 103\t\t4-RoomID = 104\n5-RoomID = 105\t\t6-RoomID = 201\n7-RoomID = 202\t\t8-RoomID = 203\n9-RoomID = 204\t\t10-RoomID = 205\n");
    printf("Please Enter number to choose Room :  ");
    scanf(" %s", &option);
    switch (option)
    {
    case '1':

        strcpy(c.roomID, "101");
        strcpy(c.room_type, "Superior");
        c.room_price = 180;
        break;
    case '2':
        strcpy(c.roomID, "102");
        strcpy(c.room_type, "Deluxe");
        c.room_price = 200;
        break;
    case '3':
        strcpy(c.roomID, "103");
        strcpy(c.room_type, "Studio");
        c.room_price = 250;
        break;
    case '4':
        strcpy(c.roomID, "104");
        strcpy(c.room_type, "Executive Suite");
        c.room_price = 400;
        break;
    case '5':
        strcpy(c.roomID, "105");
        strcpy(c.room_type, "Deluxe Suite");
        c.room_price = 180;
        break;
    case '6':
        strcpy(c.roomID, "201");
        strcpy(c.room_type, "Superior");
        c.room_price = 180;
        break;
    default:
        break;
    }
    printf("\nEnter Customer name: ");
    scanf("%s", &c.Name);
    printf("\nEnter customer Address: ");
    scanf("%s", &c.address);
    printf("\nEnter Customer Phone: ");
    scanf("%s", &c.phone);
    printf("\nEnter Customer email: ");
    scanf("%s", &c.email);
    printf("\nEnter Customer Nationality: ");
    scanf("%s", &c.nationality);
    printf("\nEnter Customer Date of Birth: ");
    scanf("%s", &c.DoB);
    printf("\nEnter Customer Ic or Passport: ");
    scanf("%s", &c.Ic_or_passport);
    printf("\nEnter Customer Arrival date: ");
    scanf("%s", &c.arrival_date);
    printf("\nEnter number of days to stay: ");
    scanf("%lf", &c.number_of_days);

    total_charge = (((c.number_of_days * c.room_price) + (c.number_of_days * 10)) * 0.10) + ((c.number_of_days * c.room_price) + (c.number_of_days * 10));
    c.total = total_charge;
    printf("The total amount is %lf: ", c.total);

    fwrite(&c, sizeof(c), 1, FP); //write to the file
    fclose(FP);
    printf("\n <> RECORD CREATED SUCCESSFULLY <>\n");

    return;
}

// Displaying customer info Function
void Display_customer_Record()
{
    FILE *filep = fopen("customer.txt", "r");
    while (fread(&c, sizeof(c), 1, filep))
    {
        printf("\nID       : %s", c.roomID);
        printf("\nRoomPrice: %.2f", c.room_price);
        printf("\nRoomType : %s", c.room_type);
        printf("\nname     : %s", c.Name);
        printf("\naddress  : %s", c.address);
        printf("\nphone    : %s", c.phone);
        printf("\nDoB      : %s", c.DoB);
        printf("\nemail    : %s", c.email);
        printf("\nIc or Pas: %s", c.Ic_or_passport);
        printf("\nNationali: %s", c.nationality);
        printf("\nArrival  : %s", c.arrival_date);
        printf("\nDayToStay: %.2f", c.number_of_days);
        printf("\nTotal Charge: %.2f", c.total);
        printf("\n-----------------------------------------------\n");
    }
    fclose(filep);
    return;
}

// function for searching an existing customer
void Search_customer()
{
    FILE *FP = fopen("customer.txt", "r");
    char roomID[5];
    printf("\nEnter Room ID: ");
    scanf(" %s", &roomID);
    while (fread(&c, sizeof(c), 1, FP))
    {
        if (strcmp(roomID, c.roomID) == 0)
        {
            printf("\nID       : %s", c.roomID);
            printf("\nRoomPrice: %.2f", c.room_price);
            printf("\nRoomType : %s", c.room_type);
            printf("\nname     : %s", c.Name);
            printf("\naddress  : %s", c.address);
            printf("\nphone    : %s", c.phone);
            printf("\nDoB      : %s", c.DoB);
            printf("\nemail    : %s", c.email);
            printf("\nIc or Pas: %s", c.Ic_or_passport);
            printf("\national  : %s", c.nationality);
            printf("\nArrival  : %s", c.arrival_date);
            printf("\nDayToStay: %.2f", c.number_of_days);
            printf("\n-----------------------------------------------\n");
            printf("\n");
        }        
    }
    fclose(FP);
    return;
}


// finction for editing customer information
void Edit_customer_info()
{

    FILE *fp1;
    FILE *fp2;
    char roomID[5];
    fp1 = fopen("customer.txt", "r");
    fp2 = fopen("New_customer.txt", "w");
    printf("\nEnter Room ID: ");
    scanf(" %s", &roomID);

    while (fread(&c, sizeof(c), 1, fp1))
        if (roomID == c.roomID){
            continue;
        }
        else {
            printf("Room ID  Found");       
        }

    fclose(fp1);
    fclose(fp2);
    remove("customer.txt");
    rename("New_customer.txt", "customer.txt");
    printf("\n");
    printf("Please Edit your personal information");

    fp1 = fopen("customer.txt", "a");

    printf("\nEnter Customer name: ");
    scanf("%s", &c.Name);
    printf("\nEnter customer Address: ");
    scanf("%s", &c.address);
    printf("\nEnter Customer Phone: ");
    scanf("%s", &c.phone);
    printf("\nEnter Customer email: ");
    scanf("%s", &c.email);
    printf("\nEnter Customer Nationality: ");
    scanf("%s", &c.nationality);
    printf("\nEnter Customer Date of Birth: ");
    scanf("%s", &c.DoB);
    printf("\nEnter Customer Ic or Passport: ");
    scanf("%s", &c.Ic_or_passport);
    printf("\nEnter Customer Arrival date: ");
    scanf("%s", &c.arrival_date);
    printf("\nEnter number of days to stay: ");
    scanf("%.2f", &c.number_of_days);

    if (fp1 != NULL)
    {
        fwrite(&c, sizeof(c), 1, fp1); //write to the file
    }

    fclose(fp1);
    printf("Details successfully Updated");
    printf("\n");
    return;
}