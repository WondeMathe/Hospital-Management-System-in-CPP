#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

struct PatientProfile {
    int card_number;
    char firstName[35];
    char lastName[35];
    int age;
    char gender;
    char bloodGroup[3];
    char allergic[20];
    int phoneNumber;
};

const int size =50;
PatientProfile patients[size];

char fileName[40];
fstream file;

void displayMenu();
void patientRegistretion(char fileName[], int count_patient);
void displayRecord(int patient_number, char fileName[]);
void searchRecord(int patient_number, char fileName[], int card_number);
void uppdateRecord(int patient_number, char fileName[], int card_number);
void deleteRecord(int patient_number, char fileName[], int card_number);
void medicalServices();
void displayDoctorsInfo();
void AboutUs();
void askResponse();

int main()
{
    int card_number, patient_number=1, count_patient = 1;
    system("cls");
    displayMenu();
    char patient_choice;
    cout << "\n\tPlease enter your preference: ";
    cin>>patient_choice;
    system("cls");

    switch(patient_choice){
        case '1':
            cout<<"\tEnter appropriate file name: ";
            cin >>fileName;
            system("cls");
            patientRegistretion(fileName, count_patient);
            break;

        case '2':
            cout<<"\t\tEnter appropraite file name: ";
            cin>>fileName;
            system("cls");
            cout<<"\t\tHow many patients registerd before? ";
            cin>>patient_number;
            system("cls");
            displayRecord(patient_number, fileName);
            break;

        case '3':
            cout<<"\t\tEnter file name: ";
            cin>>fileName;
            system("cls");
            cout<<"\t\tHow many patients registerd before? ";
            cin>>patient_number;
            system("cls");
            cout<<"\t\tEnter the card number of the patient: ";
            cin>>card_number;
            system("cls");
            searchRecord(patient_number,fileName,card_number);
            break;

        case '4':
            cout<<"\t\tEnter file name: ";
            SearchAgain4:
            cin>>fileName;
            system("cls");
            cout<<"\t\tHow many patients registerd before? ";
            cin>>patient_number;
            system("cls");
            cout<<"\t\tEnter the card number of the patient: ";
            cin>>card_number;
            system("cls");
            uppdateRecord(patient_number,fileName,card_number);
            break;

        case '5':
            cout<<"\t\tEnter file name: ";
            SearchAgain5:
            cin>>fileName;
            cout<<"\t\tHow many patients registerd before? ";
            cin>>patient_number;
            system("cls");
            cout<<"\t\tEnter the card number of the patient: ";
            cin>>card_number;
            system("cls");
            deleteRecord(patient_number,fileName,card_number);
            break;
        case '6':
            medicalServices();
            break;
        case '7':
            displayDoctorsInfo();
            break;
        case '8':
            AboutUs();
            break;
        case '9':
            cout<<"\tWE ARE ALWAYS DELIGHTED TO SERVE YOU!"<<endl;
            break;
        default: main();
    }

    return 0;
}

void displayMenu(){
    cout <<"\t----------------------------------------"<<endl;
    cout <<"\t\tWelcome to YMY Hospital\n";
    cout <<"\t-------------------------------------------"<<endl;
    cout <<"\tPlease Enter Your Preference: " <<endl;
    cout <<"\t\t1. Register for medical services" <<endl;
    cout <<"\t\t2. Display all patient records" <<endl;
    cout <<"\t\t3. Search for Patient" <<endl;
    cout <<"\t\t4. Update a Patient's record" <<endl;
    cout <<"\t\t5. Delete a Patient record" <<endl;
    cout <<"\t\t6. Medical services" <<endl;
    cout <<"\t\t7. Get Doctors" <<endl;
    cout <<"\t\t8. About Us" <<endl;
    cout <<"\t\t9. Exit.";
}


void patientRegistretion(char fileName[],int count_patient){

    file.open(fileName, ios::out| ios::binary| ios::app);
    if(file.is_open()){
        int patient_number = 0;
        add:
        if(patient_number < size) {
            cout <<"\tCard number: ";
            cin >>patients[patient_number].card_number;
            cout << "\tFirst Name: ";
            cin >> patients[patient_number].firstName;
            cout << "\tLast Name: ";
            cin >> patients[patient_number].lastName;
            cout << "\tAge: ";
            cin >> patients[patient_number].age;
            cout << "\tGender: ";
            cin >> patients[patient_number].gender;
            cout << "\tBlood Group: ";
            cin >> patients[patient_number].bloodGroup;
            cout << "\tAllergic: ";
            cin >> patients[patient_number].allergic;
            cout << "\tPhone Number: ";
            cin >> patients[patient_number].phoneNumber;
            patient_number++;
         }
        count_patient++;
        char choice;
        FailChoice:
        system("cls");
        cout <<"\t1. Registor another patient: "<<endl;
        cout <<"\t2. Exit"<<endl;
        cout<<"\n\tChoice: ";
        cin>>choice;
        system ("cls");
        if(choice == '1'){
            goto add;
          }
        else if(choice == '2'){
            cout <<"\t\tYou registered: "<<count_patient - 1<<" patients succesfully";
           }
        else {
            goto FailChoice;
           }
        int num_size = count_patient -1;
        file.write((char*)&patients, num_size * sizeof(PatientProfile));
        file.close();
        askResponse();
       }

    else {
        cout<<"\t\t ERROR";
        }
}


