
#include <iostream>
#include <string>
using namespace std;

class node{
public:
    string data;
    node* next;

    node(string data){
        this->data = data;
        this->next = NULL;
    }
};

void inserth(node* &head, string val){
    node* newN = new node(val);
    newN->next = head;
    head=newN;
}

void iend(node* &head, string val){
    node* newN = new node(val);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newN;
}


void change(node* &head, string val, int pos){
    node* temp=head;
    int cp= 1;
    while(cp != pos){
        temp=temp->next;
        cp++;
    }
    temp->data=val;
}


void display(node* head){ //travers
    node* temp = head;
    int x=1;
    while (temp != NULL)
    {
        cout<<x<<". " <<temp->data<< " "<<endl;
        temp = temp->next;
        x++;
    }
    cout<<endl;
}

void search(string& pat, node* head) { 
    int M = pat.size();

    node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        string txt = temp->data;
        int N = txt.size();

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M) {
                cout << "Word found at position " << pos << " in the Text Editor" << endl;
                break; 
            }
        }
        temp = temp->next;
        pos++;
    }
}
void dp(node* &head, int pos) {
    node* temp = head;

    if (pos == 1) {
        head = head->next;
        delete temp;
        cout <<"Successfully deleted"<< endl;
        return;
    }

    int x = 1;
    while (temp != NULL && x < pos - 1) {
        temp = temp->next;
        x++;
    }

    node* del = temp->next;
    temp->next = del->next;
    delete del;
    cout<<"Successfully deleted"<< endl;
}


int main() {
    node* head = NULL;
    
    while (true)
    {
        cout<<"Simple Text Editor"<<endl;
        cout<<"1. Insert a text line"<<endl;
        cout<<"2. Change text at position"<<endl;
        cout<<"3. Search by keyword"<<endl;
        cout<<"4. Delete at position"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        int x;
        int h=0;
        cin>>x;
        if(x==1){
            string txt;
            cout<<"Enter a line: ";
            cin.ignore(); 
            getline(cin,txt);
            if(head == NULL){ 
                inserth(head,txt);
            }
            else{
                iend(head,txt);
            }
        }
        else if(x==2){
            string txt2;
            int y;
            cout<<"Enter position: ";
            cin>>y;
            cout<<"Enter new text line: ";
            cin.ignore(); 
            getline(cin,txt2);
            change(head,txt2,y);
        }
        else if(x==3){
            string txt2;
            cout<<"Enter the word you want to search: ";
            cin.ignore(); 
            getline(cin,txt2);
            search(txt2,head);
        }
        else if(x==4){
            int b;
            cout<<"Enter the text position to delete: ";
            cin>>b;
            dp(head,b);
        }

        else if(x==5){
            display(head);
        }
        else if(x==6){
            break;
        }
    }
    

    return 0;
}

