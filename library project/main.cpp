#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

struct book{
    int id;
    string name,author;
    float price;
};
void home(book b);
void backToHome(book b);
void loadData(book b);
void title();
void add (book b);
void display(book b);
void searchById(book b);
void searchByName(book b);
void update(book b);
void deleteBook(book b);

book bring[100];
int index=0;

int main()
{
    book b;
    home(b);
    return 0;
}
void home(book b){
    cout<<"\n "<<setw(70)<<"Welcome to our library ^_^  ^_^  ^_^\n\n";

    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To Add new book press ====> 1\n";
    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To show all books press ====> 2\n";
    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To search for book by id press ====> 3\n";
    cout<<left<<"\n "<<setw(70)<<"To search for book by name press ====> 4\n";
    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To edit book press ====> 5\n";
    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To delete book press ====> 6\n";
    cout<<left<<"\n "<<setw(70)<<setw(50)<<"To exit press ====> 7\n"<<endl;
    int select;
    cout<<"Select your choise : ";
    cin>>select;
    switch(select){
        case 1: add(b);backToHome(b);break;
        case 2: display(b);backToHome(b);break;
        case 3: searchById(b);backToHome(b);break;
        case 4: searchByName(b);backToHome(b);break;
        case 5: update(b);backToHome(b);break;
        case 6: deleteBook(b);backToHome(b);break;
        case 7: exit(1);break;
        default: home(b);break;
    }
}
void backToHome(book b){
    char x[1];
    cout<<"Press any letter or number to back to main window....."<<endl;
    if(cin>>x[0]){
        home(b);
    }

}
void loadData(book b){
    ifstream load("books.txt",ios::in);
    if ( !load ){
            cout << "File could not be opened" << endl;
        }
     while(load>>b.id>>b.name>>b.author>>b.price){
        bring[index]=b;
        index++;
    }
}
void title(){
     cout<<" "<<setw(30)<<left<<"ID"<< setw(30)<< "Name"
           <<setw(30)<<"Author"<<setw(30)<<"Price"<<endl;
}
void add (book b){
    loadData(b);
    ofstream addBook("books.txt", ios::app);
    cout<<"Enter book  id , name , author  and  price  : \n";
    cin>>b.id;
    for(int i=0;i<index;i++){
        if(b.id==bring[i].id){
            cout<<"This Id is already exist!!"<<endl;
            index=0;
            add(b);
            backToHome(b);
        }}
        cin>>b.name;
        for(int i=0;i<index;i++){
        if(b.name==bring[i].name){
            cout<<"This name is already exist!!"<<endl;
            index=0;
            add(b);
            backToHome(b);
        }}
        cin>>b.author>>b.price;
        addBook<<" "<<setw(30)<<b.id<<setw(30)<<b.name
                <<setw(30)<<b.author<<setw(30)<<b.price<<endl;
                index=0;

}
void display(book b){
    loadData(b);
    title();
    for(int i=0;i<index;i++){
        cout<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
        <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
    }
    index=0;
}
void searchById(book b){
    loadData(b);
    int id;
    bool check;
    cout<<"Enter the ID of the book : ";
    cin>>id;
    bool found=false;

    for(int i=0;i<=index;i++){
        if(id==bring[i].id){
            found=true;
            title();
            cout<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
                <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
            break;
        }
    }
    if(found==false)
            cout<<"Not found!!\n";
    index=0;
}
void searchByName(book b){
    loadData(b);
    string name;
    bool check;
    cout<<"Enter Name of the book : ";
    cin>>name;
    bool found=false;
    for(int i=0;i<=index;i++){
        if(name==bring[i].name){
            found=true;
            title();
            cout<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
                <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
            break;
        }
    }
    if(found==false){
        cout<<"Not found!!\n";
        searchByName(b);
    }

    index=0;
}
void update(book b){
    index=0;
    loadData(b);
    ofstream e("books.txt",ios::out);
    string newName,newAuthor;
    float newPrice;
    int id;
    cout<<"Enter the ID of the book you want to edit: ";
    cout<<index<<endl;
    cin>>id;
    bool check=false;
    for(int i=0;i<index;i++){
        if(id==bring[i].id){
                check=true;
            cout<<"Enter new name : ";
            cin>>newName;
            bring[i].name=newName;
            cout<<"Enter new author : ";
            cin>>newAuthor;
            bring[i].author=newAuthor;
            cout<<"Enter new price : ";
            cin>>newPrice;
            bring[i].price=newPrice;
            e<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
         <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
        }
        else{

             e<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
         <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
        }
    }
    if(!check){
        cout<<"No such ID!!\n";
        update(b);
        }
    index=0;
}
void deleteBook(book b){
    loadData(b);
    ofstream d("books.txt",ios::out);
    int id;
    cout<<"Enter the ID of the book you want to delete: ";
    cin>>id;
    bool
     found=false;
    for(int i=0;i<index;i++){
        if(id==bring[i].id){
            found=true;
        }
        else{
            d<<" "<<setw(30)<<bring[i].id<<setw(30)<<bring[i].name
             <<setw(30)<<bring[i].author<<setw(30)<<bring[i].price<<endl;
            }
        }
        if(!found){
            cout<<"ID not found\n";
            index=0;
            deleteBook(b);
        }
    index=0;
    }

