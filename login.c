#include <stdio.h>
#include <string.h>

struct user {
	char username[20];
	char mail[30];
	char pass[20];
	char phone[12];
};

//*************************polyFunctions*****************************

//this fuction check if this person creat an account before

int checkAcc(char ch[20]){
    FILE *f=fopen("login.dat","rb");
    if(f==NULL){
        printf("\n\t------Error-----");
        return 1;
    }

    struct user u ;

    while(fread(&u,sizeof(struct user),1,f)==1){
        if(strcmp(u.username,ch)==0){
            fclose(f);
            return 1 ;
        }

    }
    fclose(f);
    return 0 ;
}



//this function check if the file exist else it create it
void checkfile(){
    FILE *f = fopen("login.dat","rb");
    if(f==NULL){
        FILE *f= fopen("login.dat","ab");
    }


}


//this fuction check if the password correct or not
int correctPass(char name[20], char pass[20]){
    FILE *f = fopen("login.dat","rb");
    struct user u ;

    while (fread(&u,sizeof(struct user),1,f)==1){
        if(strcmp(u.username,name)==0){
            fclose(f);
            if(strcmp(u.pass,pass)==0){
                return 1 ;
            }
            else{
            return 0;
            }

    }}
    fclose(f);
    return 0;

}


//************************************************************

//***************************************************Sign in Operation *****************************************************

void sign_in(){

    checkfile();
    //read data
    struct user u ;
	printf("\nUsername : ");
	scanf("%s",u.username);
	while (checkAcc(u.username)==1){
        printf("\tThis user name exisit before !! \n==> ");
        scanf("%s",&u.username);
	}
	printf("\nMail : ");
	scanf("%s",u.mail);
	printf("\nEnter password : " );
	scanf("%s",u.pass);
    printf("\nPhone number : " );
	scanf("%s",u.phone);


	//storing data in login.dat

	//1 : opening file

	FILE *f =fopen("login.dat","ab");

	//2 ; checking the opening of the file

	if (f==NULL){
        printf("Error while opening login.dat");
        return;
	}

	//3 : data storing
	fwrite(&u,sizeof(struct user),1,f);
	printf("\n\t\tyou have been created an account !!! ");

	//4 : closing file
	fclose(f);





}


//******************************************************************************************************************




//******************************************************login operations********************************************

void displayAcc(char username[20]){
    printf("\n***** Welcome back %s :) *****");
    FILE *f= fopen("login.dat","rb");
    struct user u ;
    while(fread(&u,sizeof(struct user),1,f)==1){
        if(strcmp(username,u.username)==0){
            printf("\n____________________________________\n");
            printf("Username  : %s\n",u.username);
            printf("Mail  : %s\n",u.mail);
            printf("Password  : %s\n",u.pass);
            printf("Phone number  : %s\n",u.phone);
            printf("____________________________________\n");
            fclose(f);
            return ;


        }
    }

}
void login(){
    char username[20];
    printf("\n\nenter your username : ");
    scanf("%s",username);
    if(checkAcc(username)==1){
        printf("Enter your password : ");
        char pass[20];
        scanf("%s",pass);
        if(correctPass(username,pass)){
            displayAcc(username);
        }
        else{
            printf("\n\t password doesn't match !! ");
        }
    }else{
        printf("\n\tThis username does not exist !!");
    }




}
//*******************************************************************************************************************


//********************************************************Deleting operations****************************************
void delOperation(char ch[20]){
    FILE * f =fopen("login.dat","rb");
    if(f==NULL){
        printf("\n\t\t Error while opening file !!");
        return ;
    }
    int i = 0 ;
    struct user t[100];
    struct user u ;
    while(fread(&u,sizeof(struct user),1,f)==1){
                if(strcmp(ch,u.username)!=0){
                    t[i]=u;
                    i++;
                }
    }
    fclose(f);
    f =fopen("login.dat","wb");
    for(int j =0; j<=i;j++){
        u=t[i];
        fwrite(&t[j],sizeof(struct user),1,f);
    }
    printf("\n\t\tAccount deleted ... .. .");
    fclose(f);



}




void deleteAcc(){
    checkfile();
    char ch[20];
    printf("\nEnter the username : ");
    scanf("%s",ch);
    if(checkAcc(ch)==0){
        printf("\nThis username does not exist !!");
        return ;
    }
    else{
        char pass[20];
        printf("Enter %s password's : ",ch);
        scanf("%s",pass);
        if (correctPass(ch,pass)){
            delOperation(ch);
        }
        else{
            printf("\n\tIncorrect password !!");
        }

    }



}
//*****************************************************************************************************************************


int main(){
    printf("\n\t\t\t---------------- Welcome to authentication system ---------------\n");
	printf("\n\n");
    while(1){

	//welcome ligne



	//display options
	printf("Select your operation :\n");
	printf("1 : sign in \n");
	printf("2 : Login \n");
    printf("3 : Delete account \n");
	printf("4 : Exit \n ");
	printf("\n\n");


	//choose option

	printf("Your option ==> ");
	int n ;
	scanf("%d",&n);

	while( (n<1) || (n>4)){
		printf("option invalide !!\n");
		printf("==> ");
		scanf("%d",&n);
	}
    if(n==4){
        return 0;
    }
    else{
    	switch (n){
        case 1 :
            sign_in();
            break ;

        case 2 :
            login();
            break ;
        case 3 :
            deleteAcc();
            break ;
        case 4 :
            printf("\n\t\tExiting ... .. .\n");
            break;
    	}

        }


    }
}

