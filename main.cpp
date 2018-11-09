//  Created by ARx & AF.
#include "Header.h"
#include "Queue.hpp"
using namespace std;
void MainMenu(Queue* q){
    
    int x;
    int choice;
    cout <<"****************************************************************" << endl;
    cout << "Welcome! " << endl;
    cout << "Please enter your choise from the following menu: " << endl;
    cout << "1 - Quary 50 numbers into Link List" << endl;
    cout << "2 - Quary 50 numbers into Binary Tree" << endl;
    cout << "3 - Quary 50 numbers into both Structures" << endl;
    cout << "4 - Dequeue the biggest number from Link List " << endl;
    cout << "5 - Dequeue the All Numbers from Big to Small -  Link List **Use only after Enqueing using 1**" << endl;
    cout << "6 - Dequeue the biggest number from Binary Tree" << endl;
    cout << "7 - Dequeue the All Numbers from Big to Small -  Binary Tree **Use only after Enqueing using 2**" << endl;
    cout << "8 - Dequeue the All Numbers from Big to Small -  All Structures **Use only after using 3**" << endl;
    cout << "9 - Exit Program." << endl;
    cout << "Your Choise: ";
    cin >> choice;
    cout << endl <<"****************************************************************" <<endl;
    switch(choice){
        case 1:{
            for(int i = 0; i<NumOfNum; i++){
                x = q->getRand();
                cout << "------> " << x << " -----> Entered into LinkList" << endl;
                q->LinkL::Enqueue(x);
            }
            MainMenu(q);
            break;
        }
        case 2:{
            for(int i = 0; i<NumOfNum; i++){
                x = q->getRand();
                cout << "------> " << x << " -----> Entered into Tree" << endl;
                q->Tree::Enqueue(x);
            }
            MainMenu(q);
            break;
        }
        case 3:{
            for(int i = 0; i<NumOfNum; i++){
                x = q->getRand();
                cout << "------> " << x << " -----> Entered into Both Structures" << endl;
                q->Queue::Enqueue(x);
            }
            MainMenu(q);
            break;
        }
        case 4:{
            q->LinkL::Dequeue();
            MainMenu(q);
            break;
        }
        case 5:{
            if(q->LinkL::_numOfNodes != 50){
                cout << "Use Only with quary 50 Numbers" << endl;
                MainMenu(q);
                break;
            }
            for(int i = 0; i<NumOfNum; i++){
                q->LinkL::Dequeue();
            }
            MainMenu(q);
            break;
        }
        case 6 :{
            int max = q->Tree::FindMax();
            cout << q->Tree::Dequeue(max) << endl;
            MainMenu(q);
            break;
        }
        case 7 :{
            int max;
            for(int i = 0; i< NumOfNum; i++){
                max = q->Tree::FindMax();
                cout << q->Tree::Dequeue(max) << endl;
            }
            MainMenu(q);
            break;
        }
        case 8: {
            if(q->LinkL::_numOfNodes != 50){
                cout << "Use Only with quary 50 Numbers to both Structures" << endl;
                MainMenu(q);
                break;
            }
            for(int i = 0; i < NumOfNum; i++)
                q->Queue::Dequeue();
            MainMenu(q);
            break;
        }
        case 9:{
            cout << "Bye Bye Hope you Enjoyed, Asaf and Arik" << endl;
            break;
        }
        default: { MainMenu(q); }
            
    }
}
int main(){
    Queue q;
    MainMenu(&q);
    
    return 0;
}
