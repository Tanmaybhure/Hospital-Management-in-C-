#include <iostream>
#include <string>
#include <cctype>
#include <thread>
#include <chrono>
#include <windows.h>
#include <random>
#include<ctime>
#include <vector>

using namespace std;
vector<string> doc_name={"Dr.Avinash","Dr.Meghana","Dr.Vinayak","Dr.Nayak"};
vector<string> qua_name={"MBBS","BDS","BUMS","BHMS"};
vector<int> doc_age={35,30,42,28};
vector<string> doc_blood={"A+","B+","O+","A+"};
int p[6]={12,30,10,15,10,50};
string m[6]={"Dengue      ","Vitamin E","Acidity","Crocine","Multivitamin","Amoxicillin"};
int s[6]={100,150,100,100,150,100};

int lrange=50;
int rrange=300;
int lrange1=50;
int rrange1=70;
int lrange2=10;
int rrange2=40;


class Payment{
    public: 
    void dopayment(){
                       cout<<"\t \t \t \t Welcome\n";
                       cout<<"\n\t_______________________________________________\t";
                       cout<<"\n\t|1. Card Payement                             |\t";
	                   cout<<"\n\t|2. Net Banking(Pay TM ,Phone pay, Google pay)|\t";
                       cout<<"\n\t|3. On Cash Delivery.                         |\t";
                       //cout<<"\n\t|4. Exit                                      |\t";
                       cout<<"\n\t______________________________________________|\t";
                       int u;
                       cout<<"\n\nEnter your payment Method.:";
                       cin>>u;
                       cout<<"\n\n";
                       switch(u)
                   {
                   case 1:
                    {
                                while(true)
                        {
                              int q;
                              cout<<"\n";
                               cout<<"Enter card Number(only 4 digit):";
                               cin>>q;
                               if((q>999)&&(q<10000))
                           {
                               cout<<"Card scan succesfully.";
                               break;
                           }
                           else
                           {
                                  cout<<"Please enter Correct 4 digit number.";
                           }
                       }

                       while(true)
                       {
                           int y;
                           cout<<"\n";
                           cout<<"Enter the password of your card(4 digit pin).";
                           cin>>y;
                          if((y>999)&&(y<10000))
                           {
                               cout<<"\n";
                               cout<<"Pinned correct.\n";
                               cout<<"Payment Successful\n";
                               cout<<"Thank you \n";
                               break;
                           }
                           else
                            {
                                cout<<"\nPlease Enter valid Pin(4 Digit Pin only).\n";
                            }
                       }
                       break;

                  }
                   case 2:
                           {
                               char nam[20];
                               int y;
                               cout<<"Enter your Name:";
                               cin>>nam;
                               while(true)
                             {

                               cout<<"\nEnter the password of your card(4 digit pin).";
                               cin>>y;
                                if((y>999)&&(y<10000))
                           {
                               cout<<"\n";
                               cout<<"Pinned correct.\n";
                               cout<<"Payment Successful\n";
                               cout<<"Thank you \n";
                               break;
                           }
                           else
                            {
                                cout<<"\nPlease Enter valid Pin(4 Digit Pin only).\n";
                            }
                           }
                           break;
                           }
                   case 3:
                          {
                              cout<<"Ok! medicines will shipped to you , Then you will pay.\n";
                              break;
                        }
                //    case 4:
                //     {
                //         break;
                //         exit(0);
                //     }
                   default:
                            {
                                cout<<"Invalid Option.";
                                break;
                            }
                      }
                  }
    };

class medicine{

    public: int med_id;
            int med_quantity;
            int med_total;

            medicine(){
                med_total=0;
            }

