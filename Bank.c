#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct account
{
    char id[20];
    char name[256];
    int age;
    char gender[256];
    char nationality[256];
    char address[256];

}ac[100];

int fetch_by_ac_no(unsigned long long int x)
{
    int ii;
    ii=x%100;
    return ii;
}

int main()
{
    FILE *individual_acc_info, *del_individual_acc_info, *f_acc_srl, *ps_wrd_c, *ps_wrd, *accounts, *balance, *transaction;
    int i=0, p=0;

    f_acc_srl=fopen("Accounts\\acc_serial.txt", "r");                 //Account Serial Check
    fscanf(f_acc_srl, "%d", &i);
    fclose(f_acc_srl);

    ps_wrd_c=fopen("Passwords\\ps_wrd_c.txt", "r");                    //Check whether a password is set or not
    fscanf(ps_wrd_c, "%d", &p);
    fclose(ps_wrd_c);
 
    check:
    int opt, chs, j;
    char pass[11],password[11];
    while(p==0)
    {
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n::::::::::::::::::::ULAB BANK::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\nEnter a New security password(max 10digits) : ");
    scanf("%s",password);

    ps_wrd=fopen("Passwords\\ps_wrd.txt", "w");                        //New Password Set
    fputs(password, ps_wrd);
    fclose(ps_wrd);

    p++;
    ps_wrd_c=fopen("Passwords\\ps_wrd_c.txt", "w");                    //Write down that password has been set
    fprintf(ps_wrd_c, "%d", p);
    fclose(ps_wrd_c);

    printf("\nYour Password is : %s", password);
    printf("\nRemember Your Password");
    printf("\nPress Enter to go to Main Menu");
    if (getch())
    {
        system("cls");
        goto check;
    }
    }

    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n::::::::::::::::::::ULAB BANK::::::::::::::::::::");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
    printf("\n\n\tEnter the security password to login: ");
    scanf("%s",pass);
    char password_c[11];

    ps_wrd=fopen("Passwords\\ps_wrd.txt", "r");                        //Read original Password
    fgets(password_c, 11, ps_wrd);
    fclose(ps_wrd);

    if (strcmp(pass,password_c)==0)                         //Compare inputted password with original
    {
        system("cls");
        goto main_menu;
    }
    else
    {
        system("cls");
        printf("\n......Wrong Password......\n");
        goto check;
    }
    
    main_menu:
    printf("\n::::::::::::::::::::ULAB BANK::::::::::::::::::::");
    printf("\n\n\t\tWelcome To Main Menu\n\n");
    printf("\n1. Create New Account");
    printf("\n2. Update Information of Existing Account");
    printf("\n3. View Informations of Existing Account");
    printf("\n4. Delete Account");
    printf("\n5. Info of Deleted Accounts");
    printf("\n6. Do Transaction");
    printf("\n7. View Customers' List");
    printf("\n8. EXIT");
    printf("\n\nChoose your option : ");
    scanf("%d", &opt);
    system("cls");

    switch (opt)
    {
    case 1:                                                                //CASE 1 HERE   Create Account
        if (i<100)
        {
            printf("\n:::::::::Account Creating:::::::::\n");

            fflush(stdin);
            printf("\nEnter 9 Digit Student ID : ");
            gets(ac[i].id);

            fflush(stdin);
            printf("\nEnter Full Name of A/C holder : ");
            gets(ac[i].name);

            printf("\nEnter Age : ");
            scanf("%d", &ac[i].age);

            printf("\nEnter Gender : ");
            scanf(" %s", ac[i].gender);

            printf("\nEnter Nationality : ");
            scanf("%s", ac[i].nationality);

            fflush(stdin);
            printf("\nEnter Address : ");
            gets(ac[i].address);

            char filename[20]="Accounts\\acc";                                // Create individual Text File for each account
            char f[20];
            char e[20]=".txt";
            sprintf(f, "%d", i);
            strcat(filename, f);
            strcat(filename, e);

            individual_acc_info=fopen(filename, "w");
            fprintf(individual_acc_info, "::::::::::::::   %d   ::::::::::::::\n", i+1);
            fprintf(individual_acc_info, "ID NO:\t\t\t%s\n", ac[i].id);

            char z[]="000";                                         // Create Account Number
            char s[]="";
            if (i>=0 && i<10)
            {
                strncat(ac[i].id, z, 2);
            }
            else if (i>=10 && i<100)
            {
                strncat(ac[i].id, z, 1);
            }
            sprintf(s,"%d", i);
            strcat(ac[i].id, s);
            accounts=fopen("Accounts\\acc_no.txt", "a");                       //Store All Account Numbers
            fprintf(accounts, "%s", ac[i].id);
            fprintf(accounts,"\n");
            fclose(accounts);
            fprintf(individual_acc_info, "A/C NO:\t\t\t%s\n", ac[i].id);           
            fprintf(individual_acc_info, "Name:\t\t\t%s\n", ac[i].name);           
            fprintf(individual_acc_info, "Age:\t\t\t%d\n", ac[i].age);           
            fprintf(individual_acc_info, "Gender:\t\t\t%s\n", ac[i].gender);            
            fprintf(individual_acc_info, "Nationality:\t\t%s\n", ac[i].nationality);            
            fprintf(individual_acc_info, "Address:\t\t%s\n", ac[i].address);            
            fprintf(individual_acc_info, "\n");
            fclose(individual_acc_info);
            
            system("cls");
            i=i+1;

            f_acc_srl=fopen("Accounts\\acc_serial.txt", "w");           //write account serial
            fprintf(f_acc_srl, "%d", i);
            fclose(f_acc_srl);

            printf("\n::::::::::::Account Successfully Created::::::::::::\n");
            printf("\n:::::   Your Account Number is : %s   ::::\n", ac[i-1].id);

            printf("\nEnter ' 1 ' to go to Main Menu");
            printf("\nEnter ' 0 ' to go to Exit\n");

            fflush(stdin);
            scanf("%d", &chs);
            if (chs==1)
            {
                system("cls");
                goto main_menu;
            }
            else if(chs==0)
            {
                system("cls");
                printf("::::::::::::::::::::::::::::::::::");
                printf("\n  Thanks For Using Our Services\n");
                printf("::::::::::::::::::::::::::::::::::");
            }
        }
        break;

    case 2:;                                                                //Case 2 Update
            chc_upt:
            int jjj;
            unsigned long long int fetch_acc_u;
            char aa_check[20];
            char aa_check_a[20];
            char c3u_check_a[20];
            char pass_m[11];
            printf("\n::::::::::::      Update Details      :::::::::::\n");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n:::::::::::::::     ULAB BANK     :::::::::::::::");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\n\tEnter the Security password to Update: ");
            scanf("%s",pass_m);

            char password_cc[11];
            ps_wrd=fopen("Passwords\\ps_wrd.txt", "r");                                //Read original Password
            fgets(password_cc, 11, ps_wrd);
            fclose(ps_wrd);

            if (strcmp(pass_m,password_cc)==0)                              // Can Update if password is right
            {
                try_again:
                    system("cls");
                    printf("\n::::::::::::      Update Details      :::::::::::\n");
                    printf("Enter your Account NO : ");                             //Takes integer to find account serial
                    scanf("%llu", &fetch_acc_u);
                    jjj=fetch_by_ac_no(fetch_acc_u);
                    printf("Again\nEnter your Account NO : ");                      //Takes string to confirm whether the account exists or not
                    scanf("%s", aa_check);

                    int start, a_check=0;

                    accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( start = 0; start < i; start++)
                    {
                    fscanf(accounts, "%s ", aa_check_a);

                    if (strcmp(aa_check,aa_check_a)==0)
                    {
                        a_check++;
                    }
                    }
                    fclose(accounts);

                    int c3v_check=0;
                    accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for (int c3lstart = 0; c3lstart < 50; c3lstart++)
                    {
                    fscanf(accounts, "%s ", c3u_check_a);
                    if (c3v_check==1)
                    {
                        break;
                    }
                    if (strcmp(aa_check, c3u_check_a)==0)
                    {
                        c3v_check++;
                    }
                    }
                    fclose(accounts);

                if (a_check==1  && c3v_check==0)                                             //if accounts found
                {
                    system("cls");
                    printf("\n::::::::::::      A/C NO Matched      :::::::::::\n");
                    char filename_eee[20]="Accounts\\acc";                            //Create Filename and Open The specific text file for Individual Account
                    char fff[20];
                    char eee[20]=".txt";
                    sprintf(fff, "%d", jjj);
                    strcat(filename_eee, fff);
                    strcat(filename_eee, eee);

                    fflush(stdin);
                    printf("\nEnter Student ID : ");
                    gets(ac[jjj].id);

                    fflush(stdin);
                    printf("\nEnter Full Name of A/C holder : ");
                    gets(ac[jjj].name);

                    printf("\nEnter Age : ");
                    scanf("%d", &ac[jjj].age);

                    printf("\nEnter Gender : ");
                    scanf(" %s", ac[jjj].gender);

                    printf("\nEnter Nationality : ");
                    scanf("%s", ac[jjj].nationality);

                    fflush(stdin);
                    printf("\nEnter Address : ");
                    gets(ac[jjj].address);

                    individual_acc_info=fopen(filename_eee, "w");
                    fprintf(individual_acc_info, "::::::::::::::   %d   ::::::::::::::\n", jjj+1);
                    fprintf(individual_acc_info, "ID NO:\t\t\t%s\n", ac[jjj].id);
                    char z[]="000";                                         //Create Updated A/C NO
                    char s[]="";
                    if (jjj>=0 && i<10)
                    {
                        strncat(ac[jjj].id, z, 2);
                    }
                    else if (jjj>=10 && jjj<100)
                    {
                        strncat(ac[jjj].id, z, 1);
                    }
                    sprintf(s,"%d", jjj);
                    strcat(ac[jjj].id, s);

                    fprintf(individual_acc_info, "A/C NO:\t\t\t%s\n", ac[jjj].id);           
                    fprintf(individual_acc_info, "Name:\t\t\t%s\n", ac[jjj].name);           
                    fprintf(individual_acc_info, "Age:\t\t\t%d\n", ac[jjj].age);           
                    fprintf(individual_acc_info, "Gender:\t\t\t%s\n", ac[jjj].gender);            
                    fprintf(individual_acc_info, "Nationality:\t\t%s\n", ac[jjj].nationality);            
                    fprintf(individual_acc_info, "Address:\t\t%s\n", ac[jjj].address);            
                    fprintf(individual_acc_info, "\n");
                    fclose(individual_acc_info);
                    system("cls");
                    printf("\n:::      A/C Details Updated Successfully      :::\n");
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");

                    int chss;
                    fflush(stdin);
                    scanf("%d", &chss);
                    if (chss==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(chss==0)
                    {
                        system("cls");
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::");
                    }
                }
                else
                {
                    system("cls");
                    printf("\nSorry!    No Accounts Found\nCould be deleted or inputted A/C NO is wrong\n");
                    printf("\nEnter '111' to go to Try Again");
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");

                    fflush(stdin);
                    int chss;
                    scanf("%d", &chss);
                    if (chss==111)
                    {
                        system("cls");
                        goto try_again;
                    }
                    else if (chss==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(chss==0)
                    {
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::");
                    }
                }
            }
            else
            {
                system("cls");
                printf("\n......Wrong Password......\n");
                printf("\nEnter '111' to go to Try Again");
                printf("\nEnter ' 1 ' to go to Main Menu");
                printf("\nEnter ' 0 ' to go to Exit\n");

                fflush(stdin);
                int chos;
                scanf("%d", &chos);
                if (chos==111)
                {
                    system("cls");
                    goto chc_upt;
                }
                else if (chos==1)
                {
                    system("cls");
                    goto main_menu;
                }
                else if(chos==0)
                {
                    system("cls");
                    printf("::::::::::::::::::::::::::::::::::");
                    printf("\n  Thanks For Using Our Services\n");
                    printf("::::::::::::::::::::::::::::::::::");
                }     
            }
        break;

    case 3:
            try_view:
            int iii;
            char c3_check[20];
            char c3_check_a[20];
            char c3d_check_a[20];
            unsigned long long int fetch_acc;
            printf("::::::::::::View Details:::::::::::\n\n");
            printf("Enter your Account NO : ");
            scanf("%llu", &fetch_acc);
            iii=fetch_by_ac_no(fetch_acc);

            printf("Again\nEnter your Account NO : ");    
            scanf(" %s", c3_check);

                int c3start, c3c_check=0;
                accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                for ( c3start = 0; c3start < i; c3start++)
                {
                fscanf(accounts, "%s ", c3_check_a);
                if (strcmp(c3_check, c3_check_a)==0)
                {
                    c3c_check++;
                }
                }
                fclose(accounts);
                int c3lstart, c3l_check=0;
                accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                for ( c3lstart = 0; c3lstart < 50; c3lstart++)
                {
                fscanf(accounts, "%s ", c3d_check_a);
                if (c3l_check==1)
                {
                    break;
                }
                if (strcmp(c3_check, c3d_check_a)==0)
                {
                    c3l_check++;
                }
                }
                fclose(accounts);
                if (c3c_check==1 && c3l_check==0)
                {
                    char filename_e[20]="Accounts\\acc";
                    char ff[20];
                    char ee[20]=".txt";
                    sprintf(ff, "%d", iii);
                    strcat(filename_e, ff);
                    strcat(filename_e, ee);
                    individual_acc_info=fopen(filename_e, "r");
                    system("cls");
                    printf("::::::::::::View Details:::::::::::\n");
                    int cc;
                        while (1)
                        {
                            cc=fgetc(individual_acc_info);
                            if (cc==EOF)
                            {
                                break;
                            }
                            else
                            {
                                printf("%c", cc);
                            }
                        }
                    fclose(individual_acc_info);

                    char filename_cc3[20]="Balance\\acc_bl";
                    char ff_cc3[20];
                    char ee_cc3[20]=".txt";
                    sprintf(ff_cc3, "%d", iii);
                    strcat(filename_cc3, ff_cc3);
                    strcat(filename_cc3, ee_cc3);

                    int current_balance=0;
                    balance=fopen(filename_cc3, "r");
                    fscanf(balance, "%d", &current_balance);
                    printf("\n\tCurrent Balance is : %d \n", current_balance);
                    fclose(balance);

                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");

                    int chsss;
                    fflush(stdin);
                    scanf("%d", &chsss);
                    if (chsss==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(chsss==0)
                    {
                        system("cls");
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::\n\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("\nSorry!    No Accounts Found\nAccount Could be deleted or inputted A/C NO is wrong\n");
                    printf("\nEnter '111' to go to Try again");
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");
                    int six_c3_e;
                    fflush(stdin);
                    scanf("%d", &six_c3_e);
                    if (six_c3_e==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(six_c3_e==111)
                    {
                        system("cls");
                        goto try_view;
                    }
                    else if(six_c3_e==0)
                    {
                        system("cls");
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::");
                    }
                }
        break;

    case 4:                                                                             //Case 4 delete
            chc_del:
            int jij;
            unsigned long long int fetch_acc_d;
            char d_check[20];
            char d_check_a[20];
            char pass_d[11];
            printf("\n::::::::::::      Delete Account      :::::::::::\n");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n:::::::::::::::     ULAB BANK     :::::::::::::::");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\n\tEnter the Security password to Delete: ");
            scanf("%s",pass_d);

            char password_d[11];
            ps_wrd=fopen("Passwords\\ps_wrd.txt", "r");                                //Read original Password
            fgets(password_d, 11, ps_wrd);
            fclose(ps_wrd);

            if (strcmp(pass_d,password_d)==0)                              // Can Delete if password is right
            {
                try_del:
                    system("cls");
                    printf("\n::::::::::::      Delete Account      :::::::::::\n\n");
                    printf("Enter your Account NO : ");                             //Takes integer to find account serial
                    scanf("%llu", &fetch_acc_d);
                    jij=fetch_by_ac_no(fetch_acc_d);
                    printf("Again\nEnter your Account NO : ");                      //Takes string to confirm whether the account exists or not
                    scanf("%s", d_check);

                    int d_start, ad_check=0;

                    accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( d_start = 0; d_start < i; d_start++)
                    {
                    fscanf(accounts, "%s ", d_check_a);
                    if (strcmp(d_check,d_check_a)==0)
                    {
                        ad_check++;
                    }
                    }
                    fclose(accounts);
                if (ad_check==1)                                             //if accounts found
                {
                    system("cls");
                    printf("\n::::::::::::      A/C NO Matched      :::::::::::\n");

                    char filename_d[20]="Accounts\\acc";                            //Create Filename and Open The specific text file for Individual Account
                    char ffd[20];
                    char eed[20]=".txt";
                    sprintf(ffd, "%d", jij);
                    strcat(filename_d, ffd);
                    strcat(filename_d, eed);

                    individual_acc_info=fopen(filename_d, "r");
                    del_individual_acc_info=fopen("Deleted\\all_deleted_ac.txt", "a");
                    int ccd;
                    while (1)
                    {         
                        ccd=fgetc(individual_acc_info); 
                        if (ccd==EOF)
                        {
                            break;
                        }     
                        fprintf(del_individual_acc_info, "%c", ccd);
                    }
                    fprintf(del_individual_acc_info, "\n");
                    fclose(del_individual_acc_info);
                    fclose(individual_acc_info);

                    accounts=fopen("Deleted\\deleted_acc_no.txt", "a");                       //Store All Account Numbers
                    fprintf(accounts, "%s", d_check);
                    fprintf(accounts,"\n");
                    fclose(accounts);

                    remove(filename_d);

                    system("cls");
                    printf("\n:::::::      A/C Deleted Successfully      :::::::\n");
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");

                    int chds;
                    fflush(stdin);
                    scanf("%d", &chds);
                    if (chds==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(chds==0)
                    {
                        system("cls");
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::");
                    }
                }
                else
                {
                    system("cls");
                    printf("\nSorry!    No Accounts Found\nCould be deleted or inputted A/C NO is wrong\n");
                    printf("\nEnter '111' to go to Try Again");
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");

                    fflush(stdin);
                    int chss;
                    scanf("%d", &chss);
                    if (chss==111)
                    {
                        system("cls");
                        goto try_del;
                    }
                    else if (chss==1)
                    {
                        system("cls");
                        goto main_menu;
                    }
                    else if(chss==0)
                    {
                        system("cls");
                        printf("::::::::::::::::::::::::::::::::::");
                        printf("\n  Thanks For Using Our Services\n");
                        printf("::::::::::::::::::::::::::::::::::");
                    }
                }
            }
            else
            {
                system("cls");
                printf("\n......Wrong Password......\n");
                printf("\nEnter '111' to go to Try Again");
                printf("\nEnter ' 1 ' to go to Main Menu");
                printf("\nEnter ' 0 ' to go to Exit\n");

                fflush(stdin);
                int chd;
                scanf("%d", &chd);
                if (chd==111)
                {
                    system("cls");
                    goto chc_del;
                }
                else if (chd==1)
                {
                    system("cls");
                    goto main_menu;
                }
                else if(chd==0)
                {
                    system("cls");
                    printf("::::::::::::::::::::::::::::::::::");
                    printf("\n  Thanks For Using Our Services\n");
                    printf("::::::::::::::::::::::::::::::::::");
                }
            }      
        break;

    case 5:                                                                         //Case 5 delete view
        printf("\n::::::::::::     Deleted Accounts     :::::::::::\n");
        int five_opt;
        printf("\n1. Show all deleted Accounts");
        printf("\n2. Show all deleted Account NUMBERS");
        printf("\n3. Return to Main Menu\n");
        printf("\n  Choose your options : ");
        scanf("%d", &five_opt);
        switch (five_opt)
        {
        case 1:                                                                     //Case 5- 1
            system("cls");
            int dbr;
            printf("\n::::::::::::     Deleted Accounts     :::::::::::\n\n");
            del_individual_acc_info=fopen("Deleted\\all_deleted_ac.txt", "r");
            while (1)
            {
                dbr=fgetc(del_individual_acc_info);
                if (dbr==EOF)
                {
                    break;
                }
                else
                {
                    printf("%c", dbr);
                }
                    
            }
            fclose(del_individual_acc_info);

            printf("\nEnter ' 1 ' to go to Main Menu");
            printf("\nEnter ' 0 ' to go to Exit\n");
            fflush(stdin);
            int chdbr;
            scanf("%d", &chdbr);
            if (chdbr==1)
            {
                system("cls");
                goto main_menu;
            }
            else if(chdbr==0)
            {
                system("cls");
                printf("::::::::::::::::::::::::::::::::::");
                printf("\n  Thanks For Using Our Services\n");
                printf("::::::::::::::::::::::::::::::::::");
            }
            break;
        
        case 2:                                                                 //Case 5- 2
            system("cls");
            int dbrn;
            printf("\n:::::::::::   Deleted Account's NOs'   ::::::::::\n\n");
            del_individual_acc_info=fopen("Deleted\\deleted_acc_no.txt", "r");
            while (1)
            {
                dbrn=fgetc(del_individual_acc_info);
                if (dbrn==EOF)
                {
                    break;
                }
                else
                {
                    printf("%c", dbrn);
                }
                    
            }
            fclose(del_individual_acc_info);

            printf("\nEnter ' 1 ' to go to Main Menu");
            printf("\nEnter ' 0 ' to go to Exit\n");
            int chdbrn;
            fflush(stdin);
            scanf("%d", &chdbrn);
            if (chdbrn==1)
            {
                system("cls");
                goto main_menu;
            }
            else if(chdbrn==0)
            {
                system("cls");
                printf("::::::::::::::::::::::::::::::::::");
                printf("\n  Thanks For Using Our Services\n");
                printf("::::::::::::::::::::::::::::::::::");
            }
            break;
        case 3:            
            system("cls");                                                 //Case 5- 3
            goto main_menu;
            break;
        default:
            printf("\n::::::     Wrong Input     ::::::");
            break;
        }
        break;

    case 6:
            chc_balance:
            int jii, c6c2i, c6c3i, c6c3_rcv_i, bfr_snd_amt, bfr_rcv_amt=0, sending_amount, new_amount_send, new_amount_receive, past_amount_with=0, withdraw_amount, new_amount_with, bfr_dep_amt=0, aft_dpt_amt;
            unsigned long long int fetch_acc_bl;
            char bl_check[20];
            char bl_check_a[20];
            char pass_bl[11];
            printf("\n:::::::::::::::    Transactions   :::::::::::::::\n");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n:::::::::::::::     ULAB BANK     :::::::::::::::");
            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::");
            printf("\n\n\tEnter the Security password for Transactions: ");
            scanf("%s",pass_bl);

            char password_bl[11];
            ps_wrd=fopen("Passwords\\ps_wrd.txt", "r");                                //Read original Password
            fgets(password_bl, 11, ps_wrd);
            fclose(ps_wrd);

            if (strcmp(pass_bl,password_bl)==0)   
            {
                transaction:
                system("cls");
                printf("\n:::::::::::::::    Transactions   :::::::::::::::\n");
                printf("\n1. Deposit Money");
                printf("\n2. Withdraw Money");
                printf("\n3. Send Money");
                printf("\n4. Return to Main Menu");
                printf("\n5. Show Transactions\n");
                printf("\n  Choose your option : ");
                int six_opt;
                scanf("%d", &six_opt);
                switch (six_opt)
                {
                case 1:
                    dep_try:
                    system("cls");
                    printf(":::::::::::::::   Deposit Money   :::::::::::::::\n\n");
                    printf("Enter your Account NO : ");                             //Takes integer to find account serial
                    scanf("%llu", &fetch_acc_bl);
                    jii=fetch_by_ac_no(fetch_acc_bl);
                    
                    printf("Again\nEnter your Account NO : ");                      //Takes string to confirm whether the account exists or not
                    scanf(" %s", bl_check);

                    int blstart, bbl_check=0;
                    accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( blstart = 0; blstart < i; blstart++)
                    {
                    fscanf(accounts, "%s ", bl_check_a);
                    if (strcmp(bl_check, bl_check_a)==0)
                    {
                        bbl_check++;
                    }
                    }
                    fclose(accounts);

                    int dblstart, dbl_check=0;
                    accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( dblstart = 0; dblstart < 50; dblstart++)
                    {
                    fscanf(accounts, "%s ", bl_check_a);
                    if (dbl_check==1)
                    {
                        break;
                    }
                    if (strcmp(bl_check, bl_check_a)==0)
                    {
                        dbl_check++;
                    }
                    }
                    fclose(accounts);

                    if (bbl_check==1 && dbl_check==0)
                    {
                        int dep_amnt;
                        char acbl[20]="Balance\\acc_bl";                                // Create individual Text File for each account
                        char ffbl[20];
                        char ebl[20]=".txt";
                        sprintf(ffbl, "%d", jii);
                        strcat(acbl, ffbl);
                        strcat(acbl, ebl);

                        balance=fopen(acbl, "r");
                        fscanf(balance, "%d", &bfr_dep_amt);
                        fclose(balance);

                        system("cls");
                        balance=fopen(acbl, "w");
                        printf("Enter the Amount : ");
                        scanf("%d", &dep_amnt);

                        aft_dpt_amt=bfr_dep_amt+dep_amnt;

                        fprintf(balance, "%d", aft_dpt_amt);
                        system("cls");
                        printf(":::::::::   Deposit Money Successfully   :::::::::\n");
                        printf("\n%d amount of money has been deposited to %s\n", dep_amnt, bl_check);
                        printf("\n\tCurrent balance is : %d \n",aft_dpt_amt);
                        transaction=fopen("history.txt", "a");
                        fprintf(transaction, "\n%d    amount of money has been ::  deposited  :: to ::   %s  ::\n", dep_amnt, bl_check);
                        fprintf(transaction, "\n");
                        fclose(transaction);
                        fclose(balance);

                        printf("\nEnter ' 1 ' to go to Main Menu");
                        printf("\nEnter ' 0 ' to go to Exit\n");
                        int six_c1;
                        fflush(stdin);
                        scanf("%d", &six_c1);
                        if (six_c1==1)
                        {
                            system("cls");
                            goto main_menu;
                        }
                        else if(six_c1==0)
                        {
                            system("cls");
                            printf("::::::::::::::::::::::::::::::::::");
                            printf("\n  Thanks For Using Our Services\n");
                            printf("::::::::::::::::::::::::::::::::::");
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("\nSorry!    Can't do transactions\nAccount Could be deleted or inputted A/C NO is wrong\n");
                        printf("\nEnter '111' to go to Try again");
                        printf("\nEnter ' 1 ' to go to Main Menu");
                        printf("\nEnter ' 0 ' to go to Exit\n");
                        int six_c1_e;
                        fflush(stdin);
                        scanf("%d", &six_c1_e);
                        if (six_c1_e==1)
                        {
                            system("cls");
                            goto main_menu;
                        }
                        else if(six_c1_e==111)
                        {
                            system("cls");
                            goto dep_try;
                        }
                        else if(six_c1_e==0)
                        {
                            system("cls");
                            printf("::::::::::::::::::::::::::::::::::");
                            printf("\n  Thanks For Using Our Services\n");
                            printf("::::::::::::::::::::::::::::::::::");
                        }
                    }
                    break;

                case 2:
                    with_try:
                    system("cls");
                    unsigned long long int fetch_acc_c6c2;
                    char c6c2_check[20];
                    char c6c2_check_a[20], c6_c2_check_a[20];
                    printf("::::::::::::::    Withdraw Money   :::::::::::::::\n\n");
                    printf("Enter your Account NO : ");                             //Takes integer to find account serial
                    scanf("%llu", &fetch_acc_c6c2);
                    c6c2i=fetch_by_ac_no(fetch_acc_c6c2);
                    
                    printf("Again\nEnter your Account NO : ");                      //Takes string to confirm whether the account exists or not
                    scanf(" %s", c6c2_check);

                    int c6c2start, c6c2_check_=0;
                    accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( c6c2start = 0; c6c2start < i; c6c2start++)
                    {
                    fscanf(accounts, "%s ", c6c2_check_a);
                    if (strcmp(c6c2_check, c6c2_check_a)==0)
                    {
                        c6c2_check_++;
                    }
                    }
                    fclose(accounts);

                    int c6_c2start, c6_c2_check_=0;
                    accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( c6_c2start = 0; c6_c2start < 50; c6_c2start++)
                    {
                    fscanf(accounts, "%s ", c6_c2_check_a);
                    if (c6_c2_check_==1)
                    {
                        break;
                    }
                    if (strcmp(c6c2_check, c6_c2_check_a)==0)
                    {
                        c6_c2_check_++;
                    }
                    }
                    fclose(accounts);

                    if (c6c2_check_==1 && c6_c2_check_==0)
                    {
                        correct_amount:
                        char f_c6c2[50]="Balance\\acc_bl";                                
                        char d_c6c2[20];
                        char e_c6c2[20]=".txt";
                        sprintf(d_c6c2, "%d", c6c2i);
                        strcat(f_c6c2, d_c6c2);
                        strcat(f_c6c2, e_c6c2);

                        balance=fopen(f_c6c2, "r");
                        fscanf(balance, "%d", &past_amount_with);
                        fclose(balance);

                        system("cls");
                        printf("Enter the Amount : ");
                        scanf("%d", &withdraw_amount);

                        if (withdraw_amount>past_amount_with)
                        {
                            printf("\n:::::::::   Sorry! Insufficient Balance   :::::::::\n");
                            printf("\nEnter '111' to go to Try again");
                            printf("\nEnter ' 1 ' to go to Main Menu");
                            printf("\nEnter ' 0 ' to go to Exit\n");
                            int six_c2_;
                            fflush(stdin);
                            scanf("%d", &six_c2_);
                            if (six_c2_==1)
                            {
                                system("cls");
                                goto main_menu;
                            }
                            else if(six_c2_==111)
                            {
                                system("cls");
                                goto correct_amount;
                            }
                            else if(six_c2_==0)
                            {
                                system("cls");
                                printf("::::::::::::::::::::::::::::::::::");
                                printf("\n  Thanks For Using Our Services\n");
                                printf("::::::::::::::::::::::::::::::::::");
                            }
                        }
                        else
                        {
                            new_amount_with=past_amount_with-withdraw_amount;

                            balance=fopen(f_c6c2, "w");
                            fprintf(balance, "%d", new_amount_with);
                            fclose(balance);

                            system("cls");
                            printf(":::::::::    Money Withdraw Successful   :::::::::\n");
                            printf("\n%d amount of money has been withdrawn from %s \n", withdraw_amount, c6c2_check);
                            printf("\nYour Current balance is : %d\n", new_amount_with);

                            transaction=fopen("history.txt", "a");
                            fprintf(transaction, "\n%d    amount of money has been ::  withdrawn  :: from ::   %s  ::\n", withdraw_amount, c6c2_check);
                            fprintf(transaction, "\n");
                            fclose(transaction);

                            printf("\nEnter ' 1 ' to go to Main Menu");
                            printf("\nEnter ' 0 ' to go to Exit\n");
                            int six_c2;
                            fflush(stdin);
                            scanf("%d", &six_c2);
                            if (six_c2==1)
                            {
                                system("cls");
                                goto main_menu;
                            }
                            else if(six_c2==0)
                            {
                                system("cls");
                                printf("::::::::::::::::::::::::::::::::::");
                                printf("\n  Thanks For Using Our Services\n");
                                printf("::::::::::::::::::::::::::::::::::");
                            }
                        }
                        
                    }
                    else
                    {
                        system("cls");
                        printf("\nSorry!    Can't do transactions\nAccount Could be deleted or inputted A/C NO is wrong\n");
                        printf("\nEnter '111' to go to Try again");
                        printf("\nEnter ' 1 ' to go to Main Menu");
                        printf("\nEnter ' 0 ' to go to Exit\n");
                        int six_c2_e;
                        fflush(stdin);
                        scanf("%d", &six_c2_e);
                        if (six_c2_e==1)
                        {
                            system("cls");
                            goto main_menu;
                        }
                        else if(six_c2_e==111)
                        {
                            system("cls");
                            goto with_try;
                        }
                        else if(six_c2_e==0)
                        {
                            system("cls");
                            printf("::::::::::::::::::::::::::::::::::");
                            printf("\n  Thanks For Using Our Services\n");
                            printf("::::::::::::::::::::::::::::::::::");
                        }
                    }
                    break;
                case 3:
                    system("cls");
                    unsigned long long int fetch_acc_c6c3;
                    char c6c3_check[20]; 
                    char c6c3_check_a[20], c6_c3_check_a[20];

                    printf(":::::::::::::    Balance  Transfer   :::::::::::::\n\n");
                    sender_try:
                    printf("Enter Sender Account NO : ");                             //Takes integer to find account serial
                    scanf("%llu", &fetch_acc_c6c3);
                    c6c3i=fetch_by_ac_no(fetch_acc_c6c3);
                    
                    printf("Again\nEnter Sender Account NO : ");                      //Takes string to confirm whether the account exists or not
                    scanf(" %s", c6c3_check);

                    int c6c3start, c6c3_check_=0;
                    accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( c6c3start = 0; c6c3start < i; c6c3start++)
                    {
                    fscanf(accounts, "%s ", c6c3_check_a);
                    if (strcmp(c6c3_check, c6c3_check_a)==0)
                    {
                        c6c3_check_++;
                    }
                    }
                    fclose(accounts);

                    int c6_c3start, c6_c3_check_=0;
                    accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                    for ( c6_c3start = 0; c6_c3start < 50; c6_c3start++)
                    {
                    fscanf(accounts, "%s ", c6_c3_check_a);
                    if (c6_c3_check_==1)
                    {
                        break;
                    }
                    if (strcmp(c6c3_check, c6_c3_check_a)==0)
                    {
                        c6_c3_check_++;
                    }
                    }
                    fclose(accounts);

                    if (c6c3_check_==1 && c6_c3_check_==0)
                    {
                        try_send_amount:
                        system("cls");

                        char f_c6c3[50]="Balance\\acc_bl";                                
                        char d_c6c3[20];
                        char e_c6c3[20]=".txt";
                        sprintf(d_c6c3, "%d", c6c3i);
                        strcat(f_c6c3, d_c6c3);
                        strcat(f_c6c3, e_c6c3);

                        balance=fopen(f_c6c3, "r");
                        fscanf(balance, "%d", &bfr_snd_amt);
                        fclose(balance);

                        system("cls");
                        printf("Enter the Amount : ");
                        scanf("%d", &sending_amount);

                        if (sending_amount>bfr_snd_amt)
                        {
                            printf("\n:::::::::   Sorry! Insufficient Balance   :::::::::\n");
                            printf("\nEnter '111' to go to Try again");
                            printf("\nEnter ' 1 ' to go to Main Menu");
                            printf("\nEnter ' 0 ' to go to Exit\n");
                            int six_c3_;
                            fflush(stdin);
                            scanf("%d", &six_c3_);
                            if (six_c3_==1)
                            {
                                system("cls");
                                goto main_menu;
                            }
                            else if(six_c3_==111)
                            {
                                system("cls");
                                goto try_send_amount;
                            }
                            else if(six_c3_==0)
                            {
                                system("cls");
                                printf("::::::::::::::::::::::::::::::::::");
                                printf("\n  Thanks For Using Our Services\n");
                                printf("::::::::::::::::::::::::::::::::::");
                            }
                        }
                        else
                        {
                            int serial;
                            unsigned long long int fetch_acc_c6c3_rcv;
                            char c6c3_rcv_check[20];
                            char c6c3_rcv_check_a[20], c6_c3_rcv_check_a[20];

                            printf("\nEnter Receiver's Account NO : ");
                            scanf("%llu", &fetch_acc_c6c3_rcv);
                            serial=fetch_acc_c6c3_rcv%100;

                            printf("Again\nEnter Receiver's Account NO : ");                      //Takes string to confirm whether the account exists or not
                            scanf(" %s", c6c3_rcv_check);

                            int c6c3_rcv_start, c6c3_rcv_check_=0;
                            accounts=fopen("Accounts\\acc_no.txt", "r");                              //Ensure if the account Exists or Not
                            for ( c6c3_rcv_start = 0; c6c3_rcv_start < i; c6c3_rcv_start++)
                            {
                            fscanf(accounts, "%s ", c6c3_rcv_check_a);
                            if (strcmp(c6c3_rcv_check, c6c3_rcv_check_a)==0)
                            {
                                c6c3_rcv_check_++;
                            }
                            }
                            fclose(accounts);

                            int c6_c3_rcv_start, c6_c3_rcv_check_=0;
                            accounts=fopen("Deleted\\deleted_acc_no.txt", "r");                              //Ensure if the account Exists or Not
                            for ( c6_c3_rcv_start = 0; c6_c3_rcv_start < 50; c6_c3_rcv_start++)
                            {
                            fscanf(accounts, "%s ", c6_c3_rcv_check_a);
                            if (c6_c3_rcv_check_==1)
                            {
                                break;
                            }
                            if (strcmp(c6c3_rcv_check, c6_c3_rcv_check_a)==0)
                            {
                                c6_c3_rcv_check_++;
                            }
                            }
                            fclose(accounts);

                            if (c6c3_rcv_check_==1 && c6_c3_rcv_check_==0)
                            {

                            char f_c6c3_rcv[50]="Balance\\acc_bl";                                
                            char d_c6c3_rcv[20];
                            char e_c6c3_rcv[20]=".txt";
                            sprintf(d_c6c3_rcv, "%d", serial);
                            strcat(f_c6c3_rcv, d_c6c3_rcv);
                            strcat(f_c6c3_rcv, e_c6c3_rcv);

                            balance=fopen(f_c6c3_rcv, "r");
                            fscanf(balance, "%d", &bfr_rcv_amt);
                            fclose(balance);

                            new_amount_receive=bfr_rcv_amt+sending_amount;
                            
                            balance=fopen(f_c6c3_rcv, "w");
                            fprintf(balance, "%d", new_amount_receive);
                            fclose(balance);

                            new_amount_send=bfr_snd_amt-sending_amount;
                                    
                            balance=fopen(f_c6c3, "w");
                            fprintf(balance, "%d", new_amount_send);
                            fclose(balance);

                            system("cls");
                            printf(":::::::::    Money Transfer Successful   :::::::::\n");
                            printf("\n%d amount of money has been Transferred from your account\n", sending_amount);

                            transaction=fopen("history.txt", "a");
                            fprintf(transaction, "\n%d    amount of money has been ::  Transferred  :: to ::   %s  ::\n", sending_amount, c6c3_rcv_check);

                            fclose(transaction);

                            printf("\nSender's Current balance is : %d\n", new_amount_send);
                            printf("\nReceiver's Current balance is : %d\n", new_amount_receive);

                            printf("\nEnter ' 1 ' to go to Main Menu");
                            printf("\nEnter ' 0 ' to go to Exit\n");
                            int six_c3;
                            fflush(stdin);
                            scanf("%d", &six_c3);
                            if (six_c3==1)
                            {
                                system("cls");
                                goto main_menu;
                            }
                            else if(six_c3==0)
                            {
                                system("cls");
                                printf("::::::::::::::::::::::::::::::::::");
                                printf("\n  Thanks For Using Our Services\n");
                                printf("::::::::::::::::::::::::::::::::::");
                            }
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("\nSorry!    Can't do transactions\nAccount Could be deleted or inputted A/C NO is wrong\n");
                        printf("\nEnter '111' to go to Try again");
                        printf("\nEnter ' 1 ' to go to Main Menu");
                        printf("\nEnter ' 0 ' to go to Exit\n");
                        int six_c3_e;
                        fflush(stdin);
                        scanf("%d", &six_c3_e);
                        if (six_c3_e==1)
                        {
                            system("cls");
                            goto main_menu;
                        }
                        else if(six_c3_e==111)
                        {
                            system("cls");
                            goto sender_try;
                        }
                        else if(six_c3_e==0)
                        {
                            system("cls");
                            printf("::::::::::::::::::::::::::::::::::");
                            printf("\n  Thanks For Using Our Services\n");
                            printf("::::::::::::::::::::::::::::::::::");
                        }
                    }
                    
                    break;
                case 4:
                    system("cls");
                    goto main_menu;
                    break;

                case 5:
                    system("cls");
                    printf("::::::::::::    Transaction History   :::::::::::\n");
                    int tran_read;
                    transaction=fopen("history.txt", "r");
                    while (1)
                    {
                        tran_read=fgetc(transaction);
                        if (tran_read==EOF)
                        {
                            break;
                        }
                        else
                        {
                        printf("%c", tran_read);                       
                        }          
                    }

                    printf("\n");
                    int optn;
                    printf("\nEnter ' 1 ' to go to Main Menu");
                    printf("\nEnter ' 0 ' to go to Exit\n");
                    scanf("%d", &optn);
                    if (optn==1)
                    {
                    system("cls");
                    goto main_menu;
                    }
                    else
                    {
                    printf("::::::::::::::::::::::::::::::::::");
                    printf("\n  Thanks For Using Our Services\n");
                    printf("::::::::::::::::::::::::::::::::::");
                    }
                break;
                    
                default:
                    printf("Wrong Input");
                    goto transaction;
                    break;
                }
            }
            
            else
            {
                system("cls");
                printf("\n......Wrong Password......\n");
                printf("\nEnter '111' to go to Try Again");
                printf("\nEnter ' 1 ' to go to Main Menu");
                printf("\nEnter ' 0 ' to go to Exit\n");

                fflush(stdin);
                int chbl;
                scanf("%d", &chbl);
                if (chbl==111)
                {
                    system("cls");
                    goto chc_balance;
                }
                else if (chbl==1)
                {
                    system("cls");
                    goto main_menu;
                }
                else if(chbl==0)
                {
                    system("cls");
                    printf("::::::::::::::::::::::::::::::::::");
                    printf("\n  Thanks For Using Our Services\n");
                    printf("::::::::::::::::::::::::::::::::::");
                }
            }
        break;

    case 7:                                                                             //Case 7 Customer's List
            printf("\n::::::::::Customers' List::::::::::\n\n");
            if (i==0)
            {
                printf("\nNo Customers are added yet\n\n");
            }

            int abc;
            f_acc_srl=fopen("Accounts\\acc_serial.txt", "r");
            fscanf(f_acc_srl, "%d", &abc);
            fclose(f_acc_srl);

            for (int k = 0; k < abc; k++)
            {
            char filename_ee[20]="Accounts\\acc";
            char fff[20];
            char eee[20]=".txt";
            sprintf(fff, "%d", k);
            strcat(filename_ee, fff);
            strcat(filename_ee, eee);
            individual_acc_info=fopen(filename_ee, "r");
            int ccc;
            while (1)
            {
                ccc=fgetc(individual_acc_info);
                if (ccc==EOF)
                {
                    break;
                }
                else
                {
                    printf("%c", ccc);
                }
                    
            }
                fclose(individual_acc_info);
            }
                printf("\nEnter ' 1 ' to go to Main Menu");
                printf("\nEnter ' 0 ' to go to Exit\n");
                scanf("%d", &chs);
                if (chs==1)
                {
                system("cls");
                goto main_menu;
                }
                else
                {
                printf("::::::::::::::::::::::::::::::::::");
                printf("\n  Thanks For Using Our Services\n");
                printf("::::::::::::::::::::::::::::::::::");
                }
        break;

    case 8:                                                                     //Case 8 Exit
            printf("::::::::::::::::::::::::::::::::::");
            printf("\n  Thanks For Using Our Services\n");
            printf("::::::::::::::::::::::::::::::::::");
        break;
    
    default:
            printf("\n~~~~~~~-----Wrong Input-----~~~~~~~\n");
            printf("~~~~Please Enter the Correct Value~~~~\n");
            goto main_menu;;
    }
    return 0;
}