void displayRecord(int patient_number, char fileName[]){
        file.open(fileName, ios::in| ios::binary);
        if(file.is_open()){
        cout<<"\t\tAll available patient information";
        cout<<"\n\t\t-----------------------";
        for(int i = 0; i < patient_number; i++){
            while(file.read((char*)&patients[i],sizeof(PatientProfile))){
                cout<<"\n\t\tCard Number: "<<patients[i].card_number<<endl;
                cout<<"\t\tFirst Name: "<<patients[i].firstName<<endl;
                cout<<"\t\tLast Name: "<<patients[i].lastName<<endl;
                cout<<"\t\tAge: "<<patients[i].age<<endl;
                cout<<"\t\tGender: "<<patients[i].gender<<endl;
                cout<<"\t\tBlood Group: "<<patients[i].bloodGroup<<endl;
                cout<<"\t\tAllergic: "<<patients[i].allergic<<endl;
                cout<<"\t\tPhone Number: "<<patients[i].phoneNumber<<endl;
                cout<<"\t\t-----------------------";
            }
        }
        }
        else {
                cout<<"\t\tThere is no file named "<<fileName<<endl;
                FailChoice2:
                cout <<"\t\t 1. Try again"<<endl;
                cout <<"\t\t 2. Go to Home page"<<endl;
                cout <<"\t\t 3. Exit"<<endl;
                cout<<"\n\t\t Choice: ";
                char choice;
                cin>>choice;
                system("cls");
                if(choice=='1'){
                    cout<<"\t\tEnter valid file name: ";
                    cin>>fileName;
                    system("cls");
                    displayRecord(patient_number, fileName);
                }
                else if(choice=='2')
                    main();
                else if(choice == '3'){
                    cout<<"\tWE ARE ALWAYS DELIGHTED TO SERVE YOU!"<<endl;
                }
                else {
                    goto FailChoice2;
                }
            }
        file.close();
        cout<<endl;
        askResponse();
}

void searchRecord(int patient_number, char fileName[], int card_number){
    file.open(fileName, ios::in| ios::binary);
    if(file.is_open()){
        bool isfound = false;
        for(int i = 0; i < patient_number; i++){
            while(file.read((char*)&patients[i],sizeof(PatientProfile))){
                if(patients[i].card_number == card_number){
                    cout<<"\n\t\tAll available patient information"<<endl;
                    cout<<"\t\t---------------------------------"<<endl;
                    cout<<"\t\tCard Number: "<<patients[i].card_number<<endl;
                    cout<<"\t\tFirst Name: "<<patients[i].firstName<<endl;
                    cout<<"\t\tLast Name: "<<patients[i].lastName<<endl;
                    cout<<"\t\tAge: "<<patients[i].age<<endl;
                    cout<<"\t\tGender: "<<patients[i].gender<<endl;
                    cout<<"\t\tBlood Group: "<<patients[i].bloodGroup<<endl;
                    cout<<"\t\tAllergic: "<<patients[i].allergic<<endl;
                    cout<<"\t\tPhone Number: "<<patients[i].phoneNumber<<endl;
                    cout<<"\t\t---------------------------------"<<endl;
                    isfound = true;
                    break;
                    }
                }
                break;
            }
            if(!isfound){
                cout<<"\t\tCard number "<<card_number<<" doesn't exist"<<endl;
                askResponse();
            }
        file.close();
        }
    else {
        cout<<"\t\tThere is no file named "<<fileName<<endl;
        FailChoice3:
        cout <<"\t\t 1. Try again"<<endl;
        cout <<"\t\t 2. Go to Home page"<<endl;
        cout <<"\t\t 3. Exit"<<endl;
        cout<<"\n\t\t Choice: ";
        char choice;
        cin>>choice;
        system("cls");
        if(choice=='1'){
            cout<<"\t\tEnter valid file name: ";
            cin>>fileName;
            system("cls");
            searchRecord(patient_number,fileName,card_number);
            }
        else if(choice=='2')
            main();
        else if(choice == '3'){
            cout<<"\tWE ARE ALWAYS DELIGHTED TO SERVE YOU!"<<endl;
            }
        else {
            goto FailChoice3;
            }
    }
    askResponse();
}

