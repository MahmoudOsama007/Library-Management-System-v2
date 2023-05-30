#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Library-mangment-system-DataStrucure.h"



        /************************************ Library management system ************************************/




/********** Main Code **********/






int main()
{

    read* head = create();

    NewReg*head_Reg = createNewuser();

    while(1)

    {

        printf("\n\t\t\t\t Hello world!\n"
               "\t /****** This is Library management system project ******/ \n\n\n");

        char rechoose = 0;
        char choose_mesode = 0;
        static char Username[50],password[50],User[50]={0},pass[50]={0};

        printf("\t 1 - Login\n"
               "\t 2 - Reigster \n");
        printf("YOUR CHOISE IS : \n");
        scanf("%d",&choose_mesode);

        switch(choose_mesode)
        {

        /******** case 1 Represent Login *********/

        case 1:

            /******** Login *********/

            printf("\t Please Enter your Username\n "
                   "\t  Username : ");
            scanf("%s",&Username);
            printf("\t Please Enter your password \n"
                   "\t  password : ");
            scanf("%s",&password);
            printf("\t\n your Username %s password %s \n",Username,password);

            /******** ADMIN Login *********/
            int val1 = strcmp(Username , "admin" );
            int val2 = strcmp(password ,"admin");
            if((val1 == 0) &&(val2 == 0) )
            {
                printf("\n\n****\tLogin Successful\t****\n\n");
                printf("\t Welcome admin \n"
                       "\t What do you want to do Admin\n");
                printf("1 - READ BOOKS\n"
                       "2 - DELETE BOOK\n"
                       "3 - ADD BOOK \n"
                       "4 - LOGOUT\n"
                       "5 - Exit \n");
                while(1){
                int dd;
                printf("Your choise : ");
                scanf("%d",&dd);

                switch (dd){
                    case 1 :// Reading
                        Reading(head);
                        break;


                    case 2 :// deleting
                        deleting(head);
                        break;

                    case 3 :// add
                        adding(head);
                        break;


                    case 4 :// Logout
                        break;

                    case 5 :// Logout
                        exit(1);





                }//admin choises

                printf("\n\n\n\t\t DO YOU wanna continue  : \n"
                       "1- continue LOGIN \n"
                       "2- LOGOUT \n"
                       " your choise is : \n");
                       scanf("%d",&rechoose);

                       switch (rechoose){
                       case 1 :continue;
                       case 2 : break;
                       }break;


                }//admin Logout

            }//admin login
            /******** Admin code is finished don't change it  *********/

            /******** USER Login *********/
            char ch = 0;

            int n =  FindUser(head_Reg,Username,password);
            if(n == 1)
            {
                 while(1){
                printf("\n\n****\tLogin Successful\t****\n\n");
                printf("\t Welcome %s\n "
                       "\t What do you want to do %s \n");
                printf("1 - READ BOOKS\n"
                       "2 - LOGOUT\n",User,User);
                       printf("Enter your choise : ");
                       scanf("%d",&ch);

                       switch (ch){
                       case 1 :Reading(head);break;
                       case 2 : exit(1);
                       }
                }
            }
            else{
                printf("\n\n****\tLogin Faild\t****\n\n");
                getchar();
                }


             printf("\n\n\n\t\t You ARE NOT Register DO YOU wanna SIGNUP : \n"
                       "1- continue \n"
                       "2- Register \n"
                       " your choise is : \n");
                       scanf("%d",&rechoose);

                       switch (rechoose){
                       case 1 :continue;
                       case 2 : break;
                       }
                       break;






        /******** case 2 Represent Reigisteration *********/


        case 2:
            addingUsers(head_Reg);

            break;


        }//Switch
        }//while



    return 0;
}