    void getmed(int tempnum1){
        string med_name[tempnum1];
        int medq[tempnum1];
        int medprice[tempnum1];
        int medperprice[tempnum1];
    cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
    cout<<"||  DRUG ID    ||  DRUGD TYPE  ||      DRUGS NAME :-> DRUGS PRIcE (Rs)"<<endl;
    cout<<"||---------------------------------------------------------------------"<<endl;
    for(int i=0;i<6;i++){
    cout<<"||      "<<i<<"      ||    OTC       ||   "<<m[i]<<":-> "<<p[i]<<" "<<"\n";    
    }
    cout<<"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
    cout<<"\n\n\n";
        for(int i=0;i<tempnum1;i++){
            cout<<"enter Medicine ID as per Chart:";
            cin>>med_id;
            cout<<"\n";
            if(med_id>5){
                cout<<"\nPlease enter valid drug ID.\n";
                i--;
                continue;
            }
            cout<<"\nYou Choosen\t"<<m[med_id]<<"\n";
            med_name[i]=m[med_id];
            cout<<"Enter Quantity:";
            cin>>med_quantity;
            if(med_quantity>s[med_id]){
                cout<<"Not have enough Stock";
                i--;
                continue;
            }
            cout<<"price per unit:"<<p[med_id];
            s[med_id]-=med_quantity;
            medq[i]=med_quantity;
            medprice[i]=med_quantity*p[med_id];
            // cout<<"";
            int med_total1=med_quantity*p[med_id];
            med_total=med_total+(med_quantity*p[med_id]);
            cout<<" "<<med_quantity<<"*"<<p[med_id]<<"="<<med_total1<<"\n\n";
            medperprice[i]=p[med_id];
            //cout<<"\n";
            cout<<"Total:"<<med_total<<"\n";
        }
        cout<<"\nMedicine added to your list successfully!!!\n\n";
        cout<<"Press 1 to view list\n\n";
        int c;
        cin>>c;
    while(1){    
        if(c==1){
        cout<<"loading...\n\n";
        Sleep(2000);    
        cout<<"\n";
        cout<<"\t\t\t\tHospital Management System\n\n";
        time_t now;
        struct tm nowLocal;
        now=time(NULL);
        nowLocal=*localtime(&now);
        cout<<"\tPurchase Date:"<<nowLocal.tm_mday<<"-"<<nowLocal.tm_mon+1<<"-"<<nowLocal.tm_year+1900<<"\n";
        cout<<"\tPurchaseTime:"<<nowLocal.tm_hour<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<"\n\n";
        cout<<"\tSR.NO\t\t"<<"\tDrug Name\t"<<"\tQuantity\t"<<"\tUnit price\t"<<"\tTotal"<<"\n";
        for(int i=0;i<tempnum1;i++){
            cout<<"\t"<<i+1<<"\t\t\t"<<med_name[i]<<"\t\t"<<medq[i]<<"\t\t"<<medperprice[i]<<"\t\t\t"<<medprice[i]<<"\n\n";
        }
        cout<<"\t Final Amount:"<<med_total<<"\n";
        cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
        Payment pay;
        int p11111;
        cout<<"press 1 to payment:";
        cin>>p11111; 
        while(true){
            if(p11111==1){
                pay.dopayment();
                break;
            }else{
                cout<<"please press 1 to continue\n\n";
                continue;
            }
        }
        break;
    }else{
        cout<<"Please press 1\n\n";
        continue;
    }
    }
    }        
};
class patient: public medicine{
    public:
            string p_name;
            string p_disease;
            int p_id;
            int p_age;
            int p_room;
            int p_bed;
            string p_mobile;

            patient(){
                p_disease="!!!!!";
            }    