void uppdateRecord(int patient_number, char fileName[], int card_number){
    file.open(fileName, ios::out| ios::in| ios::binary);
    if(file.is_open()){
        bool isfound = false;
        for(int i = 0; i < patient_number; i++){
            while(file.read((char*)&patients[i],sizeof(PatientProfile))){
                if(patients[i].card_number == card_number){
                    cout <<"\tEnter new Card number: ";
                    cin >>patients[i].card_number;
                    cout << "\tEnter new First Name: ";
                    cin >> patients[i].firstName;
                    cout << "\tEnter new Last Name: ";
                    cin >> patients[i].lastName;
                    cout << "\tEnter new Age: ";
                    cin >> patients[i].age;
                    cout << "\tEnter new Gender: ";
                    cin >> patients[i].gender;
                    cout << "\tEnter new Blood Group: ";
                    cin >> patients[i].bloodGroup;
                    cout << "\tEnter new Allergic: ";
                    cin >> patients[i].allergic;
                    cout << "\tEnter new Phone Number: ";
                    cin >> patients[i].phoneNumber;
                    int location = sizeof(patients[i]);
                    file.seekp(-location, ios::cur);
                    file.write((char*)&patients[i],sizeof(PatientProfile));
                    isfound = true;
                    break;
                    }
                }
                break;
            }
            if(!isfound){
                cout<<"\t\tCard number "<<card_number<<" doesn't exist";
                askResponse();
            }
        file.close();
        system("cls");
        }
    else {
        cout<<"\tThere is no file named "<<fileName<<endl;
        cout<<"\tEnter valid file name: ";
        cin>>fileName;
        system("cls");
        uppdateRecord(patient_number,fileName,card_number);
        }
        cout<<"\t\tRecord updated successfully";
        askResponse();
}


void deleteRecord(int patient_number, char fileName[], int card_number){
    file.open(fileName, ios::out| ios::in| ios::binary);
    bool isfound = false;
    fstream tempfile;
    tempfile.open("temp.bin", ios::out| ios::binary);
    if(file.is_open()){
        if(tempfile.is_open()){
            for(int i = 0; i < patient_number; i++){
                while(file.read((char*)&patients[i],sizeof(PatientProfile))){
                    if(patients[i].card_number != card_number){
                        tempfile.write((char*)&patients[i], sizeof(PatientProfile));
                        isfound = true;
                    }
                }
                break;
            }   if(!isfound){
                cout<<"\t\tCard number "<<card_number<<" doesn't exist";
                askResponse();
            }
        }
        cout<<"\t\tRecord deleted Successfully"<<endl;
        } else {
        cout<<"\tThere is no file named "<<fileName<<endl;
        cout<<"\tEnter valid file name: ";
        cin>>fileName;
        system("cls");
        deleteRecord(patient_number, fileName,card_number);
    }
    tempfile.close();
    file.close();
    remove(fileName);
    rename ("temp.bin",fileName);
    askResponse();

}

void medicalServices(){
    cout << "\t\t-----------------------------------------"<<endl;
    cout << "\t\t\tMedical Services We Provide\n";
    cout << "\t\t-----------------------------------------"<<endl;
    cout << "\t\t1. Physical Exam" <<endl;
    cout << "\t\t2. Diagnostic Test" <<endl;
    cout << "\t\t3. Common Illness Treatments" <<endl;
    cout << "\t\t4. Preventative Care" <<endl;
    cout << "\t\t5. Emergency Care" <<endl;
    cout << "\t\t6. Plastic Surgery" <<endl;
    cout << "\t\t7. Neurosurgery" <<endl;
    cout << "\t\t8. General Surgery" <<endl;
    cout << "\t\t9. Vascular Surgery" <<endl;
    cout << "\t\t10. Check up " <<endl;
    cout << "\t\t11. Main Menu press" <<endl;
    askResponse();
}

void displayDoctorsInfo(){
    cout << "\t\t----------------------------------------"<<endl;
    cout << "\t\t\t   Doctors\n";
    cout << "\t\t------------------------------------------"<<endl;
    cout << "\t\t1. Dr. Abel Belay: Dentist" <<endl;
    cout << "\t\t2. Dr. Selam Belete: Therapist" <<endl;
    cout << "\t\t3. Dr. Wubshet Kebede: Allergist" <<endl;
    cout << "\t\t4. Dr. Hailu Tariku: Consulting Doctor" <<endl;
    cout << "\t\t5. Dr. Hiwot Tesfaye: Psychologist\n" <<endl;
    askResponse();
}

void AboutUs(){
    cout << "\t\t---------------------------------------\n";
    cout << "\t\t\tWM Hospital - Healthy Community\n";
    cout << "\t\t----------------------------------------\n";
    cout << "\t\tAddress: Addis Ababa, Ethiopia" <<endl;
    cout << "\t\tWebsite: www.wmhospital.com" <<endl;
    cout << "\t\tCall: +251983818806, +251946158852, +251944648869";
    askResponse();
}

void askResponse(){
                cout <<"\n\t\t1. Go to Home page"<<endl;
                cout <<"\t\t2. Exit"<<endl;
                cout<<"\n\t\tChoice: ";
                char choice;
                cin>>choice;
                system("cls");
                if(choice=='1')
                    main();
                else if(choice == '2'){
                    cout<<"\tWE ARE ALWAYS DELIGHTED TO SERVE YOU!"<<endl;
                }
                else {
                    cout<<"\t\tPlease enter valid choice:";
                    askResponse();
            }
}
