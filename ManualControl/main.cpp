#include <iostream>
#include <wiringPi.h>
#include "StepperMotor.hpp"

using namespace std;

int main()
{
 
	char choice{};
    do{
        
        wiringPiSetup();
        StepperMotor sm;
        sm.setGPIOutputs(0, 1, 2, 3);
        
        cout<<endl;
        cout << "R - Rotate" << endl; 
        cout << "Q - Print numbers" << endl; 
        cout<<endl;
        cout << "Enter your choice: "; 
        cin >> choice ;
        
        if(choice=='R' || choice=='r')
        {
            cout<<endl;
            float rotate{0};
            cout << "Rotate to left= -1 or right= 1 :" ;
            cin >> rotate;
                if(rotate == -1)
                    cout << "Rotate to left" << endl;
                else if(rotate==1)
                    cout << "Rotate to right" << endl;
                else
                    cout << "Wrong option" << endl;
                    
            int degrees{0};
            cout << "How many degrees rotate you wanna 0-360: "; 
            cin >> degrees;
            
            int Speed{0};
            cout << "How many % speed clockwise 0-100: "; 
            cin >> Speed;   
            
            sm.run(rotate, degrees, Speed);   
            }
       
        }while(choice!='Q' && choice!='q');    
}
	return 0;