            void getdata(){
                cout<<"Enter name:";
                cin>>p_name;
                cout<<"\n";
                cout<<"Enter Age:";
                cin>>p_age;
                cout<<"\n";
                cout<<"Enter Mobile:";
                cin>>p_mobile;
                cout<<"\n";

                random_device rd;
                mt19937 eng(rd()); 
                uniform_int_distribution<> distr1(lrange, rrange); // define the range
                lrange+=10;
                rrange+=20;
                uniform_int_distribution<> distr2(lrange1, rrange1);
                lrange1+=3;
                rrange1+=5;
                uniform_int_distribution<> distr3(lrange2, rrange2);
                lrange2+=1;
                rrange2+=1;
                int randomNumber1 = distr1(eng);
                int randomNumber2 = distr1(eng);
                int randomNumber3 = distr1(eng);
                randomNumber1++;
                randomNumber2+=2;
                randomNumber3+=2;
                p_id=randomNumber1;
                p_room=randomNumber2;
                p_bed=randomNumber3;
                cout<<"Loading...";
                Sleep(1500);
                cout <<"\r";
                cout<<"\nPatient Data stored Successfully.\t\t\t Patient ID:"<<p_id<<"\n";
                cout<<"Your Room Number:"<<p_room<<"\t\t\t\t\t\tBed:"<<p_bed<<"\n";
                cout<<"Patient Sufferring from:\t\t"<<p_disease<<"\n\n";
            }

            void showdata(){
                cout<<"Patient ID:\t"<<p_id<<"\n";
                cout<<"Patient Name:\t"<<p_name<<"\n";
                cout<<"Patient Age:\t"<<p_age<<"\n";
                cout<<"Contact:\t"<<p_mobile<<"\n";
                cout<<"Patient Room:\t"<<p_room<<"\n";
                cout<<"Patient Bed:\t"<<p_bed<<"\n";
                cout<<"Patient Disease:\t"<<p_disease<<"\n";
                cout<<"\n\n";
            }
};

class schedule{
    public: vector<int> t1;
               vector<int> v1;
};

class doctor: public schedule,patient{
    public: 
            string d_name;
            int d_age;
            string d_qua;
            string d_blood;

            void viewstaff(){
                cout<<"\n";
                cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
                cout<<"Sr NO \t\t\t Name \t\t\t\tAge\t\t\t BloodGroup \t\t\t Qualification\n";
                for(int i=0;i<doc_name.size();i++){
                    cout<<i+1<<"\t\t\t"<<doc_name[i]<<"\t\t\t"<<doc_age[i]<<"\t\t\t\t"<<doc_blood[i]<<"\t\t\t\t"<<qua_name[i]<<"\n";
                }
                cout<<"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
            }

            void addstaff(){
                cout<<"Enter Name:";
                cin>>d_name;
                cout<<"\nEnter Age:";
                cin>>d_age;
                cout<<"\nEnter Blood Group:";
                cin>>d_blood;
                cout<<"\nEnter Qualification:";
                cin>>d_qua;

                doc_name.push_back(d_name);
                doc_age.push_back(d_age);
                qua_name.push_back(d_qua);
                doc_blood.push_back(d_blood);    

                cout<<"\nLoading...\n\n";
                Sleep(1200);
                cout<<"\r New Staff Added Successfully.\n\n";            
            }

            void updatestaff(){
                viewstaff();
                cout<<"\n\nEnter Sr.No of Staff.";
                int srno;
                cin>>srno;
                cout<<"\n\n";
                if(0<=srno && srno>doc_name.size()){
                    cout<<"please enter valid Sr.No\n";
                    updatestaff();
                }
                srno=srno-1;
                cout<<"You choose:"<<doc_name[srno]<<"\n";
                cout<<"enter New Name:";
                cin>>d_name;
                cout<<"\n";
                cout<<"enter New Age:";
                cin>>d_age;
                cout<<"\n";
                cout<<"enter New Blood Group:";
                cin>>d_blood;
                cout<<"\n";
                cout<<"enter New Qualification:";
                cin>>d_qua;
                cout<<"\n";

                doc_name[srno]=d_name;
                doc_age[srno]=d_age;
                doc_blood[srno]=d_blood;
                qua_name[srno]=d_qua;

                cout<<"Please Wait We are Updating Info...\n";
                Sleep(1500);
                cout<<"\r Data Updated";
                cout<<"\n";
            }

