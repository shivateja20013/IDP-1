#include<iostream>
#include<fstream>
using namespace std;
class shopping{
    private:
        int pcode;
        float price,dis;
        string pname;
        public:
            void menu();
            void admin();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void recipt();
};
void shopping::menu(){
    int ch;
    string userid,pass;
    cout<<"╔══════════════════════════════╗"<<endl;
    cout<<"║          Main Menu           ║"<<endl;
	cout<<"╠══════════════════════════════╣"<<endl;
    cout<<"║   1.Admin                    ║"<<endl;
    cout<<"║   2.Buyer                    ║"<<endl;
    cout<<"║   3.Exit                     ║"<<endl;
    cout<<"╚══════════════════════════════╝"<<endl;
    cout<<"Select the option:";
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Login"<<endl;
            cout<<"Enter Admin name : ";
            cin>>userid;
            cout<<"Enter password : "; 
            cin>>pass;
            if(userid=="shiva"&&pass=="20013"||userid=="saketh"&&pass=="20012"||userid=="srinu"&&pass=="20017"||userid=="topper"&&pass=="20025"){
                admin();
            }
            else
                cout<<"invalid user id (or) password!!!"<<endl;
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(1);
            break;
        default :
            cout<<"Enter a valid choice!!"<<endl;
        break;
    }
}  
void shopping::admin(){
    int ch;
    cout<<"╔══════════════════════════════╗"<<endl;
    cout<<"║          Admin Menu          ║"<<endl;
	cout<<"╠══════════════════════════════╣"<<endl;
    cout<<"║   1.Add-Product              ║"<<endl;
    cout<<"║   2.Modify-Product           ║"<<endl;
    cout<<"║   3.Modify-Product           ║"<<endl;
    cout<<"║   4.Back to Menu             ║"<<endl;
    cout<<"╚══════════════════════════════╝"<<endl;
    cout<<"Select the option:";
    cin>>ch;
    switch(ch){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"Invalid Choice!!"<<endl;
            break;
    }
}
void shopping ::add(){
fstream data;
int c,token=0;
float p,d;
string n;
cout<<"New Product"<<endl;
cout<<"Enter Product code of the product :";
cin>>pcode;
cout<<"Name of the product :";
cin>>pname;
cout<<"Price of the product :";
cin>>price;
cout<<"Discount on product :";
cin>>dis;
data.open("database.txt", ios::out|ios::app);
if(!data){
data.open("database.txt", ios::app|ios::out); 
data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n"; 
data.close();
}
else{
data>>c>>n>>p>>d;
    while (!data.eof()){
        if(c ==pcode){
            token++;
        }
    }
    data>>c>>n>>p>>d;
} 
data.close();
    if (token==1){
		admin();
    }
    else{
        data.open("database.txt", ios::app|ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<">"<<dis<<"\n";
        data.close();
    }
cout<<" Record inserted !"<<endl;
admin();
}
void shopping::buyer(){
	int ch;
	cout<<"1.Buy product\n2.go back"<<endl;
	cout<<"Enter the Choice:";
	cin>>ch;
	switch(ch){
		case 1:
			recipt();
			break;
		case 2:
			menu();
			break;
		default :
			cout<<"Invalid Choice"<<endl;
	}
}
void shopping::edit(){
    fstream data,data1;
    int pkey,c,token=0;
    float p,d;
    string n;
    cout<<"Modifying the Record"<<endl;
    cout<<"Enter product code:";
    cin>>pkey;
    data.open("database.txt",ios::app|ios::out);
    if(!data){
        cout<<"File not found!!"<<endl;
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"New Product code :";
                cin>>c;
                cout<<"Name of product :";
                cin>>n;
                cout<<"Price :";
                cin>>p;
                cout<<"Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record Edited"<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"Record not found"<<endl;
        }
    }
}
void shopping::rem(){
    fstream data,data1;
    int pkey,token=0;
    cout<<"Delete product"<<endl;
    cout<<"Enter product id :";
    cin>>pkey;
    data.open("database.txt",ios::app|ios::out);
    if(!data){
        cout<<"File not found !!"<<endl;
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"Product deleted succesfully"<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"Product not found!!"<<endl;
        }
    }
 }
void shopping::list(){
    fstream data;
    string line;
    cout<<"+----------------------------------------------------------------+"<<endl;
	cout<<"¦ P.No  ¦     Product name                        ¦  Price       ¦"<<endl;
	cout<<"¦-------+-----------------------------------------+--------------¦"<<endl;
    data.open("database.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(getline(data,line)){   
        cout<<line<<endl;        
    }
    cout<<"+----------------------------------------------------------------+"<<endl;
    data.close();
}
void shopping::recipt(){
    fstream data;
    int arrc[100],arrq[100],c=0;
    char ch;
    float amount,dis,total;
    cout<<"Billing "<<endl;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File is Empty"<<endl;
    }
    else{
        data.close();
        list();
        cout<<"+-----------------------------------+"<<endl;
    	cout<<"¦          Place the order          ¦"<<endl;
        cout<<"+-----------------------------------+"<<endl;
        do{
            cout<<"Enter product code:";
            cin>>arrc[c];
            cout<<"Enter product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"Duplicate product code"<<endl; 
                }
            }
            c++;
            cout<<"Do you want to buy another product? if yes press 'y' else press 'n' for no";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
        cout<<"+-----------------------------------+"<<endl;
    	cout<<"¦               Bill                ¦"<<endl;
        cout<<"+-----------------------------------+"<<endl;
        cout<<"P.No\tProduct name\tPrice\tDiscount\n";
        for (int i=0;i<c;i++){
        data.open("database.txt", ios::in); 
        data>>pcode>>pname>>price>>dis; 
        while(!data.eof()){
            if(pcode==arrc[i]){
            amount=price*arrq[i];
            dis=amount-(amount*dis/100);
            total=total+dis; 
            cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<dis;
            }
            data>>pcode>>pname>>price>>dis;
            }
        }
            data.close();
}
}
int main() {
    shopping s;
    Menu:
    s.menu();
    goto Menu;
    return 0;
}
