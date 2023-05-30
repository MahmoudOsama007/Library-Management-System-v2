#ifndef LIBRARY-MANGMENT-SYSTEM-DATASTRUCURE_H_INCLUDED
#define LIBRARY-MANGMENT-SYSTEM-DATASTRUCURE_H_INCLUDED

/********** struct of adding New Users **********/
typedef struct NewUser{

char Newusername[50];
char NewPassword[50];
struct NewUser*NextUser;

}NewReg;



/********** functions prototype of ADDING,DELETE New Users **********/
NewReg* createNewuser();
NewReg* addingUsers(NewReg*head_Reg);
int deletingUsers(NewReg*head_Reg);
void ReadingUsers(NewReg*head_Reg);
int FindUser(NewReg*head_Reg,char* Username,char* password);
/********************** Main Functions of (ADDING,DELETE New Users) **********************/
/********** adding New Users Function *********/
NewReg* addingUsers(NewReg*head_Reg)
{

static NewReg*New_Reg,*temp_Reg;

New_Reg=(NewReg*)malloc(sizeof(NewReg));
char d_User[50];
char d_Password[50];

printf("Enter The name of the new User : ");
scanf("%s",d_User);
printf("Enter The Password of the new User : ");
scanf("%s",d_Password);

if(head_Reg->NextUser == NULL){
head_Reg->NextUser=New_Reg;
temp_Reg = head_Reg;
}

// New_Reg->Newusername=d;
memcpy(New_Reg->Newusername,d_User,sizeof(d_User));
memcpy(New_Reg->NewPassword,d_Password,sizeof(d_Password));
New_Reg->NextUser = NULL;

temp_Reg->NextUser=New_Reg;
temp_Reg=temp_Reg->NextUser;

return New_Reg;

}


/********** deleting Users Function **********/
int deletingUsers(NewReg*head_Reg)
{
int x,i=1;
printf("which one do you wanna delete \n");
ReadingUsers(head_Reg);
printf(" \n");

scanf("%d",&x);
NewReg * temp=head_Reg,*current;
while(i<x-1){
    temp = temp->NextUser;
    i++;
}
current = temp->NextUser;
temp->NextUser = current->NextUser;
free(current);
return 1 ;
}

/********** Reading Users Function **********/
void ReadingUsers(NewReg*head_Reg)
{

NewReg* ptr=head_Reg;

while(ptr != NULL){
printf("%s\n",ptr->Newusername);
ptr=ptr->NextUser;
}

}

/********** create Newuser Function **********/

NewReg* createNewuser(){
 NewReg* head_Reg = (NewReg*)malloc(sizeof(NewReg));
            head_Reg->NextUser=NULL;

    return head_Reg;
}

/********** Finding New Users Function *********/
int FindUser(NewReg*head_Reg,char* Username,char* password){



            NewReg *ptr_Reg = head_Reg;

            while(ptr_Reg!=NULL){
            int value1 = strcmp(Username , ptr_Reg->Newusername );
            int value2 = strcmp(password ,ptr_Reg->NewPassword );

            if((value1 == 0) && (value2 == 0))
            {

                return 1;

            }

             ptr_Reg=ptr_Reg->NextUser;

                }

return 0;

}


/********** struct of Reading,ADDING,DELETE BOOKS **********/
typedef struct readbook{

char data[50];

struct readbook* next;

}read;

/********** functions prototype of Reading,ADDING,DELETE BOOKS **********/
read* create();
void Reading(read*head);
read* adding(read*head);
int deleting(read*head);

/********************** Main Functions of (Reading,adding,deleting) **********************/


/********** create the linked List **********/
read* create(){
struct readbook* head = (struct readbook*)malloc(sizeof(struct readbook));

    memcpy(head->data,"lab",sizeof("lab"));

    head->next=NULL;

    return head;
}



/********** Reading BOOKS Function **********/
void Reading(read*head)
{

struct readbook* ptr=head;

while(ptr != NULL){
printf("%s\n",ptr->data);
ptr=ptr->next;
}

}


/********** adding BOOKS Function *********/
read* adding(read*head)
{

static read*New_book,*temp;





New_book=(read*)malloc(sizeof(read));
char d[50];

printf("Enter The name of the new book : ");
scanf("%s",d);

if(head->next == NULL){
head->next=New_book;
temp = head;
}

// New_book->data=d;
memcpy(New_book->data,d,sizeof(d));
New_book->next = NULL;

temp->next=New_book;
temp=temp->next;

return New_book;

}








/********** deleting BOOKS Function **********/
int deleting(read*head)
{
int x,i=1;
printf("which one do you wanna delete \n");
Reading(head);
printf(" \n");

scanf("%d",&x);
read * temp=head,*current;
while(i<x-1){
    temp = temp->next;
    i++;
}
current = temp->next;
temp->next = current->next;
free(current);
return 1 ;
}





#endif // LIBRARY-MANGMENT-SYSTEM-DATASTRUCURE_H_INCLUDED