            void deletestaff(){
                viewstaff();
                cout<<"Enter Sr No of the staff You want to Delete.\n";
                int srno;
                cin>>srno;
                if(0<=srno && srno>doc_name.size()){
                    cout<<"please enter valid Sr.No\n";
                    deletestaff();
                }
                srno=srno-1;
                cout<<"You choose:"<<doc_name[srno]<<"\n";
                doc_name.erase(doc_name.begin() + srno);
                doc_age.erase(doc_age.begin() + srno);
                doc_blood.erase(doc_blood.begin() + srno);
                qua_name.erase(qua_name.begin() + srno);
                cout<<"\nLoading...\n";
                Sleep(1200);
                cout<<"Data Remove Successfully.";
                cout<<"\n";
            }

};

class inventory{
    public: 
            void showstock(){
    cout<<"||'''''''''''||''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''||''''''''''''''''''||"<<endl;
    cout<<"||  DRUG ID  ||  DRUGD TYPE  ||      DRUGS NAME    ||  DRUGS PRISE (Rs)    ||     Total Stock  ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     0     ||     OTC      ||      "<<m[0]<<"    ||      " <<p[0]<<"(Rs)          ||       "<<  s[0]<<"        ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     1     ||     OTC      ||     "<<m[1]<<"      ||       " <<p[1]<<"(Rs)         ||      "<< s[1]<<"         ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     2     ||     OTC      ||  "<<m[2]<<"         ||       "<<p[2]<<"(Rs)         ||       "<< s[2]<<"        ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     3     ||     OTC      ||  "<<m[3]<<"   ||      "<<p[3]<<"(Rs)          ||      "<<s[3]<<"         ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     4     ||     OTC      ||  "<<m[4]<<"      ||       "<<p[4]<<"(Rs)         ||      "<< s[4]<<"         ||"<<endl;
    cout<<"||-------------------------------------------------------------------------||------------------||"<<endl;
    cout<<"||     5     ||     OTC      || "<< m[5]<< "   ||      "<<p[5]<<"(Rs)          ||       "<< s[5]<<"        ||"<<endl;
    cout<<"||'''''''''''||''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''||''''''''''''''''''||"<<endl;
            }
};


