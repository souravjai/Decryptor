#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void draw_heart()
{
     for( float y = 1.3 ; y >= -1.1 ; y -= 0.06 ){
        for( float x = -1.2 ; x <= 1.2 ; x += 0.025 )
            if( pow((x*x+y*y-1.0),3) - x*x*y*y*y <= 0.0 )
                cout<<' ';
            else
                cout<<'$';
        cout<<endl;
    }
}
void greet()
{
    cout<<"This game is made by Sourav jaiswal. Please do not plagiarize. Mail me at souravjaiswal2000@gmail.com\n\n";
    cout<<"\t\t\t\tTHE DECRYPTOR GAME"<<endl;

    cout<<"Welcome to The Decryptor Game!!!!\n"<<endl;
    cout<<"Overview: The computer generates a 4 digit password,"<<endl;
    cout<<"          This password consist UNIQUE/NON REPEATING digits."<<endl;
    
    cout<<"\nAim:   Your aim is to crack the password,"<<endl;
    cout<<"       At each stage you try to guess a 4 digit Password"<<endl;
    cout<<"       You might get one of the outcome:\n"<<endl;
    cout<<"       ( "<<(char)251<<" ) : "<<"The digit is present in password and rightly placed."<<endl;
    cout<<"       (<->) : The digit is present in password but wrongly placed."<<endl;
    cout<<"       ( X ) : The digit is not present in the password."<<endl;
    cout<<"\nNote: The 4-Digit password generted has every digit Unique ,i.e, no digit is repeated.\n"<<endl;
    
    for(int i=0;i<5;i++)
    {
        cout<<"The Game starts in "<<5-i<<" seconds"<<endl;
        sleep(1);
    }
    cout<<endl;
}


bool print(int output[4],int input[4])
{
    cout<<endl;
     bool flag=true;
     cout<<"     "<<input[0]<<"       "<<input[1]<<"       "<<input[2]<<"       "<<input[3]<<endl; 
     for(int i=0;i<4;i++)
     {
         if(output[i]==input[i])
         printf("   ( %c )",251);

         else 
         {
             flag=false;
             string x="( X )";
               for(int j=0;j<4;j++)
                 if(output[j]==input[i])
                 {
                    x="(<->)";
                    break;
                 } 

              cout<<"   "<<x;
         }      
     }
     cout<<endl;
     return flag;
}

bool check(int input)
{
   // cout<<input<<endl;
    if(input>9999||input<1000) return false;
    int f=input%10; input/=10;
    int s=input%10; input/=10;
    int t=input%10; input/=10;
    
    if(f==s||f==t||f==input||s==t||s==input||t==input) return false;
    return true;
}

bool validate(string s)
{
    bool f=false;

    if(s.size()!=4)
    f=true;

    for(int i=0;!f && i<4;i++)
    {
        if(!( s[i]>='0' && s[i]<='9'))
        f=true;
    }

    if(f)
    {
        string x;

        cout<<"DIDN'T I TOLD YOU TO ENTER  A 4 DIGIT NUMBER WITHOUT SPACES?\n"<<endl;
        cout<<"[Press 1] You take full responsibility of your action and will not repeat the mistake."<<endl;
        cout<<"[Press 2] You just want to watch the world Burn."<<endl;
        cin>>x;

        if(x=="1")
        cout<<"It's okay buddy!"<<endl;
        else if(x=="2")
        cout<<"Change your attitude!"<<endl;
        else
        cout<<"You MORON!"<<endl;
        
        
        cout<<"Okay! Now please continue"<<endl;
    }

    return f;    
}

int start_game()
{
    srand(time(0));
    cout<<"Generating a Number..."<<endl;
    
    sleep(3);
    int output=0;
    do{
        output=1000+rand()%9000;
    }while(!check(output));

    cout<<"Number Is Generated!"<<endl;

    int turns=0;
    string in;
    bool flag=true;

    int o[4],i[4];
    o[0]=output%10; output/=10;
    o[1]=output%10; output/=10;
    o[2]=output%10; output/=10;
    o[3]=output;

    do
    {
        turns++;
        if(turns==9) break;
        cout<<"\n[Turns Left:"<<9-turns<<"]  Enter a 4 digit number without spaces: ";
        cin>>in;

        if(validate(in))
        continue;
        
        else
        {
            i[0]=in[0]-'0';
            i[1]=in[1]-'0';
            i[2]=in[2]-'0';
            i[3]=in[3]-'0';

            if(print(o,i))
            break;
        }
        
        
    }while(true);
    if(turns==9)
    {
        cout<<"Alas! You lost BUT Never lose hope buddy we have a game to win "<<endl;
        cout<<"The number was:"<<o[0]<<o[1]<<o[2]<<o[3]<<endl;
    }
    else
    cout<<"\ncongratulation You won in "<<turns<<" steps! BUT can you do better?"<<endl;
    sleep(3);
    draw_heart();
    string s;
    cout<<"[Press Y] to Play again."<<endl;
    cout<<"[Press N] to exit."<<endl;
    cin>>s;

    if(s=="N")
    return 0;
    
    return 1;
}

int main()
{
    greet();
    int x=1;
    do
    {
      x=start_game();
      if(x==0) cout<<"See you later alligator";
      else cout<<"Get Ready To Play again\n\n";
    } while (x==1);
    
}