int main(){
    patient p[15];
    int count_patient=0;
    cout<<"\n \t\t\tWelcome to Hospital Management System.\n";
    cout<<"\n";
    cout<<"\t\t\tPlease login to continue...\n\n";
    string phone;
    int pass=2023;
    while(true){
    cout<<"\t\t\tEnter your Phone number:";
    cin>>phone;
    if (phone.length() != 10) {
        cout<<"\t\t\tPlease enter valid phone number.\n\n";
        continue;
    }else{
        int p_temp;
        cout<<"\n\t\t\tenter password:";
        cin>>p_temp;
        cout<<"Please Wait....";
        cout<<"\n\n";
        Sleep(2500);
        if(p_temp!=pass){
            cout << "\r";
            cout<<"!!!!!Password is incorrect.\n\n";
            continue;
        }else{
            cout << "\r";
            cout<<"welcome Sir\n\n";
            break;
        }
    }
    }
    while(true){
        cout<<"1. Patient Management\n";
        cout<<"2. Staff Management\n";
        cout<<"3. Inventory Management\n";
        cout<<"4. Exit\n\n";

        int main_choice;
        cout<<"Enter your Choice.";
        cin>>main_choice;
        cout<<"\n";
        switch(main_choice){
            //case 1 start
            case 1:{
                int flaggloop=1;
                while(flaggloop){
                    int pm_choice;
                    cout<<"1. Register New Patient\n";
                    cout<<"2. Show Patients\n";
                    cout<<"3. Assign disease.\n";
                    cout<<"4. Order Medicine. \n";
                    cout<<"5. update patient Info. \n";
                    cout<<"6. Exit\n\n";
                    cout<<"enter Your choice:";
                    cin>>pm_choice;
                    cout<<"\n";
                    switch(pm_choice){
                        case 1: {
                                    p[count_patient].getdata();
                                    count_patient++;
                                    cout<<"Patient Admitted Successfully.\n\n";
                                    break;
                                }
                        case 2:{
                                  for(int i=0;i<count_patient;i++){
                                    cout<<"\n";
                                    p[i].showdata();
                                  }
                                  break;
                        }
                        case 3:{
                                  int temp_idcase3;
                                  int flagcase3=0;
                                  cout<<"Enter the Patient ID:";
                                  cin>>temp_idcase3;
                                  cout<<"\n";
                                  for(int i=0;i<count_patient;i++){
                                    if(p[i].p_id==temp_idcase3){
                                        string case3p_dname;
                                        cout<<"Enter Diesease:";
                                        cin>>case3p_dname;
                                        p[i].p_disease=case3p_dname;
                                        cout<<"please wait...\n\n";
                                        Sleep(1500);
                                        cout<<"\r";
                                        cout<<"Successfully updated.\n\n";
                                        flagcase3=1;
                                        break;
                                    }
                                  } if(flagcase3==0){
                                    cout<<"!!!!!Please first register patient.\n\n";
                                  }
                                  break;  
                        }
                        case 4:{
                            int temp_idcase4;
                            int temp_flagcase4=0;
                            cout<<"Enter patient ID:";
                            cin>>temp_idcase4;
                            for(int i=0;i<count_patient;i++){
                                if(p[i].p_id==temp_idcase4){
                                    int tempnum;
                                    cout<<"Enter how many medicine you want:";
                                    cin>>tempnum;
                                    cout<<"\n\n";
                                    p[i].getmed(tempnum);
                                    //p[i].showbill();
                                    temp_flagcase4=1;
                                    break;
                                }
                            } if(temp_flagcase4=0){
                                cout<<"!!!!!Please first register patient.\n\n";
                            }
                            break;
                        }
                        case 5:{
                            int temp_p_idcase5;
                            cout<<"enter patient id:";
                            cin>>temp_p_idcase5;
                                for(int i=0;i<count_patient;i++){
                                    if(p[i].p_id==temp_p_idcase5){
                                        int tempage,tempmobile;
                                        string tempname; 
                                        cout<<"\nenter name:";
                                        cin>>tempname;
                                        cout<<"\nenter age:";
                                        cin>>tempage;
                                        cout<<"\nenter mobile:";
                                        cin>>tempmobile;
                                        p[i].p_age=tempage;
                                        p[i].p_name=tempname;
                                        p[i].p_mobile=tempmobile;
                                        cout<<"\n\nLoading...";
                                        Sleep(1500);
                                        cout<<"Patient Information Updated\n\n";
                                    }else{
                                        cout<<"\n\nenter valid patient id.";
                                    }
                                }
                            break;
                        }
                        case 6:{
                            flaggloop=0;
                            break;
                        }
                        default: {
                            cout<<"\nPlease Enter valid choice\n\n";
                            break;
                        }        
                    }
                }
                break;
            };

            //case1 completed

            case 2:{
                    int outerflagcase2=1;
                    while(outerflagcase2){
                        cout<<"1 view staff.\n";
                        cout<<"2 update staff.\n";
                        cout<<"3 Make a Schedule.\n";
                        cout<<"enter choice:";
                        int chcase2;
                        cin>>chcase2;
                        cout<<"\n";

                        switch(chcase2){
                            case 1:{
                                doctor d1;
                                d1.viewstaff();
                                break;
                            }
                            case 2:{
                                int case2cas2flag=1;
                                while(case2cas2flag){
                                    cout<<"1 add Staff.\n";
                                    cout<<"2 update Staff Info.\n";
                                    cout<<"3 delete Staff Member.\n";
                                    cout<<"4 Exit.\n";
                                    int case2case2choice;
                                    cout<<"\nEnter choice:";
                                    cin>>case2case2choice;
                                    cout<<"\n\n";
                                    switch(case2case2choice){
                                        case 1:{
                                            doctor dcase2;
                                            dcase2.addstaff();
                                            break;
                                        };
                                        case 2:{
                                            doctor dcase2case2;
                                            dcase2case2.updatestaff();
                                            break;
                                        }
                                        case 3:{
                                            doctor dcase2case3;
                                            dcase2case3.deletestaff();
                                            break;
                                        }
                                        case 4:{
                                            case2cas2flag=0;
                                            break;
                                        }   
                                        default:{
                                            cout<<"\n!!!Please Enter Valid choice.\n";
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            case 3:{
                                doctor d23;
                                d23.viewstaff();
                                cout<<"Enter Your Srno.";
                                int srno;
                                cin>>srno;
                                cout<<"\n\n";
                                if(0<=srno && srno>doc_name.size()){
                                    cout<<"please enter valid Sr.No\n";
                                    break;
                                }
                                srno=srno-1;
                                cout<<"welcome "<<doc_name[srno]<<"\n\n";
                                doctor dtemp;
                                dtemp.d_name=doc_name[srno];
                                dtemp.d_age=doc_age[srno];
                                dtemp.d_blood=doc_blood[srno];
                                dtemp.d_qua=qua_name[srno];
                            int flag=1;
                            while(flag){
                            cout<<"1 Add Schedule.\n";
                            cout<<"2 Remove Schedule.\n";
                            cout<<"3 View Schedule.\n";
                            cout<<"4 Exit.\n\n";
                            cout<<"Enter choice:";
                            int ch;
                            cin>>ch;
                            cout<<"\n\n";
                            switch(ch){
                                case 1:{
                                    for(int i=0;i<count_patient;i++){
                                        p[i].showdata();
                                    }
                                    cout<<"\nEnter the Patient ID to make Your schedule:";
                                    int tempdid;
                                    cin>>tempdid;
                                    cout<<"\n";
                                    int flag234=0;
                                    for(int i=0;i<count_patient;i++){
                                        if(tempdid==p[i].p_id){
                                        dtemp.v1.push_back(p[i].p_id);
                                        flag234=1;
                                        }
                                    }
                                    if(flag234==0){
                                        cout<<"\nplease enter valid Patient id\n";
                                        continue;
                                    }
                                    cout<<"\nLoading...";
                                    Sleep(800);
                                    cout<<"\nPatient Add to your Schedule.\n\n";
                                    break;
                                }
                                case 2:{
                                    for(int i=0;i<count_patient;i++){
                                        p[i].showdata();
                                    }
                                    int pipid;
                                    cout<<"Enter Patient Id to be remove from schedule.";
                                    cin>>pipid;
                                    cout<<"\n\n";
                                    int ipbpflag=0;
                                    for(int i=0;i<dtemp.v1.size();i++){
                                        if(pipid==dtemp.v1[i]){
                                         dtemp.v1.erase(dtemp.v1.begin() + dtemp.v1[i]);
                                         ipbpflag=1;
                                         cout<<"Please wait...\n";
                                         Sleep(800);
                                         cout<<"\r Patient from your schedule List is remove\n\n";
                                        }
                                    }
                                    if(ipbpflag==0){
                                        cout<<"No Patient Found with "<<pipid<<" ID\n";
                                    }
                                    break;
                                }
                        
                                case 3:{
                                    cout<<"'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
                                        cout<<" ID\t Name\t\tAge\t  Mobile \t diease \tRoom \t\t Bed\n";
                                        vector<int> tempj;
                                    for(int i=0;i<=dtemp.v1.size();i++){
                                        int dddid=dtemp.v1[i];
                                        for(int j=0;j<count_patient;j++){
                                            if(dddid==p[i].p_id){
                                                tempj.push_back(j);
                                            }
                                        }
                                    }
                                    for(int i=0;i<tempj.size();i++){
                                        cout<<" "<<p[i].p_id<<"\t"<<p[i].p_name<<"\t\t"<<p[i].p_age<<"\t"<<p[i].p_mobile<<"\t\t"<<p[i].p_disease<<"\t\t"<<p[i].p_room<<"\t\t"<<p[i].p_bed<<"\n";
                                    }
                                    cout<<"\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
                                    break;
                                }
                                case 4:{
                                    flag=0;
                                    break;
                                }
                                default:{
                                    cout<<"\n Please enter valid choice.";
                                    break;
                                }
                            }
                        } 
                                break;
                            }
                            case 4:{
                                outerflagcase2=0;
                                break;
                            }
                            default:{
                                cout<<"enter valid choice\n";
                                break;
                            }
                        }    
                    }
                    break;
            };

            case 3:{
                    int flagloopcase3=1;
                    while(flagloopcase3){
                        cout<<"1 view Available stock.\n";
                        cout<<"2 order stock.\n";
                        cout<<"3 update medicines.\n";
                        cout<<"4 Exit.\n";
                        cout<<"\n enter your choice.";
                        int case3choice;
                        cin>>case3choice;
                        cout<<"\n\n";
                        switch(case3choice){
                            case 1:{
                                inventory itemp;
                                itemp.showstock();
                                break;
                            }
                            case 2:{
                                int D_id,d_stock;
                                cout<<"Enter Drug ID:";
                                cin>>D_id;
                                cout<<"You choose:\t"<<m[D_id];
                                cout<<"\tAvailable Stock:\t"<<s[D_id];
                                cout<<"\n\n";
                                cout<<"Enter How many Stocks or Units You want.";
                                cin>>d_stock;
                                s[D_id]+=d_stock;
                                cout<<"\n Please wait.....";
                                Sleep(1500);
                                cout<<"\r";
                                cout<<"\n\t\tStock has been delivered.\n\n";
                                break;
                            }
                            case 3:{
                                int D_id1;
                                cout<<"Enter Drug ID:";
                                cin>>D_id1;
                                cout<<"You choose:"<<m[D_id1];
                                int innerflagcase3=1;
                                while(innerflagcase3){
                                    cout<<"\n1 update name\n";
                                    cout<<"2 update price\n";
                                    cout<<"3 remove stock\n";
                                    cout<<"4 view updated list\n";
                                    cout<<"5 exit\n";
                                    int coo;
                                    cout<<"\n Enter Your choice:";
                                    cin>>coo;
                                    switch(coo){
                                        case 1:{
                                            string new_med_name;
                                            cout<<"Enter New Name:";
                                            cin>>new_med_name;
                                            m[D_id1]=new_med_name;
                                            cout<<"Loading...\n\n";
                                            Sleep(1300);
                                            cout<<"Name Updated successfully.";
                                            break;
                                        }
                                        case 2:{
                                            int new_med_price;
                                            cout<<"Enter New Price:";
                                            cin>>new_med_price;
                                            ::p[D_id1]=new_med_price;
                                            cout<<"Loading...\n\n";
                                            Sleep(1300);
                                            cout<<"Price Updated successfully.";
                                            break;
                                        }
                                        case 3:{
                                            int new_med_stock;
                                            cout<<"Enter stock to remove:";
                                            cin>>new_med_stock;
                                            if(s[D_id1]>=new_med_stock)
                                            {
                                                s[D_id1]-=new_med_stock;
                                            }else{
                                                cout<<"\nNot have enough stock.\n\n";
                                                break;
                                            }
                                            cout<<"Loading...\n\n";
                                            Sleep(1300);
                                            cout<<"Stock Updated successfully.\n\n";
                                            break;
                                        }
                                        case 4:{
                                            inventory iv;
                                            iv.showstock();
                                        }
                                        case 5:{
                                            innerflagcase3=0;
                                            break;
                                        }
                                         default:{
                                            cout<<"Please enter Valid choice\n";
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            case 4:{
                                flagloopcase3=0;
                                break;
                            }
                            default:{
                                cout<<"please enter valid choice.\n\n";
                                break;
                            }
                        }
                    }
                    break;
            };

            case 4:{cout<<"Thanks To visit Hospital Management.";
            
                    exit(0);
                    break;
            };

            default:{
                cout<<"!!!please enter valid choice.\n\n";
                break;
            };
        }
    }
    return 0;
    }
